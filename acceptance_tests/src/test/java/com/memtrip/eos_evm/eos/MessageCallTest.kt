package com.memtrip.eos_evm.eos

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.assertConsoleString
import com.memtrip.eos_evm.eos.actions.raw.RawAction
import com.memtrip.eos_evm.eos.evm.GetCode
import com.memtrip.eos_evm.ethereum.EthereumTransaction
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Test
import java.math.BigInteger
import java.util.concurrent.TimeUnit

class MessageCallTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val rawAction = RawAction(chainApi)

    private val getCode = GetCode(chainApi)

    @Test
    fun `external message call that creates an event`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger.valueOf(0),
            "0x6080604052348015600f57600080fd5b5060cb8061001e6000396000f3fe608060405260043610601c5760003560e01c806373d98e39146021575b600080fd5b60276029565b005b7fbbbf55a6f5ae8ee75e6fb8f92a93e32841ed3055bf2139469c60bbc79a455da73334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a156fea265627a7a7231582069c4265b77ab1bd39221ac01c9f6f1adacb2f5a7beeccf724523846fa4aaf8ba64736f6c63430005100032"
        )

        val response = rawAction.pushTransaction(
            newAccountName,
            transaction.sign(newEthAccount).signedTransaction.toHexString(),
            accountIdentifier.toHexString(),
            TransactionContext(
                newAccountName,
                newAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // then
        assertEquals(response.statusCode, 202)

        // and when
        val contractCode = getCode.getAllByOwner(
            accountIdentifier.pad256().toHexString()
        ).blockingGet()

        val contractAddress: String = if (contractCode is GetCode.Record.Multiple) {
            assertEquals(
                "608060405260043610601c5760003560e01c806373d98e39146021575b600080fd5b60276029565b005b7fbbbf55a6f5ae8ee75e6fb8f92a93e32841ed3055bf2139469c60bbc79a455da73334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a156fea265627a7a7231582069c4265b77ab1bd39221ac01c9f6f1adacb2f5a7beeccf724523846fa4aaf8ba64736f6c63430005100032",
                contractCode.items[0].code
            )
            assertEquals(accountIdentifier.pad256().toHexString(), contractCode.items[0].owner)
            assertEquals("1.0", contractCode.items[0].nonce)
            contractCode.items[0].address
        } else "address_not_found"

        // and when
        val callTransaction = EthereumTransaction(
            2,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger.valueOf(2),
            "0x73d98e39",
            contractAddress
        )

        val callTransactionResponse = rawAction.pushTransaction(
            newAccountName,
            callTransaction.sign(newEthAccount).signedTransaction.toHexString(),
            accountIdentifier.toHexString(),
            TransactionContext(
                newAccountName,
                newAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // and then
        assertEquals(202, callTransactionResponse.statusCode)
        callTransactionResponse.assertConsoleString(
            "data=000000000000000000000000${accountIdentifier.toHexString()}0000000000000000000000000000000000000000000000000000000000000002"
        )
    }

    @Test
    fun `external message call adding two numbers`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger.valueOf(0),
            "0x608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390a160b8806100826000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a7231582071c7fe98a34e7c0c2e10ae018de7d3708ce7189591eff656e9cbf717bc03c1f664736f6c63430005100032"
        )

        val response = rawAction.pushTransaction(
            newAccountName,
            transaction.sign(newEthAccount).signedTransaction.toHexString(),
            accountIdentifier.toHexString(),
            TransactionContext(
                newAccountName,
                newAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // then
        assertEquals(response.statusCode, 202)

        // and when
        val contractCode = getCode.getAllByOwner(
            accountIdentifier.pad256().toHexString()
        ).blockingGet()

        val contractAddress: String = if (contractCode is GetCode.Record.Multiple) {
            assertEquals(
                "6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a7231582071c7fe98a34e7c0c2e10ae018de7d3708ce7189591eff656e9cbf717bc03c1f664736f6c63430005100032",
                contractCode.items[0].code
            )
            assertEquals(
                accountIdentifier.pad256().toHexString(),
                contractCode.items[0].owner
            )
            contractCode.items[0].address
        } else "address_not_found"

        // and when
        val callTransaction = EthereumTransaction(
            2,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger.valueOf(0),
            "0x771602f700000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000002",
            contractAddress
        )

        val callTransactionResponse = rawAction.pushTransaction(
            newAccountName,
            callTransaction.sign(newEthAccount).signedTransaction.toHexString(),
            accountIdentifier.toHexString(),
            TransactionContext(
                newAccountName,
                newAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // and then
        assertEquals(202, callTransactionResponse.statusCode)
        callTransactionResponse.assertConsoleString(
            "return[0000000000000000000000000000000000000000000000000000000000000003]"
        )
    }
}
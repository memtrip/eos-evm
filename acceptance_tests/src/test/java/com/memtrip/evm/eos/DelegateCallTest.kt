package com.memtrip.evm.eos

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.assertConsoleString
import com.memtrip.evm.eos.actions.raw.RawAction
import com.memtrip.evm.eos.state.GetAccountState
import com.memtrip.evm.eos.evm.GetCode
import com.memtrip.evm.ethereum.EthereumTransaction
import com.memtrip.evm.ethereum.pad256
import com.memtrip.evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Assert.fail
import org.junit.Test
import java.math.BigInteger
import java.util.concurrent.TimeUnit

class DelegateCallTest {

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

    private val getAccountState = GetAccountState(chainApi)

    @Test
    fun `Execute a log statement in a child contract via delegate call`() {

        // given
        val (contractAccountName, contractPrivateKey, contractEthAccount) = setupTransactions.seedWithEvmBalance(17000)
        val contractAccountIdentifier = AccountIdentifier.create(contractAccountName, contractEthAccount.address)

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a00", 16),
            BigInteger.valueOf(0),
            "0x608060405234801561001057600080fd5b5060405161001d9061007e565b604051809103906000f080158015610039573d6000803e3d6000fd5b506000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555061008a565b60e98061024c83390190565b6101b3806100996000396000f3fe6080604052600060606000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f7468616e6b73282900000000000000000000000000000000000000000000000081525060080190506040518091039020604051602401604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b6020831061010c57805182526020820191506020810190506020830392506100e9565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d806000811461016c576040519150601f19603f3d011682016040523d82523d6000602084013e610171565b606091505b508092508193505050505000fea265627a7a72315820da7c31f28b4f3375beaded9e8de4f3d0d931474ec015024b6692d620ea57405264736f6c634300051000326080604052348015600f57600080fd5b5060cb8061001e6000396000f3fe608060405260043610601c5760003560e01c806373d98e39146021575b600080fd5b60276029565b005b7fbbbf55a6f5ae8ee75e6fb8f92a93e32841ed3055bf2139469c60bbc79a455da73334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a156fea265627a7a7231582069c4265b77ab1bd39221ac01c9f6f1adacb2f5a7beeccf724523846fa4aaf8ba64736f6c63430005100032"
        )

        val createContract = faultTolerant {
            rawAction.pushTransaction(
                contractAccountName,
                transaction.sign(contractEthAccount).signedTransaction.toHexString(),
                contractAccountIdentifier.toHexString(),
                TransactionContext(
                    contractAccountName,
                    contractPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet()
        }

        // then
        assertEquals(202, createContract.statusCode)

        // and when
        val getContractCode = getCode.getAllByOwner(
            contractAccountIdentifier.pad256().toHexString()
        ).blockingGet()

        val parentContractAddress = if (getContractCode !is GetCode.Record.Multiple) "invalid_address" else {
            assertEquals(1, getContractCode.items.size)
            assertEquals(
                "6080604052600060606000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f7468616e6b73282900000000000000000000000000000000000000000000000081525060080190506040518091039020604051602401604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b6020831061010c57805182526020820191506020810190506020830392506100e9565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d806000811461016c576040519150601f19603f3d011682016040523d82523d6000602084013e610171565b606091505b508092508193505050505000fea265627a7a72315820da7c31f28b4f3375beaded9e8de4f3d0d931474ec015024b6692d620ea57405264736f6c63430005100032",
                getContractCode.items.first().code
            )
            getContractCode.items.first().address
        }

        // and when
        val getChildCode = getCode.getAllByOwner(parentContractAddress).blockingGet()

        val childAddress = if (getChildCode !is GetCode.Record.Multiple) "invalid_address" else {
            assertEquals(1, getChildCode.items.size)
            assertEquals(
                "608060405260043610601c5760003560e01c806373d98e39146021575b600080fd5b60276029565b005b7fbbbf55a6f5ae8ee75e6fb8f92a93e32841ed3055bf2139469c60bbc79a455da73334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a156fea265627a7a7231582069c4265b77ab1bd39221ac01c9f6f1adacb2f5a7beeccf724523846fa4aaf8ba64736f6c63430005100032",
                getChildCode.items.first().code
            )
            getChildCode.items.first().address
        }

        // and when
        val getAccountState = getAccountState.getAll(parentContractAddress).blockingGet()

        // and then
        if (getAccountState !is GetAccountState.Record.Multiple) fail("no account states") else {
            val items = getAccountState.items
            assertEquals(items.first().accountIdentifier, parentContractAddress)
            assertEquals(items[0].value, childAddress)
        }

        // and then
        val (senderAccountName, senderAccountPrivateKey, senderEthAccount) = setupTransactions.seedWithEvmBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        val callTransaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger.valueOf(1),
            "0x",
            parentContractAddress
        )

        val callTransactionResponse = rawAction.pushTransaction(
            senderAccountName,
            callTransaction.sign(senderEthAccount).signedTransaction.toHexString(),
            senderAccountIdentifier.toHexString(),
            TransactionContext(
                senderAccountName,
                senderAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // and then
        assertEquals(202, callTransactionResponse.statusCode)

        callTransactionResponse.assertConsoleString(
            "data=000000000000000000000000${senderAccountIdentifier.toHexString()}0000000000000000000000000000000000000000000000000000000000000000)"
        )
    }
}
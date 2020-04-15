package com.memtrip.eos_evm.eos

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.raw.RawAction
import com.memtrip.eos_evm.eos.state.GetAccount
import com.memtrip.eos_evm.eos.state.GetCode
import com.memtrip.eos_evm.ethereum.AccountStateKey
import com.memtrip.eos_evm.ethereum.EthereumTransaction
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.*
import org.junit.Test
import java.math.BigInteger
import java.util.concurrent.TimeUnit

class CreateContractTest {

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
    fun `Create a contract via CREATE`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x7c601080600c6000396000f3006000355415600957005b60203560003555600052601d60036017f0600055"
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
        val result = getCode.getValue(
            newAccountName,
            accountIdentifier.pad256().toHexString()
        ).blockingGet()

        if (result is GetCode.Record.Value) {
            assertEquals(
                "601080600c6000396000f3006000355415600957005b60203560003555",
                result.code
            )
            assertEquals(
                accountIdentifier.pad256().toHexString(),
                result.address
            )
        } else {
            fail("account_code record not found")
        }
    }

    @Test

    fun `Create a contract via COPYCODE`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger.valueOf(0),
            "0x608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390a160b8806100826000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a723158209551755b4e59ca6cf78d79f5356d91565950805937074458700610f23c6ecf9b64736f6c63430005100032"
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
        val result = getCode.getValue(
            newAccountName,
            accountIdentifier.pad256().toHexString()
        ).blockingGet()

        if (result is GetCode.Record.Value) {
            assertEquals(
                "6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a723158209551755b4e59ca6cf78d79f5356d91565950805937074458700610f23c6ecf9b64736f6c63430005100032",
                result.code
            )
            assertEquals(
                accountIdentifier.pad256().toHexString(),
                result.address
            )
        } else {
            fail("account_code record not found")
        }
    }

    @Test
    fun `Only one code entry can be created per address via CREATE`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val transaction1 = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x7c601080600c6000396000f3006000355415600957005b60203560003555600052601d60036017f0600055"
        )

        // then
        val response1 = rawAction.pushTransaction(
            newAccountName,
            transaction1.sign(newEthAccount).signedTransaction.toHexString(),
            accountIdentifier.toHexString(),
            TransactionContext(
                newAccountName,
                newAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        Thread.sleep(500) // avoid duplicate transaction exception

        // then
        assertEquals(202, response1.statusCode)

        // and when
        val transaction2 = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x7c601080600c6000396000f3006000355415600957005b60203560003555600052601d60036017f0600055"
        )

        // then
        val response2 = rawAction.pushTransaction(
            newAccountName,
            transaction2.sign(newEthAccount).signedTransaction.toHexString(),
            accountIdentifier.toHexString(),
            TransactionContext(
                newAccountName,
                newAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // and then
        assertEquals(500, response2.statusCode)

        assertTrue(
            response2.containsErrorString(
                "The sender address already contains a code entry"
            )
        )
    }

    @Test
    fun `Only one code entry can be created per address via CODECOPY`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val transaction1 = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger.valueOf(0),
            "0x608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390a160b8806100826000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a723158209551755b4e59ca6cf78d79f5356d91565950805937074458700610f23c6ecf9b64736f6c63430005100032"
        )

        // then
        val response1 = rawAction.pushTransaction(
            newAccountName,
            transaction1.sign(newEthAccount).signedTransaction.toHexString(),
            accountIdentifier.toHexString(),
            TransactionContext(
                newAccountName,
                newAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        Thread.sleep(500) // avoid duplicate transaction exception

        // then
        assertEquals(202, response1.statusCode)

        // and when
        val transaction2 = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger.valueOf(0),
            "0x608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390a160b8806100826000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a723158209551755b4e59ca6cf78d79f5356d91565950805937074458700610f23c6ecf9b64736f6c63430005100032"
        )

        // then
        val response2 = rawAction.pushTransaction(
            newAccountName,
            transaction2.sign(newEthAccount).signedTransaction.toHexString(),
            accountIdentifier.toHexString(),
            TransactionContext(
                newAccountName,
                newAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // and then
        assertEquals(500, response2.statusCode)

        assertTrue(
            response2.containsErrorString(
                "The sender address already contains a code entry"
            )
        )
    }
}
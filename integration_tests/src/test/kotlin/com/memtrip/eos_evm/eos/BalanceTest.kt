package com.memtrip.eos_evm.eos

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.actions.raw.RawAction
import com.memtrip.eos_evm.eos.state.GetAccountState
import com.memtrip.eos_evm.ethereum.AccountStateKey
import com.memtrip.eos_evm.ethereum.EthereumTransaction
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Test
import java.math.BigInteger
import java.util.concurrent.TimeUnit

class BalanceTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val rawAction = RawAction(chainApi)

    private val getAccountState = GetAccountState(chainApi)

    @Test
    fun `The empty balance of the sender is stored in the account state`() {

        // given
        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {

            val (accountName, accountPrivateKey, ethAccount) = setupTransactions.seed()

            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x3331600055"
            )
            val signedTransaction = transaction.sign(ethAccount).signedTransaction.toHexString()

            val accountIdentifier = AccountIdentifier.create(accountName, ethAccount.address)
            val response = rawAction.pushTransaction(
                accountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                TransactionContext(
                    accountName,
                    accountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet()

            TestTransaction(
                accountName,
                accountIdentifier,
                response
            )
        }

        // then
        assertEquals(202, response.statusCode)

        val balance = getAccountState.getValue(
            accountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x00)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000000", balance)
    }

    @Test
    fun `The sender balance of 0_5000 is stored in the account state`() {

        // given
        val (accountName, accountPrivateKey, ethAccount) = setupTransactions.seedWithBalance()
        val accountIdentifier = AccountIdentifier.create(accountName, ethAccount.address)

        // when
        val transferResult = faultTolerant {
            setupTransactions.transfer(
                "eos.evm",
                "0.5000 ${Config.SYMBOL}",
                "evm funds",
                accountName,
                accountPrivateKey,
                "eosio.token"
            ).blockingGet()
        }

        // then
        assertEquals(202, transferResult.statusCode)

        // and when
        val balanceResponse = faultTolerant {
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x3331600055"
            )
            val signedTransaction = transaction.sign(ethAccount).signedTransaction.toHexString()

            rawAction.pushTransaction(
                accountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                TransactionContext(
                    accountName,
                    accountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet()
        }

        // and then
        assertEquals(202, balanceResponse.statusCode)

        val balance = getAccountState.getValue(
            accountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x00)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000001388", balance)
    }
}
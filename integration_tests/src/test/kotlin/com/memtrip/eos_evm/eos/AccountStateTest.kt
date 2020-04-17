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

class AccountStateTest {

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
    fun `State is retrieved by SLOAD, used in an operation, and stored under another key`() {
        // given
        val (accountName, accountPrivateKey, ethAccount) = setupTransactions.seedWithBalance()
        val accountIdentifier = AccountIdentifier.create(accountName, ethAccount.address)

        // when
        val storageResponse = faultTolerant {
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x6010600055600054600501600155"
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

        assertEquals(202, storageResponse.statusCode)

        // then
        val storage00 = getAccountState.getValue(
            accountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x00)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000010", storage00)

        val storage01 = getAccountState.getValue(
            accountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000015", storage01)
    }
}
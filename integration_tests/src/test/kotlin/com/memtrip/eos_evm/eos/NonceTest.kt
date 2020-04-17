package com.memtrip.eos_evm.eos

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.actions.raw.RawAction
import com.memtrip.eos_evm.eos.state.GetAccount
import com.memtrip.eos_evm.ethereum.EthereumTransaction
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert
import org.junit.Assert.assertEquals
import org.junit.Test
import java.math.BigInteger
import java.util.concurrent.TimeUnit

class NonceTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val rawAction = RawAction(chainApi)

    private val getAccount = GetAccount(chainApi)

    @Test
    fun `The nonce of two subsequent transactions must be sequential`() {

        // given
        val (accountName, accountPrivateKey, ethAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(accountName, ethAccount.address).toHexString()

        // when
        val transaction1 = faultTolerant {
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x00"
            )
            val signedTransaction = transaction.sign(ethAccount).signedTransaction.toHexString()

            rawAction.pushTransaction(
                accountName,
                signedTransaction,
                accountIdentifier,
                TransactionContext(
                    accountName,
                    accountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet()
        }

        // and then
        assertEquals(202, transaction1.statusCode)

        Thread.sleep(500) // ensure duplicate transaction doesn't occur

        // and when
        val transaction2 = faultTolerant {
            val transaction = EthereumTransaction(
                2,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x00"
            )
            val signedTransaction = transaction.sign(ethAccount).signedTransaction.toHexString()

            rawAction.pushTransaction(
                accountName,
                signedTransaction,
                accountIdentifier,
                TransactionContext(
                    accountName,
                    accountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet()
        }

        // and then
        assertEquals(202, transaction2.statusCode)

        // and when
        val endingNonce = getAccount.getEvmAccount(accountName).blockingGet()
        if (endingNonce !is GetAccount.Record.Single) Assert.fail("Failed to create account") else {
            assertEquals("2.0", endingNonce.item.nonce)
        }
    }
}
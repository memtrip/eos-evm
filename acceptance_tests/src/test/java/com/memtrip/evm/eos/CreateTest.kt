package com.memtrip.evm.eos

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.eos.actions.create.CreateAction
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Test
import java.util.concurrent.TimeUnit

class CreateTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val createAction = CreateAction(chainApi)

    @Test
    fun `Only one Eth address can be linked to an EOS Account`() {

        // given
        val (eosAccountName, eosPrivateKey, ethAccount) = setupTransactions.seed()

        Thread.sleep(500) // avoid duplicate transaction exception

        // when
        val response2 = createAction.pushTransaction(
            eosAccountName,
            ethAccount.address,
            TransactionContext(
                eosAccountName,
                eosPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // then
        assertEquals(500, response2.statusCode)
    }
}
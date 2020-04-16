package com.memtrip.eos_evm.eos

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.Config.SYMBOL
import com.memtrip.eos_evm.eos.raw.RawAction
import com.memtrip.eos_evm.eos.state.GetAccount
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert
import org.junit.Assert.assertEquals
import org.junit.Assert.assertTrue
import org.junit.Test
import java.util.concurrent.TimeUnit

class TransferTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val getAccount = GetAccount(chainApi)

    @Test
    fun `Successfully transfer tokens from an EOS account to an EVM account`() {

        // given
        val (accountName, privateKey) = setupTransactions.seedWithBalance()

        // when
        val transferResult = setupTransactions.transfer(
            "eos.evm",
            "0.0010 $SYMBOL",
            "evm funds",
            accountName,
            privateKey,
            "eosio.token"
        ).blockingGet()

        // then
        assertEquals(202, transferResult.statusCode)

        // and when
        val ok = getAccount.getAccount(accountName).blockingGet()
        print("")
    }
}
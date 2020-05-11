package com.memtrip.evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.evm.contracts.misc.PackedBytesContract
import com.memtrip.evm.eos.state.GetAccountState
import com.memtrip.evm.eos.evm.GetCode
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert
import org.junit.Assert.assertEquals
import org.junit.Test
import java.util.concurrent.TimeUnit

class PackedBytesContractTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val getCode = GetCode(chainApi)

    private val getAccountState = GetAccountState(chainApi)

    @Test
    fun `The PackedBytes contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = PackedBytesContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContract = contract.createContract().blockingGet()

        // then
        assertEquals(202, createContract.statusCode)

        // and when
        assertEquals(1, createContract.code.size)
        assertEquals(
            "6080604052600080fdfea265627a7a7231582071d46d91d99545b71d18b39f30129abbc3428b8dc272203b76c1f0ea262d09d364736f6c63430005100032",
            createContract.code[0].code
        )

        // and when
        val accountState = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()

        // and then
        if (accountState !is GetAccountState.Record.Multiple) Assert.fail("no state saved") else {
            assertEquals(1, accountState.items.size)
            assertEquals("aabbcc0000000000000000000000000000000000000000000000000000000006", accountState.items[0].value) // bytes and size
        }
    }
}
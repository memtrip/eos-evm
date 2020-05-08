package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.contracts.misc.LongByteArrayContract
import com.memtrip.eos_evm.eos.state.GetAccountState
import com.memtrip.eos_evm.eos.evm.GetCode
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert
import org.junit.Assert.assertEquals
import org.junit.Test
import java.util.concurrent.TimeUnit

class LongByteArrayContractTest {

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

        val contract = LongByteArrayContract(
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
            "6080604052600080fdfea265627a7a72315820e4bba4f987074f2f41aba48eb3a41df0b1a1a918fbcdb02b9babea440b1fd74a64736f6c63430005100032",
            createContract.code[0].code
        )

        // and when
        val accountState = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()

        // and then
        if (accountState !is GetAccountState.Record.Multiple) Assert.fail("no state saved") else {
            assertEquals(5, accountState.items.size)
            assertEquals("0000000000000000000000000000000000000000000000000000000000000001", accountState.items[0].value)
            assertEquals("0000000000000000000000000000000000000000000000000000000000000101", accountState.items[1].value)
            assertEquals("0000000000000000000000000000000000000000000000000000000000000002", accountState.items[2].value)
            assertEquals("0000000000000000000000000000000000000000000000000000000000000003", accountState.items[3].value)
            assertEquals("0000000000000000000000000000000000000000000000000000000000000004", accountState.items[4].value)
        }
    }
}
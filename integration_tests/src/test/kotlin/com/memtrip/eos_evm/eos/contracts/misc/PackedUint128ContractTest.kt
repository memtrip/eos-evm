package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.contracts.misc.PackedUint128Contract
import com.memtrip.eos_evm.eos.faultTolerant
import com.memtrip.eos_evm.eos.state.GetAccountState
import com.memtrip.eos_evm.eos.state.GetCode
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert
import org.junit.Assert.assertEquals
import org.junit.Test
import java.util.concurrent.TimeUnit

class PackedUint128ContractTest {

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
    fun `The PackedUint128 contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = PackedUint128Contract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContractResponse = faultTolerant {
            contract.createContract().blockingGet()
        }

        // then
        assertEquals(202, createContractResponse.statusCode)

        // and when
        val getCodeResult = getCode.getAll(
            contract.accountIdentifier.pad256().toHexString()
        ).blockingGet()

        if (getCodeResult !is GetCode.Record.Multiple) Assert.fail("code record not found") else {
            assertEquals(1, getCodeResult.items.size)
            assertEquals(
                "6080604052600080fdfea265627a7a72315820e22258c2b16769e411f5fbf58b407fdd387503b4749d58827d952947049d6efb64736f6c63430005100032",
                getCodeResult.items[0].code
            )
            assertEquals(getCodeResult.items[0].address, contract.accountIdentifier.pad256().toHexString())
        }

        // and when
        val accountState = getAccountState.getAll(contract.accountIdentifier.pad256().toHexString()).blockingGet()

        // and then
        if (accountState !is GetAccountState.Record.Multiple) Assert.fail("no state saved") else {
            assertEquals(3, accountState.items.size)
            assertEquals("0000000000000000000000000000000000000000000000000000000000000004", accountState.items[0].value) // size
            assertEquals("000000000000000000000000000000bb000000000000000000000000000000aa", accountState.items[1].value) // index 0 and 1 packed
            assertEquals("000000000000000000000000000000dd000000000000000000000000000000cc", accountState.items[2].value) // index 1 and 2 packed
        }
    }
}
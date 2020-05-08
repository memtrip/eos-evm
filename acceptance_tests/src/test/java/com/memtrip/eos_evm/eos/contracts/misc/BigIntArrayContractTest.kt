package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.contracts.misc.BigIntArrayContract
import com.memtrip.eos_evm.eos.state.GetAccountState
import com.memtrip.eos_evm.eos.evm.GetCode
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Assert.fail
import org.junit.Test
import org.web3j.crypto.Hash
import java.math.BigInteger
import java.util.concurrent.TimeUnit

class BigIntArrayContractTest {

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
    fun `The BigIntArray contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = BigIntArrayContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContract = contract.createContract(listOf(
            BigInteger.valueOf(0),
            BigInteger(Hash.sha3(contract.ownerAccountIdentifier.pad256()).toHexString(), 16),
            BigInteger("4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff16", 16)
        )).blockingGet()

        // then
        assertEquals(202, createContract.statusCode)
        assertEquals(1, createContract.code.size)
        assertEquals(
            "6080604052600080fdfea265627a7a72315820a69ee7faacbc5dae47918f7b25009aace0b3bdf791cb6e44035d0311a86a8d1364736f6c63430005100032",
            createContract.code[0].code
        )

        // and when
        val accountState = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()

        // and then
        if (accountState !is GetAccountState.Record.Multiple) fail("no state saved") else {
            assertEquals(4, accountState.items.size)
        }
    }
}
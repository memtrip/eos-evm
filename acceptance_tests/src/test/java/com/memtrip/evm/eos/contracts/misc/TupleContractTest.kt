package com.memtrip.evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.assertConsoleString
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.contracts.misc.TupleContract
import com.memtrip.evm.eos.faultTolerant
import com.memtrip.evm.eos.evm.GetCode
import com.memtrip.evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Test
import java.util.concurrent.TimeUnit

class TupleContractTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val getCode = GetCode(chainApi)

    @Test
    fun `The Tuple contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = TupleContract(
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
            "6080604052348015600f57600080fd5b506004361060285760003560e01c8063ab5ed15014602d575b600080fd5b60336049565b6040518082815260200191505060405180910390f35b6000806052605e565b50809150508091505090565b6000606060018090506040518060400160405280600281526020017f486900000000000000000000000000000000000000000000000000000000000081525091509150909156fea265627a7a7231582014e7a484ae72de63d610eee5700f82beb654743f08478ca0c91c5147159df3c764736f6c63430005100032",
            createContract.code[0].code
        )
    }

    @Test
    fun `Call the test method`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(17000)
        val contract = TupleContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContract = contract.createContract().blockingGet()
        assertEquals(202, createContract.statusCode)

        // when
        val response = faultTolerant {
            contract.getOne(
                EvmSender(
                    2,
                    newEthAccount,
                    newAccountName,
                    newAccountPrivateKey,
                    contract.ownerAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[0000000000000000000000000000000000000000000000000000000000000001]")
    }
}
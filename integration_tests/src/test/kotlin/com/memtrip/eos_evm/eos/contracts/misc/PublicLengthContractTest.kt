package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.assertConsoleString
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.misc.PublicLengthContract
import com.memtrip.eos_evm.eos.evm.contracts.misc.TupleContract
import com.memtrip.eos_evm.eos.faultTolerant
import com.memtrip.eos_evm.eos.state.GetCode
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert
import org.junit.Assert.assertEquals
import org.junit.Test
import java.util.concurrent.TimeUnit

class PublicLengthContractTest {

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
    fun `The PublicLength contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(17000)

        val contract = PublicLengthContract(
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
            assertEquals(2, getCodeResult.items.size)
            assertEquals(
                "6080604052348015600f57600080fd5b506004361060325760003560e01c806333b77955146037578063fd1ee54c146053575b600080fd5b603d6092565b6040518082815260200191505060405180910390f35b607c60048036036020811015606757600080fd5b8101908080359060200190929190505050609e565b6040518082815260200191505060405180910390f35b60008080549050905090565b6000818154811060aa57fe5b90600052602060002001600091509050548156fea265627a7a723158204ff2745c468bff5a5ba57c96f3bba49d977e9b473ad476a3a74b8c6fb45ecd6664736f6c63430005100032",
                getCodeResult.items[0].code
            )
            assertEquals(
                "6080604052348015600f57600080fd5b506004361060285760003560e01c8063f8a8fd6d14602d575b600080fd5b60336049565b6040518082815260200191505060405180910390f35b60008060009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff166333b779556040518163ffffffff1660e01b815260040160206040518083038186803b15801560b157600080fd5b505afa15801560c4573d6000803e3d6000fd5b505050506040513d602081101560d957600080fd5b810190808051906020019092919050505090509056fea265627a7a72315820fa05caa2f43753e3f959dc20ebab902ec875dfe544613f33ab6a5b1fcdeb9a7764736f6c63430005100032",
                getCodeResult.items[1].code
            )
            assertEquals(getCodeResult.items[1].address, contract.accountIdentifier.pad256().toHexString())
        }
    }

    @Test
    fun `Call the test method`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(17000)
        val contract = PublicLengthContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.test(
                EvmSender(
                    4,
                    newEthAccount,
                    newAccountName,
                    newAccountPrivateKey,
                    contract.accountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[0000000000000000000000000000000000000000000000000000000000000005]")
    }
}
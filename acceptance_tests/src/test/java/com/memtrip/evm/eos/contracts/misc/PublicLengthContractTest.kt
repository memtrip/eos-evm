package com.memtrip.evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.assertConsoleString
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.contracts.misc.PublicLengthContract
import com.memtrip.evm.eos.faultTolerant
import com.memtrip.evm.eos.state.GetAccountState
import com.memtrip.evm.eos.evm.GetCode
import com.memtrip.evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Assert.fail
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

    private val getAccountState = GetAccountState(chainApi)

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
        val createContract = contract.createContract().blockingGet()

        // then
        assertEquals(202, createContract.statusCode)

        // and when
        assertEquals(1, createContract.code.size)
        assertEquals(
            "6080604052348015600f57600080fd5b506004361060285760003560e01c8063f8a8fd6d14602d575b600080fd5b60336049565b6040518082815260200191505060405180910390f35b60008060009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff166333b779556040518163ffffffff1660e01b815260040160206040518083038186803b15801560b157600080fd5b505afa15801560c4573d6000803e3d6000fd5b505050506040513d602081101560d957600080fd5b810190808051906020019092919050505090509056fea265627a7a72315820fa05caa2f43753e3f959dc20ebab902ec875dfe544613f33ab6a5b1fcdeb9a7764736f6c63430005100032",
            createContract.code[0].code
        )
        assertEquals("2.0", createContract.code[0].nonce)

        val childContracts = getCode.getAllByOwner(createContract.parentContractAddress32).blockingGet()
        val childContractAddress = if (childContracts is GetCode.Record.Multiple) {
            assertEquals(
                "6080604052348015600f57600080fd5b506004361060325760003560e01c806333b77955146037578063fd1ee54c146053575b600080fd5b603d6092565b6040518082815260200191505060405180910390f35b607c60048036036020811015606757600080fd5b8101908080359060200190929190505050609e565b6040518082815260200191505060405180910390f35b60008080549050905090565b6000818154811060aa57fe5b90600052602060002001600091509050548156fea265627a7a723158204ff2745c468bff5a5ba57c96f3bba49d977e9b473ad476a3a74b8c6fb45ecd6664736f6c63430005100032",
                childContracts.items[0].code
            )
            assertEquals(childContracts.items[0].owner, createContract.parentContractAddress32)
            assertEquals("1.0", childContracts.items[0].nonce)
            childContracts.items[0].address
        } else "address not found"

        // and when
        val contractAccountState = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()

        // and then
        if (contractAccountState !is GetAccountState.Record.Multiple) fail("no state saved") else {
            assertEquals(1, contractAccountState.items.size)
            assertEquals(childContractAddress, contractAccountState.items[0].value)
        }

        // and when
        val childContractAccountState = getAccountState.getAll(childContractAddress).blockingGet()

        // and then
        if (childContractAccountState !is GetAccountState.Record.Multiple) fail("no child state saved") else {
            assertEquals(6, childContractAccountState.items.size)
            assertEquals("0000000000000000000000000000000000000000000000000000000000000005", childContractAccountState.items[0].value)
            assertEquals("000000000000000000000000000000000000000000000000000000000000000a", childContractAccountState.items[1].value)
            assertEquals("0000000000000000000000000000000000000000000000000000000000000014", childContractAccountState.items[2].value)
            assertEquals("000000000000000000000000000000000000000000000000000000000000001e", childContractAccountState.items[3].value)
            assertEquals("0000000000000000000000000000000000000000000000000000000000000028", childContractAccountState.items[4].value)
            assertEquals("0000000000000000000000000000000000000000000000000000000000000032", childContractAccountState.items[5].value)
        }
    }

    @Test
    fun `Call the test method`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance(17000)
        val contract = PublicLengthContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract().blockingGet()
        assertEquals(202, createContract.statusCode)

        // when
        val response = faultTolerant {
            contract.test(
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
        response.assertConsoleString("return[0000000000000000000000000000000000000000000000000000000000000005]")
    }
}
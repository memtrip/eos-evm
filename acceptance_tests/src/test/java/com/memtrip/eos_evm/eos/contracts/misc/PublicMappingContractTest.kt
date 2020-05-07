package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.assertConsoleString
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.misc.PublicMappingContract
import com.memtrip.eos_evm.eos.evm.contracts.misc.TupleContract
import com.memtrip.eos_evm.eos.faultTolerant
import com.memtrip.eos_evm.eos.state.GetCode
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert
import org.junit.Assert.assertEquals
import org.junit.Assert.fail
import org.junit.Test
import java.util.concurrent.TimeUnit

class PublicMappingContractTest {

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
    fun `The PublicMapping contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = PublicMappingContract(
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

        if (getCodeResult !is GetCode.Record.Multiple) fail("code record not found") else {
            assertEquals(2, getCodeResult.items.size)
            assertEquals(
                "6080604052348015600f57600080fd5b506004361060285760003560e01c8063ed17585014602d575b600080fd5b605660048036036020811015604157600080fd5b8101908080359060200190929190505050606c565b6040518082815260200191505060405180910390f35b6000602052806000526040600020600091509050548156fea265627a7a72315820e42322782734d761aba70a6907d7fb967e28211b423341f82ada9db18e1d4aa364736f6c63430005100032",
                getCodeResult.items[0].code
            )
            assertEquals("1.0", getCodeResult.items[0].nonce)
            assertEquals(
                "6080604052348015600f57600080fd5b506004361060285760003560e01c80636d4ce63c14602d575b600080fd5b60336049565b6040518082815260200191505060405180910390f35b60008060009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1663ed17585060006040518263ffffffff1660e01b81526004018082815260200191505060206040518083038186803b15801560bd57600080fd5b505afa15801560d0573d6000803e3d6000fd5b505050506040513d602081101560e557600080fd5b810190808051906020019092919050505090509056fea265627a7a723158207c14e48936f157bc142b66e8b65db2eb112ce20675860c92cfed700a2febe7ac64736f6c63430005100032",
                getCodeResult.items[1].code
            )
            assertEquals("1.0", getCodeResult.items[0].nonce)
            assertEquals(getCodeResult.items[1].address, contract.accountIdentifier.pad256().toHexString())
        }
    }

    @Test
    fun `Call the get method`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(17000)
        val contract = PublicMappingContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.get(
                EvmSender(
                    2,
                    newEthAccount,
                    newAccountName,
                    newAccountPrivateKey,
                    contract.accountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[000000000000000000000000000000000000000000000000000000000000002a]")
    }
}
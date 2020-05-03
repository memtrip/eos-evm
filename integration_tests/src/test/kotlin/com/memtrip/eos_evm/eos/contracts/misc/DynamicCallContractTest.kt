package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.assertConsoleString
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.misc.DynamicCallContract
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

class DynamicCallContractTest {

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
    fun `The DynamicCall contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = DynamicCallContract(
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
                "608060405234801561001057600080fd5b50600436106100365760003560e01c80632fbebd381461003b578063febb0f7e14610069575b600080fd5b6100676004803603602081101561005157600080fd5b8101908080359060200190929190505050610087565b005b610071610094565b6040518082815260200191505060405180910390f35b80600a0160008190555050565b60008060603073ffffffffffffffffffffffffffffffffffffffff1660405180807f666f6f2875696e74323536290000000000000000000000000000000000000000815250600c0190506040518091039020600160405160200180837bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19167bffffffffffffffffffffffffffffffffffffffffffffffffffffffff191681526020018260ff168152602001925050506040516020818303038152906040526040518082805190602001908083835b60208310610182578051825260208201915060208101905060208303925061015f565b6001836020036101000a0380198251168184511680821785525050505050509050019150506000604051808303816000865af19150503d80600081146101e4576040519150601f19603f3d011682016040523d82523d6000602084013e6101e9565b606091505b5091509150600054925050509056fea265627a7a7231582073b60d229026f9e49ad9d300e07e48201a07c72d29fa0695b1252f7cb2927b7b64736f6c63430005100032",
                getCodeResult.items[0].code
            )
            assertEquals(getCodeResult.items[0].address, contract.accountIdentifier.pad256().toHexString())
        }
    }

    @Test
    fun `bar method is called`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val contract = DynamicCallContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.bar(
                EvmSender(
                    3,
                    newEthAccount,
                    newAccountName,
                    newAccountPrivateKey,
                    contract.accountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[000000000000000000000000000000000000000000000000000000000000000b]")
    }
}
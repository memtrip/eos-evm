package com.memtrip.evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.assertConsoleString
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.contracts.misc.TupleContract
import com.memtrip.evm.eos.faultTolerant
import com.memtrip.evm.eos.evm.GetCode
import com.memtrip.evm.eos.evm.contracts.misc.RevertCreateContract
import com.memtrip.evm.ethereum.EthAsset
import com.memtrip.evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Assert.fail
import org.junit.Test
import java.util.concurrent.TimeUnit

class RevertCreateContractTest {

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
    fun `The RevertCreate contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()

        val contract = RevertCreateContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContract = contract.createContract(EthAsset.milliether(150)).blockingGet()

        // then
        assertEquals(202, createContract.statusCode)

        // and when
        assertEquals(1, createContract.code.size)
        assertEquals(
            "6080604052348015600f57600080fd5b506004361060285760003560e01c8063a3a4ba3114602d575b600080fd5b60336035565b005b6000809054906101000a90505056fea265627a7a7231582026dd7bc956212ed74abd364ccb7df367a6030de4f79a56fd1bf803c9d0a14fb264736f6c63430005100032",
            createContract.code[0].code
        )
        assertEquals("0.1500 EVM", createContract.code[0].balance.toString())
    }

    @Test
    fun `Call the createChild method, 1 child contract is created, 1 child contract is reverted`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val contract = RevertCreateContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract(EthAsset.milliether(150)).blockingGet()
        assertEquals(202, createContract.statusCode)

        // when
        val response = faultTolerant {
            contract.createChild(
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

        val parentContractBalance = getCode.getAllByOwner(contract.ownerAccountIdentifierString32).blockingGet()
        if (parentContractBalance is GetCode.Record.Multiple) {
            assertEquals(1, parentContractBalance.items.size)
            assertEquals("0.1500 EVM", parentContractBalance.items.first().balance.toString())
        } else fail("parent contract not found")

        val childContract = getCode.getAllByOwner(createContract.parentContractAddress32).blockingGet()
        if (childContract is GetCode.Record.Multiple) {
            assertEquals(1, childContract.items.size)
            assertEquals(
                "60806040526004361061001e5760003560e01c8063efc81a8c14610023575b600080fd5b61002b61002d565b005b3460405161003a906100e8565b6040518091039082f080158015610055573d6000803e3d6000fd5b5090506000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff1602179055506040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260238152602001806101446023913960400191505060405180910390fd5b604f806100f58339019056fe6080604052603e8060116000396000f3fe6080604052600080fdfea265627a7a7231582036fdb05fde318805a00ee7d04f0cf8d0b2ae3190de6e1944175db57ca219309c64736f6c63430005100032646f206e6f742063726561746520746865205265766572744d6520636f6e7472616374a265627a7a7231582067c7fe59e8dc51cea0ba13ceeec2a1c8a2e3ea8d61192d7ed40bfd369e798dd764736f6c63430005100032",
                childContract.items.first().code
            )
            assertEquals("0.0000 EVM", childContract.items.first().balance.toString())
        } else fail("child contract not found")
    }
}
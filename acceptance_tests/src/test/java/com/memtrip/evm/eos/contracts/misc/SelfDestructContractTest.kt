package com.memtrip.evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.assertConsoleString
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.GetCode
import com.memtrip.evm.eos.evm.contracts.misc.SelfDestructContract
import com.memtrip.evm.eos.faultTolerant
import com.memtrip.evm.eos.state.GetAccount
import com.memtrip.evm.eos.state.GetAccountState
import com.memtrip.evm.ethereum.EthAsset
import com.memtrip.evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Assert.fail
import org.junit.Assert.assertTrue
import org.junit.Test
import java.util.concurrent.TimeUnit

class SelfDestructContractTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val getAccount = GetAccount(chainApi)

    private val getCode = GetCode(chainApi)

    val getAccountState = GetAccountState(chainApi)

    @Test
    fun `The SelfDestruct contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val contract = SelfDestructContract(newAccountName, newAccountPrivateKey, newEthAccount)

        // when
        val createContract = contract.createContract(EthAsset.milliether(100)).blockingGet()

        // then
        assertEquals(202, createContract.statusCode)

        // and when
        assertEquals(1, createContract.code.size)
        assertEquals(
            "6080604052348015600f57600080fd5b506004361060325760003560e01c8063b69ef8a8146037578063e9fad8ee146053575b600080fd5b603d605b565b6040518082815260200191505060405180910390f35b60596063565b005b600047905090565b3373ffffffffffffffffffffffffffffffffffffffff16fffea265627a7a7231582041289775868e81f3076f17de839e0bd9ed95120826665a354cae1ec15e23c21864736f6c63430005100032",
            createContract.code[0].code
        )
        assertEquals("0.1000 EVM", createContract.code[0].balance.toString())
    }

    @Test
    fun `Call the balance method`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val contract = SelfDestructContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract(EthAsset.milliether(150)).blockingGet()
        assertEquals(202, createContract.statusCode)

        // when
        val response = faultTolerant {
            contract.balance(
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
        response.assertConsoleString("return[0000000000000000000000000000000000000000000000000214e8348c4f0000]")
    }

    @Test
    fun `Call the exit method`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val contract = SelfDestructContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract(EthAsset.milliether(150)).blockingGet()
        assertEquals(202, createContract.statusCode)
        assertEquals("0.1500 EVM", createContract.code.first().balance.toString())

        // and when
        val balanceAfterCreateContract = getAccount.getEvmAccount(newAccountName).blockingGet()

        // and then
        if (balanceAfterCreateContract !is GetAccount.Record.Single) fail("Failed to check balance after create contract") else {
            assertEquals("0.8500 EVM", balanceAfterCreateContract.item.balance.toString())
        }

        // and when
        val storageAfterCreateContract = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()

        // and then
        if (storageAfterCreateContract is GetAccountState.Record.Multiple) {
            assertEquals(3, storageAfterCreateContract.items.size)
        } else fail("no storage for contract found")

        // when
        val response = faultTolerant {
            contract.exit(
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

        // and when
        val balanceAfterSelfDestruct = getAccount.getEvmAccount(newAccountName).blockingGet()

        // and then
        if (balanceAfterSelfDestruct !is GetAccount.Record.Single) fail("Failed to check balance after create contract") else {
            assertEquals("1.0000 EVM", balanceAfterSelfDestruct.item.balance.toString())
        }

        // and when
        val contractCodeAfterSelfDestruct = getCode.getAllByOwner(contract.ownerAccountIdentifierString32).blockingGet()

        // and then
        assertTrue(contractCodeAfterSelfDestruct is GetCode.Record.None)

        // and when
        val storageAfterSelfDestruct = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()

        // and then
        assertTrue(storageAfterSelfDestruct is GetAccountState.Record.None)
    }
}
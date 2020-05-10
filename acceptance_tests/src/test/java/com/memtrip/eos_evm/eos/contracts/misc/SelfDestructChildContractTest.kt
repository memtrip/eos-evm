package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.GetCode
import com.memtrip.eos_evm.eos.evm.contracts.misc.SelfDestructChildContract
import com.memtrip.eos_evm.eos.faultTolerant
import com.memtrip.eos_evm.ethereum.EthAsset
import com.memtrip.eos_evm.ethereum.toHexString
import junit.framework.TestCase.fail
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Test
import java.util.concurrent.TimeUnit

class SelfDestructChildContractTest {

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
    fun `The SelfDestructChild contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()

        val contract = SelfDestructChildContract(
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
            "6080604052348015600f57600080fd5b506004361060285760003560e01c8063f0c597dd14602d575b600080fd5b60336035565b005b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1663e9fad8ee6040518163ffffffff1660e01b8152600401600060405180830381600087803b158015609d57600080fd5b505af115801560b0573d6000803e3d6000fd5b5050505056fea265627a7a7231582083a9bac0ccfd83c6ccb14c524ab352e0a75c3ed58554a296ee38cbd57f7ae55d64736f6c63430005100032",
            createContract.code[0].code
        )

        // and when
        val getChildCode = getCode.getAllByOwner(createContract.parentContractAddress32).blockingGet()

        // and then
        if (getChildCode is GetCode.Record.Multiple) {
            assertEquals(1, getChildCode.items.size)
            assertEquals("6080604052348015600f57600080fd5b506004361060325760003560e01c8063b69ef8a8146037578063e9fad8ee146053575b600080fd5b603d605b565b6040518082815260200191505060405180910390f35b60596063565b005b600047905090565b3373ffffffffffffffffffffffffffffffffffffffff16fffea265627a7a72315820a342b6a6d2f7f3321a6100757f6f36633d5e11913994ca88e749d05b0718c62264736f6c63430005100032", getChildCode.items.first().code)
        }
    }

    @Test
    fun `Call the exitChild method`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val contract = SelfDestructChildContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract(EthAsset.milliether(150)).blockingGet()
        assertEquals(202, createContract.statusCode)
        assertEquals("0.0000 EVM", createContract.code.first().balance.toString())

        // and when
        val balanceBeforeSelfDestruct = getCode.getAllByOwner(createContract.parentContractAddress32).blockingGet()

        // and then
        if (balanceBeforeSelfDestruct is GetCode.Record.Multiple) {
            assertEquals("0.1500 EVM", balanceBeforeSelfDestruct.items.first().balance.toString())
        } else fail("Could not find child contract")

        // and when
        val response = faultTolerant {
            contract.exitChild(
                EvmSender(
                    2,
                    newEthAccount,
                    newAccountName,
                    newAccountPrivateKey,
                    contract.ownerAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // and then
        assertEquals(202, response.statusCode)

        // and when
        val balanceAfterSelfDestruct = getCode.getAllByOwner(contract.ownerAccountIdentifierString32).blockingGet()

        // and then
        if (balanceAfterSelfDestruct is GetCode.Record.Multiple) {
            assertEquals("0.1500 EVM", balanceAfterSelfDestruct.items.first().balance.toString())
        } else fail("Could not find parent contract")
    }
}
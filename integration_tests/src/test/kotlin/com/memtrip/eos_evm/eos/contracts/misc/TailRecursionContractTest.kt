package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.assertConsoleString
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.misc.TailRecursionContract
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

class TailRecursionContractTest {

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
    fun `The TailRecursion contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = TailRecursionContract(
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
                "608060405234801561001057600080fd5b50600436106100415760003560e01c8063188b85b414610046578063b239139814610088578063d4d6bc77146100ca575b600080fd5b6100726004803603602081101561005c57600080fd5b810190808035906020019092919050505061010c565b6040518082815260200191505060405180910390f35b6100b46004803603602081101561009e57600080fd5b8101908080359060200190929190505050610132565b6040518082815260200191505060405180910390f35b6100f6600480360360208110156100e057600080fd5b8101908080359060200190929190505050610146565b6040518082815260200191505060405180910390f35b6000808214610128576101216001830361010c565b820161012b565b60005b9050919050565b600061013f826000610177565b9050919050565b600080600090506000600190505b83811161016d5780820191508080600101915050610154565b5080915050919050565b60008083146101945761018f60018403848401610177565b610196565b815b90509291505056fea265627a7a723158201a82845bb967d881b90fa267b5a8dd6c5afcd981f0917c58d71b1604066f146264736f6c63430005100032",
                getCodeResult.items[0].code
            )
            assertEquals(getCodeResult.items[0].address, contract.accountIdentifier.pad256().toHexString())
        }
    }

    @Test
    fun `call the sum method`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val contract = TailRecursionContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.sum(5, EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[000000000000000000000000000000000000000000000000000000000000000f]")
    }

    @Test
    fun `call the sumloop method`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val contract = TailRecursionContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.sumloop(9, EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[000000000000000000000000000000000000000000000000000000000000002d]")
    }

    @Test
    fun `call the sumtail method`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val contract = TailRecursionContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.sumtail(12, EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[000000000000000000000000000000000000000000000000000000000000004e]")
    }
}
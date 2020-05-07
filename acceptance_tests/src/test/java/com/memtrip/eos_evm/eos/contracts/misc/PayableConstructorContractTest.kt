package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.assertConsoleString
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.misc.PayableConstructorContract
import com.memtrip.eos_evm.eos.faultTolerant
import com.memtrip.eos_evm.eos.state.GetAccount
import com.memtrip.eos_evm.eos.state.GetCode
import com.memtrip.eos_evm.ethereum.EthAsset
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Assert.fail
import org.junit.Test
import java.util.concurrent.TimeUnit

class PayableConstructorContractTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val getCode = GetCode(chainApi)

    private val getAccount = GetAccount(chainApi)

    @Test
    fun `The PayableContract is created and it's balance is confirmed`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val contract = PayableConstructorContract(newAccountName, newAccountPrivateKey, newEthAccount)

        // when
        val createContractResponse = faultTolerant {
            contract.createContract(EthAsset.milliether(100)).blockingGet()
        }

        // then
        assertEquals(202, createContractResponse.statusCode)

        // and when
        val getCodeResult = getCode.getAll(
            contract.accountIdentifier.pad256().toHexString()
        ).blockingGet()

        if (getCodeResult !is GetCode.Record.Multiple) fail("code record not found") else {
            assertEquals(1, getCodeResult.items.size)
            assertEquals(
                "6080604052348015600f57600080fd5b506004361060285760003560e01c8063b69ef8a814602d575b600080fd5b60336049565b6040518082815260200191505060405180910390f35b60004790509056fea265627a7a723158201e67140e5829ab00a31e93e55b4815e847fb2621a4184d8f5dd0a575dfb7301964736f6c63430005100032",
                getCodeResult.items[0].code
            )
            assertEquals(getCodeResult.items[0].nonce, "1.0")
            assertEquals(getCodeResult.items[0].address, contract.accountIdentifier.pad256().toHexString())
        }

        // and when
        val balanceResponse = faultTolerant {
            contract.balance(EvmSender(
                2,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.contractAccountIdentifier
            )
            ).blockingGet()
        }

        // and then
        assertEquals(202, balanceResponse.statusCode)
        balanceResponse.assertConsoleString("return[0000000000000000000000000000000000000000000000000c7d713b49da0000]")

        // and when
        val balanceAfterCreateContract = getAccount.getEvmAccount(newAccountName).blockingGet()

        // and then
        if (balanceAfterCreateContract !is GetAccount.Record.Single) fail("Failed to check balance after create contract") else {
            assertEquals("0.9000 EVM", balanceAfterCreateContract.item.balance.toString())
        }
    }
}
package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.assertConsoleString
import com.memtrip.eos_evm.eos.AccountIdentifier
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.misc.IntArrayContract
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

class IntArrayContractTest {

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
    fun `The IntArray contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = IntArrayContract(
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
                "608060405234801561001057600080fd5b506004361061002b5760003560e01c8063dffeadd014610030575b600080fd5b610038610076565b6040518082600560200280838360005b83811015610063578082015181840152602081019050610048565b5050505090500191505060405180910390f35b61007e61012c565b60646000806005811061008d57fe5b018190555060c860006001600581106100a257fe5b018190555061012c60006002600581106100b857fe5b018190555061019060006003600581106100ce57fe5b01819055506101f460006004600581106100e457fe5b01819055506000600580602002604051908101604052809291908260058015610122576020028201915b81548152602001906001019080831161010e575b5050505050905090565b6040518060a0016040528060059060208202803883398082019150509050509056fea265627a7a723158204fccd77f13a8ae4c34649e2722dfe2584837c3fd1f4c00ef1604c3b131e2bdff64736f6c63430005100032",
                getCodeResult.items[0].code
            )
            assertEquals(getCodeResult.items[0].address, contract.accountIdentifier.pad256().toHexString())
        }
    }

    @Test
    fun `Call the main method on the ArrayDeleteContract`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(17000)

        val contract = IntArrayContract(
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

        // and given
        val (senderAccountName, senderPrivateKey, senderEthAccount) = setupTransactions.seedWithSystemBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        // and when
        val response = faultTolerant {
            contract.main(EvmSender(
                1,
                senderEthAccount,
                senderAccountName,
                senderPrivateKey,
                senderAccountIdentifier.toHexString()
            )).blockingGet()
        }

        // and then
        assertEquals(response.statusCode, 202)
        response.assertConsoleString("return[0000000000000000000000000000000000000000000000000000000000000064,00000000000000000000000000000000000000000000000000000000000000c8,000000000000000000000000000000000000000000000000000000000000012c,0000000000000000000000000000000000000000000000000000000000000190,00000000000000000000000000000000000000000000000000000000000001f4]")

        // and when
        val accountStateAfterDelegate = getAccountState.getAll(contract.accountIdentifier.pad256().toHexString()).blockingGet()

        // and then
        if (accountStateAfterDelegate !is GetAccountState.Record.Multiple) Assert.fail("no state saved") else {
            assertEquals(5, accountStateAfterDelegate.items.size)
            assertEquals("0000000000000000000000000000000000000000000000000000000000000064", accountStateAfterDelegate.items[0].value)
            assertEquals("00000000000000000000000000000000000000000000000000000000000000c8", accountStateAfterDelegate.items[1].value)
            assertEquals("000000000000000000000000000000000000000000000000000000000000012c", accountStateAfterDelegate.items[2].value)
            assertEquals("0000000000000000000000000000000000000000000000000000000000000190", accountStateAfterDelegate.items[3].value)
            assertEquals("00000000000000000000000000000000000000000000000000000000000001f4", accountStateAfterDelegate.items[4].value)
        }
    }
}
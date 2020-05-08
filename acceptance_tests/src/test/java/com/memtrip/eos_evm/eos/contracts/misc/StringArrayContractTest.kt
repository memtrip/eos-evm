package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.AccountIdentifier
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.misc.StringArrayContract
import com.memtrip.eos_evm.eos.faultTolerant
import com.memtrip.eos_evm.eos.state.GetAccountState
import com.memtrip.eos_evm.eos.evm.GetCode
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Assert.fail
import org.junit.Test
import java.util.concurrent.TimeUnit

class StringArrayContractTest {

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
    fun `The StringArray contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(17000)

        val contract = StringArrayContract(
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
            "608060405234801561001057600080fd5b506004361061002b5760003560e01c8063febb0f7e14610030575b600080fd5b6100386100b3565b6040518080602001828103825283818151815260200191508051906020019080838360005b8381101561007857808201518184015260208101905061005d565b50505050905090810190601f1680156100a55780820380516001836020036101000a031916815260200191505b509250505060405180910390f35b606060006001815481106100c357fe5b906000526020600020018054600181600116156101000203166002900480601f0160208091040260200160405190810160405280929190818152602001828054600181600116156101000203166002900480156101615780601f1061013657610100808354040283529160200191610161565b820191906000526020600020905b81548152906001019060200180831161014457829003601f168201915b505050505090509056fea265627a7a72315820bccccda8ab169771b837580ac1a33ba60d334bb6ae8b869fee56908119df820964736f6c63430005100032",
            createContract.code[0].code
        )
    }

    @Test
    fun `Call the main method on the ArrayDeleteContract`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(17000)

        val contract = StringArrayContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContract = contract.createContract().blockingGet()

        // then
        assertEquals(202, createContract.statusCode)

        // and given
        val (senderAccountName, senderPrivateKey, senderEthAccount) = setupTransactions.seedWithSystemBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        // and when
        val response = faultTolerant {
            contract.bar(
                EvmSender(
                    1,
                    senderEthAccount,
                    senderAccountName,
                    senderPrivateKey,
                    senderAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // and then
        assertEquals(response.statusCode, 202)

        // and when
        val accountStateAfterDelegate = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()

        // and then
        if (accountStateAfterDelegate !is GetAccountState.Record.Multiple) fail("no state saved") else {
            assertEquals(3, accountStateAfterDelegate.items.size)
            assertEquals("0000000000000000000000000000000000000000000000000000000000000002", accountStateAfterDelegate.items[0].value)
            // TODO: clarify these results
        }
    }
}
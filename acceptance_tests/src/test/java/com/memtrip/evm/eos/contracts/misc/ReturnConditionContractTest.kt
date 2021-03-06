package com.memtrip.evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.assertConsoleString
import com.memtrip.evm.eos.AccountIdentifier
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.contracts.misc.ReturnConditionContract
import com.memtrip.evm.eos.faultTolerant
import com.memtrip.evm.eos.state.GetAccountState
import com.memtrip.evm.eos.evm.GetCode
import com.memtrip.evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Test
import java.util.concurrent.TimeUnit

class ReturnConditionContractTest {

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
    fun `The ErrorTrap contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = ReturnConditionContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContract = contract.createContract().blockingGet()

        // then
        assertEquals(202, createContract.statusCode)
        assertEquals(1, createContract.code.size)
        assertEquals(
            "608060405234801561001057600080fd5b506004361061002b5760003560e01c80632fbebd3814610030575b600080fd5b61005c6004803603602081101561004657600080fd5b81019080803590602001909291905050506100de565b6040518080602001838152602001828103825284818151815260200191508051906020019080838360005b838110156100a2578082015181840152602081019050610087565b50505050905090810190601f1680156100cf5780820380516001836020036101000a031916815260200191505b50935050505060405180910390f35b6060600080606484101561012e57806040518060400160405280600981526020017f546f6f20736d616c6c000000000000000000000000000000000000000000000081525090925092505061014d565b6000600590508060405180602001604052806000815250909350935050505b91509156fea265627a7a7231582003bd2d298ab06361448903acbc6d2a4047ff9ddc1ac691d39ef7bcf183a8659264736f6c63430005100032",
            createContract.code[0].code
        )
    }

    @Test
    fun `The ErrorTrap contract produced trap`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = ReturnConditionContract(
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
        val fooResponse = faultTolerant {
            contract.foo(10, EvmSender(
                1,
                senderEthAccount,
                senderAccountName,
                senderPrivateKey,
                senderAccountIdentifier.toHexString()
            )).blockingGet()
        }

        assertEquals(202, fooResponse.statusCode)
        fooResponse.assertConsoleString("return[0000000000000000000000000000000000000000000000000000000000000040,0000000000000000000000000000000000000000000000000000000000000000,0000000000000000000000000000000000000000000000000000000000000009,546f6f20736d616c6c0000000000000000000000000000000000000000000000]")
    }

    @Test
    fun `The ErrorTrap contract did not produce a trap`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = ReturnConditionContract(
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
        val fooResponse = faultTolerant {
            contract.foo(101, EvmSender(
                1,
                senderEthAccount,
                senderAccountName,
                senderPrivateKey,
                senderAccountIdentifier.toHexString()
            )).blockingGet()
        }

        assertEquals(fooResponse.statusCode, 202)
    }
}
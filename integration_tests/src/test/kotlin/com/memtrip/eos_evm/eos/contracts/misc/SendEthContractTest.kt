package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.AccountIdentifier
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.misc.SendEthContract
import com.memtrip.eos_evm.eos.faultTolerant
import com.memtrip.eos_evm.eos.state.GetAccount
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

class SendEthContractTest {

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
    fun `The SendEth contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = SendEthContract(
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
                "608060405234801561001057600080fd5b50600436106100415760003560e01c80633e58c58c146100465780633fa26c8f1461008a5780636a0fac75146100ce575b600080fd5b6100886004803603602081101561005c57600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610112565b005b6100cc600480360360208110156100a057600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610153565b005b610110600480360360208110156100e457600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610194565b005b8073ffffffffffffffffffffffffffffffffffffffff166108fc670de0b6b3a76400009081150290604051600060405180830381858888f193505050505050565b8073ffffffffffffffffffffffffffffffffffffffff166108fc670de0b6b3a76400009081150290604051600060405180830381858888f193505050505050565b60008173ffffffffffffffffffffffffffffffffffffffff16670de0b6b3a764000060405180600001905060006040518083038185875af1925050503d80600081146101fc576040519150601f19603f3d011682016040523d82523d6000602084013e610201565b606091505b5050809150508061021557600061021457fe5b5b505056fea265627a7a723158206f2442af23fa33ef85370ca85bcb3052c48804d2077eddcdcf5c7a0f83e60f7864736f6c63430005100032",
                getCodeResult.items[0].code
            )
            assertEquals(getCodeResult.items[0].address, contract.accountIdentifier.pad256().toHexString())
        }
    }

    @Test
    fun `Call the send method`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance(
            17000,
            "10.0000")
        val contract = SendEthContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        val (senderAccountName, senderPrivateKey, senderEthAccount) = setupTransactions.seedWithEvmBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        // when
        val response = faultTolerant {
            contract.send(
                senderAccountIdentifier.toHexString(),
                EvmSender(
                    3,
                    newEthAccount,
                    newAccountName,
                    newAccountPrivateKey,
                    contract.accountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)

        // and when
        val getAccountResult = getAccount.getEvmAccount(newAccountName).blockingGet()

        // and then
        if (getAccountResult !is GetAccount.Record.Single) fail("account not found") else {
            assertEquals(
                "9.0000 EVM",
                getAccountResult.item.balance
            )
        }
    }

    @Test
    fun `Call the callIgnoreResult method`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance(
            17000,
            "10.0000")
        val contract = SendEthContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        val (senderAccountName, senderPrivateKey, senderEthAccount) = setupTransactions.seedWithEvmBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        // when
        val response = faultTolerant {
            contract.callIgnoreResult(
                senderAccountIdentifier.toHexString(),
                EvmSender(
                    3,
                    newEthAccount,
                    newAccountName,
                    newAccountPrivateKey,
                    contract.accountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)

        // and when
        val getAccountResult = getAccount.getEvmAccount(newAccountName).blockingGet()

        // and then
        if (getAccountResult !is GetAccount.Record.Single) fail("account not found") else {
            assertEquals(
                "9.0000 EVM",
                getAccountResult.item.balance
            )
        }
    }

    @Test
    fun `Call the callWithResult method`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance(
            17000, "10.0000")
        val contract = SendEthContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        val (senderAccountName, senderPrivateKey, senderEthAccount) = setupTransactions.seedWithEvmBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        // when
        val response = faultTolerant {
            contract.callWithResult(
                senderAccountIdentifier.toHexString(),
                EvmSender(
                    3,
                    newEthAccount,
                    newAccountName,
                    newAccountPrivateKey,
                    contract.accountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)

        // and when
        val getAccountResult = getAccount.getEvmAccount(newAccountName).blockingGet()

        // and then
        if (getAccountResult !is GetAccount.Record.Single) fail("account not found") else {
            assertEquals(
                "9.0000 EVM",
                getAccountResult.item.balance
            )
        }
    }
}
package com.memtrip.evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.eos.AccountIdentifier
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.contracts.misc.SendEthContract
import com.memtrip.evm.eos.faultTolerant
import com.memtrip.evm.eos.state.GetAccount
import com.memtrip.evm.ethereum.EthAsset
import com.memtrip.evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
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

    private val getAccount = GetAccount(chainApi)

    @Test
    fun `The SendEth contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()

        val contract = SendEthContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContract = contract.createContract(EthAsset.eth(1)).blockingGet()

        // then
        assertEquals(202, createContract.statusCode)

        // and when
        assertEquals(1, createContract.code.size)
        assertEquals(
            "608060405234801561001057600080fd5b50600436106100415760003560e01c80633e58c58c146100465780633fa26c8f1461008a5780636a0fac75146100ce575b600080fd5b6100886004803603602081101561005c57600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610112565b005b6100cc600480360360208110156100a057600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610153565b005b610110600480360360208110156100e457600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610194565b005b8073ffffffffffffffffffffffffffffffffffffffff166108fc670de0b6b3a76400009081150290604051600060405180830381858888f193505050505050565b8073ffffffffffffffffffffffffffffffffffffffff166108fc670de0b6b3a76400009081150290604051600060405180830381858888f193505050505050565b60008173ffffffffffffffffffffffffffffffffffffffff16670de0b6b3a764000060405180600001905060006040518083038185875af1925050503d80600081146101fc576040519150601f19603f3d011682016040523d82523d6000602084013e610201565b606091505b5050809150508061021557600061021457fe5b5b505056fea265627a7a72315820c97551ba526259c6777eb5b1bb8cf0d44c88d5711e081ef23c4ee5d0eddca59764736f6c63430005100032",
            createContract.code[0].code
        )
        assertEquals("1.0", createContract.code[0].nonce)
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
        val createContract = contract.createContract(EthAsset.eth(1)).blockingGet()
        assertEquals(202, createContract.statusCode)

        val (senderAccountName, _, senderEthAccount) = setupTransactions.seedWithEvmBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        // when
        val response = faultTolerant {
            contract.send(
                senderAccountIdentifier.toHexString(),
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
        val getAccountResult = getAccount.getEvmAccount(newAccountName).blockingGet()

        // and then
        if (getAccountResult !is GetAccount.Record.Single) fail("account not found") else {
            assertEquals(
                "9.0000 EVM",
                getAccountResult.item.balance.toString()
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
        val createContract = contract.createContract(EthAsset.eth(1)).blockingGet()
        assertEquals(202, createContract.statusCode)

        val (senderAccountName, _, senderEthAccount) = setupTransactions.seedWithEvmBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        // when
        val response = faultTolerant {
            contract.callIgnoreResult(
                senderAccountIdentifier.toHexString(),
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
        val getAccountResult = getAccount.getEvmAccount(newAccountName).blockingGet()

        // and then
        if (getAccountResult !is GetAccount.Record.Single) fail("account not found") else {
            assertEquals(
                "9.0000 EVM",
                getAccountResult.item.balance.toString()
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
        val createContract = contract.createContract(EthAsset.eth(1)).blockingGet()
        assertEquals(202, createContract.statusCode)

        val (senderAccountName, _, senderEthAccount) = setupTransactions.seedWithEvmBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        // when
        val response = faultTolerant {
            contract.callWithResult(
                senderAccountIdentifier.toHexString(),
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
        val getAccountResult = getAccount.getEvmAccount(newAccountName).blockingGet()

        // and then
        if (getAccountResult !is GetAccount.Record.Single) fail("account not found") else {
            assertEquals(
                "9.0000 EVM",
                getAccountResult.item.balance.toString()
            )
        }
    }
}
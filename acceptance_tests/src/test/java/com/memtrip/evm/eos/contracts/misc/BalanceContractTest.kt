package com.memtrip.evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.assertConsoleString
import com.memtrip.evm.eos.AccountIdentifier
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.contracts.misc.BalanceContract
import com.memtrip.evm.eos.faultTolerant
import com.memtrip.evm.ethereum.EthAsset
import com.memtrip.evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Test
import java.util.concurrent.TimeUnit

class BalanceContractTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    @Test
    fun `The Balance contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()

        val contract = BalanceContract(newAccountName, newAccountPrivateKey, newEthAccount)

        // when
        val createContract = contract.createContract(EthAsset.milliether(150)).blockingGet()

        // then
        assertEquals(202, createContract.statusCode)

        // and when
        assertEquals(1, createContract.code.size)
        assertEquals(
            "6080604052600436106100345760003560e01c806312065fe0146100395780633504672214610064578063ff18253b146100c9575b600080fd5b34801561004557600080fd5b5061004e6100e7565b6040518082815260200191505060405180910390f35b34801561007057600080fd5b506100b36004803603602081101561008757600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff1690602001909291905050506100ef565b6040518082815260200191505060405180910390f35b6100d1610110565b6040518082815260200191505060405180910390f35b600047905090565b60008173ffffffffffffffffffffffffffffffffffffffff16319050919050565b60003373ffffffffffffffffffffffffffffffffffffffff163190509056fea265627a7a723158205b9604325be704c379f90c25c7dd21e2a29a755c1c848e649b644c3add00089964736f6c63430005100032",
            createContract.code[0].code
        )
    }

    @Test
    fun `Get the contract balance`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val contract = BalanceContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract(EthAsset.milliether(150)).blockingGet()
        assertEquals(202, createContract.statusCode)

        // when
        val response = faultTolerant {
            contract.getBalance(
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
    fun `Get the balance of an address`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val contract = BalanceContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract(EthAsset.milliether(150)).blockingGet()
        assertEquals(202, createContract.statusCode)

        val (accountName, _, ethAccount) = setupTransactions.seedWithEvmBalance()
        val accountIdentifierHex = AccountIdentifier.create(accountName, ethAccount.address).toHexString()

        // when
        val response = faultTolerant {
            contract.getAddressBalance(
                accountIdentifierHex,
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
        response.assertConsoleString("return[0000000000000000000000000000000000000000000000000de0b6b3a7640000]")
    }

    @Test
    fun `Get the balance of the sender`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val contract = BalanceContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract(EthAsset.milliether(150)).blockingGet()
        assertEquals(202, createContract.statusCode)

        // when
        val response = faultTolerant {
            contract.getSenderBalance(
                EvmSender(
                    2,
                    newEthAccount,
                    newAccountName,
                    newAccountPrivateKey,
                    contract.ownerAccountIdentifier.toHexString(),
                    EthAsset.milliether(150)
                )
            ).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[00000000000000000000000000000000000000000000000009b6e64a8ec60000]")
    }
}
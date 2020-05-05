package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.assertConsoleString
import com.memtrip.eos_evm.eos.AccountIdentifier
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.ethereum.EthAsset
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.misc.MiniDAOContract
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
import java.math.BigInteger
import java.util.concurrent.TimeUnit

class MiniDAOContractTest {

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
    fun `The MiniDAO contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = MiniDAOContract(
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
                "6080604052600436106100345760003560e01c80632e1a7d4d14610039578063b69ef8a814610074578063d0e30db01461009f575b600080fd5b34801561004557600080fd5b506100726004803603602081101561005c57600080fd5b81019080803590602001909291905050506100a9565b005b34801561008057600080fd5b506100896101cd565b6040518082815260200191505060405180910390f35b6100a7610213565b005b806000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000205410156100f85760006100f757fe5b5b600060603373ffffffffffffffffffffffffffffffffffffffff168360405180600001905060006040518083038185875af1925050503d806000811461015a576040519150601f19603f3d011682016040523d82523d6000602084013e61015f565b606091505b50809250819350505081156101bf57826000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020600082825403925050819055506101c8565b60006101c757fe5b5b505050565b60008060003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002054905090565b346000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000206000828254019250508190555056fea265627a7a72315820bf6757b79b4f27dada4126fc425ebe94b2ac4bfcf76f3f9809396992581f4bd164736f6c63430005100032",
                getCodeResult.items[0].code
            )
            assertEquals(getCodeResult.items[0].address, contract.accountIdentifier.pad256().toHexString())
        }
    }

    @Test
    fun `Deposit funds in the DAO and check the balance`() {
        // given
        val (senderAccountName, senderPrivateKey, senderEthAccount) = setupTransactions.seedWithEvmBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val contract = MiniDAOContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val depositResponse = faultTolerant {
            contract.deposit(
                EvmSender(
                    1,
                    senderEthAccount,
                    senderAccountName,
                    senderPrivateKey,
                    senderAccountIdentifier.toHexString(),
                    EthAsset.milliether(10)
                )
            ).blockingGet()
        }

        // then
        assertEquals(202, depositResponse.statusCode)

        // and when
        val balanceResponse = faultTolerant {
            contract.balance(
                EvmSender(
                    2,
                    senderEthAccount,
                    senderAccountName,
                    senderPrivateKey,
                    senderAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // and then
        assertEquals(202, balanceResponse.statusCode)
        balanceResponse.assertConsoleString("return[000000000000000000000000000000000000000000000000002386f26fc10000]")

        // and when
        val balanceAfterDeposit = getAccount.getEvmAccount(senderAccountName).blockingGet()

        // and then
        if (balanceAfterDeposit !is GetAccount.Record.Single) Assert.fail("Failed to check balance after deposit") else {
            assertEquals("0.9900 EVM", balanceAfterDeposit.item.balance.toString())
        }
    }

    @Test
    fun `Deposit funds into the DAO, partially withdraw funds, and check the balance`() {
        // given
        val (senderAccountName, senderPrivateKey, senderEthAccount) = setupTransactions.seedWithEvmBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val contract = MiniDAOContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val depositResponse = faultTolerant {
            contract.deposit(
                EvmSender(1,
                    senderEthAccount,
                    senderAccountName,
                    senderPrivateKey,
                    senderAccountIdentifier.toHexString(),
                    EthAsset.milliether(100)
                )
            ).blockingGet()
        }

        // then
        assertEquals(202, depositResponse.statusCode)

        // and when
        val balanceAfterDeposit = getAccount.getEvmAccount(senderAccountName).blockingGet()

        // and then
        if (balanceAfterDeposit !is GetAccount.Record.Single) fail("Failed to check balance after deposit") else {
            assertEquals("0.9000 EVM", balanceAfterDeposit.item.balance.toString())
        }

        // when
        val withdrawResponse = faultTolerant {
            contract.withdraw(
                EthAsset.milliether(25),
                EvmSender(2,
                    senderEthAccount,
                    senderAccountName,
                    senderPrivateKey,
                    senderAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // then
        assertEquals(202, withdrawResponse.statusCode)

        // and when
        val balanceAfterWithdraw = getAccount.getEvmAccount(senderAccountName).blockingGet()

        // and then
        if (balanceAfterWithdraw !is GetAccount.Record.Single) fail("Failed to check balance after deposit") else {
            assertEquals("0.9250 EVM", balanceAfterWithdraw.item.balance.toString())
        }

        // and when
        val balanceResponse = faultTolerant {
            contract.balance(
                EvmSender(
                    3,
                    senderEthAccount,
                    senderAccountName,
                    senderPrivateKey,
                    senderAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // and then
        assertEquals(202, balanceResponse.statusCode)
        balanceResponse.assertConsoleString("return[000000000000000000000000000000000000000000000000010a741a46278000]")
    }

    @Test
    fun `Deposit funds into the DAO, attempt to withdraw more funds than exist for the sender`() {
        // given
        val (senderAccountName, senderPrivateKey, senderEthAccount) = setupTransactions.seedWithEvmBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val contract = MiniDAOContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val depositResponse = faultTolerant {
            contract.deposit(
                EvmSender(1,
                    senderEthAccount,
                    senderAccountName,
                    senderPrivateKey,
                    senderAccountIdentifier.toHexString(),
                    EthAsset.milliether(100)
                )
            ).blockingGet()
        }

        // then
        assertEquals(202, depositResponse.statusCode)

        // and when
        val balanceAfterDeposit = getAccount.getEvmAccount(senderAccountName).blockingGet()

        // and then
        if (balanceAfterDeposit !is GetAccount.Record.Single) fail("Failed to check balance after deposit") else {
            assertEquals("0.9000 EVM", balanceAfterDeposit.item.balance.toString())
        }

        // when
        val withdrawResponse = faultTolerant {
            contract.withdraw(
                EthAsset.milliether(110),
                EvmSender(2,
                    senderEthAccount,
                    senderAccountName,
                    senderPrivateKey,
                    senderAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // then
        assertEquals(500, withdrawResponse.statusCode)
    }
}
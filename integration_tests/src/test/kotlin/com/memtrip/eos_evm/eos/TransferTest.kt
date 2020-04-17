package com.memtrip.eos_evm.eos

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos.http.rpc.model.contract.request.GetCurrencyBalance
import com.memtrip.eos_evm.eos.Config.SYMBOL
import com.memtrip.eos_evm.eos.actions.withdraw.WithdrawAction
import com.memtrip.eos_evm.eos.state.GetAccount
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.*
import org.junit.Test
import java.util.concurrent.TimeUnit

class TransferTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val getAccount = GetAccount(chainApi)

    private val withdrawAction = WithdrawAction(chainApi)

    @Test
    fun `Successfully transfer tokens from an EOS account to an EVM account`() {

        // given
        val (accountName, privateKey) = setupTransactions.seedWithBalance()

        val startingBalance = getAccount.getEvmAccount(accountName).blockingGet()
        if (startingBalance !is GetAccount.Record.Single) fail("Failed to create account") else {
            assertEquals("0.0000 EVM", startingBalance.item.asset)
        }

        // when
        val transferResult = setupTransactions.transfer(
            "eos.evm",
            "0.0010 $SYMBOL",
            "evm funds",
            accountName,
            privateKey,
            "eosio.token"
        ).blockingGet()

        // then
        assertEquals(202, transferResult.statusCode)

        val endingBalance = getAccount.getEvmAccount(accountName).blockingGet()
        if (endingBalance !is GetAccount.Record.Single) fail("Failed to create account") else {
            assertEquals("0.0010 EVM", endingBalance.item.asset)
        }
    }

    @Test
    fun `Successfully transfer tokens from an EOS account to an EVM account, and withdraw the tokens`() {

        // given
        val (accountName, privateKey) = setupTransactions.seedWithBalance()

        val startingBalance = getAccount.getEvmAccount(accountName).blockingGet()
        if (startingBalance !is GetAccount.Record.Single) fail("Failed to create account") else {
            assertEquals("0.0000 EVM", startingBalance.item.asset)
        }

        // when
        val transferResult = setupTransactions.transfer(
            "eos.evm",
            "0.0010 $SYMBOL",
            "evm funds",
            accountName,
            privateKey,
            "eosio.token"
        ).blockingGet()

        // then
        assertEquals(202, transferResult.statusCode)

        val endingBalance = getAccount.getEvmAccount(accountName).blockingGet()
        if (endingBalance !is GetAccount.Record.Single) fail("Failed to create account") else {
            assertEquals("0.0010 EVM", endingBalance.item.asset)
        }

        // and when
        val withdrawResult = withdrawAction.pushTransaction(
            accountName,
            "0.0010 $SYMBOL",
            TransactionContext(
                accountName,
                privateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // and then
        assertEquals(202, withdrawResult.statusCode)

        val finalBalance = getAccount.getEvmAccount(accountName).blockingGet()
        if (finalBalance !is GetAccount.Record.Single) fail("Failed to create account") else {
            assertEquals("0.0000 EVM", finalBalance.item.asset)
        }

        // and when
        val tokenBalanceResult =  chainApi.getCurrencyBalance(
            GetCurrencyBalance("eosio.token", accountName, "EVM")
        ).blockingGet()

        // and then
        assertEquals(200, tokenBalanceResult.code())

        val balances = tokenBalanceResult.body()
        if (balances == null || balances.isEmpty()) fail("Failed to retrieve eosio.token balance") else {
            assertEquals("1.0000 EVM", balances.first())
        }
    }

    @Test
    fun `The transfer account must be linked to an ethereum account`() {

        // given
        val accountName = generateUniqueAccountName()
        val privateKey = EosPrivateKey()
        val createAccountResponse = setupTransactions.createAccount(
            accountName, privateKey).blockingGet()

        val transferInitialFunds = setupTransactions.transfer(
            accountName,
            "1.0000 $SYMBOL",
            "seed",
            Config.CONTRACT_ACCOUNT_NAME,
            EosPrivateKey(Config.SEED_PRIVATE_KEY),
            "eosio.token"
        ).blockingGet()

        assertEquals(202, createAccountResponse.statusCode)
        assertEquals(202, transferInitialFunds.statusCode)

        // when
        val transferResult = setupTransactions.transfer(
            "eos.evm",
            "0.0010 $SYMBOL",
            "evm funds",
            accountName,
            privateKey,
            "eosio.token"
        ).blockingGet()

        // then
        assertEquals(500, transferResult.statusCode)
        assertTrue(
            transferResult.containsErrorString(
                "The `from` account is not linked to an Ethereum account."
            )
        )
    }

    @Test
    fun `A positive value is required to trigger a withdraw transfer`() {

        // given
        val (accountName, privateKey) = setupTransactions.seedWithBalance()

        val startingBalance = getAccount.getEvmAccount(accountName).blockingGet()
        if (startingBalance !is GetAccount.Record.Single) fail("Failed to create account") else {
            assertEquals("0.0000 EVM", startingBalance.item.asset)
        }

        // when
        val transferResult = setupTransactions.transfer(
            "eos.evm",
            "0.0010 $SYMBOL",
            "evm funds",
            accountName,
            privateKey,
            "eosio.token"
        ).blockingGet()

        // then
        assertEquals(202, transferResult.statusCode)

        val endingBalance = getAccount.getEvmAccount(accountName).blockingGet()
        if (endingBalance !is GetAccount.Record.Single) fail("Failed to create account") else {
            assertEquals("0.0010 EVM", endingBalance.item.asset)
        }

        // and when
        val withdrawResult = withdrawAction.pushTransaction(
            accountName,
            "0.0000 $SYMBOL",
            TransactionContext(
                accountName,
                privateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // and then
        assertEquals(500, withdrawResult.statusCode)
        assertTrue(
            withdrawResult.containsErrorString(
                "Please provide a withdraw quantity."
            )
        )
    }

    @Test
    fun `The EVM account associated with the withdraw must have sufficient balance`() {

        // given
        val (accountName, privateKey) = setupTransactions.seedWithBalance()

        val startingBalance = getAccount.getEvmAccount(accountName).blockingGet()
        if (startingBalance !is GetAccount.Record.Single) fail("Failed to create account") else {
            assertEquals("0.0000 EVM", startingBalance.item.asset)
        }

        // when
        val transferResult = setupTransactions.transfer(
            "eos.evm",
            "0.0010 $SYMBOL",
            "evm funds",
            accountName,
            privateKey,
            "eosio.token"
        ).blockingGet()

        // then
        assertEquals(202, transferResult.statusCode)

        val endingBalance = getAccount.getEvmAccount(accountName).blockingGet()
        if (endingBalance !is GetAccount.Record.Single) fail("Failed to create account") else {
            assertEquals("0.0010 EVM", endingBalance.item.asset)
        }

        // and when
        val withdrawResult = withdrawAction.pushTransaction(
            accountName,
            "0.2000 $SYMBOL",
            TransactionContext(
                accountName,
                privateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // and then
        assertEquals(500, withdrawResult.statusCode)
        assertTrue(
            withdrawResult.containsErrorString(
                "Insufficient funds."
            )
        )
    }

    @Test
    fun `A withdraw can only be performed by an EVM account`() {

        // given
        val accountName = generateUniqueAccountName()
        val privateKey = EosPrivateKey()
        val createAccountResponse = setupTransactions.createAccount(
            accountName, privateKey).blockingGet()

        assertEquals(202, createAccountResponse.statusCode)

        // when
        val withdrawResult = withdrawAction.pushTransaction(
            accountName,
            "1.0000 $SYMBOL",
            TransactionContext(
                accountName,
                privateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // and then
        assertEquals(500, withdrawResult.statusCode)
        assertTrue(
            withdrawResult.containsErrorString(
                "The `to` account is not linked to an Ethereum account."
            )
        )
    }
}
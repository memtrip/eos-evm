package com.memtrip.eos_evm.eos

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.actions.execute.ExecuteAction
import com.memtrip.eos_evm.eos.actions.raw.RawAction
import com.memtrip.eos_evm.eos.state.GetAccount
import com.memtrip.eos_evm.ethereum.EthAsset.Companion.WEI
import com.memtrip.eos_evm.eos.state.GetAccountState
import com.memtrip.eos_evm.ethereum.AccountStateKey
import com.memtrip.eos_evm.ethereum.EthereumTransaction
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Test
import java.math.BigInteger
import java.util.concurrent.TimeUnit

class BalanceTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val executeAction = ExecuteAction(chainApi)

    private val getAccountState = GetAccountState(chainApi)

    private val getAccount = GetAccount(chainApi)

    @Test
    fun `The empty balance of the sender is stored in the account state`() {

        // given
        val (accountName, accountPrivateKey, ethAccount) = setupTransactions.seed()

        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger("0de0b6b3a7640000", 16),
            ""
        )
        val signedTransaction = transaction.sign(ethAccount).signedTransaction.toHexString()

        val accountIdentifier = AccountIdentifier.create(accountName, ethAccount.address)
        val response = executeAction.pushTransaction(
            accountName,
            signedTransaction,
            accountIdentifier.toHexString(),
            "3331600055",
            TransactionContext(
                accountName,
                accountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // then
        assertEquals(202, response.statusCode)

        val balance = getAccountState.getValue(
            accountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x00)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000000", balance)
    }

    @Test
    fun `The sender balance of 0_5000 is stored in the account state`() {

        // given
        val (accountName, accountPrivateKey, ethAccount) = setupTransactions.seedWithSystemBalance()
        val accountIdentifier = AccountIdentifier.create(accountName, ethAccount.address)

        val balanceBeforeTransfer = getAccount.getEvmAccount(accountName).blockingGet()
        if (balanceBeforeTransfer is GetAccount.Record.Single) {
            assertEquals("0.0000 EVM", balanceBeforeTransfer.item.balance.toString())
        }

        // when
        val transferResult = setupTransactions.transfer(
            "eos.evm",
            "0.5000 ${Config.SYMBOL}",
            "evm funds",
            accountName,
            accountPrivateKey,
            "eosio.token"
        ).blockingGet()

        // then
        assertEquals(202, transferResult.statusCode)

        val balanceAfterTransfer = getAccount.getEvmAccount(accountName).blockingGet()
        if (balanceAfterTransfer is GetAccount.Record.Single) {
            assertEquals("0.5000 EVM", balanceAfterTransfer.item.balance.toString())
        }

        // and when
        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger("0de0b6b3a7640000", 16),
            ""
        )
        val signedTransaction = transaction.sign(ethAccount).signedTransaction.toHexString()

        val balanceResponse = executeAction.pushTransaction(
            accountName,
            signedTransaction,
            accountIdentifier.toHexString(),
            "3331600055",
            TransactionContext(
                accountName,
                accountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // and then
        assertEquals(202, balanceResponse.statusCode)

        val balance = getAccountState.getValue(
            accountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x00)
        ).blockingGet()

        val expected = BigInteger("1388", 16) * WEI
        assertEquals(expected.toByteArray().pad256().toHexString(), balance)
    }
}
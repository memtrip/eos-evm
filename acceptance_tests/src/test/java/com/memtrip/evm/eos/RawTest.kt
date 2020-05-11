package com.memtrip.evm.eos

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.assertConsoleError
import com.memtrip.evm.eos.actions.raw.RawAction
import com.memtrip.evm.ethereum.EthAccount
import com.memtrip.evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Test
import java.util.concurrent.TimeUnit

class RawTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val rawAction = RawAction(chainApi)

    @Test
    fun `Unsigned transaction must include a valid sender`() {

        // given
        val (newAccountName, newAccountPrivateKey, _) = setupTransactions.seed()

        val unsignedTransaction = stubTransaction().sign(EthAccount.create()).unsignedTransaction.toHexString()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        // when
        val response = rawAction.pushTransaction(
            newAccountName,
            unsignedTransaction,
            "invalid_sender",
            TransactionContext(
                newAccountName,
                newAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // then
        response.assertConsoleError("Could not find sender, did you provide the correct account identifier?")
    }

    @Test
    fun `Unsigned transaction can only be signed by the EOS account associated with the sender account identifier`() {

        // given (action account)
        val (actionAccountName, actionAccountPrivateKey, _) = setupTransactions.seed()

        // given (sender account)
        val (senderAccountName, _, senderEthAccount) = setupTransactions.seed()

        // given (unsigned transaction)
        val unsignedTransaction = stubTransaction().sign(EthAccount.create()).unsignedTransaction.toHexString()

        // when
        val response = rawAction.pushTransaction(
            actionAccountName,
            unsignedTransaction,
            AccountIdentifier.create(senderAccountName, senderEthAccount.address).toHexString(),
            TransactionContext(
                actionAccountName,
                actionAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // then
        response.assertConsoleError("You do not have permission to execute a transaction for the specified sender.")
    }

    @Test
    fun `The account identifier associated with a signed transaction must exist in the Account table`() {

        // given (action account)
        val (actionAccountName, actionAccountPrivateKey, _) = setupTransactions.seed()

        // given (signed transaction)
        val signedTransaction = stubTransaction().sign(EthAccount.create()).signedTransaction.toHexString()

        // when
        val response = rawAction.pushTransaction(
            actionAccountName,
            signedTransaction,
            "",
            TransactionContext(
                actionAccountName,
                actionAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // then
        response.assertConsoleError("The account identifier associated with this transaction does not exist.")
    }
}
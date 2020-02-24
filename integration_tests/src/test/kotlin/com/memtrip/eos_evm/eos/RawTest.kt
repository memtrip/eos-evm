package com.memtrip.eos_evm.eos

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.raw.RawAction
import com.memtrip.eos_evm.ethereum.EthAccount
import com.memtrip.eos_evm.ethereum._0x
import com.memtrip.eos_evm.ethereum.toHex
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertTrue
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
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val unsignedTransaction = stubTransaction().sign(EthAccount.create()).unsignedTransaction

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        // when
        val response = rawAction.pushTransaction(
            newAccountName,
            unsignedTransaction.toHex(),
            "invalid_sender",
            TransactionContext(
                newAccountName,
                newAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // then
        assertTrue(
            response.containsErrorString(
                "Could not find sender, did you provide the correct account identifier?"
            )
        )
    }

    @Test
    fun `Unsigned transaction can only be signed by the EOS account associated with the sender account identifier`() {

        // given (action account)
        val actionAccountName = generateUniqueAccountName()
        val actionAccountPrivateKey = EosPrivateKey()
        val actionEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            actionAccountName,
            actionAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            actionAccountName,
            actionAccountPrivateKey,
            actionEthAccount
        ).blockingGet()

        // given (sender account)
        val senderAccountName = generateUniqueAccountName()
        val senderAccountPrivateKey = EosPrivateKey()
        val senderEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            senderAccountName,
            senderAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            senderAccountName,
            senderAccountPrivateKey,
            senderEthAccount
        ).blockingGet()

        // given (unsigned transaction)
        val unsignedTransaction = stubTransaction().sign(EthAccount.create()).unsignedTransaction

        // when
        val response = rawAction.pushTransaction(
            actionAccountName,
            unsignedTransaction.toHex()._0x(),
            AccountIdentifier.create(senderAccountName, senderEthAccount.address).toHex(),
            TransactionContext(
                actionAccountName,
                actionAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // then
        assertTrue(
            response.containsErrorString(
                "You do not have permission to execute a transaction for the specified sender."
            )
        )
    }

    @Test
    fun `The account identifier associated with a signed transaction must exist in the Account table`() {

        // given (action account)
        val actionAccountName = generateUniqueAccountName()
        val actionAccountPrivateKey = EosPrivateKey()
        val actionEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            actionAccountName,
            actionAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            actionAccountName,
            actionAccountPrivateKey,
            actionEthAccount
        ).blockingGet()

        // given (signed transaction)
        val signedTransaction = stubTransaction().sign(EthAccount.create()).signedTransaction

        // when
        val response = rawAction.pushTransaction(
            actionAccountName,
            signedTransaction.toHex()._0x(),
            "",
            TransactionContext(
                actionAccountName,
                actionAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // then
        assertTrue(
            response.containsErrorString(
                "The account identifier associated with this transaction does not exist."
            )
        )
    }
}
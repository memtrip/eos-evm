package com.memtrip.eos_evm.eos

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.ChainApi
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import io.reactivex.Single
import com.memtrip.eos.chain.actions.transaction.account.CreateAccountChain
import com.memtrip.eos_evm.eos.Config.CONTRACT_ACCOUNT_NAME
import com.memtrip.eos_evm.eos.Config.ISSUE_PRIVATE_KEY
import com.memtrip.eos_evm.eos.create.CreateAction
import com.memtrip.eos_evm.ethereum.EthAccount
import java.lang.IllegalStateException

class SetupTransactions(
    private val chainApi: ChainApi,
    private val createAction: CreateAction = CreateAction(chainApi)
) {

    data class TestAccounts(
        val eosAccount: String,
        val eosPrivateKey: EosPrivateKey,
        val ethAccount: EthAccount
    )

    fun seed(): TestAccounts {
        for (i in 0 until 3) {
            val newAccountName = generateUniqueAccountName()
            val newAccountPrivateKey = EosPrivateKey()
            val newEthAccount = EthAccount.create()

            val createAccountResult = createAccount(
                newAccountName,
                newAccountPrivateKey
            ).blockingGet()

            val createEthAccountResult = createEthAccount(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount
            ).blockingGet()

            if (createAccountResult.isSuccessful && createEthAccountResult.isSuccessful) {
                return TestAccounts(
                    newAccountName,
                    newAccountPrivateKey,
                    newEthAccount
                )
            }
        }

        throw IllegalStateException("Failed to seed the test accounts")
    }

    fun createAccount(
        accountName: String,
        privateKey: EosPrivateKey
    ): Single<ChainResponse<TransactionCommitted>> {

        val signatureProviderPrivateKey = EosPrivateKey(ISSUE_PRIVATE_KEY)

        return CreateAccountChain(chainApi).createAccount(
            CreateAccountChain.Args(
                accountName,
                CreateAccountChain.Args.Quantity(
                7048,
                "0.0100 ${Config.SYMBOL}",
                "0.0100 ${Config.SYMBOL}"),
                privateKey.publicKey,
                privateKey.publicKey,
                true
            ),
            TransactionContext(
                CONTRACT_ACCOUNT_NAME,
                signatureProviderPrivateKey,
                transactionDefaultExpiry()
            )
        )
    }

    fun createEthAccount(
        accountName: String,
        privateKey: EosPrivateKey,
        ethAccount: EthAccount
    ): Single<ChainResponse<TransactionCommitted>> {

        return createAction.pushTransaction(
            accountName,
            ethAccount.address,
            TransactionContext(
                accountName,
                privateKey,
                transactionDefaultExpiry()
            )
        )
    }
}
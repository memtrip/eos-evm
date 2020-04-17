package com.memtrip.eos_evm.eos

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.ChainApi
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import io.reactivex.Single
import com.memtrip.eos.chain.actions.transaction.account.CreateAccountChain
import com.memtrip.eos.chain.actions.transaction.transfer.TransferChain
import com.memtrip.eos_evm.eos.Config.CONTRACT_ACCOUNT_NAME
import com.memtrip.eos_evm.eos.Config.SEED_PRIVATE_KEY
import com.memtrip.eos_evm.eos.Config.SYMBOL
import com.memtrip.eos_evm.eos.actions.create.CreateAction
import com.memtrip.eos_evm.ethereum.EthAccount
import java.lang.IllegalStateException

class SetupTransactions(
    private val chainApi: ChainApi,
    private val createAction: CreateAction = CreateAction(chainApi),
    private val createAccountChain: CreateAccountChain = CreateAccountChain(chainApi),
    private val transferChain: TransferChain = TransferChain(chainApi),
    private val seedPrivateKey: EosPrivateKey = EosPrivateKey(SEED_PRIVATE_KEY)
) {

    data class TestEthAccount(
        val eosAccount: String,
        val eosPrivateKey: EosPrivateKey,
        val ethAccount: EthAccount
    )

    fun seed(): TestEthAccount {
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
                return TestEthAccount(
                    newAccountName,
                    newAccountPrivateKey,
                    newEthAccount
                )
            }
        }

        throw IllegalStateException("Failed to seed the test accounts")
    }

    fun seedWithBalance(): TestEthAccount {
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

            val transferResult = transfer(
                newAccountName,
                "1.0000 $SYMBOL",
                "seed",
                CONTRACT_ACCOUNT_NAME,
                seedPrivateKey,
                "eosio.token"
            ).blockingGet()

            if (createAccountResult.isSuccessful && createEthAccountResult.isSuccessful && transferResult.isSuccessful) {
                return TestEthAccount(
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

        return createAccountChain.createAccount(
            CreateAccountChain.Args(
                accountName,
                CreateAccountChain.Args.Quantity(
                7048,
                "0.0100 $SYMBOL",
                "0.0100 $SYMBOL"),
                privateKey.publicKey,
                privateKey.publicKey,
                true
            ),
            TransactionContext(
                CONTRACT_ACCOUNT_NAME,
                seedPrivateKey,
                transactionDefaultExpiry()
            )
        )
    }

    fun transfer(
        to: String,
        amount: String,
        memo: String,
        from: String,
        fromPrivateKey: EosPrivateKey,
        contract: String
    ): Single<ChainResponse<TransactionCommitted>> {
        return transferChain.transfer(
            contract,
            TransferChain.Args(
                from,
                to,
                amount,
                memo
            ),
            TransactionContext(
                from,
                fromPrivateKey,
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
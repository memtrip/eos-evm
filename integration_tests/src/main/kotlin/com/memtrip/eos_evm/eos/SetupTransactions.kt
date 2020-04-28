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
import com.memtrip.eos_evm.eos.Config.DEFAULT_RAM_ISSUE
import com.memtrip.eos_evm.eos.Config.FAULT_THRESHOLD
import com.memtrip.eos_evm.eos.Config.SEED_PRIVATE_KEY
import com.memtrip.eos_evm.eos.Config.SYMBOL
import com.memtrip.eos_evm.eos.actions.create.CreateAction
import com.memtrip.eos_evm.eos.actions.execute.ExecuteAction
import com.memtrip.eos_evm.ethereum.EthAccount
import com.memtrip.eos_evm.ethereum.EthereumTransaction
import com.memtrip.eos_evm.ethereum.toHexString
import java.lang.IllegalStateException
import java.math.BigInteger

class SetupTransactions(
    private val chainApi: ChainApi,
    private val createAction: CreateAction = CreateAction(chainApi),
    private val createAccountChain: CreateAccountChain = CreateAccountChain(chainApi),
    private val transferChain: TransferChain = TransferChain(chainApi),
    private val executeAction: ExecuteAction = ExecuteAction(chainApi),
    private val seedPrivateKey: EosPrivateKey = EosPrivateKey(SEED_PRIVATE_KEY)
) {

    data class TestEthAccount(
        val eosAccount: String,
        val eosPrivateKey: EosPrivateKey,
        val ethAccount: EthAccount
    )

    fun seed(ramIssued: Long = DEFAULT_RAM_ISSUE): TestEthAccount {
        for (i in 0 until FAULT_THRESHOLD) {
            val newAccountName = generateUniqueAccountName()
            val newAccountPrivateKey = EosPrivateKey()
            val newEthAccount = EthAccount.create()

            val createAccountResult = faultTolerant {
                createAccount(
                    newAccountName,
                    newAccountPrivateKey,
                    ramIssued
                ).blockingGet()
            }

            val createEthAccountResult = faultTolerant {
                createEthAccount(
                    newAccountName,
                    newAccountPrivateKey,
                    newEthAccount
                ).blockingGet()
            }

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

    fun seedWithSystemBalance(): TestEthAccount {
        for (i in 0 until FAULT_THRESHOLD) {
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

    fun seedWithEvmBalance(ramIssued: Long = DEFAULT_RAM_ISSUE): TestEthAccount {
        for (i in 0 until FAULT_THRESHOLD) {
            val newAccountName = generateUniqueAccountName()
            val newAccountPrivateKey = EosPrivateKey()
            val newEthAccount = EthAccount.create()

            val createAccountResult = createAccount(
                newAccountName,
                newAccountPrivateKey,
                ramIssued
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

            val evmTransferResult = transfer(
                "eos.evm",
                "1.0000 ${Config.SYMBOL}",
                "evm funds",
                newAccountName,
                newAccountPrivateKey,
                "eosio.token"
            ).blockingGet()

            if (createAccountResult.isSuccessful && createEthAccountResult.isSuccessful && transferResult.isSuccessful && evmTransferResult.isSuccessful) {
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
        privateKey: EosPrivateKey,
        ramIssued: Long = DEFAULT_RAM_ISSUE
    ): Single<ChainResponse<TransactionCommitted>> {

        return createAccountChain.createAccount(
            CreateAccountChain.Args(
                accountName,
                CreateAccountChain.Args.Quantity(
                    ramIssued,
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

    fun sstore(
        accountName: String,
        privateKey: EosPrivateKey,
        ethAccount: EthAccount,
        key: String,
        value: String
    ): Single<ChainResponse<TransactionCommitted>> {

        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x"
        )
        val signedTransaction = transaction.sign(ethAccount).signedTransaction.toHexString()

        val instruction = "7F${value}60${key}55"

        return executeAction.pushTransaction(
            accountName,
            signedTransaction,
            ethAccount.address,
            instruction,
            TransactionContext(
                accountName,
                privateKey,
                transactionDefaultExpiry()
            )
        )
    }
}
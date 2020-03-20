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

class SetupTransactions(
    private val chainApi: ChainApi,
    private val createAction: CreateAction = CreateAction(chainApi)
) {

    fun createAccount(
        accountName: String,
        privateKey: EosPrivateKey
    ): Single<ChainResponse<TransactionCommitted>> {

        val signatureProviderPrivateKey = EosPrivateKey(ISSUE_PRIVATE_KEY)

        return CreateAccountChain(chainApi).createAccount(
            CreateAccountChain.Args(
                accountName,
                CreateAccountChain.Args.Quantity(
                3048,
                "0.0100 EOS",
                "0.0100 EOS"),
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
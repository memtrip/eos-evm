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

class SetupTransactions(
    private val chainApi: ChainApi
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
                "0.1000 EOS",
                "1.0000 EOS"),
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
}
package com.memtrip.eos_evm.eos.actions.withdraw

import com.memtrip.eos.abi.writer.compression.CompressionType
import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.chain.actions.transaction.ChainTransaction
import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.chain.actions.transaction.abi.ActionAbi
import com.memtrip.eos.chain.actions.transaction.abi.TransactionAuthorizationAbi
import com.memtrip.eos.http.rpc.ChainApi
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.AbiBinaryGenEvmWriter
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.actions.withdraw.abi.WithdrawArgs
import com.memtrip.eos_evm.eos.actions.withdraw.abi.WithdrawBody
import io.reactivex.Single

class WithdrawAction(chainApi: ChainApi) : ChainTransaction(chainApi) {

    fun pushTransaction(
        to: String,
        quantity: String,
        transactionContext: TransactionContext
    ): Single<ChainResponse<TransactionCommitted>> {
        return push(
            transactionContext.expirationDate,
            listOf(
                ActionAbi(
                    Config.CONTRACT_ACCOUNT_NAME,
                    "withdraw",
                    listOf(
                        TransactionAuthorizationAbi(
                            transactionContext.authorizingAccountName,
                            "active")
                    ),
                    bin(to, quantity)
                )
            ),
            transactionContext.authorizingPrivateKey
        )
    }

    private fun bin(to: String, quantity: String): String {
        return AbiBinaryGenEvmWriter(CompressionType.NONE).squishWithdrawBody(
            WithdrawBody(WithdrawArgs(to, quantity))
        ).toHex()
    }
}
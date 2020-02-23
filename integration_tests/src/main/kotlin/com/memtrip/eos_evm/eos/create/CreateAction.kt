package com.memtrip.eos_evm.eos.create

import com.memtrip.eos.abi.writer.compression.CompressionType
import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.chain.actions.transaction.ChainTransaction
import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.chain.actions.transaction.abi.ActionAbi
import com.memtrip.eos.chain.actions.transaction.abi.TransactionAuthorizationAbi
import com.memtrip.eos.http.rpc.ChainApi
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.AbiBinaryGenEvmWriter
import com.memtrip.eos_evm.eos.Config.CONTRACT_ACCOUNT_NAME
import com.memtrip.eos_evm.eos.create.abi.CreateArgs
import com.memtrip.eos_evm.eos.create.abi.CreateBody
import io.reactivex.Single

class CreateAction(chainApi: ChainApi) : ChainTransaction(chainApi) {

    fun pushTransaction(
        from: String,
        message: String,
        transactionContext: TransactionContext
    ): Single<ChainResponse<TransactionCommitted>> {
        return push(
            transactionContext.expirationDate,
            listOf(
                ActionAbi(
                    CONTRACT_ACCOUNT_NAME,
                    "create",
                    listOf(
                        TransactionAuthorizationAbi(
                            transactionContext.authorizingAccountName,
                            "active")
                    ),
                    bin(from, message)
                )
            ),
            transactionContext.authorizingPrivateKey
        )
    }

    private fun bin(
        from: String,
        message: String
    ): String {
        return AbiBinaryGenEvmWriter(CompressionType.NONE).squishCreateBody(
            CreateBody(
                CreateArgs(
                    from,
                    message
                )
            )
        ).toHex()
    }
}
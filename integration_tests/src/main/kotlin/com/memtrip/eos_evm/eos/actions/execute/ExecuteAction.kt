package com.memtrip.eos_evm.eos.actions.execute

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
import com.memtrip.eos_evm.eos.actions.execute.abi.ExecuteArgs
import com.memtrip.eos_evm.eos.actions.execute.abi.ExecuteBody
import io.reactivex.Single

class ExecuteAction(chainApi: ChainApi) : ChainTransaction(chainApi) {

    fun pushTransaction(
        from: String,
        code: String,
        sender: String,
        bytecode: String,
        transactionContext: TransactionContext
    ): Single<ChainResponse<TransactionCommitted>> {
        return push(
            transactionContext.expirationDate,
            listOf(
                ActionAbi(
                    Config.CONTRACT_ACCOUNT_NAME,
                    "execute",
                    listOf(
                        TransactionAuthorizationAbi(transactionContext.authorizingAccountName, "active")
                    ),
                    bin(from, code, sender, bytecode)
                )
            ),
            transactionContext.authorizingPrivateKey
        )
    }

    private fun bin(from: String, code: String, sender: String, bytecode: String): String {
        return AbiBinaryGenEvmWriter(CompressionType.NONE).squishExecuteBody(
            ExecuteBody(ExecuteArgs(from, code, sender, bytecode))
        ).toHex()
    }
}
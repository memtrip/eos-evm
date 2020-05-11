package com.memtrip.evm.eos.evm.contracts

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.evm.eos.evm.GetCode

data class CreateResponse(
    val response: ChainResponse<TransactionCommitted>,
    val code: List<GetCode.Item>,
    val parentContractAddress32: String,
    val statusCode: Int = response.statusCode
)
package com.memtrip.eos_evm.eos.evm.contracts.openzeppelin.math

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.evm.EvmContract
import com.memtrip.eos_evm.ethereum.EthAccount
import io.reactivex.Single

class SafeMathContract (
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x60566023600b82828239805160001a607314601657fe5b30600052607381538281f3fe73000000000000000000000000000000000000000030146080604052600080fdfea2646970667358221220fc7b294a7888254c2fd8ded3c21c1d445c4aac9950a657cc6bbf430319c3c82e64736f6c63430006060033"
) {

    fun createContract(): Single<ChainResponse<TransactionCommitted>> {
        return create()
    }
}
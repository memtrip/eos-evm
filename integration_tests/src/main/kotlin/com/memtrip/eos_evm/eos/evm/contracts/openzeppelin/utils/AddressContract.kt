package com.memtrip.eos_evm.eos.evm.contracts.openzeppelin.utils

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.evm.EvmContract
import com.memtrip.eos_evm.ethereum.EthAccount
import io.reactivex.Single

class AddressContract (
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x60566023600b82828239805160001a607314601657fe5b30600052607381538281f3fe73000000000000000000000000000000000000000030146080604052600080fdfea26469706673582212200bd35bda2df713354f2655226f2c201150b5fd720cc8f4154f76ed89181e7fac64736f6c63430006060033"
) {

    fun createContract(): Single<ChainResponse<TransactionCommitted>> {
        return create()
    }
}
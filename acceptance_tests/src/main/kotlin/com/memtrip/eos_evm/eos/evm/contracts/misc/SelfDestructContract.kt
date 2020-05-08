package com.memtrip.eos_evm.eos.evm.contracts.misc

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.evm.EvmContract
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.CreateResponse
import com.memtrip.eos_evm.ethereum.EthAccount
import io.reactivex.Single
import org.web3j.abi.TypeReference
import org.web3j.abi.datatypes.Type
import org.web3j.abi.datatypes.Uint
import java.math.BigInteger

class SelfDestructContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405266038d7ea4c68000341015601757600080fd5b60b1806100256000396000f3fe6080604052348015600f57600080fd5b506004361060325760003560e01c8063b69ef8a8146037578063e9fad8ee146053575b600080fd5b603d605b565b6040518082815260200191505060405180910390f35b60596063565b005b600047905090565b3373ffffffffffffffffffffffffffffffffffffffff16fffea265627a7a72315820a342b6a6d2f7f3321a6100757f6f36633d5e11913994ca88e749d05b0718c62264736f6c63430005100032"
) {

    fun createContract(value: BigInteger): Single<CreateResponse> {
        return create(listOf(), value)
    }

    fun balance(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "balance",
            listOf(),
            listOf(object : TypeReference<Type<Uint>>() { }),
            sender
        )
    }

    fun exit(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "exit",
            listOf(),
            listOf(),
            sender
        )
    }
}
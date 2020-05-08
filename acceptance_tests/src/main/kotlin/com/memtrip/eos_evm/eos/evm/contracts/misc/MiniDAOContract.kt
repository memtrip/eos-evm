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
import org.web3j.abi.datatypes.Uint
import java.math.BigInteger

class MiniDAOContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405234801561001057600080fd5b50610296806100206000396000f3fe6080604052600436106100345760003560e01c80632e1a7d4d14610039578063b69ef8a814610074578063d0e30db01461009f575b600080fd5b34801561004557600080fd5b506100726004803603602081101561005c57600080fd5b81019080803590602001909291905050506100a9565b005b34801561008057600080fd5b506100896101cd565b6040518082815260200191505060405180910390f35b6100a7610213565b005b806000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000205410156100f85760006100f757fe5b5b600060603373ffffffffffffffffffffffffffffffffffffffff168360405180600001905060006040518083038185875af1925050503d806000811461015a576040519150601f19603f3d011682016040523d82523d6000602084013e61015f565b606091505b50809250819350505081156101bf57826000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020600082825403925050819055506101c8565b60006101c757fe5b5b505050565b60008060003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002054905090565b346000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000206000828254019250508190555056fea265627a7a72315820bf6757b79b4f27dada4126fc425ebe94b2ac4bfcf76f3f9809396992581f4bd164736f6c63430005100032"
) {

    fun createContract(): Single<CreateResponse> {
        return create(listOf())
    }

    fun deposit(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "deposit",
            listOf(),
            listOf(),
            sender
        )
    }

    fun balance(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "balance",
            listOf(),
            listOf(object : TypeReference<Uint>() { }),
            sender
        )
    }

    fun withdraw(amount: BigInteger, sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "withdraw",
            listOf(Uint(amount)),
            listOf(),
            sender
        )
    }
}
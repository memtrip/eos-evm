package com.memtrip.eos_evm.eos.evm.contracts.misc

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.evm.EvmContract
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.ethereum.EthAccount
import io.reactivex.Single
import org.web3j.abi.datatypes.Address

/**
pragma solidity ^0.5.11;

contract SendEth {

    function send(address payable recipient) public {
        recipient.send(1 ether);
    }

    function callIgnoreResult(address payable recipient) public {
        recipient.send(1 ether);
    }

    function callWithResult(address payable recipient) public {
        bool success;
        (success,) = recipient.call.value(1 ether)("");
        if(!success) assert(false);
    }
}
*/
class SendEthContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405234801561001057600080fd5b5061024e806100206000396000f3fe608060405234801561001057600080fd5b50600436106100415760003560e01c80633e58c58c146100465780633fa26c8f1461008a5780636a0fac75146100ce575b600080fd5b6100886004803603602081101561005c57600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610112565b005b6100cc600480360360208110156100a057600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610153565b005b610110600480360360208110156100e457600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610194565b005b8073ffffffffffffffffffffffffffffffffffffffff166108fc670de0b6b3a76400009081150290604051600060405180830381858888f193505050505050565b8073ffffffffffffffffffffffffffffffffffffffff166108fc670de0b6b3a76400009081150290604051600060405180830381858888f193505050505050565b60008173ffffffffffffffffffffffffffffffffffffffff16670de0b6b3a764000060405180600001905060006040518083038185875af1925050503d80600081146101fc576040519150601f19603f3d011682016040523d82523d6000602084013e610201565b606091505b5050809150508061021557600061021457fe5b5b505056fea265627a7a723158206f2442af23fa33ef85370ca85bcb3052c48804d2077eddcdcf5c7a0f83e60f7864736f6c63430005100032"
) {

    fun createContract(): Single<ChainResponse<TransactionCommitted>> {
        return create(listOf())
    }

    fun send(recipient: String, sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "send",
            listOf(Address(recipient)),
            listOf(),
            sender
        )
    }

    fun callIgnoreResult(recipient: String, sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "callIgnoreResult",
            listOf(Address(recipient)),
            listOf(),
            sender
        )
    }

    fun callWithResult(recipient: String, sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "callWithResult",
            listOf(Address(recipient)),
            listOf(),
            sender
        )
    }
}
package com.memtrip.eos_evm.eos.evm.contracts.misc

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.evm.EvmContract
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.ethereum.EthAccount
import io.reactivex.Single
import org.web3j.abi.TypeReference
import org.web3j.abi.datatypes.*

/**
pragma solidity ^0.5.11;

contract Proposal {
    mapping (address => bool) approvals;
    bytes32 public approvalMask;
    bytes32 public approver1;
    bytes32 public approver2;
    bytes32 public target;

    constructor(address thirdParty) public {
        approver1 = bytes32(uint256(thirdParty));
        approver2 = bytes32(uint256(msg.sender));
        target = approver1 | approver2;
    }

    function approve(address approver) public {
        approvalMask |= bytes32(uint256(approver));
        approvals[approver] = true;
    }

    function isApproved() public view returns(bool) {
        return approvalMask == target;
    }
}
*/
class ProposalContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405234801561001057600080fd5b506040516102c43803806102c48339818101604052602081101561003357600080fd5b81019080805190602001909291905050508073ffffffffffffffffffffffffffffffffffffffff1660001b6002819055503373ffffffffffffffffffffffffffffffffffffffff1660001b6003819055506003546002541760048190555050610223806100a16000396000f3fe608060405234801561001057600080fd5b50600436106100625760003560e01c80630cc0e1fb1461006757806328f371aa146100855780636b1d752b146100a7578063d4b83992146100c5578063daea85c5146100e3578063eb6fd96a14610127575b600080fd5b61006f610145565b6040518082815260200191505060405180910390f35b61008d61014b565b604051808215151515815260200191505060405180910390f35b6100af610159565b6040518082815260200191505060405180910390f35b6100cd61015f565b6040518082815260200191505060405180910390f35b610125600480360360208110156100f957600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610165565b005b61012f6101e8565b6040518082815260200191505060405180910390f35b60035481565b600060045460015414905090565b60025481565b60045481565b8073ffffffffffffffffffffffffffffffffffffffff1660001b60016000828254179250508190555060016000808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060006101000a81548160ff02191690831515021790555050565b6001548156fea265627a7a72315820a60e9f060ca75c3ecb2f1802174a2de71b07c27b8ab109e575719f0c0b404ef564736f6c63430005100032"
) {

    fun createContract(address: String): Single<ChainResponse<TransactionCommitted>> {
        return create(listOf(Address(address)))
    }

    fun approve(address: String, sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "approve",
            listOf(Address(address)),
            listOf(),
            sender
        )
    }

    fun isApproved(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "isApproved",
            listOf(),
            listOf(object : TypeReference<Bool>() { }),
            sender
        )
    }
}
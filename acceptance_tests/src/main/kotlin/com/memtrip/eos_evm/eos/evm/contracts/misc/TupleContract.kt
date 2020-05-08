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

/**
pragma solidity ^0.5.11;

contract Tuple {
    function tuple() private pure returns(uint, string memory) {
        return (1, "Hi");
    }

    function getOne() public pure returns(uint) {
        uint a;
        (a,) = tuple();
        return a;
    }
}
*/
class TupleContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x6080604052348015600f57600080fd5b5060da8061001e6000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063ab5ed15014602d575b600080fd5b60336049565b6040518082815260200191505060405180910390f35b6000806052605e565b50809150508091505090565b6000606060018090506040518060400160405280600281526020017f486900000000000000000000000000000000000000000000000000000000000081525091509150909156fea265627a7a7231582014e7a484ae72de63d610eee5700f82beb654743f08478ca0c91c5147159df3c764736f6c63430005100032"
) {

    fun createContract(): Single<CreateResponse> {
        return create(listOf())
    }

    fun getOne(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "getOne",
            listOf(),
            listOf(object : TypeReference<Type<Uint>>() { }),
            sender
        )
    }
}
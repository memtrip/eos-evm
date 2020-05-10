package com.memtrip.eos_evm.eos.evm.contracts.misc

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.evm.EvmContract
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.CreateResponse
import com.memtrip.eos_evm.ethereum.EthAccount
import io.reactivex.Single
import java.math.BigInteger

/**
pragma solidity ^0.5.11;

import "./SelfDestruct.sol";

contract SelfDestructChild {

    SelfDestruct child;

    constructor() payable public {
        child = (new SelfDestruct).value(msg.value)();
    }

    function exitChild() public {
        child.exit();
    }
}
*/
class SelfDestructChildContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x60806040523460405161001190610073565b6040518091039082f08015801561002c573d6000803e3d6000fd5b5090506000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555061007f565b60d68061017883390190565b60eb8061008d6000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063f0c597dd14602d575b600080fd5b60336035565b005b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1663e9fad8ee6040518163ffffffff1660e01b8152600401600060405180830381600087803b158015609d57600080fd5b505af115801560b0573d6000803e3d6000fd5b5050505056fea265627a7a7231582083a9bac0ccfd83c6ccb14c524ab352e0a75c3ed58554a296ee38cbd57f7ae55d64736f6c63430005100032608060405266038d7ea4c68000341015601757600080fd5b60b1806100256000396000f3fe6080604052348015600f57600080fd5b506004361060325760003560e01c8063b69ef8a8146037578063e9fad8ee146053575b600080fd5b603d605b565b6040518082815260200191505060405180910390f35b60596063565b005b600047905090565b3373ffffffffffffffffffffffffffffffffffffffff16fffea265627a7a72315820a342b6a6d2f7f3321a6100757f6f36633d5e11913994ca88e749d05b0718c62264736f6c63430005100032"
) {

    fun createContract(value: BigInteger): Single<CreateResponse> {
        return create(listOf(), value)
    }

    fun exitChild(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "exitChild",
            listOf(),
            listOf(),
            sender
        )
    }
}
package com.memtrip.evm.eos.evm.contracts.misc

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.evm.eos.evm.EvmContract
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.contracts.CreateResponse
import com.memtrip.evm.ethereum.EthAccount
import io.reactivex.Single
import java.math.BigInteger

/**
pragma solidity ^0.5.11;

contract RevertMe {
    constructor() public payable {
    }
}

contract RevertCreateChild {

    RevertMe revertMe;

    constructor() public {
    }

    function create() public payable {
        revertMe = (new RevertMe).value(msg.value)();
        revert("do not create the RevertMe contract");
    }
}

contract RevertCreate {

    RevertCreateChild child;

    constructor() public payable {
        child = new RevertCreateChild();
    }

    function createChild() public {
        child.create.value(address(this).balance);
    }
}
*/
class RevertCreateContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405260405161001090610071565b604051809103906000f08015801561002c573d6000803e3d6000fd5b506000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555061007e565b6101bb8061010583390190565b60798061008c6000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063a3a4ba3114602d575b600080fd5b60336035565b005b6000809054906101000a90505056fea265627a7a7231582026dd7bc956212ed74abd364ccb7df367a6030de4f79a56fd1bf803c9d0a14fb264736f6c63430005100032608060405234801561001057600080fd5b5061019b806100206000396000f3fe60806040526004361061001e5760003560e01c8063efc81a8c14610023575b600080fd5b61002b61002d565b005b3460405161003a906100e8565b6040518091039082f080158015610055573d6000803e3d6000fd5b5090506000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff1602179055506040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260238152602001806101446023913960400191505060405180910390fd5b604f806100f58339019056fe6080604052603e8060116000396000f3fe6080604052600080fdfea265627a7a7231582036fdb05fde318805a00ee7d04f0cf8d0b2ae3190de6e1944175db57ca219309c64736f6c63430005100032646f206e6f742063726561746520746865205265766572744d6520636f6e7472616374a265627a7a7231582067c7fe59e8dc51cea0ba13ceeec2a1c8a2e3ea8d61192d7ed40bfd369e798dd764736f6c63430005100032"
) {

    fun createContract(value: BigInteger): Single<CreateResponse> {
        return create(listOf(), value)
    }

    fun createChild(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "createChild",
            listOf(),
            listOf(),
            sender
        )
    }
}
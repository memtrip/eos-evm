package com.memtrip.eos_evm.eos.evm.contracts.misc

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.evm.EvmContract
import com.memtrip.eos_evm.eos.evm.contracts.CreateResponse
import com.memtrip.eos_evm.ethereum.EthAccount
import io.reactivex.Single

/**
pragma solidity ^0.5.11;

contract MappingDelete {

    struct Data {
        uint a;
        uint b;
    }

    mapping (uint => Data) public items;

    constructor() public {
        items[0] = Data(1,2);
        items[1] = Data(3,4);
        items[2] = Data(5,6);
        delete items[1];
    }
}
*/
class MappingDeleteContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405234801561001057600080fd5b506040518060400160405280600181526020016002815250600080808152602001908152602001600020600082015181600001556020820151816001015590505060405180604001604052806003815260200160048152506000806001815260200190815260200160002060008201518160000155602082015181600101559050506040518060400160405280600581526020016006815250600080600281526020019081526020016000206000820151816000015560208201518160010155905050600080600181526020019081526020016000206000808201600090556001820160009055505060cc806101076000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063bfb231d214602d575b600080fd5b605660048036036020811015604157600080fd5b81019080803590602001909291905050506073565b604051808381526020018281526020019250505060405180910390f35b6000602052806000526040600020600091509050806000015490806001015490508256fea265627a7a72315820b347531998585fd491671776cf64ddf668f3bd22990178431371cd918eb3abbd64736f6c63430005100032"
) {

    fun createContract(): Single<CreateResponse> {
        return create(listOf())
    }
}
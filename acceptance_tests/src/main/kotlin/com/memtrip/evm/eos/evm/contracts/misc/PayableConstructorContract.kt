package com.memtrip.evm.eos.evm.contracts.misc

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.evm.eos.evm.EvmContract
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.contracts.CreateResponse
import com.memtrip.evm.ethereum.EthAccount
import io.reactivex.Single
import org.web3j.abi.TypeReference
import org.web3j.abi.datatypes.Type
import org.web3j.abi.datatypes.Uint
import java.math.BigInteger

/**
pragma solidity ^0.5.11;

contract PayableConstructor {

    constructor() public payable {
    }

    function balance() public view returns (uint) {
        return address(this).balance;
    }
}
*/
class PayableConstructorContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405266038d7ea4c68000341015601757600080fd5b3460008190555060868061002c6000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063b69ef8a814602d575b600080fd5b60336049565b6040518082815260200191505060405180910390f35b60004790509056fea265627a7a723158201e67140e5829ab00a31e93e55b4815e847fb2621a4184d8f5dd0a575dfb7301964736f6c63430005100032"
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
}
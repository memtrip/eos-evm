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

contract SelfDestruct {

    uint storage1;
    uint storage2;
    uint storage3;

    constructor() public payable {
        require(msg.value >= 1000000000000000);
        storage1 = 1;
        storage2 = 2;
        storage3 = 3;
    }

    function balance() public view returns (uint) {
        return address(this).balance;
    }

    function exit() public {
        return selfdestruct(msg.sender);
    }
}
*/
class SelfDestructContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405266038d7ea4c6800034101561001857600080fd5b60016000819055506002600181905550600360028190555060b18061003e6000396000f3fe6080604052348015600f57600080fd5b506004361060325760003560e01c8063b69ef8a8146037578063e9fad8ee146053575b600080fd5b603d605b565b6040518082815260200191505060405180910390f35b60596063565b005b600047905090565b3373ffffffffffffffffffffffffffffffffffffffff16fffea265627a7a7231582041289775868e81f3076f17de839e0bd9ed95120826665a354cae1ec15e23c21864736f6c63430005100032"
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
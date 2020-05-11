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
import org.web3j.abi.datatypes.Address
import org.web3j.abi.datatypes.Type
import org.web3j.abi.datatypes.Uint
import java.math.BigInteger

/**
pragma solidity ^0.5.11;

contract Balance {

    constructor() public payable {
    }

    function getBalance() public returns(uint) {
        return address(this).balance;
    }

    function getAddressBalance(address sender) public returns(uint) {
        return address(sender).balance;
    }
}
*/
class BalanceContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x6080604052610164806100136000396000f3fe6080604052600436106100345760003560e01c806312065fe0146100395780633504672214610064578063ff18253b146100c9575b600080fd5b34801561004557600080fd5b5061004e6100e7565b6040518082815260200191505060405180910390f35b34801561007057600080fd5b506100b36004803603602081101561008757600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff1690602001909291905050506100ef565b6040518082815260200191505060405180910390f35b6100d1610110565b6040518082815260200191505060405180910390f35b600047905090565b60008173ffffffffffffffffffffffffffffffffffffffff16319050919050565b60003373ffffffffffffffffffffffffffffffffffffffff163190509056fea265627a7a723158205b9604325be704c379f90c25c7dd21e2a29a755c1c848e649b644c3add00089964736f6c63430005100032"
) {

    fun createContract(value: BigInteger): Single<CreateResponse> {
        return create(listOf(), value)
    }

    fun getBalance(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "getBalance",
            listOf(),
            listOf(object : TypeReference<Type<Uint>>() { }),
            sender
        )
    }

    fun getAddressBalance(address: String, sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "getAddressBalance",
            listOf(Address(address)),
            listOf(object : TypeReference<Type<Uint>>() { }),
            sender
        )
    }

    fun getSenderBalance(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
                "getSenderBalance",
                listOf(),
                listOf(object : TypeReference<Type<Uint>>() { }),
                sender
        )
    }
}
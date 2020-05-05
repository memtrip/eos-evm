package com.memtrip.eos_evm.eos.evm.contracts.misc

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.evm.EvmContract
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.ethereum.EthAccount
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

function payMake() payable public returns(uint) {
    PayableConstructor child = (new PayableConstructor).value(msg.value)();
    return child.balance();
}

function make(uint value) public returns(uint) {
    PayableConstructor child = (new PayableConstructor).value(value)();
    return child.balance();
}
 */
class PayableFactoryContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405234801561001057600080fd5b506102fe806100206000396000f3fe6080604052600436106100295760003560e01c8063516517ab1461002e5780635aead1c51461007d575b600080fd5b34801561003a57600080fd5b506100676004803603602081101561005157600080fd5b810190808035906020019092919050505061009b565b6040518082815260200191505060405180910390f35b610085610154565b6040518082815260200191505060405180910390f35b600080826040516100ab9061020b565b6040518091039082f0801580156100c6573d6000803e3d6000fd5b50905090508073ffffffffffffffffffffffffffffffffffffffff1663b69ef8a86040518163ffffffff1660e01b815260040160206040518083038186803b15801561011157600080fd5b505afa158015610125573d6000803e3d6000fd5b505050506040513d602081101561013b57600080fd5b8101908080519060200190929190505050915050919050565b600080346040516101649061020b565b6040518091039082f08015801561017f573d6000803e3d6000fd5b50905090508073ffffffffffffffffffffffffffffffffffffffff1663b69ef8a86040518163ffffffff1660e01b815260040160206040518083038186803b1580156101ca57600080fd5b505afa1580156101de573d6000803e3d6000fd5b505050506040513d60208110156101f457600080fd5b810190808051906020019092919050505091505090565b60b2806102188339019056fe608060405266038d7ea4c68000341015601757600080fd5b3460008190555060868061002c6000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063b69ef8a814602d575b600080fd5b60336049565b6040518082815260200191505060405180910390f35b60004790509056fea265627a7a723158201e67140e5829ab00a31e93e55b4815e847fb2621a4184d8f5dd0a575dfb7301964736f6c63430005100032a265627a7a723158204d0e45beb9af12f34b2071d78b689b2070ac7c789d4ba0d04763001e938b211764736f6c63430005100032"
) {

    fun createContract(): Single<ChainResponse<TransactionCommitted>> {
        return create(listOf())
    }

    fun payMake(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "payMake",
            listOf(),
            listOf(object : TypeReference<Type<Uint>>() { }),
            sender
        )
    }

    fun make(value: BigInteger, sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "make",
            listOf(Uint(value)),
            listOf(object : TypeReference<Type<Uint>>() { }),
            sender
        )
    }
}
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
import org.web3j.abi.datatypes.Address
import org.web3j.abi.datatypes.generated.Uint256
import java.math.BigInteger

/**
pragma solidity ^0.5.11;

contract BasicToken {

    mapping(address => uint256) balances;

    constructor() public {
        balances[msg.sender] = 15000000;
    }

    function transfer(address recipient, uint256 value) public {
        balances[msg.sender] -= value;
        balances[recipient] += value;
    }

    function balanceOf(address account) public view returns (uint256) {
        return balances[account];
    }
}
*/
class BasicTokenContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405234801561001057600080fd5b5062e4e1c06000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020819055506101fa806100666000396000f3fe608060405234801561001057600080fd5b50600436106100365760003560e01c806370a082311461003b578063a9059cbb14610093575b600080fd5b61007d6004803603602081101561005157600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff1690602001909291905050506100e1565b6040518082815260200191505060405180910390f35b6100df600480360360408110156100a957600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190505050610129565b005b60008060008373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020549050919050565b806000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060008282540392505081905550806000808473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060008282540192505081905550505056fea265627a7a723158206cd6bdb9d9779d30a4f5bab15baadea00a6ca7a723ad04549b29d5477684678f64736f6c63430005100032"
) {

    fun createContract(): Single<CreateResponse> {
        return create(listOf())
    }

    fun transfer(address: String, value: Long, sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "transfer",
            listOf(Address(address), Uint256(BigInteger.valueOf(value))),
            listOf(),
            sender
        )
    }

    fun balanceOf(address: String, sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "balanceOf",
            listOf(Address(address)),
            listOf(object : TypeReference<Uint256>() { }),
            sender
        )
    }
}
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
import org.web3j.abi.datatypes.generated.Uint256
import java.math.BigInteger

/**
pragma solidity ^0.5.11;

contract DynamicCall {

    uint x = 0;

    function foo(uint _x) public {
        x = 10 + _x;
    }

    function bar() public returns(uint) {
        (bool a, bytes memory result) = address(this).call(abi.encode(bytes4(keccak256('foo(uint256)')), 1));
        return x; // returns 11
    }
}
*/
class DynamicCallContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x60806040526000805534801561001457600080fd5b5061022d806100246000396000f3fe608060405234801561001057600080fd5b50600436106100365760003560e01c80632fbebd381461003b578063febb0f7e14610069575b600080fd5b6100676004803603602081101561005157600080fd5b8101908080359060200190929190505050610087565b005b610071610094565b6040518082815260200191505060405180910390f35b80600a0160008190555050565b60008060603073ffffffffffffffffffffffffffffffffffffffff1660405180807f666f6f2875696e74323536290000000000000000000000000000000000000000815250600c0190506040518091039020600160405160200180837bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19167bffffffffffffffffffffffffffffffffffffffffffffffffffffffff191681526020018260ff168152602001925050506040516020818303038152906040526040518082805190602001908083835b60208310610182578051825260208201915060208101905060208303925061015f565b6001836020036101000a0380198251168184511680821785525050505050509050019150506000604051808303816000865af19150503d80600081146101e4576040519150601f19603f3d011682016040523d82523d6000602084013e6101e9565b606091505b5091509150600054925050509056fea265627a7a7231582073b60d229026f9e49ad9d300e07e48201a07c72d29fa0695b1252f7cb2927b7b64736f6c63430005100032"
) {

    fun createContract(): Single<ChainResponse<TransactionCommitted>> {
        return create(listOf())
    }

    fun bar(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "bar",
            listOf(),
            listOf(object : TypeReference<Type<Uint256>>() { }, object : TypeReference<Type<Uint256>>() { }),
            sender
        )
    }
}
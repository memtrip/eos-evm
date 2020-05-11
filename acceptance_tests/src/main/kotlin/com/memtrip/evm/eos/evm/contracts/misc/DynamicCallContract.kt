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

contract DynamicCall {

    uint x = 0;

    function foo(uint _x) public {
        x = 10 + _x;
    }

    function bar() public returns(uint) {
        (bool a, bytes memory result) = address(this).call(abi.encode(bytes4(keccak256('foo(uint256)')), 1));
        return x;
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
    "0x60806040526000805534801561001457600080fd5b5061022a806100246000396000f3fe608060405234801561001057600080fd5b50600436106100365760003560e01c80632fbebd381461003b578063febb0f7e14610069575b600080fd5b6100676004803603602081101561005157600080fd5b8101908080359060200190929190505050610087565b005b610071610094565b6040518082815260200191505060405180910390f35b80600a0160008190555050565b60008060603073ffffffffffffffffffffffffffffffffffffffff1660405180807f666f6f2875696e74323536290000000000000000000000000000000000000000815250600c0190506040518091039020600160405160200180837bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19167bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19168152602001828152602001925050506040516020818303038152906040526040518082805190602001908083835b6020831061017f578051825260208201915060208101905060208303925061015c565b6001836020036101000a0380198251168184511680821785525050505050509050019150506000604051808303816000865af19150503d80600081146101e1576040519150601f19603f3d011682016040523d82523d6000602084013e6101e6565b606091505b5091509150600054925050509056fea265627a7a7231582005d06ced8dc0b3c591c328c1ce4aaf10f8e110ed04b68674e8ad389b6a52d90d64736f6c63430005100032"
) {

    fun createContract(): Single<CreateResponse> {
        return create(listOf())
    }

    fun foo(value: Long, sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "foo",
            listOf(Uint(BigInteger.valueOf(value))),
            listOf(object : TypeReference<Type<Uint>>() { }, object : TypeReference<Type<Uint>>() { }),
            sender
        )
    }

    fun bar(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "bar",
            listOf(),
            listOf(object : TypeReference<Type<Uint>>() { }, object : TypeReference<Type<Uint>>() { }),
            sender
        )
    }
}
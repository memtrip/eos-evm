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
import org.web3j.abi.datatypes.generated.Uint256
import java.math.BigInteger

/**
pragma solidity ^0.5.11;

contract ReturnCondition {
    function foo(uint a) public pure returns(string memory, uint) {
        uint nullReturn;
        if(a < 100) {
            return('Too small', nullReturn);
        }
        uint b = 5;
        return ('', b);
    }
}
*/
class ReturnConditionContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405234801561001057600080fd5b50610187806100206000396000f3fe608060405234801561001057600080fd5b506004361061002b5760003560e01c80632fbebd3814610030575b600080fd5b61005c6004803603602081101561004657600080fd5b81019080803590602001909291905050506100de565b6040518080602001838152602001828103825284818151815260200191508051906020019080838360005b838110156100a2578082015181840152602081019050610087565b50505050905090810190601f1680156100cf5780820380516001836020036101000a031916815260200191505b50935050505060405180910390f35b6060600080606484101561012e57806040518060400160405280600981526020017f546f6f20736d616c6c000000000000000000000000000000000000000000000081525090925092505061014d565b6000600590508060405180602001604052806000815250909350935050505b91509156fea265627a7a7231582003bd2d298ab06361448903acbc6d2a4047ff9ddc1ac691d39ef7bcf183a8659264736f6c63430005100032"
) {

    fun createContract(): Single<CreateResponse> {
        return create(listOf())
    }

    fun foo(value: Long, sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "foo",
            listOf(Uint256(BigInteger.valueOf(value))),
            listOf(object : TypeReference<Type<String>>() { }, object : TypeReference<Type<Uint>>() { }),
            sender
        )
    }
}
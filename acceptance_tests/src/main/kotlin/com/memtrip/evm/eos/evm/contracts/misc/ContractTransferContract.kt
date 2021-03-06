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
import org.web3j.abi.datatypes.Uint
import java.math.BigInteger

/**
pragma solidity ^0.5.11;

import "./PayableConstructor.sol";
import "./PayableFallbackContract.sol";

contract ContractTransfer {
    uint seedAmount;
    PayableConstructor child1;
    PayableFallbackContract child2;

    constructor() public payable {
        seedAmount = msg.value;
        child1 = (new PayableConstructor).value(seedAmount)();
        child2 = new PayableFallbackContract();
    }

    function transfer() public {
        child1.transfer(address(uint160(address(child2))), seedAmount);
    }

    function child2Balance() public returns(uint) {
        return child2.balance();
    }
}
*/
class ContractTransferContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x60806040523460008190555060005460405161001a906100e6565b6040518091039082f080158015610035573d6000803e3d6000fd5b509050600160006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff160217905550604051610084906100f3565b604051809103906000f0801580156100a0573d6000803e3d6000fd5b50600260006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff1602179055506100ff565b6101c48061033783390190565b60b1806104fb83390190565b6102298061010e6000396000f3fe608060405234801561001057600080fd5b50600436106100365760003560e01c8063150a06da1461003b5780638a4068dd14610059575b600080fd5b610043610063565b6040518082815260200191505060405180910390f35b61006161010d565b005b6000600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1663b69ef8a86040518163ffffffff1660e01b815260040160206040518083038186803b1580156100cd57600080fd5b505afa1580156100e1573d6000803e3d6000fd5b505050506040513d60208110156100f757600080fd5b8101908080519060200190929190505050905090565b600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1663a9059cbb600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff166000546040518363ffffffff1660e01b8152600401808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200182815260200192505050600060405180830381600087803b1580156101da57600080fd5b505af11580156101ee573d6000803e3d6000fd5b5050505056fea265627a7a723158208ffcff90cbf8522864156cc107926d9d21eb85c43404fdd6e8f234f8305e1ab264736f6c63430005100032608060405266038d7ea4c6800034101561001857600080fd5b346000819055506101968061002e6000396000f3fe608060405234801561001057600080fd5b50600436106100415760003560e01c806340c4d94114610046578063a9059cbb14610090578063b69ef8a8146100de575b600080fd5b61004e6100fc565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6100dc600480360360408110156100a657600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190505050610104565b005b6100e6610159565b6040518082815260200191505060405180910390f35b600030905090565b80600054101561011057fe5b8060008082825403925050819055508173ffffffffffffffffffffffffffffffffffffffff166108fc829081150290604051600060405180830381858888f19350505050505050565b60004790509056fea265627a7a723158201f52b9f50d419b8778ecc28108e9f36e9ad38b2b1c0e5723cd2143be265268e864736f6c634300051000326080604052348015600f57600080fd5b5060938061001e6000396000f3fe608060405260043610601c5760003560e01c8063b69ef8a814602d575b346000808282540192505081905550005b348015603857600080fd5b50603f6055565b6040518082815260200191505060405180910390f35b6000805490509056fea265627a7a723158206ac80067d3f015c42e8793ac9375e67b0b5d2f7e12c838820ba966f9cef6d65064736f6c63430005100032"
) {

    fun createContract(value: BigInteger): Single<CreateResponse> {
        return create(listOf(), value)
    }

    fun transfer(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "transfer",
            listOf(),
            listOf(),
            sender
        )
    }

    fun child2Balance(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "child2Balance",
            listOf(),
            listOf(object : TypeReference<Uint>() { }),
            sender
        )
    }
}
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

/**
pragma solidity ^0.5.11;

contract LengthValue {
    uint[] public nums;

    constructor() public {
        nums.push(10);
        nums.push(20);
        nums.push(30);
        nums.push(40);
        nums.push(50);
    }

    function getNumLength() public view returns(uint) {
        return nums.length;
    }
}

contract PublicLength {
    LengthValue lengthValue;

    constructor() public {
        lengthValue = new LengthValue();
    }

    function test() public view returns (uint) {
        return lengthValue.getNumLength();
    }
}
*/
class PublicLengthContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405234801561001057600080fd5b5060405161001d9061007e565b604051809103906000f080158015610039573d6000803e3d6000fd5b506000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555061008b565b6101f3806101be83390190565b6101248061009a6000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063f8a8fd6d14602d575b600080fd5b60336049565b6040518082815260200191505060405180910390f35b60008060009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff166333b779556040518163ffffffff1660e01b815260040160206040518083038186803b15801560b157600080fd5b505afa15801560c4573d6000803e3d6000fd5b505050506040513d602081101560d957600080fd5b810190808051906020019092919050505090509056fea265627a7a72315820fa05caa2f43753e3f959dc20ebab902ec875dfe544613f33ab6a5b1fcdeb9a7764736f6c63430005100032608060405234801561001057600080fd5b506000600a90806001815401808255809150509060018203906000526020600020016000909192909190915055506000601490806001815401808255809150509060018203906000526020600020016000909192909190915055506000601e908060018154018082558091505090600182039060005260206000200160009091929091909150555060006028908060018154018082558091505090600182039060005260206000200160009091929091909150555060006032908060018154018082558091505090600182039060005260206000200160009091929091909150555060f3806101006000396000f3fe6080604052348015600f57600080fd5b506004361060325760003560e01c806333b77955146037578063fd1ee54c146053575b600080fd5b603d6092565b6040518082815260200191505060405180910390f35b607c60048036036020811015606757600080fd5b8101908080359060200190929190505050609e565b6040518082815260200191505060405180910390f35b60008080549050905090565b6000818154811060aa57fe5b90600052602060002001600091509050548156fea265627a7a723158204ff2745c468bff5a5ba57c96f3bba49d977e9b473ad476a3a74b8c6fb45ecd6664736f6c63430005100032"
) {

    fun createContract(): Single<ChainResponse<TransactionCommitted>> {
        return create(listOf())
    }

    fun test(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "test",
            listOf(),
            listOf(object : TypeReference<Type<Uint>>() { }),
            sender
        )
    }
}
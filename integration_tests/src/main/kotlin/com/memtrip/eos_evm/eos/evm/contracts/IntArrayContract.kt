package com.memtrip.eos_evm.eos.evm.contracts

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.evm.EvmContract
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.ethereum.EthAccount
import io.reactivex.Single
import org.web3j.abi.TypeReference
import org.web3j.abi.datatypes.StaticArray
import org.web3j.abi.datatypes.Uint

/**(
pragma solidity ^0.5.11;

contract IntArray {
    uint[5] numbers;

    function main() public returns (uint[5] memory) {
        numbers[0] = 100;
        numbers[1] = 200;
        numbers[2] = 300;
        numbers[3] = 400;
        numbers[4] = 500;
        return numbers;
    }
}
*/
class IntArrayContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405234801561001057600080fd5b50610183806100206000396000f3fe608060405234801561001057600080fd5b506004361061002b5760003560e01c8063dffeadd014610030575b600080fd5b610038610076565b6040518082600560200280838360005b83811015610063578082015181840152602081019050610048565b5050505090500191505060405180910390f35b61007e61012c565b60646000806005811061008d57fe5b018190555060c860006001600581106100a257fe5b018190555061012c60006002600581106100b857fe5b018190555061019060006003600581106100ce57fe5b01819055506101f460006004600581106100e457fe5b01819055506000600580602002604051908101604052809291908260058015610122576020028201915b81548152602001906001019080831161010e575b5050505050905090565b6040518060a0016040528060059060208202803883398082019150509050509056fea265627a7a723158204fccd77f13a8ae4c34649e2722dfe2584837c3fd1f4c00ef1604c3b131e2bdff64736f6c63430005100032"
) {

    fun createContract(): Single<ChainResponse<TransactionCommitted>> {
        return create(listOf())
    }

    fun main(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "main",
            listOf(),
            listOf(object : TypeReference<StaticArray<Uint>>() { }),
            sender
        )
    }
}
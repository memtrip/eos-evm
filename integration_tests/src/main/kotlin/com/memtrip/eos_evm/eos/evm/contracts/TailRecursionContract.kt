package com.memtrip.eos_evm.eos.evm.contracts

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.evm.EvmContract
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.ethereum.EthAccount
import io.reactivex.Single
import org.web3j.abi.TypeReference
import org.web3j.abi.datatypes.Address
import org.web3j.abi.datatypes.Uint
import org.web3j.abi.datatypes.generated.Bytes32
import java.math.BigInteger

/**
pragma solidity ^0.5.11;

contract TailRecursion {

    function sum(uint n) public view returns(uint) {
        return n == 0 ? 0 :
        n + sum(n-1);
    }

    function sumloop(uint n) public pure returns(uint) {
        uint256 total = 0;
        for(uint256 i=1; i<=n; i++) {
        total += i;
    }
        return total;
    }

    function sumtailHelper(uint n, uint acc) private view returns(uint) {
        return n == 0 ? acc :
        sumtailHelper(n-1, acc + n);
    }

    function sumtail(uint n) public view returns(uint) {
        return sumtailHelper(n, 0);
    }
}
*/
class TailRecursionContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "608060405234801561001057600080fd5b506101d3806100206000396000f3fe608060405234801561001057600080fd5b50600436106100415760003560e01c8063188b85b414610046578063b239139814610088578063d4d6bc77146100ca575b600080fd5b6100726004803603602081101561005c57600080fd5b810190808035906020019092919050505061010c565b6040518082815260200191505060405180910390f35b6100b46004803603602081101561009e57600080fd5b8101908080359060200190929190505050610132565b6040518082815260200191505060405180910390f35b6100f6600480360360208110156100e057600080fd5b8101908080359060200190929190505050610146565b6040518082815260200191505060405180910390f35b6000808214610128576101216001830361010c565b820161012b565b60005b9050919050565b600061013f826000610177565b9050919050565b600080600090506000600190505b83811161016d5780820191508080600101915050610154565b5080915050919050565b60008083146101945761018f60018403848401610177565b610196565b815b90509291505056fea265627a7a723158201a82845bb967d881b90fa267b5a8dd6c5afcd981f0917c58d71b1604066f146264736f6c63430005100032"
) {

    fun createContract(): Single<ChainResponse<TransactionCommitted>> {
        return create(listOf())
    }

    fun sum(value: Long, sender: EvmSender): Single<ChainResponse<TransactionCommitted>>  {
        return executeMethod(
            "sum",
            listOf(Uint(BigInteger.valueOf(value))),
            listOf(object : TypeReference<Uint>() { }),
            sender
        )
    }

    fun sumloop(value: Long, sender: EvmSender): Single<ChainResponse<TransactionCommitted>>  {
        return executeMethod(
            "sumloop",
            listOf(Uint(BigInteger.valueOf(value))),
            listOf(object : TypeReference<Uint>() { }),
            sender
        )
    }

    fun sumtail(value: Long, sender: EvmSender): Single<ChainResponse<TransactionCommitted>>  {
        return executeMethod(
            "sumtail",
            listOf(Uint(BigInteger.valueOf(value))),
            listOf(object : TypeReference<Uint>() { }),
            sender
        )
    }
}
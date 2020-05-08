package com.memtrip.eos_evm.eos.evm.contracts.misc

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.evm.EvmContract
import com.memtrip.eos_evm.eos.evm.contracts.CreateResponse
import com.memtrip.eos_evm.ethereum.EthAccount
import io.reactivex.Single

/**
pragma solidity ^0.5.11;

contract PackedUint128 {
    uint128[] s;
    constructor() public {
        s.length = 4;
        s[0] = 0xAA;
        s[1] = 0xBB;
        s[2] = 0xCC;
        s[3] = 0xDD;
    }
}
*/
class PackedUint128Contract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405234801561001057600080fd5b5060046000816100209190610191565b5060aa6000808154811061003057fe5b90600052602060002090600291828204019190066010026101000a8154816fffffffffffffffffffffffffffffffff02191690836fffffffffffffffffffffffffffffffff16021790555060bb600060018154811061008b57fe5b90600052602060002090600291828204019190066010026101000a8154816fffffffffffffffffffffffffffffffff02191690836fffffffffffffffffffffffffffffffff16021790555060cc60006002815481106100e657fe5b90600052602060002090600291828204019190066010026101000a8154816fffffffffffffffffffffffffffffffff02191690836fffffffffffffffffffffffffffffffff16021790555060dd600060038154811061014157fe5b90600052602060002090600291828204019190066010026101000a8154816fffffffffffffffffffffffffffffffff02191690836fffffffffffffffffffffffffffffffff1602179055506101f0565b8154818355818111156101c65760010160029004816001016002900483600052602060002091820191016101c591906101cb565b5b505050565b6101ed91905b808211156101e95760008160009055506001016101d1565b5090565b90565b603e806101fe6000396000f3fe6080604052600080fdfea265627a7a72315820e22258c2b16769e411f5fbf58b407fdd387503b4749d58827d952947049d6efb64736f6c63430005100032"
) {

    fun createContract(): Single<CreateResponse> {
        return create(listOf())
    }
}
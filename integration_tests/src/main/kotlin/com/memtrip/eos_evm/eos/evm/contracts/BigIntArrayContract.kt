package com.memtrip.eos_evm.eos.evm.contracts

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.evm.EvmContract
import com.memtrip.eos_evm.ethereum.EthAccount
import io.reactivex.Single
import org.web3j.abi.datatypes.DynamicArray
import org.web3j.abi.datatypes.generated.Uint256
import java.math.BigInteger

/**
pragma solidity ^0.5.11;

contract BigIntArray {
    uint256[] public numbers;
    constructor(uint256[] memory _numbers) public {
        for(uint256 i=0; i<_numbers.length; i++) {
            numbers.push(_numbers[i]);
        }
    }
}
*/
class BigIntArrayContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405234801561001057600080fd5b506040516101733803806101738339818101604052602081101561003357600080fd5b810190808051604051939291908464010000000082111561005357600080fd5b8382019150602082018581111561006957600080fd5b825186602082028301116401000000008211171561008657600080fd5b8083526020830192505050908051906020019060200280838360005b838110156100bd5780820151818401526020810190506100a2565b5050505090500160405250505060008090505b81518110156101255760008282815181106100e757fe5b6020026020010151908060018154018082558091505090600182039060005260206000200160009091929091909150555080806001019150506100d0565b5050603e806101356000396000f3fe6080604052600080fdfea265627a7a72315820a69ee7faacbc5dae47918f7b25009aace0b3bdf791cb6e44035d0311a86a8d1364736f6c63430005100032"
) {

    fun createContract(numbers: List<BigInteger>): Single<ChainResponse<TransactionCommitted>> {
        return create(listOf(DynamicArray<Uint256>(Uint256::class.java, numbers.map { Uint256(it) })))
    }
}
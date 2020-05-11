package com.memtrip.evm.eos.evm.contracts.ethereumorg

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.evm.eos.evm.EvmContract
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.contracts.CreateResponse
import com.memtrip.evm.ethereum.EthAccount
import io.reactivex.Single
import org.web3j.abi.datatypes.Address
import org.web3j.abi.datatypes.Uint
import org.web3j.abi.datatypes.generated.Uint256
import java.math.BigInteger

/**
 * https://github.com/ethereum/ethereum-org/blob/master/solidity/token-minimal.sol
 */
class TokenMinimalContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405234801561001057600080fd5b506040516103573803806103578339818101604052602081101561003357600080fd5b8101908080519060200190929190505050806000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002081905550506102c0806100976000396000f3fe608060405234801561001057600080fd5b50600436106100365760003560e01c806370a082311461003b578063a9059cbb14610093575b600080fd5b61007d6004803603602081101561005157600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff1690602001909291905050506100f9565b6040518082815260200191505060405180910390f35b6100df600480360360408110156100a957600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190505050610111565b604051808215151515815260200191505060405180910390f35b60006020528060005260406000206000915090505481565b6000816000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002054101561015e57600080fd5b6000808473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002054826000808673ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020540110156101e957600080fd5b816000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060008282540392505081905550816000808573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060008282540192505081905550600190509291505056fea265627a7a72315820fce249dd8198d97ea105b4a4ab403c0ec5de9f63b22316cb84e47b382ac7a6ee64736f6c63430005100032"
) {

    fun createContract(initialSupply: BigInteger): Single<CreateResponse> {
        return create(listOf(Uint256(initialSupply)))
    }

    fun transfer(address: String, value: BigInteger, sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "transfer",
            listOf(Address(address), Uint(value)),
            listOf(),
            sender
        )
    }
}
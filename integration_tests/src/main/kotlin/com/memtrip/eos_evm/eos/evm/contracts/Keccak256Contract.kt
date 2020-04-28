package com.memtrip.eos_evm.eos.evm.contracts

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.evm.EvmContract
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.ethereum.EthAccount
import io.reactivex.Single
import org.web3j.abi.TypeReference
import org.web3j.abi.datatypes.Bool
import org.web3j.abi.datatypes.generated.Bytes32

/**
pragma solidity ^0.5.11;

contract Keccak256 {
    function hashArray() public pure returns(bytes32) {
        bytes8[] memory tickers = new bytes8[](4);
        tickers[0] = bytes8('BTC');
        tickers[1] = bytes8('ETH');
        tickers[2] = bytes8('LTC');
        tickers[3] = bytes8('DOGE');
        return keccak256(abi.encode(tickers));
        // 0x374c0504f79c1d5e6e4ded17d488802b5656bd1d96b16a568d6c324e1c04c37b
    }

    function hashPackedArray() public pure returns(bytes32) {
        bytes8 btc = bytes8('BTC');
        bytes8 eth = bytes8('ETH');
        bytes8 ltc = bytes8('LTC');
        bytes8 doge = bytes8('DOGE');
        return keccak256(abi.encode(btc, eth, ltc, doge));
        // 0xe79a6745d2205095147fd735f329de58377b2f0b9f4b81ae23e010062127f2bc
    }

    function hashAddress() public pure returns(bytes32) {
        address account = 0x6779913e982688474F710B47E1c0506c5Dca4634;
        return keccak256(abi.encode(bytes20(account)));
        // 0x229327de236bd04ccac2efc445f1a2b63afddf438b35874b9f6fd1e6c38b0198
    }

    function testPackedArgs() public pure returns (bool) {
        return keccak256(abi.encode('ab')) == keccak256(abi.encode('a', 'b'));
    }

    function hashHex() public pure returns (bytes32) {
        return keccak256(abi.encode(0x0a));
        // 0x0ef9d8f8804d174666011a394cab7901679a8944d24249fd148a6a36071151f8
    }

    function hashInt() public pure returns (bytes32) {
        return keccak256(abi.encode(int(1)));
    }

    function hashNegative() public pure returns (bytes32) {
        return keccak256(abi.encode(int(-1)));
    }

    function hash8() public pure returns (bytes32) {
        return keccak256(abi.encode(1));
    }

    function hash32() public pure returns (bytes32) {
        return keccak256(abi.encode(uint32(1)));
    }

    function hash256() public pure returns (bytes32) {
        return keccak256(abi.encode(uint(1)));
    }

    function hashEth() public pure returns (bytes32) {
        return keccak256(abi.encode(uint(100 ether)));
    }

    function hashWei() public pure returns (bytes32) {
        return keccak256(abi.encode(uint(100)));
    }

    function hashMultipleArgs() public pure returns (bytes32) {
        return keccak256(abi.encode("a", 1));
    }

    function hashString() public pure returns (bytes32) {
        return keccak256(bytes("a"));
    }
}
*/
class Keccak256Contract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405234801561001057600080fd5b50610aa7806100206000396000f3fe608060405234801561001057600080fd5b50600436106100ea5760003560e01c80635985b6241161008c578063c8cf44bd11610066578063c8cf44bd1461021b578063d2f8cf241461023d578063e86783a71461025b578063f74d8e3214610279576100ea565b80635985b624146101c15780635fdc7f65146101df5780637781deba146101fd576100ea565b806344d9385f116100c857806344d9385f146101495780634c9e7ca5146101675780635087821a1461018557806351193102146101a3576100ea565b806304d3c094146100ef578063114be5841461010d57806311b405c71461012b575b600080fd5b6100f7610297565b6040518082815260200191505060405180910390f35b6101156102db565b6040518082815260200191505060405180910390f35b610133610329565b6040518082815260200191505060405180910390f35b6101516104de565b6040518082815260200191505060405180910390f35b61016f610510565b6040518082815260200191505060405180910390f35b61018d61077d565b6040518082815260200191505060405180910390f35b6101ab6107e8565b6040518082815260200191505060405180910390f35b6101c9610850565b6040518082815260200191505060405180910390f35b6101e7610882565b6040518082815260200191505060405180910390f35b6102056108b1565b6040518082815260200191505060405180910390f35b6102236108e0565b604051808215151515815260200191505060405180910390f35b6102456109d1565b6040518082815260200191505060405180910390f35b610263610a00565b6040518082815260200191505060405180910390f35b610281610a37565b6040518082815260200191505060405180910390f35b60006040518060400160405280600181526020017f610000000000000000000000000000000000000000000000000000000000000081525080519060200120905090565b60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6040516020018082815260200191505060405160208183030381529060405280519060200120905090565b6000807f4254430000000000000000000000000000000000000000000000000000000000905060007f4554480000000000000000000000000000000000000000000000000000000000905060007f4c54430000000000000000000000000000000000000000000000000000000000905060007f444f474500000000000000000000000000000000000000000000000000000000905083838383604051602001808577ffffffffffffffffffffffffffffffffffffffffffffffff191677ffffffffffffffffffffffffffffffffffffffffffffffff191681526020018477ffffffffffffffffffffffffffffffffffffffffffffffff191677ffffffffffffffffffffffffffffffffffffffffffffffff191681526020018377ffffffffffffffffffffffffffffffffffffffffffffffff191677ffffffffffffffffffffffffffffffffffffffffffffffff191681526020018277ffffffffffffffffffffffffffffffffffffffffffffffff191677ffffffffffffffffffffffffffffffffffffffffffffffff191681526020019450505050506040516020818303038152906040528051906020012094505050505090565b60006001604051602001808260ff16815260200191505060405160208183030381529060405280519060200120905090565b6000606060046040519080825280602002602001820160405280156105445781602001602082028038833980820191505090505b5090507f42544300000000000000000000000000000000000000000000000000000000008160008151811061057557fe5b602002602001019077ffffffffffffffffffffffffffffffffffffffffffffffff1916908177ffffffffffffffffffffffffffffffffffffffffffffffff1916815250507f4554480000000000000000000000000000000000000000000000000000000000816001815181106105e757fe5b602002602001019077ffffffffffffffffffffffffffffffffffffffffffffffff1916908177ffffffffffffffffffffffffffffffffffffffffffffffff1916815250507f4c544300000000000000000000000000000000000000000000000000000000008160028151811061065957fe5b602002602001019077ffffffffffffffffffffffffffffffffffffffffffffffff1916908177ffffffffffffffffffffffffffffffffffffffffffffffff1916815250507f444f474500000000000000000000000000000000000000000000000000000000816003815181106106cb57fe5b602002602001019077ffffffffffffffffffffffffffffffffffffffffffffffff1916908177ffffffffffffffffffffffffffffffffffffffffffffffff191681525050806040516020018080602001828103825283818151815260200191508051906020019060200280838360005b8381101561075657808201518184015260208101905061073b565b50505050905001925050506040516020818303038152906040528051906020012091505090565b6000600160405160200180806020018360ff168152602001828103825260018152602001807f61000000000000000000000000000000000000000000000000000000000000008152506020019250505060405160208183030381529060405280519060200120905090565b600080736779913e982688474f710b47e1c0506c5dca463490508060601b60405160200180826bffffffffffffffffffffffff19166bffffffffffffffffffffffff191681526020019150506040516020818303038152906040528051906020012091505090565b6000600a604051602001808260ff16815260200191505060405160208183030381529060405280519060200120905090565b600060016040516020018082815260200191505060405160208183030381529060405280519060200120905090565b600060016040516020018082815260200191505060405160208183030381529060405280519060200120905090565b6000604051602001808060200180602001838103835260018152602001807f6100000000000000000000000000000000000000000000000000000000000000815250602001838103825260018152602001807f620000000000000000000000000000000000000000000000000000000000000081525060200192505050604051602081830303815290604052805190602001206040516020018080602001828103825260028152602001807f61620000000000000000000000000000000000000000000000000000000000008152506020019150506040516020818303038152906040528051906020012014905090565b600060646040516020018082815260200191505060405160208183030381529060405280519060200120905090565b600068056bc75e2d631000006040516020018082815260200191505060405160208183030381529060405280519060200120905090565b60006001604051602001808263ffffffff1663ffffffff1681526020019150506040516020818303038152906040528051906020012090509056fea265627a7a723158203ccded79eaba7a938b786187cc3dda1b36358e29af0b6effcb7f99df1ed8995e64736f6c63430005100032"
) {

    fun createContract(): Single<ChainResponse<TransactionCommitted>> {
        return create(listOf())
    }

    fun hashArray(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "hashArray",
            listOf(),
            listOf(object : TypeReference<Bytes32>() { }),
            sender
        )
    }

    fun hashPackedArray(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "hashPackedArray",
            listOf(),
            listOf(object : TypeReference<Bytes32>() { }),
            sender
        )
    }

    fun hashAddress(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "hashAddress",
            listOf(),
            listOf(object : TypeReference<Bytes32>() { }),
            sender
        )
    }

    fun testPackedArgs(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "testPackedArgs",
            listOf(),
            listOf(object : TypeReference<Bool>() { }),
            sender
        )
    }

    fun hashHex(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "hashHex",
            listOf(),
            listOf(object : TypeReference<Bytes32>() { }),
            sender
        )
    }

    fun hashInt(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "hashInt",
            listOf(),
            listOf(object : TypeReference<Bytes32>() { }),
            sender
        )
    }

    fun hashNegative(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "hashNegative",
            listOf(),
            listOf(object : TypeReference<Bytes32>() { }),
            sender
        )
    }

    fun hash8(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "hash8",
            listOf(),
            listOf(object : TypeReference<Bytes32>() { }),
            sender
        )
    }

    fun hash32(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "hash32",
            listOf(),
            listOf(object : TypeReference<Bytes32>() { }),
            sender
        )
    }

    fun hash256(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "hash256",
            listOf(),
            listOf(object : TypeReference<Bytes32>() { }),
            sender
        )
    }

    fun hashEth(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "hashEth",
            listOf(),
            listOf(object : TypeReference<Bytes32>() { }),
            sender
        )
    }

    fun hashWei(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "hashWei",
            listOf(),
            listOf(object : TypeReference<Bytes32>() { }),
            sender
        )
    }

    fun hashMultipleArgs(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "hashMultipleArgs",
            listOf(),
            listOf(object : TypeReference<Bytes32>() { }),
            sender
        )
    }

    fun hashString(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "hashString",
            listOf(),
            listOf(object : TypeReference<Bytes32>() { }),
            sender
        )
    }
}
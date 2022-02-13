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
import org.web3j.abi.datatypes.Address
import org.web3j.abi.datatypes.DynamicArray
import org.web3j.abi.datatypes.generated.Uint256
import java.math.BigInteger

/**
pragma solidity ^0.5.11;

contract Child {
    uint[] public amounts;

    function init(uint[] memory _amounts) public {
        amounts = _amounts;
    }
}

contract Factory {
    struct ChildData {
        uint[] amounts;
    }
    mapping (address => ChildData) listOfData;

    function set(uint[] memory _amounts) public {
        listOfData[msg.sender] = ChildData(_amounts);
    }

    function make() public returns(address) {
        Child child = new Child();
        child.init(listOfData[msg.sender].amounts);
        return address(child);
    }
}
*/
class FactoryContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405234801561001057600080fd5b506105b6806100206000396000f3fe608060405234801561001057600080fd5b50600436106100365760003560e01c80636ea9bfc51461003b578063c6dad082146100f3575b600080fd5b6100f16004803603602081101561005157600080fd5b810190808035906020019064010000000081111561006e57600080fd5b82018360208201111561008057600080fd5b803590602001918460208302840111640100000000831117156100a257600080fd5b919080806020026020016040519081016040528093929190818152602001838360200280828437600081840152601f19601f82011690508083019250505050505050919291929050505061013d565b005b6100fb6101ad565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6040518060200160405280828152506000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060008201518160000190805190602001906101a69291906102cb565b5090505050565b6000806040516101bc90610318565b604051809103906000f0801580156101d8573d6000803e3d6000fd5b5090508073ffffffffffffffffffffffffffffffffffffffff1663d88b06db6000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000206000016040518263ffffffff1660e01b81526004018080602001828103825283818154815260200191508054801561028c57602002820191906000526020600020905b815481526020019060010190808311610278575b505092505050600060405180830381600087803b1580156102ac57600080fd5b505af11580156102c0573d6000803e3d6000fd5b505050508091505090565b828054828255906000526020600020908101928215610307579160200282015b828111156103065782518255916020019190600101906102eb565b5b5090506103149190610325565b5090565b6102378061034b83390190565b61034791905b8082111561034357600081600090555060010161032b565b5090565b9056fe608060405234801561001057600080fd5b50610217806100206000396000f3fe608060405234801561001057600080fd5b50600436106100365760003560e01c806345f0a44f1461003b578063d88b06db1461007d575b600080fd5b6100676004803603602081101561005157600080fd5b8101908080359060200190929190505050610135565b6040518082815260200191505060405180910390f35b6101336004803603602081101561009357600080fd5b81019080803590602001906401000000008111156100b057600080fd5b8201836020820111156100c257600080fd5b803590602001918460208302840111640100000000831117156100e457600080fd5b919080806020026020016040519081016040528093929190818152602001838360200280828437600081840152601f19601f820116905080830192505050505050509192919290505050610156565b005b6000818154811061014257fe5b906000526020600020016000915090505481565b806000908051906020019061016c929190610170565b5050565b8280548282559060005260206000209081019282156101ac579160200282015b828111156101ab578251825591602001919060010190610190565b5b5090506101b991906101bd565b5090565b6101df91905b808211156101db5760008160009055506001016101c3565b5090565b9056fea265627a7a72315820a7fb0132e94897221eb0044f6445dde8d78885f7c36a05cc01368d35c95ff26064736f6c63430005100032a265627a7a72315820b6937d27c0b58e786b37eb17f047c649f7560ce3f2122910751fb718711ea7b064736f6c63430005100032"
) {

    fun createContract(): Single<CreateResponse> {
        return create(listOf())
    }

    fun set(amounts: List<BigInteger>, sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "set",
            listOf(DynamicArray<Uint256>(Uint256::class.java, amounts.map { Uint256(it) })),
            listOf(),
            sender
        )
    }

    fun make(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "make",
            listOf(),
            listOf(object : TypeReference<Address>() { }),
            sender
        )
    }
}
package com.memtrip.eos_evm.eos.evm.contracts.misc

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.evm.EvmContract
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.CreateResponse
import com.memtrip.eos_evm.ethereum.EthAccount
import io.reactivex.Single
import org.web3j.abi.datatypes.Uint
import java.math.BigInteger

/**
pragma solidity ^0.5.11;

contract Modifiers {

    bool locked = false;

    modifier greaterThan(uint value, uint limit) {
        if(value <= limit) { assert(false); }
        _;
    }

    modifier lock() {
        if (locked) {
            locked = true;
            _;
            locked = false;
        }
    }

    function g(uint a) public greaterThan(a, 10) {}
    function refund() public lock {
        msg.sender.send(0);
    }
}
*/
class ModifiersContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405260008060006101000a81548160ff02191690831515021790555034801561002a57600080fd5b506101428061003a6000396000f3fe608060405234801561001057600080fd5b50600436106100365760003560e01c8063590e1ae31461003b578063e420264a14610045575b600080fd5b610043610073565b005b6100716004803603602081101561005b57600080fd5b81019080803590602001909291905050506100f5565b005b6000809054906101000a900460ff16156100f35760016000806101000a81548160ff0219169083151502179055503373ffffffffffffffffffffffffffffffffffffffff166108fc60009081150290604051600060405180830381858888f193505050505060008060006101000a81548160ff0219169083151502179055505b565b80600a80821161010857600061010757fe5b5b50505056fea265627a7a72315820d23f3401d5531c12d13f51dd61053b213830082e7f0139dd69930e753c6f43ba64736f6c63430005100032"
) {

    fun createContract(): Single<CreateResponse> {
        return create(listOf())
    }

    fun g(value: Long, sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "g",
            listOf(Uint(BigInteger.valueOf(value))),
            listOf(),
            sender
        )
    }
}
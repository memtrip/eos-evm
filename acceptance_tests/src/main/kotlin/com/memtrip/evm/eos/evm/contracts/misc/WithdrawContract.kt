package com.memtrip.evm.eos.evm.contracts.misc

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.evm.eos.evm.EvmContract
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.contracts.CreateResponse
import com.memtrip.evm.ethereum.EthAccount
import io.reactivex.Single
import java.math.BigInteger

/**
pragma solidity ^0.5.11;

contract Withdraw {

    constructor() public payable {
    }

    function withdraw() public {
        msg.sender.transfer(address(this).balance);
    }
}
*/
class WithdrawContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405260b2806100126000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c80633ccfd60b14602d575b600080fd5b60336035565b005b3373ffffffffffffffffffffffffffffffffffffffff166108fc479081150290604051600060405180830381858888f19350505050158015607a573d6000803e3d6000fd5b5056fea265627a7a7231582031cc683240cfd2891b6f741024dbe81cba9e97335b85d1a51b28fe8fc56f017764736f6c63430005100032"
) {

    fun createContract(value: BigInteger): Single<CreateResponse> {
        return create(listOf(), value)
    }

    fun withdraw(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "withdraw",
            listOf(),
            listOf(),
            sender
        )
    }
}
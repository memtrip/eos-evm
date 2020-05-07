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
contract MappingValue {
    mapping(uint => uint) public objects;

    constructor() public {
        objects[0] = 42;
    }
}

contract PublicMapping {
    // insert address of deployed First here
    MappingValue mappingValue;

    constructor() public {
        mappingValue = new MappingValue();
    }

    function get() public view returns(uint) {
        return mappingValue.objects(0);
    }
}
*/
class PublicMappingContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405234801561001057600080fd5b5060405161001d9061007e565b604051809103906000f080158015610039573d6000803e3d6000fd5b506000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555061008a565b60f0806101c983390190565b610130806100996000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c80636d4ce63c14602d575b600080fd5b60336049565b6040518082815260200191505060405180910390f35b60008060009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1663ed17585060006040518263ffffffff1660e01b81526004018082815260200191505060206040518083038186803b15801560bd57600080fd5b505afa15801560d0573d6000803e3d6000fd5b505050506040513d602081101560e557600080fd5b810190808051906020019092919050505090509056fea265627a7a723158207c14e48936f157bc142b66e8b65db2eb112ce20675860c92cfed700a2febe7ac64736f6c63430005100032608060405234801561001057600080fd5b50602a6000808081526020019081526020016000208190555060b9806100376000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063ed17585014602d575b600080fd5b605660048036036020811015604157600080fd5b8101908080359060200190929190505050606c565b6040518082815260200191505060405180910390f35b6000602052806000526040600020600091509050548156fea265627a7a72315820e42322782734d761aba70a6907d7fb967e28211b423341f82ada9db18e1d4aa364736f6c63430005100032"
) {

    fun createContract(): Single<ChainResponse<TransactionCommitted>> {
        return create(listOf())
    }

    fun get(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "get",
            listOf(),
            listOf(object : TypeReference<Type<Uint>>() { }),
            sender
        )
    }
}
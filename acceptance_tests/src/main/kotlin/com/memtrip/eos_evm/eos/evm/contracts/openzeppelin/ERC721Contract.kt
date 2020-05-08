package com.memtrip.eos_evm.eos.evm.contracts.openzeppelin

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.evm.EvmContract
import com.memtrip.eos_evm.eos.evm.contracts.CreateResponse
import com.memtrip.eos_evm.ethereum.EthAccount
import io.reactivex.Single
import org.web3j.abi.datatypes.Type
import org.web3j.abi.datatypes.Utf8String

/**
 * https://github.com/OpenZeppelin/openzeppelin-contracts/blob/master/contracts/token/ERC721/ERC721.sol
 */
class ERC721Contract (
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x60806040523480156200001157600080fd5b5060405162002a1838038062002a18833981810160405260408110156200003757600080fd5b81019080805160405193929190846401000000008211156200005857600080fd5b838201915060208201858111156200006f57600080fd5b82518660018202830111640100000000821117156200008d57600080fd5b8083526020830192505050908051906020019080838360005b83811015620000c3578082015181840152602081019050620000a6565b50505050905090810190601f168015620000f15780820380516001836020036101000a031916815260200191505b50604052602001805160405193929190846401000000008211156200011557600080fd5b838201915060208201858111156200012c57600080fd5b82518660018202830111640100000000821117156200014a57600080fd5b8083526020830192505050908051906020019080838360005b838110156200018057808201518184015260208101905062000163565b50505050905090810190601f168015620001ae5780820380516001836020036101000a031916815260200191505b50604052505050620001cd6301ffc9a760e01b6200024f60201b60201c565b8160069080519060200190620001e592919062000358565b508060079080519060200190620001fe92919062000358565b50620002176380ac58cd60e01b6200024f60201b60201c565b6200022f635b5e139f60e01b6200024f60201b60201c565b6200024763780e9d6360e01b6200024f60201b60201c565b505062000407565b63ffffffff60e01b817bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19161415620002ec576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252601c8152602001807f4552433136353a20696e76616c696420696e746572666163652069640000000081525060200191505060405180910390fd5b6001600080837bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19167bffffffffffffffffffffffffffffffffffffffffffffffffffffffff1916815260200190815260200160002060006101000a81548160ff02191690831515021790555050565b828054600181600116156101000203166002900490600052602060002090601f016020900481019282601f106200039b57805160ff1916838001178555620003cc565b82800160010185558215620003cc579182015b82811115620003cb578251825591602001919060010190620003ae565b5b509050620003db9190620003df565b5090565b6200040491905b8082111562000400576000816000905550600101620003e6565b5090565b90565b61260180620004176000396000f3fe608060405234801561001057600080fd5b506004361061010b5760003560e01c80634f6ccce7116100a257806395d89b411161007157806395d89b411461059b578063a22cb4651461061e578063b88d4fde1461066e578063c87b56dd14610773578063e985e9c51461081a5761010b565b80634f6ccce7146104105780636352211e146104525780636c0360eb146104c057806370a08231146105435761010b565b806318160ddd116100de57806318160ddd146102b457806323b872dd146102d25780632f745c591461034057806342842e0e146103a25761010b565b806301ffc9a71461011057806306fdde0314610175578063081812fc146101f8578063095ea7b314610266575b600080fd5b61015b6004803603602081101561012657600080fd5b8101908080357bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19169060200190929190505050610896565b604051808215151515815260200191505060405180910390f35b61017d6108fd565b6040518080602001828103825283818151815260200191508051906020019080838360005b838110156101bd5780820151818401526020810190506101a2565b50505050905090810190601f1680156101ea5780820380516001836020036101000a031916815260200191505b509250505060405180910390f35b6102246004803603602081101561020e57600080fd5b810190808035906020019092919050505061099f565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6102b26004803603604081101561027c57600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190505050610a3a565b005b6102bc610b7e565b6040518082815260200191505060405180910390f35b61033e600480360360608110156102e857600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190505050610b8f565b005b61038c6004803603604081101561035657600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190505050610c05565b6040518082815260200191505060405180910390f35b61040e600480360360608110156103b857600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190505050610c60565b005b61043c6004803603602081101561042657600080fd5b8101908080359060200190929190505050610c80565b6040518082815260200191505060405180910390f35b61047e6004803603602081101561046857600080fd5b8101908080359060200190929190505050610ca3565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6104c8610cda565b6040518080602001828103825283818151815260200191508051906020019080838360005b838110156105085780820151818401526020810190506104ed565b50505050905090810190601f1680156105355780820380516001836020036101000a031916815260200191505b509250505060405180910390f35b6105856004803603602081101561055957600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610d7c565b6040518082815260200191505060405180910390f35b6105a3610e51565b6040518080602001828103825283818151815260200191508051906020019080838360005b838110156105e35780820151818401526020810190506105c8565b50505050905090810190601f1680156106105780820380516001836020036101000a031916815260200191505b509250505060405180910390f35b61066c6004803603604081101561063457600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190803515159060200190929190505050610ef3565b005b6107716004803603608081101561068457600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190803590602001906401000000008111156106eb57600080fd5b8201836020820111156106fd57600080fd5b8035906020019184600183028401116401000000008311171561071f57600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f8201169050808301925050505050505091929192905050506110ab565b005b61079f6004803603602081101561078957600080fd5b8101908080359060200190929190505050611123565b6040518080602001828103825283818151815260200191508051906020019080838360005b838110156107df5780820151818401526020810190506107c4565b50505050905090810190601f16801561080c5780820380516001836020036101000a031916815260200191505b509250505060405180910390f35b61087c6004803603604081101561083057600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190803573ffffffffffffffffffffffffffffffffffffffff16906020019092919050505061140c565b604051808215151515815260200191505060405180910390f35b6000806000837bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19167bffffffffffffffffffffffffffffffffffffffffffffffffffffffff1916815260200190815260200160002060009054906101000a900460ff169050919050565b606060068054600181600116156101000203166002900480601f0160208091040260200160405190810160405280929190818152602001828054600181600116156101000203166002900480156109955780601f1061096a57610100808354040283529160200191610995565b820191906000526020600020905b81548152906001019060200180831161097857829003601f168201915b5050505050905090565b60006109aa826114a0565b6109ff576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252602c8152602001806124f6602c913960400191505060405180910390fd5b6004600083815260200190815260200160002060009054906101000a900473ffffffffffffffffffffffffffffffffffffffff169050919050565b6000610a4582610ca3565b90508073ffffffffffffffffffffffffffffffffffffffff168373ffffffffffffffffffffffffffffffffffffffff161415610acc576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252602181526020018061257a6021913960400191505060405180910390fd5b8073ffffffffffffffffffffffffffffffffffffffff16610aeb6114bd565b73ffffffffffffffffffffffffffffffffffffffff161480610b1a5750610b1981610b146114bd565b61140c565b5b610b6f576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260388152602001806124496038913960400191505060405180910390fd5b610b7983836114c5565b505050565b6000610b8a600261157e565b905090565b610ba0610b9a6114bd565b82611593565b610bf5576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252603181526020018061259b6031913960400191505060405180910390fd5b610c00838383611687565b505050565b6000610c5882600160008673ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000206118ca90919063ffffffff16565b905092915050565b610c7b838383604051806020016040528060008152506110ab565b505050565b600080610c978360026118e490919063ffffffff16565b50905080915050919050565b6000610cd3826040518060600160405280602981526020016124ab6029913960026119139092919063ffffffff16565b9050919050565b606060098054600181600116156101000203166002900480601f016020809104026020016040519081016040528092919081815260200182805460018160011615610100020316600290048015610d725780601f10610d4757610100808354040283529160200191610d72565b820191906000526020600020905b815481529060010190602001808311610d5557829003601f168201915b5050505050905090565b60008073ffffffffffffffffffffffffffffffffffffffff168273ffffffffffffffffffffffffffffffffffffffff161415610e03576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252602a815260200180612481602a913960400191505060405180910390fd5b610e4a600160008473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020611932565b9050919050565b606060078054600181600116156101000203166002900480601f016020809104026020016040519081016040528092919081815260200182805460018160011615610100020316600290048015610ee95780601f10610ebe57610100808354040283529160200191610ee9565b820191906000526020600020905b815481529060010190602001808311610ecc57829003601f168201915b5050505050905090565b610efb6114bd565b73ffffffffffffffffffffffffffffffffffffffff168273ffffffffffffffffffffffffffffffffffffffff161415610f9c576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260198152602001807f4552433732313a20617070726f766520746f2063616c6c65720000000000000081525060200191505060405180910390fd5b8060056000610fa96114bd565b73ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060008473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060006101000a81548160ff0219169083151502179055508173ffffffffffffffffffffffffffffffffffffffff166110566114bd565b73ffffffffffffffffffffffffffffffffffffffff167f17307eab39ab6107e8899845ad3d59bd9653f200f220920489ca2b5937696c3183604051808215151515815260200191505060405180910390a35050565b6110bc6110b66114bd565b83611593565b611111576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252603181526020018061259b6031913960400191505060405180910390fd5b61111d84848484611947565b50505050565b606061112e826114a0565b611183576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252602f81526020018061254b602f913960400191505060405180910390fd5b6060600860008481526020019081526020016000208054600181600116156101000203166002900480601f01602080910402602001604051908101604052809291908181526020018280546001816001161561010002031660029004801561122c5780601f106112015761010080835404028352916020019161122c565b820191906000526020600020905b81548152906001019060200180831161120f57829003601f168201915b5050505050905060006009805460018160011615610100020316600290049050141561125b5780915050611407565b6000815111156113345760098160405160200180838054600181600116156101000203166002900480156112c65780601f106112a45761010080835404028352918201916112c6565b820191906000526020600020905b8154815290600101906020018083116112b2575b505082805190602001908083835b602083106112f757805182526020820191506020810190506020830392506112d4565b6001836020036101000a03801982511681845116808217855250505050505090500192505050604051602081830303815290604052915050611407565b600961133f846119b9565b604051602001808380546001816001161561010002031660029004801561139d5780601f1061137b57610100808354040283529182019161139d565b820191906000526020600020905b815481529060010190602001808311611389575b505082805190602001908083835b602083106113ce57805182526020820191506020810190506020830392506113ab565b6001836020036101000a038019825116818451168082178552505050505050905001925050506040516020818303038152906040529150505b919050565b6000600560008473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060008373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060009054906101000a900460ff16905092915050565b60006114b6826002611b0090919063ffffffff16565b9050919050565b600033905090565b816004600083815260200190815260200160002060006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff160217905550808273ffffffffffffffffffffffffffffffffffffffff1661153883610ca3565b73ffffffffffffffffffffffffffffffffffffffff167f8c5be1e5ebec7d5bd14f71427d1e84f3dd0314c0f7b2291e5b200ac8c7c3b92560405160405180910390a45050565b600061158c82600001611b1a565b9050919050565b600061159e826114a0565b6115f3576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252602c81526020018061241d602c913960400191505060405180910390fd5b60006115fe83610ca3565b90508073ffffffffffffffffffffffffffffffffffffffff168473ffffffffffffffffffffffffffffffffffffffff16148061166d57508373ffffffffffffffffffffffffffffffffffffffff166116558461099f565b73ffffffffffffffffffffffffffffffffffffffff16145b8061167e575061167d818561140c565b5b91505092915050565b8273ffffffffffffffffffffffffffffffffffffffff166116a782610ca3565b73ffffffffffffffffffffffffffffffffffffffff1614611713576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260298152602001806125226029913960400191505060405180910390fd5b600073ffffffffffffffffffffffffffffffffffffffff168273ffffffffffffffffffffffffffffffffffffffff161415611799576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260248152602001806123f96024913960400191505060405180910390fd5b6117a4838383611b2b565b6117af6000826114c5565b61180081600160008673ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020611b3090919063ffffffff16565b5061185281600160008573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020611b4a90919063ffffffff16565b5061186981836002611b649092919063ffffffff16565b50808273ffffffffffffffffffffffffffffffffffffffff168473ffffffffffffffffffffffffffffffffffffffff167fddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef60405160405180910390a4505050565b60006118d98360000183611b99565b60001c905092915050565b6000806000806118f78660000186611c1c565b915091508160001c8160001c8090509350935050509250929050565b6000611926846000018460001b84611cb5565b60001c90509392505050565b600061194082600001611dab565b9050919050565b611952848484611687565b61195e84848484611dbc565b6119b3576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260328152602001806123c76032913960400191505060405180910390fd5b50505050565b60606000821415611a01576040518060400160405280600181526020017f30000000000000000000000000000000000000000000000000000000000000008152509050611afb565b600082905060005b60008214611a2b578080600101915050600a8281611a2357fe5b049150611a09565b60608167ffffffffffffffff81118015611a4457600080fd5b506040519080825280601f01601f191660200182016040528015611a775781602001600182028036833780820191505090505b50905060006001830390508593505b60008414611af357600a8481611a9857fe5b0660300160f81b82828060019003935081518110611ab257fe5b60200101907effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1916908160001a905350600a8481611aeb57fe5b049350611a86565b819450505050505b919050565b6000611b12836000018360001b6120df565b905092915050565b600081600001805490509050919050565b505050565b6000611b42836000018360001b612102565b905092915050565b6000611b5c836000018360001b6121ea565b905092915050565b6000611b90846000018460001b8473ffffffffffffffffffffffffffffffffffffffff1660001b61225a565b90509392505050565b600081836000018054905011611bfa576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260228152602001806123a56022913960400191505060405180910390fd5b826000018281548110611c0957fe5b9060005260206000200154905092915050565b60008082846000018054905011611c7e576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260228152602001806124d46022913960400191505060405180910390fd5b6000846000018481548110611c8f57fe5b906000526020600020906002020190508060000154816001015492509250509250929050565b60008084600101600085815260200190815260200160002054905060008114158390611d7c576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825283818151815260200191508051906020019080838360005b83811015611d41578082015181840152602081019050611d26565b50505050905090810190601f168015611d6e5780820380516001836020036101000a031916815260200191505b509250505060405180910390fd5b50846000016001820381548110611d8f57fe5b9060005260206000209060020201600101549150509392505050565b600081600001805490509050919050565b6000611ddd8473ffffffffffffffffffffffffffffffffffffffff16612336565b611dea57600190506120d7565b600060608573ffffffffffffffffffffffffffffffffffffffff1663150b7a0260e01b611e156114bd565b898888604051602401808573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200183815260200180602001828103825283818151815260200191508051906020019080838360005b83811015611ec5578082015181840152602081019050611eaa565b50505050905090810190601f168015611ef25780820380516001836020036101000a031916815260200191505b5095505050505050604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b60208310611f8a5780518252602082019150602081019050602083039250611f67565b6001836020036101000a0380198251168184511680821785525050505050509050019150506000604051808303816000865af19150503d8060008114611fec576040519150601f19603f3d011682016040523d82523d6000602084013e611ff1565b606091505b50915091508161205f5760008151111561200e5780518082602001fd5b6040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260328152602001806123c76032913960400191505060405180910390fd5b600081806020019051602081101561207657600080fd5b8101908080519060200190929190505050905063150b7a0260e01b7bffffffffffffffffffffffffffffffffffffffffffffffffffffffff1916817bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19161493505050505b949350505050565b600080836001016000848152602001908152602001600020541415905092915050565b600080836001016000848152602001908152602001600020549050600081146121de576000600182039050600060018660000180549050039050600086600001828154811061214d57fe5b906000526020600020015490508087600001848154811061216a57fe5b90600052602060002001819055506001830187600101600083815260200190815260200160002081905550866000018054806121a257fe5b600190038181906000526020600020016000905590558660010160008781526020019081526020016000206000905560019450505050506121e4565b60009150505b92915050565b60006121f68383612381565b61224f578260000182908060018154018082558091505060019003906000526020600020016000909190919091505582600001805490508360010160008481526020019081526020016000208190555060019050612254565b600090505b92915050565b60008084600101600085815260200190815260200160002054905060008114156123015784600001604051806040016040528086815260200185815250908060018154018082558091505060019003906000526020600020906002020160009091909190915060008201518160000155602082015181600101555050846000018054905085600101600086815260200190815260200160002081905550600191505061232f565b8285600001600183038154811061231457fe5b90600052602060002090600202016001018190555060009150505b9392505050565b60008060007fc5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a47060001b9050833f915080821415801561237857506000801b8214155b92505050919050565b60008083600101600084815260200190815260200160002054141590509291505056fe456e756d657261626c655365743a20696e646578206f7574206f6620626f756e64734552433732313a207472616e7366657220746f206e6f6e20455243373231526563656976657220696d706c656d656e7465724552433732313a207472616e7366657220746f20746865207a65726f20616464726573734552433732313a206f70657261746f7220717565727920666f72206e6f6e6578697374656e7420746f6b656e4552433732313a20617070726f76652063616c6c6572206973206e6f74206f776e6572206e6f7220617070726f76656420666f7220616c6c4552433732313a2062616c616e636520717565727920666f7220746865207a65726f20616464726573734552433732313a206f776e657220717565727920666f72206e6f6e6578697374656e7420746f6b656e456e756d657261626c654d61703a20696e646578206f7574206f6620626f756e64734552433732313a20617070726f76656420717565727920666f72206e6f6e6578697374656e7420746f6b656e4552433732313a207472616e73666572206f6620746f6b656e2074686174206973206e6f74206f776e4552433732314d657461646174613a2055524920717565727920666f72206e6f6e6578697374656e7420746f6b656e4552433732313a20617070726f76616c20746f2063757272656e74206f776e65724552433732313a207472616e736665722063616c6c6572206973206e6f74206f776e6572206e6f7220617070726f766564a26469706673582212208a69b2d01b5815dfbb57f261faec16434699c734d5eb82d8210402595275189464736f6c63430006060033"
) {

    fun createContract(name: String, symbol: String): Single<CreateResponse> {
        return create(listOf(Utf8String(name), Utf8String(symbol)))
    }
}
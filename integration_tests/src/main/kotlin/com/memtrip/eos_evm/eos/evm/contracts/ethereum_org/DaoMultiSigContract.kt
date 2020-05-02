package com.memtrip.eos_evm.eos.evm.contracts.ethereum_org

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.evm.EvmContract
import com.memtrip.eos_evm.ethereum.EthAccount
import io.reactivex.Single
import org.web3j.abi.datatypes.Address
import org.web3j.abi.datatypes.DynamicArray
import org.web3j.abi.datatypes.Uint
import org.web3j.abi.datatypes.Utf8String
import java.math.BigInteger

/**
 * https://github.com/ethereum/ethereum-org/blob/master/solidity/dao-time-lock-multisig.sol
 */
class DaoMultiSigContract (
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x6080604052600a600555604051620031ef380380620031ef833981810160405260608110156200002e57600080fd5b8101908080519060200190929190805160405193929190846401000000008211156200005957600080fd5b838201915060208201858111156200007057600080fd5b82518660208202830111640100000000821117156200008e57600080fd5b8083526020830192505050908051906020019060200280838360005b83811015620000c7578082015181840152602081019050620000aa565b5050505090500160405260200180519060200190929190505050336000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff160217905550600073ffffffffffffffffffffffffffffffffffffffff168373ffffffffffffffffffffffffffffffffffffffff16146200019757826000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff1602179055505b60008114620001a857806005819055505b620001ca6000604051806020016040528060008152506200024e60201b60201c565b620002326000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff166040518060400160405280600781526020017f666f756e646572000000000000000000000000000000000000000000000000008152506200024e60201b60201c565b62000245826001620004d160201b60201c565b50505062000aae565b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff1614620002a857600080fd5b600080600360008573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000205414156200035957600480549050600360008573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002081905550600480548091906001016200035191906200088d565b90506200039c565b600360008473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000205490505b60405180606001604052808473ffffffffffffffffffffffffffffffffffffffff1681526020018381526020014281525060048281548110620003db57fe5b906000526020600020906003020160008201518160000160006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555060208201518160010190805190602001906200044e929190620008c2565b50604082015181600201559050507f27b022af4a8347100c7a041ce5ccf8e14d644ff05de696315196faae8cd50c9b836001604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001821515151581526020019250505060405180910390a1505050565b60008090505b82518110156200055757811562000523576200051d838281518110620004f957fe5b6020026020010151604051806020016040528060008152506200024e60201b60201c565b62000549565b620005488382815181106200053457fe5b60200260200101516200055c60201b60201c565b5b8080600101915050620004d7565b505050565b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff1614620005b657600080fd5b6000600360008373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000205414156200060457600080fd5b6000600360008373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000205490505b600160048054905003811015620007c457600460018201815481106200066b57fe5b9060005260206000209060030201600482815481106200068757fe5b90600052602060002090600302016000820160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff168160000160006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff160217905550600182018160010190805460018160011615610100020316600290046200072592919062000949565b50600282015481600201559050508060036000600484815481106200074657fe5b906000526020600020906003020160000160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002081905550808060010191505062000649565b506000600360008373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020819055506004600160048054905003815481106200082057fe5b9060005260206000209060030201600080820160006101000a81549073ffffffffffffffffffffffffffffffffffffffff0219169055600182016000620008689190620009d7565b6002820160009055505060048054809190600190036200088991906200088d565b5050565b815481835581811115620008bd57600302816003028360005260206000209182019101620008bc919062000a23565b5b505050565b828054600181600116156101000203166002900490600052602060002090601f016020900481019282601f106200090557805160ff191683800117855562000936565b8280016001018555821562000936579182015b828111156200093557825182559160200191906001019062000918565b5b50905062000945919062000a86565b5090565b828054600181600116156101000203166002900490600052602060002090601f016020900481019282601f10620009845780548555620009c4565b82800160010185558215620009c457600052602060002091601f016020900482015b82811115620009c3578254825591600101919060010190620009a6565b5b509050620009d3919062000a86565b5090565b50805460018160011615610100020316600290046000825580601f10620009ff575062000a20565b601f01602090049060005260206000209081019062000a1f919062000a86565b5b50565b62000a8391905b8082111562000a7f57600080820160006101000a81549073ffffffffffffffffffffffffffffffffffffffff021916905560018201600062000a6d9190620009d7565b60028201600090555060030162000a2a565b5090565b90565b62000aab91905b8082111562000aa757600081600090555060010162000a8d565b5090565b90565b6127318062000abe6000396000f3fe6080604052600436106100fe5760003560e01c80638da5cb5b11610095578063c01f9e3711610064578063c01f9e3714610ae7578063c127c24714610b36578063d3c0715b14610c1e578063eceb294514610cfc578063f2fde38b14610e10576100fe565b80638da5cb5b146106445780638f4ffcb11461069b578063b1050da5146107ad578063b9f256cd1461094a576100fe565b8063237e9492116100d1578063237e9492146103f457806339106821146104c6578063400e39491461052b5780635daf08ca14610556576100fe565b8063013cf08b1461016b5780630b1ca49a14610279578063159887d1146102ca57806315bef9cd14610323575b7fa398b89ba344a0b23a0b9de53db298b2a1a868b396c1878b7e9dcbafecd49b133334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a1005b34801561017757600080fd5b506101a46004803603602081101561018e57600080fd5b8101908080359060200190929190505050610e61565b604051808873ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018781526020018060200186151515158152602001858152602001848152602001838152602001828103825287818151815260200191508051906020019080838360005b8381101561023857808201518184015260208101905061021d565b50505050905090810190601f1680156102655780820380516001836020036101000a031916815260200191505b509850505050505050505060405180910390f35b34801561028557600080fd5b506102c86004803603602081101561029c57600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610f75565b005b3480156102d657600080fd5b5061030d600480360360408110156102ed57600080fd5b810190808035906020019092919080359060200190929190505050611298565b6040518082815260200191505060405180910390f35b34801561032f57600080fd5b506103f26004803603604081101561034657600080fd5b810190808035906020019064010000000081111561036357600080fd5b82018360208201111561037557600080fd5b8035906020019184602083028401116401000000008311171561039757600080fd5b919080806020026020016040519081016040528093929190818152602001838360200280828437600081840152601f19601f8201169050808301925050505050505091929192908035151590602001909291905050506112b5565b005b34801561040057600080fd5b506104c46004803603604081101561041757600080fd5b81019080803590602001909291908035906020019064010000000081111561043e57600080fd5b82018360208201111561045057600080fd5b8035906020019184600183028401116401000000008311171561047257600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f82011690508083019250505050505050919291929050505061132a565b005b3480156104d257600080fd5b50610515600480360360208110156104e957600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050611526565b6040518082815260200191505060405180910390f35b34801561053757600080fd5b5061054061153e565b6040518082815260200191505060405180910390f35b34801561056257600080fd5b5061058f6004803603602081101561057957600080fd5b8101908080359060200190929190505050611544565b604051808473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200180602001838152602001828103825284818151815260200191508051906020019080838360005b838110156106075780820151818401526020810190506105ec565b50505050905090810190601f1680156106345780820380516001836020036101000a031916815260200191505b5094505050505060405180910390f35b34801561065057600080fd5b50610659611633565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b3480156106a757600080fd5b506107ab600480360360808110156106be57600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190803573ffffffffffffffffffffffffffffffffffffffff1690602001909291908035906020019064010000000081111561072557600080fd5b82018360208201111561073757600080fd5b8035906020019184600183028401116401000000008311171561075957600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f820116905080830192505050505050509192919290505050611658565b005b3480156107b957600080fd5b50610934600480360360808110156107d057600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190803590602001909291908035906020019064010000000081111561081757600080fd5b82018360208201111561082957600080fd5b8035906020019184600183028401116401000000008311171561084b57600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f820116905080830192505050505050509192919290803590602001906401000000008111156108ae57600080fd5b8201836020820111156108c057600080fd5b803590602001918460018302840111640100000000831117156108e257600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f82011690508083019250505050505050919291929050505061186f565b6040518082815260200191505060405180910390f35b34801561095657600080fd5b50610ad16004803603608081101561096d57600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190803590602001906401000000008111156109b457600080fd5b8201836020820111156109c657600080fd5b803590602001918460018302840111640100000000831117156109e857600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f82011690508083019250505050505050919291929080359060200190640100000000811115610a4b57600080fd5b820183602082011115610a5d57600080fd5b80359060200191846001830284011164010000000083111715610a7f57600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f820116905080830192505050505050509192919290505050611b47565b6040518082815260200191505060405180910390f35b348015610af357600080fd5b50610b2060048036036020811015610b0a57600080fd5b8101908080359060200190929190505050611bb5565b6040518082815260200191505060405180910390f35b348015610b4257600080fd5b50610c1c60048036036040811015610b5957600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190640100000000811115610b9657600080fd5b820183602082011115610ba857600080fd5b80359060200191846001830284011164010000000083111715610bca57600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f820116905080830192505050505050509192919290505050611c06565b005b348015610c2a57600080fd5b50610cfa60048036036060811015610c4157600080fd5b810190808035906020019092919080351515906020019092919080359060200190640100000000811115610c7457600080fd5b820183602082011115610c8657600080fd5b80359060200191846001830284011164010000000083111715610ca857600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f820116905080830192505050505050509192919290505050611e81565b005b348015610d0857600080fd5b50610df660048036036080811015610d1f57600080fd5b8101908080359060200190929190803573ffffffffffffffffffffffffffffffffffffffff1690602001909291908035906020019092919080359060200190640100000000811115610d7057600080fd5b820183602082011115610d8257600080fd5b80359060200191846001830284011164010000000083111715610da457600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f8201169050808301925050505050505091929192905050506121a0565b604051808215151515815260200191505060405180910390f35b348015610e1c57600080fd5b50610e5f60048036036020811015610e3357600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050612282565b005b60018181548110610e6e57fe5b90600052602060002090600902016000915090508060000160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1690806001015490806002018054600181600116156101000203166002900480601f016020809104026020016040519081016040528092919081815260200182805460018160011615610100020316600290048015610f465780601f10610f1b57610100808354040283529160200191610f46565b820191906000526020600020905b815481529060010190602001808311610f2957829003601f168201915b5050505050908060030160009054906101000a900460ff16908060040154908060050154908060060154905087565b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff1614610fce57600080fd5b6000600360008373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002054141561101b57600080fd5b6000600360008373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000205490505b6001600480549050038110156111d4576004600182018154811061108057fe5b90600052602060002090600302016004828154811061109b57fe5b90600052602060002090600302016000820160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff168160000160006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff1602179055506001820181600101908054600181600116156101000203166002900461113792919061231e565b506002820154816002015590505080600360006004848154811061115757fe5b906000526020600020906003020160000160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020819055508080600101915050611060565b506000600360008373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000208190555060046001600480549050038154811061122f57fe5b9060005260206000209060030201600080820160006101000a81549073ffffffffffffffffffffffffffffffffffffffff021916905560018201600061127591906123a5565b60028201600090555050600480548091906001900361129491906123ed565b5050565b60008183601402816112a657fe5b0460140360020a905092915050565b60008090505b82518110156113255781156112fb576112f68382815181106112d957fe5b602002602001015160405180602001604052806000815250611c06565b611318565b61131783828151811061130a57fe5b6020026020010151610f75565b5b80806001019150506112bb565b505050565b60006001838154811061133957fe5b9060005260206000209060090201905061135283611bb5565b4210158015611365575060008160040154135b801561138057508060030160009054906101000a900460ff16155b80156113bc57506113bb838260000160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff168360010154856121a0565b5b6113c557600080fd5b60018160030160006101000a81548160ff02191690831515021790555060008160000160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168260010154846040518082805190602001908083835b602083106114585780518252602082019150602081019050602083039250611435565b6001836020036101000a03801982511681845116808217855250505050505090500191505060006040518083038185875af1925050503d80600081146114ba576040519150601f19603f3d011682016040523d82523d6000602084013e6114bf565b606091505b50509050806114cd57600080fd5b7fc8e780a743bb79c7e7221b794df13b67119fc788bcabd46747d91a74434c3b6b8483600401546114fd87611bb5565b60405180848152602001838152602001828152602001935050505060405180910390a150505050565b60036020528060005260406000206000915090505481565b60025481565b6004818154811061155157fe5b90600052602060002090600302016000915090508060000160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1690806001018054600181600116156101000203166002900480601f0160208091040260200160405190810160405280929190818152602001828054600181600116156101000203166002900480156116235780601f106115f857610100808354040283529160200191611623565b820191906000526020600020905b81548152906001019060200180831161160657829003601f168201915b5050505050908060020154905083565b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b60008290508073ffffffffffffffffffffffffffffffffffffffff166323b872dd8630876040518463ffffffff1660e01b8152600401808473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019350505050602060405180830381600087803b15801561171857600080fd5b505af115801561172c573d6000803e3d6000fd5b505050506040513d602081101561174257600080fd5b810190808051906020019092919050505061175c57600080fd5b7f0eeb71b8926d7ed8f47a2cedf6b9b204e2001344c7fa20c696c9f06ea7c413c685858585604051808573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018481526020018373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200180602001828103825283818151815260200191508051906020019080838360005b8381101561182b578082015181840152602081019050611810565b50505050905090810190601f1680156118585780820380516001836020036101000a031916815260200191505b509550505050505060405180910390a15050505050565b600080600360003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000205414156118bd57600080fd5b600180548091906001016118d1919061241f565b90506000600182815481106118e257fe5b90600052602060002090600902019050858160000160006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555084816001018190555083816002019080519060200190611956929190612451565b50858584604051602001808473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660601b815260140183815260200182805190602001908083835b602083106119cb57805182526020820191506020810190506020830392506119a8565b6001836020036101000a038019825116818451168082178552505050505050905001935050505060405160208183030381529060405280519060200120816005018190555060008160030160006101000a81548160ff0219169083151502179055504281600601819055507f646fec02522b41e7125cfc859a64fd4f4cefd5dc3b6237ca0abe251ded1fa88182878787604051808581526020018473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200183815260200180602001828103825283818151815260200191508051906020019080838360005b83811015611ad9578082015181840152602081019050611abe565b50505050905090810190601f168015611b065780820380516001836020036101000a031916815260200191505b509550505050505060405180910390a160018201600281905550611b3b82600160405180602001604052806000815250611e81565b81915050949350505050565b600080600360003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020541415611b9557600080fd5b611bab85670de0b6b3a76400008602858561186f565b9050949350505050565b60008060018381548110611bc557fe5b906000526020600020906009020190506000611bed8260040154600160048054905003611298565b9050603c60055482020282600601540192505050919050565b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff1614611c5f57600080fd5b600080600360008573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020541415611d0c57600480549050600360008573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000208190555060048054809190600101611d0591906123ed565b9050611d4f565b600360008473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000205490505b60405180606001604052808473ffffffffffffffffffffffffffffffffffffffff1681526020018381526020014281525060048281548110611d8d57fe5b906000526020600020906003020160008201518160000160006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff1602179055506020820151816001019080519060200190611dfe9291906124d1565b50604082015181600201559050507f27b022af4a8347100c7a041ce5ccf8e14d644ff05de696315196faae8cd50c9b836001604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001821515151581526020019250505060405180910390a1505050565b6000600360003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020541415611ece57600080fd5b600060018481548110611edd57fe5b90600052602060002090600902019050600115158160080160003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060009054906101000a900460ff1615151415611f4d57600080fd5b60018160080160003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060006101000a81548160ff0219169083151502179055508215611fc6578060040160008154809291906001019190505550611fdc565b8060040160008154809291906001900391905055505b7fc34f869b7ff431b034b7b9aea9822dac189a685e0b015c7d1be3add3f89128e88484338560405180858152602001841515151581526020018373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200180602001828103825283818151815260200191508051906020019080838360005b83811015612083578082015181840152602081019050612068565b50505050905090810190601f1680156120b05780820380516001836020036101000a031916815260200191505b509550505050505060405180910390a16120c984611bb5565b421180156120db575060008160040154135b801561217257508060000160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff168160010154604051602001808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660601b815260140182815260200160000192505050604051602081830303815290604052805190602001208160050154145b801561217b5750825b1561219a57612199846040518060200160405280600081525061132a565b5b50505050565b600080600186815481106121b057fe5b90600052602060002090600902019050848484604051602001808473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660601b815260140183815260200182805190602001908083835b602083106122345780518252602082019150602081019050602083039250612211565b6001836020036101000a038019825116818451168082178552505050505050905001935050505060405160208183030381529060405280519060200120816005015414915050949350505050565b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff16146122db57600080fd5b806000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555050565b828054600181600116156101000203166002900490600052602060002090601f016020900481019282601f106123575780548555612394565b8280016001018555821561239457600052602060002091601f016020900482015b82811115612393578254825591600101919060010190612378565b5b5090506123a19190612551565b5090565b50805460018160011615610100020316600290046000825580601f106123cb57506123ea565b601f0160209004906000526020600020908101906123e99190612551565b5b50565b81548183558181111561241a576003028160030283600052602060002091820191016124199190612576565b5b505050565b81548183558181111561244c5760090281600902836000526020600020918201910161244b91906125d4565b5b505050565b828054600181600116156101000203166002900490600052602060002090601f016020900481019282601f1061249257805160ff19168380011785556124c0565b828001600101855582156124c0579182015b828111156124bf5782518255916020019190600101906124a4565b5b5090506124cd9190612551565b5090565b828054600181600116156101000203166002900490600052602060002090601f016020900481019282601f1061251257805160ff1916838001178555612540565b82800160010185558215612540579182015b8281111561253f578251825591602001919060010190612524565b5b50905061254d9190612551565b5090565b61257391905b8082111561256f576000816000905550600101612557565b5090565b90565b6125d191905b808211156125cd57600080820160006101000a81549073ffffffffffffffffffffffffffffffffffffffff02191690556001820160006125bc91906123a5565b60028201600090555060030161257c565b5090565b90565b61266b91905b8082111561266757600080820160006101000a81549073ffffffffffffffffffffffffffffffffffffffff0219169055600182016000905560028201600061262291906123a5565b6003820160006101000a81549060ff021916905560048201600090556005820160009055600682016000905560078201600061265e919061266e565b506009016125da565b5090565b90565b508054600082556002029060005260206000209081019061268f9190612692565b50565b6126f991905b808211156126f557600080820160006101000a81549060ff02191690556000820160016101000a81549073ffffffffffffffffffffffffffffffffffffffff02191690556001820160006126ec91906123a5565b50600201612698565b5090565b9056fea265627a7a72315820942ce86dd6412c45a350796e1d9663042dde380de5bf102248b25c3678a60b8064736f6c63430005100032"
) {

    fun createContract(
        address: String,
        initialMembers: List<String>,
        minimumAmountOfMinutes: Long
    ): Single<ChainResponse<TransactionCommitted>> {
        return create(listOf(
            Address(address),
            DynamicArray<Utf8String>(Utf8String::class.java, initialMembers.map { Utf8String(it) }),
            Uint(BigInteger.valueOf(minimumAmountOfMinutes))
        ))
    }
}
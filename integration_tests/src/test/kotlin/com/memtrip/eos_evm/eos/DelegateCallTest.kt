package com.memtrip.eos_evm.eos

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.assertConsoleString
import com.memtrip.eos_evm.eos.actions.raw.RawAction
import com.memtrip.eos_evm.eos.state.GetAccountState
import com.memtrip.eos_evm.eos.state.GetCode
import com.memtrip.eos_evm.ethereum.EthereumTransaction
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert
import org.junit.Assert.assertEquals
import org.junit.Assert.fail
import org.junit.Test
import java.math.BigInteger
import java.util.concurrent.TimeUnit

class DelegateCallTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val rawAction = RawAction(chainApi)

    private val getCode = GetCode(chainApi)

    private val getAccountState = GetAccountState(chainApi)

    @Test
    fun `Execute a log statement in a child contract via delegate call`() {

        // given
        val (contractAccountName, contractPrivateKey, contractEthAccount) = setupTransactions.seedWithEvmBalance(17000)
        val contractAccountIdentifier = AccountIdentifier.create(contractAccountName, contractEthAccount.address)

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a00", 16),
            BigInteger.valueOf(0),
            "0x608060405234801561001057600080fd5b5060405161001d9061007e565b604051809103906000f080158015610039573d6000803e3d6000fd5b506000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555061008a565b60e98061024c83390190565b6101b3806100996000396000f3fe6080604052600060606000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f7468616e6b73282900000000000000000000000000000000000000000000000081525060080190506040518091039020604051602401604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b6020831061010c57805182526020820191506020810190506020830392506100e9565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d806000811461016c576040519150601f19603f3d011682016040523d82523d6000602084013e610171565b606091505b508092508193505050505000fea265627a7a72315820da7c31f28b4f3375beaded9e8de4f3d0d931474ec015024b6692d620ea57405264736f6c634300051000326080604052348015600f57600080fd5b5060cb8061001e6000396000f3fe608060405260043610601c5760003560e01c806373d98e39146021575b600080fd5b60276029565b005b7fbbbf55a6f5ae8ee75e6fb8f92a93e32841ed3055bf2139469c60bbc79a455da73334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a156fea265627a7a7231582069c4265b77ab1bd39221ac01c9f6f1adacb2f5a7beeccf724523846fa4aaf8ba64736f6c63430005100032"
        )

        val createContractResponse = faultTolerant {
            rawAction.pushTransaction(
                contractAccountName,
                transaction.sign(contractEthAccount).signedTransaction.toHexString(),
                contractAccountIdentifier.toHexString(),
                TransactionContext(
                    contractAccountName,
                    contractPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet()
        }


        // then
        assertEquals(202, createContractResponse.statusCode)

        // and when
        val getCodeResult = getCode.getAll(
            contractAccountIdentifier.pad256().toHexString()
        ).blockingGet()

        val childAddress = if (getCodeResult !is GetCode.Record.Multiple) "invalid_address" else {
            assertEquals(2, getCodeResult.items.size)
            assertEquals(
                "608060405260043610601c5760003560e01c806373d98e39146021575b600080fd5b60276029565b005b7fbbbf55a6f5ae8ee75e6fb8f92a93e32841ed3055bf2139469c60bbc79a455da73334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a156fea265627a7a7231582069c4265b77ab1bd39221ac01c9f6f1adacb2f5a7beeccf724523846fa4aaf8ba64736f6c63430005100032",
                getCodeResult.items[0].code
            )
            assertEquals(
                "6080604052600060606000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f7468616e6b73282900000000000000000000000000000000000000000000000081525060080190506040518091039020604051602401604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b6020831061010c57805182526020820191506020810190506020830392506100e9565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d806000811461016c576040519150601f19603f3d011682016040523d82523d6000602084013e610171565b606091505b508092508193505050505000fea265627a7a72315820da7c31f28b4f3375beaded9e8de4f3d0d931474ec015024b6692d620ea57405264736f6c63430005100032",
                getCodeResult.items[1].code
            )
            assertEquals(getCodeResult.items[1].address, contractAccountIdentifier.pad256().toHexString())
            getCodeResult.items[0].address
        }

        // and then
        val (senderAccountName, senderAccountPrivateKey, senderEthAccount) = setupTransactions.seedWithEvmBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        val callTransaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger.valueOf(1),
            "0x",
            contractAccountIdentifier.toHexString()
        )

        val callTransactionResponse = rawAction.pushTransaction(
            senderAccountName,
            callTransaction.sign(senderEthAccount).signedTransaction.toHexString(),
            senderAccountIdentifier.toHexString(),
            TransactionContext(
                senderAccountName,
                senderAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // and when
        val getAccountState = getAccountState.getAll(contractAccountIdentifier.pad256().toHexString()).blockingGet()

        // and then
        if (getAccountState !is GetAccountState.Record.Multiple) fail("no account states") else {
            val items = getAccountState.items
            assertEquals(items.first().accountIdentifier, contractAccountIdentifier.pad256().toHexString())
            assertEquals(items[0].value, childAddress)
        }

        // and then
        val error = callTransactionResponse.errorBody?.error?.details?.get(1)?.message
        assertEquals(202, callTransactionResponse.statusCode)

        // and then
        callTransactionResponse.assertConsoleString(
            "return[0000000000000000000000000000000000000000000000000000000000000003]"
        )
    }

//    @Test
//    fun `Delegate call`() {
//
//        // given
//        val (contractAccountName, contractPrivateKey, contractEthAccount) = setupTransactions.seedWithEvmBalance(17000)
//        val contractAccountIdentifier = AccountIdentifier.create(contractAccountName, contractEthAccount.address)
//
//        // when
//        val transaction = EthereumTransaction(
//            1,
//            BigInteger("5af3107a4000", 16),
//            BigInteger("0186a00", 16),
//            BigInteger.valueOf(0),
//            "0x608060405234801561001057600080fd5b5060405161001d906100e8565b604051809103906000f080158015610039573d6000803e3d6000fd5b50600160006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff160217905550604051610086906100f5565b604051809103906000f0801580156100a2573d6000803e3d6000fd5b50600260006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff160217905550610102565b61012f8061076a83390190565b6101138061089983390190565b610659806101116000396000f3fe608060405234801561001057600080fd5b50600436106100625760003560e01c80631003e2d214610067578063131e2f181461009557806365372147146100c357806374c1328a146100e1578063bf9ce952146101b0578063ec597128146101fa575b600080fd5b6100936004803603602081101561007d57600080fd5b8101908080359060200190929190505050610244565b005b6100c1600480360360208110156100ab57600080fd5b81019080803590602001909291905050506103df565b005b6100cb61057a565b6040518082815260200191505060405180910390f35b61019a600480360360208110156100f757600080fd5b810190808035906020019064010000000081111561011457600080fd5b82018360208201111561012657600080fd5b8035906020019184600183028401116401000000008311171561014857600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f820116905080830192505050505050509192919290505050610580565b6040518082815260200191505060405180910390f35b6101b86105d8565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6102026105fe565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b60006060600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f63616c63756c6174652875696e74323536290000000000000000000000000000815250601201905060405180910390208460405160240180828152602001915050604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b602083106103585780518252602082019150602081019050602083039250610335565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d80600081146103b8576040519150601f19603f3d011682016040523d82523d6000602084013e6103bd565b606091505b508092508193505050826103d082610580565b146103da57600080fd5b505050565b60006060600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f63616c63756c6174652875696e74323536290000000000000000000000000000815250601201905060405180910390208460405160240180828152602001915050604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b602083106104f357805182526020820191506020810190506020830392506104d0565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d8060008114610553576040519150601f19603f3d011682016040523d82523d6000602084013e610558565b606091505b5080925081935050508261056b82610580565b1461057557600080fd5b505050565b60005481565b60008060008090505b83518110156105ce576001810184510360080260020a8482815181106105ab57fe5b602001015160f81c60f81b60f81c60ff1602820191508080600101915050610589565b5080915050919050565b600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a7231582017b4eb46db1316fc2127512df0b43ad0380c1b0eb75f3a31fb9a378db39670ff64736f6c63430005100032608060405234801561001057600080fd5b5061010f806100206000396000f3fe6080604052348015600f57600080fd5b506004361060325760003560e01c806365372147146037578063b9d92de8146053575b600080fd5b603d6092565b6040518082815260200191505060405180910390f35b607c60048036036020811015606757600080fd5b81019080803590602001909291905050506098565b6040518082815260200191505060405180910390f35b60005481565b60008082141560ac576000808190555060d0565b60008260005402905082600054828160c057fe5b041460c757fe5b80600081905550505b600054905091905056fea265627a7a72315820f28bb30210248f29692c73c3ecc526072fde84cc5375d676f207491a5933010c64736f6c63430005100032608060405234801561001057600080fd5b5060f48061001f6000396000f3fe6080604052348015600f57600080fd5b506004361060325760003560e01c806365372147146037578063b9d92de8146053575b600080fd5b603d6092565b6040518082815260200191505060405180910390f35b607c60048036036020811015606757600080fd5b81019080803590602001909291905050506098565b6040518082815260200191505060405180910390f35b60005481565b6000808260005401905060005481101560ad57fe5b8060008190555060005491505091905056fea265627a7a723158202fe7c9dfca39dfa60dab36594791f39966033d3b6125f96e37634eb5acd6d1c464736f6c63430005100032"
//        )
//
//        val createContractResponse = faultTolerant {
//            rawAction.pushTransaction(
//                contractAccountName,
//                transaction.sign(contractEthAccount).signedTransaction.toHexString(),
//                contractAccountIdentifier.toHexString(),
//                TransactionContext(
//                    contractAccountName,
//                    contractPrivateKey,
//                    transactionDefaultExpiry()
//                )
//            ).blockingGet()
//        }
//
//
//        // then
//        assertEquals(202, createContractResponse.statusCode)
//
//        // and when
//        val getCodeResult = getCode.getAll(
//            contractAccountIdentifier.pad256().toHexString()
//        ).blockingGet()
//
//        val childAddresses = if (getCodeResult !is GetCode.Record.Multiple) listOf() else {
//            assertEquals(3, getCodeResult.items.size)
//            assertEquals(
//                "6080604052348015600f57600080fd5b506004361060325760003560e01c806365372147146037578063b9d92de8146053575b600080fd5b603d6092565b6040518082815260200191505060405180910390f35b607c60048036036020811015606757600080fd5b81019080803590602001909291905050506098565b6040518082815260200191505060405180910390f35b60005481565b60008082141560ac576000808190555060d0565b60008260005402905082600054828160c057fe5b041460c757fe5b80600081905550505b600054905091905056fea265627a7a72315820f28bb30210248f29692c73c3ecc526072fde84cc5375d676f207491a5933010c64736f6c63430005100032",
//                getCodeResult.items[0].code
//            )
//            assertEquals(
//                "6080604052348015600f57600080fd5b506004361060325760003560e01c806365372147146037578063b9d92de8146053575b600080fd5b603d6092565b6040518082815260200191505060405180910390f35b607c60048036036020811015606757600080fd5b81019080803590602001909291905050506098565b6040518082815260200191505060405180910390f35b60005481565b6000808260005401905060005481101560ad57fe5b8060008190555060005491505091905056fea265627a7a723158202fe7c9dfca39dfa60dab36594791f39966033d3b6125f96e37634eb5acd6d1c464736f6c63430005100032",
//                getCodeResult.items[1].code
//            )
//            assertEquals(
//                "608060405234801561001057600080fd5b50600436106100625760003560e01c80631003e2d214610067578063131e2f181461009557806365372147146100c357806374c1328a146100e1578063bf9ce952146101b0578063ec597128146101fa575b600080fd5b6100936004803603602081101561007d57600080fd5b8101908080359060200190929190505050610244565b005b6100c1600480360360208110156100ab57600080fd5b81019080803590602001909291905050506103df565b005b6100cb61057a565b6040518082815260200191505060405180910390f35b61019a600480360360208110156100f757600080fd5b810190808035906020019064010000000081111561011457600080fd5b82018360208201111561012657600080fd5b8035906020019184600183028401116401000000008311171561014857600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f820116905080830192505050505050509192919290505050610580565b6040518082815260200191505060405180910390f35b6101b86105d8565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6102026105fe565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b60006060600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f63616c63756c6174652875696e74323536290000000000000000000000000000815250601201905060405180910390208460405160240180828152602001915050604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b602083106103585780518252602082019150602081019050602083039250610335565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d80600081146103b8576040519150601f19603f3d011682016040523d82523d6000602084013e6103bd565b606091505b508092508193505050826103d082610580565b146103da57600080fd5b505050565b60006060600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f63616c63756c6174652875696e74323536290000000000000000000000000000815250601201905060405180910390208460405160240180828152602001915050604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b602083106104f357805182526020820191506020810190506020830392506104d0565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d8060008114610553576040519150601f19603f3d011682016040523d82523d6000602084013e610558565b606091505b5080925081935050508261056b82610580565b1461057557600080fd5b505050565b60005481565b60008060008090505b83518110156105ce576001810184510360080260020a8482815181106105ab57fe5b602001015160f81c60f81b60f81c60ff1602820191508080600101915050610589565b5080915050919050565b600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a7231582017b4eb46db1316fc2127512df0b43ad0380c1b0eb75f3a31fb9a378db39670ff64736f6c63430005100032",
//                getCodeResult.items[2].code
//            )
//            assertEquals(getCodeResult.items[2].address, contractAccountIdentifier.pad256().toHexString())
//            listOf(getCodeResult.items[0].address, getCodeResult.items[1].address)
//        }
//
//        // and then
//        val (senderAccountName, senderAccountPrivateKey, senderEthAccount) = setupTransactions.seedWithEvmBalance()
//        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)
//
//        val callTransaction = EthereumTransaction(
//            1,
//            BigInteger("5af3107a4000", 16),
//            BigInteger("0186a0", 16),
//            BigInteger.valueOf(0),
//            "0x1003e2d20000000000000000000000000000000000000000000000000000000000000002",
//            contractAccountIdentifier.toHexString()
//        )
//
//        val callTransactionResponse = rawAction.pushTransaction(
//            senderAccountName,
//            callTransaction.sign(senderEthAccount).signedTransaction.toHexString(),
//            senderAccountIdentifier.toHexString(),
//            TransactionContext(
//                senderAccountName,
//                senderAccountPrivateKey,
//                transactionDefaultExpiry()
//            )
//        ).blockingGet()
//
//        // and when
//        val getAccountState = getAccountState.getAll(contractAccountName).blockingGet()
//
//        // and then
//        if (getAccountState !is GetAccountState.Record.Multiple) fail("no account states") else {
//            val items = getAccountState.items
//            assertEquals(items.first().accountIdentifier, contractAccountIdentifier.pad256().toHexString())
//            assertEquals(items[0].value, childAddresses[0])
//            assertEquals(items[1].value, childAddresses[1])
//        }
//
//        // and then
//        val error = callTransactionResponse.errorBody?.error?.details?.get(1)?.message
//        assertEquals(202, callTransactionResponse.statusCode)
//
//        // and then
//        callTransactionResponse.assertConsoleString(
//            "return[0000000000000000000000000000000000000000000000000000000000000003]"
//        )
//    }
}
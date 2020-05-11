package com.memtrip.evm.eos

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.assertConsoleError
import com.memtrip.evm.eos.actions.raw.RawAction
import com.memtrip.evm.eos.state.GetAccountState
import com.memtrip.evm.eos.evm.GetCode
import com.memtrip.evm.ethereum.EthereumTransaction
import com.memtrip.evm.ethereum.pad256
import com.memtrip.evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Assert.fail
import org.junit.Assert.assertTrue
import org.junit.Assert.assertNotEquals
import org.junit.Test
import java.math.BigInteger
import java.util.concurrent.TimeUnit

class CreateContractTest {

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
    fun `Create a contract via COPYCODE`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger.valueOf(0),
            "0x608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390a160b8806100826000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a723158209551755b4e59ca6cf78d79f5356d91565950805937074458700610f23c6ecf9b64736f6c63430005100032"
        )

        val response = faultTolerant {
            rawAction.pushTransaction(
                newAccountName,
                transaction.sign(newEthAccount).signedTransaction.toHexString(),
                accountIdentifier.toHexString(),
                TransactionContext(
                    newAccountName,
                    newAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet()
        }

        // then
        assertEquals(response.statusCode, 202)

        // and when
        val getCodeResult = getCode.getValue(
            accountIdentifier.pad256().toHexString()
        ).blockingGet()

        if (getCodeResult !is GetCode.Record.Value) fail("code record not found") else {
            assertEquals(
                "6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a723158209551755b4e59ca6cf78d79f5356d91565950805937074458700610f23c6ecf9b64736f6c63430005100032",
                getCodeResult.item.code
            )
            assertEquals("1.0", getCodeResult.item.nonce)
            assertEquals("0.0000 EVM", getCodeResult.item.balance.toString())
        }
    }

    @Test
    fun `Create a contract CODECOPY and a child contract with CREATE`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val newAccountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger.valueOf(0),
            "0x608060405234801561001057600080fd5b5060405161001d9061007e565b604051809103906000f080158015610039573d6000803e3d6000fd5b506000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555061008a565b60978061027083390190565b6101d7806100996000396000f3fe60806040526004361061001e5760003560e01c80635c60da1b14610126575b7f2230ca5690d71a74605e39bd522eea4bff3859bc627abd4ac5e473fcb8c5c3b05a6040518082815260200191505060405180910390a16000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff165a34600036604051808383808284378083019250505092505050600060405180830381858888f193505050503d80600081146100e5576040519150601f19603f3d011682016040523d82523d6000602084013e6100ea565b606091505b5050507f2230ca5690d71a74605e39bd522eea4bff3859bc627abd4ac5e473fcb8c5c3b05a6040518082815260200191505060405180910390a1005b34801561013257600080fd5b5061013b61017d565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a72315820a640f191ec583fbf9eec25b23042882a593697e120f7cea5230f7784081c042364736f6c634300051000326080604052348015600f57600080fd5b5060798061001e6000396000f3fe60806040527fe1f2fff362a4d171d703cc8eb57b9a51dfaa0c2eb2c706aa8ad32011aabf6d0b5a6040518082815260200191505060405180910390a16000604257fe5b00fea265627a7a7231582032423d6c27d3e2eb9e2afa78c5a73bbc112a163dd8f1d29f6a0b05237bfeac9964736f6c63430005100032"
        )

        val response = faultTolerant {
            rawAction.pushTransaction(
                newAccountName,
                transaction.sign(newEthAccount).signedTransaction.toHexString(),
                newAccountIdentifier.toHexString(),
                TransactionContext(
                    newAccountName,
                    newAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet()
        }
        // then
        assertEquals(response.statusCode, 202)

        // and when
        val getParentCode = getCode.getAllByOwner(newAccountIdentifier.pad256().toHexString()).blockingGet()

        // and then
        val parentAddress = if (getParentCode is GetCode.Record.Multiple) {
            assertEquals(1, getParentCode.items.size)
            assertEquals(
                "60806040526004361061001e5760003560e01c80635c60da1b14610126575b7f2230ca5690d71a74605e39bd522eea4bff3859bc627abd4ac5e473fcb8c5c3b05a6040518082815260200191505060405180910390a16000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff165a34600036604051808383808284378083019250505092505050600060405180830381858888f193505050503d80600081146100e5576040519150601f19603f3d011682016040523d82523d6000602084013e6100ea565b606091505b5050507f2230ca5690d71a74605e39bd522eea4bff3859bc627abd4ac5e473fcb8c5c3b05a6040518082815260200191505060405180910390a1005b34801561013257600080fd5b5061013b61017d565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a72315820a640f191ec583fbf9eec25b23042882a593697e120f7cea5230f7784081c042364736f6c63430005100032",
                getParentCode.items.first().code
            )
            assertEquals("2.0", getParentCode.items.first().nonce)
            getParentCode.items.first().address
        } else "address does not exist"

        val result = getCode.getAllByOwner(parentAddress).blockingGet()

        val childAddress = if (result is GetCode.Record.Multiple) {
            assertEquals(1, result.items.size)
            assertEquals(
                "60806040527fe1f2fff362a4d171d703cc8eb57b9a51dfaa0c2eb2c706aa8ad32011aabf6d0b5a6040518082815260200191505060405180910390a16000604257fe5b00fea265627a7a7231582032423d6c27d3e2eb9e2afa78c5a73bbc112a163dd8f1d29f6a0b05237bfeac9964736f6c63430005100032",
                result.items[0].code
            )
            assertEquals("1.0", result.items[0].nonce)
            result.items[0].address
        } else "no address found"

        // and then child contract address is saved
        val accountStateResult = getAccountState.getAll(parentAddress).blockingGet()
        if (accountStateResult !is GetAccountState.Record.Multiple) fail("no account states") else {
            assertEquals(1, accountStateResult.items.size)
            assertEquals(childAddress, accountStateResult.items.first().value)
        }
    }

    @Test
    fun `Create a contract via CREATE2`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger.valueOf(0),
            "0x6080604052348015600f57600080fd5b5060cb8061001e6000396000f3fe608060405260043610601c5760003560e01c806373d98e39146021575b600080fd5b60276029565b005b7fbbbf55a6f5ae8ee75e6fb8f92a93e32841ed3055bf2139469c60bbc79a455da73334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a156fea265627a7a7231582069c4265b77ab1bd39221ac01c9f6f1adacb2f5a7beeccf724523846fa4aaf8ba64736f6c63430005100032"
        )

        val response = faultTolerant {
            rawAction.pushTransaction(
                newAccountName,
                transaction.sign(newEthAccount).signedTransaction.toHexString(),
                accountIdentifier.toHexString(),
                TransactionContext(
                    newAccountName,
                    newAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet()
        }

        // then
        assertEquals(response.statusCode, 202)

        // and when
        val getCodeResult = getCode.getAllByOwner(
            accountIdentifier.pad256().toHexString()
        ).blockingGet()

        if (getCodeResult !is GetCode.Record.Multiple) fail("code record not found") else {
            assertEquals(1, getCodeResult.items.size)
            assertEquals(
                "608060405260043610601c5760003560e01c806373d98e39146021575b600080fd5b60276029565b005b7fbbbf55a6f5ae8ee75e6fb8f92a93e32841ed3055bf2139469c60bbc79a455da73334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a156fea265627a7a7231582069c4265b77ab1bd39221ac01c9f6f1adacb2f5a7beeccf724523846fa4aaf8ba64736f6c63430005100032",
                    getCodeResult.items[0].code
            )
            assertEquals("1.0", getCodeResult.items[0].nonce)
            assertEquals("0.0000 EVM", getCodeResult.items[0].balance.toString())
            assertTrue(getCodeResult.items[0].address.isNotEmpty())
        }
    }

    @Test
    fun `Create a contract with CODECOPY, and two child contracts with CREATE`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(17000)
        val newAccountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a00", 16),
            BigInteger.valueOf(0),
            "0x608060405234801561001057600080fd5b5060405161001d906100e8565b604051809103906000f080158015610039573d6000803e3d6000fd5b50600160006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff160217905550604051610086906100f5565b604051809103906000f0801580156100a2573d6000803e3d6000fd5b50600260006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff160217905550610102565b61012f8061076a83390190565b6101138061089983390190565b610659806101116000396000f3fe608060405234801561001057600080fd5b50600436106100625760003560e01c80631003e2d214610067578063131e2f181461009557806365372147146100c357806374c1328a146100e1578063bf9ce952146101b0578063ec597128146101fa575b600080fd5b6100936004803603602081101561007d57600080fd5b8101908080359060200190929190505050610244565b005b6100c1600480360360208110156100ab57600080fd5b81019080803590602001909291905050506103df565b005b6100cb61057a565b6040518082815260200191505060405180910390f35b61019a600480360360208110156100f757600080fd5b810190808035906020019064010000000081111561011457600080fd5b82018360208201111561012657600080fd5b8035906020019184600183028401116401000000008311171561014857600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f820116905080830192505050505050509192919290505050610580565b6040518082815260200191505060405180910390f35b6101b86105d8565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6102026105fe565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b60006060600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f63616c63756c6174652875696e74323536290000000000000000000000000000815250601201905060405180910390208460405160240180828152602001915050604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b602083106103585780518252602082019150602081019050602083039250610335565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d80600081146103b8576040519150601f19603f3d011682016040523d82523d6000602084013e6103bd565b606091505b508092508193505050826103d082610580565b146103da57600080fd5b505050565b60006060600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f63616c63756c6174652875696e74323536290000000000000000000000000000815250601201905060405180910390208460405160240180828152602001915050604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b602083106104f357805182526020820191506020810190506020830392506104d0565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d8060008114610553576040519150601f19603f3d011682016040523d82523d6000602084013e610558565b606091505b5080925081935050508261056b82610580565b1461057557600080fd5b505050565b60005481565b60008060008090505b83518110156105ce576001810184510360080260020a8482815181106105ab57fe5b602001015160f81c60f81b60f81c60ff1602820191508080600101915050610589565b5080915050919050565b600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a7231582017b4eb46db1316fc2127512df0b43ad0380c1b0eb75f3a31fb9a378db39670ff64736f6c63430005100032608060405234801561001057600080fd5b5061010f806100206000396000f3fe6080604052348015600f57600080fd5b506004361060325760003560e01c806365372147146037578063b9d92de8146053575b600080fd5b603d6092565b6040518082815260200191505060405180910390f35b607c60048036036020811015606757600080fd5b81019080803590602001909291905050506098565b6040518082815260200191505060405180910390f35b60005481565b60008082141560ac576000808190555060d0565b60008260005402905082600054828160c057fe5b041460c757fe5b80600081905550505b600054905091905056fea265627a7a72315820f28bb30210248f29692c73c3ecc526072fde84cc5375d676f207491a5933010c64736f6c63430005100032608060405234801561001057600080fd5b5060f48061001f6000396000f3fe6080604052348015600f57600080fd5b506004361060325760003560e01c806365372147146037578063b9d92de8146053575b600080fd5b603d6092565b6040518082815260200191505060405180910390f35b607c60048036036020811015606757600080fd5b81019080803590602001909291905050506098565b6040518082815260200191505060405180910390f35b60005481565b6000808260005401905060005481101560ad57fe5b8060008190555060005491505091905056fea265627a7a723158202fe7c9dfca39dfa60dab36594791f39966033d3b6125f96e37634eb5acd6d1c464736f6c63430005100032"
        )

        val response = faultTolerant {
            rawAction.pushTransaction(
                newAccountName,
                transaction.sign(newEthAccount).signedTransaction.toHexString(),
                newAccountIdentifier.toHexString(),
                TransactionContext(
                    newAccountName,
                    newAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet()
        }

        // then
        assertEquals(response.statusCode, 202)

        // and when
        val getParentCode = getCode.getAllByOwner(newAccountIdentifier.pad256().toHexString()).blockingGet()

        // and then
        val parentAddress = if (getParentCode is GetCode.Record.Multiple) {
            assertEquals(1, getParentCode.items.size)
            assertEquals(
                "608060405234801561001057600080fd5b50600436106100625760003560e01c80631003e2d214610067578063131e2f181461009557806365372147146100c357806374c1328a146100e1578063bf9ce952146101b0578063ec597128146101fa575b600080fd5b6100936004803603602081101561007d57600080fd5b8101908080359060200190929190505050610244565b005b6100c1600480360360208110156100ab57600080fd5b81019080803590602001909291905050506103df565b005b6100cb61057a565b6040518082815260200191505060405180910390f35b61019a600480360360208110156100f757600080fd5b810190808035906020019064010000000081111561011457600080fd5b82018360208201111561012657600080fd5b8035906020019184600183028401116401000000008311171561014857600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f820116905080830192505050505050509192919290505050610580565b6040518082815260200191505060405180910390f35b6101b86105d8565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6102026105fe565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b60006060600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f63616c63756c6174652875696e74323536290000000000000000000000000000815250601201905060405180910390208460405160240180828152602001915050604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b602083106103585780518252602082019150602081019050602083039250610335565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d80600081146103b8576040519150601f19603f3d011682016040523d82523d6000602084013e6103bd565b606091505b508092508193505050826103d082610580565b146103da57600080fd5b505050565b60006060600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f63616c63756c6174652875696e74323536290000000000000000000000000000815250601201905060405180910390208460405160240180828152602001915050604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b602083106104f357805182526020820191506020810190506020830392506104d0565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d8060008114610553576040519150601f19603f3d011682016040523d82523d6000602084013e610558565b606091505b5080925081935050508261056b82610580565b1461057557600080fd5b505050565b60005481565b60008060008090505b83518110156105ce576001810184510360080260020a8482815181106105ab57fe5b602001015160f81c60f81b60f81c60ff1602820191508080600101915050610589565b5080915050919050565b600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a7231582017b4eb46db1316fc2127512df0b43ad0380c1b0eb75f3a31fb9a378db39670ff64736f6c63430005100032",
                getParentCode.items.first().code
            )
            assertEquals("3.0", getParentCode.items.first().nonce)
            getParentCode.items.first().address
        } else "invalid address"

        // and when
        val getCodeResult = getCode.getAllByOwner(parentAddress).blockingGet()

        if (getCodeResult is GetCode.Record.Multiple) {
            assertEquals(2, getCodeResult.items.size)
            assertEquals(
                "6080604052348015600f57600080fd5b506004361060325760003560e01c806365372147146037578063b9d92de8146053575b600080fd5b603d6092565b6040518082815260200191505060405180910390f35b607c60048036036020811015606757600080fd5b81019080803590602001909291905050506098565b6040518082815260200191505060405180910390f35b60005481565b60008082141560ac576000808190555060d0565b60008260005402905082600054828160c057fe5b041460c757fe5b80600081905550505b600054905091905056fea265627a7a72315820f28bb30210248f29692c73c3ecc526072fde84cc5375d676f207491a5933010c64736f6c63430005100032",
                getCodeResult.items[0].code
            )
            assertEquals("1.0", getCodeResult.items[0].nonce)
            assertEquals(
                "6080604052348015600f57600080fd5b506004361060325760003560e01c806365372147146037578063b9d92de8146053575b600080fd5b603d6092565b6040518082815260200191505060405180910390f35b607c60048036036020811015606757600080fd5b81019080803590602001909291905050506098565b6040518082815260200191505060405180910390f35b60005481565b6000808260005401905060005481101560ad57fe5b8060008190555060005491505091905056fea265627a7a723158202fe7c9dfca39dfa60dab36594791f39966033d3b6125f96e37634eb5acd6d1c464736f6c63430005100032",
                getCodeResult.items[1].code
            )
            assertEquals("1.0", getCodeResult.items[1].nonce)
        } else fail("could not find code")

        // and then the child contract addresses are saved
        val accountStateResult = getAccountState.getAll(parentAddress).blockingGet()
        if (accountStateResult !is GetAccountState.Record.Multiple) fail("no account states") else {
            assertNotEquals(accountStateResult.items[0].value, accountStateResult.items[1].value)
        }
    }

    @Test
    fun `Attempt to create an impossible contract`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(17000)
        val newAccountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a00", 16),
            BigInteger.valueOf(0),
            "0x608060405234801561001057600080fd5b503073ffffffffffffffffffffffffffffffffffffffff1663f8a8fd6d6040518163ffffffff1660e01b815260040160206040518083038186803b15801561005757600080fd5b505afa15801561006b573d6000803e3d6000fd5b505050506040513d602081101561008157600080fd5b8101908080519060200190929190505050506087806100a16000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063f8a8fd6d14602d575b600080fd5b60336049565b6040518082815260200191505060405180910390f35b6000600290509056fea265627a7a72315820523c8d6f31779c4cb02b3588d0ce28924193ddb9e749963217fe3dfa92849bab64736f6c63430005100032"
        )

        val response = faultTolerant {
            rawAction.pushTransaction(
                newAccountName,
                transaction.sign(newEthAccount).signedTransaction.toHexString(),
                newAccountIdentifier.toHexString(),
                TransactionContext(newAccountName, newAccountPrivateKey, transactionDefaultExpiry()
                )
            ).blockingGet()
        }

        // then
        assertEquals(response.statusCode, 500)
        response.assertConsoleError("MESSAGE_CALL_REVERTED")
    }
}
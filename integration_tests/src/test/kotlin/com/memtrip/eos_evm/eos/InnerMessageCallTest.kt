package com.memtrip.eos_evm.eos

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.assertConsoleString
import com.memtrip.eos_evm.assertNotConsoleString
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

class InnerMessageCallTest {

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
    fun `internal message call to a subcontract`() {
        // given
        val (contractAccountName, contractAccountPrivateKey, contractEthAccount) = setupTransactions.seedWithEvmBalance()
        val contractAccountIdentifier = AccountIdentifier.create(contractAccountName, contractEthAccount.address)

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger.valueOf(0),
            "0x608060405234801561001057600080fd5b5060405161001d9061007e565b604051809103906000f080158015610039573d6000803e3d6000fd5b506000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555061008a565b60978061027083390190565b6101d7806100996000396000f3fe60806040526004361061001e5760003560e01c80635c60da1b14610126575b7f2230ca5690d71a74605e39bd522eea4bff3859bc627abd4ac5e473fcb8c5c3b05a6040518082815260200191505060405180910390a16000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff165a34600036604051808383808284378083019250505092505050600060405180830381858888f193505050503d80600081146100e5576040519150601f19603f3d011682016040523d82523d6000602084013e6100ea565b606091505b5050507f2230ca5690d71a74605e39bd522eea4bff3859bc627abd4ac5e473fcb8c5c3b05a6040518082815260200191505060405180910390a1005b34801561013257600080fd5b5061013b61017d565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a72315820a640f191ec583fbf9eec25b23042882a593697e120f7cea5230f7784081c042364736f6c634300051000326080604052348015600f57600080fd5b5060798061001e6000396000f3fe60806040527fe1f2fff362a4d171d703cc8eb57b9a51dfaa0c2eb2c706aa8ad32011aabf6d0b5a6040518082815260200191505060405180910390a16000604257fe5b00fea265627a7a7231582032423d6c27d3e2eb9e2afa78c5a73bbc112a163dd8f1d29f6a0b05237bfeac9964736f6c63430005100032"
        )

        val createContractResponse = faultTolerant {
            rawAction.pushTransaction(
                contractAccountName,
                transaction.sign(contractEthAccount).signedTransaction.toHexString(),
                contractAccountIdentifier.toHexString(),
                TransactionContext(
                    contractAccountName,
                    contractAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet()
        }

        // then
        assertEquals(202, createContractResponse.statusCode)

        // and when
        val contractCode = getCode.getAll(
            contractAccountIdentifier.pad256().toHexString()
        ).blockingGet()

        // and then
        val childAddress = if (contractCode is GetCode.Record.Multiple) {
            assertEquals(2, contractCode.items.size)
            assertEquals(
                "60806040527fe1f2fff362a4d171d703cc8eb57b9a51dfaa0c2eb2c706aa8ad32011aabf6d0b5a6040518082815260200191505060405180910390a16000604257fe5b00fea265627a7a7231582032423d6c27d3e2eb9e2afa78c5a73bbc112a163dd8f1d29f6a0b05237bfeac9964736f6c63430005100032",
                contractCode.items[0].code
            )
            assertEquals(
                contractAccountIdentifier.pad256().toHexString(),
                contractCode.items[0].owner
            )
            assertEquals(
                "60806040526004361061001e5760003560e01c80635c60da1b14610126575b7f2230ca5690d71a74605e39bd522eea4bff3859bc627abd4ac5e473fcb8c5c3b05a6040518082815260200191505060405180910390a16000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff165a34600036604051808383808284378083019250505092505050600060405180830381858888f193505050503d80600081146100e5576040519150601f19603f3d011682016040523d82523d6000602084013e6100ea565b606091505b5050507f2230ca5690d71a74605e39bd522eea4bff3859bc627abd4ac5e473fcb8c5c3b05a6040518082815260200191505060405180910390a1005b34801561013257600080fd5b5061013b61017d565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a72315820a640f191ec583fbf9eec25b23042882a593697e120f7cea5230f7784081c042364736f6c63430005100032",
                contractCode.items[1].code
            )
            assertEquals(
                contractAccountIdentifier.pad256().toHexString(),
                contractCode.items[1].owner
            )
            assertEquals(contractAccountIdentifier.pad256().toHexString(), contractCode.items[1].address)
            contractCode.items[0].address
        } else "address_not_found"

        // and given
        val (senderAccountName, senderAccountPrivateKey, senderEthAccount) = setupTransactions.seedWithEvmBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        // and when
        val callTransaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("4630C0", 16),
            BigInteger.valueOf(1),
            "0x",
            contractAccountIdentifier.toHexString()
        )

        val callTransactionResponse = faultTolerant {
            rawAction.pushTransaction(
                senderAccountName,
                callTransaction.sign(senderEthAccount).signedTransaction.toHexString(),
                senderAccountIdentifier.toHexString(),
                TransactionContext(
                    senderAccountName,
                    senderAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet()
        }
        
        // and then
        val states = getAccountState.getAll(contractAccountIdentifier.pad256().toHexString()).blockingGet()
        if (states !is GetAccountState.Record.Multiple) fail("no account states") else {
            val items = states.items
            assertEquals(1, items.size)
            assertEquals(items.first().accountIdentifier, contractAccountIdentifier.pad256().toHexString())
            assertEquals(items.first().value, childAddress)
        }

        assertEquals(202, callTransactionResponse.statusCode)

        callTransactionResponse.assertConsoleString(
            "LOG(topics=[2230ca5690d71a74605e39bd522eea4bff3859bc627abd4ac5e473fcb8c5c3b0], data=0000000000000000000000000000000000000000000000000000000000463093)"
        )

        callTransactionResponse.assertConsoleString(
            "LOG(topics=[2230ca5690d71a74605e39bd522eea4bff3859bc627abd4ac5e473fcb8c5c3b0], data=00000000000000000000000000000000000000000000000000000000000117e6)"
        )
    }
}
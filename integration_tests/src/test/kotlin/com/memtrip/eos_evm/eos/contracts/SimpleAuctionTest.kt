package com.memtrip.eos_evm.eos.contracts

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.*
import com.memtrip.eos_evm.eos.actions.raw.RawAction
import com.memtrip.eos_evm.eos.state.GetAccountState
import com.memtrip.eos_evm.eos.state.GetCode
import com.memtrip.eos_evm.ethereum.EthereumTransaction
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert
import org.junit.Assert.assertEquals
import org.junit.Test
import java.math.BigInteger
import java.util.concurrent.TimeUnit

class SimpleAuctionTest {

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
    fun `The ballot contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(17000)
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a00", 16),
            BigInteger.valueOf(0),
            "0x608060405234801561001057600080fd5b506040516108583803806108588339818101604052604081101561003357600080fd5b810190808051906020019092919080519060200190929190505050806000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555081420160018190555050506107b0806100a86000396000f3fe6080604052600436106100705760003560e01c80633ccfd60b1161004e5780633ccfd60b146100ed5780634b449cba1461011c57806391f9015714610147578063d57bde791461019e57610070565b80631998aeef146100755780632a24f46c1461007f57806338af3eed14610096575b600080fd5b61007d6101c9565b005b34801561008b57600080fd5b506100946103e9565b005b3480156100a257600080fd5b506100ab6105dd565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b3480156100f957600080fd5b50610102610602565b604051808215151515815260200191505060405180910390f35b34801561012857600080fd5b50610131610726565b6040518082815260200191505060405180910390f35b34801561015357600080fd5b5061015c61072c565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b3480156101aa57600080fd5b506101b3610752565b6040518082815260200191505060405180910390f35b600154421115610241576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260168152602001807f41756374696f6e20616c726561647920656e6465642e0000000000000000000081525060200191505060405180910390fd5b60035434116102b8576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252601e8152602001807f546865726520616c7265616479206973206120686967686572206269642e000081525060200191505060405180910390fd5b6000600354146103345760035460046000600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020600082825401925050819055505b33600260006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff160217905550346003819055507ff4757a49b326036464bec6fe419a4ae38c8a02ce3e68bf0809674f6aab8ad3003334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a1565b600154421015610461576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260168152602001807f41756374696f6e206e6f742079657420656e6465642e0000000000000000000081525060200191505060405180910390fd5b600560009054906101000a900460ff16156104c7576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260238152602001806107596023913960400191505060405180910390fd5b6001600560006101000a81548160ff0219169083151502179055507fdaec4582d5d9595688c8c98545fdd1c696d41c6aeaeb636737e84ed2f5c00eda600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff16600354604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a16000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff166108fc6003549081150290604051600060405180830381858888f193505050501580156105da573d6000803e3d6000fd5b50565b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b600080600460003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020549050600081111561071d576000600460003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020819055503373ffffffffffffffffffffffffffffffffffffffff166108fc829081150290604051600060405180830381858888f1935050505061071c5780600460003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020819055506000915050610723565b5b60019150505b90565b60015481565b600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b6003548156fe61756374696f6e456e642068617320616c7265616479206265656e2063616c6c65642ea265627a7a723158208a1464e347522f3568b7c66c9b4d4f99db6d8f34b47beda0b103254d74fa629c64736f6c63430005100032"
        )

        val createContractResponse = faultTolerant {
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
        assertEquals(createContractResponse.statusCode, 202)
    }
}
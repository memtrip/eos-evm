package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.misc.FactoryContract
import com.memtrip.eos_evm.eos.faultTolerant
import com.memtrip.eos_evm.eos.state.GetAccountState
import com.memtrip.eos_evm.eos.evm.GetCode
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Test
import java.math.BigInteger
import java.util.concurrent.TimeUnit

class FactoryContractTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val getCode = GetCode(chainApi)

    private val getAccountState = GetAccountState(chainApi)

    @Test
    fun `The Factory contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = FactoryContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContract = contract.createContract().blockingGet()

        // then
        assertEquals(202, createContract.statusCode)
        assertEquals(1, createContract.code.size)
        assertEquals(
            "608060405234801561001057600080fd5b50600436106100365760003560e01c80636ea9bfc51461003b578063c6dad082146100f3575b600080fd5b6100f16004803603602081101561005157600080fd5b810190808035906020019064010000000081111561006e57600080fd5b82018360208201111561008057600080fd5b803590602001918460208302840111640100000000831117156100a257600080fd5b919080806020026020016040519081016040528093929190818152602001838360200280828437600081840152601f19601f82011690508083019250505050505050919291929050505061013d565b005b6100fb6101ad565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6040518060200160405280828152506000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060008201518160000190805190602001906101a69291906102cb565b5090505050565b6000806040516101bc90610318565b604051809103906000f0801580156101d8573d6000803e3d6000fd5b5090508073ffffffffffffffffffffffffffffffffffffffff1663d88b06db6000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000206000016040518263ffffffff1660e01b81526004018080602001828103825283818154815260200191508054801561028c57602002820191906000526020600020905b815481526020019060010190808311610278575b505092505050600060405180830381600087803b1580156102ac57600080fd5b505af11580156102c0573d6000803e3d6000fd5b505050508091505090565b828054828255906000526020600020908101928215610307579160200282015b828111156103065782518255916020019190600101906102eb565b5b5090506103149190610325565b5090565b6102378061034b83390190565b61034791905b8082111561034357600081600090555060010161032b565b5090565b9056fe608060405234801561001057600080fd5b50610217806100206000396000f3fe608060405234801561001057600080fd5b50600436106100365760003560e01c806345f0a44f1461003b578063d88b06db1461007d575b600080fd5b6100676004803603602081101561005157600080fd5b8101908080359060200190929190505050610135565b6040518082815260200191505060405180910390f35b6101336004803603602081101561009357600080fd5b81019080803590602001906401000000008111156100b057600080fd5b8201836020820111156100c257600080fd5b803590602001918460208302840111640100000000831117156100e457600080fd5b919080806020026020016040519081016040528093929190818152602001838360200280828437600081840152601f19601f820116905080830192505050505050509192919290505050610156565b005b6000818154811061014257fe5b906000526020600020016000915090505481565b806000908051906020019061016c929190610170565b5050565b8280548282559060005260206000209081019282156101ac579160200282015b828111156101ab578251825591602001919060010190610190565b5b5090506101b991906101bd565b5090565b6101df91905b808211156101db5760008160009055506001016101c3565b5090565b9056fea265627a7a72315820a7fb0132e94897221eb0044f6445dde8d78885f7c36a05cc01368d35c95ff26064736f6c63430005100032a265627a7a72315820b6937d27c0b58e786b37eb17f047c649f7560ce3f2122910751fb718711ea7b064736f6c63430005100032",
            createContract.code[0].code
        )
        assertEquals("1.0", createContract.code[0].nonce)
    }

    @Test
    fun `Create a new instance of child using the Factory contract`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(17000)
        val contract = FactoryContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContract = contract.createContract().blockingGet()
        assertEquals(202, createContract.statusCode)

        // when
        val setResponse = faultTolerant {
            contract.set(
                listOf(BigInteger.valueOf(100), BigInteger.valueOf(150)),
                EvmSender(
                    2,
                    newEthAccount,
                    newAccountName,
                    newAccountPrivateKey,
                    contract.ownerAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // then
        assertEquals(setResponse.statusCode, 202)

        // and when
        val makeResponse = faultTolerant {
            contract.make(
                EvmSender(
                    3,
                    newEthAccount,
                    newAccountName,
                    newAccountPrivateKey,
                    contract.ownerAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // and then
        assertEquals(makeResponse.statusCode, 202)
    }
}
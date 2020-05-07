package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.assertConsoleString
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.misc.PayableFactoryContract
import com.memtrip.eos_evm.eos.faultTolerant
import com.memtrip.eos_evm.eos.state.GetAccount
import com.memtrip.eos_evm.eos.state.GetCode
import com.memtrip.eos_evm.ethereum.EthAsset
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Assert.fail
import org.junit.Test
import java.util.concurrent.TimeUnit

class PayableFactoryContractTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val getCode = GetCode(chainApi)

    private val getAccount = GetAccount(chainApi)

    @Test
    fun `Create the PayableFactory contract`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val contract = PayableFactoryContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val getCodeResult = getCode.getAll(
            contract.accountIdentifier.pad256().toHexString()
        ).blockingGet()

        // then
        if (getCodeResult !is GetCode.Record.Multiple) fail("code record not found") else {
            assertEquals(1, getCodeResult.items.size)
            assertEquals(
                "6080604052600436106100295760003560e01c8063516517ab1461002e5780635aead1c51461007d575b600080fd5b34801561003a57600080fd5b506100676004803603602081101561005157600080fd5b810190808035906020019092919050505061009b565b6040518082815260200191505060405180910390f35b610085610154565b6040518082815260200191505060405180910390f35b600080826040516100ab9061020b565b6040518091039082f0801580156100c6573d6000803e3d6000fd5b50905090508073ffffffffffffffffffffffffffffffffffffffff1663b69ef8a86040518163ffffffff1660e01b815260040160206040518083038186803b15801561011157600080fd5b505afa158015610125573d6000803e3d6000fd5b505050506040513d602081101561013b57600080fd5b8101908080519060200190929190505050915050919050565b600080346040516101649061020b565b6040518091039082f08015801561017f573d6000803e3d6000fd5b50905090508073ffffffffffffffffffffffffffffffffffffffff1663b69ef8a86040518163ffffffff1660e01b815260040160206040518083038186803b1580156101ca57600080fd5b505afa1580156101de573d6000803e3d6000fd5b505050506040513d60208110156101f457600080fd5b810190808051906020019092919050505091505090565b6101c4806102198339019056fe608060405266038d7ea4c6800034101561001857600080fd5b346000819055506101968061002e6000396000f3fe608060405234801561001057600080fd5b50600436106100415760003560e01c806340c4d94114610046578063a9059cbb14610090578063b69ef8a8146100de575b600080fd5b61004e6100fc565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6100dc600480360360408110156100a657600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190505050610104565b005b6100e6610159565b6040518082815260200191505060405180910390f35b600030905090565b80600054101561011057fe5b8060008082825403925050819055508173ffffffffffffffffffffffffffffffffffffffff166108fc829081150290604051600060405180830381858888f19350505050505050565b60004790509056fea265627a7a723158201f52b9f50d419b8778ecc28108e9f36e9ad38b2b1c0e5723cd2143be265268e864736f6c63430005100032a265627a7a72315820c9b8b31ec119fecdb854b246f45e37622deaedbaef6fe6facf9ad1813007433f64736f6c63430005100032",
                getCodeResult.items[0].code
            )
            assertEquals(getCodeResult.items[0].address, contract.accountIdentifier.pad256().toHexString())
        }
    }

    @Test
    fun `The PayableFactory creates a payable contract, by calling the payableMake function, and both contract endowments are payed by the sender`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val contract = PayableFactoryContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val makeResponse = faultTolerant {
            contract.payMake(EvmSender(
                2,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.contractAccountIdentifier,
                EthAsset.milliether(150)
            )).blockingGet()
        }

        // then
        assertEquals(202, makeResponse.statusCode)
        makeResponse.assertConsoleString("return[0000000000000000000000000000000000000000000000000214e8348c4f0000]")

        // and when
        val balanceAfterCreateContract = getAccount.getEvmAccount(newAccountName).blockingGet()

        // and then
        if (balanceAfterCreateContract !is GetAccount.Record.Single) fail("Failed to check balance after create contract") else {
            assertEquals("0.7000 EVM", balanceAfterCreateContract.item.balance.toString())
        }

        // and when
        val getCodeAfterMakeResult = getCode.getAll(
            contract.accountIdentifier.pad256().toHexString()
        ).blockingGet()

        if (getCodeAfterMakeResult !is GetCode.Record.Multiple) fail("code record not found") else {
            assertEquals(2, getCodeAfterMakeResult.items.size)
            assertEquals(
                "608060405234801561001057600080fd5b50600436106100415760003560e01c806340c4d94114610046578063a9059cbb14610090578063b69ef8a8146100de575b600080fd5b61004e6100fc565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6100dc600480360360408110156100a657600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190505050610104565b005b6100e6610159565b6040518082815260200191505060405180910390f35b600030905090565b80600054101561011057fe5b8060008082825403925050819055508173ffffffffffffffffffffffffffffffffffffffff166108fc829081150290604051600060405180830381858888f19350505050505050565b60004790509056fea265627a7a723158201f52b9f50d419b8778ecc28108e9f36e9ad38b2b1c0e5723cd2143be265268e864736f6c63430005100032",
                getCodeAfterMakeResult.items[1].code
            )
            assertEquals("2.0", getCodeAfterMakeResult.items[0].nonce)
            assertEquals("0.1500 EVM", getCodeAfterMakeResult.items[0].balance.toString())
            assertEquals(getCodeAfterMakeResult.items[0].address, contract.accountIdentifier.pad256().toHexString())
            assertEquals(
                "0.1500 EVM",
                getCodeAfterMakeResult.items[1].balance.toString()
            )
        }
    }

    @Test
    fun `The PayableFactory creates a payable contract, by calling the make function, and only the parent contract endowment is payed by the sender`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val contract = PayableFactoryContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val makeResponse = faultTolerant {
            contract.make(EthAsset.milliether(150), EvmSender(
                2,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.contractAccountIdentifier
            )).blockingGet()
        }

        // then
        assertEquals(202, makeResponse.statusCode)
        makeResponse.assertConsoleString("return[0000000000000000000000000000000000000000000000000214e8348c4f0000]")

        // and when
        val balanceAfterCreateContract = getAccount.getEvmAccount(newAccountName).blockingGet()

        // and then
        if (balanceAfterCreateContract !is GetAccount.Record.Single) fail("Failed to check balance after create contract") else {
            assertEquals("0.8500 EVM", balanceAfterCreateContract.item.balance.toString())
        }

        // and when
        val getCodeAfterMakeResult = getCode.getAll(
            contract.accountIdentifier.pad256().toHexString()
        ).blockingGet()

        if (getCodeAfterMakeResult !is GetCode.Record.Multiple) fail("code record not found") else {
            assertEquals(2, getCodeAfterMakeResult.items.size)
            assertEquals(
                "608060405234801561001057600080fd5b50600436106100415760003560e01c806340c4d94114610046578063a9059cbb14610090578063b69ef8a8146100de575b600080fd5b61004e6100fc565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6100dc600480360360408110156100a657600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190505050610104565b005b6100e6610159565b6040518082815260200191505060405180910390f35b600030905090565b80600054101561011057fe5b8060008082825403925050819055508173ffffffffffffffffffffffffffffffffffffffff166108fc829081150290604051600060405180830381858888f19350505050505050565b60004790509056fea265627a7a723158201f52b9f50d419b8778ecc28108e9f36e9ad38b2b1c0e5723cd2143be265268e864736f6c63430005100032",
                getCodeAfterMakeResult.items[1].code
            )
            assertEquals("2.0", getCodeAfterMakeResult.items[0].nonce)
            assertEquals("0.0000 EVM", getCodeAfterMakeResult.items[0].balance.toString())
            assertEquals(getCodeAfterMakeResult.items[0].address, contract.accountIdentifier.pad256().toHexString())
            assertEquals(
                "0.1500 EVM",
                getCodeAfterMakeResult.items[1].balance.toString()
            )
        }
    }
}
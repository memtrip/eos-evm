package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.misc.RemoveFromArrayContract
import com.memtrip.eos_evm.eos.faultTolerant
import com.memtrip.eos_evm.eos.state.GetAccountState
import com.memtrip.eos_evm.eos.state.GetCode
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert
import org.junit.Assert.assertEquals
import org.junit.Test
import java.util.concurrent.TimeUnit

class RemoveFromArrayContractTest {
    
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
    fun `The RemoveFromArray contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = RemoveFromArrayContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContractResponse = faultTolerant {
            contract.createContract().blockingGet()
        }

        // then
        assertEquals(202, createContractResponse.statusCode)

        // and when
        val getCodeResult = getCode.getAll(
            contract.accountIdentifier.pad256().toHexString()
        ).blockingGet()

        if (getCodeResult !is GetCode.Record.Multiple) Assert.fail("code record not found") else {
            assertEquals(1, getCodeResult.items.size)
            assertEquals(
                "608060405234801561001057600080fd5b50600436106100365760003560e01c80635e383d211461003b578063f8a8fd6d1461007d575b600080fd5b6100676004803603602081101561005157600080fd5b81019080803590602001909291905050506100dc565b6040518082815260200191505060405180910390f35b6100856100fd565b6040518080602001828103825283818151815260200191508051906020019060200280838360005b838110156100c85780820151818401526020810190506100ad565b505050509050019250505060405180910390f35b600081815481106100e957fe5b906000526020600020016000915090505481565b60606000600a90806001815401808255809150509060018203906000526020600020016000909192909190915055506000601490806001815401808255809150509060018203906000526020600020016000909192909190915055506000601e90806001815401808255809150509060018203906000526020600020016000909192909190915055506000602890806001815401808255809150509060018203906000526020600020016000909192909190915055506000603290806001815401808255809150509060018203906000526020600020016000909192909190915055506101ea601e6101f7565b6101f2610211565b905090565b600061020282610269565b905061020d816102a5565b5050565b6060600080548060200260200160405190810160405280929190818152602001828054801561025f57602002820191906000526020600020905b81548152602001906001019080831161024b575b5050505050905090565b600080600090505b826000828154811061027f57fe5b90600052602060002001541461029c578080600101915050610271565b80915050919050565b5b6001600080549050038110156102f957600060018201815481106102c657fe5b9060005260206000200154600082815481106102de57fe5b906000526020600020018190555080806001019150506102a6565b600080548091906001900361030e9190610312565b5050565b81548183558181111561033957818360005260206000209182019101610338919061033e565b5b505050565b61036091905b8082111561035c576000816000905550600101610344565b5090565b9056fea265627a7a72315820d358222b69a76aaa7298e2af599ef28d215dd82793b3f12f692faa12ff13774064736f6c63430005100032",
                getCodeResult.items[0].code
            )
            assertEquals(getCodeResult.items[0].address, contract.accountIdentifier.pad256().toHexString())
        }
    }

    @Test
    fun `Call the test method`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(17000)
        val contract = RemoveFromArrayContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.test(EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)

        // and when
        val accountState = getAccountState.getAll(contract.accountIdentifier.pad256().toHexString()).blockingGet()

        // and then
        if (accountState !is GetAccountState.Record.Multiple) Assert.fail("no state saved") else {
            assertEquals(6, accountState.items.size)
            assertEquals("0000000000000000000000000000000000000000000000000000000000000004", accountState.items[0].value) // array size 4
            assertEquals("000000000000000000000000000000000000000000000000000000000000000a", accountState.items[1].value) // 10
            assertEquals("0000000000000000000000000000000000000000000000000000000000000014", accountState.items[2].value) // 20
            assertEquals("0000000000000000000000000000000000000000000000000000000000000028", accountState.items[3].value) // 30
            assertEquals("0000000000000000000000000000000000000000000000000000000000000032", accountState.items[4].value) // 40
            assertEquals("0000000000000000000000000000000000000000000000000000000000000000", accountState.items[5].value) // cleared value
        }
    }
}
package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.assertConsoleString
import com.memtrip.eos_evm.eos.AccountIdentifier
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.misc.ArrayMessageArgsContract
import com.memtrip.eos_evm.eos.state.GetAccountState
import com.memtrip.eos_evm.eos.evm.GetCode
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Assert.fail
import org.junit.Test
import java.util.concurrent.TimeUnit

class ArrayMessageArgsContractTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val getAccountState = GetAccountState(chainApi)

    @Test
    fun `The ArrayMessageArgs contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()

        val contract = ArrayMessageArgsContract(
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
            "608060405234801561001057600080fd5b506004361061002b5760003560e01c8063cb85227114610030575b600080fd5b61003861004e565b6040518082815260200191505060405180910390f35b600080600a908060018154018082558091505090600182039060005260206000200160009091929091909150555060008060405161008b90610185565b808060200182810382528381815481526020019150805480156100cd57602002820191906000526020600020905b8154815260200190600101908083116100b9575b505092505050604051809103906000f0801580156100ef573d6000803e3d6000fd5b5090508073ffffffffffffffffffffffffffffffffffffffff1663d39fa23360006040518263ffffffff1660e01b81526004018082815260200191505060206040518083038186803b15801561014457600080fd5b505afa158015610158573d6000803e3d6000fd5b505050506040513d602081101561016e57600080fd5b810190808051906020019092919050505091505090565b6102c0806101938339019056fe608060405234801561001057600080fd5b506040516102c03803806102c08339818101604052602081101561003357600080fd5b810190808051604051939291908464010000000082111561005357600080fd5b8382019150602082018581111561006957600080fd5b825186602082028301116401000000008211171561008657600080fd5b8083526020830192505050908051906020019060200280838360005b838110156100bd5780820151818401526020810190506100a2565b5050505090500160405250505060008090505b81518110156101255760008282815181106100e757fe5b6020026020010151908060018154018082558091505090600182039060005260206000200160009091929091909150555080806001019150506100d0565b505061018a806101366000396000f3fe608060405234801561001057600080fd5b50600436106100365760003560e01c80636d4ce63c1461003b578063d39fa2331461009a575b600080fd5b6100436100dc565b6040518080602001828103825283818151815260200191508051906020019060200280838360005b8381101561008657808201518184015260208101905061006b565b505050509050019250505060405180910390f35b6100c6600480360360208110156100b057600080fd5b8101908080359060200190929190505050610134565b6040518082815260200191505060405180910390f35b6060600080548060200260200160405190810160405280929190818152602001828054801561012a57602002820191906000526020600020905b815481526020019060010190808311610116575b5050505050905090565b6000818154811061014157fe5b90600052602060002001600091509050548156fea265627a7a7231582087b043ad63c6fe318034dab154666fec0eba7763b28451cf1cec4d1dbc1abebb64736f6c63430005100032a265627a7a7231582062acf3bff1ff54635b700f4462d602978b0847644f164d59c412a81580b938ca64736f6c63430005100032",
            createContract.code[0].code
        )

        // and given
        val (senderAccountName, senderPrivateKey, senderEthAccount) = setupTransactions.seedWithEvmBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        // and when
        val response = contract.makeA(EvmSender(
            1,
            senderEthAccount,
            senderAccountName,
            senderPrivateKey,
            senderAccountIdentifier.toHexString()
        )).blockingGet()

        // and then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[000000000000000000000000000000000000000000000000000000000000000a]")

        // and when
        val accountState = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()

        // and then
        if (accountState !is GetAccountState.Record.Multiple) fail("no state saved") else {
            assertEquals(2, accountState.items.size)
            assertEquals("0000000000000000000000000000000000000000000000000000000000000001", accountState.items[0].value)
            assertEquals("000000000000000000000000000000000000000000000000000000000000000a", accountState.items[1].value)
        }
    }
}
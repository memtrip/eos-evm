package com.memtrip.evm.eos.contracts.ethereumorg

import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.eos.AccountIdentifier
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.contracts.ethereumorg.TokenMinimalContract
import com.memtrip.evm.eos.state.GetAccountState
import com.memtrip.evm.ethereum.EthAsset
import com.memtrip.evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Assert.fail
import org.junit.Test
import java.util.concurrent.TimeUnit

class TokenMinimalContractTest {

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
    fun `The TokenMinimal contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance(30000)

        val contract = TokenMinimalContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContract = contract.createContract(EthAsset.eth(1)).blockingGet()

        // then
        assertEquals(202, createContract.statusCode)

        // and when
        assertEquals(1, createContract.code.size)
        assertEquals(
            "608060405234801561001057600080fd5b50600436106100365760003560e01c806370a082311461003b578063a9059cbb14610093575b600080fd5b61007d6004803603602081101561005157600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff1690602001909291905050506100f9565b6040518082815260200191505060405180910390f35b6100df600480360360408110156100a957600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190505050610111565b604051808215151515815260200191505060405180910390f35b60006020528060005260406000206000915090505481565b6000816000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002054101561015e57600080fd5b6000808473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002054826000808673ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020540110156101e957600080fd5b816000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060008282540392505081905550816000808573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060008282540192505081905550600190509291505056fea265627a7a72315820fce249dd8198d97ea105b4a4ab403c0ec5de9f63b22316cb84e47b382ac7a6ee64736f6c63430005100032",
            createContract.code[0].code
        )
    }

    @Test
    fun `The owner of the contract can send tokens to another address`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance(30000)
        val contract = TokenMinimalContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract(EthAsset.eth(1)).blockingGet()
        assertEquals(202, createContract.statusCode)

        val (secondAccountName, secondAccountPrivateKey, secondEthAccount) = setupTransactions.seedWithEvmBalance(30000)
        val senderAccountIdentifier = AccountIdentifier.create(secondAccountName, secondEthAccount.address)

        val accountStateBeforeTransfer = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()
        if (accountStateBeforeTransfer is GetAccountState.Record.Multiple) {
            assertEquals(1, accountStateBeforeTransfer.items.size)
            assertEquals("0000000000000000000000000000000000000000000000000de0b6b3a7640000", accountStateBeforeTransfer.items.first().value)
        } else fail("no account state")

        // when
        val transferResponse = contract.transfer(
            senderAccountIdentifier.toHexString(),
            EthAsset.milliether(150), EvmSender(
                2,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.ownerAccountIdentifier.toHexString()
            )
        ).blockingGet()

        assertEquals(202, transferResponse.statusCode)

        // then
        val accountStateAfterTransfer = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()
        if (accountStateAfterTransfer is GetAccountState.Record.Multiple) {
            assertEquals(2, accountStateAfterTransfer.items.size)
            assertEquals(
                "0000000000000000000000000000000000000000000000000bcbce7f1b150000",
                    accountStateAfterTransfer.items.first().value
            )
            assertEquals(
                "0000000000000000000000000000000000000000000000000214e8348c4f0000",
                accountStateAfterTransfer.items[1].value
            )
        } else fail("no account state")
    }
}
package com.memtrip.evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.assertConsoleString
import com.memtrip.evm.eos.AccountIdentifier
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.contracts.misc.BasicTokenContract
import com.memtrip.evm.eos.faultTolerant
import com.memtrip.evm.eos.state.GetAccountState
import com.memtrip.evm.eos.evm.GetCode
import com.memtrip.evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert
import org.junit.Assert.assertEquals
import org.junit.Test
import java.util.concurrent.TimeUnit

class BasicTokenContractTest {

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
    fun `The BasicToken contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = BasicTokenContract(
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
            "608060405234801561001057600080fd5b50600436106100365760003560e01c806370a082311461003b578063a9059cbb14610093575b600080fd5b61007d6004803603602081101561005157600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff1690602001909291905050506100e1565b6040518082815260200191505060405180910390f35b6100df600480360360408110156100a957600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190505050610129565b005b60008060008373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020549050919050565b806000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060008282540392505081905550806000808473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060008282540192505081905550505056fea265627a7a723158206cd6bdb9d9779d30a4f5bab15baadea00a6ca7a723ad04549b29d5477684678f64736f6c63430005100032",
            createContract.code[0].code
        )
        assertEquals("1.0", createContract.code[0].nonce)

        // and when
        val accountState = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()

        // and then
        if (accountState !is GetAccountState.Record.Multiple) Assert.fail("no state saved") else {
            assertEquals(1, accountState.items.size)
            assertEquals("0000000000000000000000000000000000000000000000000000000000e4e1c0", accountState.items.first().value)
        }
    }

    @Test
    fun `Transfer basic tokens from the contract owner to AddressX`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val contract = BasicTokenContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract().blockingGet()
        assertEquals(202, createContract.statusCode)

        // and given
        val (senderAccountName, senderPrivateKey, senderEthAccount) = setupTransactions.seedWithSystemBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        // and when
        val transferResponse = faultTolerant {
            contract.transfer(
                senderAccountIdentifier.toHexString(),
                5000,
                EvmSender(
                    2,
                    newEthAccount,
                    newAccountName,
                    newAccountPrivateKey,
                    contract.ownerAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // and then
        assertEquals(transferResponse.statusCode, 202)

        // and when
        val balanceOfResponse = faultTolerant {
            contract.balanceOf(
                senderAccountIdentifier.toHexString(),
                EvmSender(
                    1,
                    senderEthAccount,
                    senderAccountName,
                    senderPrivateKey,
                    senderAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // and then
        assertEquals(balanceOfResponse.statusCode, 202)
        balanceOfResponse.assertConsoleString("return[0000000000000000000000000000000000000000000000000000000000001388]")
    }
}
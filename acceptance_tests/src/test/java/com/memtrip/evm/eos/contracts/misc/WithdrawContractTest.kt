package com.memtrip.evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.GetCode
import com.memtrip.evm.eos.evm.contracts.misc.WithdrawContract
import com.memtrip.evm.eos.faultTolerant
import com.memtrip.evm.eos.state.GetAccount
import com.memtrip.evm.ethereum.EthAsset
import com.memtrip.evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Assert.fail
import org.junit.Test
import java.util.concurrent.TimeUnit

class WithdrawContractTest {

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
    fun `The Withdraw contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()

        val contract = WithdrawContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContract = contract.createContract(EthAsset.milliether(150)).blockingGet()

        // then
        assertEquals(202, createContract.statusCode)

        // and when
        assertEquals(1, createContract.code.size)
        assertEquals(
            "6080604052348015600f57600080fd5b506004361060285760003560e01c80633ccfd60b14602d575b600080fd5b60336035565b005b3373ffffffffffffffffffffffffffffffffffffffff166108fc479081150290604051600060405180830381858888f19350505050158015607a573d6000803e3d6000fd5b5056fea265627a7a7231582031cc683240cfd2891b6f741024dbe81cba9e97335b85d1a51b28fe8fc56f017764736f6c63430005100032",
            createContract.code[0].code
        )
        assertEquals(
            "0.1500 EVM",
            createContract.code[0].balance.toString()
        )
    }

    @Test
    fun `Call the withdraw method`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance(17000)
        val contract = WithdrawContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContract = contract.createContract(EthAsset.milliether(150)).blockingGet()
        assertEquals(202, createContract.statusCode)

        val accountBeforeWithdraw = getAccount.getAccountIdentifier(contract.ownerAccountIdentifierString32).blockingGet()
        if (accountBeforeWithdraw is GetAccount.Record.Single) {
            assertEquals("0.8500 EVM", accountBeforeWithdraw.item.balance.toString())
        } else fail("account not found")

        // when
        val response = faultTolerant {
            contract.withdraw(
                EvmSender(
                    2,
                    newEthAccount,
                    newAccountName,
                    newAccountPrivateKey,
                    contract.ownerAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        assertEquals(202, response.statusCode)

        // then
        val parentContractBalance = getCode.getAllByOwner(contract.ownerAccountIdentifierString32).blockingGet()
        if (parentContractBalance is GetCode.Record.Multiple) {
            assertEquals("0.0000 EVM", parentContractBalance.items.first().balance.toString())
        } else fail("parent contract not found")

        val accountAfterWithdraw = getAccount.getAccountIdentifier(contract.ownerAccountIdentifierString32).blockingGet()
        if (accountAfterWithdraw is GetAccount.Record.Single) {
            assertEquals("1.0000 EVM", accountAfterWithdraw.item.balance.toString())
        } else fail("account not found")
    }
}
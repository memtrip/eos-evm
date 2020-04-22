package com.memtrip.eos_evm.eos

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.assertConsoleError
import com.memtrip.eos_evm.eos.actions.raw.RawAction
import com.memtrip.eos_evm.eos.state.GetAccount
import com.memtrip.eos_evm.eos.state.GetCode
import com.memtrip.eos_evm.ethereum.EthereumTransaction
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.*
import org.junit.Test
import java.math.BigInteger
import java.util.concurrent.TimeUnit

class EndownmentTest {

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

    private val getAccount = GetAccount(chainApi)

    @Test
    fun `The EVM account must have enough balance to fulfil the CREATE contract endowment value`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x7c601080600c6000396000f3006000355415600957005b60203560003555600052601d60036017f0600055"
        )

        val response = rawAction.pushTransaction(
            newAccountName,
            transaction.sign(newEthAccount).signedTransaction.toHexString(),
            accountIdentifier.toHexString(),
            TransactionContext(
                newAccountName,
                newAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // then
        assertEquals(response.statusCode, 500)

        response.assertConsoleError("Insufficient funds.")
    }

    @Test
    fun `The EVM account transfers the endowment value to the virtual code address`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithBalance()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val transferResult = faultTolerant {
            setupTransactions.transfer(
                "eos.evm",
                "0.5000 ${Config.SYMBOL}",
                "evm funds",
                newAccountName,
                newAccountPrivateKey,
                "eosio.token"
            ).blockingGet()
        }

        // then
        assertEquals(202, transferResult.statusCode)

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x7c601080600c6000396000f3006000355415600957005b60203560003555600052601d60036017f0600055"
        )

        val response = rawAction.pushTransaction(
            newAccountName,
            transaction.sign(newEthAccount).signedTransaction.toHexString(),
            accountIdentifier.toHexString(),
            TransactionContext(
                newAccountName,
                newAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        // then
        assertEquals(response.statusCode, 202)

        // and when
        val getCodeResult = getCode.getValue(
            accountIdentifier.pad256().toHexString()
        ).blockingGet()

        // and then
        if (getCodeResult !is GetCode.Record.Value) fail("code record not found") else {
            assertEquals(
                "6000355415600957005b602035600035",
                getCodeResult.item.code
            )
            assertEquals(
                accountIdentifier.pad256().toHexString(),
                getCodeResult.item.owner
            )
            assertEquals(
                "0.0023 EVM",
                getCodeResult.item.balance
            )
        }

        // and when
        val getAccountResult = getAccount.getEvmAccount(newAccountName).blockingGet()

        // and then
        if (getAccountResult !is GetAccount.Record.Single) fail("account not found") else {
            assertEquals(
                "0.4977 EVM",
                getAccountResult.item.balance
            )
        }
    }
}
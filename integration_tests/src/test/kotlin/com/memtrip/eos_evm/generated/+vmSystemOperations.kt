import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.*
import com.memtrip.eos_evm.eos.account_state.GetAccountState
import com.memtrip.eos_evm.eos.raw.RawAction
import com.memtrip.eos_evm.ethereum.EthAccount
import com.memtrip.eos_evm.ethereum.EthereumTransaction
import com.memtrip.eos_evm.ethereum.toHexString
import com.memtrip.eos_evm.ethereum.toHexBytes
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.AccountStateKey
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Test
import java.math.BigInteger
import java.util.concurrent.TimeUnit
import com.memtrip.eos_evm.eos.TestTransaction
import com.memtrip.eos_evm.eos.faultTolerant

//
// 12.04.2020
// Auto generated based off the Ethereum tests found here:
// https://github.com/ethereum/tests/blob/develop/VMTests/
//
class vmSystemOperations {
    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val rawAction = RawAction(chainApi)

    private val getAccountState = GetAccountState(chainApi)

    @Test
    fun `return0______1cd2b9480f1f5bdd82e8026b6342008ef84d318c3f9f173eae7d09e50eaf26b3`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("17", 16),
                "0x603760005360005160005560016000f3"
            )
            val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()

            // then
            val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)
            TestTransaction(newAccountName, accountIdentifier, rawAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                TransactionContext(
                    newAccountName,
                    newAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet())
        }

        assertEquals(202, response.statusCode)

        // and then
        // 0x00
        val value_0x00 = getAccountState.getValue(
            accountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x00)
        ).blockingGet()
        assertEquals("3700000000000000000000000000000000000000000000000000000000000000", value_0x00)

    }
    @Test
    fun `return1______5cd716a8e8d460b10e0dc1b3d5b6394f0c388e0e36246bf124478b0cb86a1f76`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("17", 16),
                "0x603760005360005160005560026000f3"
            )
            val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()

            // then
            val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)
            TestTransaction(newAccountName, accountIdentifier, rawAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                TransactionContext(
                    newAccountName,
                    newAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet())
        }

        assertEquals(202, response.statusCode)

        // and then
        // 0x00
        val value_0x00 = getAccountState.getValue(
            accountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x00)
        ).blockingGet()
        assertEquals("3700000000000000000000000000000000000000000000000000000000000000", value_0x00)

    }
    @Test
    fun `suicideSendEtherToMe______0cf005812e9c99dc87bdd8463a9849a0164a9e02b3d09eaab228267d6c8c703e`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("03e8", 16),
                BigInteger("0186a0", 16),
                "0x30ff"
            )
            val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()

            // then
            val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)
            TestTransaction(newAccountName, accountIdentifier, rawAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                TransactionContext(
                    newAccountName,
                    newAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet())
        }

        assertEquals(202, response.statusCode)

        // and then
    }
    @Test
    fun `TestNameRegistrator______7e0e4bcbcbe8bcaf9a8535e65d4c6665db752910953b5eafc63da8f7cdff20b7`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x6000355415600957005b60203560003555"
            )
            val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()

            // then
            val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)
            TestTransaction(newAccountName, accountIdentifier, rawAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                TransactionContext(
                    newAccountName,
                    newAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet())
        }

        assertEquals(202, response.statusCode)

        // and then
        // 0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa
        val value_0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa = getAccountState.getValue(
            accountName,
            AccountStateKey.create(accountIdentifier.pad256(), "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa".toHexBytes())
        ).blockingGet()
        assertEquals("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa", value_0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa)

    }
    @Test
    fun `suicideNotExistingAccount______ba450a40efb62a9fb6e16e3bced0afde8d0b08b9c0f78979f35fc45b9de72816`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("03e8", 16),
                BigInteger("0186a0", 16),
                "0x73aa1722f3947def4cf144679da39c4c32bdc35681ff"
            )
            val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()

            // then
            val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)
            TestTransaction(newAccountName, accountIdentifier, rawAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                TransactionContext(
                    newAccountName,
                    newAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet())
        }

        assertEquals(202, response.statusCode)

        // and then
    }
    @Test
    fun `return2______4181cbf262c1dc2cdc186e007ec6c13466bd031b190b07874b1177a00717deeb`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("17", 16),
                "0x603760005360005160005560216000f3"
            )
            val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()

            // then
            val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)
            TestTransaction(newAccountName, accountIdentifier, rawAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                TransactionContext(
                    newAccountName,
                    newAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet())
        }

        assertEquals(202, response.statusCode)

        // and then
        // 0x00
        val value_0x00 = getAccountState.getValue(
            accountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x00)
        ).blockingGet()
        assertEquals("3700000000000000000000000000000000000000000000000000000000000000", value_0x00)

    }
    @Test
    fun `suicide0______56c8766e8a1687dfe807b1e8f2d0454267f432c7e3035ff5fa9c27a2d594739d`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("03e8", 16),
                BigInteger("0186a0", 16),
                "0x33ff"
            )
            val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()

            // then
            val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)
            TestTransaction(newAccountName, accountIdentifier, rawAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                TransactionContext(
                    newAccountName,
                    newAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet())
        }

        assertEquals(202, response.statusCode)

        // and then
    }
}

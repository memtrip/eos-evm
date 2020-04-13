import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.*
import com.memtrip.eos_evm.eos.account_state.GetAccountState
import com.memtrip.eos_evm.eos.raw.RawAction
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
// 13.04.2020
// Auto generated based off the Ethereum tests found here:
// https://github.com/ethereum/tests/blob/develop/VMTests/
//
class vmRandomTest {
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
    fun `201503110206PYTHON______ad34ff6291ab537633ab5e7163537b24617cc4edb2f45eac65bed9d2c009cfc3`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("2710", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x4045404145454441343987ff3735043055"
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
    fun `201503111844PYTHON______a8049871a173837bf8fbfab3352baf9bb9e33d0ffa2bd20ba6246a70d9c1b165`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("2710", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x65424555"
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
    fun `201503112218PYTHON______6fc205d30fd7493b6e120e18c91e1e41f6fe334b94abadbac37d2817066ebccb`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("2710", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x4041"
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
    fun `201503110219PYTHON______93dd23cbf213b07ac96a1fdfc826f41475452fea6da2e4f8d3f5d206e9a1adb9`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("2710", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x4040459143404144809759886d608f"
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
    fun `201503102320PYTHON______38aa9ba7f7836987852734619b0192d42434bd7106da17663d5fc85d81a1e6cf`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("2710", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x434342444244454597"
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
    fun `201503110346PYTHON_PUSH24______953cb389f468c0d45697c57895679d7675ab43de963ad34a0ee547b8d27d10c8`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("2710", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x7745414245403745f31387900a8d55"
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

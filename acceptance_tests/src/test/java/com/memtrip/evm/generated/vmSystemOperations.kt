import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.AccountIdentifier
import com.memtrip.evm.eos.state.GetAccountState
import com.memtrip.evm.eos.actions.execute.ExecuteAction
import com.memtrip.evm.ethereum.EthereumTransaction
import com.memtrip.evm.ethereum.toHexString
import com.memtrip.evm.ethereum.toHexBytes
import com.memtrip.evm.ethereum.pad256
import com.memtrip.evm.ethereum.AccountStateKey
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Test
import java.math.BigInteger
import java.util.concurrent.TimeUnit
import com.memtrip.evm.eos.TestTransaction
import com.memtrip.evm.eos.faultTolerant
import com.memtrip.evm.eos.transactionDefaultExpiry

//
// 11.05.2020
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

    private val executeAction = ExecuteAction(chainApi)

    private val getAccountState = GetAccountState(chainApi)

    @Test
    fun `return0______e411717bc045fc7a3d57ec536d815b121da8649c91934310e0dff29a42f0a13f`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("17", 16),
            "0xaa"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "603760005360005160005560016000f300",
                TransactionContext(
                    newAccountName,
                    newAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet()
        }

        // then
        TestTransaction(newAccountName, accountIdentifier, response)

        assertEquals(202, response.statusCode)

        // and then
        // 0x00
        val value_0x00 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x00)
        ).blockingGet()
        assertEquals("3700000000000000000000000000000000000000000000000000000000000000", value_0x00)
    }
    @Test
    fun `return1______41ac1d247e7dc68eb9783a4641fd57a5650839bb4357dcdd16d715f2378d686f`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("17", 16),
            "0xaa"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "603760005360005160005560026000f300",
                TransactionContext(
                    newAccountName,
                    newAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet()
        }

        // then
        TestTransaction(newAccountName, accountIdentifier, response)

        assertEquals(202, response.statusCode)

        // and then
        // 0x00
        val value_0x00 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x00)
        ).blockingGet()
        assertEquals("3700000000000000000000000000000000000000000000000000000000000000", value_0x00)
    }
    @Test
    fun `TestNameRegistrator______11f3a69a1428da1f0b2bee61f88237b2690aa146a09b5c97805fa643d29c5131`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffafffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "6000355415600957005b60203560003555",
                TransactionContext(
                    newAccountName,
                    newAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet()
        }

        // then
        TestTransaction(newAccountName, accountIdentifier, response)

        assertEquals(202, response.statusCode)

        // and then
        // 0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa
        val value_0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa".toHexBytes())
        ).blockingGet()
        assertEquals("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa", value_0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa)
    }
    @Test
    fun `return2______8abe5a8645b3cb674299c8acbba110d87d8090ace46a32b3e6b906df91d187fb`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("17", 16),
            "0xaa"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "603760005360005160005560216000f300",
                TransactionContext(
                    newAccountName,
                    newAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet()
        }

        // then
        TestTransaction(newAccountName, accountIdentifier, response)

        assertEquals(202, response.statusCode)

        // and then
        // 0x00
        val value_0x00 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x00)
        ).blockingGet()
        assertEquals("3700000000000000000000000000000000000000000000000000000000000000", value_0x00)
    }
}

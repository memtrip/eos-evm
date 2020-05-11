import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.AccountIdentifier
import com.memtrip.evm.eos.state.GetAccountState
import com.memtrip.evm.eos.actions.execute.ExecuteAction
import com.memtrip.evm.ethereum.EthereumTransaction
import com.memtrip.evm.ethereum.toHexString
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
class vmRandomTest {
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
    fun `201503111844PYTHON______3a9641b4e844c1cfc6d65c21da9a75f5ce8b0bc88e839a94303ea014f3ce9d4c`() {

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
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "65424555",
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
    }
    @Test
    fun `201503110346PYTHON_PUSH24______54955e29499ee091894b980295066cff056df38014183428a910e8a75aafa981`() {

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
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "7745414245403745f31387900a8d55",
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
    }
}

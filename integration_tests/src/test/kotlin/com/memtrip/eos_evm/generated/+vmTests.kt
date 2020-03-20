import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.*
import com.memtrip.eos_evm.eos.raw.RawAction
import com.memtrip.eos_evm.ethereum.EthAccount
import com.memtrip.eos_evm.ethereum.EthereumTransaction
import com.memtrip.eos_evm.ethereum.toHex
import com.memtrip.eos_evm.fixture.TestCases
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Test
import java.math.BigInteger
import java.util.concurrent.TimeUnit

//
// 20.03.2020
// Auto generated based off the Ethereum tests found here:
// https://github.com/ethereum/tests/blob/develop/VMTests/
//
class vmTests {
    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val rawAction = RawAction(chainApi)

    @Test
    fun `suicide______4622c577440f9db4b3954a1de60bf2fac55886dcb0ec4ecaf906c25bc77372e7`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("5af3107a4000", 16),
            BigInteger("0186a0", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x33ff"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            "0x$signedTransaction",
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
            TransactionContext(
                newAccountName,
                newAccountPrivateKey,
                transactionDefaultExpiry()
            )
        ).blockingGet()

        assertEquals(202, response.statusCode)

        // TODO: verify the account state table
    }

}

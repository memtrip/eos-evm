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

    private val getAccountState = GetAccountState(chainApi)

    @Test
    fun `suicide______4622c577440f9db4b3954a1de60bf2fac55886dcb0ec4ecaf906c25bc77372e7`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
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

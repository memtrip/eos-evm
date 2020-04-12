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
class vmBlockInfoTest {
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
    fun `gaslimit______f1250fd89a1c3e517ae92cc1f73865c594bfad34db20f3b3396af4efe19d3bfb`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x45600055"
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
        assertEquals("00000000000000000000000000000000000000000000000000000000000f4240", value_0x00)

    }
    @Test
    fun `number______404caf239c3e0ad4394c1417b728d10e1f68a8eee3963425d9e391f4f3ec023c`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x43600055"
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `difficulty______30c06d1988994e3f4e738e60b1e0d6b8734fb576e3b2580151251c5f058fa9c6`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x44600055"
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000100", value_0x00)

    }
    @Test
    fun `coinbase______9f5df0c263c2b48fbf48db70ec64ddf3efa5f1651ced1fedf933ee239e9c851d`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x41600055"
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
        assertEquals("0000000000000000000000002adc25665018aa1fe0e6bc666dac8fc2697ff9ba", value_0x00)

    }
    @Test
    fun `timestamp______44c8782a2b04af7092f76bfa83b1cb24e590722db220b32a52e4e249e596def4`() {

        val (accountName, accountIdentifier, response) = faultTolerant {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x42600055"
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
}

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.AccountIdentifier
import com.memtrip.evm.eos.state.GetAccountState
import com.memtrip.evm.eos.actions.execute.ExecuteAction
import com.memtrip.evm.ethereum.EthereumTransaction
import com.memtrip.evm.ethereum.toHexString
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
import com.memtrip.evm.assertConsoleError

//
// 11.05.2020
// Auto generated based off the Ethereum tests found here:
// https://github.com/ethereum/tests/blob/develop/VMTests/
//
class vmEnvironmentalInfo {
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
    fun `calldataload_BigOffset______e92194914f8eaa68524e2fbd430f8f434ac585013b8a47ed3a179130f33a5184`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x4200000000000000000000000000000000000000000000000000000000000000"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "7f42000000000000000000000000000000000000000000000000000000000000003560005500",
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
    fun `calldatacopy2______8bd27dcf56a5fc6cf1e944b4b93ab7a6d3e89a899a249a336e46c7d6d41271cd`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "6000600160003760005160005500",
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
    fun `calldatacopy2_return______68cfce0f6a821a80c32d144556d14eacab7bd2e7f56176ba64f3daa4e62484db`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60006001600037600051600055596000f300",
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
    fun `calldataload2______b87662d5ecb0ee70b88059bfce95d2dde81bc573aae982f6a835a4d4aa13ed0e`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x123456789abcdef00000000000000000000000000000000000000000000000000024"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60053560005500",
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
        assertEquals("bcdef00000000000000000000000000000000000000000000000000024000000", value_0x00)
    }
    @Test
    fun `calldatacopy_DataIndexTooHigh______9d64252755a4f9037cba23e34e5f2f0d12201f7c808f81b5726d3c832584b65b`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60ff7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa60003760005160005500",
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
    fun `calldatacopyUnderFlow______2e6145527d0c175c6a7409d38c2befafab1f84a53f2f5ea654c5682da0dfee09`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "600260013700",
                TransactionContext(
                    newAccountName,
                    newAccountPrivateKey,
                    transactionDefaultExpiry()
                )
            ).blockingGet()
        }

        // then
        TestTransaction(newAccountName, accountIdentifier, response)

        assertEquals(500, response.statusCode)
        response.assertConsoleError("stack_underflow".toUpperCase())

        // and then
    }
    @Test
    fun `calldatacopy_DataIndexTooHigh_return______b09dd546a2a371e7d8a47fd28b61955fba17b10614c42ae6e37814868350caa1`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60ff7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600037600051600055596000f300",
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
    fun `gasprice______19456c127f98922cc89869a50acef218af8b65c62e46e4d7786e3de31d907948`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "3a60005500",
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
        assertEquals("000000000000000000000000000000000000000000000000000000000000000c", value_0x00)
    }
    @Test
    fun `codecopy0______9853f1b117bb3cca0030545f0aa096c9f249d2b327e3e15916c6b73227551d86`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "6005600060003960005160005500",
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
        assertEquals("6005600060000000000000000000000000000000000000000000000000000000", value_0x00)
    }
    @Test
    fun `calldatacopyZeroMemExpansion_return______06f76845fe79e1e25af55961b3b19d90654d23179cc8e74b6ae93a1cac50a1ed`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60006000600037600051600055596000f300",
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
    fun `calldatacopy1_return______ff4a0ade893a383451dbfeec7f650cbc8b743c69a9af7dce8e35562d6f6fe4bf`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60016001600037600051600055596000f300",
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
        assertEquals("3400000000000000000000000000000000000000000000000000000000000000", value_0x00)
    }
    @Test
    fun `calldatasize2______1ad1119299f35a1ba1fddf097a4fcdbf6753c1a26439b5b9683a089667089d0f`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x230000000000000000000000000000000000000000000000000000000000000023"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "3660005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000021", value_0x00)
    }
    @Test
    fun `codecopyZeroMemExpansion______70f6e78f5f8ffaed53ec5b52d17e22424c5c110d043e59dd78349a6e176829df`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "6000600060003960005160005500",
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
    fun `calldatacopy_sec______15323dbe31a91339553ce7d5197229c685d975fb40bd35739f7397b8b779fe72`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "6005565b005b6042601f536101036000601f3760005180606014600357640badc0ffee60ff55",
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
        // 0xff
        val value_0xff = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0xff)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000badc0ffee", value_0xff)
    }
    @Test
    fun `calldatasize1______ad1349d5e6d70cf38b831de08f866ee8902618a667da450eb279c5b39fb94784`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "3660005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000021", value_0x00)
    }
    @Test
    fun `calldatacopyZeroMemExpansion______ce6a997314ad1ba5b483f764ed64699624914cccb230499752652d6b63aa301f`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "6000600060003760005160005500",
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
    fun `codecopy_DataIndexTooHigh______6a5a1aa1f2dddb2c524ed6f1e216814462dfcb91f5001c0392dcc903bd47ee3c`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60087ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa60003960005160005500",
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
    fun `codesize______65b39c55e2e41f5faf305f21e2761639a3d4eb8fe21e233e0c48d69fc6621752`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "3860005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000005", value_0x00)
    }
    @Test
    fun `calldataloadSizeTooHighPartial______2a812d43752bf76dc6cfe8efba32c0d1a3cd6c15f4646651e9cae9a1fe1bc7a3`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x123456789abcdef00000000000000000000000000000000000000000000024"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "600a3560005500",
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
        assertEquals("0000000000000000000000000000000000000000240000000000000000000000", value_0x00)
    }
    @Test
    fun `calldatacopy_DataIndexTooHigh2______164fa3d98d49e4d745f3b63bb9d093b75be9fec10da729a5b2b228ba1092958b`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60097ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa60003760005160005500",
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
    fun `calldatasize0______cfb2c972fc3666c4e23f3f8c958393431ae18ce0954b95ce9fc32ad6575f714e`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x2560"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "3660005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000002", value_0x00)
    }
    @Test
    fun `calldataloadSizeTooHigh______3b3ed1426074a870b48afb77b67c46c8c7b59f0bbe563c5ba8d29ade563049f5`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x123456789abcdef00000000000000000000000000000000000000000000000000024"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa3560005500",
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
    fun `calldatacopy0______f51dcaa74870531418fc87e57f55edd955e428ddfdd4650e41984bd544f0425f`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "6002600160003760005160005500",
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
        assertEquals("3456000000000000000000000000000000000000000000000000000000000000", value_0x00)
    }
    @Test
    fun `calldatacopy0_return______340beddeffa11c976a3185b6332be05a6e98fb258ae85e085cb432b148859db8`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60026001600037600051600055596000f300",
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
        assertEquals("3456000000000000000000000000000000000000000000000000000000000000", value_0x00)
    }
    @Test
    fun `calldataload0______4bed34e4fa23bc5d6619dfddc54ea8eee9dea401022363ad16e0b39acef239ca`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x2560"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60003560005500",
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
        assertEquals("2560000000000000000000000000000000000000000000000000000000000000", value_0x00)
    }
    @Test
    fun `calldatacopy_DataIndexTooHigh2_return______fcddba5ae383bede89e8d2a03ebf05069f5f3221ffa516faa7fa309c263e5888`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60097ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600037600051600055596000f300",
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
    fun `calldataload1______97a1ddaa3b85cbb0cf2e43c7f250e64c8f7efa0abb0e9a4abe7458b63f618537`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60013560005500",
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
        assertEquals("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23", value_0x00)
    }
    @Test
    fun `callvalue______ffc2710e200fe7f6535015c9ec15a74a7238e126942376a557aaeeaf7f9a99f3`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0a", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "3460005500",
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
        assertEquals("000000000000000000000000000000000000000000000000000000000000000a", value_0x00)
    }
    @Test
    fun `calldatacopy1______6c09d2420e8dc4d5508ec35f60140762086aad4b142f433da7f43000ea2d9366`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("174876e800", 16),
            BigInteger("0b", 16),
            "0x1234567890abcdef01234567890abcdef0"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "6001600160003760005160005500",
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
        assertEquals("3400000000000000000000000000000000000000000000000000000000000000", value_0x00)
    }
}

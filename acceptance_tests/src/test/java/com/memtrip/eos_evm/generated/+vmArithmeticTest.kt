import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.*
import com.memtrip.eos_evm.eos.state.GetAccountState
import com.memtrip.eos_evm.eos.actions.execute.ExecuteAction
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
import com.memtrip.eos_evm.eos.faultTolerantCreateAccount
import com.memtrip.eos_evm.assertConsoleError

//
// 06.05.2020
// Auto generated based off the Ethereum tests found here:
// https://github.com/ethereum/tests/blob/develop/VMTests/
//
class vmArithmeticTest {
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
    fun `mulmoddivByZero______45a69ddce4cc7f5f5e74b373204f3b5084463792224ac9513dea21ef76e28a34`() {

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
               "6000600160050960005500",
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
    fun `sub0______194b427bf35e0d2d21fa3c005dcc229f9f5427a5d8b2e943b48ff93e975310f7`() {

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
               "600160170360005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000016", value_0x00)

    }
    @Test
    fun `expPowerOf256_29______bf5e73521a425d8c265cbc21a65a11cb7c6df1d1cd746ec5dae939e52cbe14c1`() {

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
               "601d6101000a600055601d60ff0a600155601d6101010a60025500",
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
        assertEquals("0000010000000000000000000000000000000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("000000e48814fe44fc1a8f78642d946d7c879b39a055b6988e438647446a1cff", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000011ea4a49e3a9ee435d23f98a8826a875a9ae54cb3090d5c3fd547961d01", value_0x02)

    }
    @Test
    fun `signextend_BigByteBigByte______e8371c4c36a4a35c5ea77e2cb796557b13bbbb8661f7a4047dd8c389c9ed03db`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0b60005500",
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
        assertEquals("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", value_0x00)

    }
    @Test
    fun `expPowerOf256Of256_22______055c1e52f37544721063663cbf6425ffed0c7235c1e6eadd843c5b4969dd2725`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60166101000a6101000a600055601660ff0a6101000a60015560166101010a6101000a60025560166101000a60ff0a600355601660ff0a60ff0a60045560166101010a60ff0a60055560166101000a6101010a600655601660ff0a6101010a60075560166101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("9ec55c33085514ff7f0000000000000000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("ec447e662ac08957d7e290a421dbf54c0aaf43aadc9cc465ad0b02f071ea00ff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("dc9178d3bab470096f01477c859b5f4173986640b659426412a653465c1600ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("b68fb921f7aa6aff810000000000000000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("dcf0a770777610503596ae0311af46c171151ed45107d7e7bb8f74bb5bea0101", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("4d65773387993928c95c861274232d3fb6f6b7fe1b22e4e61a30e71172160101", value_0x08)

    }
    @Test
    fun `expPowerOf256Of256_8______47c294599e0b74cdb5b6c8f39143ce294599a2ba3c227cc0c137f38aafb8268c`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("989680", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60086101000a6101000a600055600860ff0a6101000a60015560086101010a6101000a60025560086101000a60ff0a600355600860ff0a60ff0a60045560086101010a60ff0a60055560086101000a6101010a600655600860ff0a6101010a60075560086101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("230041a0e7602d6e459609ed39081ec55c33085514ff7f000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("c407d8a413ef9079ead457ed686a05ac81039c0cae0a7f6afd01e8461ff800ff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("67a397e0692385e4cd83853aabce220a94d449e885fa867e96d3ef5e180800ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("70add926e753655d6d0ebe9c0f81368fb921f7aa6aff81000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("0bdce80b8378e43f13d454b9d0a4c83cf311b8eaa45d5122cfd544a217f80101", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("629c25790e1488998877a9ecdf0fb69637e77d8a4bdc1b46270093ba20080101", value_0x08)

    }
    @Test
    fun `mul4______39ad8576fd372782e5e821f9cf34bf59a23ff9a62253d6e775d5682d764784d4`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7f80000000000000000000000000000000000000000000000000000000000000000260005500",
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
        assertEquals("8000000000000000000000000000000000000000000000000000000000000000", value_0x00)

    }
    @Test
    fun `expPowerOf256_13______49243ae35d4dcf1e8f26f5731e5c371a3aa02285f0b8ca4b1db079061e143f32`() {

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
               "600d6101000a600055600d60ff0a600155600d6101010a60025500",
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
        assertEquals("0000000000000000000000000000000000000100000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000000000f34ce4c5ffad5104361db20cff", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("000000000000000000000000000000000000010d4f20d00dbab909cc1e4e0d01", value_0x02)

    }
    @Test
    fun `mulmod3______490eafb72162ed0be60804f1426e3bd88e20d497dd0a1bbf05afe6e5636335df`() {

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
               "6003600003600160050960005500",
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
    fun `exp6______e09c09fb132488b830c21b6110ed71e641f154f4312e675032a4e386fe943350`() {

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
               "61010160010a60005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `addmodDivByZero1______6f8973396767dc5b6482087da9794a3ba5273792c9931950e3856920c4d40e0c`() {

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
               "6000600160000860005500",
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
    fun `expPowerOf256Of256_18______f7ee2933d5ce988ae974b6e0625922ecff304a3a2d68aa9e138ad5a2b0ff5dba`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60126101000a6101000a600055601260ff0a6101000a60015560126101010a6101000a60025560126101000a60ff0a600355601260ff0a60ff0a60045560126101010a60ff0a60055560126101000a6101010a600655601260ff0a6101010a60075560126101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("698218879ec55c33085514ff7f00000000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("8a2cbd9f40794e2205b13306f2aa0a43c60823c64b95d8601fa4f1e521ee00ff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("c1b5a1e3a81da51b10d84e880f0113ff67b863ddad3faf1f4ecf413f101200ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("c9b0f000b68fb921f7aa6aff8100000000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("410be68e49452a1fbcd863bf6e8d637f8eae4979c34c88d552afbcc20fee0101", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("f540cb714754b5b1eb0373833833bd7fb0ee925ce8b92962500b7a1c22120101", value_0x08)

    }
    @Test
    fun `smod5______dcfb040cbcc23315b6ee4da7adbd4bdbb15dbd9059ea16150c4ed7664ac9265e`() {

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
               "7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6000030760005500",
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
    fun `expPowerOf256_25______b1e616098a5afb7feb365ea2838933a187c19fd721c8195a2144220010c533f7`() {

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
               "60196101000a600055601960ff0a60015560196101010a60025500",
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
        assertEquals("0000000000000100000000000000000000000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("00000000000000e823349d2286a5ec3de3529625f683e56c0903589efad418ff", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("000000000000011a352e3c45325c4583eb6149e1b7d4e73f709bbb72fd2c1901", value_0x02)

    }
    @Test
    fun `mulmoddivByZero3______96291f103326241cdc521b7b8d20280651b5715a11dbffd8a91e78c1494a1691`() {

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
               "6000600060000960010360005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `expPowerOf256_33______d6fd7df7a60bc04404ff1e67e62595bcef9405553e61f4da4e3330e47ae64999`() {

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
               "60216101000a600055602160ff0a60015560216101010a60025500",
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
        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("fb4c498e11e3f82e714be514ef024675bb48d678bd192222cd2e783d4df020ff", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("25f3884075dd08b8fb400789097aa95df8750bd17be0d83c9a0fb7ed52102101", value_0x02)

    }
    @Test
    fun `expPowerOf256Of256_4______647c323c2bc230a23effbd64c806cba1a0f51ef01565776e1debc688911c8a24`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60046101000a6101000a600055600460ff0a6101000a60015560046101010a6101000a60025560046101000a60ff0a600355600460ff0a60ff0a60045560046101010a60ff0a60055560046101000a6101010a600655600460ff0a6101010a60075560046101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("e6540ce46eaf70da9d644015a661e0e245b13f307cb3885514ff7f0000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("6526b38b05a6325b80e1c84ab41dc934fd70f33f1bd0eab3d1f61a4707fc00ff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("e959516cd27e5d8fd487b72db2989b3ec2ba9fb7ead41554526fe5a3040400ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("e7498a48c6ce2530bbe814ee3440c8c44fffab7ad8a277aa6aff810000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("2dffa3e901e5a392d15b79f4193d2168147d2aa7c55870b46c3a905d03fc0101", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("e16ea721c96539edb4f7fb82de0dad8cccb1e7a6966a6777635f6fb908040101", value_0x08)

    }
    @Test
    fun `sdiv7______4a960489050bb51fe85a0bb68080bdb65f7b419a651a6d3bc501d41edf747e5c`() {

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
               "601960016000030560005500",
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
    fun `divByNonZero1______6302d1c75eb6e14efad160500857a8e45a15d85a5b44b37aa4ab8a045d865582`() {

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
               "601860170460005500",
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
    fun `addmod1_overflow2______18fc8d42f75579dbb540ca13d37171909ea71f3f046e2595e09e59ddd816d634`() {

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
               "6005600060016000030860005500",
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
    fun `expPowerOf256Of256_14______982c514109f3c8a7a75b5a5a89fda523ac87887437cb569a4cbbd480ed3310e9`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600e6101000a6101000a600055600e60ff0a6101000a600155600e6101010a6101000a600255600e6101000a60ff0a600355600e60ff0a60ff0a600455600e6101010a60ff0a600555600e6101000a6101010a600655600e60ff0a6101010a600755600e6101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("db9902ec698218879ec55c33085514ff7f000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("83fab06c6c8fef761ebbb9534c06ac2a9d61820623008069062ff3b1e1f200ff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("3f791dd183ed5b963bd86e0dba1a9dd5b8ceeb078f15c73062f1942fd40e00ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("e0bfa28fc9b0f000b68fb921f7aa6aff81000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("8133b760dfae27560eb490f235ddfa301f058dee4f01f3fe4b3567d0d3f20101", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("cd4cd0124e983af71620fb5f98275965c6a8bebc4b8adc288b63224ee20e0101", value_0x08)

    }
    @Test
    fun `expPowerOf256Of256_15______b23a72815275a6e9c96988da474d048b158b9b5f0c5085c5eb04cad97e950262`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600f6101000a6101000a600055600f60ff0a6101000a600155600f6101010a6101000a600255600f6101000a60ff0a600355600f60ff0a60ff0a600455600f6101010a60ff0a600555600f6101000a6101010a600655600f60ff0a6101010a600755600f6101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("9882ec698218879ec55c33085514ff7f00000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("75c4915e18b96704209738f5ca765568bb4dc4113d56683977825a132c8dfeff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("5c76839bf5a80b1da705dbdf43e4dd6770cd7501af11ff2dab7918dfe18f00ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("bf228fc9b0f000b68fb921f7aa6aff8100000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("c6a29131e7594004bc2aa79f0d2c402a1409c57c77d284c14b1a3ab0ff8fff01", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("e6b3e5cf6ec90e532fef7d08455ebf92a03e9e3f6e224ea0febdf1a9f08f0101", value_0x08)

    }
    @Test
    fun `divByNonZero0______516b53a477e30a30be5ae227b6e950f313cd50bd2480ddb8ae7d5ddb9672b899`() {

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
               "600260050460005500",
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
    fun `addmod1_overflow3______a4a7f568169a01c7082e429c26bb24aa1a457b970a36436014d9634ac0e905e9`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6005600160016000030860005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `sdiv6______0103d93d72c2614c4cec9dd2b82287be897db08dcbaa7c7265ca640ab1a6419f`() {

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
               "60007f80000000000000000000000000000000000000000000000000000000000000006000030560005500",
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
    fun `expPowerOf256Of256_5______a2a3900744d7e4ad99c02456503c7b664cdcc198cc743862f9a324f2774a710d`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60056101000a6101000a600055600560ff0a6101000a60015560056101010a6101000a60025560056101000a60ff0a600355600560ff0a60ff0a60045560056101010a60ff0a60055560056101000a6101010a600655600560ff0a6101010a60075560056101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("b581ac185aad71db2d177c286929c4c22809e5dcb3085514ff7f000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("75789eb2a64bc971389fbd11a1e6d7abbf95ad25e23fb9aa25e73a0bfc83feff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("fc403fa42ceb6a0d0d3321bd9b2d8af25b1b667f87a04f496c78168d078500ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("cec5ec213b9cb5811f6ae00428fd7b6ef5a1af39a1f7aa6aff81000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("70ab32233202b98d382d17713fa0be391eaf74f85ba1740c9c3238c4ed85ff01", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("b622672a213faa79b32185ff93a7b27a8499e48f7b032cdb4d1a70300c850101", value_0x08)

    }
    @Test
    fun `expPowerOf256_32______0afd4b54adf222e4389e6598fdda7bd10262af1a998f30cab4dc814f75798ecd`() {

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
               "60206101000a600055602060ff0a60015560206101010a60025500",
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
        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("e1dd29730112f6ef1d8edabfd4c3c60c823d865cd592abcdf0bdec64a1efe001", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("2203ef98a7ce0ef9bf3c04038583f6b2ab4d27e3ed8e5285b6e32c8b61f02001", value_0x02)

    }
    @Test
    fun `divBoostBug______650197f2502b31819041a12c1aab2512973402709a10ae1335059812012773c7`() {

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
               "7f01dae6076b981dae6076b981dae6076b981dae6076b981dae6076b981dae60777fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffba0460005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000089", value_0x00)

    }
    @Test
    fun `mulmoddivByZero2______e221e722ff7cbdac29da2b6dc482bd30b423c9a19c74d8ce021cfa4ee624982d`() {

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
               "6000600060010960005500",
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
    fun `addmod1_overflowDiff______23d49c4115fd1813c87e0a6dbacb839d26ce46e9847893178e2a1dd97d3d3657`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6005600260000360016000030860005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000004", value_0x00)

    }
    @Test
    fun `expPowerOf256_24______a156b1005f5c3e745ab41d32c2690ad8e39b8392e539ad80444d5c69a8866c52`() {

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
               "60186101000a600055601860ff0a60015560186101010a60025500",
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
        assertEquals("0000000000000001000000000000000000000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000000000e90c40de00872d19573a8d23493fc3a9151e217a1913e801", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000001191c122a1b1745008367f9509126ae39066a3189e9141801", value_0x02)

    }
    @Test
    fun `smod4______5f1fc786d48010599fcf52b5fb4dbf30a63bb0742db2f8f12ebc90fded4ee5d7`() {

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
               "600060026000030760005500",
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
    fun `expPowerOf256Of256_19______9de67843d894c00616e9a7146777bae0d9e412b5314707b8f5a18e405d70981b`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60136101000a6101000a600055601360ff0a6101000a60015560136101010a6101000a60025560136101000a60ff0a600355601360ff0a60ff0a60045560136101010a60ff0a60055560136101000a6101010a600655601360ff0a6101010a60075560136101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("8218879ec55c33085514ff7f0000000000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("b795ad7ac24cfbb7435cf53bd3584f3d4b2709935635c3ceb66e761ff091feff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("1f0bb7be91a0ccd0cca93d75cf03de3e6b56fe8f1c54242617665327219300ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("b0f000b68fb921f7aa6aff810000000000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("ad571756ecbff1bfdef064861e5e92c5d897a9cc380e54bdbaabd80bb793ff01", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("d8b5b531989e689f700dcdb43ab90e79a49dfbbb5a13dbf751df98bb34930101", value_0x08)

    }
    @Test
    fun `mulmod2______0b68e2a72fa3ff902605f10cb3690ae33ad254ccd5af802e582fbb8713975c77`() {

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
               "6003600160056000030960005500",
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
    fun `exp7______bcb57804639629884271f6c0312ca810255c51f0e4601b0eb576e23d35d9f5f5`() {

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
               "61010160020a60005500",
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
    fun `mul5______fe47df58ddb7b3169648a746c9eaf57dea8388dd62b34c85da6be3baf48ef164`() {

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
               "7f80000000000000000000000000000000000000000000000000000000000000007f80000000000000000000000000000000000000000000000000000000000000000260005500",
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
    fun `expPowerOf256_12______a75d47707ed55f4956a2f3b51e7d4f796be5b6d6b26f0b45f0f735840e67ef42`() {

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
               "600c6101000a600055600c60ff0a600155600c6101010a60025500",
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
        assertEquals("0000000000000000000000000000000000000001000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000f44125ebeb98e9ee2441f401", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000000000010c42ddf21b9f19efdc420c01", value_0x02)

    }
    @Test
    fun `expPowerOf256Of256_9______9e5a0d851b9992075bfc751adbccd8feee18f0f46e23a500d3bd7b66de1a7123`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60096101000a6101000a600055600960ff0a6101000a60015560096101010a6101000a60025560096101000a60ff0a600355600960ff0a60ff0a60045560096101010a60ff0a60055560096101000a6101010a600655600960ff0a6101010a60075560096101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("53017d8eb210db2c8cd4a299079ec55c33085514ff7f00000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("48be09b6c6ae2aa660f1972125cecbb1038b5d236ecf766ba786e2c4e887feff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("2e350d847ba73dc2099f83f532951c47269d9fd7e411b50bae00a9581f8900ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("013ab9e1f0df89a184b4d07080b68fb921f7aa6aff8100000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("f387ed41c1050f9da667f429a3e8fb30b61a55ede97d7b8acd797a03cd89ff01", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("525696c22bb3ce00fd2e3f6bbb9b4ea1046a5e31fcff2fedf8f8c74d28890101", value_0x08)

    }
    @Test
    fun `signextend_BigByte_0______0296ac66b6ac206fd24659db45aebaf420fd30f20f7f187a0ac4a53329544fd6`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0b60005500",
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
    fun `expPowerOf256Of256_23______3e0ba7d9051784f948fb7be568f679656cb397c6bc378ef818f5437680df32cd`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60176101000a6101000a600055601760ff0a6101000a60015560176101010a6101000a60025560176101000a60ff0a600355601760ff0a60ff0a60045560176101010a60ff0a60055560176101000a6101010a600655601760ff0a6101010a60075560176101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("c55c33085514ff7f000000000000000000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("537ca0f03f974303005f1e6693b55b72315a166841732e42b8353724a495feff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("86418797ec60058de6cca47dfdbee79923ac49d7801e01840041ca76719700ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("8fb921f7aa6aff81000000000000000000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("56a55341ab8d4318f1cfb55d5f21e2ba35d7e070a72bac6b2b21baae5f97ff01", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("55ddd0ec77909de6d8311116cf520398e816f928b06fdd90ec239d0488970101", value_0x08)

    }
    @Test
    fun `expPowerOf256_1______864c45e280734b724963777a23c9933e76d869a2ea9803c93543c0a5b0d8d308`() {

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
               "60016101000a600055600160ff0a60015560016101010a60025500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000100", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000000000000000000000000000000000ff", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000101", value_0x02)

    }
    @Test
    fun `mulmod1_overflow______dffba439ec22436530408f833f34746fa35d178055bf679df70a1b00db085c44`() {

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
               "6005600260016000030960005500",
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
    fun `sub1______b90f6025fbb260ce9f3e1d1bfb42fdf808178f2baef6bf5da244a39a5494723c`() {

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
               "600360020360005500",
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
        assertEquals("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", value_0x00)

    }
    @Test
    fun `expPowerOf256_28______86894ac2726a7b31e3b7b20e7edcb638bca421de54eb093a195c74641b61ba08`() {

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
               "601c6101000a600055601c60ff0a600155601c6101010a60025500",
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
        assertEquals("0000000100000000000000000000000000000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("00000000e56d8280c5c1dc6be448760a77f47c1750f146fd962467ee3579e401", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("000000011d871d80b9e4ff369ba3f4b3ce9beb6f2bb9931fe9243807cd7a1c01", value_0x02)

    }
    @Test
    fun `expPowerOf256_23______a5ad360f2026aa6442680e87c2810ffa62630d69a74b8902250a6a586048342d`() {

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
               "60176101000a600055601760ff0a60015560176101010a60025500",
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
        assertEquals("0000000000000000010000000000000000000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("000000000000000000e9f63715159cc9e33a7502256eae721b304e6fea0316ff", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("00000000000000000118040e1bff182cd3afb8410f81a5092fd6939debfd1701", value_0x02)

    }
    @Test
    fun `addmod0______5d23b01f1c8ea3156332b0a22aaf41feeaa663792539adc9d9ae5179e1e71381`() {

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
               "6002600260010860005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `add0______eed49c2012a3b056407dbe3262ef483c24dae0700eb5885f0f7eaabe99e60230`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0160005500",
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
        assertEquals("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe", value_0x00)

    }
    @Test
    fun `expPowerOf256Of256_28______42e6bc9efaae171f2270551777ca19b08ebf7c7dffe0ff9579af401e2f9c69ab`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "601c6101000a6101000a600055601c60ff0a6101000a600155601c6101010a6101000a600255601c6101000a60ff0a600355601c60ff0a60ff0a600455601c6101010a60ff0a600555601c6101000a6101010a600655601c60ff0a6101010a600755601c6101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("14ff7f0000000000000000000000000000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("ffd368e44b3f85cb81ae394c9809ca9fa2db46a83d7880a912ab6d4a87e400ff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("0981ad53c19b15a94bcf0bf20235dd0da9df25f46ae635029fe2062e6c1c00ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("6aff810000000000000000000000000000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("19df06ffa28250867006726405fbc05d43dc2f9d2f025006db089bd46be40101", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("243fffe3a4f2982f45055c08f379648ab886da8027a7401117a8e0b8881c0101", value_0x08)

    }
    @Test
    fun `mulmod2_1______368eb3f392783c2b4a263e888cfffaaaa8f182fa19b7f3640b1ef2a0f83c071f`() {

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
               "6003600160056000030960036005600003061460005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `smod8_byZero______7209e99924daaa4578cd0c70783788c5176b6c2fdcee3987e9d90279d3c0552e`() {

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
               "600d600060c8600003070360005500",
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
        assertEquals("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff3", value_0x00)

    }
    @Test
    fun `expPowerOf256Of256_2______d79175d178184b76a996da417b55447f7a923174412c1bb0ee2c3db869c19d39`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60026101000a6101000a600055600260ff0a6101000a60015560026101010a6101000a60025560026101000a60ff0a600355600260ff0a60ff0a60045560026101010a60ff0a60055560026101000a6101010a600655600260ff0a6101010a60075560026101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("4ee4ceeaac565c81f55a87c43f82f7c889ef4fc7c679671e28d594ff7f000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("82f46a1b4e34d66712910615d2571d75606ceac51fa8ca8c58cf6ca881fe00ff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("81c9fcefa5de158ae2007f25d35c0d11cd735342a48905955a5a6852800200ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("666ac362902470ed850709e2a29969d10cba09debc03c38d172aeaff81000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("eb30a3c678a01bde914548f98f3366dc0ffe9f85384ebf1111d03dad7ffe0101", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("72d0a7939b6303ce1d46e6e3f1b8be303bfdb2b00f41ad8076b0975782020101", value_0x08)

    }
    @Test
    fun `expPowerOf256_19______be32d9b8ae72a7144efc64005eb4233dc4d1680f8e51b16125f80441c323755d`() {

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
               "60136101000a600055601360ff0a60015560136101010a60025500",
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
        assertEquals("0000000000000000000000000100000000000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("00000000000000000000000000eda745f6fd3851d68db3866a315cdfc85512ff", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000113aed851d6c1fca84402033e297b27c9ab1301", value_0x02)

    }
    @Test
    fun `signextend_bigBytePlus1______5cff45b93e5c246a2d2d69c5e0c3a2109c2d6943bf74ea0663c7945589f0af65`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "66f000000000000161ffff0b600055",
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
        assertEquals("00000000000000000000000000000000000000000000000000f0000000000001", value_0x00)

    }
    @Test
    fun `sdivByZero2______9146fb9b6c1954d92d08cab701e2927c85dac72b1c99f13b339f3d74a971383a`() {

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
               "600160007ffffffffffffffffffffffffffffffffffffffffffffffffffffffffcf923bdff600003050160005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `sdiv1______eb138ce03ad7c36829021dec77c0c12a6da30f10649068e6ee751aa8e32a68d9`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6000037fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0560005500",
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
        assertEquals("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", value_0x00)

    }
    @Test
    fun `addmod1_overflow4______d87b826a19534575ad5cce48dff7fb18c84f399b859a49209f1f8c04ba023373`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6005600260016000030860005500",
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
    fun `expPowerOf256Of256_12______8fd3970a9f5f7049c84b8c85450e2c033fafe1606161788ad1f2d6c31e1bf6d8`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600c6101000a6101000a600055600c60ff0a6101000a600155600c6101010a6101000a600255600c6101000a60ff0a600355600c60ff0a60ff0a600455600c6101010a60ff0a600555600c6101000a6101010a600655600c60ff0a6101010a600755600c6101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("b0e95b83a36ce98218879ec55c33085514ff7f00000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("c482ab56ec19186dc48c88f30861a850b2253b1ea6dc021589e569bd47f400ff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("cf45c7f9af4bbe4a83055b55b97777ad5e0a3f08b129c9ae208c5d713c0c00ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("a5cbb62a421049b0f000b68fb921f7aa6aff8100000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("3bde6ca66dffe1bf5d727c3edea74c7a4af43b3912e6256d37705c8f3bf40101", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("3f49a1e40c5213aa4ffed57eb4c1ad2d181b2aaa289e9d59c2256c43480c0101", value_0x08)

    }
    @Test
    fun `expPowerOf256Of256_32______fb46d4db8746818c19aa2728485194b798eb5a487fa2712ee4d12e64c60970f4`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60206101000a6101000a600055602060ff0a6101000a60015560206101010a6101000a60025560206101000a60ff0a600355602060ff0a60ff0a60045560206101010a60ff0a60055560206101000a6101010a600655602060ff0a6101010a60075560206101010a6101010a60085500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("b8247842bb5ce75c08d0c251669ed5870fa24a22952e5db3a7c66c59ffe000ff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("ee526e5a06f2a990b2bf6c951e5feabf0e07ee16877296e1be872db9e02000ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("eda7d024b6de40a9d3b966e71f10a4667edc5b71cab07aeabcac6249dfe00101", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("512ecfaeeb11205f0833e1054dcb1300488e0954be5af77a49e143aa00200101", value_0x08)

    }
    @Test
    fun `expPowerOf256_6______c079ca3fcd029f737c1dab297236c85b7435e26699c41e872e09728f69e8c411`() {

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
               "60066101000a600055600660ff0a60015560066101010a60025500",
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
        assertEquals("0000000000000000000000000000000000000000000000000001000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000fa0eec0efa01", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000001060f140f0601", value_0x02)

    }
    @Test
    fun `expPowerOf256Of256_24______ff082d6cc52f56d2a51dad22fba3bf4e9f2f7cfc53f64a9c4bb21e5a9d3f258a`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60186101000a6101000a600055601860ff0a6101000a60015560186101010a6101000a60025560186101000a60ff0a600355601860ff0a60ff0a60045560186101010a60ff0a60055560186101000a6101010a600655601860ff0a6101010a60075560186101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("5c33085514ff7f00000000000000000000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("d542e526003539ead104274aff2d78332366e29d328c2161f0c120731fe800ff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("c706cb25e8384ce9bb5c9cb48415238ba03e16c448e292c0a101843b081800ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("b921f7aa6aff8100000000000000000000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("4ca55f89202c524cb0f1cb3195d13c8d94a9f7a05c59e1d4031577c707e80101", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("8c4b0574e9156b80035f3ecdcf1fe79d273ed7559747a4322bcd338f20180101", value_0x08)

    }
    @Test
    fun `expPowerOf2_32______eef81e5034bed999aa6daf3693391856da94ed701a7f2369a0c48a62fcc7a88d`() {

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
               "602060020a600055601f60020a600155602160020a60025500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000100000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000080000000", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000200000000", value_0x02)

    }
    @Test
    fun `signextend_0_BigByte______0e9bb9da2cebd330e78e5907a78c66783f74d5d45d1879cf4ab4de33a37503d6`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000b60005500",
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
        assertEquals("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", value_0x00)

    }
    @Test
    fun `mod1______1faa1711d5c8a5961559a87debfc93008978bf2be50e2e9ed580897eb760e500`() {

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
               "60027fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0660005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `sdiv_i256min______00b14e0301d52da6b1c4199b2d3d9e0b628d64dddd7feaa75fe781b784ab58f0`() {

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
               "60016000037f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6000030560005500",
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
        assertEquals("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", value_0x00)

    }
    @Test
    fun `expPowerOf256_15______3adb25f770f215842df34ee36825ab9fe6503b13aba4b94cf477cf3886440446`() {

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
               "600f6101000a600055600f60ff0a600155600f6101010a60025500",
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
        assertEquals("0000000000000000000000000000000001000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000f1673e495873f60f7eb5acc6970eff", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000010f6acc60cea63c3698c056c7690f01", value_0x02)

    }
    @Test
    fun `mul2______eb2525a03cd7c1e0aaf5a9b660360ced8388a7eafadd951192dd9f1a604b980f`() {

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
               "601760000260005500",
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
    fun `exp0______1bf9005e2da813e69b360daecd973f484befb8837bc43a0167358a16b289cfeb`() {

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
               "600260020a60005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000004", value_0x00)

    }
    @Test
    fun `signextend_BitIsNotSetInHigherByte______28b00b14290431ba1769b6bb6fed1bfc8729c11bdfab6519e8d1fa47722472a4`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "62126af460010b600055",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000006af4", value_0x00)

    }
    @Test
    fun `smod3______2e80eec4bc6c2aa3d52dcfe775f00b257b763332ad4dd8b5dfd836cf40c1fbcb`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60026000030760005500",
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
    fun `smod2______5e600e0210e88a9ca85cb8726ab0810e89acc616e459b93cc892786649a32322`() {

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
               "600360056000030760005500",
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
        assertEquals("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe", value_0x00)

    }
    @Test
    fun `signextend_Overflow_dj42______f907896fe2ba3e44f6ca1b7eafba25b3d0231f4d2b55309ada59a0f3ee3be25a`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6005565b005b61800080680100000000000000010b6180011160035763badf000d60115500",
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
    fun `mulmod4______f29f6d7adbce227deffde4150c945725226a5786c951e1426ddb8b56f9532703`() {

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
               "6064601b60250960005360006001f300",
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
    fun `exp1______9b9a9bbea8ffa7bb08c76effac9201410b50cb5036fff6fe2de5be5db36156d4`() {

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
               "7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0a60005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `expPowerOf256_14______27dccd3a14a2324bd2d6d6f5401828bd1902fbd03bbad451cbf8af61f3bd1589`() {

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
               "600e6101000a600055600e60ff0a600155600e6101010a60025500",
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
        assertEquals("0000000000000000000000000000000000010000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("000000000000000000000000000000000000f25997e139ada3b331e7945af201", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000010e5c6ff0ddc873c2d5ea6c5b0e01", value_0x02)

    }
    @Test
    fun `mul3______bead834fbe09c2c9429306e7eb517177b4e9b6123749aa32cdd1a66143590202`() {

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
               "600160170260005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000017", value_0x00)

    }
    @Test
    fun `smod_i256min1______98a54c2f68772a7be9cbfb7d087bbfcb22b51b2bf48b1cfca62bf8b327b28d3a`() {

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
               "60016000037f80000000000000000000000000000000000000000000000000000000000000006000030760005500",
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
    fun `expPowerOf2_64______e85ab0b7fa1d64d8c85a7a51ad8b13e555d0fed13e559a50bf81182f34dc7c25`() {

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
               "604060020a600055603f60020a600155604160020a60025500",
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
        assertEquals("0000000000000000000000000000000000000000000000010000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000008000000000000000", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000020000000000000000", value_0x02)

    }
    @Test
    fun `mod0______8d3ce05f1163ba12be60a5f1c6e79cad02cc337c8c39f722a2afec69299b235f`() {

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
               "600360020660005500",
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
    fun `expPowerOf256Of256_25______2b23497be02c53571c595b418b0840ca1e924ec71a34b52e0ef3cc588017a0d8`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60196101000a6101000a600055601960ff0a6101000a60015560196101010a6101000a60025560196101000a60ff0a600355601960ff0a60ff0a60045560196101010a60ff0a60055560196101000a6101010a600655601960ff0a6101010a60075560196101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("33085514ff7f0000000000000000000000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("7f510dd7198cac0a92ff7ea80451838c0dfa12114c41a0ef05907397f897feff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("1275e752b6aee228ecba5e9b57ef1111deff3c651e2cfbf2cccd13151f9900ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("21f7aa6aff810000000000000000000000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("6646340ad51a03bb710caf05756b685b33c7dad62ae68d369243700ead99ff01", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("29d80e8060ef2221929bb18215586c742686d6860e028ca0456b443238990101", value_0x08)

    }
    @Test
    fun `expPowerOf256_7______3f454af11103be7560988543f6f0158da6a32430a000ebf91a65ee1e82646db0`() {

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
               "60076101000a600055600760ff0a60015560076101010a60025500",
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
        assertEquals("0000000000000000000000000000000000000000000000000100000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000000000000000000000f914dd22eb06ff", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000107152323150701", value_0x02)

    }
    @Test
    fun `expPowerOf256Of256_33______c91e0137f1121347da62e2f5f326d8633ee3876eb01d3d7d7bf2acf54b49f413`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60216101000a6101000a600055602160ff0a6101000a60015560216101010a6101000a60025560216101000a60ff0a600355602160ff0a60ff0a60045560216101010a60ff0a60055560216101000a6101010a600655602160ff0a6101010a60075560216101010a6101010a60085500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("8dcb65b5494eba78cd6756a6f9851f6e26d0f2bb9ecd7e9abd7e9b11209ffeff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("6694bb31b20cd625f3756897dae6d738f2e64467b5b6f10fa3e07763ffa100ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("e678999aeffd1f1f45081f64de7f80ab083dd7df04721ed64ee04c03bda1ff01", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("39b68fb9898dd7568abd178397251ce8226a25c1d305a4e79573333520a10101", value_0x08)

    }
    @Test
    fun `expPowerOf256Of256_13______fc57b96fa11997c8164256bfedac8449dac12d0044ad13b06c7a5dd8514cc37e`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600d6101000a6101000a600055600d60ff0a6101000a600155600d6101010a6101000a600255600d6101000a60ff0a600355600d60ff0a60ff0a600455600d6101010a60ff0a600555600d6101000a6101010a600655600d60ff0a6101010a600755600d6101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("e02639036c698218879ec55c33085514ff7f0000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("8be664bde946d939ce551b948b503787942d2a7734509288c1b62fd5c48bfeff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("a923a28e7a75aef26c51580ffc686879e4a0b404b089bdbcd751d88b478d00ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("41ac5ea30fc9b0f000b68fb921f7aa6aff810000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("0daa3a177ec975cb69bb4acf4a6e1be7bcc1ad33d1ffad97510f9fea9d8dff01", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("19e6822beb889be28310060f4fb9741bfd50a31fa81ec65de21f7b02548d0101", value_0x08)

    }
    @Test
    fun `sdiv0______102a243faf303a2a91097602951b569dda59dbfc4b1ece4ceec3fbe22c947881`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6000030560005500",
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
        assertEquals("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", value_0x00)

    }
    @Test
    fun `expPowerOf256_18______805bae07efca1d7dc14dc1920beaee473f11525a046a0759d61a18daa7c4d759`() {

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
               "60126101000a600055601260ff0a60015560126101010a60025500",
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
        assertEquals("0000000000000000000000000001000000000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000000000000000000000ee95dbd2d0085a30be71f86293f0d098ee01", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000001129c3c15c100fbac976a98a583f730991201", value_0x02)

    }
    @Test
    fun `expPowerOf256Of256_3______daa7e221f3009f1d3d603cc683ba908903b7cc435d3ae53c7cf6c742122076b6`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60036101000a6101000a600055600360ff0a6101000a60015560036101010a6101000a60025560036101000a60ff0a600355600360ff0a60ff0a60045560036101010a60ff0a60055560036101000a6101010a600655600360ff0a6101010a60075560036101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("109a00e1370d2d2922bf892e85becb54297354b2e5c75388d514ff7f00000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("54a792f15e9aba7e4ad9e716bc169eea3a6e2e9c49bf9b335874613c8081feff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("5d24a14d8e5e039372cd0f6a0f31e9ed6b75adba9f16b1c5b3edd5ba818300ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("298e2f316b4ccded5ebf515998d9ec20df69404b04a441782a6aff8100000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("4335694e98f372183c62a2339fa4ad161e9b4c42240bdc9452abffd07783ff01", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("f0f0820797315acd063056bba76f6a9c3e281cdb5197a233967ca94684830101", value_0x08)

    }
    @Test
    fun `signextend_AlmostBiggestByte______1991debca3b6f358a990cbb332251e82ee450477d2844786f13285c245f0991c`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe0b60005500",
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
        assertEquals("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe", value_0x00)

    }
    @Test
    fun `addmod3_0______78b24cf9f66f0e18822b6db9346b14e8b95482018b32a4377c02df121eba3d98`() {

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
               "6002600360000360016004081460005500",
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
    fun `mulmod2_0______5759a12b68db6f37ea65edd0db1cc21a9aa840c5c7571bc5c7cd2c3d36510d93`() {

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
               "6003600160056000030960036005600003071460005500",
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
    fun `expPowerOf256Of256_29______838778a6ef42f0bbdd91dc9968f3fa06e46e864c11999959a08fe7d482937fbe`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "601d6101000a6101000a600055601d60ff0a6101000a600155601d6101010a6101000a600255601d6101000a60ff0a600355601d60ff0a60ff0a600455601d6101010a60ff0a600555601d6101000a6101010a600655601d60ff0a6101010a600755601d6101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("ff7f000000000000000000000000000000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("41e065d46e0349cfe624c4e8a2034aea1f7edfff80e511cd8067d488949bfeff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("a84162ca6675a22c4c79dfc4ea15f760db5a04dbf04246764199b668879d00ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("ff81000000000000000000000000000000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("1226984faa6b05ebdbd45d8477fa4fd5b55bfd5061de03c319282b153d9dff01", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("5cc9e6b0b749fd94541ad00364bdec2fca7816981ca3e38f485decc7a49d0101", value_0x08)

    }
    @Test
    fun `signextend_BigBytePlus1_2______57624347ff06fb66da3c682469d4711f42adef53d0adaba22710c6a26f662d04`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60ff68f000000000000000010b600055",
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
        assertEquals("00000000000000000000000000000000000000000000000000000000000000ff", value_0x00)

    }
    @Test
    fun `add1______5d119256032625a91fccdc4958b4e6c8202f1c3e9ff104b37a40850d3337189b`() {

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
               "60047fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0160005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000003", value_0x00)

    }
    @Test
    fun `addmod1______d0a8e231b6d65fd8fce0c386d559c78a1ed012bf67b6cbf2a0604fbec6b5df0f`() {

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
               "6002600260000360016000030860005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `expPowerOf256_22______62731347ed7e1a7944279f7e70feeef4c06004c004dbc01825a0a69928242938`() {

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
               "60166101000a600055601660ff0a60015560166101010a60025500",
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
        assertEquals("0000000000000000000100000000000000000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("00000000000000000000eae1182d42dfa98cc73c3e63d280f30e3e8cfce6ea01", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000116ed20fb041418baf4c37d91efb553dbfa9904e71601", value_0x02)

    }
    @Test
    fun `expPowerOf256Of256_10______a796d7fa589cd3522f3f115c03f5ccb9988fa51ed9b3dff53221b5d409b32d73`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600a6101000a6101000a600055600a60ff0a6101000a600155600a6101010a6101000a600255600a6101000a60ff0a600355600a60ff0a60ff0a600455600a6101010a60ff0a600555600a6101000a6101010a600655600a60ff0a6101010a600755600a6101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("fe0f60957dc223578a0298879ec55c33085514ff7f0000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("c1ea45f348b5d351c4d8fe5c77da979cadc33d866acc42e981278896b1f600ff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("56ddb29bca94fb986ac0a40188b3b53f3216b3559bd8324a77ea8bd8a80a00ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("2d49ff6b0bbe177ae9317000b68fb921f7aa6aff810000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("185fa9eab94cfe3016b69657e83b23fd24cc6960218254231c3db627a7f60101", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("a7a0223829f26d6c635368034320563df4aa5eb62efc87a42bb35f69b20a0101", value_0x08)

    }
    @Test
    fun `sdiv3______b33026d13187cb8b6e1132788a4d72a4b9bbce0920a22c129ca2ce413dbfaed0`() {

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
               "600260000360040560005500",
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
        assertEquals("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe", value_0x00)

    }
    @Test
    fun `sdivByZero0______f091f402495e7f2fb2617a7f4850284b0e8c5d9fcd1c7db47b7f02ad9931a027`() {

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
               "600060000360036000030560005500",
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
    fun `mulmod1_overflow3______156d883b6c0877f690ec7d6afa153c81e748eb9e417d8e9bb67331c8389eba2a`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600560027f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0960005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000004", value_0x00)

    }
    @Test
    fun `expXY_success______f6f5bcc588dee0299366dacb6ea35702303e4d74cfc69cd3e575e5738f2489ca`() {

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
            "0x0000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000000f"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6000356000556020356001556001546000540a60025500",
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

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("000000000000000000000000000000000000000000000000000000000000000f", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000008000", value_0x02)

    }
    @Test
    fun `expPowerOf256Of256_0______728cf4cf0e100d14f1c198d8defacddd6ef8b5cafcda2ed1026efdd5e1ac644f`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60006101000a6101000a600055600060ff0a6101000a60015560006101010a6101000a60025560006101000a60ff0a600355600060ff0a60ff0a60045560006101010a60ff0a60055560006101000a6101010a600655600060ff0a6101010a60075560006101010a6101010a60085500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000100", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000100", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000100", value_0x02)

        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000000000000000000000000000000000ff", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000000000000000000000000000000000ff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000000000000000000000000000000000ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000101", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000101", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000101", value_0x08)

    }
    @Test
    fun `div1______d09f689310c035b0c904a752bb432a0509abf030dc17f0e7cc8407d81c1614d7`() {

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
               "60027ffedcba9876543210fedcba9876543210fedcba9876543210fedcba98765432100460005260206000f300",
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
    fun `add2______c340ae00d650ccbdd5f49fca533cf56359f6354ada5a654a7eda76778c189a07`() {

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
               "60017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0160005500",
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
    fun `expPowerOf256_8______fda6fff91784fb11efefd3a89724569987b3bcd8110fb9e7be022325e864d8d2`() {

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
               "60086101000a600055600860ff0a60015560086101010a60025500",
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
        assertEquals("0000000000000000000000000000000000000000000000010000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("000000000000000000000000000000000000000000000000f81bc845c81bf801", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("000000000000000000000000000000000000000000000001081c3846381c0801", value_0x02)

    }
    @Test
    fun `expPowerOf2_256______2919add85570073d7ebfac054a076be74d7af40d5b5cf07166122c7211a081a8`() {

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
               "61010060020a60005560ff60020a60015561010160020a60025500",
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
        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("8000000000000000000000000000000000000000000000000000000000000000", value_0x01)

    }
    @Test
    fun `expPowerOf2_128______5d64f31d1bb8df7ce9f1f6a0f4702f3d5c1f7aca8111de824d4b7a7a7048a1f9`() {

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
               "608060020a600055607f60020a600155608160020a60025500",
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
        assertEquals("0000000000000000000000000000000100000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000080000000000000000000000000000000", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000200000000000000000000000000000000", value_0x02)

    }
    @Test
    fun `addmod2______4054bcf630df1fe672246851ddbd3dd868a87c7e6170e6b2666c729cb3b6eec2`() {

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
               "6003600160066000030860005500",
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
    fun `expPowerOf256_21______6effe3bdae2055eda2fbdedb850bb9797fdb6e9d89249ee33f929a813732f2db`() {

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
               "60156101000a600055601560ff0a60015560156101010a60025500",
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
        assertEquals("0000000000000000000001000000000000000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000000000000000ebcce5125534de6b326ead10e3645765a4312e14ff", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("000000000000000000000115d749b152c1576391324b46a90c47946632d21501", value_0x02)

    }
    @Test
    fun `not1______d7f58c595a34cbe868d5732665e5b50e4ae992e422ff3cbde744c5ebe1287b52`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6201e2406000526000511960005260206000f300",
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
    fun `smod1______76edf8b91fa48c38da463b93b3045d5fd52c5a1c15924f5f77ce462a66540a0d`() {

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
               "600360000360050760005500",
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
    fun `divByZero______e232462aeec49758e02a7961c6385550ed5f0f665126254fbcf4f2a7d42a0952`() {

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
               "600060020460005500",
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
    fun `exp2______782b66820c1247e152eecd75ac7706cc6daf1f8061b322d9d96e1d32f36e5e91`() {

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
               "637fffffff637fffffff0a60005500",
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
        assertEquals("bc8cccccccc888888880000000aaaaaab00000000fffffffffffffff7fffffff", value_0x00)

    }
    @Test
    fun `mul0______e625977162bc531ffc014c01a9847375acf1963db4b65ccaaaf86b62ff211123`() {

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
               "600360020260005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000006", value_0x00)

    }
    @Test
    fun `expPowerOf256_17______c50971f1d499f27e59dabcc372a7f49a7b00ddfeb1889d89b995c9148d8f867d`() {

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
               "60116101000a600055601160ff0a60015560116101010a60025500",
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
        assertEquals("0000000000000000000000000000010000000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("000000000000000000000000000000ef856134040c669755c7c022b6a77810ff", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("000000000000000000000000000001118ab1645ca45755422870354ea8881101", value_0x02)

    }
    @Test
    fun `smod_i256min2______133562c9024bb92ed296af69aacb6a21780e058b04ce56043632942c9418c771`() {

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
               "600160016000037f8000000000000000000000000000000000000000000000000000000000000000600003070360005500",
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
        assertEquals("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", value_0x00)

    }
    @Test
    fun `fibbonacci_unrolled______cd894f7dc775feaad1ba46fa30c9278f7d05b08daeeeb1717b5051da0624e549`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6001600181810181810181810181810181810181810181810181810181810181810181810181810181810181810181810181810181810160005260206000f300",
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
    fun `mod3______7a468883e5541e5364851597ed7c80a39a3a0ce3967a1060ca98a9767d816689`() {

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
               "600060030660005500",
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
    fun `expPowerOf256Of256_26______bbd45c2e48bf7fff3bac0081b9b5f4ef96ef095543ec162ec71084f4dce35f7d`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "601a6101000a6101000a600055601a60ff0a6101000a600155601a6101010a6101000a600255601a6101000a60ff0a600355601a60ff0a60ff0a600455601a6101010a60ff0a600555601a6101000a6101010a600655601a60ff0a6101010a600755601a6101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("085514ff7f000000000000000000000000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("1d164db738eb6893868b361ad2803f97be35764456e82a837667a693d1e600ff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("8b92c24abebf376a5aab5ff4dfd3538a03d38a10bced2aae8e1a8a85b81a00ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("f7aa6aff81000000000000000000000000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("6931bda98c70e860a1f6a5224940f1ec7e6734cd9456c95806384f7cb7e60101", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("3402a9db66492dfc2a220715e76243469462f24edc56903ba1d8e96ed21a0101", value_0x08)

    }
    @Test
    fun `expPowerOf256_4______fc27c21e9a727c51d51b893f4dbf9b28a30cd14165a4f930dd1ab32169821c65`() {

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
               "60046101000a600055600460ff0a60015560046101010a60025500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000100000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000000000000000000000000000fc05fc01", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000104060401", value_0x02)

    }
    @Test
    fun `expPowerOf256Of256_30______b3aa05605d8814e39af0099de73c74d4ed076f92cb5f58d8e234c7bda83e7a26`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "601e6101000a6101000a600055601e60ff0a6101000a600155601e6101010a6101000a600255601e6101000a60ff0a600355601e60ff0a60ff0a600455601e6101010a60ff0a600555601e6101000a6101010a600655601e60ff0a6101010a600755601e6101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("7f00000000000000000000000000000000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("e9772778f50fa0a69cd10fa019ac56d72ac7a7d7af26c4ba28415c8f41e200ff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("33f0385ef73feebdb952e5adb643dd0fa178fd9271578219ad50a73d241e00ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("8100000000000000000000000000000000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("fd405cce8f73dffc04a6f0ff6ffc6bf7961876d09c5b4933a68f0cc623e20101", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("c5a8f4566fd2e96e4ce3a8b3ec0863e7b20bc3b2f3dc5261ba8a0174421e0101", value_0x08)

    }
    @Test
    fun `sub4______6ea0a3ccb85f08d4e0f05fd3a3223d05a835c04f05c9b7a546b0759857276e44`() {

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
               "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0360005500",
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
        assertEquals("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", value_0x00)

    }
    @Test
    fun `signextend_BitIsNotSet______caa82fcaef9ac8ef4213746c97d84e853b3b6e1c3ca0c9d55b2c4d2db4fba928`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "62122f6a60000b600055",
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
        assertEquals("000000000000000000000000000000000000000000000000000000000000006a", value_0x00)

    }
    @Test
    fun `expPowerOf256Of256_31______a0d2f853118152b04d7e2e5183a93db7bd86b6fbda13dc4ebbe847cc7cdd795e`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "601f6101000a6101000a600055601f60ff0a6101000a600155601f6101010a6101000a600255601f6101000a60ff0a600355601f60ff0a60ff0a600455601f6101010a60ff0a600555601f6101000a6101010a600655601f60ff0a6101010a600755601f6101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("f9cb87f5b1ab58602f52a1e9d392e5675b86a59a53943a8d4ec2a915dc9dfeff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("893d729a64e318860ec5047e70e598da163eb41e71e74b04dfd4712d419f00ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("ee5f2839c1b4f6ca05e6fdb04e2fb49c0f860b3765c27dc781a150cb7f9fff01", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("b4c358e3c6bcddfb509ea487d733df0e1854f29c3b6bfd4a8caabe3f609f0101", value_0x08)

    }
    @Test
    fun `signextend_BitIsSetInHigherByte______5849835529c5a2ac9cc0415fa48bbac98453e432bda296d9dac8c0b22928aca6`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6212faf460010b600055",
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
        assertEquals("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffaf4", value_0x00)

    }
    @Test
    fun `expPowerOf256_5______b3ff159092b0405ffc28f6d48974a437061d7a7f7bdfe5bf88d457360bfad053`() {

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
               "60056101000a600055600560ff0a60015560056101010a60025500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000010000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("000000000000000000000000000000000000000000000000000000fb09f604ff", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("000000000000000000000000000000000000000000000000000001050a0a0501", value_0x02)

    }
    @Test
    fun `expPowerOf256Of256_27______1eea3ada8cf295e1d3ba6423495e9caa7ac98e53b40798f54aa6bc83b72a2a36`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "601b6101000a6101000a600055601b60ff0a6101000a600155601b6101010a6101000a600255601b6101000a60ff0a600355601b60ff0a60ff0a600455601b6101010a60ff0a600555601b6101000a6101010a600655601b60ff0a6101010a600755601b6101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("5514ff7f00000000000000000000000000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("178918ffbcb401d4efd2f7dfb4d01a897172267f0f491121ac52dd614899feff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("38ecff71480ca0b422f2ed6f780d5fead2ae234a49104b10a86f7f0dd19b00ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("aa6aff8100000000000000000000000000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("d02811cb5dc1d80567e810532b235b7672f5c78cd6e89bb511d5e2d8f79bff01", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("1b4e6404f474c18055d30bb8987672f59e97980d6f9de1764c0fbec5ec9b0101", value_0x08)

    }
    @Test
    fun `expPowerOf2_2______a4189e65e97bef1455b7b4616050e8bd53910ad1419fe9370629345f8441d82d`() {

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
               "600260020a600055600160020a600155600360020a60025500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000004", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000002", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000008", value_0x02)

    }
    @Test
    fun `addmodDivByZero______8766d7675f11a894cdede83037f6f3303859aece8ea357b5de4a497459dcd2cb`() {

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
               "6000600160040860005500",
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
    fun `mod2______0d51b1ed885d4819cac9bdcb1a6792f0e74f3f260ffca23a7900281e2b788c36`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000660005500",
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
    fun `mul1______587e1a93d06a1bf965d38fc9bdc79cc0a012fa8a8eeaa74abc2740d8c4d262f3`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0260005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `expPowerOf256_16______2679d268c66c2e15574348918d5de72c815913ab0a5330d79b7b94f540e82649`() {

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
               "60106101000a600055601060ff0a60015560106101010a60025500",
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
        assertEquals("0000000000000000000000000000000100000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000f075d70b0f1b82196f36f719d077f001", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("00000000000000000000000000000001107a372d2f74e272cf59171e30781001", value_0x02)

    }
    @Test
    fun `exp3______88f26409489f3a07145542d3442c754bf28c4288729a2bc0126e106c97ec3dd5`() {

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
               "637fffffff60000a60005500",
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
    fun `smod0______1a5e70500460d728e4ae9ba39004551b638ee45fd60e5642fedb95c05f750c66`() {

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
               "600360000360056000030760005500",
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
        assertEquals("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe", value_0x00)

    }
    @Test
    fun `expPowerOf256_20______83c9e6484d0d81cf94c4e46a0d37d73e9ec26e4f10577a68f48f83297c9d0558`() {

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
               "60146101000a600055601460ff0a60015560146101010a60025500",
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
        assertEquals("0000000000000000000000010000000000000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("000000000000000000000000ecb99eb1063b1984b725d2e3c72b82e88cbdec01", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("00000000000000000000000114c2872a2898bea4ec46054167a4a2f174be1401", value_0x02)

    }
    @Test
    fun `addmod3______9696582fbb435bd6c0142e52bf953610c4f46034e094f3fd11e705f707eab1b2`() {

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
               "6003600003600160040860005500",
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
    fun `expPowerOf256_9______68e1fb1f25e7ab9288bf60ca8a655aaaa8aaf3e7cc849a75a04679caccf62743`() {

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
               "60096101000a600055600960ff0a60015560096101010a60025500",
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
        assertEquals("0000000000000000000000000000000000000000000001000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000f723ac7d8253dc08ff", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000000000000000010924547e7e54240901", value_0x02)

    }
    @Test
    fun `add3______7bb8009c7719c8350f7d4d8c35170e5bc255a511a9139bc347d405d655a382db`() {

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
               "600060000160005500",
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
    fun `expPowerOf256Of256_1______650b70dd25318cf5ae924f19178eb8e93e57d47cb80da99a28ded7d629fa5c02`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60016101000a6101000a600055600160ff0a6101000a60015560016101010a6101000a60025560016101000a60ff0a600355600160ff0a60ff0a60045560016101010a60ff0a60055560016101000a6101010a600655600160ff0a6101010a60075560016101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("06c3acd330b959ad6efabce6d2d2125e73a88a65a9880d203dddf5957f7f0001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("8f965a06da0ac41dcb3a34f1d8ab7d8fee620a94faa42c395997756b007ffeff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("bce9265d88a053c18bc229ebff404c1534e1db43de85131da0179fe9ff8100ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("02b5e9d7a094c19f5ebdd4f2e618f859ed15e4f1f0351f286bf849eb7f810001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("c73b7a6f68385c653a24993bb72eea0e4ba17470816ec658cf9c5bedfd81ff01", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("b89fc178355660fe1c92c7d8ff11524702fad6e2255447946442356b00810101", value_0x08)

    }
    @Test
    fun `mulmod1_overflow2______8294f60d49c113d864d9f1ff088b3dac5c303c779f73e9ee934ee11a3cc18ef8`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600560027f80000000000000000000000000000000000000000000000000000000000000000960005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `sdiv2______79c54ebd501dc4a5284c46ffd0a42facdbef1a34512836a7f26e2176fbdeffcb`() {

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
               "600460000360026000030560005500",
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
    fun `sdivByZero1______76baef73ae1e349a2f010b815cd97545025424bb7f66e68343ba6a32a61477c7`() {

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
               "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6000030560005500",
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
    fun `expPowerOf256Of256_11______b7283c660d474721ff391d1b674d060f3df3bba27143fb2ac53410ffb54f115d`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600b6101000a6101000a600055600b60ff0a6101000a600155600b6101010a6101000a600255600b6101000a60ff0a600355600b60ff0a60ff0a600455600b6101010a60ff0a600555600b6101000a6101010a600655600b60ff0a6101010a600755600b6101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("e1440264b8ee0cea0218879ec55c33085514ff7f000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("29575fdce377b23043e489e358581474bc863187fa85f9945473a2be5889feff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("3df8c030ec521fb109c4d887dbbc14c7c9c9921b27058e3503971b60b18b00ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("67799740340daf4a30f000b68fb921f7aa6aff81000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("540a4e4635b40585e09ff10b63ffe310dd717fca5c0a51570091e25e378bff01", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("dbbaef5c49ffee61b08cde6ebc8dba6e9a62d56c2355d1980cb9e790bc8b0101", value_0x08)

    }
    @Test
    fun `divByZero_2______a3500f4f0814f3bee143c9c5ab0113f5a3ff24271f43cf76810d010628120997`() {

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
               "60076000600d040160005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000007", value_0x00)

    }
    @Test
    fun `smod7______4ba00d55aa3f200d20534a563295fac27f0f71cb759e4023c28ccd232df34e17`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6000030760005500",
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
    fun `addmodDivByZero3______ef4d1665ed7ade006cb7794b65613921f746a75c8e80618a7a75a822e9b3601e`() {

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
               "6001600060006000080360005500",
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
        assertEquals("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", value_0x00)

    }
    @Test
    fun `sdiv9______4b0bfe6e5cdfe250878764f6b989de91bb91b59d27ef1568d283763885e1f3d2`() {

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
               "600160016000030560005500",
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
        assertEquals("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", value_0x00)

    }
    @Test
    fun `exp4______93bc07a34b469b53c786a5a83e7a8a865f40ade78b97a7b521eeb9fb6db21e9e`() {

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
               "6000637fffffff0a60005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `mulmod1______818e2df6fe433776c8ebffdb2d137998afd7145f927300f69ae75b7395c193c0`() {

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
               "6003600260000360016000030960005500",
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
    fun `expPowerOf256_11______2c3bc67fa17ff7f04c6a53095108bca3be88f13df22bb885de3b63edb79274ef`() {

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
               "600b6101000a600055600b60ff0a600155600b6101010a60025500",
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
        assertEquals("0000000000000000000000000000000000000000010000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("000000000000000000000000000000000000000000f5365c4833ccb6a4c90aff", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000010b37a64bcfcf4aa5370b01", value_0x02)

    }
    @Test
    fun `mul6______1bec7cce7c541b5ff479c4a1d2413d1565c4482c0eaebb3126366099af7cdc10`() {

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
               "7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0260005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `expPowerOf256Of256_20______8bac38f4deddc9455492175a165d32c5d8c8fd3b521a41c45a03cd17b9350a40`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60146101000a6101000a600055601460ff0a6101000a60015560146101010a6101000a60025560146101000a60ff0a600355601460ff0a60ff0a60045560146101010a60ff0a60055560146101000a6101010a600655601460ff0a6101010a60075560146101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("18879ec55c33085514ff7f000000000000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("67e4797dc21f02ce4a7c52218c7dbea5d212e6c244e24f0ba4c08613c7ec00ff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("a1ce1a085f258785846939cc1d2e8725ac94ad4dff8913234e00679fb41400ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("f000b68fb921f7aa6aff81000000000000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("cce501857a1cb45473915a28082af950e0f78f7e2de68ce748adb661b3ec0101", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("3b2e28d274a16c08b58a23bad63bba6d7b09685769d1f68ca3873bedc8140101", value_0x08)

    }
    @Test
    fun `expPowerOf256_2______1a6817aa186629b86948a3a40b0d12602295f039335f815822f67e4d64fc2b0f`() {

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
               "60026101000a600055600260ff0a60015560026101010a60025500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000010000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("000000000000000000000000000000000000000000000000000000000000fe01", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000010201", value_0x02)

    }
    @Test
    fun `sub2______aa1d19b346d04380d9a1cefe28c384315a7cb138728b5c0ebbff5e88eb5e3065`() {

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
               "601760000360005500",
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
        assertEquals("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe9", value_0x00)

    }
    @Test
    fun `signextendInvalidByteNumber______55f8f483a85c319f8e284aa902a670b248ef974c28a64bf94e262f483cc70f57`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "62126af460500b600055",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000126af4", value_0x00)

    }
    @Test
    fun `expPowerOf256Of256_16______70cf94546a7bd655a0e8e00bce2262eb410570cd7a3f4c49698b264865262e76`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60106101000a6101000a600055601060ff0a6101000a60015560106101010a6101000a60025560106101000a60ff0a600355601060ff0a60ff0a60045560106101010a60ff0a60055560106101000a6101010a600655601060ff0a6101010a60075560106101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("82ec698218879ec55c33085514ff7f0000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("3122f4bcdf6dd8b265cd18eb6af28c879aed44a35e0bf59273e39e6c7ff000ff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("6a2b3bc87a02c29b9d27757df43047ecd0f15485270fca27417a701c701000ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("228fc9b0f000b68fb921f7aa6aff810000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("88e1259502eef93d46060aacc9e2ff506c734dade0b6714ab12d17e46ff00101", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("4a103813c12c12169b218296bb0a9eae80cf8d2b158aa70eb990f99480100101", value_0x08)

    }
    @Test
    fun `modByZero______17cf54f97886305270b6352d0b42b748b874ec7928b0cff53908d30a97c05aba`() {

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
               "600160006003060360005500",
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
        assertEquals("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", value_0x00)

    }
    @Test
    fun `divByNonZero3______bfc6fa5ba4671a032f24497cd767ea5b9ebe383494b1de8fcbefc06bdc197312`() {

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
               "600160010460005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `exp8______35b66ee6bdccf1dbf0943cd34b4d24dfd66454c113a15c0a318d96e35fc23aaa`() {

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
               "600060000a60005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `sdiv5______10f5aa0f1d7558a819f81e280bfee8b9e211bf1eed66198ee78f50f2ca6c8a23`() {

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
               "60016000037f80000000000000000000000000000000000000000000000000000000000000006000030560005500",
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
        assertEquals("8000000000000000000000000000000000000000000000000000000000000000", value_0x00)

    }
    @Test
    fun `expPowerOf2_16______0ff114aa433525d0a0f99084a1a74725c7653e5f6dcbf761cbd0465556f54974`() {

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
               "601060020a600055600f60020a600155601160020a60025500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000010000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000008000", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000020000", value_0x02)

    }
    @Test
    fun `expPowerOf256Of256_6______28c503e855e4822e308f6f3c6709cb02bc14e569ee8ab9e599938e378a2fe8d6`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60066101000a6101000a600055600660ff0a6101000a60015560066101010a6101000a60025560066101000a60ff0a600355600660ff0a60ff0a60045560066101010a60ff0a60055560066101000a6101010a600655600660ff0a6101010a60075560066101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("1948059de1def03c4ec35fc22c2bb8f2bf45dc33085514ff7f00000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("41f818a8e24eb6d7bb7b193b4f2b5fdcf4bd0d453f2ac3499d8830d391fa00ff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("ede6fe4a943dfb5d967a2b85d6728759d40d2ef0ae4bc28bbb1867f98c0600ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("083c936cbaad5de592badc2e142fe4ebd6103921f7aa6aff8100000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("57385019fe4e0939ca3f35c37cadfaf52fba5b1cdfb02def3866e8068bfa0101", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("810ac878bd98428f6be8c6426ba9f9da09e3e33bf4fe10bfa3f8b12c92060101", value_0x08)

    }
    @Test
    fun `expPowerOf256_31______e0302e77b2cd442b66d4f72b3d8991246234cf19b97b4c2bbc2cab17b6206acb`() {

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
               "601f6101000a600055601f60ff0a600155601f6101010a60025500",
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
        assertEquals("0100000000000000000000000000000000000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("00e2bfe95c5d7067567402dd9d7235fc088ac84eab8113bf8d7e3c288d2f1eff", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0120e30c8c1bb25c9d2219ea196c17ded3d775b231bbd28005b131fa90d11f01", value_0x02)

    }
    @Test
    fun `sdiv_i256min2______5340c13918d0bf4fc971ccf9b34ba471f3ee903a964c8cb7cefb3eff11865337`() {

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
               "60016000037f80000000000000000000000000000000000000000000000000000000000000006000030560005500",
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
        assertEquals("8000000000000000000000000000000000000000000000000000000000000000", value_0x00)

    }
    @Test
    fun `addmod2_1______563e92029c03dcd4d3d67e29d1d2752f3e4d67041196a1a091f4513c82f46c13`() {

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
               "6003600160066000030860036005600003061460005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `mulmoddivByZero1______3e6702097b3c3e0fe9becf1de13dc5e6095fc887e66cf286d183a3019994824f`() {

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
               "6000600160000960005500",
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
    fun `add4______c0d604cebc8b3877404f482a76f3502907f2161d3afa92bc7baaee2791bb15f1`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60010160005500",
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
    fun `addmodBigIntCast______805da3f1f884b5bdc6872643fa4bef2f29f15098ef1bbce633c00bd12edaa6ce`() {

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
               "600560017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0860005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `expPowerOf256_27______fb68f282f80610098116a5808a47a2c98e5c1e33a1415d0d3881e1bb4bf2f209`() {

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
               "601b6101000a600055601b60ff0a600155601b6101010a60025500",
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
        assertEquals("0000000001000000000000000000000000000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000e653d6571cdebb270b53c9d44c40bcd425165d5af1157d6ba11aff", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("00000000011c6ab2cdebf906306b38bbf7d6c52648e2d6bc63859e996e5f1b01", value_0x02)

    }
    @Test
    fun `expPowerOf256_26______2134d8211b9f93020848af3f17ec72e4ba8085bcfa27fbd0f1040a3ad464c8e3`() {

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
               "601a6101000a600055601a60ff0a600155601a6101010a60025500",
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
        assertEquals("0000000000010000000000000000000000000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("000000000000e73b116885641f4651a56f438fd08d61869cfa55465bd944e601", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000011b4f636a81778ea1c96f4cab2b998cbc26b00c572e7029451a01", value_0x02)

    }
    @Test
    fun `mulUnderFlow______a96c7a603d0f0e8b4c15f2957a14f805c59b9aa79e2f2837947c4c2ef10af453`() {

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
               "60010260015500",
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
    fun `mulmod3_0______856d73914958703b7e4654c1ef4a2dda7ecf8aac94ea0edba28cd9ffcec09410`() {

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
               "6002600360000360016005091460005500",
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
    fun `sdiv_i256min3______ad339e353945b7d1ad661b43eeb5ab05ea796d91194af691ce74ae4bc696ea43`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6000037fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0560005500",
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
    fun `addmod2_0______9021d5a8c133e1851d26c385f9087edaa727b4eeeea1d7e68d048d84828c8f9f`() {

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
               "6003600160066000030860036005600003071460005500",
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
    fun `stop______f16df0de68a86bccc62823dd2488c75cc8b997669b02c68ecc36736f35dad6f0`() {

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
               "00",
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
    fun `signextend_bitIsSet______c46832d606ce85476bebf2d4fa4fe606ea5345a91370345b77c154be3bd0f616`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "62122ff460000b600055",
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
        assertEquals("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff4", value_0x00)

    }
    @Test
    fun `expPowerOf256_30______bac66e2e3d9b1f47989e384089a0179800eb7971451be9af2362b0987a3c83ad`() {

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
               "601e6101000a600055601e60ff0a600155601e6101010a60025500",
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
        assertEquals("0001000000000000000000000000000000000000000000000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000e3a38ce946b71e74e8ebc966d90f0b139e66b560e1f5b542c0fd25b2e201", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("00011fc34942d8d9831a0811d8412aecf1e1f58031ffbc16699c151cddb31e01", value_0x02)

    }
    @Test
    fun `sdiv_dejavu______a9a984665d587171d23e7a2a90804bf287239efc196c89d093b68600d170bf5b`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("989680", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60056009600003058060005500",
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
        assertEquals("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", value_0x00)

    }
    @Test
    fun `expPowerOf2_8______e33211e91e3a8897fe0eb3fbdd06812680f0a404c89ffa72a3f56902b050729c`() {

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
               "600860020a600055600760020a600155600960020a60025500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000100", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000080", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000200", value_0x02)

    }
    @Test
    fun `expPowerOf256Of256_7______b09e5461e22115cbda9b98df5bbe359a549eaa2886e9630d4752905ac57c7a39`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60076101000a6101000a600055600760ff0a6101000a60015560076101010a6101000a60025560076101000a60ff0a600355600760ff0a60ff0a60045560076101010a60ff0a60055560076101000a6101010a600655600760ff0a6101010a60075560076101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("8bb02654111ad8c60ad8af132283a81f455c33085514ff7f0000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("a8f75c129dbb8466d6703a2a0b8212131b3248d70e2478862ac40fe17485feff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("5fd4d2de580383ee59f5e800ddb3f1717ceae03aede19d3dec5e5a69918700ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("c8624230b524b85d6340da48a5db20370fb921f7aa6aff810000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("287b58a5a13cd7f454468ca616c181712f5ed25433a7d5a894b6ced35f87ff01", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("09930d11ac2804fa977bf951593c8dff8498779cc0cdc5812a4fba2f98870101", value_0x08)

    }
    @Test
    fun `expXY______147d26f125116ea9be815b717cc45436ad4cc4573fe3feb3388f148043703e5a`() {

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
            "0x0000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000100000000000f"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6000356000556020356001556001546000540a60025500",
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

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("000000000000000000000000000000000000000000000000000100000000000f", value_0x01)

    }
    @Test
    fun `mulmod1_overflow4______7f82a1fac6095bda3ce083e8d673d2940b74eb11ca7ff8e16d9f0bb9acc504ed`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600560027f80000000000000000000000000000000000000000000000000000000000000010960005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000003", value_0x00)

    }
    @Test
    fun `sdiv4______f569f4af1d05099ca38e35ab0227c0c9699596d34823be8c750963706ade1761`() {

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
               "600460000360050560005500",
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
        assertEquals("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", value_0x00)

    }
    @Test
    fun `divByNonZero2______d5d5abde63b2241ebc02914027f91fed2a975c7b3a0c8bc8b2ce3b6d81551e35`() {

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
               "601860000460005500",
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
    fun `expPowerOf256Of256_17______51d18cac038852d7e04c82389115ae2421baaf6f83c1326b465bad8417b8ffbd`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60116101000a6101000a600055601160ff0a6101000a60015560116101010a6101000a60025560116101000a60ff0a600355601160ff0a60ff0a60045560116101010a60ff0a60055560116101000a6101010a600655601160ff0a6101010a60075560116101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("ec698218879ec55c33085514ff7f000000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("722ad218eb1995a2d257c4c06d8de993c203cfc8e3512df7d633e17e908ffeff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("8ac9b5ec08d74612cb29f941481d274b51721af2296207c0da8d24667f9100ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("8fc9b0f000b68fb921f7aa6aff81000000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("81d5ff63680841482299f3eab616446dcd336f537c0c565aa4112ab95d91ff01", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("9c6ca90dac4e97dea02ac969e8649ee9e6232e0c3f4797411151cb8f90910101", value_0x08)

    }
    @Test
    fun `sub3______eb7cc3225f34cc5f406daeca8e1bb787ca8acba883cd90ed3b321a9e3e406550`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000360005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `expPowerOf256_3______b4c86ff1c45d9976b4ff5bfeb14fffb986ea7ab2d74fd1e3b66c434b0b284b0c`() {

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
               "60036101000a600055600360ff0a60015560036101010a60025500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000001000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000fd02ff", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000001030301", value_0x02)

    }
    @Test
    fun `expPowerOf256Of256_21______3c58ce3f6e1fa9a48042be3d51141d71e47692c0ef861a9bd5ed93c093bbaed8`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60156101000a6101000a600055601560ff0a6101000a60015560156101010a6101000a60025560156101000a60ff0a600355601560ff0a60ff0a60045560156101010a60ff0a60055560156101000a6101010a600655601560ff0a6101010a60075560156101010a6101010a60085500",
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
        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("879ec55c33085514ff7f00000000000000000000000000000000000000000001", value_0x03)

        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("7fd07055ff50cdfe4b4bd9a15133d72d3607d92eb7ac81bac93db7ff4c93feff", value_0x04)

        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("665ac5c769e87f61d5993abc26522fbfca2734d76a63216b2d550d29c79500ff", value_0x05)

        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("00b68fb921f7aa6aff8100000000000000000000000000000000000000000001", value_0x06)

        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("1c93db67c9884bc694686d69a25a5d7ed089841d5ce147fdd7199ab00d95ff01", value_0x07)

        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("485053d8ff66be52036597520344fac87b6a305426a9e49221d3f934dc950101", value_0x08)

    }
    @Test
    fun `expPowerOf2_4______caaf04b1fe39b1190f26524877074bbef391fd77573d60ea148dc8b86ffa3a6c`() {

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
               "600460020a600055600360020a600155600560020a60025500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000010", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000008", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000020", value_0x02)

    }
    @Test
    fun `signextend_00______c603338732f470a8ce019cb6716e161afd018b9aedb9b2be5d2340579eb6508c`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600060000b60005500",
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
    fun `mod4______787d8e78c5ec67f50fa72623d7c58dc6f951c7828a12f5244aaa5e1b77e0a6d6`() {

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
               "600360026000030660005500",
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
    fun `expPowerOf256_10______2fa5466f3ed66ddb772c8d2c29409b298cec951d4a7e916845e1ea5700f44156`() {

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
               "600a6101000a600055600a60ff0a600155600a6101010a60025500",
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
        assertEquals("0000000000000000000000000000000000000000000100000000000000000000", value_0x00)

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000000000000000f62c88d104d1882cf601", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("000000000000000000000000000000000000000000010a2d78d2fcd2782d0a01", value_0x02)

    }
    @Test
    fun `mul7______5271c216a0485bdb24099169ea109b7359238e34a4b3de786c81839018c90d36`() {

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
               "7001234567890abcdef0fedcba09876543217001234567890abcdef0fedcba09876543217001234567890abcdef0fedcba0987654321020260005260206000f300",
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
    fun `sdiv8______7117a8f6f6575b80cfc6796e85c8187ba96ff9ef58ad71437df676bec010e026`() {

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
               "600160000360016000030560005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
    @Test
    fun `exp5______0985c5ebb0e9593ccca5915fee6a7e8a50b0bbf42e510db6a0df63e674549643`() {

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
               "60016101010a60005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000101", value_0x00)

    }
    @Test
    fun `mulmod0______4db3ce52686b76adcb6655d512c9a060bcd431f05fb137f4b235dc3c7c5597f9`() {

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
               "6002600260010960005500",
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
    fun `addmodDivByZero2______65ec5d3b6a27a2b89db89078fcff49f6fa3022f79c629d0e2e576e1e2713d590`() {

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
               "6000600060010860005500",
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
    fun `arith1______5832601e38094911f365508cc328361c9e367d96c0e7da2f7bc6fad15cda60d2`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0f4240", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6001600190016007026005016002900460049060016021900560150160030260059007600303600960110a60005260086000f300",
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
    fun `smod6______cce7ac589150731516b3dccabb5df19cdef2ab341e26c5cdb15ec4f7b7f249df`() {

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
               "7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6000030760005500",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x00)

    }
}

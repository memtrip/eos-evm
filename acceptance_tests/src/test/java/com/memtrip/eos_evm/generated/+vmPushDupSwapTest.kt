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
class vmPushDupSwapTest {
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
    fun `dup3______ffbec5daa4346b7014fe83eea8fec326343dca7c858cb492582cebf904596d2c`() {

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
               "60036002600182600355",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000003", value_0x03)

    }
    @Test
    fun `push13______82c508093067df9640d43d9d592a8465b5c573cabdbea966af90b327111ee47c`() {

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
               "6c33445566778899aabbccddeeff600355",
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
        assertEquals("0000000000000000000000000000000000000033445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `push6______2f8f1a3105c0471295a6e881129409c55dbb5c3f0570ce9e268cb55c653d273f`() {

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
               "65aabbccddeeff600355",
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
        assertEquals("0000000000000000000000000000000000000000000000000000aabbccddeeff", value_0x03)

    }
    @Test
    fun `swap4______c656dfa0b605868357430d3e4a68fd24622a5d2205185fad7c9d52b739d1c82a`() {

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
               "600460036002600160039355",
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
        // 0x04
        val value_0x04 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x04)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x04)

    }
    @Test
    fun `dup13______b217c381b320d9adc5f4fa3297cfff389e49b82ced991f966871a90bbb15f4f8`() {

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
               "600d600c600b600a6009600860076006600560046003600260018c600355",
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
        assertEquals("000000000000000000000000000000000000000000000000000000000000000d", value_0x03)

    }
    @Test
    fun `push29______098aa98643d1598b63ce8b6bc17cd5c3d81328fb915903ff945b6107562e104d`() {

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
               "7c33445566778899aabbccddeeff00112233445566778899aabbccddeeff600355",
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
        assertEquals("00000033445566778899aabbccddeeff00112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `swap2error______73dadbdf24729e84c233d101470fbacd1b3fdecd6be288832539dc82a0cd229e`() {

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
               "7f10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff60039155",
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
    fun `swap8______e4338c34353d9245ab1ada05ddb2e360c887f21a7cc5f23602c058fcd396b1c7`() {

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
               "6008600760066005600460036002600160039755",
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
        // 0x08
        val value_0x08 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x08)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x08)

    }
    @Test
    fun `push33______0241eb7779c0c9cfd4663fb61e3ffe404179dd97776580b7f56bb37c5e7b1cf5`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("04e200", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60656107d26204a0c763026921f4640bc5588eb165372d0f1dca6e661ba1d901961c71670c55f7bc23038e3868056bc75e2d630fffff69021e19e0c9bab24000016a085d1c6e8050f0ea1c71bd6b0688be36543f3c36e638e37a6c03d41f73d55d0d482ae55555376dc76810d0fe03c91964d31c71c6f46e615dd0360c07d931663b14e38e38b16f2da3f99955a3adcf27ebb1caaaaaaa6e7014ccba6a8bb1ed35bd86bf065c71c71c2b7109491c5d4781b79c9009de6bfb8e38e38de8720414a0f6fdec81304d4c563e740bffffffffa573118427b3b4a05bc8a8a4de8459868000000000017406eb15e7331e727940d4ac54b7cdca1c71c71c71bd750567a91c9fefc96ebaa626a22f98c5e638e38e38e37a76032abd16c5b68006e15d5aa307e383f4e55555555555377701a6427bdc4f0d58eab5f48a3ec67f64e21c71c71c71c6f478080dd0a0c9b9ff2c2a0c740b06853a0a980ee38e38e38e38b17903c679cb5e8f2f9cb3b5d6652b0e7334f746faaaaaaaaaaaaa6e7a01b873815917ebb2bf3b890a1af495d6235bae3c71c71c71c71c2b7b07ae4cca96e1a55dfa49c85ad3c3e60e426b92fb8e38e38e38e38de87c036018bf074e292bcc7d6c8bea0f9699443046178bffffffffffffffa57d0e7d34c64a9c85d4460dbbca87196b61618a4bd2168000000000000000017e05b901f48a5b994d6572502bc4ea43140486666416aa1c71c71c71c71c71bd7f047889870c178fc477414ea231d70467a388fffe31b4e638e38e38e38e38e37a00",
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
    fun `push25______485fa507fb3ad6f54117ac2eb76120cd3f021ef73298efaa30af4f448ba833f1`() {

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
               "78778899aabbccddeeff00112233445566778899aabbccddeeff600355",
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
        assertEquals("00000000000000778899aabbccddeeff00112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `swap10______01e47b0133697d8576aefe89d3578490fee02053ff74a2ab53aec88366fb473b`() {

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
               "600a60096008600760066005600460036002600160039955",
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
        // 0x0a
        val value_0x0a = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x0a)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x0a)

    }
    @Test
    fun `swap11______c0cb649e2d55545175badf469aec6fd7c79f779b503589de3953863609432692`() {

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
               "600b600a60096008600760066005600460036002600160039a55",
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
        // 0x0b
        val value_0x0b = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x0b)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x0b)

    }
    @Test
    fun `push24______ddcf80aeeb4e5d78918e3524bad70b4f7cfc19b054ca673712c8ba78ff9459fc`() {

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
               "778899aabbccddeeff00112233445566778899aabbccddeeff600355",
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
        assertEquals("00000000000000008899aabbccddeeff00112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `push32______cd433c75c88e83ab403482287e3daa6e743b70617162124d4e3e0280c0120149`() {

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
               "7f10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff600355",
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
        assertEquals("10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `swap9______0551c80109d14dc0115d9156721d39e6e15f518ad8deb828fc981d2f8c04a3d8`() {

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
               "60096008600760066005600460036002600160039855",
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
        // 0x09
        val value_0x09 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x09)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x09)

    }
    @Test
    fun `push28______221def684b3376e2d13446665b9d3d572a3f9a8edd28c16b110c036fc5c4df45`() {

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
               "7b445566778899aabbccddeeff00112233445566778899aabbccddeeff600355",
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
        assertEquals("00000000445566778899aabbccddeeff00112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `swap5______2f18299e0d68f22785e4b18363d840e892264a656d3a5d06f7bbd2517843db79`() {

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
               "6005600460036002600160039455",
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
        // 0x05
        val value_0x05 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x05)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x05)

    }
    @Test
    fun `dup12______c199c83e1a1d94e473fe2f6df835089eccfe077333e18c8ada5972507ec63aa0`() {

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
               "600c600b600a6009600860076006600560046003600260018b600355",
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
        assertEquals("000000000000000000000000000000000000000000000000000000000000000c", value_0x03)

    }
    @Test
    fun `push7______efec1ff88dd564f71279c68368ff95ac9e4afb13b14dd90a88489b353fff612c`() {

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
               "6699aabbccddeeff600355",
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
        assertEquals("0000000000000000000000000000000000000000000000000099aabbccddeeff", value_0x03)

    }
    @Test
    fun `push12______2841bfc001f926f620d5d0b8e859560360a9d941029bbe5118e79b02e492f7f2`() {

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
               "6b445566778899aabbccddeeff600355",
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
        assertEquals("0000000000000000000000000000000000000000445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `dup2______5a651ebacf9b474efe77288f5a1893a02465f1d3afccd25843e247bb07fa98bd`() {

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
               "6002600181600355",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000002", value_0x03)

    }
    @Test
    fun `dup9______c3a7e0b2c3720ef7873f9f3717cff7c78e4e0c5e3c052af059ba8d6d7ee20383`() {

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
               "60096008600760066005600460036002600188600355",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000009", value_0x03)

    }
    @Test
    fun `push19______d1608506c9b71fd03d47dc5aacd0231341d74d7cf605cf9d4ee6f832e773f79b`() {

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
               "72ddeeff00112233445566778899aabbccddeeff600355",
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
        assertEquals("00000000000000000000000000ddeeff00112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `push23______c538a83de57aa0a8176cfdd7250c539cfeab693619d76705a837fd4d5088ce5b`() {

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
               "7699aabbccddeeff00112233445566778899aabbccddeeff600355",
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
        assertEquals("00000000000000000099aabbccddeeff00112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `swap16______3053648762457d1d9ae7c6bb1f90f4ffe6c3a4f34d375cb9bc7a102cbbfe906a`() {

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
               "6010600f600e600d600c600b600a60096008600760066005600460036002600160039f55",
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
        // 0x10
        val value_0x10 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x10)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x10)

    }
    @Test
    fun `dup5______3be5a64799ae4daec47fde614e5cc574a6b012245d3aacdccc2bd86362029d8a`() {

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
               "6005600460036002600184600355",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000005", value_0x03)

    }
    @Test
    fun `push15______1164daffbb21e98d35880075a0ed1b258ca2edf43b938aec012db44469034034`() {

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
               "6e112233445566778899aabbccddeeff600355",
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
        assertEquals("0000000000000000000000000000000000112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `push32Undefined3______1b4b9199a0bb642c2f7f583ef2bdd863316c206148eb4380d90ed86e7d698478`() {

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
               "7f",
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
    fun `dup15______ae23e222524950299e086152abcba2e791a89d24301fbd130b8601e3b60dac52`() {

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
               "600f600e600d600c600b600a6009600860076006600560046003600260018e600355",
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
        assertEquals("000000000000000000000000000000000000000000000000000000000000000f", value_0x03)

    }
    @Test
    fun `swap2______25419aa849f088475924d2372210eb8bc1ea8ba069a39047308b46103a538d26`() {

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
               "6002600160039155",
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
        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x02)

    }
    @Test
    fun `push32Undefined2______46ffdbdc899754783b4e1e26701f96baa1cd8e182d9b14b67ea01379efa55f52`() {

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
               "7f0102030000000000000000000000000000000000000000000000000000000000600055",
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
        assertEquals("0102030000000000000000000000000000000000000000000000000000000000", value_0x00)

    }
    @Test
    fun `dup14______c9955b3c31b9dbcbf701dc8c7aff07dd6bd0f573e558d06304086d92f644cd8c`() {

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
               "600e600d600c600b600a6009600860076006600560046003600260018d600355",
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
        assertEquals("000000000000000000000000000000000000000000000000000000000000000e", value_0x03)

    }
    @Test
    fun `swap3______d3ecc9280969f06f74044067892d67574ed0d02876118e5b1e573bc03bb00167`() {

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
               "60036002600160039255",
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

    }
    @Test
    fun `swapjump1______46d77f9bed1d179a30e85ffe9b20713c248bbf6f2e986f0ab2d68dc1d5e0f007`() {

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
               "600560026001600c575050005b9060016116575050005b035b0360005260016003611ff3",
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
    fun `push1______1e602609c8a096b1f417df763c9bfade0e0cde8b0e6b5b0dcf4c448b83284a23`() {

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
               "60ff600355",
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
        assertEquals("00000000000000000000000000000000000000000000000000000000000000ff", value_0x03)

    }
    @Test
    fun `push14______dc1ba5b2b3f9f00f4f89a76789e3f3d3e4b1b084da0ff7c87b4c4bfed6072a49`() {

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
               "6d2233445566778899aabbccddeeff600355",
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
        assertEquals("0000000000000000000000000000000000002233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `dup4______dca065d1abc9a081abe284db30087edcdaf9dd9dcbc550db9614e9b38b3292e0`() {

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
               "600460036002600183600355",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000004", value_0x03)

    }
    @Test
    fun `push22______a043c1cb21614ce8a0addc5254d338625f3213d836e1fb9dbd8c23047d38857b`() {

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
               "75aabbccddeeff00112233445566778899aabbccddeeff600355",
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
        assertEquals("00000000000000000000aabbccddeeff00112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `push18______af2bc3ddba25c1fccca593f1cb52bbbaf728308d51d236468ae5d07362e28bda`() {

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
               "71eeff00112233445566778899aabbccddeeff600355",
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
        assertEquals("0000000000000000000000000000eeff00112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `dup8______7658194bff0779f626e5ac4c8641f690ad2b66369cd2eea22c5755f377fc3586`() {

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
               "6008600760066005600460036002600187600355",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000008", value_0x03)

    }
    @Test
    fun `swap14______5dd3396b19f79d64eab79f487388ac71516881c7c05cdc4c33dce857cac235a0`() {

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
               "600e600d600c600b600a60096008600760066005600460036002600160039d55",
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
        // 0x0e
        val value_0x0e = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x0e)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x0e)

    }
    @Test
    fun `push21______1f575d9a50eb429faf04328f3f095c833c781929482dbc7fd5efc4fd6c57db43`() {

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
               "74bbccddeeff00112233445566778899aabbccddeeff600355",
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
        assertEquals("0000000000000000000000bbccddeeff00112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `push2______3e1595d9538a95e2163be318d2bd0ef54f8e7bf845d73c7301d214450552b580`() {

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
               "61eeff600355",
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
        assertEquals("000000000000000000000000000000000000000000000000000000000000eeff", value_0x03)

    }
    @Test
    fun `push17______62f3f74c3c33982afd94c5e8bc8037c0ff58d7dbb8717e241a9fd76a3382b06c`() {

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
               "70ff00112233445566778899aabbccddeeff600355",
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
        assertEquals("000000000000000000000000000000ff00112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `dup7______a679458119bd67a64dfdf09018267567f00846cddb7a8638e5336d05b8ad500f`() {

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
               "600760066005600460036002600186600355",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000007", value_0x03)

    }
    @Test
    fun `push32FillUpInputWithZerosAtTheEnd______317c858435522458091fe69f56a74a5d27d0e78c8d6198b1b210d0324e17ed7a`() {

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
               "7fff10112233445566778899aabbccddeeff00112233445566778899aabbccdd",
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
    fun `dup6______1d224090ae0ffecc37a7aa03c4000f8df50edfc6402259456feaafbca2a831c5`() {

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
               "60066005600460036002600185600355",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000006", value_0x03)

    }
    @Test
    fun `push16______c306bef2d2b972117b64c2d8dd7a6793dd4398a0eb4604733c269f57c02b5b29`() {

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
               "6f10112233445566778899aabbccddeeff600355",
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
        assertEquals("0000000000000000000000000000000010112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `push3______dae54a191aa6c65b724677f953d0298448d525a948e74992e76b026a9b1bef0b`() {

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
               "62ddeeff600355",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000ddeeff", value_0x03)

    }
    @Test
    fun `dup16______c637436a97103631bcd248438cf1cd9e1869ad9a7d824be627040a44d05194f4`() {

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
               "6010600f600e600d600c600b600a6009600860076006600560046003600260018f600355",
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000010", value_0x03)

    }
    @Test
    fun `swap1______4b1f4fb2021c8954cadc02bd42eeaf1e5d8abe3457a29dfe5b63e226be356709`() {

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
               "7f10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff60039055",
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
        // 0x10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff
        val value_0x10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), "10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff".toHexBytes())
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000003", value_0x10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff)

    }
    @Test
    fun `push32Undefined______2e73291165e52fcab6403f76af9e132a3b8b0c63266db4153057c8e207e1a9a7`() {

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
               "7f010203600055",
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
    fun `push20______5cd6597f8e845bae7327014e1f8e6030a1f405bee91b735175fbb8696c3c0739`() {

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
               "73ccddeeff00112233445566778899aabbccddeeff600355",
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
        assertEquals("000000000000000000000000ccddeeff00112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `swap15______6aa56f1487713a36ef3cf8277727cc6e4f2d0ec0cfcdd768cd6497fa5f9bc0d5`() {

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
               "600f600e600d600c600b600a60096008600760066005600460036002600160039e55",
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
        // 0x0f
        val value_0x0f = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x0f)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x0f)

    }
    @Test
    fun `swap6______82c8e762ae4b14795406ead33eeb6fc974b27a548f2147f71cad883397a59a2c`() {

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
               "60066005600460036002600160039555",
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
        // 0x06
        val value_0x06 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x06)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x06)

    }
    @Test
    fun `dup11______bb20a4ebe22c00053206876bbc379aa62426243bfd76676408b79eaab6c7cf27`() {

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
               "600b600a6009600860076006600560046003600260018a600355",
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
        assertEquals("000000000000000000000000000000000000000000000000000000000000000b", value_0x03)

    }
    @Test
    fun `push4______97b8e0ae332e78ec1a540dff28dccbf40717819f3302f0ebe1c55312570bacaa`() {

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
               "63ccddeeff600355",
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
        assertEquals("00000000000000000000000000000000000000000000000000000000ccddeeff", value_0x03)

    }
    @Test
    fun `push11______0369f5a70676fce801a45b8e8123fc4013804fcc8849b89495fd050e9e825a81`() {

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
               "6a5566778899aabbccddeeff600355",
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
        assertEquals("0000000000000000000000000000000000000000005566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `dup2error______68e9e5fd7b5457982a66c559006e8e7f39bf8e8b957320eb0b937025f7825bb6`() {

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
               "7f10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff81600355",
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
    fun `dup1______5bfc41de291bb4a8a82aa44729ca5f0cbac364757517087d323f88636baff1ca`() {

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
               "7f10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff80600355",
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
        assertEquals("10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `swap12______a3cbb81c3102f763c7de4501c17f1a55b52df2e34222faf2f7178e0803c66c64`() {

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
               "600c600b600a60096008600760066005600460036002600160039b55",
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
        // 0x0c
        val value_0x0c = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x0c)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x0c)

    }
    @Test
    fun `push27______8377f7c247cbf80e75f7eb346c8c827e8072e890a52ec4a2a1bb6203bbc1e472`() {

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
               "7a5566778899aabbccddeeff00112233445566778899aabbccddeeff600355",
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
        assertEquals("00000000005566778899aabbccddeeff00112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `push31______735be1309a605b58545aae0d79c79302dc7092ed98d2ffbbf7974b7d8c457efc`() {

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
               "7e112233445566778899aabbccddeeff00112233445566778899aabbccddeeff600355",
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
        assertEquals("00112233445566778899aabbccddeeff00112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `push8______c2a142fc39b38a9200d1a9f3067c0da535eefe69224f11a657c20c74fce1ced4`() {

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
               "678899aabbccddeeff600355",
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
        assertEquals("0000000000000000000000000000000000000000000000008899aabbccddeeff", value_0x03)

    }
    @Test
    fun `push9______8baf143f1db7e22bc6e0ea1d4fa42ee1163c7d32670859048d8681bd48e5078d`() {

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
               "68778899aabbccddeeff600355",
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
        assertEquals("0000000000000000000000000000000000000000000000778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `push30______8e5c10b44c88a7d3ab12b18bbd59ce1a26c2c33a14cee51eaa593182bf6a9095`() {

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
               "7d2233445566778899aabbccddeeff00112233445566778899aabbccddeeff600355",
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
        assertEquals("00002233445566778899aabbccddeeff00112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `push26______57cfa6e43b13e93abb0ab4b19fa3a760e458e3351cbc98cc13cb9854168665a1`() {

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
               "7966778899aabbccddeeff00112233445566778899aabbccddeeff600355",
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
        assertEquals("00000000000066778899aabbccddeeff00112233445566778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `swap13______29d73949c4eb8bbd3d76b1966d35f44d5b614e22db594b81e254b72c81e2cb77`() {

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
               "600d600c600b600a60096008600760066005600460036002600160039c55",
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
        // 0x0d
        val value_0x0d = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x0d)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x0d)

    }
    @Test
    fun `push10______7255dda5284e2ccb79bea433e0d469866d3d0d6c8ff54d15d746f49ac54ac1ca`() {

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
               "6966778899aabbccddeeff600355",
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
        assertEquals("0000000000000000000000000000000000000000000066778899aabbccddeeff", value_0x03)

    }
    @Test
    fun `push5______da12dc57ed8e0716195a783b28b209b7e37a4b4a0ce8e506a97b77737391161d`() {

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
               "64bbccddeeff600355",
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
        assertEquals("000000000000000000000000000000000000000000000000000000bbccddeeff", value_0x03)

    }
    @Test
    fun `swap7______f1b6c287d52c5f225d3641e8f98f67ee3087852de166deddf5243bf03b4a2440`() {

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
               "600760066005600460036002600160039655",
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
        // 0x07
        val value_0x07 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x07)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x07)

    }
    @Test
    fun `dup10______8e3522bab36caaa65bc9134418d5823d0b14b076854b1f25f416e8b800ec2e6e`() {

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
               "600a60096008600760066005600460036002600189600355",
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
        assertEquals("000000000000000000000000000000000000000000000000000000000000000a", value_0x03)

    }
    @Test
    fun `push1_missingStack______68300bcd11c1214486f328bbd4a2cad61f88fc685c7fa480ee0c36e4f1b0789e`() {

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
               "60",
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

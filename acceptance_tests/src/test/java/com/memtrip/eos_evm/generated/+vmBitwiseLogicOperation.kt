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
class vmBitwiseLogicOperation {
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
    fun `slt1______1d6cfd4be348f47f26815c96a9805d11e21f2e3c9cbce069941b1ebd1ca7cd8d`() {

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
               "600260000360001260005500",
               TransactionContext(
                   newAccountName,
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
    fun `or2______8de97b69135dab0235ffad5d98bdbecb9e87d3621a1eaec632ae170419950544`() {

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
               "600160031760005500",
               TransactionContext(
                   newAccountName,
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
    fun `sgt3______9d66ea591c184ba2295ed3f5dd0e9e0e171b312b9bf254dbf8965b540842aaf4`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60001360005500",
               TransactionContext(
                   newAccountName,
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
    fun `xor2______a7e6da72f6240cfa040d4a40143e7c984a114174dfae0635a5671b035080ee17`() {

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
               "600160031860005500",
               TransactionContext(
                   newAccountName,
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
    fun `byte4______8948584057cf91d218252142512f207da22edbf1d782a4c1c2cbc58a5470a228`() {

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
               "6780402010080402016004601f031a60005500",
               TransactionContext(
                   newAccountName,
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

    }
    @Test
    fun `not5______53348b9719a8627a969e72f9ed933258544249355a0a3f97331dcb9d9db969f0`() {

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
               "60006000031960005500",
               TransactionContext(
                   newAccountName,
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
    fun `eq2______b2d716396d12dc97180b8152b4c0aaff27210722d37d08e7c06143efbfd2e513`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1460005500",
               TransactionContext(
                   newAccountName,
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
    fun `byte8______033b3fdc6a35ea782e565b9d1c74ff224fe6028523c5898e4a945c4ba7e12240`() {

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
               "678040201008040201601f601f031a60005500",
               TransactionContext(
                   newAccountName,
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
    fun `and0______c40353c65b979562862dd7d04b62d69fc7c38c645428e93f461f1cac359e3f5e`() {

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
               "600260021660005500",
               TransactionContext(
                   newAccountName,
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
    fun `and1______92e40f17e0a9077630bf0cef49de526ce0f270ff4a2da281d82c94eae0456946`() {

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
               "600160021660005500",
               TransactionContext(
                   newAccountName,
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
    fun `byte9______101bcc95959a1c5793a35408c8da6a591e1fa1c83d257ecd74ad3ac67697baf8`() {

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
               "6780402010080402016020601f051a60005500",
               TransactionContext(
                   newAccountName,
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
    fun `not4______b7deb3aa18fcfa197c84e6cf00f10d0ad755f1e21664eb59c75d978a6ea51f04`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6000031960005500",
               TransactionContext(
                   newAccountName,
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
    fun `byte5______f42859aee6a2fcaaab7b2aebd6a0ad6478ec246f3008fa8132709ea9812c20cb`() {

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
               "6780402010080402016005601f031a60005500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000020", value_0x00)

    }
    @Test
    fun `xor3______f1215b33b0028138337bf498d00b043f603594d6286c8ad80259043d6c67e927`() {

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
               "7f0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1860005500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("fedcba9876543210fedcba9876543210fedcba9876543210fedcba9876543210", value_0x00)

    }
    @Test
    fun `sgt2______47bbf89217496d523294ed357657c4f83f9496b451b7d06df0ad5716a024d9b8`() {

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
               "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1360005500",
               TransactionContext(
                   newAccountName,
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
    fun `or3______92d0f6fe174fa59b8d0dcc4ff4bde628c1a662f4b6450bf1b12e23c17cf0823f`() {

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
               "7f0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1760005500",
               TransactionContext(
                   newAccountName,
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
    fun `slt0______3ae833c8da69980fb07ef8ed5841ce0f435ea2367ef01e33119901c1e0859507`() {

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
               "600060026000031260005500",
               TransactionContext(
                   newAccountName,
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
    fun `not3______9d15a0f5f891e35d991e57396be8d96d359ac379dd770bce0a52586a51c036e6`() {

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
               "60026000031960005500",
               TransactionContext(
                   newAccountName,
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
    fun `lt0______7215a9bba3f52209ee4d88c501e1d5be9dadf227c40db1c93d422cd55916921e`() {

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
               "600060026000031060005500",
               TransactionContext(
                   newAccountName,
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
    fun `gt2______dd0aaffde364cf9a80df42f854be651e9da858052e279559a22e7a429165eded`() {

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
               "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1160005500",
               TransactionContext(
                   newAccountName,
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
    fun `or4______2d1d9d971e4387390bd025e68ccc6cf5a417999ba23fc43bc1938b8aaa88643d`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee1760005500",
               TransactionContext(
                   newAccountName,
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
    fun `xor4______21b5fc2a9794b3dee29f63945511c0709a86759cb04ea70be1e06dafcec18688`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee1860005500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("1111111111111111111111111111111111111111111111111111111111111111", value_0x00)

    }
    @Test
    fun `byte2______4dcb8fb06db558c6f87712d03c87a27770c760c4d366c12e2a189f5dfef5e48e`() {

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
               "6780402010080402016002601f031a60005500",
               TransactionContext(
                   newAccountName,
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
    fun `byte3______972a37042584365726f573826465dc1fc589376ab30b4c30e5a3470f093d8497`() {

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
               "6780402010080402016003601f031a60005500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000008", value_0x00)

    }
    @Test
    fun `xor5______b13cfb27b0dc5d75f153db558108c111150b4ab9c734d2bc3b817eba8b1877f7`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeefeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee1860005500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("1111111111111111111111111111101111111111111111111111111111111111", value_0x00)

    }
    @Test
    fun `sgt4______b735292ef446cbdb965a0a49421380e1ad4195604f1ad2f7c6e750eead25d669`() {

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
               "600360000360056000031360005500",
               TransactionContext(
                   newAccountName,
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
    fun `or5______8f4e889a3136fdb23e65823f863a2147b0783839d6211850cded6bec1df40751`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeefeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee1760005500",
               TransactionContext(
                   newAccountName,
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
    fun `gt3______6c76635dc0b46eb74b3832016952f70d948da050cd1e4f469cfa39011bf3c4e2`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60001160005500",
               TransactionContext(
                   newAccountName,
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
    fun `lt1______08c5a13db7eb864c1318d8c79b78b4ba2c494bd4d49085b5a96c1454283fff7a`() {

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
               "600260000360001060005500",
               TransactionContext(
                   newAccountName,
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
    fun `not2______7ab3647221dd6c8b42dc5b515020c5be134a45efd012bc74a28a5eda456ad0a1`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1960005500",
               TransactionContext(
                   newAccountName,
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
    fun `and4______2f95852d29395f28f29f09c3968858179b97b062caa4e388f2ffdc2c62add796`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee1660005500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee", value_0x00)

    }
    @Test
    fun `gt0______19eaff4bc4babcc2c71930986a3ac95aa7dfd15408a096da93faab8e8d8acd1c`() {

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
               "600060026000031160005500",
               TransactionContext(
                   newAccountName,
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
    fun `iszero0______cb2362cbec805fbe2158b543915ea93b9f3e7eecbdea7f39d3afdc71b3c575fe`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1560005500",
               TransactionContext(
                   newAccountName,
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
    fun `lt2______a539298bf110f5763a46ebcd8955a53dfbfee4bec0e903a0bc2c4d0124296f35`() {

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
               "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1060005500",
               TransactionContext(
                   newAccountName,
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
    fun `not1______30d49c47d08666377d743e9c50ccd2a33a3a0b06b0c1f16a49f36f71f6f54fad`() {

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
               "60021960005500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffd", value_0x00)

    }
    @Test
    fun `byte0______6e4a3dbcba9210a7e37ba449a4d5f203b6bfae7876221bc9be4293dcd540242c`() {

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
               "6780402010080402016000601f031a60005500",
               TransactionContext(
                   newAccountName,
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
    fun `slt4______1c6ad637c774fc865fc4b308c6637dfc06b3231c5cd82ac7f146b20623f47352`() {

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
               "600360000360056000031260005500",
               TransactionContext(
                   newAccountName,
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
    fun `byte1______421ed8cfbf542717eb2af3a11847a4942f8b07dd9ae7a1161bfd0c2fd440dfe6`() {

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
               "6780402010080402016001601f031a60005500",
               TransactionContext(
                   newAccountName,
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
    fun `not0______dd7ac25c42a66a8adb490cc8301bf791f93bbb99f7e6af8adcc5d21263079470`() {

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
               "60001960005500",
               TransactionContext(
                   newAccountName,
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
    fun `lt3______bee2688e5cacde141c463f294d987f3a1ab75cb3b6bbd5137ddeb8bf6d9c9b33`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60001060005500",
               TransactionContext(
                   newAccountName,
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
    fun `iszero1______c4e0f9e2cd35e935633730400eab95c14a7d180f208ad4bd71f6a9a1695965e3`() {

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
               "60001560005500",
               TransactionContext(
                   newAccountName,
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
    fun `gt1______4b02207ff24a59f8691d2dce3a1b155f4b392565f0964b7a3d37f4ea3207aec6`() {

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
               "600260000360001160005500",
               TransactionContext(
                   newAccountName,
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
    fun `byteBN______bcd1d24d868f03ceb7f413c6e7edb6f4f9b4ff22819405de2aee318e3931442b`() {

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
               "641234523456601f1a800160015500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("00000000000000000000000000000000000000000000000000000000000000ac", value_0x01)

    }
    @Test
    fun `and5______4cb06bd9dace9c6556db7d8831b587aecebf5fc56342a0e02fe58b4b301e7f5c`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeefeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee1660005500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("eeeeeeeeeeeeeeeeeeeeeeeeeeeeefeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee", value_0x00)

    }
    @Test
    fun `byte6______7cb8fb35460672dd82118bba6feab41877437d20b6f838de9a80c6387c919dbb`() {

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
               "6780402010080402016006601f031a60005500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000040", value_0x00)

    }
    @Test
    fun `xor0______787214bbdcaa5700693cba6ac538c4ee61d47ac2be4dbe8bd3f1a92db6b14812`() {

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
               "600260021860005500",
               TransactionContext(
                   newAccountName,
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
    fun `sgt1______815df3b7b40f38bd552eb8d276a42ab8d95bdb4aeff80ee46f36bb41416f218e`() {

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
               "600260000360001360005500",
               TransactionContext(
                   newAccountName,
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
    fun `or0______a86c21e32601782988ab644fc718ad330defe02bcba039d08be2f1c57311c996`() {

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
               "600260021760005500",
               TransactionContext(
                   newAccountName,
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
    fun `slt3______e53415c8ebbaf76706e5f74fede5948ea03b6c87aa5cc79ad9bb195f919d14bc`() {

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
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60001260005500",
               TransactionContext(
                   newAccountName,
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
    fun `and2______d2ed664b2c711297008dca673e71d3505b287410f65fbfeec95dd3351964eaec`() {

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
               "600160031660005500",
               TransactionContext(
                   newAccountName,
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
    fun `byte11______4d8ccc3641222e01d4ce431ad66dd5dcd4976df2db62e2e5df732f7e9198bc1d`() {

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
               "67804020100804020160001a60005500",
               TransactionContext(
                   newAccountName,
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
    fun `iszeo2______30cd9235c67be31f04b119305b0985b34787110d3483b38c3b507702bc6a5ebc`() {

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
               "60026000031560005500",
               TransactionContext(
                   newAccountName,
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
    fun `eq0______778aa850729f70c994647bdb1487432b38b2d1ade6138036bed1509c99ba5118`() {

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
               "600360000360056000031460005500",
               TransactionContext(
                   newAccountName,
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
    fun `eq1______0ee1cb1ebb52b04e7317d73122b0572f6baba0fa7976130af684ab07adaa19ad`() {

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
               "600060001460005500",
               TransactionContext(
                   newAccountName,
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
    fun `byte10______f32ca6574789bd3749a1dea65ea6c64bf10eb7b642e60f0532ee858f9e3593b1`() {

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
               "6780402010080402017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1a60005500",
               TransactionContext(
                   newAccountName,
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
    fun `and3______eb1141f933d73bc23b99d298d8d051b85a3184777aa17ab0e5c469bbf6028365`() {

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
               "7f0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1660005500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef", value_0x00)

    }
    @Test
    fun `slt2______1ba9695a1388e9a583ea16aa528c0f792f67998f6f948eaa69e5e73b63c9a1cb`() {

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
               "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1260005500",
               TransactionContext(
                   newAccountName,
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
    fun `or1______6540302402b45c7e3680fdc1d63dd4b664c0ee07797e8018b17967bd783c9e8d`() {

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
               "600160021760005500",
               TransactionContext(
                   newAccountName,
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
    fun `sgt0______1142a1998c184cb7cd1cd0cba8ade456c3920e8ab41c0edfcc5031d191d39e54`() {

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
               "600060026000031360005500",
               TransactionContext(
                   newAccountName,
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
    fun `xor1______788046c24f986a6794abc4424c79b69f3e4388a4a5abad78db207a718eb1d988`() {

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
               "600160021860005500",
               TransactionContext(
                   newAccountName,
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
    fun `byte7______357ab8dcab670e5791bca70f9ec7415e130602edeaa571645ae01fb43bf17ffb`() {

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
               "6780402010080402016007601f031a60005500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000080", value_0x00)

    }
}

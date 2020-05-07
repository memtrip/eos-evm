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
class vmIOandFlowOperations {
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
    fun `jumpAfterStop______c56c01dc36ed0d73f7a7a687a3166f1462b2ca885e784f0653c6ee827dad0bea`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6006560060015b6002600355",
               TransactionContext(
                   newAccountName,
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
    fun `JDfromStorageDynamicJump0_withoutJumpdest______ff145a7549a17954a66e2ed3f4181df8dc8e3ba1207699755a9fb22825e788c9`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val store1 = faultTolerant {
            setupTransactions.sstore(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount,
                AccountStateKey.create(accountIdentifier.pad256(), 0x00),
                "0000000000000000000000000000000000000000000000000000000000000004"
            ).blockingGet()
        }
        assertEquals(202, store1.statusCode)

        // and when
        val transaction = EthereumTransaction(
            1 + 1,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6023600760005401566001600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `DynamicJumpStartWithJumpDest______ee9cfd46e0f9fa5901e8614056c6889ea24239ac319dc374eeae27a5f0ee79e4`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "5b586000555960115758600052596000575b58600055",
               TransactionContext(
                   newAccountName,
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000012", value_0x00)

    }
    @Test
    fun `jump0_jumpdest0______a20c7dfce4431144ada47d59ba7c6ae10d2bf67130de793a84cf2fe278e48106`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "602360075660015b600255",
               TransactionContext(
                   newAccountName,
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000023", value_0x02)

    }
    @Test
    fun `sstore_load_1______765047074018a481f0c988024c0b5ce28ab9f266c464f745e1c5d4405edd2f20`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60ff60005560ee600a5560645460145500",
               TransactionContext(
                   newAccountName,
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

        // 0x0a
        val value_0x0a = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x0a)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000000000000000000000000000000000ee", value_0x0a)

    }
    @Test
    fun `loop_stacklimit_1020______f43d3ab51b9e9e5f6e138995a13174b48ad8b8dc50167a967ae5862cddf45acf`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("03fc", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6000345b60019003906001018180600357600052600152600059f300",
               TransactionContext(
                   newAccountName,
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
    fun `msize0______9e555f37f64db37922067720bead2dd2e08aba87193acf10356cde88135ad378`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60ff6000525960005500",
               TransactionContext(
                   newAccountName,
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
    fun `jumpiToUintmaxPlus1______02db1b3f7910ec581f38dc51c70441e5191ff22ba79ff3895ab6ade7879df61a`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6001640100000009575b5b6001600155",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `mstore8WordToBigError______c8540f8b9c00d93e232cd87af2d638d3e1210b122773e458a68dfa8e23dcebe1`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60015360015160015500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("ff00000000000000000000000000000000000000000000000000000000000000", value_0x01)

    }
    @Test
    fun `jumpInsidePushWithJumpDest______f59bdcf39b348dfa4247ddf0e2dce382419060e793436c2bee6fe654e0010589`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600456655b6001600155",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `DynamicJump_value3______bfe1ded01fe9866ceac9754126b8b719c9c7949e0273dccf8f4376af8c3daf8a`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("1b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60016002600334565b5050600052596000f35b50600052596000f35b600052596000f3",
               TransactionContext(
                   newAccountName,
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
    fun `indirect_jump1______114d1db98c797e1220d7816e71eca07a06a1e5ce33965501684bd5192ab15e62`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600460030156005b6001600052596000f300",
               TransactionContext(
                   newAccountName,
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
    fun `JDfromStorageDynamicJump0_AfterJumpdest______36e90851ec41aaf2c622208c2a6c82946904d6a269fc42ba23e714d7e53b93e6`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val store1 = faultTolerant {
            setupTransactions.sstore(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount,
                AccountStateKey.create(accountIdentifier.pad256(), 0x00),
                "0000000000000000000000000000000000000000000000000000000000000004"
            ).blockingGet()
        }
        assertEquals(202, store1.statusCode)

        // and when
        val transaction = EthereumTransaction(
            1 + 1,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60236008600054015660015b600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `DynamicJumpJD_DependsOnJumps1______a866a3f5c05ee4a74cadf69fe61eb89134f55825a811ef402813d5efe8a1cf5b`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600a436006575b5660015b6001600155",
               TransactionContext(
                   newAccountName,
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x01)

    }
    @Test
    fun `DynamicJumpi0______7b66888012ce1da9e7eecf98afff4cb5076da27a2139f0c015c486c5dd1e307a`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "602360016009600301576001600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `DynamicJumpi1______88fada7d17305137713081d427d8a809653285854ace3cb48b7d1be79a5c4cf8`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "602360006009600301576001600255",
               TransactionContext(
                   newAccountName,
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
    fun `DynamicJumpJD_DependsOnJumps0______35e1e4661472c1c09c3fb7b49d6c2152bb1462db53e8779273a6e209ad7a1d36`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6009436006575b566001",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `DynamicJumpi1_jumpdest______1793c25430bf499a8731cbd2fad303c0b0c06c1a65fb6a37cdc40d4b27d36d70`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60236001600a6003015760015b600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `DynamicJumpiOutsideBoundary______ef891d41934fb1df9cec7a86af76c08220e4425dc81eaacf3f98a29022dd9786`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60017ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0600301576002600355",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `codecopyMemExp______9d977110436c06a4010256e286e6e1f3eb65a599e545086a690e03f000c19ba4`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("01f4153d80", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60ff60ff630fffffff630fffffff39",
               TransactionContext(
                   newAccountName,
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
    fun `DynamicJump_value2______fbf1521165f2da9e707f00eaf6de93114257267a6947fb3481f5834927f43dd8`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("12", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60016002600334565b5050600052596000f35b50600052596000f35b600052596000f3",
               TransactionContext(
                   newAccountName,
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
    fun `return1______bab1e94d8a901000f2796e0e31d8a244afd3faf85d1b3d0e9f24bd7020c05fd0`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6001620f4240f300",
               TransactionContext(
                   newAccountName,
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
    fun `mloadMemExp______a31781825952e4df963c4579565b3503396dbdbba5c342cbe047d27f6001a800`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("800570", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "630fffffff51",
               TransactionContext(
                   newAccountName,
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
    fun `jumpInsidePushWithoutJumpDest______ec4107598a735516122b840270a53d62166d53bd07f2052abfda6f30cd319cae`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60055661eeff",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `JDfromStorageDynamicJumpifInsidePushWithoutJumpDest______6dcd5e334a0317da47bde4ac9170a9cfde27e925978b985b13cac777e026806e`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val store1 = faultTolerant {
            setupTransactions.sstore(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount,
                AccountStateKey.create(accountIdentifier.pad256(), 0x00),
                "0000000000000000000000000000000000000000000000000000000000000004"
            ).blockingGet()
        }
        assertEquals(202, store1.statusCode)

        // and when
        val transaction = EthereumTransaction(
            1 + 1,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60016007600054015761eeff",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `jumpOntoJump______90008ead856190f530fe38116e33f2ab265b6ea5629bb133a89fba8abff8ca81`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "565b600056",
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
    fun `DynamicJumpifInsidePushWithJumpDest______49008282fb062cc4f6bc8cc910f36ec52c24eb25a2492cc0b7838b07c34e8f18`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6001600660030157655b6001600155",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `JDfromStorageDynamicJumpInsidePushWithoutJumpDest______18b34f7104d36e5dad3b5a586ab546bccbc3b6dcbdd93c9275a7634f6b71422b`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val store1 = faultTolerant {
            setupTransactions.sstore(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount,
                AccountStateKey.create(accountIdentifier.pad256(), 0x00),
                "0000000000000000000000000000000000000000000000000000000000000004"
            ).blockingGet()
        }
        assertEquals(202, store1.statusCode)

        // and when
        val transaction = EthereumTransaction(
            1 + 1,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6005600054015661eeff",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `msize1______046af0bbe820d5766b5c4ee12cce080cc013231325b80b8e142c3a1503d21443`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "64ffffffffff6000525960005500",
               TransactionContext(
                   newAccountName,
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
    fun `DynamicJumpiAfterStop______ea1f4950f0f0d80128476b5bd232041bef84f59c5024ce5da355d6a83ce80c37`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60016008600301570060015b6002600355",
               TransactionContext(
                   newAccountName,
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
    fun `jumpHigh______11bedf3a9e6f6bdee4dbc546cd4b2dd9d83c0293d3ed8f038ed95d2e99b60185`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "630fffffff565b5b600160015500",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `loop_stacklimit_1021______02bb67af7d72d5206d686ab87fefc07962b627f1fdbca7055144c3a37595b554`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("03fd", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6000345b60019003906001018180600357600052600152600059f300",
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
        response.assertConsoleError("stack_limit".toUpperCase())

        // and then
    }
    @Test
    fun `bad_indirect_jump2______f16963051809be45b7261faf41f55903a3575c6607a9c85a91e6e9b1a57e874c`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6001600360030257600060005600",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `sstore_load_0______d172d17a72e23af145acf19790328396667f51023e3c10bfe913594cc68191d3`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60ff60005560ee600a5560005460145500",
               TransactionContext(
                   newAccountName,
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

        // 0x0a
        val value_0x0a = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x0a)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000000000000000000000000000000000ee", value_0x0a)

        // 0x14
        val value_0x14 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x14)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000000000000000000000000000000000ff", value_0x14)

    }
    @Test
    fun `jumpTo1InstructionafterJump_noJumpDest______d490b721b3f863a786250cfbfcc9166092b30f32ddab636b0f2d1118f3c5cd7e`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6003566001600055",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `for_loop1______8b2b6673a96dc59dd2909a039991cf25b6b71bf0d894bb3c848026566975b2fa`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600a6080525b6000608051111560265760a0516080510160a0526001608051036080526005565b00",
               TransactionContext(
                   newAccountName,
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
    fun `DynamicJump0_jumpdest2______f268fec6e27187f5bcbce2f96a7d51a45be46ed7cb6003216f6511fd8d1ce908`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6023600a6008506003015660015b600255",
               TransactionContext(
                   newAccountName,
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000023", value_0x02)

    }
    @Test
    fun `mstore0______6af69f4a83b06f939b5034e619a9a9b3287f44ec6f549cf713625dab47514a0f`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60015260015160015500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", value_0x01)

    }
    @Test
    fun `JDfromStorageDynamicJump0_jumpdest0______2b2e9eb85b1fbce7e8cc300dbebf4f345e2d235e33b7fc20b772c8ece5d635f6`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val store1 = faultTolerant {
            setupTransactions.sstore(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount,
                AccountStateKey.create(accountIdentifier.pad256(), 0x00),
                "0000000000000000000000000000000000000000000000000000000000000004"
            ).blockingGet()
        }
        assertEquals(202, store1.statusCode)

        // and when
        val transaction = EthereumTransaction(
            1 + 1,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60236007600054015660015b600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `jumpifInsidePushWithJumpDest______77a604d158caf2a00460f716af2860370b02481c7642a7be920d29815db3a4ea`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6001600657655b6001600155",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `JDfromStorageDynamicJumpInsidePushWithJumpDest______3e804e167c5d050f3c158db0b6782b5c7f182947bcdf6b63b62c68721843a8a9`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val store1 = faultTolerant {
            setupTransactions.sstore(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount,
                AccountStateKey.create(accountIdentifier.pad256(), 0x00),
                "0000000000000000000000000000000000000000000000000000000000000004"
            ).blockingGet()
        }
        assertEquals(202, store1.statusCode)

        // and when
        val transaction = EthereumTransaction(
            1 + 1,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60046000540156655b6001600155",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `DynamicJump_valueUnderflow______6b4d0c9a6785c86ec07e724bc3ae21d394e7090057223ad38991e16e03577531`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("1b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60016002600334565b5050600052596000f35b50600052596000f35b505050600052596000f3",
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
    fun `DynamicJumpInsidePushWithJumpDest______aa8ebedcd5ba1c4b520819db9661817bbcfe6268c5e8717c3eec9ee1c2a7eab0`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600460030156655b6001600155",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `DynamicJumpPathologicalTest1______0ec35ead01bd83ca38ee5131a7c43840e13c1b3805fcc9221c3cac36c8baea12`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "435660615b4343025660615b60615b605b6001600155",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `jump0_withoutJumpdest______9c83d8259b56620b0205a4590e7c9343503c743e7da0e58c5e7bcd64074e87a5`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60236007566001600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `jumpToUint64maxPlus1______3b5f10ad34c03cbd0c049cd2c7e7ba54e602d9b5ffdc4e0e4918c756a8c03df0`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6801000000000000000b565b5b6001600155",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `jumpi1______b2fa00b2842ca814d4a24f5b1c13b932269ea624423a8989aa9400ff04750149`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "602360006009576001600255",
               TransactionContext(
                   newAccountName,
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
    fun `mloadOutOfGasError2______b20bf32ad082d10fa661b5f340c1a48e83575af99c76742b8e3c53ab53ddd995`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "627248255160015500",
               TransactionContext(
                   newAccountName,
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
    fun `DynamicJumpifInsidePushWithoutJumpDest______3e0a8e3e1c5c244f912e8d7fd4f301394023672a05a178bcfb1ff2d3dc5d6163`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600160076003015761eeff",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `mloadError0______0ffdb0d235c6a5ce671521a112d5938dc1ad218f9a1e0232ab1e30d92b03529a`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60005160005500",
               TransactionContext(
                   newAccountName,
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
    fun `DynamicJump0_AfterJumpdest______f1b2a8970120adbe6ef5a84db00b98dc5b78fbdc56f385ec0163ec21a01a370c`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "602360086003015660015b600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `JDfromStorageDynamicJumpiOutsideBoundary______53ff597d4696abb88488273c523c582dfc3c29c9edfd678e09eec2511adc0581`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val store1 = faultTolerant {
            setupTransactions.sstore(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount,
                AccountStateKey.create(accountIdentifier.pad256(), 0x00),
                "0000000000000000000000000000000000000000000000000000000000000004"
            ).blockingGet()
        }
        assertEquals(202, store1.statusCode)

        // and when
        val transaction = EthereumTransaction(
            1 + 1,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60017ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff060005401576002600355",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `mloadError1______8a0f5e004862d2622bec07327dea33ab3db0cedc15ee391a302ac44fe295da5a`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "601760015260005160015500",
               TransactionContext(
                   newAccountName,
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
    fun `jumpToUintmaxPlus1______29edbd08e694c30f143daf79f3fd5063ccc378a50a63fb52b4cc6caca104ddab`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "640100000007565b5b6001600155",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `jumpi0______1b9274d1f740ad5b88df94a504f94390e25e9ab1d961c72eb332df8f572c6134`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "602360016009576001600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `JDfromStorageDynamicJumpifInsidePushWithJumpDest______77f7a26b3bfa9216ac060dbdcbd99640691945c739bf96c11aaf7374577e658a`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val store1 = faultTolerant {
            setupTransactions.sstore(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount,
                AccountStateKey.create(accountIdentifier.pad256(), 0x00),
                "0000000000000000000000000000000000000000000000000000000000000004"
            ).blockingGet()
        }
        assertEquals(202, store1.statusCode)

        // and when
        val transaction = EthereumTransaction(
            1 + 1,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600160066000540157655b6001600155",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `DynamicJumpPathologicalTest0______aa3fc3d950c537f5629384ab47eca9e267c47011b6c7e3dc868c40928f9f7005`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("030d40", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "435660615b4343025660615b60615b5b5b6001600155",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `DynamicJump0_withoutJumpdest______a2b6bd50ab1667cd498744a08f76d7f8ae99296fbf12d7cf8a4b1a7a64809251`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60236007600301566001600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `jumpTo1InstructionafterJump_jumpdestFirstInstruction______c25c1a23133897f0904fdda69bae204a92248dee744c91799a9cab1fee299bd8`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "5b6003565b6001600055",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `jumpifInsidePushWithoutJumpDest______7f49a923ddc0cce92c65c90639f0720bc0d36d98c82a56f1bfaeb43b58b74606`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600160075761eeff",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `mstore1______53211b86e216af37c6d10fdc5402db0aeef861a60c7f299116006aa26b47d8dd`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60020160015260015160015500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x01)

    }
    @Test
    fun `jump0_AfterJumpdest3______df29eb5b42d780c5687f0cb8e220139b103a77f21c73d7f494b2435f1dfca711`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6023600b6008505660015b600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `DynamicJumpPathologicalTest3______62bba45b3bbd290f04067ac12d0c5055402d53fa081ff6b3d7ee7d1d5e1ed2d6`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "435631615b60615b60615b606001600155",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `swapAt52becameMstore______6008951a4298e7f59619ee474eda94eca47ef9007c7d7967435bcacb28a323b6`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600260035255",
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
    fun `calldatacopyMemExp______126ce6c14ae7760cb0d2acf96a15749c384a62bd8cb54d0bf6644f1a9f211a8c`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("01f4153d80", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60ff60ff630fffffff630fffffff37",
               TransactionContext(
                   newAccountName,
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
    fun `mstore8_0______c09cd0b1656086f10b804d06d72cb848240f683726e7dbeb905f6a01be5d9b8b`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60015360015160015500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("ff00000000000000000000000000000000000000000000000000000000000000", value_0x01)

    }
    @Test
    fun `JDfromStorageDynamicJump0_jumpdest2______de787f6f54b08f43d5b14eda419868a862a2a8721d53c0aac1a3520672d48b8d`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val store1 = faultTolerant {
            setupTransactions.sstore(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount,
                AccountStateKey.create(accountIdentifier.pad256(), 0x00),
                "0000000000000000000000000000000000000000000000000000000000000004"
            ).blockingGet()
        }
        assertEquals(202, store1.statusCode)

        // and when
        val transaction = EthereumTransaction(
            1 + 1,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6023600a600850600054015660015b600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `DynamicJump0_jumpdest0______59dd1fa611b69c2da265a4cc2060304c16402f5b7cdcd113d4fce6008fca006e`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "602360076003015660015b600255",
               TransactionContext(
                   newAccountName,
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000023", value_0x02)

    }
    @Test
    fun `DynamicJump0_AfterJumpdest3______24001b738d844bbcfcee38f48ecce72287817ad8a742f5d378303ac9645e330b`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6023600b6008506003015660015b600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `jump0_AfterJumpdest______613b66cc6f8128d346f4a955d41cc8337b5b85b024d3f56832af4f5d46186aba`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "602360085660015b600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `jump1______967462cce448ed66268c31247b9142142b9c21675617ee320931c8767c27cb5a`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "620fffff620fffff0156",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `deadCode_1______3c140128a695590c7962596293f317b9ba8ff084290c4140f9d1c79ad7137443`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6001600053596000f300000000000000005b0000",
               TransactionContext(
                   newAccountName,
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
    fun `memory1______6c0c6cab605480b44b43a80930946761c618357f70a72a25a00097c52454eacc`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600260005360036001536000516001510160025260406000f300",
               TransactionContext(
                   newAccountName,
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
    fun `log1MemExp______37b9d3cb1a977e07a9fc925c5417bc82cc414895600b135b808a8a27b950a1b1`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("01f4153d80", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60ff60ff630fffffffa1",
               TransactionContext(
                   newAccountName,
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
    fun `dupAt51becameMload______eb32cda95bb9f2823756c0707205baaaa731ebc82fcebfa97e5379232f35edd8`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600260035155",
               TransactionContext(
                   newAccountName,
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
    fun `jump0_foreverOutOfGas______a41b1a2c15c767c1df3935dd1d1c5010eb4367a07a495ed34f6a17cfb3f73df5`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "5b600056",
               TransactionContext(
                   newAccountName,
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
    fun `jump0_outOfBoundary______0671b215b2840e18f4e6c84f8740bb266798c72831f2885eaefe0491f81f4bd7`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60236007566001600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `JDfromStorageDynamicJumpi0______e472676b6825e9a018a99ff9152647a56267f8e7cd1c6da3dc793879e7fea8fe`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val store1 = faultTolerant {
            setupTransactions.sstore(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount,
                AccountStateKey.create(accountIdentifier.pad256(), 0x00),
                "0000000000000000000000000000000000000000000000000000000000000004"
            ).blockingGet()
        }
        assertEquals(202, store1.statusCode)

        // and when
        val transaction = EthereumTransaction(
            1 + 1,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60236001600960005401576001600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `JDfromStorageDynamicJumpi1______147683985c1184c00d30610ba3040b5f9e1fbbe26bf354131bc80b29cc0c71e7`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val store1 = faultTolerant {
            setupTransactions.sstore(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount,
                AccountStateKey.create(accountIdentifier.pad256(), 0x00),
                "0000000000000000000000000000000000000000000000000000000000000004"
            ).blockingGet()
        }
        assertEquals(202, store1.statusCode)

        // and when
        val transaction = EthereumTransaction(
            1 + 1,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60236000600960005401576001600255",
               TransactionContext(
                   newAccountName,
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

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000001", value_0x02)

    }
    @Test
    fun `jumpdestBigList______5001ebe68d64d24279e1d4935a90375f078e893f1850027b78a39d3edd263a87`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("05f5e100", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6009565b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b",
               TransactionContext(
                   newAccountName,
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
    fun `stackjump1______4d0774baea20c8ae5388f3d113c44b48d99bc98dbc5956db0910dec4b3bd634a`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6004600660096014565b600a03600052596000f35b6000520160095600",
               TransactionContext(
                   newAccountName,
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
    fun `byte1______9504bcc409715d7d565edd0a01d69f6c3557ff282d8fb868c3d3b501701ac079`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "7f112233445566778899001122334455667788990011223344556677889900aabb60001a7f112233445566778899001122334455667788990011223344556677889900aabb60011a7f112233445566778899001122334455667788990011223344556677889900aabb60021a7f112233445566778899001122334455667788990011223344556677889900aabb60031a7f112233445566778899001122334455667788990011223344556677889900aabb60041a7f112233445566778899001122334455667788990011223344556677889900aabb60051a7f112233445566778899001122334455667788990011223344556677889900aabb60061a7f112233445566778899001122334455667788990011223344556677889900aabb60071a7f112233445566778899001122334455667788990011223344556677889900aabb60081a7f112233445566778899001122334455667788990011223344556677889900aabb60091a7f112233445566778899001122334455667788990011223344556677889900aabb600a1a7f112233445566778899001122334455667788990011223344556677889900aabb600b1a7f112233445566778899001122334455667788990011223344556677889900aabb600c1a7f112233445566778899001122334455667788990011223344556677889900aabb600d1a7f112233445566778899001122334455667788990011223344556677889900aabb600e1a7f112233445566778899001122334455667788990011223344556677889900aabb600f1a7f112233445566778899001122334455667788990011223344556677889900aabb60101a7f112233445566778899001122334455667788990011223344556677889900aabb60111a7f112233445566778899001122334455667788990011223344556677889900aabb60121a7f112233445566778899001122334455667788990011223344556677889900aabb60131a7f112233445566778899001122334455667788990011223344556677889900aabb60141a7f112233445566778899001122334455667788990011223344556677889900aabb60151a7f112233445566778899001122334455667788990011223344556677889900aabb60161a7f112233445566778899001122334455667788990011223344556677889900aabb60171a7f112233445566778899001122334455667788990011223344556677889900aabb60181a7f112233445566778899001122334455667788990011223344556677889900aabb60191a7f112233445566778899001122334455667788990011223344556677889900aabb601a1a7f112233445566778899001122334455667788990011223344556677889900aabb601b1a7f112233445566778899001122334455667788990011223344556677889900aabb601c1a7f112233445566778899001122334455667788990011223344556677889900aabb601d1a7f112233445566778899001122334455667788990011223344556677889900aabb601e1a7f112233445566778899001122334455667788990011223344556677889900aabb601f1a7f112233445566778899001122334455667788990011223344556677889900aabb60201a7f112233445566778899001122334455667788990011223344556677889900aabb6107de1a600060005500",
               TransactionContext(
                   newAccountName,
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
    fun `jumpTo1InstructionafterJump______534b909c897b24ccd539bad0f8275c154886c8c0e3fea72be8df5513d93bd7d9`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6003565b6001600055",
               TransactionContext(
                   newAccountName,
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
    fun `jumpi1_jumpdest______269d3885db0208e060ae04c8dc8463ade93fb3aa41dd6efd652cc5969b9764b1`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60236001600a5760015b600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `DynamicJump0_foreverOutOfGas______efc896722a72d17b7e7d2f62330d572ded4ae6ecd389dc4c438b5aff2af9b832`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "5b600060000156",
               TransactionContext(
                   newAccountName,
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
    fun `for_loop2______1e538c2f9a6578aee50fd827242b73f70bfbec147d2a3dacc91d93f3c94ed51c`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60006080525b600a608051101560265760a0516080510160a0526001608051016080526005565b00",
               TransactionContext(
                   newAccountName,
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
    fun `mstore8_1______53dab60c65084636e3c4af93b60f67be16e9d0126a60d777f4d6423e87ed6234`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60ff60015360ee60025360005160015500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("00ffee0000000000000000000000000000000000000000000000000000000000", value_0x01)

    }
    @Test
    fun `indirect_jump4______c6c57c6a54e82ec9ac6b16a44cf47f5ce314de9f1dd561c6bcd78a4c75001eb5`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60006007600501576001600052005b00",
               TransactionContext(
                   newAccountName,
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
    fun `jumpDynamicJumpSameDest______e409665d90691bc965f5a0b106d04ff9523d415bcd254360c92fcbd989228aef`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6002600401565b600360005260206000f3600656",
               TransactionContext(
                   newAccountName,
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
    fun `DynamicJumpPathologicalTest2______276f91947ac87c69ddf8ec3f748511d68c0eb2add59cae8acaa8a5ee7ef8b8d4`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "435631615b60615b60615b606001600155",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `DyanmicJump0_outOfBoundary______af17b27f8bf9ce920fbc628facf863bee88f1a44a9a4c0fffd476adf7659f1cc`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val store1 = faultTolerant {
            setupTransactions.sstore(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount,
                AccountStateKey.create(accountIdentifier.pad256(), 0x00),
                "0000000000000000000000000000000000000000000000000000000000000004"
            ).blockingGet()
        }
        assertEquals(202, store1.statusCode)

        // and when
        val transaction = EthereumTransaction(
            1 + 1,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6023600760005401566001600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `pop1______6d3b6e4497896523ee2423eb6faa99a24efce0fc5a6ef53b3408f1c69642a399`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "5060026003600455",
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
    fun `JDfromStorageDynamicJumpiAfterStop______8003e65aa5eb6c34401c5f46c10b1d790ff33f03e06354d414f067e526582842`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val store1 = faultTolerant {
            setupTransactions.sstore(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount,
                AccountStateKey.create(accountIdentifier.pad256(), 0x00),
                "0000000000000000000000000000000000000000000000000000000000000004"
            ).blockingGet()
        }
        assertEquals(202, store1.statusCode)

        // and when
        val transaction = EthereumTransaction(
            1 + 1,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6001600860005401570060015b6002600355",
               TransactionContext(
                   newAccountName,
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

        // 0x03
        val value_0x03 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x03)
        ).blockingGet()
        assertEquals("0000000000000000000000000000000000000000000000000000000000000002", value_0x03)

    }
    @Test
    fun `msize2______7cf5db448b9f0264ca8ac38b404bcffa5ba679350bfabf5e9d4b36c62cf8d867`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "64ffffffffff60005261eeee6020525960005500",
               TransactionContext(
                   newAccountName,
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
    fun `DynamicJumpAfterStop______0c8e3617d40094a75947aa4aef03559146a544467f3a41388aa13fb4ce9461df`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6008600101560060015b6002600355",
               TransactionContext(
                   newAccountName,
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
    fun `JDfromStorageDynamicJump0_foreverOutOfGas______a65da372e8d7530d7a4f5d374ccbd62249fd27402984ff4ca677eb0209de8444`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val store1 = faultTolerant {
            setupTransactions.sstore(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount,
                AccountStateKey.create(accountIdentifier.pad256(), 0x00),
                "0000000000000000000000000000000000000000000000000000000000000004"
            ).blockingGet()
        }
        assertEquals(202, store1.statusCode)

        // and when
        val transaction = EthereumTransaction(
            1 + 1,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "5b600060000156",
               TransactionContext(
                   newAccountName,
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
    fun `mstoreWordToBigError______0f79133931e8ad605b870750894ce90c52abf92a501ad3cf2df23e98d9d7982e`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60015260015160015500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", value_0x01)

    }
    @Test
    fun `bad_indirect_jump1______9c977a506285471a40efa451b4720ddc494a688835cbe0f2203ec5e8fb44ae41`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "601b602502565b00",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `jumpiToUint64maxPlus1______619dc00ccaab2339cbd5134eaf93c86783357a2968e3dfcc6281a6e4eb3d5f67`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60016801000000000000000d575b5b6001600155",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `mstoreMemExp______443c654a959e4dec7f18fa769d5349738f2f1405e9c5763740e3b4d204f6e286`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("01f4153d80", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60f1630fffffff52",
               TransactionContext(
                   newAccountName,
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
    fun `stack_loop______ba04df84d9ced9a4d3e55f9e27793954d0077bc269d1923cab86a9c077380b6c`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60015b6001810380600257600053600153600253600353600453600553600653600753600853600953596000f3",
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
    fun `jump0_jumpdest2______26d35f66be755fa1f0de21dedccfc7246e546ae406770e83155ee8bc3d5dd7c5`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6023600a6008505660015b600255",
               TransactionContext(
                   newAccountName,
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000023", value_0x02)

    }
    @Test
    fun `sstore_underflow______6fcc63f7fb55e77c64645ce415b4ef5c7792aed88de32aeca3e626de8e560550`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600155",
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
    fun `JDfromStorageDynamicJump0_AfterJumpdest3______dd4adfab9fb47b6616a606cd161c9f029412f34951adb57037ea464b9bf7a616`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val store1 = faultTolerant {
            setupTransactions.sstore(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount,
                AccountStateKey.create(accountIdentifier.pad256(), 0x00),
                "0000000000000000000000000000000000000000000000000000000000000004"
            ).blockingGet()
        }
        assertEquals(202, store1.statusCode)

        // and when
        val transaction = EthereumTransaction(
            1 + 1,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6023600b600850600054015660015b600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `indirect_jump3______c0a1a2d01d4a1a71ff5e27a0a850c24a1506c5008ed8559406350929461fc005`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6001600460050157005b6001600052596000f300",
               TransactionContext(
                   newAccountName,
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
    fun `DynamicJump_value1______7b60adeb85061e98e9fd94a89720d4d169874215b9429123e798ef5349765808`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("08", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60016002600334565b5050600052596000f35b50600052596000f35b600052596000f3",
               TransactionContext(
                   newAccountName,
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
    fun `return2______ea804dc3863eff0dcf0d6d97cd444c005e0c75c31a91a092ef02d10ec761ecde`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6001608052600060805111601b57600160005260206000f3602b565b602760005260206000f360026080525b00",
               TransactionContext(
                   newAccountName,
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
    fun `jumpiOutsideBoundary______33b9b782ae062bc6ca7672cc92308235cfe92cc523160b84440dfa254cf16796`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff576002600355",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `mstore8MemExp______866c7bb5dca82959cb2386c45ec18705211e8b9725349a62fef01404f115e99e`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("800570", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60f1630fffffff53",
               TransactionContext(
                   newAccountName,
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
    fun `jumpi_at_the_end______a349d0793b06078d37b9107ac53e9c872b15db047ee2f79a60423c7e7d7e8f6f`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600a6000525b600051600190038060005260055700",
               TransactionContext(
                   newAccountName,
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
    fun `gas1______6babfa8abe4b59c85cf39743f69acc2c50d02bce96477dd258ad99d2249098b8`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "5a60005500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("000000000000000000000000000000000000000000000000000000000001869e", value_0x00)

    }
    @Test
    fun `pc0______3b4cc0b9b68475e127607d8dc7a66ede03c7d7a0c197dd40ef0288dba1546e14`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "5860005500",
               TransactionContext(
                   newAccountName,
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
    fun `when______320c9dfa9a9ad7681d0642d272faf1e7fa9f50031145172c4e67a31b8f5e4ad3`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600060011115600e57600d6080525b00",
               TransactionContext(
                   newAccountName,
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
    fun `pc1______874d624c78f402d3ce9772f2c2c933684cfb3334d8c5622b8e1195495b698a00`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60ff6000555860005500",
               TransactionContext(
                   newAccountName,
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
    fun `gasOverFlow______82ee14fedc70a1ee6d74c9e85096cef8ebf154a04c57020a164a40dc59f92880`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60035b600190038060025768010000000000000016565b63badf000d6011550000",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `jumpiAfterStop______fa2e2b52b18a87bbdbdb79317a1b4820153b69f644e8d645c6f1995985e08ae5`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60016008570060015b6002600355",
               TransactionContext(
                   newAccountName,
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
    fun `gas0______87cfe07015d8a8cbd7f3cd3e7b2b0e0b3de6c462faf41d18eb8f3607660808a5`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "64ffffffffff60005261eeee605a525a60005500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000018680", value_0x00)

    }
    @Test
    fun `indirect_jump2______83e3d6f35f99019dacbda6fae475427ec678c8849b650cdd0639ec8ca1d3b616`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "600860060156005b6001600052005b6002600052596000f300",
               TransactionContext(
                   newAccountName,
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
    fun `JDfromStorageDynamicJumpi1_jumpdest______d8793d1f4cc4088e78e25474be528f3443479e6aa6b4d454355d03c0a89d18a1`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val store1 = faultTolerant {
            setupTransactions.sstore(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount,
                AccountStateKey.create(accountIdentifier.pad256(), 0x00),
                "0000000000000000000000000000000000000000000000000000000000000004"
            ).blockingGet()
        }
        assertEquals(202, store1.statusCode)

        // and when
        val transaction = EthereumTransaction(
            1 + 1,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60236001600a600054015760015b600255",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `mstore_mload0______4edd47cee6ce49dd02d4eed4ff3d4dccbb06f5dd6c7a8d7cd99bb8dc4129eded`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "601760005260005160015500",
               TransactionContext(
                   newAccountName,
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
        assertEquals("0000000000000000000000000000000000000000000000000000000000000017", value_0x01)

    }
    @Test
    fun `JDfromStorageDynamicJump1______c9714fbf904e601f1b095a3c7ddb16eb59536e03686e17586e9fb475d8848f5f`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when
        val store1 = faultTolerant {
            setupTransactions.sstore(
                newAccountName,
                newAccountPrivateKey,
                newEthAccount,
                AccountStateKey.create(accountIdentifier.pad256(), 0x00),
                "0000000000000000000000000000000000000000000000000000000000000004"
            ).blockingGet()
        }
        assertEquals(202, store1.statusCode)

        // and when
        val transaction = EthereumTransaction(
            1 + 1,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "620fffff620fffff016000540156",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `sstore_load_2______51cb2ee1d19df3dbac06156f84f682b4cc6469cce263f28efaa03e27f81e9054`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("030d40", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60ff60005560ee60015560dd600255600154600a5560025460145500",
               TransactionContext(
                   newAccountName,
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

        // 0x01
        val value_0x01 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x01)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000000000000000000000000000000000ee", value_0x01)

        // 0x02
        val value_0x02 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x02)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000000000000000000000000000000000dd", value_0x02)

        // 0x0a
        val value_0x0a = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x0a)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000000000000000000000000000000000ee", value_0x0a)

        // 0x14
        val value_0x14 = getAccountState.getValue(
            newAccountName,
            AccountStateKey.create(accountIdentifier.pad256(), 0x14)
        ).blockingGet()
        assertEquals("00000000000000000000000000000000000000000000000000000000000000dd", value_0x14)

    }
    @Test
    fun `sha3MemExp______c43e039d485d4eb92f06777c13bb1e632c0ba655aa5517f08d2b83ac453cab42`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("01f4153d80", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60ff630fffffff20",
               TransactionContext(
                   newAccountName,
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
    fun `DynamicJump1______09f67c6801caaa37a56b396dfc33dc3e3fe0bb62da55ffa45faaddad2f632074`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "620fffff620fffff0160030156",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `DynamicJumpInsidePushWithoutJumpDest______be46483961399c97e392aa6c0bc0cb03f6264ca601f97084d4981741f38e6b58`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "60056003015661eeff",
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
        response.assertConsoleError("jump_destination".toUpperCase())

        // and then
    }
    @Test
    fun `msize3______bf628647fe897fe1227b62f36a23b6587f8a201960e22ccaf2fbc96ff882bcfe`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "64ffffffffff60005261eeee605a525960005500",
               TransactionContext(
                   newAccountName,
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
    @Test
    fun `pop0______80055f0605c1ba4ce319b67ce709043d635e865512612974bbfee8e0d7b627e3`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               signedTransaction,
               accountIdentifier.toHexString(),
               "6002600360045055",
               TransactionContext(
                   newAccountName,
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
}

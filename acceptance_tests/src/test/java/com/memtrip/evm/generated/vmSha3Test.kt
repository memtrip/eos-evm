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

//
// 11.05.2020
// Auto generated based off the Ethereum tests found here:
// https://github.com/ethereum/tests/blob/develop/VMTests/
//
class vmSha3Test {
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
    fun `sha3_0______b99ef89ec788de6255a65927490820dc07d19dc71b40115513c7aa518465ef20`() {

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
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "600060002060005500",
                TransactionContext(
                    newAccountName,
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
        assertEquals("c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470", value_0x00)
    }
    @Test
    fun `sha3_memSizeNoQuadraticCost31______7bd0bcdfd4ed3cd89ee9c763c8975326daf6a12e132d6ebb11120ea0af469c2d`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("0100000000", 16),
            BigInteger("7c", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60016103c02060005500",
                TransactionContext(
                    newAccountName,
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
        assertEquals("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a", value_0x00)
    }
    @Test
    fun `sha3_memSizeQuadraticCost63______4d8a8b59f65435245ba2fea14c0a92bf735bac63f97e5955f50767e93102b0b9`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("0100000000", 16),
            BigInteger("7c", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60016107c02060005500",
                TransactionContext(
                    newAccountName,
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
        assertEquals("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a", value_0x00)
    }
    @Test
    fun `sha3_1______ece29a11a21213fddea869679952a15d24f89ccfd2bf45d7a00ff003df498ceb`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "600560042060005500",
                TransactionContext(
                    newAccountName,
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
        assertEquals("c41589e7559804ea4a2080dad19d876a024ccb05117835447d72ce08c1d020ec", value_0x00)
    }
    @Test
    fun `sha3_memSizeQuadraticCost65______c7611dde7c250d3c5a84af161483675030397c9fdb92ffc10b2e002f0aab93c0`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("0100000000", 16),
            BigInteger("7c", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60016108002060005500",
                TransactionContext(
                    newAccountName,
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
        assertEquals("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a", value_0x00)
    }
    @Test
    fun `sha3_memSizeQuadraticCost32______1082cc892869c28a6d15724217c7f7383b4032632c74b77d112052950436eca3`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("0100000000", 16),
            BigInteger("7c", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60016103e02060005500",
                TransactionContext(
                    newAccountName,
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
        assertEquals("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a", value_0x00)
    }
    @Test
    fun `sha3_bigOffset______ab8775e308b58ee75d3ef19d554c74e8ffb9c4376907a328b953d71a68f40ae3`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("010000000000", 16),
            BigInteger("7c", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60027e0fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff2060005500",
                TransactionContext(
                    newAccountName,
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
    fun `sha3_6______bbd86d101066e8b383a6cbf5c4101779825de64cd97f97bbbca14d44010e33fa`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff2060005500",
                TransactionContext(
                    newAccountName,
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
    fun `sha3_memSizeQuadraticCost33______ed7993323c0c82f074fe9edcaca291adb2270752b1ebe7c875d221d2f03e45d2`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("0100000000", 16),
            BigInteger("7c", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60016104002060005500",
                TransactionContext(
                    newAccountName,
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
        assertEquals("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a", value_0x00)
    }
    @Test
    fun `sha3_memSizeQuadraticCost64______3b256f546c6cbdbe9661e3bd5310f1bacb2456c7ef5b490e8437cc60ce528c55`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("0100000000", 16),
            BigInteger("7c", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60016107e02060005500",
                TransactionContext(
                    newAccountName,
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
        assertEquals("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a", value_0x00)
    }
    @Test
    fun `sha3_memSizeQuadraticCost64_2______4ad5c8a3eb5039f86c15c25bf291ccfd47ae2defdfcef7f961348cfcca8d5877`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("0100000000", 16),
            BigInteger("7c", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60206107e02060005500",
                TransactionContext(
                    newAccountName,
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
        assertEquals("290decd9548b62a8d60345a988386fc84ba6bc95484008f6362f93160ef3e563", value_0x00)
    }
    @Test
    fun `sha3_4______1a753ff8e419c74ac7cdafedbb77ea085c33f3503beb0090d6b25173cf180c5c`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "6064640fffffffff2060005500",
                TransactionContext(
                    newAccountName,
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
    fun `sha3_5______fdf4310e913f6039c9c5b0d741f0e4bbaa54e233cede4c7f3fc2e39769749bea`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "640fffffffff6127102060005500",
                TransactionContext(
                    newAccountName,
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
    fun `sha3_bigSize______e140749a85369fcc3c6177951bc816b073deb941cf910b5927acb2ee8adfb059`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("010000000000", 16),
            BigInteger("7c", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "7effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff2060005500",
                TransactionContext(
                    newAccountName,
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
    fun `sha3_2______0a41ee61592815f2e8ea81001358719f022ed41f4fdd4fea73c789af3dcd7d36`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "600a600a2060005500",
                TransactionContext(
                    newAccountName,
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
        assertEquals("6bd2dd6bd408cbee33429358bf24fdc64612fbf8b1b4db604518f40ffd34b607", value_0x00)
    }
    @Test
    fun `sha3_memSizeQuadraticCost32_zeroSize______1f9a4d4b0235fbd4b45a48b1bc9790de0aecb64ea89dea73a13a14c7f25f723c`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("0100000000", 16),
            BigInteger("7c", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "60006104002060005500",
                TransactionContext(
                    newAccountName,
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
        assertEquals("c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470", value_0x00)
    }
    @Test
    fun `sha3_3______36cb8a641285b7dcbf2be71e4ecd3abf358bd3b24daace8768460906d54e4cac`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("0c", 16),
            BigInteger("0186a0", 16),
            BigInteger("0b", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "620fffff6103e82060005500",
                TransactionContext(
                    newAccountName,
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
    fun `sha3_bigOffset2______2a72ad916044fc2fa16f2490b7a25216d042d81ab073964ead1e3231692b9b05`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        // when

        // and when
        val transaction = EthereumTransaction(
            1 + 0,
            BigInteger("01", 16),
            BigInteger("1000000000", 16),
            BigInteger("00", 16),
            "0x"
        )

        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHexString()
        val response = faultTolerant {
            executeAction.pushTransaction(
                newAccountName,
                signedTransaction,
                accountIdentifier.toHexString(),
                "600263010000002060005500",
                TransactionContext(
                    newAccountName,
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
        assertEquals("54a8c0ab653c15bfb48b47fd011ba2b9617af01cb45cab344acd57c924d56798", value_0x00)
    }
}

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.*
import com.memtrip.eos_evm.eos.raw.RawAction
import com.memtrip.eos_evm.ethereum.EthAccount
import com.memtrip.eos_evm.ethereum.EthereumTransaction
import com.memtrip.eos_evm.ethereum.toHex
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Test
import java.math.BigInteger
import java.util.concurrent.TimeUnit

//
// 11.04.2020
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

    private val rawAction = RawAction(chainApi)

    @Test
    fun `mulmoddivByZero______d2f1f45a525dd3c94e60ba59a808bfa6f526ff1517294eacdf4d09d9d33415d5`() {
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
            "0x60006001600509600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sub0______6e271b6ee17cb23f68d252f5c2bddad3c667f05dc922fd4839721727eb10ee0f`() {
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
            "0x6001601703600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_29______d1d28e8369ccb0a73475421072fcba58bc0491a0a30c1541d47076a0284609a2`() {
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
            "0x601d6101000a600055601d60ff0a600155601d6101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `signextend_BigByteBigByte______5cd096028c09eba94315bd6d591ae9cb76413b56bac1aeada8d337d47c59be10`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0b600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_22______c0e0c1457caeab0bedb354de662de3741cd90362ec3fe970cbd5565c8e164a1f`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60166101000a6101000a600055601660ff0a6101000a60015560166101010a6101000a60025560166101000a60ff0a600355601660ff0a60ff0a60045560166101010a60ff0a60055560166101000a6101010a600655601660ff0a6101010a60075560166101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_8______eabf261994e71ba3fab018f76089ada2039bf58f8547a549aca6f9605bb7e452`() {
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
            BigInteger("989680", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60086101000a6101000a600055600860ff0a6101000a60015560086101010a6101000a60025560086101000a60ff0a600355600860ff0a60ff0a60045560086101010a60ff0a60055560086101000a6101010a600655600860ff0a6101010a60075560086101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mul4______98024d8b456973580b82d5dfcc6e3d389628d673e12d43ff8653a44b435fbee6`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7f800000000000000000000000000000000000000000000000000000000000000002600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_13______9a5723090752b32355ffaefd5d4b998f17196c358567128240bb0f8e83a1d375`() {
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
            "0x600d6101000a600055600d60ff0a600155600d6101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mulmod3______a4466904098f2aa254af6f260446e643504d5993d6226da4cf88c82942018de1`() {
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
            "0x60036000036001600509600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `exp6______05a538a5941013f6dc6dfb36f122b6d6840d86e5cb69af7da789e71d14c54937`() {
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
            "0x61010160010a600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `addmodDivByZero1______858b669ae5775b5aeae36c69828eb74ecfa9498698f01ae8d1ba73328b466d96`() {
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
            "0x60006001600008600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_18______9aae91d4c3217ab1ae7ac11ca2cdce036b3be2c2bc426f515bbc1b1e4a9a48eb`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60126101000a6101000a600055601260ff0a6101000a60015560126101010a6101000a60025560126101000a60ff0a600355601260ff0a60ff0a60045560126101010a60ff0a60055560126101000a6101010a600655601260ff0a6101010a60075560126101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `smod5______7b7e7c70fbcb291a99ff4ae3f8d46a67b94183a8cf3c5a93aff9262c81bd3aa7`() {
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
            BigInteger("2710", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000307600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_25______fce87c81a0e08fa580701f25ecc21b487f85741090abd8a7614cabf6b90e42ae`() {
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
            "0x60196101000a600055601960ff0a60015560196101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mulmoddivByZero3______7f1443cbcb5f817b38aed7b0dd96af4d58e8025b71a380e14af792c24fc2d8fa`() {
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
            "0x60006000600009600103600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_33______dcdd8d12914af51d9ebd69cf0085106850fcc496b40c13bdc30d5a5440b561ce`() {
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
            "0x60216101000a600055602160ff0a60015560216101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_4______5758fdc80aadf2b69e7e75acfa05239e6c5d9d5ad1374b1cac0d19477a861b72`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60046101000a6101000a600055600460ff0a6101000a60015560046101010a6101000a60025560046101000a60ff0a600355600460ff0a60ff0a60045560046101010a60ff0a60055560046101000a6101010a600655600460ff0a6101010a60075560046101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sdiv7______2b55fc5f5e58371ec9404c0b8c5e009c45c2c2efdbb5f8856cec1e847f588dba`() {
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
            "0x6019600160000305600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `divByNonZero1______fcd51ef794022b0a97b5d1c20e12e1a725cdd126f9a42fc135a79bc15e95e447`() {
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
            "0x6018601704600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `addmod1_overflow2______bef2a19f1d2f3d74ad56dcff0d4f94046bf73b3b27472e2d92b415dceebe9ca0`() {
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
            BigInteger("2710", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60056000600160000308600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_14______58cc5ba032541e61180d5bb54913a3b14ba2db81e6e455d45fd0504bb1a69da4`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x600e6101000a6101000a600055600e60ff0a6101000a600155600e6101010a6101000a600255600e6101000a60ff0a600355600e60ff0a60ff0a600455600e6101010a60ff0a600555600e6101000a6101010a600655600e60ff0a6101010a600755600e6101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_15______ce849f731f8f9cfdb8c922cac2e16d847e6af0bea8958367c172b277020c7819`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x600f6101000a6101000a600055600f60ff0a6101000a600155600f6101010a6101000a600255600f6101000a60ff0a600355600f60ff0a60ff0a600455600f6101010a60ff0a600555600f6101000a6101010a600655600f60ff0a6101010a600755600f6101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `divByNonZero0______70dda40426c888f3c2b4505f99842373bae332be0976cb37dd6b4f8f950e7314`() {
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
            "0x6002600504600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `addmod1_overflow3______37950a5f52df8d7eb5241267f3b45a759284d77a88e876990c6ee5b1c0f48857`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60056001600160000308600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sdiv6______e7b278490909bf62877a08100ade05781f50a8e1057283f7b8c734a0aec01dee`() {
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
            "0x60007f800000000000000000000000000000000000000000000000000000000000000060000305600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_5______b03dff0692fa130237d4d29c2879391227fd71f95a3efec5d191667dc7a5ac8a`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60056101000a6101000a600055600560ff0a6101000a60015560056101010a6101000a60025560056101000a60ff0a600355600560ff0a60ff0a60045560056101010a60ff0a60055560056101000a6101010a600655600560ff0a6101010a60075560056101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_32______9a7aca6dc6ad1b3e6bbf7596f5d5f35e917f8e4be05eb7d962bf9e2852345fa5`() {
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
            "0x60206101000a600055602060ff0a60015560206101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `divBoostBug______d2e783985274bb48def6615bebddaf86d9ebdcf49e03f93a9854166ce999b166`() {
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
            "0x7f01dae6076b981dae6076b981dae6076b981dae6076b981dae6076b981dae60777fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffba04600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mulmoddivByZero2______dade878a93b655f3a61789e38fb21ece3dd658e3e58d13a23bd5dcf5af668ef6`() {
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
            "0x60006000600109600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `addmod1_overflowDiff______fd000aecad4faf960141a35e708c6686bf6d29b917347ec0f793b8a62393ed8b`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60056002600003600160000308600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_24______e4c8a16c072ceeebfd96c18dbd58a9088c910a9d2b9e35f9114ff0ecfb526d10`() {
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
            "0x60186101000a600055601860ff0a60015560186101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `smod4______131b0f2f206b381215517d412fb1ea7564a8152d2f4d4cd6ab3bff2cee6b2198`() {
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
            "0x6000600260000307600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_19______82899697a114c2742a99d07558e3ff58075aed7ac8d0b4624e336727ed10644b`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60136101000a6101000a600055601360ff0a6101000a60015560136101010a6101000a60025560136101000a60ff0a600355601360ff0a60ff0a60045560136101010a60ff0a60055560136101000a6101010a600655601360ff0a6101010a60075560136101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mulmod2______79bc8735a59de453773cbcd0053df3cd759b8d55ece41192570ed00471f038ac`() {
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
            "0x60036001600560000309600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `exp7______618bedd207234fc5c4da314056bc9550ecb1c3ace2bd12dd6ee9a305a58b1853`() {
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
            "0x61010160020a600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mul5______df427409c23049ff69ae32648441bacf7f46bfa8380019c6d1effaefa428d3e1`() {
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
            "0x7f80000000000000000000000000000000000000000000000000000000000000007f800000000000000000000000000000000000000000000000000000000000000002600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_12______2e2fede61e970560166c4fa485d48bc644ee46ba312aae472afd3c861f73799c`() {
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
            "0x600c6101000a600055600c60ff0a600155600c6101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_9______f93cdd3e162869675b64e4a5e5bb04307b799762656cb3e2db858aeeb6195767`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60096101000a6101000a600055600960ff0a6101000a60015560096101010a6101000a60025560096101000a60ff0a600355600960ff0a60ff0a60045560096101010a60ff0a60055560096101000a6101010a600655600960ff0a6101010a60075560096101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `signextend_BigByte_0______ed96ff1a29a7869a15e633346c24da243ef11761dbfac1fe6b6e54629e3d265a`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0b600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_23______6ff02117a4131900b84bb38b99a97e590f197792f742bd27678797d0976c2c3d`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60176101000a6101000a600055601760ff0a6101000a60015560176101010a6101000a60025560176101000a60ff0a600355601760ff0a60ff0a60045560176101010a60ff0a60055560176101000a6101010a600655601760ff0a6101010a60075560176101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_1______308cd7ec273573ca2f8a96a8300b5469c13bdf78fa4c4f643d154e501333fc3f`() {
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
            "0x60016101000a600055600160ff0a60015560016101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mulmod1_overflow______8746002a182b1690ee3c6f9285ae2f6293abc8531dce20c6a81c632dea5b06c2`() {
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
            BigInteger("2710", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60056002600160000309600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sub1______9c03702b06e54741e8c89a52f479d93892f0186c3d8cd469dd8c1ef4987c0d55`() {
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
            "0x6003600203600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_28______02bf29a25df27bb8f98935cb17cdd2e1b37c3963178dfd245c681919697c6750`() {
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
            "0x601c6101000a600055601c60ff0a600155601c6101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_23______abfb8b178f10c9de69b1ee116db59a0f9a127e78c370610d4593c8aab78771a6`() {
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
            "0x60176101000a600055601760ff0a60015560176101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `addmod0______1315e3365bbf4b0d1ea7d5f885974318055ca1dc25f54a106df8f76f3dfd34d5`() {
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
            "0x60026002600108600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `add0______2d47e8f287f580e1e0ec6b926375f8fee1142475cbf3bdcdf9305e618b66cb40`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_28______f0bed14e403ae3cbb67dfbf7e93be879d04590226ad07c947e5d76e1ef45a4e4`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x601c6101000a6101000a600055601c60ff0a6101000a600155601c6101010a6101000a600255601c6101000a60ff0a600355601c60ff0a60ff0a600455601c6101010a60ff0a600555601c6101000a6101010a600655601c60ff0a6101010a600755601c6101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mulmod2_1______ad3c90c6e0cbacf8ba3baab6c0f8540ec0ff24038b0768dadabf67efac5e07ed`() {
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
            "0x60036001600560000309600360056000030614600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `smod8_byZero______d21aca0c1e7c0240084f3604e37698a1495ee8777b0dcb2d3a61b714d7288683`() {
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
            "0x600d600060c86000030703600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_2______249a51e755ea2cd7bdbc704a8b3825fc01d8145221332c23e605cda095415004`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60026101000a6101000a600055600260ff0a6101000a60015560026101010a6101000a60025560026101000a60ff0a600355600260ff0a60ff0a60045560026101010a60ff0a60055560026101000a6101010a600655600260ff0a6101010a60075560026101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_19______91e9804a3d43e6f2e973625ca587f4e8583bec88aa3c53c333a24bfd50e911f7`() {
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
            "0x60136101000a600055601360ff0a60015560136101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `signextend_bigBytePlus1______e1d4c88c2ad5fbe82fefe183562d1533a0408cce7501f79d294a2207637afd23`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x66f000000000000161ffff0b600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sdivByZero2______0395bca3ef9221cdfca63d08eceb32873be670cae868547e38aa1a42c29e41d9`() {
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
            "0x600160007ffffffffffffffffffffffffffffffffffffffffffffffffffffffffcf923bdff6000030501600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sdiv1______65482c2a8e74781262c4db10d43d8c7731628b313a56e48a8dfdc9af9a1e4164`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6000037fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff05600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `addmod1_overflow4______d256203dabe38a3e460b068f5f85039a7f3db2f87cdd47c4eba6631f1eebe846`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60056002600160000308600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_12______8e662f9b2bcc90eacdf00d0f18353ff17d7bada18f5ea2260030951429e0ff62`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x600c6101000a6101000a600055600c60ff0a6101000a600155600c6101010a6101000a600255600c6101000a60ff0a600355600c60ff0a60ff0a600455600c6101010a60ff0a600555600c6101000a6101010a600655600c60ff0a6101010a600755600c6101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_32______6391696ba6998cd4f6154479524ffa7c1fd2970c481100e6885eacbba5700f64`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60206101000a6101000a600055602060ff0a6101000a60015560206101010a6101000a60025560206101000a60ff0a600355602060ff0a60ff0a60045560206101010a60ff0a60055560206101000a6101010a600655602060ff0a6101010a60075560206101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_6______2513b1044fefd548846b5188b80ed9633303bbbf23522518925608b2916bbc6c`() {
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
            "0x60066101000a600055600660ff0a60015560066101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_24______cbbb2605b3283fff77ffccb39e107bd2a9353d0f25fb2fa43dc94f5db1c9f1f3`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60186101000a6101000a600055601860ff0a6101000a60015560186101010a6101000a60025560186101000a60ff0a600355601860ff0a60ff0a60045560186101010a60ff0a60055560186101000a6101010a600655601860ff0a6101010a60075560186101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf2_32______1c83675482424298675a170ac78731d2fd4660aa4a42739a1ba1e6032e3a736a`() {
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
            "0x602060020a600055601f60020a600155602160020a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `signextend_0_BigByte______9690d6442d8ff89edda5c528ab4e1cb01ee09ba06c4e0c59d78be6d82259c40b`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000b600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mod1______efb4ba86b8ead1a13d49883472aa7876f6c2f22d094d84a22e0aa206bcf0443e`() {
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
            "0x60027fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff06600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sdiv_i256min______0fb4aa11ee10780f512ea76b238c096b781768ac4048e45d4b5ce3aa8f0a987d`() {
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
            "0x60016000037f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000305600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_15______5b661530dd5092ea6c0916ede1eac91b3650b6eb747c7fb5b51c86e6c638b29c`() {
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
            "0x600f6101000a600055600f60ff0a600155600f6101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mul2______d78a8768183f5c845b70898608b589cea44445d770bac7d08071fbccd9122d7a`() {
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
            "0x6017600002600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `exp0______becfe094fe303afc738e2960a64d60ec529d99bf137a608b055ba1ae426f5040`() {
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
            "0x600260020a600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `signextend_BitIsNotSetInHigherByte______d7fe1705027d2eaee0adc232f8c10fad41b29b39323215fba98de942695a2ba0`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x62126af460010b600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `smod3______065fa0c03f285a3f544803b152a83747c02e25bfa2534c5aaae56128a836d245`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600260000307600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `smod2______0ae154b4126001a661cccd291c9f3a10cc9051e554a729f22dc26cb32f37c7f4`() {
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
            "0x6003600560000307600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `signextend_Overflow_dj42______7670c75ec39bedeeac949ccec613c786efedd311a4f2a05ce3b28b1822f67b3b`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x6005565b005b61800080680100000000000000010b6180011160035763badf000d601155"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mulmod4______d0eab7707b7c4159ec4e9b68f395056a16fefb9a701a45e137b8993127870fb1`() {
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
            "0x6064601b60250960005360006001f3"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `exp1______865320dd21d6636f4bf6f450f1df11b3df505304b74e57940db08814078b7208`() {
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
            "0x7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0a600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_14______61841ab9a30c340ba56febf6d767ab19f91d9bb32ddd7a0c5ee5fdf080faf829`() {
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
            "0x600e6101000a600055600e60ff0a600155600e6101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mul3______ea10c103a01bd1ae9bf5e1b964928ced5f84e6dbcdaa589400d20efcc3f6f787`() {
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
            "0x6001601702600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `smod_i256min1______1ac5584b891146649c93c9adb684f955bb539884cb37173d6765c46b37a39c50`() {
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
            "0x60016000037f800000000000000000000000000000000000000000000000000000000000000060000307600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf2_64______8e369c41de5a6a6e3c87ed3f76e2a56d98b8283b18c9ef028d4829ed286d3b75`() {
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
            "0x604060020a600055603f60020a600155604160020a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mod0______44970c0ef5fc5d700edaf9be35380d95cc5f91ac6f813a57046b9e1884afab0e`() {
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
            "0x6003600206600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_25______681b6391573ae3638d187cb462c2ceac81bb651942fa2a4039c54835a82bc251`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60196101000a6101000a600055601960ff0a6101000a60015560196101010a6101000a60025560196101000a60ff0a600355601960ff0a60ff0a60045560196101010a60ff0a60055560196101000a6101010a600655601960ff0a6101010a60075560196101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_7______ccc726de1f10bdaaee5b164f93a976e78f4c031e826a8237bb03f46113e00059`() {
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
            "0x60076101000a600055600760ff0a60015560076101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_33______52733d6f69e238cd513f28e3fe30dc303493edb9c0637029e448f0e974b1c940`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60216101000a6101000a600055602160ff0a6101000a60015560216101010a6101000a60025560216101000a60ff0a600355602160ff0a60ff0a60045560216101010a60ff0a60055560216101000a6101010a600655602160ff0a6101010a60075560216101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_13______d7052bc90b7237c69a4efdf860a687a529c09e545ddc74ab104923c720ad0b91`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x600d6101000a6101000a600055600d60ff0a6101000a600155600d6101010a6101000a600255600d6101000a60ff0a600355600d60ff0a60ff0a600455600d6101010a60ff0a600555600d6101000a6101010a600655600d60ff0a6101010a600755600d6101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sdiv0______f0994462e2dd8cc0e076a7379a5a88a01a40586601ff426717cf1d678cd4385d`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000305600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_18______5a677d007106e82a37e13f3560fa0e97f88bad6f826a0b63740fc4b25d0b5a15`() {
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
            "0x60126101000a600055601260ff0a60015560126101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_3______54eb95326b641250ce064811abbd4d246395a7fedaffa684b00c7667b04ec00c`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60036101000a6101000a600055600360ff0a6101000a60015560036101010a6101000a60025560036101000a60ff0a600355600360ff0a60ff0a60045560036101010a60ff0a60055560036101000a6101010a600655600360ff0a6101010a60075560036101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `signextend_AlmostBiggestByte______fbfe54fdecb381ce1abdf7dcd95076ae6a3ce4cdd49d414df4798399a536f517`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe0b600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `addmod3_0______45cf97d25ad676aeea9764fcff1d6e7ec78270b322af420c5a3a668f8807222f`() {
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
            "0x60026003600003600160040814600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mulmod2_0______e7772703144f24ed842d6df70931910c59e3cf48885caa204e1cfc66109d56aa`() {
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
            "0x60036001600560000309600360056000030714600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_29______eea0d96d36132886c8e85240f2ce145ee5d78888bfb08cbfc937c4eb29d76075`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x601d6101000a6101000a600055601d60ff0a6101000a600155601d6101010a6101000a600255601d6101000a60ff0a600355601d60ff0a60ff0a600455601d6101010a60ff0a600555601d6101000a6101010a600655601d60ff0a6101010a600755601d6101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `signextend_BigBytePlus1_2______ab3be4aeefd25904d80c1a58bec3280e86ce66085d4871343424179945748003`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60ff68f000000000000000010b600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `add1______d67a2f100d1736e3bc391e1ed2aea12f7fe8b1b9009c854c07c188c70a28d0cf`() {
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
            "0x60047fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `addmod1______2ff6c05f22a0669f6a2cbfe5d7706c016e3849448e53e6261251584908c4f683`() {
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
            "0x60026002600003600160000308600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_22______6c41658d1a70ae8cbafb18046c8863fdf6d5b2ecd6fedaac9597d0b23580ddc9`() {
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
            "0x60166101000a600055601660ff0a60015560166101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_10______21b4b949d4f8bc1ab587529fc2373e244edd0374433a99ef3b288334d65adb9b`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x600a6101000a6101000a600055600a60ff0a6101000a600155600a6101010a6101000a600255600a6101000a60ff0a600355600a60ff0a60ff0a600455600a6101010a60ff0a600555600a6101000a6101010a600655600a60ff0a6101010a600755600a6101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sdiv3______0b700f5943e191289b5c0bee1e9c8d4cae53ef77c61f055af8df241c94d2d8a0`() {
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
            "0x6002600003600405600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sdivByZero0______8527a93d7cd284bffde534c9240234c0325249bc55a94cbc7bbee86e0abc6a3c`() {
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
            "0x6000600003600360000305600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mulmod1_overflow3______cea734f62c2074f0e7220b0a22f7cffe76276077677881ecbcc503a8a9b624b7`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x600560027f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff09600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expXY_success______671a3326670385e9a6a354d8b382a4b62cdd57425bc6d6e67384360f61a67510`() {
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
            "0x6000356000556020356001556001546000540a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_0______005d6e42bfd4e4c18da7d75bdaa44190606fd695395f0758c89c9911ab5218c5`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60006101000a6101000a600055600060ff0a6101000a60015560006101010a6101000a60025560006101000a60ff0a600355600060ff0a60ff0a60045560006101010a60ff0a60055560006101000a6101010a600655600060ff0a6101010a60075560006101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `div1______aad64e6d9e7887c570b9203d54147d896b21832207288f19a71473bf9539cd13`() {
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
            "0x60027ffedcba9876543210fedcba9876543210fedcba9876543210fedcba98765432100460005260206000f3"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `add2______4f9cfe5905693f7a54fedaa484e51920df01a064e3c9c5bd1e479d506060787d`() {
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
            "0x60017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_8______c1a5c8ebaaa46926bf87a4cfe02f647400e739fac7761296761beaf6ae2ac0b0`() {
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
            "0x60086101000a600055600860ff0a60015560086101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf2_256______12737b4806aed49d7ab7eb74ddda1f35510496a85e1e478a3704f75b24ee136f`() {
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
            "0x61010060020a60005560ff60020a60015561010160020a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf2_128______07c52f2c971e3f0c01c5e6ff304223399f96a48fcdc3434fa2a0938124de37b3`() {
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
            "0x608060020a600055607f60020a600155608160020a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `addmod2______0d2340969d1058d6112d1aaaafd1e242260a075b9801fc37576ce9df1cf847f1`() {
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
            "0x60036001600660000308600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_21______c1c01fc64a2e345e6bb31672d7f8bc063b652f80d0f75002d1c49d36a9c7b3bb`() {
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
            "0x60156101000a600055601560ff0a60015560156101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `not1______e3aa182b2227b5b90343ecfd84d5e7ecdc8ef49a282262a4651d4809aafc6e67`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x6201e2406000526000511960005260206000f3"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `smod1______d9e61a2b0310599d823b17276f69995d294e799066503dcd6bd06a62b6b17c7f`() {
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
            "0x6003600003600507600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `divByZero______5872a3754ed6c302fcba58fd2332eb0e9d1eaebac9e83d906e5317f10711de16`() {
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
            "0x6000600204600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `exp2______bd970c7eba2b9d704a1afd3831e8c17073a5c1080806048085d89dccdbee0bfa`() {
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
            "0x637fffffff637fffffff0a600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mul0______45cd7403ec890b29ae80f0d74b103c96059310c00ecc103470031fd88875573c`() {
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
            "0x6003600202600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_17______f8e9fd0755c46024b28013f53f8259f6dd3827cc79db275a26c326cfcc6e92d6`() {
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
            "0x60116101000a600055601160ff0a60015560116101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `smod_i256min2______2482d9bf2796986ef35654b87d92ccc1132251b51dc9ad3d8bde2e45e8659d56`() {
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
            "0x600160016000037f80000000000000000000000000000000000000000000000000000000000000006000030703600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `fibbonacci_unrolled______6ca8d6f0f1975e8ffe105ae83d44902ae15cc738402d3921eda5194feac10303`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x6001600181810181810181810181810181810181810181810181810181810181810181810181810181810181810181810181810181810160005260206000f3"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mod3______e8738afe9d6d4a8e2a3f430ea09cfcaa563a4779254b91c81374e5a297409634`() {
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
            "0x6000600306600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_26______466a34547f08dfadfe7b8170595dbcd4a85e8841d60e17d45535efadf41e6a24`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x601a6101000a6101000a600055601a60ff0a6101000a600155601a6101010a6101000a600255601a6101000a60ff0a600355601a60ff0a60ff0a600455601a6101010a60ff0a600555601a6101000a6101010a600655601a60ff0a6101010a600755601a6101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_4______c2d1ac475be3d9708dd091aeee22a87804a4004cbe6a382c63f1d4d304764b57`() {
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
            "0x60046101000a600055600460ff0a60015560046101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_30______479e812da82943e323dfedc14ea5728ff43add90f4b8440158a12862c97a54f2`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x601e6101000a6101000a600055601e60ff0a6101000a600155601e6101010a6101000a600255601e6101000a60ff0a600355601e60ff0a60ff0a600455601e6101010a60ff0a600555601e6101000a6101010a600655601e60ff0a6101010a600755601e6101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sub4______05d9e4b327336db04e1b79dd21df56bd61361029dd7b4efb33e94315f6f1fe42`() {
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
            "0x60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff03600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `signextend_BitIsNotSet______ad6c39d9aab1ff75cc4d29e0952352a880d3239b3dcd9ac284b8738fac7debe9`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x62122f6a60000b600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_31______c0c9812a4aec910c25f698f7851d356969417e40a66756b8579024fb5ad6946c`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x601f6101000a6101000a600055601f60ff0a6101000a600155601f6101010a6101000a600255601f6101000a60ff0a600355601f60ff0a60ff0a600455601f6101010a60ff0a600555601f6101000a6101010a600655601f60ff0a6101010a600755601f6101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `signextend_BitIsSetInHigherByte______ac72667a2e447bdbe107272ec54041d01f13e9d0ad67be9f35ceb797fa8fa3d9`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x6212faf460010b600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_5______6146ceb91510b1cb9c01dab28929f5c50ab7351b971631b79b4e55ec4f9d0758`() {
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
            "0x60056101000a600055600560ff0a60015560056101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_27______4cb84dd85410e6e10a6fb0903c5336c92f1f3b1183b37b0d69793ab6eeff538a`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x601b6101000a6101000a600055601b60ff0a6101000a600155601b6101010a6101000a600255601b6101000a60ff0a600355601b60ff0a60ff0a600455601b6101010a60ff0a600555601b6101000a6101010a600655601b60ff0a6101010a600755601b6101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf2_2______a2bac0fecd9bb22498ef34248c689e040dff1c9551695bb52490005655252a90`() {
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
            "0x600260020a600055600160020a600155600360020a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `addmodDivByZero______07a2c67042f0a0a767dabddeff135071990a3121c53e59388d423f7312d97732`() {
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
            "0x60006001600408600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mod2______1f5ca72bfa3c2c922df107ec65b03875606654bc9323bbe4d0d6917cc70b78a0`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600006600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mul1______62739e6b84ff552b35b894761b28b32935dd20af24275507ba8fb2823e21a3fa`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff02600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_16______9b8e345adf5a89c6fd364d4f668a7bd07dafbe8d54035b530c17592ffc0a7867`() {
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
            "0x60106101000a600055601060ff0a60015560106101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `exp3______60cc7f7666a3c4ef52e3af53332f1cf55f8a6b0bffe0395fa9236bb58d6600d8`() {
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
            "0x637fffffff60000a600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `smod0______657d85189406a5174b2e2c8d2a156aa8bd3844d715a6a21cca3f977769de8ddf`() {
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
            "0x6003600003600560000307600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_20______d1c3af7ccb5c6194e2169b9e2f961b10e1899b7fefde762a18e4962171293562`() {
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
            "0x60146101000a600055601460ff0a60015560146101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `addmod3______90b707def53d6810926ea7b4b409adf597e5ab856e36916ad59bd0080b3493c1`() {
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
            "0x60036000036001600408600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_9______1c9cbff4e50f2007147b4c1ee0f4f1bce34cc34003bdf76c682d6f8fe096a842`() {
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
            "0x60096101000a600055600960ff0a60015560096101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `add3______3bd86a492ae4e00b1432d5458d920592919816b61704a200a619a4519dc033f6`() {
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
            "0x6000600001600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_1______cfa261cd17404f41ad16a6c50f85e826ba31c9ef0f4fb07330baccb7fceaf896`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60016101000a6101000a600055600160ff0a6101000a60015560016101010a6101000a60025560016101000a60ff0a600355600160ff0a60ff0a60045560016101010a60ff0a60055560016101000a6101010a600655600160ff0a6101010a60075560016101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mulmod1_overflow2______39bbcf3f466015094b1966b488fb130f5f43e7f754742dcd73ab9fe36b175140`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x600560027f800000000000000000000000000000000000000000000000000000000000000009600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sdiv2______f23ddbb1007d7edd1cc43aa31e6754f5bffc664fd470d83d4ba9c5d73f92e05a`() {
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
            "0x6004600003600260000305600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sdivByZero1______da488af1640adb0d5fe53576afb146ba3e48b79d6fb20ebc0a723810c957347c`() {
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
            "0x60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000305600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_11______0b1366d68a11bbb8b60d5458d1c5f75983c677beda062040a2a12217dcd6dd92`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x600b6101000a6101000a600055600b60ff0a6101000a600155600b6101010a6101000a600255600b6101000a60ff0a600355600b60ff0a60ff0a600455600b6101010a60ff0a600555600b6101000a6101010a600655600b60ff0a6101010a600755600b6101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `divByZero_2______78d75e4a3fa542827bcd7d0ea0219c73036b1894b4f4f1d2db5115e9d6b82245`() {
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
            "0x60076000600d0401600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `smod7______a36ed55f2f8ba020ce5a62ef6e40d293dd21f437a822cd6f33b5525c8af00c8c`() {
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
            BigInteger("2710", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000307600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `addmodDivByZero3______9d7b88296068c5ed1620b7eaad6d1790e9140bd888ff108169d44055223777a3`() {
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
            "0x60016000600060000803600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sdiv9______18566af59c50610c4d0730ca3171edb8079ef515fe3580e356caf81401a54bab`() {
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
            "0x6001600160000305600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `exp4______3e3173753802a0d3265703667247f978ebbe5f0e2d22c9cf94f0c09efb3a2ac2`() {
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
            "0x6000637fffffff0a600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mulmod1______ed3024180ecf5192c2c72e6c0e0c646a31121a9c2d81f8fc661cc404c2c49175`() {
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
            "0x60036002600003600160000309600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_11______b1c6926a4ec774b5eb1dc422f228e11e96f892b8bbb40a525ba97ac9f30b610a`() {
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
            "0x600b6101000a600055600b60ff0a600155600b6101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mul6______93939ec6ec2137f19afdb9596236ff35ae94068ba39563ed649153ed975d8a9d`() {
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
            "0x7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff02600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_20______c3555c8b166600d82076a8dace17cdba2e354cc84b92e88080ae847533a1f39e`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60146101000a6101000a600055601460ff0a6101000a60015560146101010a6101000a60025560146101000a60ff0a600355601460ff0a60ff0a60045560146101010a60ff0a60055560146101000a6101010a600655601460ff0a6101010a60075560146101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_2______c16dec87b8f5f4457c20c3ef8bba3a291ca99433d10c52a8c95844ae4c80f774`() {
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
            "0x60026101000a600055600260ff0a60015560026101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sub2______2a70037d8d25f8333be090608c64a57f9d894ba31647d9ca910f1d68f6f91d73`() {
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
            "0x6017600003600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `signextendInvalidByteNumber______fafb83f281612538c3b8a0ad616214c94f232a83b661ddeb2913d44c86c5e1f8`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x62126af460500b600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_16______7abe4db41b9db5ddba7e759a19f56721bfda3633d9a209a61885770b48730ba0`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60106101000a6101000a600055601060ff0a6101000a60015560106101010a6101000a60025560106101000a60ff0a600355601060ff0a60ff0a60045560106101010a60ff0a60055560106101000a6101010a600655601060ff0a6101010a60075560106101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `modByZero______60d18d29ddc0d3fada77384fd6a1fdb5c8db6f39cac1d49150133ad4c876111e`() {
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
            "0x6001600060030603600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `divByNonZero3______18eb2a03d9fb6139351c9348177f453fae7b4d0147cb61f0bc054cc94611fc79`() {
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
            "0x6001600104600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `exp8______8cc82dc5b40b6997018e4dd9ed813adc10d48b61aa086c3d44b89c02180d9286`() {
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
            "0x600060000a600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sdiv5______900ae8a1b5b71f5af75af223f8157cca4eac7224648cae647c2e9973be2db508`() {
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
            "0x60016000037f800000000000000000000000000000000000000000000000000000000000000060000305600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf2_16______d929b716ca2db29bb5383636946442ae3b248a8044221ae84cebd98b40bf3fa2`() {
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
            "0x601060020a600055600f60020a600155601160020a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_6______0b504c01aa8be1b0f4d75843a158f9ece56004fdfb31cbdd8ea631b19bd31c2e`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60066101000a6101000a600055600660ff0a6101000a60015560066101010a6101000a60025560066101000a60ff0a600355600660ff0a60ff0a60045560066101010a60ff0a60055560066101000a6101010a600655600660ff0a6101010a60075560066101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_31______49c27829894da6d63678e456733ea6fdc70f2757967ba5abbf180965428758ee`() {
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
            "0x601f6101000a600055601f60ff0a600155601f6101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sdiv_i256min2______90030696ae4a357369cc2782a28d4815a9935a9de909919b56b4a35e73a6fe1f`() {
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
            "0x60016000037f800000000000000000000000000000000000000000000000000000000000000060000305600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `addmod2_1______98bb343b4feee04868cc71c50989783b808acc50b1c98e7ade4776e994906b50`() {
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
            "0x60036001600660000308600360056000030614600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mulmoddivByZero1______a98185211df6a24ee07ad038dcac863c96507e63593dfa4ba40e268dec182118`() {
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
            "0x60006001600009600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `add4______84ab9087035c1a89c5fb97de39f5a70014a07ccd234033a86345e1023a9e3f63`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600101600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `addmodBigIntCast______08fea224001a172ce28f79d64d39b6ae2010c93b8db2a22eceaf648b4864410b`() {
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
            "0x600560017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff08600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_27______0b01e16cc7bd26138401de1bc3b8243c48d1b0a460b24a562fa58b5b6a2af2d1`() {
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
            "0x601b6101000a600055601b60ff0a600155601b6101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_26______6dccbbcb0ee8cd7d2f5843ad5ddf775a3226c7bf803ec5e6a6c6743745cf39a9`() {
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
            "0x601a6101000a600055601a60ff0a600155601a6101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mulUnderFlow______f00e90cf7a2da69a3d545bd6f562a8277dd75b34d1ef2c4a939be0f95768ec61`() {
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
            "0x600102600155"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mulmod3_0______0070f9a443a2322b95c7b5087c03809c2f1998b04ba560d40d23e94daef7f961`() {
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
            "0x60026003600003600160050914600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sdiv_i256min3______c515fc2566610c432b0de0dd441f64fa3786ed7b2f921e19ddd23ff00251d920`() {
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
            BigInteger("01", 16),
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6000037fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff05600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `addmod2_0______15d55915fdfbaed97e9812ea54813c07e1882f34b815255f6d795104a5320369`() {
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
            "0x60036001600660000308600360056000030714600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `stop______e2fb82d7e038c48bcb3dc482432600771264d43e043100f7c8ac802958a7e94f`() {
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
            "0x00"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `signextend_bitIsSet______079a0a92b727ced019553f0b8d57e0a53cf85803f09a10ea969030cfd302439a`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x62122ff460000b600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_30______48e0ff7a9fb61234eb98e08920d2f6edc07d27fb3d8ce297e801640882ba2a77`() {
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
            "0x601e6101000a600055601e60ff0a600155601e6101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sdiv_dejavu______6018ba5a8727b5f6c60678c66c95b410fcc2b2c14fe8b47e88aede7f66c73244`() {
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
            BigInteger("01", 16),
            BigInteger("989680", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x600560096000030580600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf2_8______b501d810365e03840b7f8635052551bd05c65ee103cdbd989438d3dbdcfb6ac3`() {
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
            "0x600860020a600055600760020a600155600960020a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_7______987100c02d0255c99706c19220a994ab2b46102fc6893ad08aca44c16626ce19`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60076101000a6101000a600055600760ff0a6101000a60015560076101010a6101000a60025560076101000a60ff0a600355600760ff0a60ff0a60045560076101010a60ff0a60055560076101000a6101010a600655600760ff0a6101010a60075560076101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expXY______b1f48c92fc069d4c6db24060394e4753fd7768e6d8c71dcf842e09536b0bf6a2`() {
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
            "0x6000356000556020356001556001546000540a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mulmod1_overflow4______e299f946769fce28c47007d1e2e2313465406917bacadaf1cfabf05f86db6844`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x600560027f800000000000000000000000000000000000000000000000000000000000000109600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sdiv4______3065d6c46735c24934865e9b79e22fb6f62c23bf23882402a1690dfe873bfe74`() {
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
            "0x6004600003600505600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `divByNonZero2______07c53576e7fa46c1ee1d5f30da0d479a49411004f70ea23881c6af61096d6347`() {
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
            "0x6018600004600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_17______d7a8e01c7d7ef07a3ab3091cf3116a4f6ec8efab1f5dabc6abdab919a3e96f08`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60116101000a6101000a600055601160ff0a6101000a60015560116101010a6101000a60025560116101000a60ff0a600355601160ff0a60ff0a60045560116101010a60ff0a60055560116101000a6101010a600655601160ff0a6101010a60075560116101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sub3______0e65bb014804438d489adaded93fa290d960a3c2400d795a7da572d8dd6c0e94`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600003600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_3______4ab92df5bf373064de3eeb8b359d28c9f1146673cf826d2ec82e531fc379a3e1`() {
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
            "0x60036101000a600055600360ff0a60015560036101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256Of256_21______10c6f39a124dba927aaa49875627683b285895b497464e74a1202217096e2089`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60156101000a6101000a600055601560ff0a6101000a60015560156101010a6101000a60025560156101000a60ff0a600355601560ff0a60ff0a60045560156101010a60ff0a60055560156101000a6101010a600655601560ff0a6101010a60075560156101010a6101010a600855"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf2_4______631f6dc2dc4c0da8fcd51e6b47631de57699ba5552f74bfffcf0c1db19ff0900`() {
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
            "0x600460020a600055600360020a600155600560020a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `signextend_00______f2d0e5f5e92b4fabe5f8849039ea24659f13dd41ab170684ac9ad4713806ccf6`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x600060000b600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mod4______1251fd388dafce899b3b8aaa3c1609354b876b279fb749c000888334946e9bc4`() {
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
            "0x6003600260000306600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `expPowerOf256_10______136a6ef3b914e46f9118f5d870a74dd1a4e9a3cfc97c84f412d81c07af01b036`() {
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
            "0x600a6101000a600055600a60ff0a600155600a6101010a600255"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mul7______68228cd9e856bee3481b095c8d1d2ab9fa30a0a1b1fbe697e3a8b01dfb6778e4`() {
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
            "0x7001234567890abcdef0fedcba09876543217001234567890abcdef0fedcba09876543217001234567890abcdef0fedcba0987654321020260005260206000f3"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `sdiv8______ea05e5ca26b556596f9d6e65f84d238632215eb308b26b1da829b48a4f07e9a1`() {
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
            "0x6001600003600160000305600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `exp5______e6fc1d5718f3d1bcbc540b19ad2c208aab3e582d581278b7d692ea4b733deecd`() {
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
            "0x60016101010a600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `mulmod0______15ef0419e36c1c1b45577f633dde9b4f4c0fc16258a46060ac228551fd5b9168`() {
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
            "0x60026002600109600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `addmodDivByZero2______ac86e7a61c79097514f97614f6afbd86d3f7d6e529c48b15a318ecbbf22e75f4`() {
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
            "0x60006000600108600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `arith1______e8665046be1f18c3372a4cdc4aab1ffc95156012239eaca43fd5c6c388f25075`() {
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
            BigInteger("0f4240", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x6001600190016007026005016002900460049060016021900560150160030260059007600303600960110a60005260086000f3"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

    @Test
    fun `smod6______23d40161e481cfa284f74d8d7a49de035d09bf5fc3f565f80292f804f92cf81f`() {
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
            "0x7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000307600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
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

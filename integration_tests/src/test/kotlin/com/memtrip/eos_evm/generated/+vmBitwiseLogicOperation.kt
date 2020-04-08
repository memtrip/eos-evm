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
// 04.04.2020
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

    private val rawAction = RawAction(chainApi)

    @Test
    fun `slt1______ed3559af4c3e3d1f16995417fd3ce8b2d5d289b2debd9d34e7d103af59a64f4a`() {
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
            "0x6002600003600012600055"
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
    fun `or2______2c00a57a80d580130b60d9deda2890eccef876d65ea95b4c43bbb1a4dd0cecd5`() {
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
            "0x6001600317600055"
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
    fun `sgt3______46e9db07c8df7ae98ca90780aeaf1b5a64a02cda8b54068c021dd897d8c56ab5`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600013600055"
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
    fun `xor2______cbff7fbed032981ae1743bb8965aaf666a481933ad201acde2a755b4e24ee7d7`() {
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
            "0x6001600318600055"
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
    fun `byte4______2ada67be185a5b95ca62844c81c52e64b00614d02b64cbf9253baf2a7566e2ae`() {
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
            "0x6780402010080402016004601f031a600055"
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
    fun `not5______0748608e64f72417803be26086c812c31a590a1a95f26e9af0bedc573bddf7e7`() {
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
            "0x600060000319600055"
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
    fun `eq2______ae4e87a6dad61b0aa93103ef5906eaeeb3733413e00cb1d2524ee7119383b375`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff14600055"
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
    fun `byte8______d8241a95a99ed5c0c39a8d26a9c809b0f62d56817af1fba2368cd2400f2e17a1`() {
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
            "0x678040201008040201601f601f031a600055"
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
    fun `and0______53831e569b6ec2b12b840d539617bd382a07e3700db75ba43d88b45c488abeea`() {
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
            "0x6002600216600055"
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
    fun `and1______d92d694f1df1088e777abdb7e6a441d9c71e4e634886410c4c65bff718a6f675`() {
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
            "0x6001600216600055"
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
    fun `byte9______29129062d256e9717217835274e382615224df82e97c8567aa472d206a2e4111`() {
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
            "0x6780402010080402016020601f051a600055"
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
    fun `not4______aee8ec9908daccb907c7076b988b58caffaa8ba68141534a0767d041fbfcb729`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000319600055"
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
    fun `byte5______c2f04b6c8ad9f10c1c6302aaa1b1faa4bb90e700d062d6cf2ad06f7f8009d115`() {
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
            "0x6780402010080402016005601f031a600055"
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
    fun `xor3______2e67a0c6dbf54b8eaa761a710775d8f516fb5d4afff97ec05f2bf2b0ca89e9a7`() {
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
            "0x7f0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff18600055"
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
    fun `sgt2______b9b0e8560b1da602351ee89d9385bd7bd33d19a5e4bc4ae1dbddc76ebf87a0ad`() {
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
            "0x60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff13600055"
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
    fun `or3______e86a2ab7088faca5e880fab11b2cf61601e941f621330eceec13296405f02e2b`() {
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
            "0x7f0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff17600055"
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
    fun `slt0______2fa0aa23a17f6f906146df0f152b09727ed44e560ba9ca9b357285f2ec0b38c3`() {
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
            "0x6000600260000312600055"
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
    fun `not3______98f29555aca23bee7693ee4962daafe489d8c024dfc8db3da4252ee438d15d64`() {
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
            "0x600260000319600055"
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
    fun `lt0______3f82794b3ab7a1381f800f045fe2a52a2c742a5bf5a0c262cfb6be574d305879`() {
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
            BigInteger("8ac7230489e80000", 16),
            "0x6000600260000310600055"
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
    fun `gt2______4b0191dbc7944ec9b47ede8560ad03500238397635dc897707fd45937b0d762b`() {
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
            "0x60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff11600055"
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
    fun `or4______0529771970ae1453127c9560e68b8274a9662ddf5684bdc7c6a5bd925fedbd27`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee17600055"
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
    fun `xor4______c3087ab19e23a572ebb996067c96ae4e3a83fbfe7a3253e347130c9767afb7be`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee18600055"
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
    fun `byte2______88e635fca6798de38b2831eaf5aa1d7ccc10a703006fc531c431a07a6f0ad9b7`() {
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
            "0x6780402010080402016002601f031a600055"
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
    fun `byte3______f182ba9431c0afa8951345caab69362ef0d08befe7af3ba46c0150f194528281`() {
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
            "0x6780402010080402016003601f031a600055"
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
    fun `xor5______208791127a38c44787ac9739f8e2d42eafcc94924b718326bb2f41c0641fe68e`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeefeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee18600055"
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
    fun `sgt4______952942a91ed7040913a6bb27488e09877b1c0eff4b14fcc9e515f8ffde6a2016`() {
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
            "0x6003600003600560000313600055"
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
    fun `or5______4c9eb19946147a54071f850e4812bd9b75e200b344b9bd27cb1d8af2c4674933`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeefeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee17600055"
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
    fun `gt3______2c4b8f3a0bd648007898638b2bf6ab5f170741704abc751161d5f90f0494d666`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600011600055"
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
    fun `lt1______63a727c86d3f482ccf6a02dbded8c26b306938192e9a6008f4ad74c7a5efd8fd`() {
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
            BigInteger("8ac7230489e80000", 16),
            "0x6002600003600010600055"
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
    fun `not2______324eba656aca54db2f9828012cc52c412e67ea3976e1e806698486b3f755b5eb`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff19600055"
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
    fun `and4______e21e8e11b9513679c36fd3f2877d5ef73d302169e669d42569e9b28e07ee85f5`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee16600055"
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
    fun `gt0______c17427d3c9acd0c27322e9bb49e967e2240aa803764c4ccf202d94ef4cb9939c`() {
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
            "0x6000600260000311600055"
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
    fun `iszero0______c7730a4eae5d80429b5e6a822a0c8c4dc6bece946d3d6902a5fddb2fc120fa04`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff15600055"
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
    fun `lt2______2e2c7923db8f0fc63497824b409ae8c0eba04c0e352fe50ae0a5cc00469d9498`() {
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
            BigInteger("8ac7230489e80000", 16),
            "0x60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff10600055"
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
    fun `not1______986682dadca33278653a19f30a97e9db367c671a612d67a4535d20510e2d625e`() {
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
            "0x600219600055"
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
    fun `byte0______ca8eddefff06f7e6cb91dd60e11a7dd107ced29e7c88ef06da7952e8cfd38d45`() {
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
            "0x6780402010080402016000601f031a600055"
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
    fun `slt4______ed936fea46872027bbe365872786c5ab0e1356dfae7bc9c81150fdaa86cb443f`() {
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
            "0x6003600003600560000312600055"
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
    fun `byte1______bb1c4e33835be3cbddbd232873e7ee350b4f971f725bf3b1c56c7e4f456d690a`() {
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
            "0x6780402010080402016001601f031a600055"
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
    fun `not0______3235e2a1af7340deea07b964fc3532b19092832b2c9592d3c777a659e97a01ba`() {
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
            "0x600019600055"
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
    fun `lt3______ba2bc4205d1ca31e29315edfc5708f300f44cb02936b9da05a9097b26f97d71a`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600010600055"
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
    fun `iszero1______1fc0ad71c14401598db2286ee499a76e21de97cbb63ee987afd5f603d34ef903`() {
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
            "0x600015600055"
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
    fun `gt1______98d2099f8676c20a4806282a1fbe0968231046a99e137070724adbc117447290`() {
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
            "0x6002600003600011600055"
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
    fun `byteBN______43da3e8490c4e2724415c26642284184fbbcb7e128d59d7693386f3da3c2d08e`() {
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
            "0x641234523456601f1a8001600155"
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
    fun `and5______1bbd8a8b90a8f84cb52e9514c9a02cd594e6e731065b54087cfa7afc9ccd2fc2`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeefeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee16600055"
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
    fun `byte6______2f99689c10d739d33cec8c8062c608a1b01c61686ca12f01d2e9fe2b73d1ee0f`() {
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
            "0x6780402010080402016006601f031a600055"
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
    fun `xor0______e08c105ef68171d063c469dd9b2a23da11aac894df3ee20271da79681250fc9b`() {
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
            "0x6002600218600055"
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
    fun `sgt1______671a4ef36d8c59426ca6b9eeb8cc46cfb41716888e2f2df3852eb03e9c14dbb1`() {
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
            "0x6002600003600013600055"
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
    fun `or0______dcc4012a46120cba05d501bbffe31a249fd5445b29b3f7e8e2133e9098e735e4`() {
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
            "0x6002600217600055"
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
    fun `slt3______32f573a07264be5090d1b383aac1d8803ab95f9420e0d8a849de627095f954ee`() {
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
            "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600012600055"
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
    fun `and2______b8c8c36bba987b4b5e5172ea00931076b8169ff8a8ff0d48244637c3dbe1eba1`() {
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
            "0x6001600316600055"
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
    fun `byte11______57be2a02bebea1ac84a6d1bbb3f15f0ab9d9339fa706131cd052c9275a0ec871`() {
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
            "0x67804020100804020160001a600055"
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
    fun `iszeo2______4e5ea4236cff2cb1176ad44dba65cb26dec72438acaa1e35600292b1bee87a71`() {
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
            "0x600260000315600055"
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
    fun `eq0______e9cd05b4ad632b287637f3682cb5bd3d39957b0a859fcaf2740c3a84bff603f2`() {
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
            "0x6003600003600560000314600055"
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
    fun `eq1______71d72425d2c1777c6991d09b38aed473c3dc3b9b370b8397c0d48e68a29b3aac`() {
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
            "0x6000600014600055"
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
    fun `byte10______866a8493a1363ce7e4595429147e8892ee6abb300fe15732d93c8d6b5c3c84f7`() {
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
            "0x6780402010080402017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1a600055"
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
    fun `and3______d37be2fe655f6f4348e3ab48e7b0f832505ab4800835a50e516c726bc6f59cf1`() {
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
            "0x7f0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff16600055"
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
    fun `slt2______92e953b3e18b0939fd97afb7875129e10860293931b9cb840b50f1559489ac16`() {
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
            "0x60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff12600055"
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
    fun `or1______791c257002ce8dd940a5391775fd4eac1836f7eb55304f658a32485f79d4993f`() {
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
            "0x6001600217600055"
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
    fun `sgt0______c5194500b062e2d1bf6dd6607185c661b6500d51c7146603f7f4ed31795b5d23`() {
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
            "0x6000600260000313600055"
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
    fun `xor1______417302c7876ef9a5209b50fcbd9ea4a70ca3d74748ed4f92f0c3164c0584c313`() {
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
            "0x6001600218600055"
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
    fun `byte7______c4d404f87e398a368fb2b0cb2165358ecdd92a97a2bbffcd0f8e833fc942976b`() {
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
            "0x6780402010080402016007601f031a600055"
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

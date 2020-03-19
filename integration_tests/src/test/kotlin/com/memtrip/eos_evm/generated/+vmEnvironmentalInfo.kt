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
// 19.03.2020
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

    private val testCases: TestCases = TestCases()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val rawAction = RawAction(chainApi)

    @Test
    fun `calldataload_BigOffset______e118bc308ccdd052ea601f5cfa51d32fc907952cb1cd16e673bff87f8c9fe203`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x7f420000000000000000000000000000000000000000000000000000000000000035600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldatacopy2______3acb5771658d79d6ff4e17b69cfeea9bcc5e51ab11afb0c511b4d7be801e71d4`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60006001600037600051600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `address0______37a0fc3337fde7233f427195a290be689e01aa752a8394b0ae56306fd97d3624`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x30600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldatacopy2_return______4268c07197871b5b5c14bcda3f746a2bb787c8dba2d987bf3c1fb0bc1fc4db4c`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60006001600037600051600055596000f3"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldataload2______0274681bf0559ab144aa2273cd566d1b32bcc58843ca142e8c6e6fd567196882`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x600535600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `origin______4d51cb9ee576e04b08a74a6a4ba3f10284ee1f735dd068abd7a0e551324f45be`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x32600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldatacopy_DataIndexTooHigh______72c5c7337895354e6d12b41ef4f144db87f945068a1a20134168f7e63f61a0d7`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60ff7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600037600051600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `address1______2f317db88316ea284d36c3031d82818be81d6cf63d1bba9437dd22705282fe27`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x30600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldatacopyUnderFlow______55ea90b15f19bf8f4838c35234d202eab4473284e5895af23b885368f34200a1`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x6001600237"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldatacopy_DataIndexTooHigh_return______640a52c64dfe9f43c6c5bb1aa4fc2a95839f352533e95fabe5493ff142b210c7`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60ff7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600037600051600055596000f3"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `caller______79214a9fde65ef8c878dbf8e03a06a75483536d289ad19e56b95fdef57b1da3d`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x33600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `gasprice______b94e3c994e54e24b85ef80fc16f53827cd26ef01fa4a96908a20e646f57d1e48`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("075bcd15", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x3a600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `codecopy0______9354634ed14a9667c8c883c3a4eceaae263bcd3d4fe47683aa0f38f45fe877e9`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60056000600039600051600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldatacopyZeroMemExpansion_return______b00f6239c55457bfec8870ad2ffaa42b2b53228c4f610eba391b8ce561dc9d4f`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60006000600037600051600055596000f3"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldatacopy1_return______671deccb615f7d6e58bc195d11ad4fde489a6a07581f9e32e029e6cf42dba991`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60016001600037600051600055596000f3"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldatasize2______cbd842b7c2ff77d176d3d7b5f200e908c22e47ee9a7d0f5294be85c917119f1e`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x36600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `codecopyZeroMemExpansion______41a8841a95018c2d228db91d29d0b75992f9a166e4207362e79d17229974ddfd`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60006000600039600051600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldatacopy_sec______9c7568cda862ed10722f83b99c948af03cb38ae4042d45fa55aae12cca979f88`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x6005565b005b6042601f536101036000601f3760005180606014600357640badc0ffee60ff55"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldatasize1______7db2dda9d80c7eac5ae82d3e2573e7f9b47ad6cb0c5545824e2500e85ec1cc3c`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x36600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldatacopyZeroMemExpansion______99d8509de4a25c88abd0647c68310552c67f395a92f4e6a8e67cc3707af076c5`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60006000600037600051600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `codecopy_DataIndexTooHigh______f6fac567f89aaca85c34c5a88b98870d1f7e2509b26ec566232c5d107741c6f4`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60087ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600039600051600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `codesize______632259bbd9962abfa58ec3b9e7b80a8f3babcdb47592bbc511fa5e4c0bc3ce3f`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x38600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldataloadSizeTooHighPartial______8090196f324f686f77a7d362987f8697cfc7b6b3bd86d702a212d790ec12ef0f`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x600a35600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldatacopy_DataIndexTooHigh2______bf92d18c0d12f1e9d48a5cf116ece7559ad36d67383a8b25792b4b6003180304`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60097ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600037600051600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldatasize0______e638e627686d20765a98fa8cfab03c642bdf33216a5869e742994072c8fd051e`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x36600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldataloadSizeTooHigh______0a556d7e2b38d3ac82c12938237c81673868011512d36133443339bc000d56c5`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa35600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldatacopy0______761871556943693860bdddd26da931c7c3f5a6c8ab95f680aa9d5854135dacd0`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60026001600037600051600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldatacopy0_return______4f9c0f3aff470ea35ad2fd5a81a593742f875409dbc51200199dd0f2baab261d`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60026001600037600051600055596000f3"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldataload0______3bfae7447ad076b4da51568b72acb70e9bd946fbf68a79705015c4600d9d99de`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x600035600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldatacopy_DataIndexTooHigh2_return______990882750573f3f5938a3f2cd66b0f41c842538f70d70045e179d246b8a076e0`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60097ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600037600051600055596000f3"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldataload1______3cda66b7abff563a2178c736c6ff9235784bbc4083083c1880268c1f32281606`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x600135600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `callvalue______4eabc176dc48df11702d9ddf6e8501c62035436adb16aa7cd79769ab273d583a`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x34600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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
    fun `calldatacopy1______65659a844a3d4458eb82347f1ef56c3657abdb06f7166b033329db7c2c8cdb78`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()
        val newEthAccount = EthAccount.create()

        setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey
        ).blockingGet()

        setupTransactions.createEthAccount(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        ).blockingGet()

        // when
        val transaction = EthereumTransaction(
            1,
            BigInteger("3b9aca00", 16),
            BigInteger("174876e800", 16),
            BigInteger("0de0b6b3a7640000", 16),
            "0x60016001600037600051600055"
        )
        val signedTransaction = transaction.sign(newEthAccount).signedTransaction.toHex()

        // then
        val response = rawAction.pushTransaction(
            newAccountName,
            signedTransaction,
            AccountIdentifier.create(newAccountName, newEthAccount.address).toHex(),
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

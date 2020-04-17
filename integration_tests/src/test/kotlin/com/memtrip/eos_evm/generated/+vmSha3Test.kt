import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.*
import com.memtrip.eos_evm.eos.state.GetAccountState
import com.memtrip.eos_evm.eos.actions.raw.RawAction
import com.memtrip.eos_evm.ethereum.EthereumTransaction
import com.memtrip.eos_evm.ethereum.toHexString
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

//
// 13.04.2020
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

    private val rawAction = RawAction(chainApi)

    private val getAccountState = GetAccountState(chainApi)

    @Test
    fun `sha3_0______55a13dc9cd0457c545a8ff9a046a83facd094f8bc1b0aa57a04d58a47f1cca2c`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("3b9aca00", 16),
                BigInteger("174876e800", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x6000600020600055"
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
        assertEquals("c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470", value_0x00)

    }
    @Test
    fun `sha3_memSizeNoQuadraticCost31______f3e15daec7cb9cd515321d21f091a8863aad12e0555b5d0a2ab01d345da4a609`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("01", 16),
                BigInteger("0100000000", 16),
                BigInteger("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", 16),
                "0x60016103c020600055"
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
        assertEquals("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a", value_0x00)

    }
    @Test
    fun `sha3_memSizeQuadraticCost63______c707d289675e51f41e5ddb0cfa077b7108e8e29550c5976b3eceb5da3038f7b2`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("01", 16),
                BigInteger("0100000000", 16),
                BigInteger("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", 16),
                "0x60016107c020600055"
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
        assertEquals("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a", value_0x00)

    }
    @Test
    fun `sha3_1______25997633273316ca1cf2258035f3cf723789e01c837f12095561c96a96d43fd8`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x6005600420600055"
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
        assertEquals("c41589e7559804ea4a2080dad19d876a024ccb05117835447d72ce08c1d020ec", value_0x00)

    }
    @Test
    fun `sha3_memSizeQuadraticCost65______2af3a55f4752f20404afb7c3a1c889d4c21d8b5581a382704e0421cec66aab9f`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("01", 16),
                BigInteger("0100000000", 16),
                BigInteger("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", 16),
                "0x600161080020600055"
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
        assertEquals("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a", value_0x00)

    }
    @Test
    fun `sha3_memSizeQuadraticCost32______ce67ec8d13841600bc8076b4136260645e72100c4eb9caab7cfaba6c22e143d2`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("01", 16),
                BigInteger("0100000000", 16),
                BigInteger("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", 16),
                "0x60016103e020600055"
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
        assertEquals("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a", value_0x00)

    }
    @Test
    fun `sha3_bigOffset______9df88aa7ae0baf4b6db458e8101233391101b3343a26dd91ff31335ea40a00dd`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("01", 16),
                BigInteger("010000000000", 16),
                BigInteger("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", 16),
                "0x60027e0fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff20600055"
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
    }
    @Test
    fun `sha3_6______db7522537756de38606a515817f7f953d63869199afbdb2ef97441a6500b6655`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff20600055"
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
    }
    @Test
    fun `sha3_memSizeQuadraticCost33______66fefc4166dd60603843813c9413995b2a0658047d0973cf1776a158581e9141`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("01", 16),
                BigInteger("0100000000", 16),
                BigInteger("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", 16),
                "0x600161040020600055"
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
        assertEquals("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a", value_0x00)

    }
    @Test
    fun `sha3_memSizeQuadraticCost64______b38d9ca851b3236eb73cb13cad9fea6e605e035f9d6f4628d20d190d9503f330`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("01", 16),
                BigInteger("0100000000", 16),
                BigInteger("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", 16),
                "0x60016107e020600055"
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
        assertEquals("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a", value_0x00)

    }
    @Test
    fun `sha3_memSizeQuadraticCost64_2______d185939aec4f4aae503167ad5a5f8b40aa65f4a532c2014ed9f905678cbbd3b3`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("01", 16),
                BigInteger("0100000000", 16),
                BigInteger("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", 16),
                "0x60206107e020600055"
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
        assertEquals("290decd9548b62a8d60345a988386fc84ba6bc95484008f6362f93160ef3e563", value_0x00)

    }
    @Test
    fun `sha3_4______f05a375db651dc62f2409f548bdd0db74a50cdc163feb25d1f65be155db69ea5`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x6064640fffffffff20600055"
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
    }
    @Test
    fun `sha3_5______58a094eff7761aa13888ad9b24ead0f78207f29b7b27ec19e07f9ab7ca3e6b57`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x640fffffffff61271020600055"
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
    }
    @Test
    fun `sha3_bigSize______794cb1a0b26deee9fb2c7a1bec1e0c6b499a91b9b6e2024f31ef10ade8074b52`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("01", 16),
                BigInteger("010000000000", 16),
                BigInteger("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", 16),
                "0x7effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff20600055"
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
    }
    @Test
    fun `sha3_2______296af237a14112e306707e5f8e6ef1c64c19f67c4bd35fbfabbfe5a94e3dd430`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x600a600a20600055"
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
        assertEquals("6bd2dd6bd408cbee33429358bf24fdc64612fbf8b1b4db604518f40ffd34b607", value_0x00)

    }
    @Test
    fun `sha3_memSizeQuadraticCost32_zeroSize______2da0644da1e2765b44f104b09873de52632c04765c752ee2428e215cae0c821c`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("01", 16),
                BigInteger("0100000000", 16),
                BigInteger("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", 16),
                "0x600061040020600055"
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
        assertEquals("c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470", value_0x00)

    }
    @Test
    fun `sha3_3______de2716629e8c598d97f20e648cce8062238e5a4c5b02d88386f72fd0d61cd905`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("5af3107a4000", 16),
                BigInteger("0186a0", 16),
                BigInteger("0de0b6b3a7640000", 16),
                "0x620fffff6103e820600055"
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
    }
    @Test
    fun `sha3_bigOffset2______6d4d1bdba5c2a7921d8c4c6145cf926eb73e32012534729620645a6d7c86c20a`() {

        val (accountName, accountIdentifier, response) = faultTolerantCreateAccount {
            // given
            val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

            // when
            val transaction = EthereumTransaction(
                1,
                BigInteger("01", 16),
                BigInteger("0100000000", 16),
                BigInteger("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", 16),
                "0x6002630100000020600055"
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
        assertEquals("54a8c0ab653c15bfb48b47fd011ba2b9617af01cb45cab344acd57c924d56798", value_0x00)

    }
}

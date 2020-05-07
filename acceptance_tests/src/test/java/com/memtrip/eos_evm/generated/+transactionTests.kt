import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.core.crypto.EosPrivateKey
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
import java.util.concurrent.TimeUnit
import com.memtrip.eos_evm.eos.TestTransaction
import com.memtrip.eos_evm.eos.faultTolerantCreateAccount
import com.memtrip.eos_evm.assertConsoleError

//
// 07.05.2020
// Auto generated based off the Ethereum tests found here:
// https://github.com/ethereum/tests/blob/develop/VMTests/
//
class TransactionTests {
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
    fun `ttRSValue______TransactionWithSvalue1`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xe115cf6bb5656786569dd273705242ca72d84bc0").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xe115cf6bb5656786569dd273705242ca72d84bc0")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f83f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a3664935301",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttRSValue______TransactionWithSvalueLargerThan_c_secp256k1n_x05`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x5ced92a94a7bfd7853b12d33ee59dd10ae94eb86").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x5ced92a94a7bfd7853b12d33ee59dd10ae94eb86")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a07fffffffffffffffffffffffffffffff5d576e7357a4501ddfe92f46681b20a1",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttRSValue______TransactionWithSvalueEqual_c_secp256k1n_x05`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xb284109d8e781949638d995c19f8feba0268191c").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xb284109d8e781949638d995c19f8feba0268191c")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a07fffffffffffffffffffffffffffffff5d576e7357a4501ddfe92f46681b20a0",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttRSValue______unpadedRValue`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xc1584838993ee7a9581cba0bced81785e8bb581d").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xc1584838993ee7a9581cba0bced81785e8bb581d")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f8880d8609184e72a00082f710947c47ef93268a311f4cad0c750724299e9b72c26880a4379607f500000000000000000000000000000000000000000000000000000000000000051c9f6ab6dda9f4df56ea45583af36660329147f1753f3724ea5eb9ed83e812ca77a0495701e230667832c8999e884e366a61028633ecf951e8cd66d119f381ae5718",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttRSValue______TransactionWithRSvalue1`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x98c188f183d4e93ff2bffadd145f39b4a792ed85").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x98c188f183d4e93ff2bffadd145f39b4a792ed85")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "df800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801b0101",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttRSValue______TransactionWithSvalueLessThan_c_secp256k1n_x05`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x33e931e187e9cb5b6f8560755519d54560dd63e8").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x33e931e187e9cb5b6f8560755519d54560dd63e8")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a07fffffffffffffffffffffffffffffff5d576e7357a4501ddfe92f46681b2090",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttRSValue______TransactionWithSvalueHigh`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x474869ba435affa1f45aaada48520880921c0887").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x474869ba435affa1f45aaada48520880921c0887")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364140",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttRSValue______TransactionWithRvalue1`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x54df0af0fd1d8ad90b5a13ff1f95463aec055bab").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x54df0af0fd1d8ad90b5a13ff1f95463aec055bab")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f83f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801b01a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttRSValue______TransactionWithRvaluePrefixed00`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x59805be0fb22cec65ee107f39f51d2a54cf8c522").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x59805be0fb22cec65ee107f39f51d2a54cf8c522")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f850800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801b910ebaaedce6af48a03bbfd25e8cd0364141a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttRSValue______TransactionWithSvaluePrefixed00`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xa825d77f343f31619c991cd7db5aaa6adbe9452e").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xa825d77f343f31619c991cd7db5aaa6adbe9452e")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f851800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a920ef0b28ad43601b4ab949f53faa07bd2c804",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttAddress______AddressLessThan20Prefixed0`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x2fbffb0b9f709fd1fa4db9ff7342f2e6b3b2b7a6").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x2fbffb0b9f709fd1fa4db9ff7342f2e6b3b2b7a6")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f85f800182520894000000000000000000000000000b9331677e6ebf0a801ca098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttGasPrice______TransactionWithHighGasPrice2`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x844d39aae4c81c546888ac8ca8dc29ddd3c040c9").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x844d39aae4c81c546888ac8ca8dc29ddd3c040c9")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f865808698852840a46f82520894095e7baea6a6c7c4c2dfeb977efac326af552d8780801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttVValue______V_equals37`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x2ea991808ba979ba103147edfd72304ebd95c028").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x2ea991808ba979ba103147edfd72304ebd95c028")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f865808698852840a46f82d6d894095e7baea6a6c7c4c2dfeb977efac326af552d87808025a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttVValue______V_overflow64bitSigned`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xfa7f04899691becd07dd3081d0a2f3ee7640af52").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xfa7f04899691becd07dd3081d0a2f3ee7640af52")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f85f030182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a801ca098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa08887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttEIP2028______DataTestSufficientGas2028`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xb42837109dfc0d8686bca0446112c8db63fdd40b").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xb42837109dfc0d8686bca0446112c8db63fdd40b")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f882800182540894095e7baea6a6c7c4c2dfeb977efac326af552d8780a3deadbeef0000000101010010101010101010101010101aaabbbbbbcccccccddddddddd1ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttSignature______Vitalik_3`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x2e485e0c23b4c3c542628a5f672eeab0ad4888be").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x2e485e0c23b4c3c542628a5f672eeab0ad4888be")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f864028504a817c80282f618943535353535353535353535353535353535353535088025a02d7c5bef027816a800da1736444fb58a807ef4c9603b7848673f7e3a68eb14a5a02d7c5bef027816a800da1736444fb58a807ef4c9603b7848673f7e3a68eb14a5",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttSignature______Vitalik_2`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x23ef145a395ea3fa3deb533b8a9e1b4c6c25d112").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x23ef145a395ea3fa3deb533b8a9e1b4c6c25d112")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f864018504a817c80182a410943535353535353535353535353535353535353535018025a0489efdaa54c0f20c7adf612882df0950f5a951637e0307cdcb4c672f298b8bcaa0489efdaa54c0f20c7adf612882df0950f5a951637e0307cdcb4c672f298b8bc6",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttSignature______Vitalik_5`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xf9358f2538fd5ccfeb848b64a96b743fcc930554").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xf9358f2538fd5ccfeb848b64a96b743fcc930554")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f865048504a817c80483019a28943535353535353535353535353535353535353535408025a013600b294191fc92924bb3ce4b969c1e7e2bab8f4c93c3fc6d0a51733df3c063a013600b294191fc92924bb3ce4b969c1e7e2bab8f4c93c3fc6d0a51733df3c060",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttSignature______Vitalik_10`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x9bddad43f934d313c2b79ca28a432dd2b7281029").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x9bddad43f934d313c2b79ca28a432dd2b7281029")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f867088504a817c8088302e2489435353535353535353535353535353535353535358202008025a064b1702d9298fee62dfeccc57d322a463ad55ca201256d01f62b45b2e1c21c12a064b1702d9298fee62dfeccc57d322a463ad55ca201256d01f62b45b2e1c21c10",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttSignature______Vitalik_9`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xd37922162ab7cea97c97a87551ed02c9a38b7332").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xd37922162ab7cea97c97a87551ed02c9a38b7332")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f867078504a817c807830290409435353535353535353535353535353535353535358201578025a052f1a9b320cab38e5da8a8f97989383aab0a49165fc91c737310e4f7e9821021a052f1a9b320cab38e5da8a8f97989383aab0a49165fc91c737310e4f7e9821021",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttSignature______Vitalik_8`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xf1f571dc362a0e5b2696b8e775f8491d3e50de35").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xf1f571dc362a0e5b2696b8e775f8491d3e50de35")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f866068504a817c80683023e3894353535353535353535353535353535353535353581d88025a06455bf8ea6e7463a1046a0b52804526e119b4bf5136279614e0b1e8e296a4e2fa06455bf8ea6e7463a1046a0b52804526e119b4bf5136279614e0b1e8e296a4e2d",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttSignature______RightVRSTest`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x58d79230fc81a042315da7d243272798e27cb40c").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x58d79230fc81a042315da7d243272798e27cb40c")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f85f030182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a801ca098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttSignature______Vitalik_11`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x3c24d7329e92f84f08556ceb6df1cdb0104ca49f").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x3c24d7329e92f84f08556ceb6df1cdb0104ca49f")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f867098504a817c809830334509435353535353535353535353535353535353535358202d98025a052f8f61201b2b11a78d6e866abc9c3db2ae8631fa656bfe5cb53668255367afba052f8f61201b2b11a78d6e866abc9c3db2ae8631fa656bfe5cb53668255367afb",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttSignature______Vitalik_4`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x82a88539669a3fd524d669e858935de5e5410cf0").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x82a88539669a3fd524d669e858935de5e5410cf0")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f865038504a817c803830148209435353535353535353535353535353535353535351b8025a02a80e1ef1d7842f27f2e6be0972bb708b9a135c38860dbe73c27c3486c34f4e0a02a80e1ef1d7842f27f2e6be0972bb708b9a135c38860dbe73c27c3486c34f4de",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttSignature______Vitalik_12`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x874b54a8bd152966d63f706bae1ffeb0411921e5").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x874b54a8bd152966d63f706bae1ffeb0411921e5")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f8610e80830493e080809560f2ff61000080610011600039610011565b6000f31ca0a310f4d0b26207db76ba4e1e6e7cf1857ee3aa8559bcbc399a6b09bfea2d30b4a06dff38c645a1486651a717ddf3daccb4fd9a630871ecea0758ddfcf2774f9bc6",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttSignature______Vitalik_7`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xa8f7aba377317440bc5b26198a363ad22af1f3a4").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xa8f7aba377317440bc5b26198a363ad22af1f3a4")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f865058504a817c8058301ec309435353535353535353535353535353535353535357d8025a04eebf77a833b30520287ddd9478ff51abbdffa30aa90a8d655dba0e8a79ce0c1a04eebf77a833b30520287ddd9478ff51abbdffa30aa90a8d655dba0e8a79ce0c1",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttSignature______libsecp256k1test`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x170ad78f26da62f591fa3fe3d54c30016167cbbf").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x170ad78f26da62f591fa3fe3d54c30016167cbbf")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "d1808609184e72a00082f3888080801b2c04",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttSignature______Vitalik_6`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xa8f7aba377317440bc5b26198a363ad22af1f3a4").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xa8f7aba377317440bc5b26198a363ad22af1f3a4")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f865058504a817c8058301ec309435353535353535353535353535353535353535357d8025a04eebf77a833b30520287ddd9478ff51abbdffa30aa90a8d655dba0e8a79ce0c1a04eebf77a833b30520287ddd9478ff51abbdffa30aa90a8d655dba0e8a79ce0c1",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttSignature______Vitalik_13`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x874b54a8bd152966d63f706bae1ffeb0411921e5").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x874b54a8bd152966d63f706bae1ffeb0411921e5")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f8660f80830493e09400000000000000000000000000000000000000c08086646f6e6b65791ba09f00c6da4f2e4b5f3316e70c7669f9df71fa21d533afa63450065731132ba7b6a03886c27a8b3515ab9e2e04492f8214718621421e92d3b6954d9e3fb409ead788",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttSignature______SenderTest`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x963f4a0d8a11b758de8d5b99ab4ac898d6438ea6").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x963f4a0d8a11b758de8d5b99ab4ac898d6438ea6")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870a801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttSignature______Vitalik_14`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x874b54a8bd152966d63f706bae1ffeb0411921e5").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x874b54a8bd152966d63f706bae1ffeb0411921e5")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f8610f80830493e080019560f3ff61000080610011600039610011565b6000f31ba0af2944b645e280a35789aacfce7e16a8d57b43a0076dfd564bdc0395e3576324a05272a0013f198713128bb0e3da43bb03ec7224c5509d4cabbe39fd31c36b5786",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttSignature______Vitalik_1`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xf0f6f18bca1b28cd68e4357452947e021241e9ce").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xf0f6f18bca1b28cd68e4357452947e021241e9ce")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f864808504a817c800825208943535353535353535353535353535353535353535808025a0044852b2a670ade5407e78fb2863c51de9fcb96542a07186fe3aeda6bb8a116da0044852b2a670ade5407e78fb2863c51de9fcb96542a07186fe3aeda6bb8a116d",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttNonce______TransactionWithHighNonce32`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xf3dac79274af6e51fbefe9d74a07bdef53d48ea1").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xf3dac79274af6e51fbefe9d74a07bdef53d48ea1")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f8648501000000000182520894095e7baea6a6c7c4c2dfeb977efac326af552d8780801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttData______DataTestZeroBytes`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x61adaba383a740078e3efbddf082be05534e5484").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x61adaba383a740078e3efbddf082be05534e5484")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f87c80018261a894095e7baea6a6c7c4c2dfeb977efac326af552d870a9d00000000000000000000000000000000000000000000000000000000001ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttData______DataTestLastZeroBytes`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x186f6d666993362b46b3b6c626f55903a439cc8d").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x186f6d666993362b46b3b6c626f55903a439cc8d")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f87c80018261a894095e7baea6a6c7c4c2dfeb977efac326af552d870a9d01000000000000000000000000000000000000000000000000000000001ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttData______dataTx_bcValidBlockTestFrontier`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xdf409d3d52c787d13836158a14672c989d5d8800").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xdf409d3d52c787d13836158a14672c989d5d8800")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f901fb803282c3508080b901ae60056013565b6101918061001d6000396000f35b3360008190555056006001600060e060020a6000350480630a874df61461003a57806341c0e1b514610058578063a02b161e14610066578063dbbdf0831461007757005b610045600435610149565b80600160a060020a031660005260206000f35b610060610161565b60006000f35b6100716004356100d4565b60006000f35b61008560043560243561008b565b60006000f35b600054600160a060020a031632600160a060020a031614156100ac576100b1565b6100d0565b8060018360005260205260406000208190555081600060005260206000a15b5050565b600054600160a060020a031633600160a060020a031614158015610118575033600160a060020a0316600182600052602052604060002054600160a060020a031614155b61012157610126565b610146565b600060018260005260205260406000208190555080600060005260206000a15b50565b60006001826000526020526040600020549050919050565b600054600160a060020a031633600160a060020a0316146101815761018f565b600054600160a060020a0316ff5b561ca0c5689ed1ad124753d54576dfb4b571465a41900a1dff4058d8adf16f752013d0a01221cbd70ec28c94a3b55ec771bcbc70778d6ee0b51ca7ea9514594c861b1884",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttData______DataTestEnoughGAS`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x1e42dc399dc122b1172fa3c3d9a9a0adabf7d026").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x1e42dc399dc122b1172fa3c3d9a9a0adabf7d026")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f86d80018259d894095e7baea6a6c7c4c2dfeb977efac326af552d870a8e0358ac39584bc98a7c979f984b031ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttData______DataTestFirstZeroBytes`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x67719a47cf3e3fe77b89c994d85395ad0f899d86").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x67719a47cf3e3fe77b89c994d85395ad0f899d86")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f87c80018261a894095e7baea6a6c7c4c2dfeb977efac326af552d870a9d00000000000000000000000000010000000000000000000000000000001ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttData______dataTx_bcValidBlockTest`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xdb3271a5b88f7bae59660418e25ce5d142f9b080").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xdb3271a5b88f7bae59660418e25ce5d142f9b080")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f901fc8032830138808080b901ae60056013565b6101918061001d6000396000f35b3360008190555056006001600060e060020a6000350480630a874df61461003a57806341c0e1b514610058578063a02b161e14610066578063dbbdf0831461007757005b610045600435610149565b80600160a060020a031660005260206000f35b610060610161565b60006000f35b6100716004356100d4565b60006000f35b61008560043560243561008b565b60006000f35b600054600160a060020a031632600160a060020a031614156100ac576100b1565b6100d0565b8060018360005260205260406000208190555081600060005260206000a15b5050565b600054600160a060020a031633600160a060020a031614158015610118575033600160a060020a0316600182600052602052604060002054600160a060020a031614155b61012157610126565b610146565b600060018260005260205260406000208190555080600060005260206000a15b50565b60006001826000526020526040600020549050919050565b600054600160a060020a031633600160a060020a0316146101815761018f565b600054600160a060020a0316ff5b561ca0c5689ed1ad124753d54576dfb4b571465a41900a1dff4058d8adf16f752013d0a01221cbd70ec28c94a3b55ec771bcbc70778d6ee0b51ca7ea9514594c861b1884",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttGasLimit______TransactionWithGasLimitOverflow63_1`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xcda94a77b8357ff651db2e3828216440c4b732e8").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xcda94a77b8357ff651db2e3828216440c4b732e8")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f865800188800000000000000194095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttGasLimit______TransactionWithGasLimitOverflow63`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xd28c6f0aca6656e828d1bc21a01904aa514932db").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xd28c6f0aca6656e828d1bc21a01904aa514932db")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f865800188800000000000000094095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttGasLimit______TransactionWithHighGas`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x03a3ce84aa05891249cde4fff6c82acb009af03f").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x03a3ce84aa05891249cde4fff6c82acb009af03f")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f8658001887fffffffffffffff94095e7baea6a6c7c4c2dfeb977efac326af552d8780801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttGasLimit______TransactionWithGasLimitxPriceOverflow2`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0x31352a0efde8bc120397e124e9f837e691b47ded").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0x31352a0efde8bc120397e124e9f837e691b47ded")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f86780873b9403b9403b5c8398968094095e7baea6a6c7c4c2dfeb977efac326af552d8780801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttGasLimit______TransactionWithHihghGasLimit63m1`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xbc3ed33da0fb6d392781b29e2b33135e944ffe16").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xbc3ed33da0fb6d392781b29e2b33135e944ffe16")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f8658001887fffffffffffffff94095e7baea6a6c7c4c2dfeb977efac326af552d87808025a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
    @Test
    fun `ttGasLimit______TransactionWithGasLimitOverflow2`() {
        // given
        val newAccountName = generateUniqueAccountName()
        val newAccountPrivateKey = EosPrivateKey()

        val createAccountResult= setupTransactions.createAccount(
            newAccountName,
            newAccountPrivateKey,
            17000
        ).blockingGet()
        assertEquals(202, createAccountResult.statusCode)

        val createEvmAccountResponse = setupTransactions.createEthAccount(
            newAccountName, newAccountPrivateKey, "0xd28c6f0aca6656e828d1bc21a01904aa514932db").blockingGet()
        assertEquals(202, createEvmAccountResponse.statusCode)

        val accountIdentifier = AccountIdentifier.create(newAccountName, "0xd28c6f0aca6656e828d1bc21a01904aa514932db")

        // when
        val response = faultTolerant {
            executeAction.pushTransaction(
               newAccountName,
               "f865800188800000000000000094095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804",
               accountIdentifier.toHexString(),
               "",
               TransactionContext(
                   newAccountName,
                   newAccountPrivateKey,
                   transactionDefaultExpiry()
               )
           ).blockingGet()
       }

       // then
       assertEquals(500, response.statusCode)
       response.assertConsoleError("assertion failure with message")
    }
}

package com.memtrip.evm.ethereum

import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.generateUniqueAccountName
import com.memtrip.evm.eos.AccountIdentifier
import com.memtrip.evm.eos.transactionDefaultExpiry
import com.memtrip.evm.eos.actions.raw.RawAction
import com.memtrip.evm.eos.evm.contracts.misc.TupleContract
import com.memtrip.evm.eos.state.GetAccount
import okhttp3.OkHttpClient
import org.junit.Assert.assertEquals
import org.junit.Ignore
import org.junit.Test
import org.web3j.crypto.Sign
import java.math.BigInteger
import java.util.concurrent.TimeUnit

/**
 * TEST IGNORED
 * A long running integration test that was used to diagnose an issue with signatures that contained leading 0's in the
 * R or S components. The bug has been resolved, and this test has been verified against 10,000 signatures.
 * LOOP 10,000 times
 * - create EOS account
 * - create EVM account
 * - publish raw EVM transaction
 * assert that the accountIdentifier could be resolved from signature bytes, and log any failures for debugging purposes.
 */
@Ignore
class MalformedTransactionDebugTest {

    private val okHttpClient = OkHttpClient.Builder()
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val getAccount = GetAccount(chainApi)

    private val rawAction = RawAction(chainApi)

    data class SignatureFailure(
        val eosAccountName: String,
        val ethAccount: EthAccount,
        val accountIdentifier: String,
        val privateKey: EosPrivateKey
    )

    data class RejectedSignature(
        val signatureBytes: String,
        val signedTransaction: String,
        val signatureData: Sign.SignatureData
    )

    @Test
    fun findRejectedSignatures() {
        val signatureFailures = ArrayList<SignatureFailure>()
        for (i in 0 until 10000) {
            val newAccountName = generateUniqueAccountName()
            val newAccountPrivateKey = EosPrivateKey()
            val newEthAccount = EthAccount.create()
            val accountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address).toHexString()
            setupTransactions.createAccount(newAccountName, newAccountPrivateKey, 170000).blockingGet()
            setupTransactions.createEthAccount(newAccountName, newAccountPrivateKey, newEthAccount).blockingGet()
            val contract = TupleContract(newAccountName, newAccountPrivateKey, newEthAccount)
            val createContractResponse = contract.createContract().blockingGet()
            if (createContractResponse.response.errorBody?.error?.details?.first()?.message?.contains("The account identifier associated with this transaction does not exist.") == true) {
                signatureFailures.add(
                    SignatureFailure(
                        newAccountName,
                        newEthAccount,
                        accountIdentifier,
                        newAccountPrivateKey
                    )
                )
            }
        }

        val rejectedSignatures = ArrayList<RejectedSignature>()
        if (signatureFailures.isNotEmpty()) {
            for (errorResult in signatureFailures) {
                val response = getAccount.getAccountIdentifier(errorResult.accountIdentifier.toHexBytes().pad256().toHexString()).blockingGet()
                val contract = TupleContract(errorResult.eosAccountName, errorResult.privateKey, errorResult.ethAccount)

                val transaction = EthereumTransaction(
                    1,
                    BigInteger("5af3107a4000", 16),
                    BigInteger("5186a00", 16),
                    BigInteger.valueOf(0),
                    "0x6080604052348015600f57600080fd5b5060da8061001e6000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063ab5ed15014602d575b600080fd5b60336049565b6040518082815260200191505060405180910390f35b6000806052605e565b50809150508091505090565b6000606060018090506040518060400160405280600281526020017f486900000000000000000000000000000000000000000000000000000000000081525091509150909156fea265627a7a7231582014e7a484ae72de63d610eee5700f82beb654743f08478ca0c91c5147159df3c764736f6c63430005100032"
                )

                val signedTransaction = transaction.sign(errorResult.ethAccount)

                rawAction.pushTransaction(
                    errorResult.eosAccountName,
                    signedTransaction.signedTransaction.toHexString(),
                    errorResult.accountIdentifier,
                    TransactionContext(errorResult.eosAccountName, errorResult.privateKey, transactionDefaultExpiry())
                )

                val createContractResponse = contract.createContract().blockingGet()
                if (createContractResponse.statusCode != 204 && response !is GetAccount.Record.None) {
                    rejectedSignatures.add(
                        RejectedSignature(
                            (signedTransaction.signature.v + signedTransaction.signature.r + signedTransaction.signature.s).toHexString(),
                            signedTransaction.signedTransaction.toHexString(),
                            signedTransaction.signature
                        )
                    )
                }
            }
        }

        rejectedSignatures.forEach {
            println("Signed transaction::")
            println(it.signedTransaction)
            println("V::")
            println(it.signatureData.v.toHexString())
            println("R::")
            println(it.signatureData.r.toHexString())
            println("S::")
            println(it.signatureData.s.toHexString())
            println("Signature bytes::")
            println(it.signatureBytes)
            println("")
        }

        assertEquals(0, rejectedSignatures.size)
    }
}
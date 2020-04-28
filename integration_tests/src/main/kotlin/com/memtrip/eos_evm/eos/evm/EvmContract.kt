package com.memtrip.eos_evm.eos.evm

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.*
import com.memtrip.eos_evm.eos.actions.raw.RawAction
import com.memtrip.eos_evm.ethereum.EthAccount
import com.memtrip.eos_evm.ethereum.EthereumTransaction
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import io.reactivex.Single
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.web3j.abi.FunctionEncoder
import org.web3j.abi.TypeReference
import org.web3j.abi.datatypes.Function
import java.math.BigInteger
import java.util.concurrent.TimeUnit
import org.web3j.abi.datatypes.Type

abstract class EvmContract(
    private val contractAccountName: String,
    private val contractPrivateKey: EosPrivateKey,
    private val contractEthAccount: EthAccount,
    private val data: String,
    private val gasPrice: BigInteger = BigInteger("5af3107a4000", 16),
    private val gasLimit: BigInteger = BigInteger("0186a00", 16)
) {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val rawAction = RawAction(chainApi)

    val accountIdentifier by lazy {
        AccountIdentifier.create(contractAccountName, contractEthAccount.address)
    }

    val contractAccountIdentifier = accountIdentifier.pad256().toHexString()

    protected fun create(parameters: List<Type<*>>): Single<ChainResponse<TransactionCommitted>> {
        val abiEncodedBytes = if (parameters.isNotEmpty()) FunctionEncoder.encodeConstructor(parameters) else ""
        val transaction = EthereumTransaction(
            1,
            gasPrice,
            gasLimit,
            BigInteger.valueOf(0),
            data + abiEncodedBytes
        )
        return rawAction.pushTransaction(
            contractAccountName,
            transaction.sign(contractEthAccount).signedTransaction.toHexString(),
            contractAccountIdentifier,
            TransactionContext(contractAccountName, contractPrivateKey, transactionDefaultExpiry())
        )
    }

    fun executeMethod(
        name: String,
        inputParameters: List<Type<*>>,
        outputParameters: List<TypeReference<Type<*>>>,
        sender: EvmSender
    ): Single<ChainResponse<TransactionCommitted>> {
        val abiEncodedBytes = encodeFunctionArgs(name, inputParameters, outputParameters)

        val callTransaction = EthereumTransaction(
            sender.nonce,
            gasPrice,
            gasLimit,
            sender.value,
            abiEncodedBytes,
            contractAccountIdentifier
        )

        return rawAction.pushTransaction(
            sender.eosAccountName,
            callTransaction.sign(sender.ethAccount).signedTransaction.toHexString(),
            sender.accountIdentifier,
            TransactionContext(sender.eosAccountName, sender.privateKey, transactionDefaultExpiry())
        )
    }

    private fun encodeFunctionArgs(
        name: String,
        inputParameters: List<Type<*>>,
        outputParameters: List<TypeReference<Type<*>>>
    ): String {
        return FunctionEncoder.encode(
            Function(
                name,
                inputParameters,
                outputParameters
            )
        )
    }
}
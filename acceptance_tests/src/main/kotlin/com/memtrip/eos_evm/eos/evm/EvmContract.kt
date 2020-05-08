package com.memtrip.eos_evm.eos.evm

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.chain.actions.transaction.TransactionContext
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.*
import com.memtrip.eos_evm.eos.actions.raw.RawAction
import com.memtrip.eos_evm.eos.evm.contracts.CreateResponse
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
    private val gasLimit: BigInteger = BigInteger("5186a00", 16)
) {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val rawAction = RawAction(chainApi)

    private val getCode = GetCode(chainApi)

    val ownerAccountIdentifier by lazy {
        AccountIdentifier.create(contractAccountName, contractEthAccount.address)
    }

    val ownerAccountIdentifierString32 = ownerAccountIdentifier.pad256().toHexString()

    private lateinit var parentAddress: String

    protected fun create(
        parameters: List<Type<*>> = listOf(),
        value: BigInteger = BigInteger.valueOf(0)
    ): Single<CreateResponse> {
        val abiEncodedBytes = if (parameters.isNotEmpty()) FunctionEncoder.encodeConstructor(parameters) else ""
        val transaction = EthereumTransaction(
            1,
            gasPrice,
            gasLimit,
            value,
            data + abiEncodedBytes
        )
        return rawAction.pushTransaction(
            contractAccountName,
            transaction.sign(contractEthAccount).signedTransaction.toHexString(),
            ownerAccountIdentifier.toHexString(),
            TransactionContext(contractAccountName, contractPrivateKey, transactionDefaultExpiry())
        ).flatMap { response ->
            val ownerAddress = ownerAccountIdentifier.pad256().toHexString()
            if (response.isSuccessful) {
                getCode.getAllByOwner(ownerAddress).map {
                    if (it is GetCode.Record.Multiple) {
                        parentAddress = it.items.last().address
                        CreateResponse(response, it.items, it.items.last().address)
                    } else {
                        CreateResponse(response, emptyList(), "")
                    }
                }
            } else {
                Single.just(CreateResponse(response, emptyList(), ""))
            }
        }
    }

    fun executeMethod(
        name: String,
        inputParameters: List<Type<*>>,
        outputParameters: List<TypeReference<*>>,
        sender: EvmSender
    ): Single<ChainResponse<TransactionCommitted>> {
        val abiEncodedBytes = encodeFunctionArgs(name, inputParameters, outputParameters)

        val callTransaction = EthereumTransaction(
            sender.nonce,
            gasPrice,
            gasLimit,
            sender.value,
            abiEncodedBytes,
            parentAddress
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
        outputParameters: List<TypeReference<*>>
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
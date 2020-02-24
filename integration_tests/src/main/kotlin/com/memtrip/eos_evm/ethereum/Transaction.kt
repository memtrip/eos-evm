package com.memtrip.eos_evm.ethereum

import org.web3j.crypto.*
import org.web3j.crypto.Sign.SignatureData
import org.web3j.rlp.RlpEncoder
import org.web3j.rlp.RlpList
import java.math.BigInteger

data class Transaction(
    val nonce: Long,
    val gasPrice: Long,
    val gasLimit: Long,
    val value: Long,
    val data: String,
    val address: String? = null
) {

    private fun createTransaction(): RawTransaction {
        if (address != null) {
            return RawTransaction.createTransaction(
                BigInteger.valueOf(nonce),
                BigInteger.valueOf(gasPrice),
                BigInteger.valueOf(gasLimit),
                address,
                data
            )
        } else {
            return RawTransaction.createContractTransaction(
                BigInteger.valueOf(nonce),
                BigInteger.valueOf(gasPrice),
                BigInteger.valueOf(gasLimit),
                BigInteger.valueOf(value),
                data
            )
        }
    }

    fun sign(ethAccount: EthAccount): SignedTransaction {

        val rawTransaction = createTransaction()

        val unsignedTransaction = TransactionEncoder.encode(
            createTransaction(),
            CHAIN_ID
        )

        val signatureData = Sign.signMessage(unsignedTransaction, ethAccount.keyPair)

        val eip155SignatureData: SignatureData = TransactionEncoder.createEip155SignatureData(
            signatureData,
            CHAIN_ID
        )

        val signedTransaction = encode(rawTransaction, eip155SignatureData)

        return SignedTransaction(
            this,
            eip155SignatureData,
            signedTransaction,
            unsignedTransaction,
            createKeccakDigest(unsignedTransaction),
            ethAccount.address
        )
    }

    private fun encode(rawTransaction: RawTransaction, signatureData: SignatureData): ByteArray {
        val values = TransactionEncoder.asRlpValues(rawTransaction, signatureData)
        val rlpList = RlpList(values)
        return RlpEncoder.encode(rlpList)
    }

    private fun createKeccakDigest(encodedTransaction: ByteArray): ByteArray {
        return Hash.sha3(encodedTransaction)
    }
}
package com.memtrip.evm.fixture.transaction.adapter

import com.memtrip.evm.remove0x
import com.memtrip.evm.pad256
import com.memtrip.evm.toHexBytes
import com.memtrip.evm.toHexString
import com.memtrip.evm.fixture.transaction.model.DecodedTransaction
import org.web3j.crypto.RawTransaction
import org.web3j.crypto.Sign
import org.web3j.crypto.SignedRawTransaction
import org.web3j.rlp.RlpDecoder
import org.web3j.rlp.RlpList
import org.web3j.rlp.RlpString
import org.web3j.utils.Numeric

class DecodeTransaction {

    fun decode(rlp: String): DecodedTransaction {
        val rawTransaction = rlpDecode(rlp)
        val toAddress = rawTransaction.to.remove0x()
        val resolvedToAddress = if (toAddress.isNotEmpty()) toAddress.toHexBytes().pad256().toHexString() else null
        return DecodedTransaction(
            rlp.remove0x(),
            if (resolvedToAddress != null) "TRANSACTION_CALL" else "TRANSACTION_CREATE",
            rawTransaction.nonce.toByteArray().pad256().toHexString(),
            rawTransaction.gasPrice.toByteArray().pad256().toHexString(),
            rawTransaction.gasLimit.toByteArray().pad256().toHexString(),
            rawTransaction.value.toByteArray().pad256().toHexString(),
            rawTransaction.data,
            resolvedToAddress,
            signature(rawTransaction)
        )
    }

    private fun signature(transaction: RawTransaction): DecodedTransaction.Signature? {
        return if (transaction is SignedRawTransaction) {
            DecodedTransaction.Signature(
                transaction.signatureData.v.pad256().toHexString(),
                transaction.signatureData.r.pad256().toHexString(),
                transaction.signatureData.s.pad256().toHexString()
            )
        } else {
            null
        }
    }

    private fun rlpDecode(hexTransaction: String): RawTransaction {
        val transaction = Numeric.hexStringToByteArray(hexTransaction)
        val rlpList = RlpDecoder.decode(transaction)
        val values = rlpList.values[0] as RlpList
        val nonce = (values.values[0] as RlpString).asPositiveBigInteger()
        val gasPrice = (values.values[1] as RlpString).asPositiveBigInteger()
        val gasLimit = (values.values[2] as RlpString).asPositiveBigInteger()
        val to = (values.values[3] as RlpString).asString()
        val value = (values.values[4] as RlpString).asPositiveBigInteger()
        val data = (values.values[5] as RlpString).asString()
        if (values.values.size == 6 || values.values.size == 8 && (values.values[7] as RlpString).bytes.size == 10 || values.values.size == 9 && (values.values[8] as RlpString).bytes.size == 10
        ) {
            // the 8th or 9nth element is the hex
            // representation of "restricted" for private transactions
            return RawTransaction.createTransaction(nonce, gasPrice, gasLimit, to, value, data)
        } else {
            val v = (values.values[6] as RlpString).bytes
            val r = (values.values[7] as RlpString).bytes
            val s = (values.values[8] as RlpString).bytes
            val signatureData = Sign.SignatureData(v, r, s)
            return SignedRawTransaction(
                nonce, gasPrice, gasLimit, to, value, data, signatureData
            )
        }
    }
}
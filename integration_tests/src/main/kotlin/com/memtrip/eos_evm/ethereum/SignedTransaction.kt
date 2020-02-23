package com.memtrip.eos_evm.ethereum

import org.web3j.crypto.Sign

@Suppress("ArrayInDataClass")
data class SignedTransaction(
    val transaction: Transaction,
    val signature: Sign.SignatureData,
    val signedTransaction: ByteArray,
    val unsignedTransaction: ByteArray,
    val digest: ByteArray,
    val address: String
) {

    fun encode() {
        print("encode")
    }
}
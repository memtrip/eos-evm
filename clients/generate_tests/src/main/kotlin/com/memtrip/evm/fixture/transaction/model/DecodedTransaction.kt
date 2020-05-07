package com.memtrip.evm.fixture.transaction.model

data class DecodedTransaction(
    val rlp: String,
    val type: String,
    val nonce: String,
    val gasPrice: String,
    val gasLimit: String,
    val value: String,
    val data: String,
    val toAddress: String?,
    val signature: Signature?
) {
    data class Signature(
        val v: String,
        val r: String,
        val s: String
    )
}
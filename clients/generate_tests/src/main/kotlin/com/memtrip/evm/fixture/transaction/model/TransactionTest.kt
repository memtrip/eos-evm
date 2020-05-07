package com.memtrip.evm.fixture.transaction.model

sealed class TransactionTest {
    data class Valid(
        val parentName: String,
        val name: String,
        val rlp: String,
        val type: String,
        val nonce: String,
        val gasPrice: String,
        val gasLimit: String,
        val value: String,
        val data: String,
        val toAddress: String?,
        val v: String?,
        val r: String?,
        val s: String?,
        val signatureAddress: String?
    ) : TransactionTest()
    data class HandledException(
        val parentName: String,
        val name: String,
        val rlp: String
    ) : TransactionTest()
}
package com.memtrip.evm.fixture.transaction.model

data class TransactionFixture(
    val rlp: String,
    val Byzantium: Sender,
    val Constantinople: Sender,
    val ConstantinopleFix: Sender,
    val EIP150: Sender,
    val EIP158: Sender,
    val Frontier: Sender,
    val Homestead: Sender,
    val Istanbul: Sender,
    val skip: Boolean
)
package com.memtrip.evm.fixture.transaction.model

data class RLPItem(
    val name: String,
    val rlp: String,
    val senderAddress: String?,
    val skip: Boolean
)
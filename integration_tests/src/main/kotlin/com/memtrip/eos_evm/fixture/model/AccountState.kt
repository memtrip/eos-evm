package com.memtrip.eos_evm.fixture.model

data class AccountState(
    val balance: String,
    val code: String,
    val nonce: String,
    val storage: Map<String, String>
)
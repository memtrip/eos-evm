package com.memtrip.evm.fixture.vm.model

data class AccountState(
    val balance: String?,
    val code: String?,
    val nonce: String?,
    val storage: Map<String, String>?,
    val reason: String?
)
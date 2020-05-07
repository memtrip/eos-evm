package com.memtrip.evm.fixture.vm.model

data class AccountStateParent(
    val address: String,
    val accountState: AccountState?,
    val failure: String?
)
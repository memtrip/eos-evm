package com.memtrip.evm.fixture.vm.model

data class VMFixture(
    val _info: Info,
    val env: Env,
    val exec: Exec,
    val gas: String,
    val logs: String,
    val out: String,
    val post: AccountStateParent,
    val pre: AccountStateParent
)
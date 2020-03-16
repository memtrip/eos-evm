package com.memtrip.eos_evm.fixture.model

data class Fixture(
    val _info: Info,
    val env: Env,
    val exec: Exec,
    val gas: String,
    val logs: String,
    val out: String,
    val post: AccountStateParent,
    val pre: AccountStateParent
)
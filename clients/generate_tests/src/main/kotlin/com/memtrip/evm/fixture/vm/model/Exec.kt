package com.memtrip.evm.fixture.vm.model

data class Exec(
    val address: String,
    val caller: String,
    val code: String,
    val data: String,
    val gas: String,
    val gasPrice: String,
    val origin: String,
    val value: String
)
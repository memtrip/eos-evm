package com.memtrip.evm.fixture.vm.model

data class Env(
    val currentCoinbase: String,
    val currentDifficulty: String,
    val currentGasLimit: String,
    val currentNumber: String,
    val currentTimestamp: String,
    val previousHash: String
)
package com.memtrip.eos_evm.fixture.model

data class Env(
    val currentCoinbase: String,
    val currentDifficulty: String,
    val currentGasLimit: String,
    val currentNumber: String,
    val currentTimestamp: String,
    val previousHash: String
)
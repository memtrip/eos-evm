package com.memtrip.eos_evm.eos

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.ethereum.EthereumTransaction
import java.lang.IllegalStateException
import java.math.BigInteger
import java.util.*
import kotlin.streams.asSequence

fun generateUniqueAccountName(): String {
    val source = "abcdefghijklmnopqrstuvwxyz"
    return Random().ints(12, 0, source.length)
        .asSequence()
        .map(source::get)
        .joinToString("")
}

object Config {
    const val CHAIN_API_BASE_URL = "http://localhost:8888/"
    const val SEED_PRIVATE_KEY = "5J8TXbmovr4mttQoZd6o7qAfJnvCcwumDJrPtVxbNZLY94UAq6B"
    const val CONTRACT_ACCOUNT_NAME = "eos.evm"
    const val SYMBOL = "EVM"
    const val FAULT_THRESHOLD = 3
    const val DEFAULT_RAM_ISSUE: Long = 7048
}

fun transactionDefaultExpiry(): Date = with(Calendar.getInstance()) {
    set(Calendar.MINUTE, get(Calendar.MINUTE) + 2)
    this
}.time

fun stubTransaction(): EthereumTransaction {
    return EthereumTransaction(
        1,
        BigInteger.valueOf(1000),
        BigInteger.valueOf(2000),
        BigInteger.valueOf(0),
        "0x000000000000000"
    )
}

fun <T> ChainResponse<T>.containsErrorString(value: String): Boolean {
    return errorBody?.error?.details?.get(0)?.message?.contains(value) ?: false
}

fun ChainResponse<TransactionCommitted>.containsConsoleString(value: String): Boolean {
    return isSuccessful && body?.processed?.action_traces?.first()?.console?.contains(value) == true
}
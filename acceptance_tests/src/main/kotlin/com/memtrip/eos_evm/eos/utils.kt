package com.memtrip.eos_evm.eos

import com.memtrip.eos_evm.ethereum.EthereumTransaction
import com.memtrip.eos_evm.ethereum.asciiToHex
import com.memtrip.eos_evm.ethereum.toHexBytes
import com.memtrip.eos_evm.ethereum.toHexString
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
    const val DEFAULT_RAM_ISSUE: Long = 8048
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

fun unit8ArrayToHex(uint8Array: String): String {
    val removePrecision = uint8Array.replace(".0", "")
    val removeLeftBracket = removePrecision.replace("[", "")
    val removeRightBracket = removeLeftBracket.replace("]", "")
    return removeRightBracket.split(",").map {
        (it.trim().toInt() and 0xFF).toByte()
    }.toByteArray().toHexString()
}

fun String.remove0x(): String {
    return if (startsWith("0x")) substring(2) else this
}
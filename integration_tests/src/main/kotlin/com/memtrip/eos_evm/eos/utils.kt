package com.memtrip.eos_evm.eos

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
    const val CHAIN_API_BASE_URL = "https://api.jungle.alohaeos.com:443/"
    const val ISSUE_PRIVATE_KEY = "5HvDsbgjH574GALj5gRcnscMfAGBQD9JSWn3sHFsD7bNrkqXqpr"
    const val CONTRACT_ACCOUNT_NAME = "memtripissue"
}

fun transactionDefaultExpiry(): Date = with(Calendar.getInstance()) {
    set(Calendar.MINUTE, get(Calendar.MINUTE) + 2)
    this
}.time
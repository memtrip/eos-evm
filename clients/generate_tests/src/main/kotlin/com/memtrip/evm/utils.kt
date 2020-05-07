package com.memtrip.evm

import com.memtrip.eos.core.hex.DefaultHexWriter
import com.memtrip.eos.core.hex.HexWriter

val HEX_WRITER: HexWriter = DefaultHexWriter()

fun ByteArray.toHexString(): String = HEX_WRITER.bytesToHex(this)

fun String.toHexBytes(): ByteArray = HEX_WRITER.hexToBytes(this)

fun ByteArray.pad256(): ByteArray {
    if (size == 32) return this
    val pad = 32 - size
    val newArray = ByteArray(32)
    newArray.fill(0x0, pad)
    copyInto(newArray, pad, 0)
    return newArray
}

fun String.remove0x(): String {
    return if (startsWith("0x")) substring(2) else this
}
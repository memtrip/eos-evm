package com.memtrip.eos_evm.ethereum

import com.memtrip.eos.core.hex.DefaultHexWriter
import com.memtrip.eos.core.hex.HexWriter

val HEX_WRITER: HexWriter = DefaultHexWriter()

fun ByteArray.toHex(): String = HEX_WRITER.bytesToHex(this)

fun String.toHex(): ByteArray = HEX_WRITER.hexToBytes(this)

fun String._0x(): String {
    return "0x$this"
}
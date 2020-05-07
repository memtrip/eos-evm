package com.memtrip.eos_evm.eos

import com.memtrip.eos.abi.writer.bytewriter.NameWriter

data class EosName(val value: String) {
    fun uint64(): String = NameWriter().eosNameAsLong(value).toString()
}
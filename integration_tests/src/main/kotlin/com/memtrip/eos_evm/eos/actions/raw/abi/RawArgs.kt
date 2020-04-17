package com.memtrip.eos_evm.eos.actions.raw.abi

import com.memtrip.eos.abi.writer.*

@Abi
data class RawArgs(
    val from: String,
    val code: String,
    val sender: String
) {

    val getFrom: String
        @AccountNameCompress get() = from

    val getCode: String
        @StringCompress get() = code

    val getSender: String
        @StringCompress get() = sender
}
package com.memtrip.evm.eos.actions.create.abi

import com.memtrip.eos.abi.writer.Abi
import com.memtrip.eos.abi.writer.AccountNameCompress
import com.memtrip.eos.abi.writer.StringCompress

@Abi
data class CreateArgs(
    val from: String,
    val message: String
) {

    val getFrom: String
        @AccountNameCompress get() = from

    val getMessage: String
        @StringCompress get() = message
}
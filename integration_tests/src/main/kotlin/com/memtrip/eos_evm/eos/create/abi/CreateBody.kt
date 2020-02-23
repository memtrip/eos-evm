package com.memtrip.eos_evm.eos.create.abi

import com.memtrip.eos.abi.writer.Abi
import com.memtrip.eos.abi.writer.ChildCompress

@Abi
data class CreateBody(
    val args: CreateArgs
) {

    val getArgs: CreateArgs
        @ChildCompress get() = args
}
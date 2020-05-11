package com.memtrip.evm.eos.actions.raw.abi

import com.memtrip.eos.abi.writer.Abi
import com.memtrip.eos.abi.writer.ChildCompress

@Abi
data class RawBody(
    val args: RawArgs
) {

    val getArgs: RawArgs
        @ChildCompress get() = args
}
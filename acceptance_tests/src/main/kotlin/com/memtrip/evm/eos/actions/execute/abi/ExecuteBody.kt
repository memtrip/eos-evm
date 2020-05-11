package com.memtrip.evm.eos.actions.execute.abi

import com.memtrip.eos.abi.writer.Abi
import com.memtrip.eos.abi.writer.ChildCompress

@Abi
data class ExecuteBody(
    val args: ExecuteArgs
) {

    val getArgs: ExecuteArgs
        @ChildCompress get() = args
}
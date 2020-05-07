package com.memtrip.eos_evm.eos.actions.withdraw.abi

import com.memtrip.eos.abi.writer.Abi
import com.memtrip.eos.abi.writer.ChildCompress

@Abi
data class WithdrawBody(
    val args: WithdrawArgs
) {

    val getArgs: WithdrawArgs
        @ChildCompress get() = args
}
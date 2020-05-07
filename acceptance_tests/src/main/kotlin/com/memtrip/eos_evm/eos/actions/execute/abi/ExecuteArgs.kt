package com.memtrip.eos_evm.eos.actions.execute.abi

import com.memtrip.eos.abi.writer.Abi
import com.memtrip.eos.abi.writer.AccountNameCompress
import com.memtrip.eos.abi.writer.DataCompress
import com.memtrip.eos.abi.writer.StringCompress

@Abi
data class ExecuteArgs(
    val from: String,
    val code: String,
    val sender: String,
    val bytecode: String
) {

    val getFrom: String
        @AccountNameCompress get() = from

    val getCode: String
        @DataCompress get() = code

    val getSender: String
        @StringCompress get() = sender

    val getBytecode: String
        @DataCompress get() = bytecode
}
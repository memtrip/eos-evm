package com.memtrip.evm.eos.actions.withdraw.abi

import com.memtrip.eos.abi.writer.Abi
import com.memtrip.eos.abi.writer.AccountNameCompress
import com.memtrip.eos.abi.writer.AssetCompress

@Abi
data class WithdrawArgs(
    val to: String,
    val quantity: String
) {

    val getTo: String
        @AccountNameCompress get() = to

    val getQuantity: String
        @AssetCompress get() = quantity
}
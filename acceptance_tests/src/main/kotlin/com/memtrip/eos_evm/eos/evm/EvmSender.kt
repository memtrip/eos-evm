package com.memtrip.eos_evm.eos.evm

import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos_evm.ethereum.EthAccount
import java.math.BigInteger

data class EvmSender(
    val nonce: Long,
    val ethAccount: EthAccount,
    val eosAccountName: String,
    val privateKey: EosPrivateKey,
    val accountIdentifier: String,
    val value: BigInteger = BigInteger.valueOf(0)
)
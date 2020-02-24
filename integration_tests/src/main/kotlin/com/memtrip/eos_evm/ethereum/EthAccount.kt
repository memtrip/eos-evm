package com.memtrip.eos_evm.ethereum

import org.web3j.crypto.*


data class EthAccount(
    val keyPair: ECKeyPair,
    val credentials: Credentials = Credentials.create(keyPair),
    val address: String = credentials.address
) {

    companion object {
        fun create(): EthAccount = EthAccount(Keys.createEcKeyPair())
    }
}
package com.memtrip.evm.ethereum

import org.web3j.crypto.ECKeyPair
import org.web3j.crypto.Credentials
import org.web3j.crypto.Keys

data class EthAccount(
    val keyPair: ECKeyPair,
    val credentials: Credentials = Credentials.create(keyPair),
    val address: String = credentials.address
) {

    companion object {
        fun create(): EthAccount = EthAccount(Keys.createEcKeyPair())
    }
}
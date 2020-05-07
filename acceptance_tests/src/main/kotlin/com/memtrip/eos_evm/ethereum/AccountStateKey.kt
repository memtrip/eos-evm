package com.memtrip.eos_evm.ethereum

import org.web3j.crypto.Hash
import java.math.BigInteger

object AccountStateKey {

    fun create(accountIdentifier: ByteArray, key: Long): String {
        return create(accountIdentifier, BigInteger.valueOf(key).toByteArray())
    }

    fun create(accountIdentifier: ByteArray, key: ByteArray): String {
        return Hash.sha3(accountIdentifier + key.pad256()).toHexString()
    }
}
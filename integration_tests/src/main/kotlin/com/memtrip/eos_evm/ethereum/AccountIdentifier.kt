package com.memtrip.eos_evm.ethereum

import org.web3j.crypto.Hash
import org.web3j.rlp.RlpEncoder
import org.web3j.rlp.RlpList
import org.web3j.rlp.RlpString
import org.web3j.rlp.RlpType
import java.util.ArrayList

object AccountIdentifier {

    fun create(name: String, address: String): ByteArray {

        val rlpList = RlpList(ArrayList<RlpType>().apply {
            add(RlpString.create(name))
            add(RlpString.create(address.toHex()))
        })

        val hash = Hash.sha3(RlpEncoder.encode(rlpList))

        return hash.sliceArray(12 until hash.size)
    }
}
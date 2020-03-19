package com.memtrip.eos_evm.ethereum

import org.junit.Test
import java.math.BigInteger

class EthereumTransactionTest {

    @Test
    fun signTransaction() {

        // given
        val transaction = EthereumTransaction(
            1,
            BigInteger.valueOf(1000),
            BigInteger.valueOf(2000),
            BigInteger.valueOf(0),
            "0x000000000000000"
        )

        // when
        val signedTransaction = transaction.sign(EthAccount.create())

        // then
        println("Unsigned transaction::")
        println(signedTransaction.unsignedTransaction.toHex())
        println("Signed transaction::")
        println(signedTransaction.signedTransaction.toHex())
        println("Digest::")
        println(signedTransaction.digest.toHex())
        println("Address::")
        println(signedTransaction.address)
        println("Signature v::")
        println(signedTransaction.signature.v.toHex())
    }
}
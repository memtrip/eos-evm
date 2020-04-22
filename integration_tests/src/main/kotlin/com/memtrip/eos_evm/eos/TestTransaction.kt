package com.memtrip.eos_evm.eos

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.eos_evm.eos.Config.FAULT_THRESHOLD
import java.lang.IllegalStateException

data class TestTransaction(
    val accountName: String,
    val accountIdentifier: ByteArray,
    val chain: ChainResponse<TransactionCommitted>
)

/**
 * In some cases the push_transaction request will respond before the test data seed transactions have been
 * included in a block. Rather than litter the code with arbitrary Thread.sleep(n), this method allows the
 * transaction under test to fail up to the THRESHOLD.
 */
fun faultTolerantCreateAccount(executor: () -> TestTransaction): TestTransaction {
    val threshold = FAULT_THRESHOLD
    for (i in 0 until threshold) {
        val response = executor()
        if (response.chain.isSuccessful || i >= threshold - 1) return response
    }
    throw IllegalStateException("not reachable")
}

fun faultTolerant(executor: () -> ChainResponse<TransactionCommitted>): ChainResponse<TransactionCommitted> {
    val threshold = FAULT_THRESHOLD
    for (i in 0 until threshold) {
        val response = executor()
        if (response.isSuccessful || i >= threshold - 1) return response
    }
    throw IllegalStateException("not reachable")
}
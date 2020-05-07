package com.memtrip.evm.fixture.transaction

import com.memtrip.evm.fixture.transaction.model.TransactionTest
import com.memtrip.evm.generate.FreemarkerMap
import java.util.Date
import kotlin.collections.HashMap

data class TransactionFreemarkerMap(
    private val validTests: List<TransactionTest.Valid>,
    private val handledExceptionTest: List<TransactionTest.HandledException>,
    private val unsignedTests: List<TransactionTest.Valid>
) : FreemarkerMap {

    override fun get(): Map<String, Any> {
        return HashMap<String, Any>().apply {
            put("validTests", validTests)
            put("handledExceptionTests", handledExceptionTest)
            put("unsignedTests", unsignedTests)
            put("lastUpdated", Date())
        }
    }
}
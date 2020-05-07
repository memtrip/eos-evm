package com.memtrip.evm.fixture.transaction

import com.memtrip.evm.files.ReadFiles
import com.memtrip.evm.fixture.transaction.model.TransactionTest

class TransactionTestCases(
    private val readFiles: ReadFiles = ReadFiles(),
    private val parseTransactionTests: ParseTransactionTests = ParseTransactionTests()
) {
    fun get(path: String): List<TransactionTest> = parseTransactionTests.parse(readFiles.read(path))
}
package com.memtrip.evm.fixture.transaction

import com.memtrip.evm.files.WriteFile
import com.memtrip.evm.fixture.transaction.model.TransactionTest
import com.memtrip.evm.generate.FreeMarker

class TransactionTestGenerator(
    private val transactionTestCases: TransactionTestCases = TransactionTestCases(),
    private val writeFile: WriteFile = WriteFile(),
    private val freeMarker: FreeMarker = FreeMarker()
) {

    fun generate(testDirectory: String, generatePath: String) {
        generateCppUnitTests(transactionTestCases.get(testDirectory), generatePath)
        generateKotlinIntegrationTests(transactionTestCases.get(testDirectory), generatePath)
    }

    private fun generateCppUnitTests(tests: List<TransactionTest>, generatePath: String) {
        val file = freeMarker.generate("transaction.tests.cpp.template",
            TransactionFreemarkerMap(
                tests.filterIsInstance<TransactionTest.Valid>(),
                tests.filterIsInstance<TransactionTest.HandledException>(),
                tests.filterIsInstance<TransactionTest.Valid>().filter {
                    it.signatureAddress != null
                }
            )
        )
        writeFile.writeFile(generatePath + "_transactionTests.test.cpp", file)
    }

    private fun generateKotlinIntegrationTests(tests: List<TransactionTest>, generatePath: String) {
        val file = freeMarker.generate("transaction.tests.kotlin.template",
            TransactionFreemarkerMap(
                tests.filterIsInstance<TransactionTest.Valid>(),
                tests.filterIsInstance<TransactionTest.HandledException>(),
                tests.filterIsInstance<TransactionTest.Valid>().filter {
                    it.signatureAddress != null
                }
            )
        )
        writeFile.writeFile("${generatePath}TransactionTests.kt", file)
    }
}
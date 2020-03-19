package com.memtrip.eos_evm.generate

import com.memtrip.eos_evm.files.WriteFile
import com.memtrip.eos_evm.fixture.TestCases
import com.memtrip.eos_evm.fixture.model.UnitTest

class GenerateVMTests(
    private val testCases: TestCases = TestCases(),
    private val writeFile: WriteFile = WriteFile(),
    private val freeMarker: FreeMarker = FreeMarker()
) {

    fun generate(testDirectory: String, generatePath: String) {
        testCases.get(testDirectory).groupBy {
            it.groupName
        }.values.forEach { tests ->
            val groupName = tests.first().groupName
            generateCppUnitTsts(groupName, tests, generatePath)
            generateKotlinIntegrationTests(groupName, tests, generatePath)
        }
    }

    private fun generateCppUnitTsts(groupName: String, tests: List<UnitTest>, generatePath: String) {
        val file = freeMarker.generate("vm.tests.cpp.template", DataMap(groupName, tests.map { unit ->
            unit.fixtureParent
        }))
        writeFile.writeFile(generatePath + "_" + tests.first().groupName + ".test.cpp", file)
    }

    private fun generateKotlinIntegrationTests(groupName: String, tests: List<UnitTest>, generatePath: String) {
        val file = freeMarker.generate("vm.tests.kotlin.template", DataMap(groupName, tests.map { unit ->
            unit.fixtureParent
        }))
        writeFile.writeFile(generatePath + "+" + tests.first().groupName + ".kt", file)
    }
}
package com.memtrip.evm.fixture.vm

import com.memtrip.evm.files.WriteFile
import com.memtrip.evm.fixture.vm.model.VMTest
import com.memtrip.evm.generate.FreeMarker

class VMTestGenerator(
    private val testCases: VMTestCases = VMTestCases(),
    private val writeFile: WriteFile = WriteFile(),
    private val freeMarker: FreeMarker = FreeMarker()
) {

    fun generate(testDirectory: String, generatePath: String) {
        testCases.get(testDirectory).groupBy {
            it.groupName
        }.values.forEach { tests ->
            val groupName = tests.first().groupName
            generateCppUnitTests(groupName, tests, generatePath)
            generateKotlinIntegrationTests(groupName, tests, generatePath)
        }
    }

    private fun generateCppUnitTests(groupName: String, tests: List<VMTest>, generatePath: String) {
        val file = freeMarker.generate("vm.tests.cpp.template",
            VMFreemarkerMap(groupName, tests.map { unit ->
                unit.fixtureParent
            })
        )
        writeFile.writeFile(generatePath + "_" + tests.first().groupName + ".test.cpp", file)
    }

    private fun generateKotlinIntegrationTests(groupName: String, tests: List<VMTest>, generatePath: String) {
        val file = freeMarker.generate("vm.tests.kotlin.template",
            VMFreemarkerMap(groupName, tests.map { unit ->
                unit.fixtureParent
            })
        )
        writeFile.writeFile(generatePath + "+" + tests.first().groupName + ".kt", file)
    }
}
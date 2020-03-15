package com.memtrip.eos_evm.generate

import com.memtrip.eos_evm.files.WriteFile
import com.memtrip.eos_evm.fixture.TestCases

class GenerateVMTests(
    private val testCases: TestCases = TestCases(),
    private val writeFile: WriteFile = WriteFile(),
    private val freeMarker: FreeMarker = FreeMarker()
) {

    fun generate(testDirectory: String, generatePath: String) {
        testCases.get(testDirectory).groupBy {
            it.groupName
        }.values.forEach {
            val file = freeMarker.generate("vm.tests.cpp.template", DataMap(it.map { unit ->
                unit.fixtureParent
            }))
            writeFile.writeFile(generatePath + "_" + it.first().groupName + ".test.cpp", file)
        }
    }
}
package com.memtrip.eos_evm.generate

import com.memtrip.eos_evm.files.WriteFile
import com.memtrip.eos_evm.fixture.TestCases

class GenerateVMTests(
    private val testCases: TestCases = TestCases(),
    private val writeFile: WriteFile = WriteFile(),
    private val freeMarker: FreeMarker = FreeMarker()
) {

    fun generate(testDirectory: String, generatePath: String) {
        val vmTests = testCases.get(testDirectory)
        val file = freeMarker.generate(
            "vm.tests.cpp.template",
            DataMap(vmTests.tests)
        )
        writeFile.writeFile(generatePath, file)
    }
}
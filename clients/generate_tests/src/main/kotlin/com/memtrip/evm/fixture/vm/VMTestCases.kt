package com.memtrip.evm.fixture.vm

import com.memtrip.evm.files.ReadFiles
import com.memtrip.evm.fixture.vm.model.VMTest

class VMTestCases(
    private val readFiles: ReadFiles = ReadFiles(),
    private val parseVMTests: ParseVMTests = ParseVMTests()
) {
    fun get(path: String): List<VMTest> = parseVMTests.parse(readFiles.read(path))
}
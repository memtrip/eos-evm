package com.memtrip.eos_evm.fixture

import com.memtrip.eos_evm.files.ReadFiles
import com.memtrip.eos_evm.fixture.model.VmTests

class TestCases(
    private val readFiles: ReadFiles = ReadFiles()
) {
    fun get(path: String): VmTests = ParseFixture().parse(readFiles.read(path))
}
package com.memtrip.eos_evm.fixture

import com.memtrip.eos_evm.files.ReadFiles
import com.memtrip.eos_evm.fixture.model.UnitTest

class TestCases(
    private val readFiles: ReadFiles = ReadFiles(),
    private val parseUnitTests: ParseUnitTests = ParseUnitTests()
) {
    fun get(path: String): List<UnitTest> = parseUnitTests.parse(readFiles.read(path))
}
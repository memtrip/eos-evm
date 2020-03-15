package com.memtrip.eos_evm.ethereum

import com.memtrip.eos_evm.generate.GenerateVMTests
import org.junit.Test

class VMTest {

    @Test
    fun generate() {
        GenerateVMTests().generate(
            "src/test/resources/tests/tests/VMTests",
            "build/"
        )
    }
}
package com.memtrip.eos_evm

import com.memtrip.eos_evm.generate.GenerateVMTests

fun main() {
    GenerateVMTests().generate(
        "src/test/resources/tests/tests/VMTests",
        "build/"
    )
}
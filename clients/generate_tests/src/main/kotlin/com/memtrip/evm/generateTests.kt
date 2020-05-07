@file:JvmName("GenerateTests")
package com.memtrip.evm

import com.memtrip.evm.fixture.transaction.TransactionTestGenerator
import com.memtrip.evm.fixture.vm.VMTestGenerator

fun main() {
    VMTestGenerator().generate(
        "src/main/resources/ethereum-tests/VMTests",
        "build/"
    )
    println(">> C++ unit tests generated in ./build")
    TransactionTestGenerator().generate(
        "src/main/resources/ethereum-tests/TransactionTests",
        "build/"
    )
    println(">> Kotlin acceptance tests generated in ./build")
}
package com.memtrip.eos_evm.ethereum

import com.memtrip.eos_evm.fixture.Fixtures
import org.junit.Test

class IntegrationTest {

    @Test
    fun ok() {
        val fixtures = Fixtures.get("src/test/resources/tests/VMTests")
    }
}
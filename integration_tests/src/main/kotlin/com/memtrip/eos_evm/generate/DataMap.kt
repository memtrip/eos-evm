package com.memtrip.eos_evm.generate

import com.memtrip.eos_evm.fixture.model.FixtureParent

data class DataMap(
    private val tests: List<FixtureParent>
) {

    fun get(): Map<String, Any> {
        return HashMap<String, Any>().apply {
            put("tests", tests)
        }
    }
}
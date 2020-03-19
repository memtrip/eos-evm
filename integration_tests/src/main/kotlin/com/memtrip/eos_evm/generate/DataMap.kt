package com.memtrip.eos_evm.generate

import com.memtrip.eos_evm.fixture.model.FixtureParent
import java.util.*
import kotlin.collections.HashMap

data class DataMap(
    private val groupName: String,
    private val tests: List<FixtureParent>
) {

    fun get(): Map<String, Any> {
        return HashMap<String, Any>().apply {
            put("tests", tests)
            put("groupName", groupName)
            put("lastUpdated", Date())
        }
    }
}
package com.memtrip.evm.fixture.vm

import com.memtrip.evm.fixture.vm.model.VMFixtureParent
import com.memtrip.evm.generate.FreemarkerMap
import java.util.Date
import kotlin.collections.HashMap

data class VMFreemarkerMap(
    private val groupName: String,
    private val tests: List<VMFixtureParent>
) : FreemarkerMap {

    override fun get(): Map<String, Any> {
        return HashMap<String, Any>().apply {
            put("tests", tests)
            put("groupName", groupName)
            put("lastUpdated", Date())
        }
    }
}
package com.memtrip.evm.fixture.vm.adapter

import com.memtrip.evm.fixture.vm.model.VMFixture
import com.memtrip.evm.fixture.vm.model.VMFixtureParent
import com.squareup.moshi.FromJson
import com.squareup.moshi.ToJson
import java.lang.IllegalStateException

class VMFixtureAdapter {

    @ToJson
    fun toJson(json: Map<String, VMFixture>): String {
        throw IllegalStateException("toJson not supported")
    }

    @FromJson
    fun fromJson(json: Map<String, VMFixture>): VMFixtureParent {
        val fixture = json.values.iterator().next()
        return VMFixtureParent(
            json.keys.first(),
            fixture
        )
    }
}
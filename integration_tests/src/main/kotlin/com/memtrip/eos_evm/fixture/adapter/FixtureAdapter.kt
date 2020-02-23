package com.memtrip.eos_evm.fixture.adapter

import com.memtrip.eos_evm.fixture.model.AccountState
import com.memtrip.eos_evm.fixture.model.Fixture
import com.memtrip.eos_evm.fixture.model.FixtureParent
import com.squareup.moshi.FromJson
import com.squareup.moshi.ToJson
import java.lang.IllegalStateException

class FixtureAdapter {

    @ToJson
    fun toJson(json: Map<String, AccountState>): String {
        throw IllegalStateException("toJson not supported")
    }

    @FromJson
    fun fromJson(json: Map<String, Fixture>): FixtureParent {
        val fixture = json.values.iterator().next();
        return FixtureParent(
            json.keys.first(),
            fixture
        )
    }
}
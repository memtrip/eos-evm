package com.memtrip.eos_evm.fixture

import com.memtrip.eos_evm.fixture.adapter.AccountAdapter
import com.memtrip.eos_evm.fixture.adapter.FixtureAdapter
import com.memtrip.eos_evm.fixture.model.FixtureParent
import com.memtrip.eos_evm.fixture.model.VmTests
import com.squareup.moshi.JsonAdapter
import com.squareup.moshi.Moshi
import java.lang.IllegalStateException

class ParseFixture(
    private val jsonAdapter: JsonAdapter<FixtureParent> = Moshi.Builder()
        .add(AccountAdapter())
        .add(FixtureAdapter())
        .build()
        .adapter(FixtureParent::class.java)
) {

    fun parse(files: List<String>): VmTests {
        return VmTests(files.map { fileBody ->
            jsonAdapter.fromJson(fileBody) ?: throw IllegalStateException("Failed to parse fixture.")
        })
    }
}
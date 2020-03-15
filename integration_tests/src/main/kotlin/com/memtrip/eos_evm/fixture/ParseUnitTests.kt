package com.memtrip.eos_evm.fixture

import com.memtrip.eos_evm.files.FileContext
import com.memtrip.eos_evm.fixture.adapter.AccountAdapter
import com.memtrip.eos_evm.fixture.adapter.FixtureAdapter
import com.memtrip.eos_evm.fixture.model.FixtureParent
import com.memtrip.eos_evm.fixture.model.UnitTest
import com.squareup.moshi.JsonAdapter
import com.squareup.moshi.Moshi
import java.lang.IllegalStateException

class ParseUnitTests(
    private val jsonAdapter: JsonAdapter<FixtureParent> = Moshi.Builder()
        .add(AccountAdapter())
        .add(FixtureAdapter())
        .build()
        .adapter(FixtureParent::class.java)
) {

    fun parse(files: List<FileContext>): List<UnitTest> {
        return files.map { file ->
            UnitTest(
                file.parentName,
                jsonAdapter.fromJson(file.body) ?: throw IllegalStateException("Failed to parse fixture.")
            )
        }
    }
}
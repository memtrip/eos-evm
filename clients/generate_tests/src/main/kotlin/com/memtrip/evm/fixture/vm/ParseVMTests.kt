package com.memtrip.evm.fixture.vm

import com.memtrip.evm.files.FileContext
import com.memtrip.evm.fixture.vm.adapter.AccountAdapter
import com.memtrip.evm.fixture.vm.adapter.VMFixtureAdapter
import com.memtrip.evm.fixture.vm.model.VMFixtureParent
import com.memtrip.evm.fixture.vm.model.VMTest
import com.squareup.moshi.JsonAdapter
import com.squareup.moshi.Moshi
import java.lang.IllegalStateException

class ParseVMTests(
    private val jsonAdapter: JsonAdapter<VMFixtureParent> = Moshi.Builder()
        .add(AccountAdapter())
        .add(VMFixtureAdapter())
        .build()
        .adapter(VMFixtureParent::class.java)
) {

    fun parse(files: List<FileContext>): List<VMTest> {
        return files.map { file ->
            VMTest(
                file.parentName,
                jsonAdapter.fromJson(file.body) ?: throw IllegalStateException("Failed to parse fixture.")
            )
        }
    }
}
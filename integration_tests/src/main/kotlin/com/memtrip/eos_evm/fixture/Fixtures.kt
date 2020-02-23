package com.memtrip.eos_evm.fixture

import com.memtrip.eos_evm.fixture.model.FixtureParent

object Fixtures {
    fun get(path: String): List<FixtureParent> = ParseFixture().parse(
        ReadFiles.read(
            path
        )
    )
}
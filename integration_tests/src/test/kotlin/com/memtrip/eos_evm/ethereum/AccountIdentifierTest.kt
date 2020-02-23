package com.memtrip.eos_evm.ethereum

import org.junit.Assert.assertEquals
import org.junit.Test

class AccountIdentifierTest {

    @Test
    fun `Create a valid account identifier`() {

        // given
        val name = "evm5"
        val address = "8d7332e9640fe8952e436dda2d5c2ac93d6870f3"

        // when
        val id = AccountIdentifier.create(name, address)

        // then
        assertEquals(
            "86a2700da1f451fa70a0dd52225f986d552eda0f",
            id.toHex()
        )
    }
}
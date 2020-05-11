package com.memtrip.evm.ethereum

import com.memtrip.evm.eos.AccountIdentifier
import org.junit.Assert.assertEquals
import org.junit.Test

class AccountIdentifierTest {

    @Test
    fun `Create a valid account identifier`() {

        // given
        val name = "evm2"
        val address = "0x3f56857646592ad99dfeaf09793137b727d33acb"

        // when
        val id = AccountIdentifier.create(name, address)

        // then
        assertEquals(
            "d4706907910db93a5cad49fd0edd88e53dfba20e",
            id.toHexString()
        )
    }
}
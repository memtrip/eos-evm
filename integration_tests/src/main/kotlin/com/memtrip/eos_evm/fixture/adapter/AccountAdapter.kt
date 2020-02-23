package com.memtrip.eos_evm.fixture.adapter

import com.memtrip.eos_evm.fixture.model.AccountState
import com.memtrip.eos_evm.fixture.model.AccountStateParent
import com.squareup.moshi.FromJson
import com.squareup.moshi.ToJson
import java.lang.IllegalStateException

class AccountAdapter {

    @ToJson
    fun toJson(json: Map<String, AccountState>): String {
        throw IllegalStateException("toJson not supported")
    }

    @FromJson
    fun fromJson(json: Map<String, AccountState>): AccountStateParent {
        val accountState = json.values.iterator().next();
        return AccountStateParent(
            json.keys.first(),
            AccountState(
                accountState.balance,
                accountState.code,
                accountState.nonce,
                accountState.storage
            )
        )
    }
}
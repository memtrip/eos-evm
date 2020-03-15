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
                padAccountStateValue(accountState.storage)
            )
        )
    }

    private fun padAccountStateValue(storage: Map<String, String>): Map<String, String> {
        return storage.entries.map {
            it.key to padAccountStateValue(it.value.substring(2))
        }.toMap()
    }

    private fun padAccountStateValue(accountStateValue: String): String {
        if (accountStateValue.isEmpty()) return accountStateValue
        return "0".repeat(64 - accountStateValue.length) + accountStateValue
    }
}
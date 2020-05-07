package com.memtrip.evm.fixture.transaction.adapter

import com.memtrip.evm.fixture.transaction.model.RLPItem
import com.memtrip.evm.fixture.transaction.model.TransactionFixture
import com.squareup.moshi.FromJson
import com.squareup.moshi.ToJson
import java.lang.IllegalStateException

class TransactionFixtureAdapter {

    @ToJson
    fun toJson(json: Map<String, TransactionFixture>): String {
        throw IllegalStateException("toJson not supported")
    }

    @FromJson
    fun fromJson(json: Map<String, TransactionFixture>): RLPItem {
        val fixture = json.values.iterator().next()
        return RLPItem(
            json.keys.first(),
            fixture.rlp,
            findSender(fixture),
            fixture.skip
        )
    }

    private fun findSender(transactionFixture: TransactionFixture): String? {
        if (transactionFixture.Byzantium.sender != null) return transactionFixture.Byzantium.sender
        if (transactionFixture.Constantinople.sender != null) return transactionFixture.Constantinople.sender
        if (transactionFixture.ConstantinopleFix.sender != null) return transactionFixture.ConstantinopleFix.sender
        if (transactionFixture.EIP150.sender != null) return transactionFixture.EIP150.sender
        if (transactionFixture.EIP158.sender != null) return transactionFixture.EIP158.sender
        if (transactionFixture.Frontier.sender != null) return transactionFixture.Frontier.sender
        if (transactionFixture.Homestead.sender != null) return transactionFixture.Homestead.sender
        if (transactionFixture.Istanbul.sender != null) return transactionFixture.Istanbul.sender
        return null
    }
}
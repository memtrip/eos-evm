package com.memtrip.eos_evm.eos.state

import com.memtrip.eos.http.rpc.ChainApi
import com.memtrip.eos.http.rpc.model.contract.request.GetTableRows
import com.memtrip.eos_evm.eos.Config
import io.reactivex.Single

class GetAccountState(
    private val chainApi: ChainApi
) {

    data class Item(
        val accountIdentifier: String,
        val key: String,
        val value: String
    )

    sealed class Record {
        data class Multiple(val items: List<Item>) : Record()
        object None : Record()
    }

    fun getAll(accountIdentifier: String): Single<Record> {
        return chainApi.getTableRows(
            GetTableRows(
                Config.CONTRACT_ACCOUNT_NAME,
                Config.CONTRACT_ACCOUNT_NAME,
                "accountstate",
                "stateid",
                true,
                1000,
                accountIdentifier,
                accountIdentifier,
                "sha256",
                "3",
                "dec"
            )
        ).map { response ->
            if (!response.isSuccessful) Record.None else {
                val tableRows = response.body()!!.rows
                if (tableRows.isEmpty()) Record.None else {
                    Record.Multiple(tableRows.mapIndexed { index, _ ->
                        Item(
                            tableRows[index]["accountIdentifier"].toString(),
                            tableRows[index]["key"].toString(),
                            tableRows[index]["value"].toString()
                        )
                    })
                }
            }
        }
    }

    fun getValue(accountName: String, key: String): Single<String> {
        return chainApi.getTableRows(
            GetTableRows(
                Config.CONTRACT_ACCOUNT_NAME,
                Config.CONTRACT_ACCOUNT_NAME,
                "accountstate",
                "statekey",
                true,
                1,
                key,
                key,
                "sha256",
                "2",
                "dec"
            )
        ).map { response ->
            if (response.isSuccessful) {
                val tableRows = response.body()!!.rows
                if (tableRows.isNotEmpty()) tableRows[0]["value"].toString() else ""
            } else {
                ""
            }
        }
    }
}
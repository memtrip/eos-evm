package com.memtrip.eos_evm.eos.state

import com.memtrip.eos.http.rpc.ChainApi
import com.memtrip.eos.http.rpc.model.contract.request.GetTableRows
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.EosName
import io.reactivex.Single

class GetAccount(
    private val chainApi: ChainApi
) {

    data class Item(
        val user: String,
        val nonce: String,
        val asset: String,
        val accountIdentifier: String
    )

    sealed class Record {
        data class Single(val item: Item) : Record()
        data class Multiple(val items: List<Item>) : Record()
        object None : Record()
    }

    fun getAccounts(): Single<Record> {
        return chainApi.getTableRows(
            GetTableRows(
                Config.CONTRACT_ACCOUNT_NAME,
                Config.CONTRACT_ACCOUNT_NAME,
                "account",
                "",
                true,
                1000,
                "",
                "",
                "",
                "",
                "dec"
            )
        ).map { response ->
            if (!response.isSuccessful) Record.None else {
                val tableRows = response.body()!!.rows
                if (tableRows.isEmpty()) Record.None else {
                    Record.Multiple(tableRows.mapIndexed { index, _ ->
                        Item(
                            tableRows[index]["user"].toString(),
                            tableRows[index]["nonce"].toString(),
                            tableRows[index]["asset"].toString(),
                            tableRows[index]["accountIdentifier"].toString()
                        )
                    })
                }
            }
        }
    }

    fun getAccount(name: String): Single<Record> {
        return chainApi.getTableRows(
            GetTableRows(
                Config.CONTRACT_ACCOUNT_NAME,
                Config.CONTRACT_ACCOUNT_NAME,
                "account",
                "",
                true,
                1,
                EosName(name).uint64(),
                EosName(name).uint64(),
                "",
                "",
                "dec"
            )
        ).map { response ->
            if (!response.isSuccessful) Record.None else {
                val tableRows = response.body()!!.rows
                if (tableRows.isEmpty()) Record.None else {
                    Record.Single(
                        Item(
                            tableRows[0]["user"].toString(),
                            tableRows[0]["nonce"].toString(),
                            tableRows[0]["asset"].toString(),
                            tableRows[0]["accountIdentifier"].toString()
                        )
                    )
                }
            }
        }
    }
}
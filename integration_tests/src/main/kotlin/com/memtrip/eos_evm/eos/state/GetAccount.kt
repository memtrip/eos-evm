package com.memtrip.eos_evm.eos.state

import com.memtrip.eos.http.rpc.ChainApi
import com.memtrip.eos.http.rpc.model.contract.request.GetTableRows
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.EosName
import com.memtrip.eos_evm.ethereum.EthAsset
import io.reactivex.Single

class GetAccount(
    private val chainApi: ChainApi
) {

    data class Item(
        val user: String,
        val nonce: String,
        val balance: EthAsset,
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
                            EthAsset.create(tableRows[index]["balance"].toString()),
                            tableRows[index]["accountIdentifier"].toString()
                        )
                    })
                }
            }
        }
    }

    fun getAccountIdentifier(accountIdentifier: String): Single<Record> {
        return chainApi.getTableRows(
            GetTableRows(
                Config.CONTRACT_ACCOUNT_NAME,
                Config.CONTRACT_ACCOUNT_NAME,
                "account",
                "accountid",
                true,
                1,
                accountIdentifier,
                accountIdentifier,
                "sha256",
                "2",
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
                            EthAsset.create(tableRows[0]["balance"].toString()),
                            tableRows[0]["accountIdentifier"].toString()
                        )
                    )
                }
            }
        }
    }

    fun getEvmAccount(name: String): Single<Record> {
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
                            EthAsset.create(tableRows[0]["balance"].toString()),
                            tableRows[0]["accountIdentifier"].toString()
                        )
                    )
                }
            }
        }
    }
}
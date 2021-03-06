package com.memtrip.evm.eos.evm

import com.memtrip.eos.http.rpc.ChainApi
import com.memtrip.eos.http.rpc.model.contract.request.GetTableRows
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.unit8ArrayToHex
import com.memtrip.evm.ethereum.EthAsset
import io.reactivex.Single

class GetCode(
    private val chainApi: ChainApi
) {

    data class Item(
        val code: String,
        val owner: String,
        val address: String,
        val balance: EthAsset,
        val nonce: String
    )

    sealed class Record {
        data class Value(val item: Item) : Record()
        data class Multiple(val items: List<Item>) : Record()
        object None : Record()
    }

    fun getValue(ownerAddress: String): Single<Record> {
        return chainApi.getTableRows(
            GetTableRows(
                Config.CONTRACT_ACCOUNT_NAME,
                Config.CONTRACT_ACCOUNT_NAME,
                "accountcode",
                "owneraddress",
                true,
                1,
                ownerAddress,
                ownerAddress,
                "sha256",
                "2",
                "dec"
            )
        ).map { response ->
            if (!response.isSuccessful) Record.None else {
                val tableRows = response.body()!!.rows
                if (tableRows.isEmpty()) Record.None else {
                    Record.Value(Item(
                            unit8ArrayToHex(tableRows[0]["code"].toString()),
                            tableRows[0]["owner"].toString(),
                            tableRows[0]["address"].toString(),
                            EthAsset.create(tableRows[0]["balance"].toString()),
                            tableRows[0]["nonce"].toString()
                    ))
                }
            }
        }
    }

    internal fun getAllByOwner(ownerAddress: String): Single<Record> {
        return chainApi.getTableRows(
            GetTableRows(
                Config.CONTRACT_ACCOUNT_NAME,
                Config.CONTRACT_ACCOUNT_NAME,
                "accountcode",
                "owneraddress",
                true,
                100,
                ownerAddress,
                ownerAddress,
                "sha256",
                "2",
                "dec"
            )
        ).map { response ->
            if (!response.isSuccessful) Record.None else {
                val tableRows = response.body()!!.rows
                if (tableRows.isEmpty()) Record.None else {
                    Record.Multiple(tableRows.mapIndexed { index, _ ->
                        Item(
                            unit8ArrayToHex(tableRows[index]["code"].toString()),
                            tableRows[index]["owner"].toString(),
                            tableRows[index]["address"].toString(),
                            EthAsset.create(tableRows[index]["balance"].toString()),
                            tableRows[index]["nonce"].toString()
                        )
                    })
                }
            }
        }
    }

    internal fun getByAddress(address: String): Single<Record> {
        return chainApi.getTableRows(
            GetTableRows(
                Config.CONTRACT_ACCOUNT_NAME,
                Config.CONTRACT_ACCOUNT_NAME,
                "accountcode",
                "codeaddress",
                true,
                100,
                address,
                address,
                "sha256",
                "3",
                "dec"
            )
        ).map { response ->
            if (!response.isSuccessful) Record.None else {
                val tableRows = response.body()!!.rows
                if (tableRows.isEmpty()) Record.None else {
                    Record.Value(
                        Item(
                            unit8ArrayToHex(tableRows.first()["code"].toString()),
                            tableRows.first()["owner"].toString(),
                            tableRows.first()["address"].toString(),
                            EthAsset.create(tableRows.first()["balance"].toString()),
                            tableRows.first()["nonce"].toString()
                        )
                    )
                }
            }
        }
    }
}
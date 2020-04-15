package com.memtrip.eos_evm.eos.state

import com.memtrip.eos.http.rpc.ChainApi
import com.memtrip.eos.http.rpc.model.contract.request.GetTableRows
import com.memtrip.eos_evm.eos.Config
import io.reactivex.Single

class GetCode(
    private val chainApi: ChainApi
) {

    sealed class Record {
        data class Value(val code: String, val address: String) : Record()
        object None : Record()
    }

    fun getValue(accountName: String, address: String): Single<Record> {
        return chainApi.getTableRows(
            GetTableRows(
                accountName,
                Config.CONTRACT_ACCOUNT_NAME,
                "accountcode",
                "codeaddress",
                true,
                1,
                address,
                address,
                "sha256",
                "2",
                "dec"
            )
        ).map { response ->
            if (response.isSuccessful) {
                val tableRows = response.body()!!.rows
                Record.Value(
                    if (tableRows.isNotEmpty()) tableRows[0]["code"].toString() else "",
                    if (tableRows.isNotEmpty()) tableRows[0]["accountIdentifier"].toString() else ""
                )
            } else {
                Record.None
            }
        }
    }
}
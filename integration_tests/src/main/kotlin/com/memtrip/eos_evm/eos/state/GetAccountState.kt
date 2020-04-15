package com.memtrip.eos_evm.eos.state

import com.memtrip.eos.http.rpc.ChainApi
import com.memtrip.eos.http.rpc.model.contract.request.GetTableRows
import com.memtrip.eos_evm.eos.Config
import io.reactivex.Single

class GetAccountState(
    private val chainApi: ChainApi
) {

    fun getValue(accountName: String, key: String): Single<String> {
        return chainApi.getTableRows(
            GetTableRows(
                accountName,
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
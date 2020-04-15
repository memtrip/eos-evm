package com.memtrip.eos_evm.eos.state

import com.memtrip.eos.http.rpc.ChainApi
import com.memtrip.eos.http.rpc.model.contract.request.GetTableRows
import com.memtrip.eos_evm.eos.Config
import io.reactivex.Single

class GetAccount(
    private val chainApi: ChainApi
) {

    fun getAll(): Single<String> {
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
            if (response.isSuccessful) {
                val tableRows = response.body()!!.rows
                ""
            } else {
                ""
            }
        }
    }
}
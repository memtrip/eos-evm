package com.memtrip.eos_evm

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import org.junit.Assert.fail

fun ChainResponse<TransactionCommitted>.assertConsoleString(value: String) {
    if (!isSuccessful) fail("transaction failed")
    val console = body?.processed?.action_traces?.first()?.console
    if (console == null) fail("no console output") else {
        if (!console.contains(value)) fail("[$value] not found in console string: [$console]")
    }
}

fun ChainResponse<TransactionCommitted>.assertNotConsoleString(value: String) {
    if (!isSuccessful) fail("transaction failed")
    val console = body?.processed?.action_traces?.first()?.console
    if (console == null) fail("no console output") else {
        if (console.contains(value)) fail("[$value] not found in console string: [$console]")
    }
}

fun ChainResponse<TransactionCommitted>.assertConsoleError(value: String) {
    if (isSuccessful) fail("transaction was successful")
    val message = errorBody?.error?.details?.get(0)?.message
    if (message == null) fail("no error message output") else {
        if (!message.contains(value)) fail("[$value] not found in error message string: [$message]")
    }
}
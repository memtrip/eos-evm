package com.memtrip.evm.fixture.transaction

import com.memtrip.evm.files.FileContext
import com.memtrip.evm.fixture.transaction.adapter.DecodeTransaction
import com.memtrip.evm.fixture.transaction.adapter.TransactionFixtureAdapter
import com.memtrip.evm.fixture.transaction.model.RLPItem
import com.memtrip.evm.fixture.transaction.model.TransactionTest
import com.squareup.moshi.JsonAdapter
import com.squareup.moshi.Moshi

class ParseTransactionTests(
    private val jsonAdapter: JsonAdapter<RLPItem> = Moshi.Builder()
        .add(TransactionFixtureAdapter())
        .build()
        .adapter(RLPItem::class.java),
    private val decodeTransaction: DecodeTransaction = DecodeTransaction()
) {

    data class RLPItemWithFileName(
        val fileName: String,
        val rlpItem: RLPItem
    )

    fun parse(files: List<FileContext>): List<TransactionTest> {
        return files.map { file ->
            val rlpItem = jsonAdapter.fromJson(file.body)
            if (rlpItem?.skip == true) null else {
                if (rlpItem != null) RLPItemWithFileName(
                    file.parentName.replace(
                        "\$",
                        ""
                    ), rlpItem
                )
                    else null
            }
        }.mapNotNull { it }.map { rlpItemWithFileName ->
            try {
                val decodedTransaction = decodeTransaction.decode(rlpItemWithFileName.rlpItem.rlp)
                TransactionTest.Valid(
                    rlpItemWithFileName.fileName,
                    rlpItemWithFileName.rlpItem.name,
                    decodedTransaction.rlp,
                    decodedTransaction.type,
                    decodedTransaction.nonce,
                    decodedTransaction.gasPrice,
                    decodedTransaction.gasLimit,
                    decodedTransaction.value,
                    decodedTransaction.data,
                    decodedTransaction.toAddress,
                    decodedTransaction.signature?.v,
                    decodedTransaction.signature?.r,
                    decodedTransaction.signature?.s,
                    rlpItemWithFileName.rlpItem.senderAddress
                )
            } catch (e: Exception) {
                TransactionTest.HandledException(
                    rlpItemWithFileName.fileName,
                    rlpItemWithFileName.rlpItem.name,
                    rlpItemWithFileName.rlpItem.rlp
                )
            }
        }
    }
}
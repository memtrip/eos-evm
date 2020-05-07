package com.memtrip.evm.files

import java.io.File

class WriteFile {

    fun writeFile(path: String, body: String) {
        File(path).printWriter().use { out ->
            body.lines().forEach {
                out.println(it)
            }
        }
    }
}
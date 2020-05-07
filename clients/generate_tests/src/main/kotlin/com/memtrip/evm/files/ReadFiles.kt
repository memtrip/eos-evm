package com.memtrip.evm.files

import java.io.File

class ReadFiles {

    fun read(path: String): List<FileContext> {
        val files = ArrayList<File>()
        File(path).collect(files)
        return files.map { FileContext(it.parentFile.name, it.readText()) }
    }

    private fun File.collect(collected: ArrayList<File>) {
        listFiles()?.forEach { file ->
            if (file.isDirectory) file.collect(collected) else collected.add(file)
        }
    }
}
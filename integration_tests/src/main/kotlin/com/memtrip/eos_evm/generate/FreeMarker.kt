package com.memtrip.eos_evm.generate

import freemarker.template.Configuration
import java.io.IOException
import java.io.StringWriter
import freemarker.template.TemplateException
import freemarker.template.TemplateExceptionHandler
import freemarker.template.Template


class FreeMarker(
    private val configuration: Configuration = createConfiguration()
) {

    fun generate(templateFileName:String, dataMap: DataMap): String = try  {
        process(templateFileName, dataMap.get())
    } catch (e: TemplateException) {
        throw IllegalStateException(
            "failed template: \n" + e.templateSourceName +
            "expression: \n" + e.blamedExpressionString +
            "line: \n" + e.lineNumber +
            "col: \n" + e.columnNumber
        )
    } catch (e: IOException) {
        throw IllegalStateException("Mapping freemarker template FAILED: \n" + e.message)
    }

    private fun process(templateFileName: String, map: Map<String, Any>): String {
        return StringWriter().use {
            getTemplate(templateFileName).process(map, it)
            it.toString()
        }
    }

    private fun getTemplate(fileName: String): Template = configuration.getTemplate(fileName)

    companion object {

        private const val TEMPLATE_ENCODING = "UTF-8"

        private fun createConfiguration(): Configuration = Configuration(Configuration.VERSION_2_3_21).apply {
            defaultEncoding = TEMPLATE_ENCODING
            templateExceptionHandler = TemplateExceptionHandler.RETHROW_HANDLER
            setClassForTemplateLoading(FreeMarker::class.java, "/")
        }
    }
}
package com.memtrip.evm.ethereum

import com.memtrip.evm.eos.Config.SYMBOL
import java.math.BigInteger

data class EthAsset(
    val hex: String,
    val weiValue: BigInteger,
    val assetValue: Long
) {

    override fun toString(): String {
        if (weiValue == BigInteger.valueOf(0)) return "0.0000 $SYMBOL"
        if (assetValue == 0L) return weiHexString()
        return assetString()
    }

    fun weiHexString(): String {
        return BigInteger(hex, 16).toByteArray().toHexString()
    }

    fun assetString(): String {
        val amountString = (assetValue.toDouble() / 10000).toString()
        val paddedAmountString = if (amountString.length < 6) amountString + "0".repeat(6 - amountString.length) else amountString
        return "$paddedAmountString $SYMBOL"
    }

    companion object {
        val WEI = BigInteger("00005AF3107A4000", 16) // wei / 10000 (i.e; .0000 precision)
        private val GWEI = BigInteger("3B9ACA00", 16)
        private val MICRO_ETHER = BigInteger("000000E8D4A51000", 16)
        private val MILLI_ETHER = BigInteger("00038D7EA4C68000", 16)
        private val ETHER = BigInteger("0DE0B6B3A7640000", 16)

        fun create(hex: String): EthAsset {
            val weiValue = BigInteger(hex, 16)
            val assetValue = weiValue / WEI
            return EthAsset(hex, weiValue, assetValue.toLong())
        }

        fun gwei(value: Long): BigInteger {
            return BigInteger.valueOf(value).multiply(GWEI)
        }

        fun microether(value: Long): BigInteger {
            return BigInteger.valueOf(value).multiply(MICRO_ETHER)
        }

        fun milliether(value: Long): BigInteger {
            return BigInteger.valueOf(value).multiply(MILLI_ETHER)
        }

        fun eth(value: Long): BigInteger {
            return BigInteger.valueOf(value).multiply(ETHER)
        }
    }
}
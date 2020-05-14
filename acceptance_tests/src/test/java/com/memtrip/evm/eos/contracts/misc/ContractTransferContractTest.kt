package com.memtrip.evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.assertConsoleString
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.contracts.misc.ContractTransferContract
import com.memtrip.evm.eos.faultTolerant
import com.memtrip.evm.eos.evm.GetCode
import com.memtrip.evm.ethereum.EthAsset
import com.memtrip.evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Test
import java.util.concurrent.TimeUnit

class ContractTransferContractTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val getCode = GetCode(chainApi)

    @Test
    fun `The ContractTransfer contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val contract = ContractTransferContract(newAccountName, newAccountPrivateKey, newEthAccount)

        // when
        val createContract = contract.createContract(EthAsset.milliether(300)).blockingGet()

        // then
        assertEquals(202, createContract.statusCode)

        // and when
        assertEquals(1, createContract.code.size)
        assertEquals(
            "608060405234801561001057600080fd5b50600436106100365760003560e01c8063150a06da1461003b5780638a4068dd14610059575b600080fd5b610043610063565b6040518082815260200191505060405180910390f35b61006161010d565b005b6000600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1663b69ef8a86040518163ffffffff1660e01b815260040160206040518083038186803b1580156100cd57600080fd5b505afa1580156100e1573d6000803e3d6000fd5b505050506040513d60208110156100f757600080fd5b8101908080519060200190929190505050905090565b600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1663a9059cbb600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff166000546040518363ffffffff1660e01b8152600401808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200182815260200192505050600060405180830381600087803b1580156101da57600080fd5b505af11580156101ee573d6000803e3d6000fd5b5050505056fea265627a7a723158208ffcff90cbf8522864156cc107926d9d21eb85c43404fdd6e8f234f8305e1ab264736f6c63430005100032",
            createContract.code[0].code
        )
        assertEquals("3.0", createContract.code[0].nonce)

        val getChildCode = getCode.getAllByOwner(createContract.parentContractAddress32).blockingGet()
        if (getChildCode is GetCode.Record.Multiple) {
            assertEquals(
                "608060405234801561001057600080fd5b50600436106100415760003560e01c806340c4d94114610046578063a9059cbb14610090578063b69ef8a8146100de575b600080fd5b61004e6100fc565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6100dc600480360360408110156100a657600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190505050610104565b005b6100e6610159565b6040518082815260200191505060405180910390f35b600030905090565b80600054101561011057fe5b8060008082825403925050819055508173ffffffffffffffffffffffffffffffffffffffff166108fc829081150290604051600060405180830381858888f19350505050505050565b60004790509056fea265627a7a723158201f52b9f50d419b8778ecc28108e9f36e9ad38b2b1c0e5723cd2143be265268e864736f6c63430005100032",
                getChildCode.items[0].code
            )
            assertEquals("1.0", getChildCode.items[0].nonce)
            assertEquals(
                "608060405260043610601c5760003560e01c8063b69ef8a814602d575b346000808282540192505081905550005b348015603857600080fd5b50603f6055565b6040518082815260200191505060405180910390f35b6000805490509056fea265627a7a723158206ac80067d3f015c42e8793ac9375e67b0b5d2f7e12c838820ba966f9cef6d65064736f6c63430005100032",
                getChildCode.items[1].code
            )
            assertEquals("1.0", getChildCode.items[1].nonce)
        }
    }

    @Test
    fun `Call the transfer method to transfer value between two contracts`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance()
        val contract = ContractTransferContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContract = contract.createContract(EthAsset.milliether(300)).blockingGet()
        assertEquals(202, createContract.statusCode)

        // when
        val transferResponse = faultTolerant {
            contract.transfer(
                EvmSender(
                    2,
                    newEthAccount,
                    newAccountName,
                    newAccountPrivateKey,
                    contract.ownerAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // then
        assertEquals(202, transferResponse.statusCode)

        // when
        val child2BalanceResponse = faultTolerant {
            contract.child2Balance(
                EvmSender(
                    3,
                    newEthAccount,
                    newAccountName,
                    newAccountPrivateKey,
                    contract.ownerAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // then
        assertEquals(202, child2BalanceResponse.statusCode)
        child2BalanceResponse.assertConsoleString("return[0000000000000000000000000000000000000000000000000429d069189e0000]")
    }
}
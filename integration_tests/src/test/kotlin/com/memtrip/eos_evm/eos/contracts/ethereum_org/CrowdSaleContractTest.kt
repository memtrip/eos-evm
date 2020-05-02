package com.memtrip.eos_evm.eos.contracts.ethereum_org

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.contracts.ethereum_org.CrowdSaleContract
import com.memtrip.eos_evm.eos.faultTolerant
import com.memtrip.eos_evm.eos.state.GetCode
import com.memtrip.eos_evm.ethereum.EthAccount
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert
import org.junit.Assert.assertEquals
import org.junit.Test
import java.util.concurrent.TimeUnit

class CrowdSaleContractTest {

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
    fun `The CrowdSale contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance(30000)

        val contract = CrowdSaleContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContractResponse = faultTolerant {
            contract.createContract(
                EthAccount.create().address,
                100,
                100,
                100,
                EthAccount.create().address
            ).blockingGet()
        }

        // then
        assertEquals(202, createContractResponse.statusCode)

        // and when
        val getCodeResult = getCode.getAll(
            contract.accountIdentifier.pad256().toHexString()
        ).blockingGet()

        if (getCodeResult !is GetCode.Record.Multiple) Assert.fail("code record not found") else {
            assertEquals(1, getCodeResult.items.size)
            assertEquals(
                "6080604052600436106100865760003560e01c806370a082311161005957806370a08231146103395780637a3a0e841461039e5780637b3e5e7b146103c9578063a035b1fe146103f4578063fd6b7ef81461041f57610086565b806301cb3b201461024957806329dcb0cf1461026057806338af3eed1461028b5780636e66f6e9146102e2575b600760019054906101000a900460ff16156100a057600080fd5b600034905080600660003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000206000828254019250508190555080600260008282540192505081905550600560009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1663a9059cbb33600454848161014c57fe5b046040518363ffffffff1660e01b8152600401808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200182815260200192505050600060405180830381600087803b1580156101b657600080fd5b505af11580156101ca573d6000803e3d6000fd5b505050507fe842aea7a5f1b01049d752008c53c52890b1a6daf660cf39e8eec506112bbdf633826001604051808473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200183815260200182151515158152602001935050505060405180910390a150005b34801561025557600080fd5b5061025e610436565b005b34801561026c57600080fd5b50610275610512565b6040518082815260200191505060405180910390f35b34801561029757600080fd5b506102a0610518565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b3480156102ee57600080fd5b506102f761053d565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b34801561034557600080fd5b506103886004803603602081101561035c57600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610563565b6040518082815260200191505060405180910390f35b3480156103aa57600080fd5b506103b361057b565b6040518082815260200191505060405180910390f35b3480156103d557600080fd5b506103de610581565b6040518082815260200191505060405180910390f35b34801561040057600080fd5b50610409610587565b6040518082815260200191505060405180910390f35b34801561042b57600080fd5b5061043461058d565b005b600354421061051057600154600254106104f4576001600760006101000a81548160ff0219169083151502179055507fec3f991caf7857d61663fd1bba1739e04abd4781238508cde554bb849d790c856000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff16600254604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a15b6001600760016101000a81548160ff0219169083151502179055505b565b60035481565b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b600560009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b60066020528060005260406000206000915090505481565b60015481565b60025481565b60045481565b60035442106108a257600760009054906101000a900460ff1661073b576000600660003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000205490506000600660003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020819055506000811115610739573373ffffffffffffffffffffffffffffffffffffffff166108fc829081150290604051600060405180830381858888f19350505050156106f3577fe842aea7a5f1b01049d752008c53c52890b1a6daf660cf39e8eec506112bbdf633826000604051808473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200183815260200182151515158152602001935050505060405180910390a1610738565b80600660003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020819055505b5b505b600760009054906101000a900460ff1680156107a357503373ffffffffffffffffffffffffffffffffffffffff166000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16145b156108a1573373ffffffffffffffffffffffffffffffffffffffff166108fc6002549081150290604051600060405180830381858888f1935050505015610884577fe842aea7a5f1b01049d752008c53c52890b1a6daf660cf39e8eec506112bbdf66000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff166002546000604051808473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200183815260200182151515158152602001935050505060405180910390a16108a0565b6000600760006101000a81548160ff0219169083151502179055505b5b5b56fea265627a7a723158208c05e8711ff46b4b6ffe9ae397a90de77796093bc33b2d8d86034e2af3669c5164736f6c63430005100032",
                getCodeResult.items[0].code
            )
            assertEquals(getCodeResult.items[0].address, contract.accountIdentifier.pad256().toHexString())
        }
    }
}
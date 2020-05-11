package com.memtrip.evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.evm.contracts.misc.SetValueContract
import com.memtrip.evm.eos.state.GetAccountState
import com.memtrip.evm.eos.evm.GetCode
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Assert.fail
import org.junit.Test
import java.util.concurrent.TimeUnit

class SetValueContractTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val getCode = GetCode(chainApi)

    private val getAccountState = GetAccountState(chainApi)

    @Test
    fun `The SetValue contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = SetValueContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContract = contract.createContract().blockingGet()

        // then
        assertEquals(202, createContract.statusCode)
        assertEquals(1, createContract.code.size)
        assertEquals(
            "6080604052600080fdfea265627a7a723158206f308c86455d745293dc61890e931c7132b85a51d8c40894d4f6f92340c4530c64736f6c63430005100032",
            createContract.code[0].code
        )

        val getChildCode = getCode.getAllByOwner(createContract.parentContractAddress32).blockingGet()
        val childContractAddress = if (getChildCode is GetCode.Record.Multiple) {
            assertEquals(
                "6080604052600436106100295760003560e01c80632f64d3861461002e578063c4784fd4146100be575b600080fd5b34801561003a57600080fd5b50610043610179565b6040518080602001828103825283818151815260200191508051906020019080838360005b83811015610083578082015181840152602081019050610068565b50505050905090810190601f1680156100b05780820380516001836020036101000a031916815260200191505b509250505060405180910390f35b610177600480360360208110156100d457600080fd5b81019080803590602001906401000000008111156100f157600080fd5b82018360208201111561010357600080fd5b8035906020019184600183028401116401000000008311171561012557600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f820116905080830192505050505050509192919290505050610217565b005b60008054600181600116156101000203166002900480601f01602080910402602001604051908101604052809291908181526020018280546001816001161561010002031660029004801561020f5780601f106101e45761010080835404028352916020019161020f565b820191906000526020600020905b8154815290600101906020018083116101f257829003601f168201915b505050505081565b806000908051906020019061022d929190610231565b5050565b828054600181600116156101000203166002900490600052602060002090601f016020900481019282601f1061027257805160ff19168380011785556102a0565b828001600101855582156102a0579182015b8281111561029f578251825591602001919060010190610284565b5b5090506102ad91906102b1565b5090565b6102d391905b808211156102cf5760008160009055506001016102b7565b5090565b9056fea265627a7a72315820d90ff93393741450f39bd7ca020063520b6b19711fa092d5f6b1e67565a0fd1964736f6c63430005100032",
                getChildCode.items.first().code
            )
            getChildCode.items.first().address
        } else "no address found"

        // and when
        val accountState = getAccountState.getAll(childContractAddress).blockingGet()

        // and then
        if (accountState !is GetAccountState.Record.Multiple) fail("no state saved") else {
            assertEquals(1, accountState.items.size)
            assertEquals(
                "7465737400000000000000000000000000000000000000000000000000000008",
                accountState.items.first().value
            )
        }
    }
}
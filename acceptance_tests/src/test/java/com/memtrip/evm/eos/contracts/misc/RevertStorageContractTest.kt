package com.memtrip.evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.GetCode
import com.memtrip.evm.eos.evm.contracts.misc.RevertStorageContract
import com.memtrip.evm.eos.faultTolerant
import com.memtrip.evm.eos.state.GetAccountState
import com.memtrip.evm.ethereum.EthAsset
import com.memtrip.evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Assert.fail
import org.junit.Assert.assertTrue
import org.junit.Test
import java.util.concurrent.TimeUnit

class RevertStorageContractTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val getAccountState = GetAccountState(chainApi)

    private val getCode = GetCode(chainApi)

    @Test
    fun `The RevertStorage contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = RevertStorageContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContract = contract.createContract().blockingGet()

        // then
        assertEquals(202, createContract.statusCode)

        // and when
        assertEquals(1, createContract.code.size)
        assertEquals(
            "60806040526004361061004a5760003560e01c80631366e6ca1461004f578063280622be1461007d578063553bcd7a146100945780636466414b146100c2578063bb1b8c2f146100f0575b600080fd5b61007b6004803603602081101561006557600080fd5b810190808035906020019092919050505061011e565b005b34801561008957600080fd5b5061009261028b565b005b6100c0600480360360208110156100aa57600080fd5b81019080803590602001909291905050506103ec565b005b6100ee600480360360208110156100d857600080fd5b8101908080359060200190929190505050610559565b005b61011c6004803603602081101561010657600080fd5b81019080803590602001909291905050506106c6565b005b60006060600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1683604051602401808281526020019150506040516020818303038152906040527f1366e6ca000000000000000000000000000000000000000000000000000000007bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b6020831061021c57805182526020820191506020810190506020830392506101f9565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d806000811461027c576040519150601f19603f3d011682016040523d82523d6000602084013e610281565b606091505b5091509150505050565b60006060600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff166040516024016040516020818303038152906040527fcf7a8965000000000000000000000000000000000000000000000000000000007bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b6020831061037e578051825260208201915060208101905060208303925061035b565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d80600081146103de576040519150601f19603f3d011682016040523d82523d6000602084013e6103e3565b606091505b50915091505050565b60006060600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1683604051602401808281526020019150506040516020818303038152906040527f553bcd7a000000000000000000000000000000000000000000000000000000007bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b602083106104ea57805182526020820191506020810190506020830392506104c7565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d806000811461054a576040519150601f19603f3d011682016040523d82523d6000602084013e61054f565b606091505b5091509150505050565b60006060600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1683604051602401808281526020019150506040516020818303038152906040527f6466414b000000000000000000000000000000000000000000000000000000007bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b602083106106575780518252602082019150602081019050602083039250610634565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d80600081146106b7576040519150601f19603f3d011682016040523d82523d6000602084013e6106bc565b606091505b5091509150505050565b60006060600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1683604051602401808281526020019150506040516020818303038152906040527fbb1b8c2f000000000000000000000000000000000000000000000000000000007bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b602083106107c457805182526020820191506020810190506020830392506107a1565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d8060008114610824576040519150601f19603f3d011682016040523d82523d6000602084013e610829565b606091505b509150915050505056fea265627a7a7231582060c115a78b93bfa378522673f4b21ced48e04118428109d004315da16590388764736f6c63430005100032",
            createContract.code[0].code
        )
    }

    @Test
    fun `Call the setVar method and confirm the delegate call sets a value`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val contract = RevertStorageContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract().blockingGet()
        assertEquals(202, createContract.statusCode)

        // when
        val response = faultTolerant {
            contract.setVars(
                EthAsset.milliether(150),
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
        assertEquals(202, response.statusCode)

        // and when
        val accountState = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()

        // and then
        if (accountState is GetAccountState.Record.Multiple) {
            assertEquals(2, accountState.items.size)
            assertEquals("0000000000000000000000000000000000000000000000000214e8348c4f0000", accountState.items[1].value)
        } else fail("could not find account state")
    }

    @Test
    fun `Call the setVarsRevert method and confirm that the storage modified in delegate call was not committed`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val contract = RevertStorageContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract().blockingGet()
        assertEquals(202, createContract.statusCode)

        // when
        val response = faultTolerant {
            contract.setVarsRevert(
                EthAsset.milliether(150),
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
        assertEquals(202, response.statusCode)

        // and when
        val accountState = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()

        // and then
        if (accountState is GetAccountState.Record.Multiple) {
            assertEquals(1, accountState.items.size)
        } else fail("could not find account state")
    }

    @Test
    fun `Call the setVarsAssert method and confirm that the storage modified in delegate call was not committed`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val contract = RevertStorageContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract().blockingGet()
        assertEquals(202, createContract.statusCode)

        // when
        val response = faultTolerant {
            contract.setVarsAssert(
                EthAsset.milliether(150),
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
        assertEquals(202, response.statusCode)

        // and when
        val accountState = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()

        // and then
        if (accountState is GetAccountState.Record.Multiple) {
            assertEquals(1, accountState.items.size)
        } else fail("could not find account state")
    }

    @Test
    fun `Call the setVarsRequire method and confirm that the storage modified in delegate call was not committed`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val contract = RevertStorageContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract().blockingGet()
        assertEquals(202, createContract.statusCode)

        // when
        val response = faultTolerant {
            contract.setVarsRequire(
                EthAsset.milliether(150),
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
        assertEquals(202, response.statusCode)

        // and when
        val accountState = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()

        // and then
        if (accountState is GetAccountState.Record.Multiple) {
            assertEquals(1, accountState.items.size)
        } else fail("could not find account state")
    }

    @Test
    fun `Call the dangerous method and confirm that the parent contract was destructed by delegatecall`() {
        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()
        val contract = RevertStorageContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract().blockingGet()
        assertEquals(202, createContract.statusCode)

        // and when
        val getParentCodeBeforeDestruct = getCode.getByAddress(createContract.parentContractAddress32).blockingGet()

        // and then
        assertTrue(getParentCodeBeforeDestruct is GetCode.Record.Value)

        // when
        val response = faultTolerant {
            contract.dangerous(
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
        assertEquals(202, response.statusCode)

        // and when
        val getParentCodeAfterDestruct = getCode.getByAddress(createContract.parentContractAddress32).blockingGet()

        // and then
        assertTrue(getParentCodeAfterDestruct is GetCode.Record.None)
    }
}
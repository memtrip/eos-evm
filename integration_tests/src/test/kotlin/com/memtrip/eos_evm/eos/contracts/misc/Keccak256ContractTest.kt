package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.assertConsoleString
import com.memtrip.eos_evm.eos.Config
import com.memtrip.eos_evm.eos.SetupTransactions
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.misc.Keccak256Contract
import com.memtrip.eos_evm.eos.faultTolerant
import com.memtrip.eos_evm.eos.state.GetAccountState
import com.memtrip.eos_evm.eos.state.GetCode
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert
import org.junit.Assert.assertEquals
import org.junit.Test
import java.util.concurrent.TimeUnit

class Keccak256ContractTest {

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
    fun `The Keccak256 contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(14000)

        val contract = Keccak256Contract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContractResponse = faultTolerant {
            contract.createContract().blockingGet()
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
                "608060405234801561001057600080fd5b50600436106100ea5760003560e01c80635985b6241161008c578063c8cf44bd11610066578063c8cf44bd1461021b578063d2f8cf241461023d578063e86783a71461025b578063f74d8e3214610279576100ea565b80635985b624146101c15780635fdc7f65146101df5780637781deba146101fd576100ea565b806344d9385f116100c857806344d9385f146101495780634c9e7ca5146101675780635087821a1461018557806351193102146101a3576100ea565b806304d3c094146100ef578063114be5841461010d57806311b405c71461012b575b600080fd5b6100f7610297565b6040518082815260200191505060405180910390f35b6101156102db565b6040518082815260200191505060405180910390f35b610133610329565b6040518082815260200191505060405180910390f35b6101516104de565b6040518082815260200191505060405180910390f35b61016f610510565b6040518082815260200191505060405180910390f35b61018d61077d565b6040518082815260200191505060405180910390f35b6101ab6107e8565b6040518082815260200191505060405180910390f35b6101c9610850565b6040518082815260200191505060405180910390f35b6101e7610882565b6040518082815260200191505060405180910390f35b6102056108b1565b6040518082815260200191505060405180910390f35b6102236108e0565b604051808215151515815260200191505060405180910390f35b6102456109d1565b6040518082815260200191505060405180910390f35b610263610a00565b6040518082815260200191505060405180910390f35b610281610a37565b6040518082815260200191505060405180910390f35b60006040518060400160405280600181526020017f610000000000000000000000000000000000000000000000000000000000000081525080519060200120905090565b60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6040516020018082815260200191505060405160208183030381529060405280519060200120905090565b6000807f4254430000000000000000000000000000000000000000000000000000000000905060007f4554480000000000000000000000000000000000000000000000000000000000905060007f4c54430000000000000000000000000000000000000000000000000000000000905060007f444f474500000000000000000000000000000000000000000000000000000000905083838383604051602001808577ffffffffffffffffffffffffffffffffffffffffffffffff191677ffffffffffffffffffffffffffffffffffffffffffffffff191681526020018477ffffffffffffffffffffffffffffffffffffffffffffffff191677ffffffffffffffffffffffffffffffffffffffffffffffff191681526020018377ffffffffffffffffffffffffffffffffffffffffffffffff191677ffffffffffffffffffffffffffffffffffffffffffffffff191681526020018277ffffffffffffffffffffffffffffffffffffffffffffffff191677ffffffffffffffffffffffffffffffffffffffffffffffff191681526020019450505050506040516020818303038152906040528051906020012094505050505090565b60006001604051602001808260ff16815260200191505060405160208183030381529060405280519060200120905090565b6000606060046040519080825280602002602001820160405280156105445781602001602082028038833980820191505090505b5090507f42544300000000000000000000000000000000000000000000000000000000008160008151811061057557fe5b602002602001019077ffffffffffffffffffffffffffffffffffffffffffffffff1916908177ffffffffffffffffffffffffffffffffffffffffffffffff1916815250507f4554480000000000000000000000000000000000000000000000000000000000816001815181106105e757fe5b602002602001019077ffffffffffffffffffffffffffffffffffffffffffffffff1916908177ffffffffffffffffffffffffffffffffffffffffffffffff1916815250507f4c544300000000000000000000000000000000000000000000000000000000008160028151811061065957fe5b602002602001019077ffffffffffffffffffffffffffffffffffffffffffffffff1916908177ffffffffffffffffffffffffffffffffffffffffffffffff1916815250507f444f474500000000000000000000000000000000000000000000000000000000816003815181106106cb57fe5b602002602001019077ffffffffffffffffffffffffffffffffffffffffffffffff1916908177ffffffffffffffffffffffffffffffffffffffffffffffff191681525050806040516020018080602001828103825283818151815260200191508051906020019060200280838360005b8381101561075657808201518184015260208101905061073b565b50505050905001925050506040516020818303038152906040528051906020012091505090565b6000600160405160200180806020018360ff168152602001828103825260018152602001807f61000000000000000000000000000000000000000000000000000000000000008152506020019250505060405160208183030381529060405280519060200120905090565b600080736779913e982688474f710b47e1c0506c5dca463490508060601b60405160200180826bffffffffffffffffffffffff19166bffffffffffffffffffffffff191681526020019150506040516020818303038152906040528051906020012091505090565b6000600a604051602001808260ff16815260200191505060405160208183030381529060405280519060200120905090565b600060016040516020018082815260200191505060405160208183030381529060405280519060200120905090565b600060016040516020018082815260200191505060405160208183030381529060405280519060200120905090565b6000604051602001808060200180602001838103835260018152602001807f6100000000000000000000000000000000000000000000000000000000000000815250602001838103825260018152602001807f620000000000000000000000000000000000000000000000000000000000000081525060200192505050604051602081830303815290604052805190602001206040516020018080602001828103825260028152602001807f61620000000000000000000000000000000000000000000000000000000000008152506020019150506040516020818303038152906040528051906020012014905090565b600060646040516020018082815260200191505060405160208183030381529060405280519060200120905090565b600068056bc75e2d631000006040516020018082815260200191505060405160208183030381529060405280519060200120905090565b60006001604051602001808263ffffffff1663ffffffff1681526020019150506040516020818303038152906040528051906020012090509056fea265627a7a723158203ccded79eaba7a938b786187cc3dda1b36358e29af0b6effcb7f99df1ed8995e64736f6c63430005100032",
                getCodeResult.items[0].code
            )
            assertEquals(getCodeResult.items[0].address, contract.accountIdentifier.pad256().toHexString())
        }
    }

    @Test
    fun `call the hashArray method`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(14000)
        val contract = Keccak256Contract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.hashArray(EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[388eb0f6665ac7a64915fbf2dbebf4e2e93e6f2a39375f565695c1149e2e2db5]")
    }

    @Test
    fun `call the hashPackedArray method`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(14000)
        val contract = Keccak256Contract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.hashPackedArray(EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[374c0504f79c1d5e6e4ded17d488802b5656bd1d96b16a568d6c324e1c04c37b]")
    }

    @Test
    fun `call the hashAddress method`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(14000)
        val contract = Keccak256Contract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.hashAddress(EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[f7c2889e894e71cac9a445259deff1fcfebaa551fdf47627aabb6a9aa2f9e9c5]")
    }

    @Test
    fun `call the testPackedArgs method`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(14000)
        val contract = Keccak256Contract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.testPackedArgs(EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[0000000000000000000000000000000000000000000000000000000000000001]")
    }

    @Test
    fun `call the hashHex method`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(14000)
        val contract = Keccak256Contract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.hashHex(EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[c65a7bb8d6351c1cf70c95a316cc6a92839c986682d98bc35f958f4883f9d2a8]")
    }

    @Test
    fun `call the hashInt method`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(14000)
        val contract = Keccak256Contract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.hashInt(EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[b10e2d527612073b26eecdfd717e6a320cf44b4afac2b0732d9fcbe2b7fa0cf6]")
    }

    @Test
    fun `call the hashNegative method`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(14000)
        val contract = Keccak256Contract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.hashNegative(EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[a9c584056064687e149968cbab758a3376d22aedc6a55823d1b3ecbee81b8fb9]")
    }

    @Test
    fun `call the hash8 method`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(14000)
        val contract = Keccak256Contract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.hash8(EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[b10e2d527612073b26eecdfd717e6a320cf44b4afac2b0732d9fcbe2b7fa0cf6]")
    }

    @Test
    fun `call the hash32 method`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(14000)
        val contract = Keccak256Contract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.hash32(EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[b10e2d527612073b26eecdfd717e6a320cf44b4afac2b0732d9fcbe2b7fa0cf6]")
    }

    @Test
    fun `call the hash256 method`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(14000)
        val contract = Keccak256Contract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.hash256(EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[b10e2d527612073b26eecdfd717e6a320cf44b4afac2b0732d9fcbe2b7fa0cf6]")
    }

    @Test
    fun `call the hashEth method`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(14000)
        val contract = Keccak256Contract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.hashEth(EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[c7cc234d21c9cfbd4632749fd77669e7ae72f5241ce5895e410c45185a469273]")
    }

    @Test
    fun `call the hashWei method`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(14000)
        val contract = Keccak256Contract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.hashWei(EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[26700e13983fefbd9cf16da2ed70fa5c6798ac55062a4803121a869731e308d2]")
    }

    @Test
    fun `call the hashMultipleArgs method`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(14000)
        val contract = Keccak256Contract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.hashMultipleArgs(EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[abc89f3c9b8891b50ea496d210d90f155f8be28bada0e41dda2b3817372f68b1]")
    }

    @Test
    fun `call the hashString method`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(14000)
        val contract = Keccak256Contract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )
        val createContractResponse = faultTolerant { contract.createContract().blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        // when
        val response = faultTolerant {
            contract.hashString(EvmSender(
                3,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.accountIdentifier.toHexString()
            )).blockingGet()
        }

        // then
        assertEquals(202, response.statusCode)
        response.assertConsoleString("return[3ac225168df54212a25c1c01fd35bebfea408fdac2e31ddd6f80a4bbf9a5f1cb]")
    }
}
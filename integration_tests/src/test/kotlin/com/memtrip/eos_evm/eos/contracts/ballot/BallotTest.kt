package com.memtrip.eos_evm.eos.contracts.ballot

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.assertConsoleError
import com.memtrip.eos_evm.eos.*
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.BallotContract
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

class BallotTest {

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
    fun `The ballot contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(17000)

        val ballotContract = BallotContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContractResponse = faultTolerant {
            ballotContract.createBallet(listOf("option1")).blockingGet()
        }

        // then
        assertEquals(createContractResponse.statusCode, 202)

        // and when
        val getCodeResult = getCode.getAll(
            ballotContract.accountIdentifier.pad256().toHexString()
        ).blockingGet()

        if (getCodeResult !is GetCode.Record.Multiple) Assert.fail("code record not found") else {
            assertEquals(1, getCodeResult.items.size)
            assertEquals(
                "608060405234801561001057600080fd5b50600436106100885760003560e01c8063609ff1bd1161005b578063609ff1bd146101925780639e7b8d61146101b0578063a3ec138d146101f4578063e2ba53f01461029157610088565b80630121b93f1461008d578063013cf08b146100bb5780632e4176cf146101045780635c19a95c1461014e575b600080fd5b6100b9600480360360208110156100a357600080fd5b81019080803590602001909291905050506102af565b005b6100e7600480360360208110156100d157600080fd5b810190808035906020019092919050505061044c565b604051808381526020018281526020019250505060405180910390f35b61010c61047d565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6101906004803603602081101561016457600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff1690602001909291905050506104a2565b005b61019a6108be565b6040518082815260200191505060405180910390f35b6101f2600480360360208110156101c657600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610935565b005b6102366004803603602081101561020a57600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610b36565b60405180858152602001841515151581526020018373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200182815260200194505050505060405180910390f35b610299610b93565b6040518082815260200191505060405180910390f35b6000600160003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020905060008160000154141561036d576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260148152602001807f486173206e6f20726967687420746f20766f746500000000000000000000000081525060200191505060405180910390fd5b8060010160009054906101000a900460ff16156103f2576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252600e8152602001807f416c726561647920766f7465642e00000000000000000000000000000000000081525060200191505060405180910390fd5b60018160010160006101000a81548160ff02191690831515021790555081816002018190555080600001546002838154811061042a57fe5b9060005260206000209060020201600101600082825401925050819055505050565b6002818154811061045957fe5b90600052602060002090600202016000915090508060000154908060010154905082565b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b6000600160003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002090508060010160009054906101000a900460ff161561056a576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260128152602001807f596f7520616c726561647920766f7465642e000000000000000000000000000081525060200191505060405180910390fd5b3373ffffffffffffffffffffffffffffffffffffffff168273ffffffffffffffffffffffffffffffffffffffff16141561060c576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252601e8152602001807f53656c662d64656c65676174696f6e20697320646973616c6c6f7765642e000081525060200191505060405180910390fd5b5b600073ffffffffffffffffffffffffffffffffffffffff16600160008473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060010160019054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16146107af57600160008373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060010160019054906101000a900473ffffffffffffffffffffffffffffffffffffffff1691503373ffffffffffffffffffffffffffffffffffffffff168273ffffffffffffffffffffffffffffffffffffffff1614156107aa576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260198152602001807f466f756e64206c6f6f7020696e2064656c65676174696f6e2e0000000000000081525060200191505060405180910390fd5b61060d565b60018160010160006101000a81548160ff021916908315150217905550818160010160016101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff1602179055506000600160008473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002090508060010160009054906101000a900460ff16156108a2578160000154600282600201548154811061087f57fe5b9060005260206000209060020201600101600082825401925050819055506108b9565b816000015481600001600082825401925050819055505b505050565b6000806000905060008090505b6002805490508110156109305781600282815481106108e657fe5b9060005260206000209060020201600101541115610923576002818154811061090b57fe5b90600052602060002090600202016001015491508092505b80806001019150506108cb565b505090565b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff16146109da576040517f08c379a0000000000000000000000000000000000000000000000000000000008152600401808060200182810382526028815260200180610bc16028913960400191505060405180910390fd5b600160008273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060010160009054906101000a900460ff1615610a9d576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260188152602001807f54686520766f74657220616c726561647920766f7465642e000000000000000081525060200191505060405180910390fd5b6000600160008373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000206000015414610aec57600080fd5b60018060008373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000206000018190555050565b60016020528060005260406000206000915090508060000154908060010160009054906101000a900460ff16908060010160019054906101000a900473ffffffffffffffffffffffffffffffffffffffff16908060020154905084565b60006002610b9f6108be565b81548110610ba957fe5b90600052602060002090600202016000015490509056fe4f6e6c79206368616972706572736f6e2063616e206769766520726967687420746f20766f74652ea265627a7a72315820715389f0d3ff5c172a66cc171ca1cf2402b11473966ed2672739c75ac2cb897564736f6c63430005100032",
                getCodeResult.items[0].code
            )
            assertEquals(getCodeResult.items[0].address, ballotContract.accountIdentifier.pad256().toHexString())
        }

        val accountStateResult = getAccountState.getAll(ballotContract.accountIdentifier.pad256().toHexString()).blockingGet()
        if (accountStateResult !is GetAccountState.Record.Multiple) Assert.fail("no state saved") else {
            assertEquals(2, accountStateResult.items.size)
            assertEquals(accountStateResult.items[0].value, ballotContract.contractAccountIdentifier)
            assertEquals(accountStateResult.items[1].value, "0000000000000000000000000000000000000000000000000000000000000001")
        }
    }

    @Test
    fun `Give an address the right to vote, and delegate that vote to the chair person`() {

        // given
        val (chairAccountName, chairPrivateKey, chairEthAccount) = setupTransactions.seed(17000)
        val contractAccountIdentifier = AccountIdentifier.create(chairAccountName, chairEthAccount.address)

        val ballotContract = BallotContract(
            chairAccountName,
            chairPrivateKey,
            chairEthAccount
        )

        // when
        val createContractResponse = faultTolerant {
            ballotContract.createBallet(listOf("option1")).blockingGet()
        }

        // then
        assertEquals(createContractResponse.statusCode, 202)

        // and given
        val (senderAccountName, senderPrivateKey, senderEthAccount) = setupTransactions.seedWithSystemBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        // and when
        val giveRightToVoteResponse = ballotContract.giveRightToVote(senderAccountIdentifier.toHexString(), EvmSender(
            3,
            chairEthAccount,
            chairAccountName,
            chairPrivateKey,
            contractAccountIdentifier.toHexString()
        )).blockingGet()

        // and then
        assertEquals(202, giveRightToVoteResponse.statusCode)

        // and when
        val accountStateResult = getAccountState.getAll(contractAccountIdentifier.pad256().toHexString()).blockingGet()

        // and then
        if (accountStateResult !is GetAccountState.Record.Multiple) Assert.fail("no state saved") else {
            assertEquals(3, accountStateResult.items.size)
        }

        // and when
        val delegateVoteResponse = ballotContract.delegate(contractAccountIdentifier.toHexString(), EvmSender(
            1,
            senderEthAccount,
            senderAccountName,
            senderPrivateKey,
            senderAccountIdentifier.toHexString()
        )).blockingGet()

        // and then
        assertEquals(202, delegateVoteResponse.statusCode)

        // and when
        val accountStateAfterDelegate = getAccountState.getAll(contractAccountIdentifier.pad256().toHexString()).blockingGet()

        // and then
        if (accountStateAfterDelegate !is GetAccountState.Record.Multiple) Assert.fail("no state saved") else {
            assertEquals(4, accountStateAfterDelegate.items.size)
        }

        // and then
        val voteResponse = ballotContract.vote(0, EvmSender(
            4,
            chairEthAccount,
            chairAccountName,
            chairPrivateKey,
            contractAccountIdentifier.toHexString()
        )).blockingGet()

        // and then
        assertEquals(202, voteResponse.statusCode)
    }

    @Test
    fun `Only the chair person can give the right to vote`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(17000)

        val ballotContract = BallotContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContractResponse = faultTolerant {
            ballotContract.createBallet(listOf("option1")).blockingGet()
        }

        // then
        assertEquals(createContractResponse.statusCode, 202)

        // and given
        val (senderAccountName, senderAccountPrivateKey, senderEthAccount) = setupTransactions.seedWithSystemBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address).toHexString()

        // and when
        val giveRightToVoteResponse = ballotContract.giveRightToVote(senderAccountIdentifier, EvmSender(
            1,
            senderEthAccount,
            senderAccountName,
            senderAccountPrivateKey,
            senderAccountIdentifier
        )).blockingGet()

        // and then
        assertEquals(500, giveRightToVoteResponse.statusCode)
        giveRightToVoteResponse.assertConsoleError("MESSAGE_CALL_REVERTED")
    }
}
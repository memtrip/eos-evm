package com.memtrip.evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.assertConsoleString
import com.memtrip.evm.eos.AccountIdentifier
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.contracts.misc.ProposalContract
import com.memtrip.evm.eos.faultTolerant
import com.memtrip.evm.eos.evm.GetCode
import com.memtrip.evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Test
import java.util.concurrent.TimeUnit

class ProposalContractTest {

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
    fun `The Proposal contract is created`() {

        // given
        val (thirdPartyAccountName, _, thirdPartyEthAccount) = setupTransactions.seed()
        val thirdPartyAccountIdentifier = AccountIdentifier.create(thirdPartyAccountName, thirdPartyEthAccount.address)

        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed()

        val contract = ProposalContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        // when
        val createContract = contract.createContract(thirdPartyAccountIdentifier.toHexString()).blockingGet()

        // then
        assertEquals(202, createContract.statusCode)
        assertEquals(1, createContract.code.size)
        assertEquals(
            "608060405234801561001057600080fd5b50600436106100625760003560e01c80630cc0e1fb1461006757806328f371aa146100855780636b1d752b146100a7578063d4b83992146100c5578063daea85c5146100e3578063eb6fd96a14610127575b600080fd5b61006f610145565b6040518082815260200191505060405180910390f35b61008d61014b565b604051808215151515815260200191505060405180910390f35b6100af610159565b6040518082815260200191505060405180910390f35b6100cd61015f565b6040518082815260200191505060405180910390f35b610125600480360360208110156100f957600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610165565b005b61012f6101e8565b6040518082815260200191505060405180910390f35b60035481565b600060045460015414905090565b60025481565b60045481565b8073ffffffffffffffffffffffffffffffffffffffff1660001b60016000828254179250508190555060016000808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060006101000a81548160ff02191690831515021790555050565b6001548156fea265627a7a72315820a60e9f060ca75c3ecb2f1802174a2de71b07c27b8ab109e575719f0c0b404ef564736f6c63430005100032",
            createContract.code[0].code
        )
    }

    @Test
    fun `Create the Proposal contract, the sender approves contract, verify the approval`() {
        // given
        val (thirdPartyAccountName, thirdPartyPrivateKey, thirdPartyEthAccount) = setupTransactions.seed()
        val thirdPartyAccountIdentifier = AccountIdentifier.create(thirdPartyAccountName, thirdPartyEthAccount.address)

        val (senderAccountName, senderPrivateKey, senderEthAccount) = setupTransactions.seed()
        val contract = ProposalContract(senderAccountName, senderPrivateKey, senderEthAccount)
        val createContract = contract.createContract(thirdPartyAccountIdentifier.toHexString()).blockingGet()
        assertEquals(202, createContract.statusCode)

        // when
        val isApprovedEmptyResponse = faultTolerant {
            contract.isApproved(
                EvmSender(
                    1,
                    thirdPartyEthAccount,
                    thirdPartyAccountName,
                    thirdPartyPrivateKey,
                    thirdPartyAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // then
        assertEquals(202, isApprovedEmptyResponse.statusCode)
        isApprovedEmptyResponse.assertConsoleString("return[0000000000000000000000000000000000000000000000000000000000000000]")

        // and when
        val senderApprovalResponse = faultTolerant {
            contract.approve(
                contract.ownerAccountIdentifier.toHexString(),
                EvmSender(
                    2,
                    senderEthAccount,
                    senderAccountName,
                    senderPrivateKey,
                    contract.ownerAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // and then
        assertEquals(202, senderApprovalResponse.statusCode)

        // and when
        val isPartiallyApprovedResponse = faultTolerant {
            contract.isApproved(
                EvmSender(
                    2,
                    thirdPartyEthAccount,
                    thirdPartyAccountName,
                    thirdPartyPrivateKey,
                    thirdPartyAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // and then
        assertEquals(202, isPartiallyApprovedResponse.statusCode)
        isPartiallyApprovedResponse.assertConsoleString("return[0000000000000000000000000000000000000000000000000000000000000000]")

        // and when
        val thirdPartyApprovalResponse = faultTolerant {
            contract.approve(
                thirdPartyAccountIdentifier.toHexString(),
                EvmSender(
                    3,
                    thirdPartyEthAccount,
                    thirdPartyAccountName,
                    thirdPartyPrivateKey,
                    thirdPartyAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // and then
        assertEquals(202, thirdPartyApprovalResponse.statusCode)

        // and when
        val isApprovedResponse = faultTolerant {
            contract.isApproved(
                EvmSender(
                    4,
                    thirdPartyEthAccount,
                    thirdPartyAccountName,
                    thirdPartyPrivateKey,
                    thirdPartyAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // and then
        assertEquals(202, isApprovedResponse.statusCode)
        isApprovedResponse.assertConsoleString("return[0000000000000000000000000000000000000000000000000000000000000001]")
    }

    @Test
    fun `Create the Proposal contract, the third party approves the contract, verify the approval`() {
        // given
        val (thirdPartyAccountName, thirdPartyPrivateKey, thirdPartyEthAccount) = setupTransactions.seed()
        val thirdPartyAccountIdentifier = AccountIdentifier.create(thirdPartyAccountName, thirdPartyEthAccount.address)

        val (senderAccountName, senderPrivateKey, senderEthAccount) = setupTransactions.seed()
        val contract = ProposalContract(senderAccountName, senderPrivateKey, senderEthAccount)
        val createContract = contract.createContract(thirdPartyAccountIdentifier.toHexString()).blockingGet()
        assertEquals(202, createContract.statusCode)

        // when
        val isApprovedEmptyResponse = faultTolerant {
            contract.isApproved(
                EvmSender(
                    1,
                    thirdPartyEthAccount,
                    thirdPartyAccountName,
                    thirdPartyPrivateKey,
                    thirdPartyAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // then
        assertEquals(202, isApprovedEmptyResponse.statusCode)
        isApprovedEmptyResponse.assertConsoleString("return[0000000000000000000000000000000000000000000000000000000000000000]")

        // and when
        val thirdPartyApprovalResponse = faultTolerant {
            contract.approve(
                thirdPartyAccountIdentifier.toHexString(),
                EvmSender(
                    2,
                    thirdPartyEthAccount,
                    thirdPartyAccountName,
                    thirdPartyPrivateKey,
                    thirdPartyAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // and then
        assertEquals(202, thirdPartyApprovalResponse.statusCode)

        // and when
        val isApprovedResponse = faultTolerant {
            contract.isApproved(
                EvmSender(
                    3,
                    thirdPartyEthAccount,
                    thirdPartyAccountName,
                    thirdPartyPrivateKey,
                    thirdPartyAccountIdentifier.toHexString()
                )
            ).blockingGet()
        }

        // and then
        assertEquals(202, isApprovedResponse.statusCode)
        isApprovedResponse.assertConsoleString("return[0000000000000000000000000000000000000000000000000000000000000000]")
    }
}
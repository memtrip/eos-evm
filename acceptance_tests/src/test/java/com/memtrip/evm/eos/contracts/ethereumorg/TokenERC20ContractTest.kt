package com.memtrip.evm.eos.contracts.ethereumorg

import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.assertConsoleString
import com.memtrip.evm.eos.AccountIdentifier
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.contracts.ethereumorg.TokenERC20Contract
import com.memtrip.evm.eos.state.GetAccountState
import com.memtrip.evm.ethereum.EthAsset
import com.memtrip.evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert
import org.junit.Assert.assertEquals
import org.junit.Test
import java.math.BigInteger
import java.util.concurrent.TimeUnit

class TokenERC20ContractTest {

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val getAccountState = GetAccountState(chainApi)

    @Test
    fun `The TokenERC20 contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance(30000)
        val contract = TokenERC20Contract(newAccountName, newAccountPrivateKey, newEthAccount)

        // when
        val createContract = contract.createContract(
            BigInteger.valueOf(1000), "eos", "EOS").blockingGet()

        // then
        assertEquals(202, createContract.statusCode)

        // and when
        assertEquals(1, createContract.code.size)
        assertEquals(
            "608060405234801561001057600080fd5b50600436106100b45760003560e01c806370a082311161007157806370a08231146102b057806379cc67901461030857806395d89b411461036e578063a9059cbb146103f1578063cae9ca5114610457578063dd62ed3e14610554576100b4565b806306fdde03146100b9578063095ea7b31461013c57806318160ddd146101a257806323b872dd146101c0578063313ce5671461024657806342966c681461026a575b600080fd5b6100c16105cc565b6040518080602001828103825283818151815260200191508051906020019080838360005b838110156101015780820151818401526020810190506100e6565b50505050905090810190601f16801561012e5780820380516001836020036101000a031916815260200191505b509250505060405180910390f35b6101886004803603604081101561015257600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff1690602001909291908035906020019092919050505061066a565b604051808215151515815260200191505060405180910390f35b6101aa61075c565b6040518082815260200191505060405180910390f35b61022c600480360360608110156101d657600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190505050610762565b604051808215151515815260200191505060405180910390f35b61024e61088d565b604051808260ff1660ff16815260200191505060405180910390f35b6102966004803603602081101561028057600080fd5b81019080803590602001909291905050506108a0565b604051808215151515815260200191505060405180910390f35b6102f2600480360360208110156102c657600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff1690602001909291905050506109a2565b6040518082815260200191505060405180910390f35b6103546004803603604081101561031e57600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190803590602001909291905050506109ba565b604051808215151515815260200191505060405180910390f35b610376610bd0565b6040518080602001828103825283818151815260200191508051906020019080838360005b838110156103b657808201518184015260208101905061039b565b50505050905090810190601f1680156103e35780820380516001836020036101000a031916815260200191505b509250505060405180910390f35b61043d6004803603604081101561040757600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190505050610c6e565b604051808215151515815260200191505060405180910390f35b61053a6004803603606081101561046d57600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff16906020019092919080359060200190929190803590602001906401000000008111156104b457600080fd5b8201836020820111156104c657600080fd5b803590602001918460018302840111640100000000831117156104e857600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f820116905080830192505050505050509192919290505050610c85565b604051808215151515815260200191505060405180910390f35b6105b66004803603604081101561056a57600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610ded565b6040518082815260200191505060405180910390f35b60008054600181600116156101000203166002900480601f0160208091040260200160405190810160405280929190818152602001828054600181600116156101000203166002900480156106625780601f1061063757610100808354040283529160200191610662565b820191906000526020600020905b81548152906001019060200180831161064557829003601f168201915b505050505081565b600081600560003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060008573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020819055508273ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff167f8c5be1e5ebec7d5bd14f71427d1e84f3dd0314c0f7b2291e5b200ac8c7c3b925846040518082815260200191505060405180910390a36001905092915050565b60035481565b6000600560008573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020548211156107ed57600080fd5b81600560008673ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060008282540392505081905550610882848484610e12565b600190509392505050565b600260009054906101000a900460ff1681565b600081600460003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000205410156108ee57600080fd5b81600460003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060008282540392505081905550816003600082825403925050819055503373ffffffffffffffffffffffffffffffffffffffff167fcc16f5dbb4873280815c1ee09dbd06736cffcc184412cf7a71a0fdb75d397ca5836040518082815260200191505060405180910390a260019050919050565b60046020528060005260406000206000915090505481565b600081600460008573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020541015610a0857600080fd5b600560008473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002054821115610a9157600080fd5b81600460008573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000206000828254039250508190555081600560008573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060008282540392505081905550816003600082825403925050819055508273ffffffffffffffffffffffffffffffffffffffff167fcc16f5dbb4873280815c1ee09dbd06736cffcc184412cf7a71a0fdb75d397ca5836040518082815260200191505060405180910390a26001905092915050565b60018054600181600116156101000203166002900480601f016020809104026020016040519081016040528092919081815260200182805460018160011615610100020316600290048015610c665780601f10610c3b57610100808354040283529160200191610c66565b820191906000526020600020905b815481529060010190602001808311610c4957829003601f168201915b505050505081565b6000610c7b338484610e12565b6001905092915050565b600080849050610c95858561066a565b15610de4578073ffffffffffffffffffffffffffffffffffffffff16638f4ffcb1338630876040518563ffffffff1660e01b8152600401808573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018481526020018373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200180602001828103825283818151815260200191508051906020019080838360005b83811015610d73578082015181840152602081019050610d58565b50505050905090810190601f168015610da05780820380516001836020036101000a031916815260200191505b5095505050505050600060405180830381600087803b158015610dc257600080fd5b505af1158015610dd6573d6000803e3d6000fd5b505050506001915050610de6565b505b9392505050565b6005602052816000526040600020602052806000526040600020600091509150505481565b600073ffffffffffffffffffffffffffffffffffffffff168273ffffffffffffffffffffffffffffffffffffffff161415610e4c57600080fd5b80600460008573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020541015610e9857600080fd5b600460008373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000205481600460008573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002054011015610f2557600080fd5b6000600460008473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002054600460008673ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000205401905081600460008673ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000206000828254039250508190555081600460008573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020600082825401925050819055508273ffffffffffffffffffffffffffffffffffffffff168473ffffffffffffffffffffffffffffffffffffffff167fddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef846040518082815260200191505060405180910390a380600460008573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002054600460008773ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002054011461113257fe5b5050505056fea265627a7a7231582040606712f5b1afe220f8b757263d1bc85371f20dffb7b33b4299f939ec29d8b364736f6c63430005100032",
            createContract.code[0].code
        )
    }

    @Test
    fun `ERC20 token transfer`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance(30000)
        val contract = TokenERC20Contract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract(EthAsset.milliether(15000), "eos", "EOS").blockingGet()
        assertEquals(202, createContract.statusCode)

        val (senderAccountName, _, senderEthAccount) = setupTransactions.seedWithEvmBalance(30000)
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        // when
        val transferResponse = contract.transfer(
            senderAccountIdentifier.toHexString(),
            EthAsset.milliether(5000),
            EvmSender(
                2,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.ownerAccountIdentifier.toHexString()
            )
        ).blockingGet()

        // then
        assertEquals(202, transferResponse.statusCode)

        // and when
        val accountState = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()

        // and then
        if (accountState !is GetAccountState.Record.Multiple) Assert.fail("no state saved") else {
            assertEquals(6, accountState.items.size)
            // TODO: clarify this account state
        }
    }

    @Test
    fun `ERC20 burn tokens`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance(30000)
        val contract = TokenERC20Contract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract(EthAsset.milliether(15000), "eos", "EOS").blockingGet()
        assertEquals(202, createContract.statusCode)

        // when
        val burnResponse = contract.burn(
            EthAsset.milliether(12000),
            EvmSender(
                2,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.ownerAccountIdentifier.toHexString()
            )
        ).blockingGet()

        // then
        assertEquals(202, burnResponse.statusCode)
        burnResponse.assertConsoleString("return[0000000000000000000000000000000000000000000000000000000000000001]")

        // and when
        val accountState = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()

        // and then
        if (accountState !is GetAccountState.Record.Multiple) Assert.fail("no state saved") else {
            assertEquals(5, accountState.items.size)
            // TODO: clarify this account state
        }
    }

    @Test
    fun `ERC20 approve a second account to access funds, and make transfer`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance(30000)
        val contract = TokenERC20Contract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract(EthAsset.milliether(15000), "eos", "EOS").blockingGet()
        assertEquals(202, createContract.statusCode)

        val (senderAccountName, senderPrivateKey, senderEthAccount) = setupTransactions.seedWithEvmBalance(30000)
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        val (thirdPartyAccountName, _, thirdPartyEthAccount) = setupTransactions.seedWithEvmBalance(30000)
        val thirdPartyAccountIdentifier = AccountIdentifier.create(thirdPartyAccountName, thirdPartyEthAccount.address)

        // when
        val approveResponse = contract.approve(
            senderAccountIdentifier.toHexString(),
            EthAsset.milliether(5000),
            EvmSender(
                2,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.ownerAccountIdentifier.toHexString()
            )
        ).blockingGet()

        // then
        assertEquals(202, approveResponse.statusCode)

        // and when
        val transferFromResponse = contract.transferFrom(
            contract.ownerAccountIdentifier.toHexString(),
            thirdPartyAccountIdentifier.toHexString(),
            EthAsset.milliether(5000),
            EvmSender(
                1,
                senderEthAccount,
                senderAccountName,
                senderPrivateKey,
                senderAccountIdentifier.toHexString()
            )
        ).blockingGet()

        // and then
        assertEquals(202, transferFromResponse.statusCode)

        // and when
        val accountState = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()

        // and then
        if (accountState !is GetAccountState.Record.Multiple) Assert.fail("no state saved") else {
            assertEquals(7, accountState.items.size)
            // TODO: clarify this account state
        }
    }

    @Test
    fun `ERC20 approve a second account to access funds, and burn tokens`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance(30000)
        val contract = TokenERC20Contract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContract = contract.createContract(EthAsset.milliether(15000), "eos", "EOS").blockingGet()
        assertEquals(202, createContract.statusCode)

        val (senderAccountName, senderPrivateKey, senderEthAccount) = setupTransactions.seedWithEvmBalance(30000)
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        // when
        val approveResponse = contract.approve(
            senderAccountIdentifier.toHexString(),
            EthAsset.milliether(5000),
            EvmSender(
                2,
                newEthAccount,
                newAccountName,
                newAccountPrivateKey,
                contract.ownerAccountIdentifier.toHexString()
            )
        ).blockingGet()

        // then
        assertEquals(202, approveResponse.statusCode)

        // and when
        val transferFromResponse = contract.burnFrom(
            contract.ownerAccountIdentifier.toHexString(),
            EthAsset.milliether(5000),
            EvmSender(
                1,
                senderEthAccount,
                senderAccountName,
                senderPrivateKey,
                senderAccountIdentifier.toHexString()
            )
        ).blockingGet()

        // and then
        assertEquals(202, transferFromResponse.statusCode)

        // and when
        val accountState = getAccountState.getAll(createContract.parentContractAddress32).blockingGet()

        // and then
        if (accountState !is GetAccountState.Record.Multiple) Assert.fail("no state saved") else {
            assertEquals(6, accountState.items.size)
            // TODO: clarify this account state
        }
    }
}
package com.memtrip.eos_evm.eos.contracts.misc

import com.memtrip.eos.http.rpc.Api
import com.memtrip.eos_evm.eos.*
import com.memtrip.eos_evm.eos.evm.EvmSender
import com.memtrip.eos_evm.eos.evm.contracts.misc.SimpleAuctionContract
import com.memtrip.eos_evm.eos.state.GetAccount
import com.memtrip.eos_evm.eos.state.GetAccountState
import com.memtrip.eos_evm.eos.state.GetCode
import com.memtrip.eos_evm.ethereum.pad256
import com.memtrip.eos_evm.ethereum.toHexString
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import org.junit.Assert.assertEquals
import org.junit.Assert.fail
import org.junit.Test
import java.math.BigInteger
import java.util.concurrent.TimeUnit

class SimpleAuctionTest {

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

    private val getAccount = GetAccount(chainApi)

    @Test
    fun `The SimpleAuction contract is created`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seed(17000)
        val contractAccountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)

        val simpleAuctionContract = SimpleAuctionContract(
            newAccountName,
            newAccountPrivateKey,
            newEthAccount
        )

        val createContractResponse = faultTolerant {
            simpleAuctionContract.createSimpleAuction(5, contractAccountIdentifier.toHexString()).blockingGet()
        }

        // then
        assertEquals(202, createContractResponse.statusCode)

        // and when
        val getCodeResult = getCode.getAll(
            contractAccountIdentifier.pad256().toHexString()
        ).blockingGet()

        if (getCodeResult !is GetCode.Record.Multiple) fail("code record not found") else {
            assertEquals(1, getCodeResult.items.size)
            assertEquals(
                "6080604052600436106100705760003560e01c80633ccfd60b1161004e5780633ccfd60b146100ed5780634b449cba1461011c57806391f9015714610147578063d57bde791461019e57610070565b80631998aeef146100755780632a24f46c1461007f57806338af3eed14610096575b600080fd5b61007d6101c9565b005b34801561008b57600080fd5b506100946103e9565b005b3480156100a257600080fd5b506100ab6105dd565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b3480156100f957600080fd5b50610102610602565b604051808215151515815260200191505060405180910390f35b34801561012857600080fd5b50610131610726565b6040518082815260200191505060405180910390f35b34801561015357600080fd5b5061015c61072c565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b3480156101aa57600080fd5b506101b3610752565b6040518082815260200191505060405180910390f35b600154421115610241576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260168152602001807f41756374696f6e20616c726561647920656e6465642e0000000000000000000081525060200191505060405180910390fd5b60035434116102b8576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252601e8152602001807f546865726520616c7265616479206973206120686967686572206269642e000081525060200191505060405180910390fd5b6000600354146103345760035460046000600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020600082825401925050819055505b33600260006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff160217905550346003819055507ff4757a49b326036464bec6fe419a4ae38c8a02ce3e68bf0809674f6aab8ad3003334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a1565b600154421015610461576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260168152602001807f41756374696f6e206e6f742079657420656e6465642e0000000000000000000081525060200191505060405180910390fd5b600560009054906101000a900460ff16156104c7576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260238152602001806107596023913960400191505060405180910390fd5b6001600560006101000a81548160ff0219169083151502179055507fdaec4582d5d9595688c8c98545fdd1c696d41c6aeaeb636737e84ed2f5c00eda600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff16600354604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a16000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff166108fc6003549081150290604051600060405180830381858888f193505050501580156105da573d6000803e3d6000fd5b50565b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b600080600460003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020549050600081111561071d576000600460003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020819055503373ffffffffffffffffffffffffffffffffffffffff166108fc829081150290604051600060405180830381858888f1935050505061071c5780600460003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020819055506000915050610723565b5b60019150505b90565b60015481565b600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b6003548156fe61756374696f6e456e642068617320616c7265616479206265656e2063616c6c65642ea265627a7a72315820f3953a841785a2ecfa7f7a0d2995f105b2a6e7e5342b7bb8dd02984824697a1a64736f6c63430005100032",
                getCodeResult.items[0].code
            )
            assertEquals(getCodeResult.items[0].address, contractAccountIdentifier.pad256().toHexString())
        }

        val accountStateResult = getAccountState.getAll(simpleAuctionContract.accountIdentifier.pad256().toHexString()).blockingGet()
        if (accountStateResult !is GetAccountState.Record.Multiple) fail("no state saved") else {
            assertEquals(2, accountStateResult.items.size)
            assertEquals(contractAccountIdentifier.pad256().toHexString(), accountStateResult.items[0].value)
            // items[1] is (now + bidding_time) in seconds
        }
    }

    @Test
    fun `Bid on the simple auction`() {

        // given
        val (newAccountName, newAccountPrivateKey, newEthAccount) = setupTransactions.seedWithEvmBalance(17000)
        val contractAccountIdentifier = AccountIdentifier.create(newAccountName, newEthAccount.address)
        val simpleAuctionContract = SimpleAuctionContract(newAccountName, newAccountPrivateKey, newEthAccount)
        val createContractResponse = faultTolerant { simpleAuctionContract.createSimpleAuction(5, contractAccountIdentifier.toHexString()).blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        val (senderAccountName, senderPrivateKey, senderEthAccount) = setupTransactions.seedWithEvmBalance()
        val senderAccountIdentifier = AccountIdentifier.create(senderAccountName, senderEthAccount.address)

        // when
        val bidResponse = simpleAuctionContract.bid(EvmSender(
            1,
            senderEthAccount,
            senderAccountName,
            senderPrivateKey,
            senderAccountIdentifier.toHexString(),
            BigInteger.valueOf(10)
        )).blockingGet()

        // then
        assertEquals(bidResponse.statusCode, 202)

        // and when
        val accountStateResult = getAccountState.getAll(simpleAuctionContract.accountIdentifier.pad256().toHexString()).blockingGet()

        // and then
        if (accountStateResult !is GetAccountState.Record.Multiple) fail("no state saved") else {
            assertEquals(4, accountStateResult.items.size)
            assertEquals(accountStateResult.items[0].value, simpleAuctionContract.accountIdentifier.pad256().toHexString())
            // items[1] is (now + bidding_time) in seconds
            assertEquals(accountStateResult.items[2].value, senderAccountIdentifier.pad256().toHexString())
            assertEquals(accountStateResult.items[3].value, "000000000000000000000000000000000000000000000000000000000000000a")
        }
    }

    @Test
    fun `AddressX bids on the simple auction, AddressY out bids AddressX, AddressX withdraws their bid`() {

        // given
        val (beneficiaryAccountName, beneficiaryPrivateKey, beneficiaryEthAccount) = setupTransactions.seedWithEvmBalance(17000)
        val beneficiaryAccountIdentifier = AccountIdentifier.create(beneficiaryAccountName, beneficiaryEthAccount.address)

        val (contractAccountName, contractPrivateKey, contractEthAccount) = setupTransactions.seedWithEvmBalance(17000)
        val simpleAuctionContract = SimpleAuctionContract(contractAccountName, contractPrivateKey, contractEthAccount)
        val createContractResponse = faultTolerant { simpleAuctionContract.createSimpleAuction(5, beneficiaryAccountIdentifier.toHexString()).blockingGet() }
        assertEquals(202, createContractResponse.statusCode)

        val (addressXAccountName, addressXPrivateKey, addressXEthAccount) = setupTransactions.seedWithEvmBalance()
        val addressXAccountIdentifier = AccountIdentifier.create(addressXAccountName, addressXEthAccount.address)

        val (addressYAccountName, addressYPrivateKey, addressYEthAccount) = setupTransactions.seedWithEvmBalance()
        val addressYAccountIdentifier = AccountIdentifier.create(addressYAccountName, addressYEthAccount.address)

        // when
        val addressXBidResponse = faultTolerant {
            simpleAuctionContract.bid(EvmSender(
                1,
                addressXEthAccount,
                addressXAccountName,
                addressXPrivateKey,
                addressXAccountIdentifier.toHexString(),
                BigInteger.valueOf(10)
            )).blockingGet()
        }

        // and then
        assertEquals(addressXBidResponse.statusCode, 202)

        // and when
        val addressXBalanceAfterBid = getAccount.getEvmAccount(addressXAccountName).blockingGet()

        // and then
        if (addressXBalanceAfterBid !is GetAccount.Record.Single) fail("Failed to check bid balance") else {
            assertEquals("0.9990 EVM", addressXBalanceAfterBid.item.balance)
        }

        // and when
        val addressYBidResponse = faultTolerant {
            simpleAuctionContract.bid(EvmSender(
                1,
                addressYEthAccount,
                addressYAccountName,
                addressYPrivateKey,
                addressYAccountIdentifier.toHexString(),
                BigInteger.valueOf(15)
            )).blockingGet()
        }

        // and then
        assertEquals(addressYBidResponse.statusCode, 202)

        // and when
        val addressYBalanceAfterBid = getAccount.getEvmAccount(addressYAccountName).blockingGet()

        // and then
        if (addressYBalanceAfterBid !is GetAccount.Record.Single) fail("Failed to check bid balance") else {
            assertEquals("0.9985 EVM", addressYBalanceAfterBid.item.balance)
        }

        // and when
        val accountStateAfterBid2 = getAccountState.getAll(simpleAuctionContract.accountIdentifier.pad256().toHexString()).blockingGet()

        // and then
        if (accountStateAfterBid2 !is GetAccountState.Record.Multiple) fail("no state saved") else {
            assertEquals(5, accountStateAfterBid2.items.size)
            assertEquals(accountStateAfterBid2.items[0].value, beneficiaryAccountIdentifier.pad256().toHexString())
            // items[1] is (now + bidding_time) in seconds
            assertEquals(accountStateAfterBid2.items[2].value, addressYAccountIdentifier.pad256().toHexString()) // highest bidder
            assertEquals(accountStateAfterBid2.items[3].value, "000000000000000000000000000000000000000000000000000000000000000f")
            assertEquals(accountStateAfterBid2.items[4].value, "000000000000000000000000000000000000000000000000000000000000000a")
        }

        // and when
        val addressXWithdrawResponse = faultTolerant {
            simpleAuctionContract.withdraw(EvmSender(
                2,
                addressXEthAccount,
                addressXAccountName,
                addressXPrivateKey,
                addressXAccountIdentifier.toHexString()
            )).blockingGet()
        }

        // and then
        val addressXString = addressXAccountIdentifier.toHexString()
        val contractString = simpleAuctionContract.accountIdentifier.toHexString()
        assertEquals(addressXWithdrawResponse.statusCode, 202)

        // and when
        val addressXBalanceAfterWithdraw = getAccount.getEvmAccount(addressXAccountName).blockingGet()

        // and then
        if (addressXBalanceAfterWithdraw !is GetAccount.Record.Single) fail("Failed to check withdrawal balance") else {
            assertEquals("1.0000 EVM", addressXBalanceAfterWithdraw.item.balance)
        }

        // and when
        val contractBalanceBeforeAuctionEnd = getAccount.getEvmAccount(contractAccountName).blockingGet()

        // and then
        if (contractBalanceBeforeAuctionEnd !is GetAccount.Record.Single) fail("Failed to check beneficiary balance") else {
            assertEquals("1.0015 EVM", contractBalanceBeforeAuctionEnd.item.balance)
        }

        // and when
        val auctionEndResponse = faultTolerant {
            simpleAuctionContract.auctionEnd(EvmSender(
                1,
                beneficiaryEthAccount,
                beneficiaryAccountName,
                beneficiaryPrivateKey,
                beneficiaryAccountIdentifier.toHexString()
            )).blockingGet()
        }

        // and then
        Thread.sleep(7000) // wait at least 5 seconds for the auction to end

        assertEquals(202, auctionEndResponse.statusCode)

        // and when
        val balanceAfterAuctionEnd =getAccount.getEvmAccount(beneficiaryAccountName).blockingGet()

        // and then
        if (balanceAfterAuctionEnd !is GetAccount.Record.Single) fail("Failed to check beneficiary balance") else {
            assertEquals("0.9985 EVM", balanceAfterAuctionEnd.item.balance)
        }
    }
}
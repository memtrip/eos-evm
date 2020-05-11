package com.memtrip.evm.eos.evm.contracts.misc

import com.memtrip.eos.chain.actions.ChainResponse
import com.memtrip.eos.core.crypto.EosPrivateKey
import com.memtrip.eos.http.rpc.model.transaction.response.TransactionCommitted
import com.memtrip.evm.eos.evm.EvmContract
import com.memtrip.evm.eos.evm.EvmSender
import com.memtrip.evm.eos.evm.contracts.CreateResponse
import com.memtrip.evm.ethereum.EthAccount
import io.reactivex.Single
import org.web3j.abi.datatypes.Address
import org.web3j.abi.datatypes.Uint
import java.math.BigInteger

/**
pragma solidity >=0.4.22 <0.6.0;

contract SimpleAuction {
    // Parameters of the auction. Times are either
    // absolute unix timestamps (seconds since 1970-01-01)
    // or time periods in seconds.
    address payable public beneficiary;
    uint public auctionEndTime;

    // Current state of the auction.
    address public highestBidder;
    uint public highestBid;

    // Allowed withdrawals of previous bids
    mapping(address => uint) pendingReturns;

    // Set to true at the end, disallows any change.
    // By default initialized to `false`.
    bool ended;

    // Events that will be emitted on changes.
    event HighestBidIncreased(address bidder, uint amount);
    event AuctionEnded(address winner, uint amount);

    // The following is a so-called natspec comment,
    // recognizable by the three slashes.
    // It will be shown when the user is asked to
    // confirm a transaction.

    /// Create a simple auction with `_biddingTime`
    /// seconds bidding time on behalf of the
    /// beneficiary address `_beneficiary`.
    constructor(
        uint _biddingTime,
        address payable _beneficiary
    ) public {
        beneficiary = _beneficiary;
        auctionEndTime = now + _biddingTime;
    }

    /// Bid on the auction with the value sent
    /// together with this transaction.
    /// The value will only be refunded if the
    /// auction is not won.
    function bid() public payable {
        // No arguments are necessary, all
        // information is already part of
        // the transaction. The keyword payable
        // is required for the function to
        // be able to receive Ether.

        // Revert the call if the bidding
        // period is over.
        require(
            now <= auctionEndTime,
            "Auction already ended."
        );

        // If the bid is not higher, send the
        // money back.
        require(
            msg.value > highestBid,
            "There already is a higher bid."
        );

        if (highestBid != 0) {
            // Sending back the money by simply using
            // highestBidder.send(highestBid) is a security risk
            // because it could execute an untrusted contract.
            // It is always safer to let the recipients
            // withdraw their money themselves.
            pendingReturns[highestBidder] += highestBid;
        }
        highestBidder = msg.sender;
        highestBid = msg.value;
        emit HighestBidIncreased(msg.sender, msg.value);
    }

    /// Withdraw a bid that was overbid.
    function withdraw() public returns (bool) {
        uint amount = pendingReturns[msg.sender]
        if (amount > 0) {
            // It is important to set this to zero because the recipient
            // can call this function again as part of the receiving call
            // before `send` returns.
            pendingReturns[msg.sender] = 0;

            if (!msg.sender.send(amount)) {
                // No need to call throw here, just reset the amount owing
                pendingReturns[msg.sender] = amount;
                return false;
            }
        }
        return true;
    }

    /// End the auction and send the highest bid
    /// to the beneficiary.
    function auctionEnd() public {
        // It is a good guideline to structure functions that interact
        // with other contracts (i.e. they call functions or send Ether)
        // into three phases:
        // 1. checking conditions
        // 2. performing actions (potentially changing conditions)
        // 3. interacting with other contracts
        // If these phases are mixed up, the other contract could call
        // back into the current contract and modify the state or cause
        // effects (ether payout) to be performed multiple times.
        // If functions called internally include interaction with external
        // contracts, they also have to be considered interaction with
        // external contracts.

        // 1. Conditions
        require(now >= auctionEndTime, "Auction not yet ended.");
        require(!ended, "auctionEnd has already been called.");

        // 2. Effects
        ended = true;
        emit AuctionEnded(highestBidder, highestBid);

        // 3. Interaction
        beneficiary.transfer(highestBid);
    }
}
*/
class SimpleAuctionContract(
    contractAccountName: String,
    contractPrivateKey: EosPrivateKey,
    contractEthAccount: EthAccount
) : EvmContract(
    contractAccountName,
    contractPrivateKey,
    contractEthAccount,
    "0x608060405234801561001057600080fd5b506040516108583803806108588339818101604052604081101561003357600080fd5b810190808051906020019092919080519060200190929190505050806000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555081420160018190555050506107b0806100a86000396000f3fe6080604052600436106100705760003560e01c80633ccfd60b1161004e5780633ccfd60b146100ed5780634b449cba1461011c57806391f9015714610147578063d57bde791461019e57610070565b80631998aeef146100755780632a24f46c1461007f57806338af3eed14610096575b600080fd5b61007d6101c9565b005b34801561008b57600080fd5b506100946103e9565b005b3480156100a257600080fd5b506100ab6105dd565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b3480156100f957600080fd5b50610102610602565b604051808215151515815260200191505060405180910390f35b34801561012857600080fd5b50610131610726565b6040518082815260200191505060405180910390f35b34801561015357600080fd5b5061015c61072c565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b3480156101aa57600080fd5b506101b3610752565b6040518082815260200191505060405180910390f35b600154421115610241576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260168152602001807f41756374696f6e20616c726561647920656e6465642e0000000000000000000081525060200191505060405180910390fd5b60035434116102b8576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252601e8152602001807f546865726520616c7265616479206973206120686967686572206269642e000081525060200191505060405180910390fd5b6000600354146103345760035460046000600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020600082825401925050819055505b33600260006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff160217905550346003819055507ff4757a49b326036464bec6fe419a4ae38c8a02ce3e68bf0809674f6aab8ad3003334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a1565b600154421015610461576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260168152602001807f41756374696f6e206e6f742079657420656e6465642e0000000000000000000081525060200191505060405180910390fd5b600560009054906101000a900460ff16156104c7576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260238152602001806107596023913960400191505060405180910390fd5b6001600560006101000a81548160ff0219169083151502179055507fdaec4582d5d9595688c8c98545fdd1c696d41c6aeaeb636737e84ed2f5c00eda600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff16600354604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a16000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff166108fc6003549081150290604051600060405180830381858888f193505050501580156105da573d6000803e3d6000fd5b50565b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b600080600460003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020549050600081111561071d576000600460003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020819055503373ffffffffffffffffffffffffffffffffffffffff166108fc829081150290604051600060405180830381858888f1935050505061071c5780600460003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020819055506000915050610723565b5b60019150505b90565b60015481565b600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b6003548156fe61756374696f6e456e642068617320616c7265616479206265656e2063616c6c65642ea265627a7a72315820f3953a841785a2ecfa7f7a0d2995f105b2a6e7e5342b7bb8dd02984824697a1a64736f6c63430005100032"
) {

    fun createSimpleAuction(biddingTime: Long, address: String): Single<CreateResponse> {
        return create(listOf(Uint(BigInteger.valueOf(biddingTime)), Address(address)))
    }

    fun bid(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "bid",
            listOf(),
            emptyList(),
            sender
        )
    }

    fun withdraw(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "withdraw",
            listOf(),
            emptyList(),
            sender
        )
    }

    fun auctionEnd(sender: EvmSender): Single<ChainResponse<TransactionCommitted>> {
        return executeMethod(
            "auctionEnd",
            listOf(),
            emptyList(),
            sender
        )
    }
}
#pragma once
#include <memory>
#include <evm/types.h>
#include <evm/external.h>
#include <evm/transaction.hpp>
#include <evm/hash.hpp>

class Context {
  public:
    explicit Context(
      uint256_t chainIdArg,
      uint256_t blockNumberArg,
      uint256_t timestampArg,
      uint256_t gasLimitArg,
      uint256_t coinbaseArg,
      uint256_t difficultyArg,
      uint256_t blockHashArg,
      uint256_t codeAddressArg,
      uint256_t codeHashArg,
      uint256_t codeVersionArg,
      uint256_t addressArg,
      uint256_t senderArg,
      uint256_t originArg,
      gas_t gasArg,
      uint256_t gasPriceArg,
      uint256_t valueArg,
      std::shared_ptr<bytes_t> codeArg,
      std::shared_ptr<bytes_t> dataArg
    ): 
      chainId(chainIdArg), 
      blockNumber(blockNumberArg), 
      timestamp(timestampArg),
      gasLimit(gasLimitArg),
      coinbase(coinbaseArg),
      difficulty(difficultyArg),
      blockHash(blockHashArg),
      codeAddress(codeAddressArg),
      codeHash(codeHashArg),
      codeVersion(codeVersionArg),
      address(addressArg),
      sender(senderArg),
      origin(originArg),
      gas(gasArg),
      gasPrice(gasPriceArg),
      value(valueArg),
      code(codeArg),
      data(dataArg) { 
      };
    uint256_t chainId;
    uint256_t blockNumber;
    uint256_t timestamp;
    uint256_t gasLimit;
    uint256_t coinbase;
    uint256_t difficulty;
    uint256_t blockHash;
    uint256_t codeAddress;
    uint256_t codeHash;
    uint256_t codeVersion;
    uint256_t address; /* Receive address, the same as codeAddress unless using CALLCODE */
    uint256_t sender;
    uint256_t origin;
    gas_t gas;
    uint256_t gasPrice;
    uint256_t value;
    std::shared_ptr<bytes_t> code;
    std::shared_ptr<bytes_t> data;

    static std::shared_ptr<Context> makeCreate(
      const env_t& env, 
      const uint256_t& senderAddress, 
      std::shared_ptr<std::vector<RLPItem>> rlp
    ) {
      return std::make_shared<Context>(
        env.chainId,
        env.blockNumber,
        env.timestamp,
        env.gasLimit,
        env.coinbase,
        env.difficulty,
        env.blockHash,
        senderAddress, /* codeAddress, TODO: clarify where this comes from */
        uint256_t(0), /* codeHash, TODO: clarify where this comes from */
        uint256_t(0), /* codeVersion, TODO: clarify where this comes from */
        senderAddress, /* address, TODO: clarify where this comes from */
        senderAddress, /* sender */
        uint256_t(0), /* origin */
        Transaction::gas(rlp),
        Transaction::gasPrice(rlp),
        Transaction::value(rlp),
        std::make_shared<bytes_t>(bytes_t(
          rlp->at(0).values[Transaction::RLP_DATA].bytes.begin(), 
          rlp->at(0).values[Transaction::RLP_DATA].bytes.end()
        )),
        std::make_shared<bytes_t>(bytes_t())
      );
    }

    static std::shared_ptr<Context> makeCall(
      const env_t& env, 
      const uint256_t& senderAddress, 
      const uint256_t& toAddress,
      std::shared_ptr<std::vector<RLPItem>> rlp, 
      std::shared_ptr<External> external
    ) {
      std::shared_ptr<bytes_t> code = external->code(toAddress);
      return std::make_shared<Context>(
        env.chainId,
        env.blockNumber,
        env.timestamp,
        env.gasLimit,
        env.coinbase,
        env.difficulty,
        env.blockHash,
        toAddress, /* codeAddress, TODO: clarify where this comes from */
        Hash::keccak256Word(code), /* codeHash, TODO: clarify where this comes from */
        uint256_t(0), /* codeVersion, TODO: clarify where this comes from */
        toAddress, /* address, TODO: clarify where this comes from */
        senderAddress, /* sender */
        uint256_t(0), /* origin */
        Transaction::gas(rlp),
        Transaction::gasPrice(rlp),
        Transaction::value(rlp),
        code,
        std::make_shared<bytes_t>(bytes_t(
          rlp->at(0).values[Transaction::RLP_DATA].bytes.begin(), 
          rlp->at(0).values[Transaction::RLP_DATA].bytes.end()
        ))
      );
    }

    static std::shared_ptr<Context> makeInnerCall(
      std::shared_ptr<Context> parentContext,
      const uint256_t& codeAddress,
      const uint256_t& receiveAddress,
      const uint256_t& senderAddress,
      const gas_t& gas,
      const uint256_t& gasPrice,
      const uint256_t& value,
      std::shared_ptr<bytes_t> data,
      std::shared_ptr<External> external
    ) {
      std::shared_ptr<bytes_t> code = external->code(codeAddress);
      return std::make_shared<Context>(
        parentContext->chainId,
        parentContext->blockNumber,
        parentContext->timestamp,
        parentContext->gasLimit,
        parentContext->coinbase,
        parentContext->difficulty,
        parentContext->blockHash,
        codeAddress, /* codeAddress, TODO: clarify where this comes from */
        Hash::keccak256Word(code),
        uint256_t(0), /* codeVersion, TODO: clarify where this comes from */
        receiveAddress, /* address, TODO: clarify where this comes from */
        senderAddress, /* sender */
        uint256_t(0), /* origin */
        gas,
        gasPrice,
        value,
        code,
        data
      );
    } 

    static std::shared_ptr<Context> makeInnerCreate(
      std::shared_ptr<Context> parentContext,
      const uint256_t& codeAddress,
      const uint256_t& receiveAddress,
      const uint256_t& senderAddress,
      const gas_t& gas,
      const uint256_t& gasPrice,
      const uint256_t& value,
      std::shared_ptr<bytes_t> code
    ) {
      return std::make_shared<Context>(
        parentContext->chainId,
        parentContext->blockNumber,
        parentContext->timestamp,
        parentContext->gasLimit,
        parentContext->coinbase,
        parentContext->difficulty,
        parentContext->blockHash,
        codeAddress, /* codeAddress, TODO: clarify where this comes from */
        Hash::keccak256Word(code),
        uint256_t(0), /* codeVersion, TODO: clarify where this comes from */
        receiveAddress, /* address, TODO: clarify where this comes from */
        senderAddress, /* sender */
        uint256_t(0), /* origin */
        gas,
        gasPrice,
        value,
        code,
        std::make_shared<bytes_t>(bytes_t())
      );
    } 

    static std::shared_ptr<Context> makeCodeCall(
      const env_t& env, 
      const uint256_t& senderAddress, 
      const bytes_t& code,
      std::shared_ptr<std::vector<RLPItem>> rlp, 
      std::shared_ptr<External> external
    ) {
      return std::make_shared<Context>(
        env.chainId,
        env.blockNumber,
        env.timestamp,
        env.gasLimit,
        env.coinbase,
        env.difficulty,
        env.blockHash,
        senderAddress, /* codeAddress, TODO: clarify where this comes from */
        uint256_t(0), /* codeHash, TODO: clarify where this comes from */
        uint256_t(0), /* codeVersion, TODO: clarify where this comes from */
        senderAddress, /* address, TODO: clarify where this comes from */
        senderAddress, /* sender */
        uint256_t(0), /* origin */
        Transaction::gas(rlp),
        Transaction::gasPrice(rlp),
        Transaction::value(rlp),
        std::make_shared<bytes_t>(code),
        std::make_shared<bytes_t>(bytes_t(
          rlp->at(0).values[Transaction::RLP_DATA].bytes.begin(), 
          rlp->at(0).values[Transaction::RLP_DATA].bytes.end()
        ))
      );
    }
};
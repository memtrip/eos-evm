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
      uint256_t addressArg,
      uint256_t senderArg,
      uint256_t originArg,
      gas_t gasArg,
      uint256_t gasPriceArg,
      uint256_t valueArg,
      bool isStaticArg,
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
      address(addressArg),
      sender(senderArg),
      origin(originArg),
      gas(gasArg),
      gasPrice(gasPriceArg),
      value(valueArg),
      isStatic(isStaticArg),
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
    uint256_t address; /* Receive address, the same as codeAddress unless using CALLCODE */
    uint256_t sender;
    uint256_t origin;
    gas_t gas;
    uint256_t gasPrice;
    uint256_t value;
    bool isStatic;
    std::shared_ptr<bytes_t> code;
    std::shared_ptr<bytes_t> data;

    static std::shared_ptr<Context> makeCreate(
      const env_t& env, 
      const uint256_t& senderAddress, 
      const uint256_t& codeAddress, 
      const gas_t gasLimit,
      const uint256_t& gasPrice,
      const uint256_t& value,
      std::shared_ptr<bytes_t> code
    ) {
      return std::make_shared<Context>(
        env.chainId,
        env.blockNumber,
        env.timestamp,
        env.gasLimit,
        env.coinbase,
        env.difficulty,
        env.blockHash,
        codeAddress, /* codeAddress */
        Hash::keccak256Word(code), /* codeHash */
        codeAddress, /* address */
        senderAddress, /* sender */
        senderAddress, /* origin */
        gasLimit,
        gasPrice,
        value,
        false,
        code,
        std::make_shared<bytes_t>()
      );
    }

    static std::shared_ptr<Context> makeCall(
      const env_t& env, 
      const uint256_t& senderAddress, 
      const uint256_t& toAddress,
      const gas_t gasLimit,
      const uint256_t& gasPrice,
      const uint256_t& value,
      std::shared_ptr<bytes_t> code,
      std::shared_ptr<bytes_t> data
    ) {
      return std::make_shared<Context>(
        env.chainId,
        env.blockNumber,
        env.timestamp,
        env.gasLimit,
        env.coinbase,
        env.difficulty,
        env.blockHash,
        toAddress, /* codeAddress */
        Hash::keccak256Word(code), 
        toAddress, /* address */
        senderAddress, /* sender */
        senderAddress, /* origin */
        gasLimit,
        gasPrice,
        value,
        false,
        code,
        data
      );
    }

    static std::shared_ptr<Context> makeInnerCall(
      std::shared_ptr<Context> parentContext,
      const uint256_t& codeExecutionAddress, // the address to execute the code as
      const uint256_t& codeAddress, // the address to fetch the code from
      const uint256_t& receiveAddress,
      const uint256_t& senderAddress,
      const gas_t& gas,
      const uint256_t& gasPrice,
      const uint256_t& value,
      bool isStatic,
      std::shared_ptr<bytes_t> code,
      std::shared_ptr<bytes_t> data
    ) {
      return std::make_shared<Context>(
        parentContext->chainId,
        parentContext->blockNumber,
        parentContext->timestamp,
        parentContext->gasLimit,
        parentContext->coinbase,
        parentContext->difficulty,
        parentContext->blockHash,
        codeExecutionAddress,
        Hash::keccak256Word(code),
        receiveAddress, 
        senderAddress, 
        parentContext->origin, 
        gas,
        gasPrice,
        value,
        isStatic,
        code,
        data
      );
    } 

    static std::shared_ptr<Context> makeInnerCreate(
      std::shared_ptr<Context> parentContext,
      const uint256_t& codeAddress,
      const gas_t& gas,
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
        codeAddress, /* codeAddress */
        Hash::keccak256Word(code),
        codeAddress, /* address */
        codeAddress, /* sender */
        parentContext->origin, /* origin */
        gas,
        parentContext->gasPrice,
        value,
        false,
        code,
        std::make_shared<bytes_t>()
      );
    } 

    static std::shared_ptr<Context> makeCodeCall(
      const env_t& env, 
      const uint256_t& senderAddress, 
      const gas_t gasLimit,
      const uint256_t& gasPrice,
      const uint256_t& value,  
      std::shared_ptr<bytes_t> code,
      std::shared_ptr<bytes_t> data
    ) {
      return std::make_shared<Context>(
        env.chainId,
        env.blockNumber,
        env.timestamp,
        env.gasLimit,
        env.coinbase,
        env.difficulty,
        env.blockHash,
        senderAddress, /* codeAddress */
        Hash::keccak256Word(code), /* codeHash */
        senderAddress, /* address */
        senderAddress, /* sender */
        senderAddress, /* origin */
        gasLimit,
        gasPrice,
        value,
        false,
        code,
        data
      );
    }
};
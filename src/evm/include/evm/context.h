#pragma once
#include <memory>
#include <evm/types.h>

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
    uint256_t address;
    uint256_t sender;
    uint256_t origin;
    gas_t gas;
    uint256_t gasPrice;
    uint256_t value;
    std::shared_ptr<bytes_t> code;
    std::shared_ptr<bytes_t> data;
};
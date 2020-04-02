#pragma once

#include <memory>
#include <vector>
#include <evm/types.h>

class Transaction {
  public:
    static bool hasSignature(std::shared_ptr<std::vector<RLPItem>> rlp);
    static std::shared_ptr<bytes_t> data(std::shared_ptr<std::vector<RLPItem>> rlp);
    static bytes_t signature(std::shared_ptr<std::vector<RLPItem>> rlp);
    static bytes_t digest(std::shared_ptr<std::vector<RLPItem>> rlp, uint8_t chainId);
    static TransactionActionType type(std::shared_ptr<std::vector<RLPItem>> rlp);
    static uint256_t nonce(std::shared_ptr<std::vector<RLPItem>> rlp);
    static uint256_t gasPrice(std::shared_ptr<std::vector<RLPItem>> rlp);
    static uint64_t gasLimit(std::shared_ptr<std::vector<RLPItem>> rlp);
    static uint256_t value(std::shared_ptr<std::vector<RLPItem>> rlp);
    static bytes_t v(std::shared_ptr<std::vector<RLPItem>> rlp);
    static bytes_t r(std::shared_ptr<std::vector<RLPItem>> rlp);
    static bytes_t s(std::shared_ptr<std::vector<RLPItem>> rlp);
    static bytes_t address(std::shared_ptr<std::vector<RLPItem>> rlp);
    static bytes_t prefixedBytes(const bytes_t& hash);
  private:
    static uint8_t eip155Compat(const bytes_t& bytes);
};
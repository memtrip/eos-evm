#pragma once

#include <vector>
#include <evm/types.h>

class Transaction {
  public:
    static transaction_t parse(std::string hex, uint8_t chainId);
    static bool signatureExists(transaction_t& transaction);
    static bytes_t signatureBytes(transaction_t& transaction);
    static bytes_t prefixedBytes(const bytes_t& hash);
  private:
    static bytes_t digest(const rlp_t& rlp, uint8_t chainId);
    static uint8_t eip155Compat(const bytes_t& bytes);
};
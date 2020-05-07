#pragma once
#include <vector>
#include <memory>
#include <keccak/keccak.hpp>
#include <evm/types.h>
#include <evm/big_int.hpp>

class Hash {
  public:
    static uint256_t keccak256WordPair(const uint256_t& word1, const uint256_t& word2) {
      bytes_t word1Bytes = BigInt::toBytes(word1);
      bytes_t word2Bytes = BigInt::toBytes(word2);
      word1Bytes.insert(word1Bytes.end(), word2Bytes.begin(), word2Bytes.end());
      return keccak256Word(word1Bytes);
    }

    static bytes_t keccak256(const bytes_t& bytes) {
      ethash::hash256 result = ethash::keccak256(bytes.data(), bytes.size());
      bytes_t hashBytes(&result.bytes[0], &result.bytes[32]);
      return hashBytes;
    }

    static bytes_t keccak256(const std::shared_ptr<bytes_t> bytes) {
      ethash::hash256 result = ethash::keccak256(bytes->data(), bytes->size());
      bytes_t hashBytes(&result.bytes[0], &result.bytes[32]);
      return hashBytes;
    }

    static uint256_t keccak256Word(const bytes_t& bytes) {
      ethash::hash256 result = ethash::keccak256(bytes.data(), bytes.size());
      return intx::be::load<uint256_t>(result.bytes);
    }

    static uint256_t keccak256Word(const std::shared_ptr<bytes_t> bytes) {
      ethash::hash256 result = ethash::keccak256(bytes->data(), bytes->size());
      return intx::be::load<uint256_t>(result.bytes);
    }

    static bytes_t keccak256(const std::array<uint8_t, 33>& bytes) {
      ethash::hash256 result = ethash::keccak256(bytes.data(), bytes.size());
      bytes_t hashBytes(&result.bytes[0], &result.bytes[32]);
      return hashBytes;
    }
};
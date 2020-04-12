#pragma once
#include <vector>
#include <memory>
#include <evm/types.h>

class Hash {
  public:
    static uint256_t keccak256Word(const uint256_t& word1, const uint256_t& word2);
    static bytes_t keccak256(const bytes_t& bytes);
    static bytes_t keccak256(const std::shared_ptr<bytes_t> bytes);
    static bytes_t keccak256(const std::array<uint8_t, 33>& bytes);
    static bytes_t keccak512(const bytes_t& bytes);
};
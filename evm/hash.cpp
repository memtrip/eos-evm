#include "hash.h"
#include "keccak/keccak.hpp"
#include "big_int.h"
#include "utils.h"

uint256_t Hash::keccak256(std::vector<uint8_t>& bytes) {
  ethash::hash256 result = ethash::keccak256(bytes.data(), bytes.size());
  std::vector<uint8_t> hashBytes(&result.bytes[0], &result.bytes[32]);
  std::reverse(hashBytes.begin(), hashBytes.end()); 
  return BigInt::fromBytes(hashBytes);
}

uint256_t Hash::keccak512(std::vector<uint8_t>& bytes) {
  ethash::hash512 result = ethash::keccak512(bytes.data(), bytes.size());
  std::vector<uint8_t> hashBytes(&result.bytes[0], &result.bytes[64]);
  std::reverse(hashBytes.begin(), hashBytes.end()); 
  return BigInt::fromBytes(hashBytes);
}
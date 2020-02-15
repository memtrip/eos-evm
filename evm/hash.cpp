#include "hash.h"
#include "keccak/keccak.hpp"
#include "utils.h"

bytes_t Hash::keccak256(bytes_t& bytes) {
  ethash::hash256 result = ethash::keccak256(bytes.data(), bytes.size());
  bytes_t hashBytes(&result.bytes[0], &result.bytes[32]);
  return hashBytes;
}

bytes_t Hash::keccak512(bytes_t& bytes) {
  ethash::hash512 result = ethash::keccak512(bytes.data(), bytes.size());
  bytes_t hashBytes(&result.bytes[0], &result.bytes[64]);
  return hashBytes;
}
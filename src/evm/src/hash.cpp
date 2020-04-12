#include <evm/hash.h>
#include <evm/big_int.h>
#include <keccak/keccak.hpp>

uint256_t Hash::keccak256Word(const uint256_t& word1, const uint256_t& word2) {
  bytes_t word1Bytes = BigInt::toBytes(word1);
  bytes_t word2Bytes = BigInt::toBytes(word2);
  word1Bytes.insert(word1Bytes.end(), word2Bytes.begin(), word2Bytes.end());
  bytes_t hashBytes = keccak256(word1Bytes);
  return BigInt::fromBigEndianBytes(hashBytes);
}

bytes_t Hash::keccak256(const bytes_t& bytes) {
  ethash::hash256 result = ethash::keccak256(bytes.data(), bytes.size());
  bytes_t hashBytes(&result.bytes[0], &result.bytes[32]);
  return hashBytes;
}

bytes_t Hash::keccak256(std::shared_ptr<bytes_t> bytes) {
  ethash::hash256 result = ethash::keccak256(bytes->data(), bytes->size());
  bytes_t hashBytes(&result.bytes[0], &result.bytes[32]);
  return hashBytes;
}

bytes_t Hash::keccak256(const std::array<uint8_t, 33>& bytes) {
  ethash::hash256 result = ethash::keccak256(bytes.data(), bytes.size());
  bytes_t hashBytes(&result.bytes[0], &result.bytes[32]);
  return hashBytes;
}

bytes_t Hash::keccak512(const bytes_t& bytes) {
  ethash::hash512 result = ethash::keccak512(bytes.data(), bytes.size());
  bytes_t hashBytes(&result.bytes[0], &result.bytes[64]);
  return hashBytes;
}
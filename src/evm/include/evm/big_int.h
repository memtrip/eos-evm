#pragma once
#include <memory>
#include <string>
#include <vector>
#include <array>
#include <evm/types.h>

class BigInt {
  public:
    static uint256_t fromBigEndianBytes(const bytes_t& bytes);
    static uint256_t fromBytes(const bytes_t& bytes);
    static uint256_t fromHex(const std::string& hex);
    static uint256_t fromCompressedKey(const compressed_key_t& compressedKey);
    static bytes_t toBytes(const uint256_t& input);
    static std::array<uint8_t, 32> toFixed32(const uint256_t& input);
    static uint256_t load32(size_t begin, std::shared_ptr<bytes_t> bytes);
};
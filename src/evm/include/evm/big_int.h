#pragma once
#include <memory>
#include <string>
#include <vector>
#include <evm/types.h>

class BigInt {
  public:
    static uint256_t fromBigEndianBytes(bytes_t& bytes);
    static uint256_t fromBytes(bytes_t& bytes);
    static uint256_t fromHex(std::string hex);
    static uint256_t fromCompressedKey(compressed_key_t& compressedKey);
    static bytes_t toBytes(uint256_t input);
    static uint256_t load32(size_t begin, std::shared_ptr<bytes_t> bytes);
};
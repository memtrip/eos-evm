#pragma once
#include <memory>
#include <string>
#include <vector>
#include <array>
#include <evm/types.h>

class BigInt {
  public:
    static uint256_t fromBigEndianBytes(const bytes_t& bytes) {
      uint8_t data[WORD_SIZE];
      uint8_t offset = WORD_SIZE - bytes.size();
      std::fill_n(data, WORD_SIZE, 0);
      std::copy(bytes.begin(), bytes.end(), data + offset);
      return intx::be::load<uint256_t>(data);
    }

    static uint256_t fromFixed32(const std::array<uint8_t, 32>& bytes) {
      uint8_t data[WORD_SIZE];
      uint8_t offset = WORD_SIZE - bytes.size();
      std::fill_n(data, WORD_SIZE, 0);
      std::copy(bytes.begin(), bytes.end(), data + offset);
      return intx::be::load<uint256_t>(data);
    }

    static bytes_t toBytes(const uint256_t& input) {
      bytes_t data;
      uint8_t bytes[32]; 
      intx::be::store(bytes, input);
      data.insert(data.end(), bytes, bytes + 32);
      return data;
    }

    static std::array<uint8_t, 32> toFixed32(const uint256_t& input) {
      std::array<uint8_t, 32> data {}; 
      uint8_t bytes[32]; 
      intx::be::store(bytes, input);
      std::move(std::begin(bytes), std::end(bytes), data.begin());
      return data;
    }

    static uint256_t load32(size_t begin, std::shared_ptr<bytes_t> bytes) {
      size_t end = std::min(begin + 32, bytes->size());
      uint8_t data[32] = {};
      for (size_t i = begin; i < end; i++)
        data[i - begin] = bytes->at(i);
      return intx::be::load<uint256_t>(data);
    }
};
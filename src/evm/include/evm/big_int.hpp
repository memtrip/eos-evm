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
      for (uint8_t i = 0; i < WORD_SIZE; i++) {
        data[i] = (i < offset) ? 0 : bytes[i - offset];
      }
      return intx::be::load<uint256_t>(data);
    }

    static uint256_t fromFixed32(const std::array<uint8_t, 32>& bytes) {
      uint8_t data[WORD_SIZE];
      uint8_t offset = WORD_SIZE - bytes.size();
      for (uint8_t i = 0; i < WORD_SIZE; i++) {
        data[i] = (i < offset) ? 0 : bytes[i - offset];
      }
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

    static uint256_t load(size_t start, size_t size, std::shared_ptr<bytes_t> bytes) {
      uint8_t data[WORD_SIZE];
      uint8_t pad = (WORD_SIZE - size);

      size_t sliceSize = start + size;
      if (sliceSize > bytes->size())
        pad += (sliceSize - bytes->size());

      for (uint8_t i = 0; i < WORD_SIZE; i++) {
        data[i] = (i < pad) ? 0 : bytes->at(start + (i - pad));
      }
      return intx::be::load<uint256_t>(data);
    }

    static uint256_t load32(size_t begin, std::shared_ptr<bytes_t> bytes) {
      size_t end = std::min(begin + WORD_SIZE, bytes->size());
      uint8_t data[WORD_SIZE] = {};
      for (size_t i = begin; i < end; i++)
        data[i - begin] = bytes->at(i);
      return intx::be::load<uint256_t>(data);
    }

    static uint256_t load32(size_t begin, const bytes_t& bytes) {
      size_t end = std::min(begin + WORD_SIZE, bytes.size());
      uint8_t data[WORD_SIZE] = {};
      for (size_t i = begin; i < end; i++)
        data[i - begin] = bytes[i];
      return intx::be::load<uint256_t>(data);
    }

    static uint256_t wei() {
      return intx::be::load<uint256_t>({ // wei / 10000 (i.e; .0000 precision) 
        0x00, 0x00, 0x5A, 0xF3, 0x10, 0x7A, 0x40, 0x00 
      });
    }
};
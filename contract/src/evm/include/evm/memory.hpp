#pragma once
#include <vector>
#include <memory>
#include <keccak/keccak.hpp>
#include <evm/types.h>
#include <evm/overflow.hpp>
#include <evm/big_int.hpp>
#include <evm/hex.hpp>
#include <evm/hash.hpp>

class Memory {
  private: 
    uint64_t memorySize;
    
    void resize(uint64_t newSize) {
      memorySize = newSize;
      memory.resize(newSize);
    }

  public:
    static constexpr uint64_t capacity = 4 * 1024;

    bytes_t memory;

    uint64_t length() const {
      return memorySize;
    }

    Memory() {
      memory = bytes_t();
      memory.reserve(capacity);
      memorySize = 0;
    };

    void expand(uint64_t size) {
      if (size > memorySize) {
        resize(size);
      }
    }

    void writeByte(uint64_t index, const uint256_t& value) {
      if (index >= length()) return;
      memory.at(index) = static_cast<uint8_t>(value);
    }

    void write(uint64_t offset, const uint256_t& word) {
      bytes_t bytes = BigInt::toBytes(word);
      uint64_t position = offset + (WORD_SIZE - bytes.size());
      if (position >= length()) return;
      std::copy(bytes.begin(), bytes.end(), memory.begin() + offset);
    }

    uint256_t read(uint64_t offset) {
      return BigInt::load32(offset, memory);
    }

    void writeSlice(uint64_t offset, uint64_t size, const bytes_t& bytes) {
      if (!isValidRange(offset, size)) return;
      std::copy(bytes.begin(), bytes.begin() + size, memory.begin() + offset);
    }

    bytes_t readSlice(uint64_t offset, uint64_t size) {
      if (!isValidRange(offset, size) 
        || offset > memorySize 
        || size > memorySize
      ) return bytes_t();
      return bytes_t(memory.begin() + offset, memory.begin() + offset + size);
    }
 
    uint256_t hashSlice(uint64_t offset, uint64_t size) {
      if (!isValidRange(offset, size) 
        || offset > memorySize 
        || size > memorySize
      ) return Hash::keccak256Word(bytes_t());

      ethash::hash256 result = ethash::keccak256(memory.data() + offset, size);
      return intx::be::load<uint256_t>(result.bytes);
    }

    std::string sliceAsString(uint64_t offset, uint64_t size) {
      if (!isValidRange(offset, size) 
        || offset > memorySize 
        || size > memorySize
      ) return "";
      return Hex::bytesToHex(bytes_t(memory.begin() + offset, memory.begin() + offset + size));
    }

    void copyData(
      uint64_t destOffset, 
      uint64_t sourceOffset,
      uint64_t size,
      std::shared_ptr<bytes_t> data
    ) {
      uint64_t outputEnd;
      if (sourceOffset > data->size() || size > data->size() || sourceOffset + size > data->size()) {
        if (sourceOffset > data->size()) {
          std::fill(
            memory.begin() + destOffset,
            memory.begin() + destOffset + size, 
            0
          );
        } else {
          uint64_t writeableOffset = destOffset + data->size() - sourceOffset;
          uint64_t writeableSize = sourceOffset + size - data->size();
          std::fill(
            memory.begin() + writeableOffset, 
            memory.begin() + writeableOffset + writeableSize, 
            0
          );
        }
        outputEnd = data->size();
      } else {
        outputEnd = (size + sourceOffset); 
      }

      if (sourceOffset < data->size()) {
        std::copy(data->begin() + sourceOffset, data->begin() + outputEnd, memory.begin() + destOffset);
      }
    }

     void copyData(
      uint64_t destOffset, 
      uint64_t sourceOffset,
      uint64_t size,
      const bytes_t& data
    ) {
      uint64_t outputEnd;
      if (sourceOffset > data.size() || size > data.size() || sourceOffset + size > data.size()) {
        if (sourceOffset > data.size()) {
          std::fill(
            memory.begin() + destOffset,
            memory.begin() + destOffset + size, 
            0
          );
        } else {
          uint64_t writeableOffset = destOffset + data.size() - sourceOffset;
          uint64_t writeableSize = sourceOffset + size - data.size();
          std::fill(
            memory.begin() + writeableOffset, 
            memory.begin() + writeableOffset + writeableSize, 
            0
          );
        }
        outputEnd = data.size();
      } else {
        outputEnd = (size + sourceOffset); 
      }

      if (sourceOffset < data.size()) {
        std::copy(data.begin() + sourceOffset, data.begin() + outputEnd, memory.begin() + destOffset);
      }
    }

    static bool isValidRange(uint64_t offset, uint64_t size) {
      overflow_t overflow = Overflow::add(offset, size);
      return size > 0 && !overflow.second;
    }

    void printBytes() {
      printf("memory{%s}\n", Hex::bytesToHex(memory).c_str());
    }
};
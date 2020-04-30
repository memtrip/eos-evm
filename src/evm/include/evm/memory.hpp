#pragma once
#include <vector>
#include <memory>
#include <evm/types.h>
#include <evm/overflow.hpp>
#include <evm/big_int.hpp>
#include <evm/hex.hpp>

class Memory {
  private: 
    uint64_t memorySize;
    
    void resize(uint64_t newSize) {
      uint64_t sizeChange = newSize - memorySize;
      memorySize = newSize;
      memory->resize(newSize);
    }

  public:
    static constexpr uint64_t capacity = 4 * 1024;

    std::shared_ptr<bytes_t> memory;

    uint64_t length() const {
      return memorySize;
    }

    Memory(std::shared_ptr<bytes_t> memoryArg) {
      memory = memoryArg;
      memorySize = 0;
      memory->reserve(capacity);
    };

    void expand(uint64_t size) {
      if (size > memorySize) {
        resize(size);
      }
    }

    void writeByte(uint64_t offset, const uint256_t& value) {
      bytes_t bytes = BigInt::toBytes(value);
      if (offset >= length()) return;
      uint8_t byte = bytes[bytes.size() - 1];
      memory->insert(memory->begin() + offset, byte);
    }

    void write(uint64_t offset, const uint256_t& word) {
      bytes_t bytes = BigInt::toBytes(word);
      uint64_t position = offset + (WORD_SIZE - bytes.size());
      if (position >= length()) return;
      memory->insert(memory->begin() + position, bytes.begin(), bytes.end());
    }

    uint256_t read(uint64_t offset) {
      if (offset >= length()) return UINT256_ZERO;
      bytes_t bytes = bytes_t(memory->begin() + offset, memory->begin() + offset + WORD_SIZE);
      return BigInt::fromBigEndianBytes(bytes);
    }

    void writeSlice(uint64_t offset, std::shared_ptr<bytes_t> bytes) {
      if (bytes->size() > 0) {
        std::copy(bytes->begin(), bytes->end(), memory->begin() + offset);
      }
    }

    void writeSlice(uint64_t offset, uint64_t size, std::shared_ptr<bytes_t> bytes) {
      if (bytes->size() > 0) {
        std::copy(bytes->begin(), bytes->begin() + size, memory->begin() + offset);
      }
    }

    void writeSlice(uint64_t offset, const bytes_t& bytes) {
      if (bytes.size() > 0) {
        std::copy(bytes.begin(), bytes.end(), memory->begin() + offset);
      }
    }

    std::shared_ptr<bytes_t> readSlice(uint64_t offset, uint64_t size) {
      if (!isValidRange(offset, size) 
        || offset > memorySize 
        || size > memorySize
      ) return std::make_shared<bytes_t>();
      return std::make_shared<bytes_t>(memory->begin() + offset, memory->begin() + offset + size);
    }
 
    std::string sliceAsString(uint64_t offset, uint64_t size) {
      if (!isValidRange(offset, size) 
        || offset > memorySize 
        || size > memorySize
      ) return "";
      return Hex::bytesToHex(bytes_t(memory->begin() + offset, memory->begin() + offset + size));
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
            memory->begin() + destOffset,
            memory->begin() + destOffset + size, 
            0
          );
        } else {
          uint64_t writeableOffset = destOffset + data->size() - sourceOffset;
          uint64_t writeableSize = sourceOffset + size - data->size();
          std::fill(
            memory->begin() + writeableOffset, 
            memory->begin() + writeableOffset + writeableSize, 
            0
          );
        }
        outputEnd = data->size();
      } else {
        outputEnd = (size + sourceOffset); 
      }

      if (sourceOffset < data->size()) {
        std::copy(data->begin() + sourceOffset, data->begin() + outputEnd, memory->begin() + destOffset);
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
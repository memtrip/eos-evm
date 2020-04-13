#pragma once
#include <vector>
#include <memory>
#include <evm/types.h>

static constexpr uint64_t capacity = 4 * 1024;

class Memory {
  public:
    Memory(std::shared_ptr<bytes_t> memoryArg) {
      memory = memoryArg;
      memorySize = 0;
      memory->reserve(capacity);
    };
    uint64_t length() const;
    void expand(uint64_t size);
    void writeByte(uint64_t offset, const uint256_t& value);
    void write(uint64_t offset, const uint256_t& word);
    uint256_t read(uint64_t offset);
    void writeSlice(uint64_t offset, std::shared_ptr<bytes_t> bytes);
    void writeSlice(uint64_t offset, const bytes_t& bytes);
    std::shared_ptr<bytes_t> readSlice(uint64_t offsetArg, uint64_t sizeArg);
    static bool isValidRange(uint64_t offset, uint64_t size);
    void copyData(
      uint64_t destOffset, 
      uint64_t sourceOffset,
      uint64_t size,
      std::shared_ptr<bytes_t> data
    );
  private: 
    std::shared_ptr<bytes_t> memory;
    uint64_t memorySize;
    void resize(uint64_t newSize);
};
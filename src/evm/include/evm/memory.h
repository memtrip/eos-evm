#pragma once
#include <vector>
#include <memory>
#include <evm/types.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/stack.h>

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
    void writeByte(const uint256_t& offset, const uint256_t& value);
    void write(const uint256_t& offset, const uint256_t& word);
    uint256_t read(const uint256_t& offset);
    void writeSlice(const uint256_t& offsetArg, const bytes_t& bytes);
    std::shared_ptr<bytes_t> readSlice(const uint256_t& offsetArg, const uint256_t& sizeArg);
    static bool isValidRange(uint64_t offset, uint64_t size);
    void copyData(
      const uint256_t& destOffset, 
      const uint256_t& sourceOffset,
      const uint256_t& size,
      std::shared_ptr<bytes_t> data
    );
  private: 
    std::shared_ptr<bytes_t> memory;
    uint64_t memorySize;
    void resize(uint64_t newSize);
};
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
    explicit Memory(const bytes_t& m = bytes_t()): memory(m), memorySize(0) {
      memory.reserve(capacity);
    };
    uint64_t length() const;
    void expand(uint64_t size);
    void writeByte(uint256_t offset, uint256_t value);
    void write(uint256_t offset, uint256_t& word);
    uint256_t read(uint256_t offset);
    void writeSlice(uint256_t offsetArg, bytes_t& bytes);
    bytes_t readSlice(uint256_t offsetArg, uint256_t sizeArg);
    static bool isValidRange(uint64_t offset, uint64_t size);
    void copyData(
      uint256_t destOffset, 
      uint256_t sourceOffset,
      uint256_t size,
      std::shared_ptr<bytes_t> data
    );
  private: 
    bytes_t memory;
    uint64_t memorySize;
    void resize(uint64_t newSize);
};
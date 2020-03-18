#include <vector>
#include <evm/types.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/stack.h>

class Memory {
  public:
    Memory(bytes_t* memoryArg);
    bytes_t* memory;
    uint64_t memorySize;
    uint64_t length();
    void expand(uint64_t size);
    void writeByte(uint256_t offset, uint256_t value);
    void write(uint256_t offset, uint256_t value);
    uint256_t read(uint256_t offset);
    void writeSlice(uint256_t offsetArg, bytes_t bytes);
    bytes_t readSlice(uint256_t offsetArg, uint256_t sizeArg);
    bool isValidRange(uint64_t offset, uint64_t size);
    ReturnData intoReturnData(uint256_t offsetArg, uint256_t sizeArg);
    void copyData(
      uint256_t destOffset, 
      uint256_t sourceOffset,
      uint256_t sizeItem,
      bytes_t bytes
    );
  private: 
    void resize(uint64_t newSize);
};
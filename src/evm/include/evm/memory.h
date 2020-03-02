#include <vector>
#include <evm/types.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/stack.h>

class Memory {
  public:
    Memory(bytes_t* memoryArg);
    bytes_t* memory;
    unsigned int length();
    void resize(unsigned int newSize);
    void expand(unsigned int size);
    void writeByte(uint256_t offset, uint256_t value);
    void write(uint256_t offset, uint256_t value);
    uint256_t read(uint256_t offset);
    void writeSlice(uint256_t offsetArg, bytes_t bytes);
    bytes_t readSlice(uint256_t offsetArg, uint256_t sizeArg);
    void writeableSlice(uint256_t offsetArg, uint256_t sizeArg);
    bool isValidRange(size_t offset, size_t size);
    ReturnData intoReturnData(uint256_t offsetArg, uint256_t sizeArg);
    void copyData(StackMachine& stack, bytes_t& bytes);
};
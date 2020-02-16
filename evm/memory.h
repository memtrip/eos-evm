#include <vector>
#include "types.h"

class Memory {
  public:
    Memory(bytes_t* memoryArg);
    bytes_t* memory;
    unsigned int size();
    void resize(unsigned int newSize);
    void expand(unsigned int size);
    void writeByte(uint256_t offset, uint256_t value);
    void write(uint256_t offset, uint256_t value);
    uint256_t read(uint256_t offset);
    void writeSlice(uint256_t offsetArg, bytes_t bytes);
    bytes_t readSlice(uint256_t offsetArg, uint256_t sizeArg);
    void writeableSlice(uint256_t offsetArg, uint256_t sizeArg);
    bool isValidRange(size_t offset, size_t size);
};
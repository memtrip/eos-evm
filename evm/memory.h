#include <vector>
#include "types.h"

class Memory {
  public:
    Memory(std::vector<char>* memoryArg);
    std::vector<char>* memory;
    unsigned int size();
    void resize(unsigned int newSize);
    void expand(unsigned int size);
    void writeByte(uint256_t offset, uint256_t value);
    void write(uint256_t offset, uint256_t value);
    void read(uint256_t offset, uint256_t* value);
    void writeSlice(uint256_t offset, Memory& memoryToWrite);
    void readSlice(uint256_t initOffset, uint256_t initSize);
    void writeableSlice(uint256_t offset, uint256_t size);
    bool isValidRange(unsigned long offset, unsigned long size);
};
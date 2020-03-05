#pragma once
#include <evm/types.h>

typedef std::pair<unsigned int, bool> overflow_t;

class Overflow {
  public:
    static overflow_t add(unsigned int value, unsigned int value2);
    static overflow_t mul(unsigned int value, unsigned int value2);
    static overflow_t toWordSize(uint256_t value);
    static int numWords(size_t byteSize);
};
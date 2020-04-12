#pragma once
#include <evm/types.h>

typedef std::pair<uint64_t, bool> overflow_t;

class Overflow {
  public:
    static overflow_t add(uint64_t value, uint64_t value2);
    static overflow_t mul(uint64_t value, uint64_t value2);
    static overflow_t sub(uint64_t value, uint64_t value2);
    static overflow_t uint256Cast(const uint256_t& value);
    static overflow_t toWordSize(const uint256_t& value);
    static uint64_t numWords(uint64_t byteSize);
};
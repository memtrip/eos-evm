#pragma once
#include <evm/types.h>

typedef std::pair<uint64_t, bool> overflow_t;

class Overflow {
  public:
    static overflow_t add(uint64_t value, uint64_t value2) {
      if (value > UINT_MAX - value2) return std::make_pair(0, true);
      return std::make_pair(value + value2, false);
    }

    static overflow_t mul(uint64_t value, uint64_t value2) {
      if (value > UINT_MAX / value2) return std::make_pair(0, true);
      return std::make_pair(value * value2, false);
    }

    static overflow_t sub(uint64_t value, uint64_t value2) {
      if (value2 > value) return std::make_pair(0, true);
      return std::make_pair(value - value2, false);
    }

    static std::pair<uint256_t, bool> sub(uint256_t value, uint256_t value2) {
      if (value2 > value) return std::make_pair(0, true);
      return std::make_pair(value - value2, false);
    }

    static overflow_t uint256Cast(const uint256_t& value) {
      if (value > std::numeric_limits<uint64_t>::max()) return std::make_pair(0, true);
      return std::make_pair(static_cast<uint64_t>(value), false);
    }

    static overflow_t toWordSize(const uint256_t& value) {
      overflow_t gas = add(static_cast<uint64_t>(value), 31);
      if (gas.second) {
        return gas;
      }

      return std::make_pair(gas.first >> 5, false);
    }

    static uint64_t numWords(uint64_t byteSize) {
      return byteSize + (WORD_SIZE - 1) / 32;
    }
};
#include <utility>
#include <climits>
#include <evm/overflow.h>
#include <evm/types.h>

overflow_t Overflow::add(unsigned int value, unsigned int value2) {
  if (value > UINT_MAX - value2) return std::make_pair(0, true);
  return std::make_pair(value + value2, false);
}

overflow_t Overflow::mul(unsigned int value, unsigned int value2) {
  if (value > UINT_MAX / value2) return std::make_pair(0, true);
  return std::make_pair(value * value2, false);
}

overflow_t Overflow::toWordSize(uint256_t value) {
  overflow_t gas = add(static_cast<gas_t>(value), 31);
  if (gas.second) {
    return gas;
  }

  return std::make_pair(gas.first >> 5, false);
}

int Overflow::numWords(size_t byteSize) {
  return static_cast<int>(byteSize) + (WORD_SIZE - 1) / 32;
}
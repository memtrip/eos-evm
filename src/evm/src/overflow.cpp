#include <utility>
#include <climits>
#include <evm/overflow.h>
#include <evm/types.h>

overflow_t Overflow::add(uint64_t value, uint64_t value2) {
  if (value > UINT_MAX - value2) return std::make_pair(0, true);
  return std::make_pair(value + value2, false);
}

overflow_t Overflow::mul(uint64_t value, uint64_t value2) {
  if (value > UINT_MAX / value2) return std::make_pair(0, true);
  return std::make_pair(value * value2, false);
}

overflow_t Overflow::sub(uint64_t value, uint64_t value2) {
  if (value2 > value) return std::make_pair(0, true);
  return std::make_pair(value - value2, false);
}

overflow_t Overflow::uint256Cast(uint256_t value) {
  if (value > std::numeric_limits<uint64_t>::max()) return std::make_pair(0, true);
  return std::make_pair(static_cast<uint64_t>(value), false);
}

overflow_t Overflow::toWordSize(uint256_t value) {
  overflow_t gas = add(static_cast<uint64_t>(value), 31);
  if (gas.second) {
    return gas;
  }

  return std::make_pair(gas.first >> 5, false);
}

uint64_t Overflow::numWords(uint64_t byteSize) {
  return byteSize + (WORD_SIZE - 1) / 32;
}
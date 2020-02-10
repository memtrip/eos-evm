#include <utility>
#include <climits>
#include "overflow.h"

std::pair<unsigned int, bool> Overflow::add(unsigned int value, unsigned int value2) {
  if (value > UINT_MAX - value2) return std::make_pair(0, true);
  return std::make_pair(value + value2, false);
}
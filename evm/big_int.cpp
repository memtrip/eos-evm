#include <vector>
#include "big_int.h"
#include "types.h"

uint256_t BigInt::fromBytes(char* bytes, int len) {
  uint256_t i;
  int limbSize = sizeof(limb_type_t);
  uint32_t size;
  if (len >= limbSize) {
    size = (uint32_t) len / sizeof(limb_type_t);
  } else {
    size = len;
  }
  i.backend().resize(size, size);
  std::memcpy(i.backend().limbs(), bytes, len);
  return i;
}

void BigInt::toBytes(uint256_t& value, char* output) {
  auto count = value.backend().size();
  auto tsize = sizeof(limb_type_t);
  auto copy_count = count * tsize;
  if (len < count * tsize) return;
  std::memcpy(output, value.backend().limbs(), copy_count);
  if (len > copy_count) std::memset(output + copy_count, 0, len - copy_count);
}
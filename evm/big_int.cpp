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
  memcpy(i.backend().limbs(), bytes, len);
  return i;
}
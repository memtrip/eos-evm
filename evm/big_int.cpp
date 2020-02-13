#include "big_int.h"
#include "types.h"
#include "utils.h" 

uint256_t BigInt::fromBigEndianBytes(std::vector<uint8_t> bytes) {
  std::reverse(bytes.begin(),bytes.end()); 
  char buffer[bytes.size()];
  std::copy(bytes.begin(), bytes.end(), buffer);
  return BigInt::fromBytes(buffer, bytes.size());
}

uint256_t BigInt::fromBytes(std::vector<uint8_t> bytes) {
  char buffer[bytes.size()];
  std::copy(bytes.begin(), bytes.end(), buffer);
  return BigInt::fromBytes(buffer, bytes.size());
}

uint256_t BigInt::fromBytes(char* bytes, int len) {
  uint256_t i;
  int limbSize = sizeof(limb_type_t);
  uint32_t size;
  if (len >= limbSize) {
    size = (uint32_t) len / sizeof(limb_type_t);
  } else {
    size = 1;
  }
  i.backend().resize(size, size);
  std::memcpy(i.backend().limbs(), bytes, len);
  return i;
}

std::vector<uint8_t> BigInt::toBytes(uint256_t const& input) {
  using boost::multiprecision::cpp_int;
  std::vector<uint8_t> data;
  export_bits(input, std::back_inserter(data), 8);
  return data;
}
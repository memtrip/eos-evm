#include <evm/hex.h>

std::string Hex::bytesToHex(bytes_t& bytes) {
  std::string result;
  result.reserve(bytes.size() * 2);

  for (uint8_t c : bytes) {
    result.push_back(hex[c / 16]);
    result.push_back(hex[c % 16]);
  }

  return result;
}
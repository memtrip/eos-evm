#include "keccak_hex.h"

std::string KeccakHex::toHex256(const ethash::hash256& h)
{
  static const auto hex_chars = "0123456789abcdef";
  std::string str;
  str.reserve(sizeof(h) * 2);
  for (auto b : h.bytes)
  {
    str.push_back(hex_chars[uint8_t(b) >> 4]);
    str.push_back(hex_chars[uint8_t(b) & 0xf]);
  }
  return str;
}

std::string KeccakHex::toHex512(const ethash::hash512& h)
{
  static const auto hex_chars = "0123456789abcdef";
  std::string str;
  str.reserve(sizeof(h) * 2);
  for (auto b : h.bytes)
  {
    str.push_back(hex_chars[uint8_t(b) >> 4]);
    str.push_back(hex_chars[uint8_t(b) & 0xf]);
  }
  return str;
}
#pragma once
#include <string>
#include <evm/types.h>

class Hex {
  public:
    static std::string bytesToHex(bytes_t& bytes);
    static bytes_t hexToBytes(std::string hex);
};
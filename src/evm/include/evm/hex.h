#pragma once
#include <memory>
#include <string>
#include <evm/types.h>

class Hex {
  public:
    static std::string bytesToHex(std::shared_ptr<bytes_t> bytes);
    static std::string bytesToHex(const bytes_t& bytes);
    static bytes_t hexToBytes(const std::string& hex);
    static std::vector<int8_t> hexToSignedBytes(const std::string& hex);
};
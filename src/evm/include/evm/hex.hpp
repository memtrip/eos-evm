#pragma once
#include <memory>
#include <string>
#include <evm/types.h>

class Hex {
  public:
    static std::string bytesToHex(std::shared_ptr<bytes_t> bytes) {
      std::string result;
      for(uint8_t byte : *bytes) {
        result += HEX_VALUES[byte >> 4];
        result += HEX_VALUES[byte & 0xf];
      }
      return result;
    }

    static std::string bytesToHex(const bytes_t& bytes) {
      std::string result;
      for(uint8_t byte : bytes) {
        result += HEX_VALUES[byte >> 4];
        result += HEX_VALUES[byte & 0xf];
      }
      return result;
    }

    static bytes_t hexToBytes(const std::string& hex) {
      bytes_t bytes;
      for (unsigned int i = 0; i < hex.length(); i+=2) {
        std::string byteString = hex.substr(i, 2);
        bytes.push_back((uint8_t) strtol(byteString.c_str(), NULL, 16));
      }
      return bytes;
    }

    static std::vector<int8_t> hexToSignedBytes(const std::string& hex) {
      std::vector<int8_t> bytes;
      for (unsigned int i = 0; i < hex.length(); i+=2) {
        std::string byteString = hex.substr(i, 2);
        bytes.push_back((int8_t) strtol(byteString.c_str(), NULL, 16));
      }
      return bytes;
    }
};
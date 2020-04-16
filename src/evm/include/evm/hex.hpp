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

    static std::string fixedToHex(const std::array<uint8_t, 32>& data) {
      std::string string;
      auto bytes = data.data();
      for(int i = 0; i < 32; ++i) {
        char const byte = bytes[i];
        string += HEX_VALUES[(byte & 0xF0) >> 4];
        string += HEX_VALUES[(byte & 0x0F) >> 0];
      }
      return string;
    }

    static bytes_t hexToBytes(const std::string& hex) {
      bytes_t bytes;
      for (unsigned int i = 0; i < hex.length(); i+=2) {
        std::string byteString = hex.substr(i, 2);
        bytes.push_back((uint8_t) strtol(byteString.c_str(), NULL, 16));
      }
      return bytes;
    }

    static std::array<uint8_t, 32> hexToChecksum256(const bytes_t& bytes) {
      std::array<uint8_t, 32> checksum256;

      for (int i = 0; i < 32; i++) {
        checksum256[i] = (i >= 12) ? bytes[i - 12] : 0;
      }

      return checksum256;
    }
};
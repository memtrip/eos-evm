#pragma once
#include <memory>
#include <string>
#include <evm/types.h>
#include <evm/big_int.hpp>

class Hex {
  public:
    static std::string bytesToHex(std::shared_ptr<bytes_t> bytes) {
      std::string result;
      for (uint64_t i = 0; i < bytes->size(); i++) {
        result += HEX_VALUES[bytes->at(i) >> 4];
        result += HEX_VALUES[bytes->at(i) & 0xf];
      }
      return result;
    }

    static std::string bytesWordToHex(const bytes_t& bytes, uint64_t offset) {
      std::string result;
      for (uint16_t i = 0; i < WORD_SIZE; i++) {
        result += HEX_VALUES[bytes.at(i + offset) >> 4];
        result += HEX_VALUES[bytes.at(i + offset) & 0xf];
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
      std::string result;
      auto bytes = data.data();
      for(int i = 0; i < 32; ++i) {
        char const byte = bytes[i];
        result += HEX_VALUES[(byte & 0xF0) >> 4];
        result += HEX_VALUES[(byte & 0x0F) >> 0];
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

    static std::array<uint8_t, 32> hexToChecksum256(const bytes_t& bytes) {
      std::array<uint8_t, 32> checksum256;

      for (int i = 0; i < 32; i++) {
        checksum256[i] = (i >= 12) ? bytes[i - 12] : 0;
      }

      return checksum256;
    }

    static void padWordSize(bytes_t& bytes) {
      if (bytes.size() >= WORD_SIZE) return;
      size_t diff = WORD_SIZE - bytes.size();
      for (int i = 0; i < diff; i++) {
        bytes.insert(bytes.begin(), 0);
      }
    }

    static std::string bytesToWordOutput(const bytes_t& bytes, uint64_t offset, uint64_t size) {
      uint64_t endIndex = offset + size;
      if (size % WORD_SIZE != 0 || endIndex > bytes.size() || size == 0) return "[]";
      std::string result = "[";
      for (uint16_t i = offset; i < endIndex; i += WORD_SIZE) {
        result += bytesWordToHex(bytes, i);
        result += ",";
      }
      result.pop_back();
      result += "]";
      return result;
    }
};
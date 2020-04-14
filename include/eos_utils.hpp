#pragma once
#include <eosio/eosio.hpp>
#include <evm/types.h>
#include <evm/hex.hpp>
#include <evm/big_int.hpp>

class eos_utils {
  public:
    static std::array<uint8_t, 32> hexToChecksum256(const bytes_t& bytes) {
      std::array<uint8_t, 32> checksum256;

      for (int i = 0; i < 32; i++) {
        checksum256[i] = (i < 20) ? bytes[i] : 0;
      }

      return checksum256;
    }

    static std::pair<bytes_t, std::array<uint8_t, 32>> senderToChecksum256(const std::string& message) {
      bytes_t bytes = Hex::hexToBytes(message);
      return std::make_pair(bytes, hexToChecksum256(bytes));
    }

    static std::string fixedToHex(const eosio::fixed_bytes<32>& data) {
      std::string string;
      auto bytes = data.data();
      for(int i = 0; i < 32; ++i) {
        char const byte = bytes[i];
        string += HEX_VALUES[(byte & 0xF0) >> 4];
        string += HEX_VALUES[(byte & 0x0F) >> 0];
      }
      return string;
    }

    static bytes_t fixedToBytes(const eosio::fixed_bytes<32>& checksum256) {
      auto checksum256Bytes = checksum256.data();
      bytes_t bytes;

      for (int i = 0; i < 32; i++) {
        bytes[i] = checksum256Bytes[i];
      }

      return bytes;
    }
};
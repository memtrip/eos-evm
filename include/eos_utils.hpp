#pragma once
#include <eosio/eosio.hpp>
#include <evm/types.h>

class eos_utils {
  public:
    static std::array<uint8_t, 32> hexToFixed(bytes_t bytes) {
      std::array<uint8_t, 32> checksum256;

      for (int i = 0; i < bytes.size(); i++) {
        checksum256[i] = bytes[i];
      }

      return checksum256;
    }

    static std::array<uint8_t, 32> hexToFixed(std::string message) {
      std::vector<uint8_t> data(message.begin(), message.end());
      return hexToFixed(data);
    }

    static std::string fixedToHex(eosio::fixed_bytes<32> data) {
      std::string string;
      auto bytes = data.data();
      for(int i = 0; i < 32; ++i) {
        char const byte = bytes[i];
        string += HEX_VALUES[(byte & 0xF0) >> 4];
        string += HEX_VALUES[(byte & 0x0F) >> 0];
      }
      return string;
    }
};
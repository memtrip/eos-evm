#pragma once
#include <eosio/eosio.hpp>
#include <evm/types.h>
#include <evm/hex.hpp>
#include <evm/big_int.hpp>

class eos_utils {
  public:

    static std::pair<bytes_t, std::array<uint8_t, 32>> senderToChecksum256(const std::string& message) {
      bytes_t bytes = Hex::hexToBytes(message);
      return std::make_pair(bytes, Hex::hexToChecksum256(bytes));
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
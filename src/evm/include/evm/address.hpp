#pragma once
#include <evm/hash.hpp>
#include <evm/rlp_encode.hpp>
#include <evm/hex.hpp>
#include <evm/types.h>

class Address {
  public:
    static bytes_t accountIdentifierFromString(const std::string& accountName, const std::string& addressString) {
      bytes_t address = Hex::hexToBytes(addressString.substr(2, addressString.size()));
      return accountIdentifierFromBytes(accountName, address);
    }

    static bytes_t accountIdentifierFromBytes(const std::string& accountName, const bytes_t& address) {
      bytes_t accountNameBytes(accountName.begin(), accountName.end());

      RLPItem accountNameItem {
        RLPType::STRING,
        accountNameBytes,
        std::vector<RLPItem> {}
      };

      RLPItem addressItem {
        RLPType::STRING,
        address,
        std::vector<RLPItem> {}
      };

      RLPItem accountNameAddressList {
        RLPType::LIST,
        bytes_t {},
        std::vector<RLPItem> { accountNameItem, addressItem }
      };

      bytes_t result = RLPEncode::encode(accountNameAddressList);

      bytes_t hashBytes = Hash::keccak256(result);

      bytes_t accountIdentifierBytes(hashBytes.end() - ADDRESS_SIZE, hashBytes.end());

      return accountIdentifierBytes;
    }

    static bytes_t ethereumAddress(const bytes_t& uncompressedPubKey) {
      bytes_t hash = Hash::keccak256(uncompressedPubKey);

      std::vector<uint8_t> address;

      for (int i = hash.size() - 20; i < hash.size(); i++) {
        address.push_back(hash[i]);
      }

      return address;
    }
};
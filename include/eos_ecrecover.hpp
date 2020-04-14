#pragma once
#include <eosio/system.hpp>
#include <eosio/fixed_bytes.hpp>
#include <eosio/crypto.hpp>

#include <evm/types.h>
#include <evm/hash.hpp>
#include <evm/address.hpp>
#include <evm/hex.hpp>
#include <evm/transaction.hpp>
#include <evm/decompress_key.hpp>

class eos_ecrecover {
  public:
    static bytes_t recover(std::string accountName, std::shared_ptr<std::vector<RLPItem>> rlp) {

      bytes_t digest = Transaction::digest(rlp, 0x01);
      std::array<uint8_t, 32> digestData;
      for (int i = 0; i < digest.size(); i++) {
        digestData[i] = digest[i];
      }
      eosio::fixed_bytes<32> digestBytes(digestData);

      bytes_t signature = Transaction::signature(rlp);
      std::array<char, 65> signatureData;
      for (int i = 0; i < signature.size(); i++) {
        signatureData[i] = signature[i];
      }
      eosio::signature signatureBytes(std::in_place_index<0>, signatureData);

      std::array<char, 33> compressedPubKey = std::get<0>(eosio::recover_key(digestBytes, signatureBytes));
      uint256_t p = DecompressKey::p();
      bytes_t uncompressedPubKey = DecompressKey::decompress(p, compressedPubKey);
      bytes_t ethereumAddress = Address::ethereumAddress(uncompressedPubKey);

      return Address::accountIdentifierFromBytes(
        accountName, 
        ethereumAddress
      );
    }
};
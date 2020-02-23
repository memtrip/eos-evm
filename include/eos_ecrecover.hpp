#pragma once
#include <eosio/system.hpp>
#include <eosio/fixed_bytes.hpp>
#include <eosio/crypto.hpp>

#include <evm/types.h>
#include <evm/hash.h>
#include <evm/address.h>
#include <evm/hex.h>
#include <evm/transaction.h>
#include <evm/decompress_key.h>

class eos_ecrecover {
  public:
    static bytes_t recover(std::string accountName, bytes_t digest, bytes_t signature) {

      std::array<uint8_t, 32> digestData;

      for (int i = 0; i < digest.size(); i++) {
        digestData[i] = digest[i];
      }

      eosio::fixed_bytes<32> digestBytes(digestData);

      // signature
      std::array<char, 65> signatureData;

      for (int i = 0; i < signature.size(); i++) {
        signatureData[i] = signature[i];
      }

      eosio::signature sig(std::in_place_index<0>, signatureData);

      // recover public key
      std::array<char, 33> compressedPubKey = std::get<0>(eosio::recover_key(digestBytes, sig));

      bytes_t uncompressedPubKey = DecompressKey::decompress(compressedPubKey);

      bytes_t ethereumAddress = Address::ethereumAddress(uncompressedPubKey);

      return Address::accountIdentifierFromBytes(
        accountName, 
        ethereumAddress
      );
    }
};
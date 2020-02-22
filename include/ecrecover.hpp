#pragma once
#include <eosio/system.hpp>
#include <eosio/transaction.hpp>
#include <eosio/fixed_bytes.hpp>
#include <eosio/crypto.hpp>

#include <evm/types.h>
#include <evm/hash.h>
#include <evm/address.h>

class ecrecover {
  public:
    static string recover(std::string accountName, bytes_t digest, bytes_t signature) {

      // digest
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
      std::array<char, 33> pub = std::get<0>(eosio::recover_key(digestBytes, sig));

      // convert the public key char items to uint8_t items for keccak hash
      std::array<uint8_t, 33> unsignedPub;

      for (int i = 0; i < pub.size(); i++) {
        unsignedPub[i] = (uint8_t) pub[i];
      }

      bytes_t hash = Hash::keccak256(unsignedPub);

      bytes_t hashEnd = bytes_t(hash.end() - 20, hash.end());

      return Address::createFromBytes(
        accountName, 
        hashEnd
      );
    }
};
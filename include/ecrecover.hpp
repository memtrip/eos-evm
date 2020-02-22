#pragma once
#include <eosio/system.hpp>
#include <eosio/transaction.hpp>
#include <eosio/fixed_bytes.hpp>
#include <eosio/crypto.hpp>

#include <evm/types.h>

class ecrecover {
  public:
    static string recover(bytes_t digest, bytes_t signature) {

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
      
      std::string v((uint8_t) signatureData[0]);

      eosio::check(1 != 1, "v: " + v);

      eosio::public_key pub = eosio::recover_key(digestBytes, sig);

      return "d1c81da825345ebe56e5d49107d10cd0738036ec";
    }
};
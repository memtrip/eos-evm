#pragma once
#include <eosio/system.hpp>
#include <eosio/fixed_bytes.hpp>
#include <eosio/crypto.hpp>

#include <evm/types.h>
#include <evm/hash.h>
#include <evm/address.h>
#include <evm/hex.h>
#include <evm/transaction.h>

class ecrecover {
  public:
    static string recover(std::string accountName, bytes_t digest, bytes_t signature) {

      // digest
      // bytes_t digestWithPrefix = Transaction::prefixedBytes(digest);

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
      std::vector<uint8_t> publicKeyBytes;

      for (int i = 0; i < pub.size(); i++) {
        publicKeyBytes.push_back((uint8_t) pub[i]);
      }

      bytes_t hash = Hash::keccak256(publicKeyBytes);

      // last 20 bytes of the hash
      // std::vector<uint8_t> address;

      // for (int i = hash.size() - 20 - 1; i < hash.size(); i++) {
      //   address.push_back(hash[i]);
      // }

      // bytes_t hashEnd = bytes_t(hash.end() - 20, hash.end());

      // 037e7d763719127cf96fb8f1f6f68b12fca179487a8907b2bd4155870ad3e62119

      return Hex::bytesToHex(hash);
    }
};
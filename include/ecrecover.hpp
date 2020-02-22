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
      std::array<char, 33> compressedPubKey = std::get<0>(eosio::recover_key(digestBytes, sig));

      bytes_t uncompressedPubKey = Hex::hexToBytes("630f70ad9f6e943088a4677e9ccf132cb2ae8bafd4a1538b42cd78454e037730c6e09149f4bae8e136794e950a072368a0a3926083017d8b7b6c20d3f8a6f2e6");

      bytes_t ethereumAddress = Address::ethereumAddress(uncompressedPubKey);

      return Hex::fixedToHex(compressedPubKey) + " - " + Hex::bytesToHex(ethereumAddress);
    }
};
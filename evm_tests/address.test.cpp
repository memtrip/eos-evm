#include "catch.hpp"
#include <evm/address.h>
#include "utils.h"
#include <evm/hex.h>

TEST_CASE("createFromString", "[address]" ) {

  std::string accountIdentifier = Address::createFromString(
    "evm5", 
    "8d7332e9640fe8952e436dda2d5c2ac93d6870f3"
  );

  CHECK(40 == accountIdentifier.length());
  CHECK("86a2700da1f451fa70a0dd52225f986d552eda0f" == 
    accountIdentifier
  );
}

TEST_CASE("createFromBytes", "[address]" ) {

  std::string accountIdentifier = Address::createFromBytes(
    "evm5", 
    Hex::hexToBytes("8d7332e9640fe8952e436dda2d5c2ac93d6870f3")
  );

  CHECK(40 == accountIdentifier.length());
  CHECK("86a2700da1f451fa70a0dd52225f986d552eda0f" == 
    accountIdentifier
  );
}

TEST_CASE("Uncompressed public key", "[address]" ) {

  bytes_t address = Address::ethereumAddress(
    Hex::hexToBytes("630f70ad9f6e943088a4677e9ccf132cb2ae8bafd4a1538b42cd78454e037730c6e09149f4bae8e136794e950a072368a0a3926083017d8b7b6c20d3f8a6f2e6")
  );

  CHECK("7a5470ca3884388f8a284ac0c63eaf0695a200ea" == 
    Hex::bytesToHex(address)
  );
}
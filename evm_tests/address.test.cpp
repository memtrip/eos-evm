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
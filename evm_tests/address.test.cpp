#include "catch.hpp"
#include <evm/address.h>
#include "utils.h"

TEST_CASE("Create accountIdentifier", "[address]" ) {

  std::string accountIdentifier = Address::createAccountIdentifier("eosio", "An arbitrary length string");

  CHECK(40 == accountIdentifier.length());
  CHECK("e432070b2193e81d086a3b1c4234f4b3c0dba3af" == 
    accountIdentifier
  );
}

TEST_CASE("Create accountIdentifier (1)", "[address]" ) {

  std::string accountIdentifier = Address::createAccountIdentifier("samkirton", "What is this salt up to then?");

  CHECK(40 == accountIdentifier.length());
  CHECK("8d7332e9640fe8952e436dda2d5c2ac93d6870f3" == 
    accountIdentifier
  );
}

TEST_CASE("Create accountIdentifier (2)", "[address]" ) {

  std::string accountIdentifier = Address::createAccountIdentifier("skream", "Essential Mix – Radio 1 – 17.06.2007");

  CHECK(40 == accountIdentifier.length());
  CHECK("41dba7d0bfd0f623d2a2d0524c11e9878a8ea06e" == 
    accountIdentifier
  );
}

TEST_CASE("Create accountIdentifier (3)", "[address]" ) {

  std::string accountIdentifier = Address::createAccountIdentifier("evm5", "0x0dfef8b14c0aa5db1daa1853fe191d0415fe70dd");

  CHECK(40 == accountIdentifier.length());
  CHECK("d1c81da825345ebe56e5d49107d10cd0738036ec" == 
    accountIdentifier
  );
}
#include <stdio.h>
#include "catch.hpp"
#include "jumps.h"
#include "types.h"
#include "utils.h"

jump_set_t jump_destinations(std::string bytecode_str) {
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  return Jumps::findDestinations(bytecode_array, sizeof(bytecode_array));
}

TEST_CASE("Find jump distinations", "[findDestinations]") {
  // given
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff5b01600055";
  
  // when
  jump_set_t jumps = jump_destinations(bytecode_str);

  // then
  for (jump_set_t::iterator it=jumps.begin(); it!=jumps.end(); ++it)
    REQUIRE(66 == *it); 
}


TEST_CASE("Verify jumps", "[verifyJump]") {
  // given
  jump_set_t jumps = jump_set_t();
  jumps.insert(2);
  jumps.insert(5);
  jumps.insert(10);

  // then
  REQUIRE(5 == Jumps::verifyJump(uint256_t(5), jumps)); 
  REQUIRE(2 == Jumps::verifyJump(uint256_t(2), jumps)); 
  REQUIRE(10 == Jumps::verifyJump(uint256_t(10), jumps)); 
  REQUIRE(INVALID_ARGUMENT == Jumps::verifyJump(3, jumps)); 
  REQUIRE(INVALID_ARGUMENT == Jumps::verifyJump(Utils::bigIntFromBytes("FFFFFFFFFFFFFFFFFFFFF"), jumps)); 
}

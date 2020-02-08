#include <stdio.h>
#include "catch.hpp"
#include "jumps.h"
#include "types.h"
#include "utils.h"

jump_set_t jump_destinations(std::string bytecode_str) {
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  return Jumps::find_destinations(bytecode_array, sizeof(bytecode_array));
}

TEST_CASE("Find jump distinations", "[find_destinations]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff5b01600055";
  jump_set_t jumps = jump_destinations(bytecode_str);

  for (jump_set_t::iterator it=jumps.begin(); it!=jumps.end(); ++it)
    REQUIRE(66 == *it); 
}
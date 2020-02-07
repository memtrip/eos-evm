#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "jumps.h"
#include "utils.h"

TEST_CASE("Find distinations", "[find_destinations]" ) {
  std::string bytecode_str = "01020304";
  char bytecode_array[bytecode_str.length() / 2];
  hex2bin(bytecode_str, bytecode_array);
  Jumps::find_destinations(bytecode_array, sizeof(bytecode_array));
}
#include <stdio.h>
#include "catch.hpp"
#include "byte_reader.h"
#include "types.h"
#include "utils.h"

TEST_CASE("Byte Reader read(32)", "[read(32)]" ) {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01600055";
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  ByteReader byteReader(1, bytecode_array, sizeof(bytecode_array));
  uint256_t item = byteReader.read(32);
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" == 
    Utils::uint256_2str(item)
  );
}

TEST_CASE("Byte Reader read(1)", "[read(1)]" ) {
  std::string bytecode_str = "6001";
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  ByteReader byteReader(1, bytecode_array, sizeof(bytecode_array));
  uint256_t item = byteReader.read(1);
  CHECK("1" == 
    Utils::uint256_2str(item)
  );
}
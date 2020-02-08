#include <stdio.h>
#include "catch.hpp"
#include "big_int.h"
#include "types.h"
#include "utils.h"

/**
  These tests assume little-endian byte ordering
*/
uint256_t bigIntFromBytes(std::string bytecode_str) {
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  return BigInt::fromBytes(bytecode_array, sizeof(bytecode_array));
}

TEST_CASE("Instantiate uint256_t from char *", "[fromBytes]") {
  CHECK("1" == 
    Utils::uint256_2str(bigIntFromBytes("0100000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("1" == 
    Utils::uint256_2str(bigIntFromBytes("0100000000000000"))
  );
  CHECK("1" == 
    Utils::uint256_2str(bigIntFromBytes("01"))
  );
  CHECK("a" == 
    Utils::uint256_2str(bigIntFromBytes("0A00000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("a" == 
    Utils::uint256_2str(bigIntFromBytes("0A00000000000000"))
  );
  CHECK("10" == 
    Utils::uint256_2str(bigIntFromBytes("1000000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("10" == 
    Utils::uint256_2str(bigIntFromBytes("10"))
  );
  CHECK("faffffffffffffffffffffffffffffff" == 
    Utils::uint256_2str(bigIntFromBytes("fffffffffffffffffffffffffffffffA"))
  );
  CHECK("fa" == 
    Utils::uint256_2str(bigIntFromBytes("fA"))
  );
  CHECK("ff" == 
    Utils::uint256_2str(bigIntFromBytes("ff"))
  );
}
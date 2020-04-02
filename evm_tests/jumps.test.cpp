#include "catch.hpp"
#include <memory>
#include <evm/jumps.h>
#include <evm/types.h>
#include <evm/hex.h>
#include <evm/utils.h>

jump_set_t jump_destinations(std::string bytecode_str) {
  bytes_t bytes = Hex::hexToBytes(bytecode_str);
  return Jumps::findDestinations(std::make_shared<bytes_t>(bytes));
}

TEST_CASE("Find jump distinations", "[jumps]") {
  // given
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff5b01600055";
  
  // when
  jump_set_t jumps = jump_destinations(bytecode_str);

  // then
  for (jump_set_t::iterator it=jumps.begin(); it!=jumps.end(); ++it)
    REQUIRE(66 == *it); 
}

TEST_CASE("Verify jumps", "[jumps]") {
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
  REQUIRE(INVALID_ARGUMENT == Jumps::verifyJump(Utils::bigIntFromBigEndianBytes("FFFFFFFFFFFFFFFFFFFFF"), jumps)); 
}

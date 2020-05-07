#include "catch.hpp"
#include <vector>
#include <memory>
#include <evm/jumps.hpp>
#include <evm/types.h>
#include <evm/hex.hpp>
#include <evm/utils.hpp>

std::vector<uint64_t> jump_destinations(std::string bytecode_str) {
  std::vector<uint64_t> output;
  bytes_t bytes = Hex::hexToBytes(bytecode_str);
  jump_set_t destinations = Jumps::findDestinations(std::make_shared<bytes_t>(bytes));
  std::copy(destinations.begin(), destinations.end(), std::back_inserter(output));
  return output;
}

TEST_CASE("Find jump distinations", "[jumps]") {
  // given
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff5b01600055";
  
  // when
  std::vector<uint64_t> jumps = jump_destinations(bytecode_str);

  // then
  REQUIRE(66 == jumps[0]); 
}

TEST_CASE("Find jump distinations in COPYCODE contract", "[jumps]") {
  // given
  std::string bytecode_str = "608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390a160b8806100826000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a723158209551755b4e59ca6cf78d79f5356d91565950805937074458700610f23c6ecf9b64736f6c63430005100032";
  
  // when
  std::vector<uint64_t> jumps = jump_destinations(bytecode_str);

  // then
  REQUIRE(7 == jumps.size()); 
  REQUIRE(16 == jumps[0]); 
  REQUIRE(145 == jumps[1]); 
  REQUIRE(170 == jumps[2]); 
  REQUIRE(175 == jumps[3]); 
  REQUIRE(195 == jumps[4]); 
  REQUIRE(226 == jumps[5]); 
  REQUIRE(248 == jumps[6]); 
}

TEST_CASE("Verify jumps", "[jumps]") {
  // given
  jump_set_t jumps = jump_set_t();
  jumps.insert(2);
  jumps.insert(5);
  jumps.insert(10);

  // then
  REQUIRE(5 == Jumps::verifyJump(5, jumps)); 
  REQUIRE(2 == Jumps::verifyJump(2, jumps)); 
  REQUIRE(10 == Jumps::verifyJump(10, jumps)); 
  REQUIRE(INVALID_ARGUMENT == Jumps::verifyJump(3, jumps)); 
  REQUIRE(INVALID_ARGUMENT == Jumps::verifyJump(0xFFFFFFFF, jumps)); 
}

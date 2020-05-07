#include <climits>
#include "catch.hpp"
#include <memory>
#include <evm/overflow.hpp>
#include <evm/utils.hpp>

TEST_CASE("Overflow add", "[overflow]") {
  std::pair<unsigned int, bool> result = Overflow::add(1, UINT_MAX);
  REQUIRE(true == result.second); 
}

TEST_CASE("Add without overflow", "[overflow]") {
  std::pair<unsigned int, bool> result = Overflow::add(1, UINT_MAX - 1);
  REQUIRE(4294967295 == result.first); 
  REQUIRE(false == result.second); 
}

TEST_CASE("Calculate largest wei number", "[overflow]") {
  uint256_t result = std::numeric_limits<uint64_t>::max() * uint256_t(0xDE0B6B3A7640000);
  REQUIRE("000000000000000000000000000000000de0b6b3a763fffff21f494c589c0000" == 
    Utils::uint256_2str(result)
  );
}

TEST_CASE("Max balance", "[overflow]") {
  uint256_t maxBalance = Utils::bigIntFromBigEndianBytes("000000000000000000000000000000000de0b6b3a763fffff21f494c589c0000");
  uint256_t result = maxBalance / std::numeric_limits<uint64_t>::max();
  REQUIRE(Utils::uint256_2str(uint256_t(0xDE0B6B3A7640000)) == 
    Utils::uint256_2str(result)
  );
}
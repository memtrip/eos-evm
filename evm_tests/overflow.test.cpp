#include <climits>
#include "catch.hpp"
#include <memory>
#include <evm/overflow.hpp>

TEST_CASE("Overflow add", "[overflow]") {
  std::pair<unsigned int, bool> result = Overflow::add(1, UINT_MAX);
  REQUIRE(true == result.second); 
}

TEST_CASE("Add without overflow", "[overflow]") {
  std::pair<unsigned int, bool> result = Overflow::add(1, UINT_MAX - 1);
  REQUIRE(4294967295 == result.first); 
  REQUIRE(false == result.second); 
}
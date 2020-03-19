#include "catch.hpp"
#include <evm/types.h>
#include <evm/stack.h>
#include <evm/utils.h>

TEST_CASE("pop", "[stack]") {
  // given 
  StackMachine sm {};
  sm.push(1);

  // when
  sm.pop(1);

  // then
  REQUIRE(0 == sm.size()); 
}

TEST_CASE("peek", "[stack]") {
  // given 
  StackMachine sm {};

  // when
  sm.push(uint256_t(1));

  // then
  REQUIRE(1 == sm.peek(0)); 
}

TEST_CASE("peekMany", "[stack]") {
  // given 
  StackMachine sm {};

  // when
  sm.push(uint256_t(5));
  sm.push(uint256_t(4));
  sm.push(uint256_t(3));
  sm.push(uint256_t(2));
  sm.push(uint256_t(1));
  sm.push(uint256_t(0));

  std::vector<uint256_t> items = sm.peekMany(2, 4);

  // then
  REQUIRE("0000000000000000000000000000000000000000000000000000000000000002" == 
    Utils::uint256_2str(items[0])
  );
  REQUIRE("0000000000000000000000000000000000000000000000000000000000000003" == 
    Utils::uint256_2str(items[1])
  );
  REQUIRE("0000000000000000000000000000000000000000000000000000000000000004" == 
    Utils::uint256_2str(items[2])
  );
  REQUIRE("0000000000000000000000000000000000000000000000000000000000000005" == 
    Utils::uint256_2str(items[3])
  );
}
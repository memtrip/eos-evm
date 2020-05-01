#include "catch.hpp"
#include <memory>
#include <evm/types.h>
#include <evm/stack.hpp>
#include <evm/utils.hpp>

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
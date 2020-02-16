#include "catch.hpp"
#include <evm/types.h>
#include <evm/stack.h>

TEST_CASE("Stack pop", "[pop(1)]") {
  // given 
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);
  sm.push(1);

  // when
  sm.pop(1);

  // then
  REQUIRE(0 == stackItems->size()); 
}

TEST_CASE("Stack peek", "[pop(1)]") {
  // given 
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  sm.push(uint256_t(1));

  // then
  REQUIRE(1 == sm.peek(0)); 
}
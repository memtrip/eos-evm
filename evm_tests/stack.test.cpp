#include "catch.hpp"
#include <memory>
#include <evm/types.h>
#include <evm/stack.h>
#include <evm/utils.h>

TEST_CASE("pop", "[stack]") {

  // given 
  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  StackMachine sm(stackItems);

  sm.push(1);

  // when
  sm.pop(1);

  // then
  REQUIRE(0 == sm.size()); 
}

TEST_CASE("peek", "[stack]") {

  // given 
  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  StackMachine sm(stackItems);

  // when
  sm.push(uint256_t(1));

  // then
  REQUIRE(1 == sm.peek(0)); 
}
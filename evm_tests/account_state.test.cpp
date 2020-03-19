#include "catch.hpp"
#include <evm/types.h>
#include <evm/account_state.h>
#include <evm/stack.h>
#include <evm/utils.h>
#include "external_mock.h"

TEST_CASE("Put pair", "[account_state]") {
  // given 
  std::vector<uint256_t> stackItems = std::vector<uint256_t>();
  stackItems.push_back(uint256_t(2));
  stackItems.push_back(uint256_t(1));

  ExternalMock ext {};
  AccountState accountState(&ext);

  // when
  accountState.putTopPair(stackItems);

  // then
  CHECK(uint256_t(2) == accountState.get(0x01));
}

TEST_CASE("Get by index", "[account_state]") {
  // given 
  std::vector<uint256_t> stackItems = std::vector<uint256_t>();
  stackItems.push_back(uint256_t(4));
  stackItems.push_back(uint256_t(3));

  ExternalMock ext {};
  AccountState accountState(&ext);

  // when
  accountState.putTopPair(stackItems);

  // then
  CHECK(uint256_t(4) == accountState.get(uint256_t(3)));
  CHECK(uint256_t() == accountState.get(uint256_t(8)));
}
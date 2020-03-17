#include "catch.hpp"
#include <evm/types.h>
#include <evm/account_state.h>
#include <evm/stack.h>
#include <evm/utils.h>
#include "external_mock.h"

TEST_CASE("Put pair", "[account_state]") {
  // given 
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  stackItems->push_back(uint256_t(2));
  stackItems->push_back(uint256_t(1));

  ExternalMock ext {};
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);

  // when
  accountState.putTopPair(stackItems);

  // then
  store_item_t item = Utils::accountStoreValue(0, accountItems);
  CHECK(uint256_t(1) == item.first);
  CHECK(uint256_t(2) == item.second);
}

TEST_CASE("Get by index", "[account_state]") {
  // given 
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  stackItems->push_back(uint256_t(4));
  stackItems->push_back(uint256_t(3));

  ExternalMock ext {};
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);

  // when
  accountState.putTopPair(stackItems);

  // then
  CHECK(uint256_t(4) == accountState.get(uint256_t(3)));
  CHECK(uint256_t() == accountState.get(uint256_t(8)));
}
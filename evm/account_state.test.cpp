#include "catch.hpp"
#include "types.h"
#include "account_state.h"
#include "utils.h"
#include "stack.h"


TEST_CASE("Put pair", "[account_state]") {
  // given 
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  stackItems->push_back(uint256_t(2));
  stackItems->push_back(uint256_t(1));

  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);

  // when
  accountState.putTopPair(stackItems);

  // then
  store_item_t item = Utils::accountStoreValue(0, accountItems);
  CHECK(uint256_t(1) == item.first);
  CHECK(uint256_t(2) == item.second);
}
#include "catch.hpp"
#include "types.h"
#include "account_state.h"
#include "utils.h"
#include "stack.h"

TEST_CASE("Put pair", "[pop(1)]") {
  // given 
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  stackItems->push_back(uint256_t(1));
  stackItems->push_back(uint256_t(2));

  std::map<uint256_t, uint256_t>* accountItems = new std::map<uint256_t,uint256_t>();
  AccountState accountState(accountItems);

  // when
  accountState.putTopPair(stackItems);

  // then
  // CHECK(uint256_t(2) == 
  //   Utils::accountStoreValue(uint256_t(1), accountItems)
  // );
}
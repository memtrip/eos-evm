#include "catch.hpp"
#include <memory>
#include <evm/types.h>
#include <evm/account_state.h>
#include <evm/stack.h>
#include <evm/utils.h>
#include "external_mock.h"

TEST_CASE("Put pair", "[account_state]") {
  // given 
  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  // when
  uint256_t codeAddress = uint256_t(0xFF);
  accountState->put(uint256_t(1), uint256_t(2), codeAddress);

  // then
  CHECK(uint256_t(2) == accountState->get(0x01, codeAddress));
}

TEST_CASE("Get by index", "[account_state]") {
  // given 
  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  // when
  uint256_t codeAddress = uint256_t(0xFF);
  accountState->put(uint256_t(3), uint256_t(4), codeAddress);

  // then
  CHECK(uint256_t(4) == accountState->get(uint256_t(3), codeAddress));
  CHECK(uint256_t() == accountState->get(uint256_t(8), codeAddress));
}
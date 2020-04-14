#include "catch.hpp"
#include <memory>
#include <evm/types.h>
#include <evm/account_state.hpp>
#include <evm/stack.hpp>
#include <evm/utils.h>
#include "external_mock.h"

TEST_CASE("Put pair", "[account_state]") {
  // given 
  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);

  // when
  uint256_t key = uint256_t(1);
  uint256_t value = uint256_t(2);
  uint256_t codeAddress = uint256_t(0xFF);
  accountState->put(external, key, value, codeAddress);

  // then
  CHECK(uint256_t(2) == accountState->get(external, 0x01, codeAddress));
}

TEST_CASE("Get by index", "[account_state]") {
  // given 
  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);

  // when
  uint256_t key = uint256_t(3);
  uint256_t value = uint256_t(4);
  uint256_t codeAddress = uint256_t(0xFF);
  accountState->put(external, key, value, codeAddress);

  // then
  CHECK(uint256_t(4) == accountState->get(external, uint256_t(3), codeAddress));
  CHECK(uint256_t() == accountState->get(external, uint256_t(8), codeAddress));
}
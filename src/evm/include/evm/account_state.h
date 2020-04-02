#pragma once
#include <memory>
#include <vector>
#include <evm/types.h>
#include <evm/external.h>

class AccountState {
  public:
    explicit AccountState(std::shared_ptr<External> e, const account_store_t& c = account_store_t()): cacheItems(c) {
      external = e;
    };
    std::shared_ptr<External> external;
    account_store_t cacheItems;
    void put(uint256_t key, uint256_t value);
    uint256_t get(uint256_t key);
    int exists(uint256_t key);
};
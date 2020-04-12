#pragma once
#include <memory>
#include <vector>
#include <evm/types.h>
#include <evm/external.h>

struct StoreItem {
  uint256_t key;
  uint256_t value;
  uint256_t codeAddress;
};

typedef StoreItem store_item_t;
typedef std::vector<store_item_t> account_store_t;

class AccountState {
  public:
    AccountState(std::shared_ptr<External> externalArg, std::shared_ptr<account_store_t> cacheItemsArg) {
      external = externalArg;
      cacheItems = cacheItemsArg;
    };
    std::shared_ptr<External> external;
    std::shared_ptr<account_store_t> cacheItems;
    void put(const uint256_t& key, const uint256_t& value, const uint256_t& codeAddress);
    uint256_t get(const uint256_t& key, const uint256_t& codeAddress);
    int exists(uint256_t key, uint256_t codeAddress);
};
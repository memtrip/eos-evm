#pragma once
#include <memory>
#include <vector>
#include <evm/types.h>
#include <evm/external.h>
#include <evm/big_int.hpp>

struct StoreItem {
  uint256_t key;
  uint256_t value;
  uint256_t codeAddress;
};

typedef StoreItem store_item_t;
typedef std::vector<store_item_t> account_store_t;

class AccountState {
  public:

    std::shared_ptr<account_store_t> cacheItems;

    AccountState(std::shared_ptr<account_store_t> cacheItemsArg) {
      cacheItems = cacheItemsArg;
    };

    void put(std::shared_ptr<External> external, const uint256_t& key, const uint256_t& value, const uint256_t& codeAddress) {
      int existingIndex = exists(external, key, codeAddress);
      store_item_t item {
        key,
        value,
        codeAddress
      };
      if (existingIndex == -1) {
        cacheItems->push_back(item);
      } else {
        cacheItems->at(existingIndex) = item;
      }
    }

    uint256_t get(std::shared_ptr<External> external, const uint256_t& key, const uint256_t& codeAddress) {
      for (int i = 0; i < cacheItems->size(); i++) {
        if (key == cacheItems->at(i).key && codeAddress == cacheItems->at(i).codeAddress)
          return cacheItems->at(i).value;
      }
      bytes_t bytes = external->storageAt(key, codeAddress);
      return BigInt::fromBigEndianBytes(bytes);
    }
    
    int exists(std::shared_ptr<External> external, uint256_t key, uint256_t codeAddress) {
      for (int i = 0; i < cacheItems->size(); i++) {
        if (key == cacheItems->at(i).key && codeAddress == cacheItems->at(i).codeAddress)
          return i;
      }
      return -1;
    }
};
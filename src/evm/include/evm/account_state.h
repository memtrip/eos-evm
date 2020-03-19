#pragma once
#include <vector>
#include <evm/types.h>
#include <evm/external.h>

class AccountState {
  public:
    AccountState(External* externalArg);
    account_store_t cacheItems;
    External* external;
    void putTopPair(std::vector<uint256_t>& stackItems);
    uint256_t get(uint256_t key);
    int exists(uint256_t key);
};
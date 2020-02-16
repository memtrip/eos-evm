#include <vector>
#include <evm/types.h>

class AccountState {
  public:
    AccountState(account_store_t* itemsArg);
    account_store_t* items;
    void putTopPair(std::vector<uint256_t>* stackItems);
};
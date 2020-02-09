#include <map>
#include <vector>
#include "types.h"

class AccountState {
  public:
    AccountState(std::map<uint256_t, uint256_t>* itemsArg);
    std::map<uint256_t, uint256_t>* items;
    void putTopPair(std::vector<uint256_t>* stackItems);
};
#include <map>
#include "types.h"

class AccountState {
  public:
    void set(uint256_t key, uint256_t value);
    std::map<uint256_t, uint256_t> items;
};
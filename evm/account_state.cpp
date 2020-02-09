#include "account_state.h"

void AccountState::set(uint256_t key, uint256_t value) {
  items.insert(std::pair<uint256_t,uint256_t>(key, value));
}
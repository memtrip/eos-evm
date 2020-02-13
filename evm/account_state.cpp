#include <utility>
#include "account_state.h"

AccountState::AccountState(account_store_t* itemsArg) {
  items = itemsArg;
}

void AccountState::putTopPair(std::vector<uint256_t>* stackItems) {
  std::vector<uint256_t> newVec = std::vector<uint256_t>(stackItems->end() - 2, stackItems->end() - 1);
  items->push_back(std::make_pair(newVec[0], newVec[1]));
}
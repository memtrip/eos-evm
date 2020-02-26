#include <utility>
#include <evm/account_state.h>

AccountState::AccountState(account_store_t* itemsArg) {
  items = itemsArg;
}

void AccountState::putTopPair(std::vector<uint256_t>* stackItems) {
  uint256_t index = stackItems->at(stackItems->size() - 1);
  uint256_t value = stackItems->at(stackItems->size() - 2);
  items->push_back(std::make_pair(index, value));
}

uint256_t AccountState::get(uint256_t key) {
  for (int i = 0; i < items->size(); i++) {
    if (key == items->at(i).first)
      return items->at(i).second;
  }
  return uint256_t();
}
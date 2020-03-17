#include <utility>
#include <evm/account_state.h>
#include <evm/big_int.h>

AccountState::AccountState(account_store_t* itemsArg, External* externalArg) {
  cacheItems = itemsArg;
  external = externalArg;
}

void AccountState::putTopPair(std::vector<uint256_t>* stackItems) {
  uint256_t key = stackItems->at(stackItems->size() - 1);
  uint256_t value = stackItems->at(stackItems->size() - 2);
  int existingIndex = exists(key);
  if (existingIndex == -1) {
    cacheItems->push_back(std::make_pair(key, value));
  } else {
    cacheItems->at(existingIndex) = std::make_pair(key, value);
  }
}

uint256_t AccountState::get(uint256_t key) {

  for (int i = 0; i < cacheItems->size(); i++) {
    if (key == cacheItems->at(i).first)
      return cacheItems->at(i).second;
  }
  return BigInt::fromBigEndianBytes(external->storageAt(key));
}

int AccountState::exists(uint256_t key) {
  for (int i = 0; i < cacheItems->size(); i++) {
    if (key == cacheItems->at(i).first)
      return i;
  }
  return -1;
}
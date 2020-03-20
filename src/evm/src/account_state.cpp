#include <utility>
#include <evm/account_state.h>
#include <evm/big_int.h>

void AccountState::put(uint256_t key, uint256_t value) {
  int existingIndex = exists(key);
  if (existingIndex == -1) {
    cacheItems.push_back(std::make_pair(key, value));
  } else {
    cacheItems.at(existingIndex) = std::make_pair(key, value);
  }
}

uint256_t AccountState::get(uint256_t key) {

  for (int i = 0; i < cacheItems.size(); i++) {
    if (key == cacheItems.at(i).first)
      return cacheItems.at(i).second;
  }

  bytes_t bytes = external->storageAt(key);
  return BigInt::fromBigEndianBytes(bytes);
}

int AccountState::exists(uint256_t key) {
  for (int i = 0; i < cacheItems.size(); i++) {
    if (key == cacheItems.at(i).first)
      return i;
  }
  return -1;
}
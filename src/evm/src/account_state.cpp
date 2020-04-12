#include <utility>
#include <evm/account_state.h>
#include <evm/big_int.h>

void AccountState::put(const uint256_t& key, const uint256_t& value, const uint256_t& codeAddress) {
  int existingIndex = exists(key, codeAddress);
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

uint256_t AccountState::get(const uint256_t& key, const uint256_t& codeAddress) {
  for (int i = 0; i < cacheItems->size(); i++) {
    if (key == cacheItems->at(i).key && codeAddress == cacheItems->at(i).codeAddress)
      return cacheItems->at(i).value;
  }
  bytes_t bytes = external->storageAt(key, codeAddress);
  return BigInt::fromBigEndianBytes(bytes);
}

int AccountState::exists(uint256_t key, uint256_t codeAddress) {
  for (int i = 0; i < cacheItems->size(); i++) {
    if (key == cacheItems->at(i).key && codeAddress == cacheItems->at(i).codeAddress)
      return i;
  }
  return -1;
}
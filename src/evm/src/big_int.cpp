#include <evm/big_int.h>
#include <evm/types.h>

uint256_t BigInt::fromBigEndianBytes(bytes_t bytes) {
  uint8_t data[WORD_SIZE];
  uint8_t offset = WORD_SIZE - bytes.size();
  std::fill_n(data, WORD_SIZE, 0);
  std::copy(bytes.begin(), bytes.end(), data + offset);
  return intx::be::load<uint256_t>(data);
}

uint256_t BigInt::fromBytes(bytes_t bytes) {
  uint8_t data[WORD_SIZE];
  uint8_t offset = WORD_SIZE - bytes.size();
  std::fill_n(data, WORD_SIZE, 0);
  std::copy(bytes.begin(), bytes.end(), data + offset);
  return intx::le::load<uint256_t>(data);
}

uint256_t BigInt::fromCompressedKey(compressed_key_t compressedKey) {
  uint8_t data[WORD_SIZE];
  uint8_t offset = WORD_SIZE;
  std::fill_n(data, WORD_SIZE, 0);
  std::copy(compressedKey.begin() + 1, compressedKey.end(), data);
  return intx::be::load<uint256_t>(data);
}

bytes_t BigInt::toBytes(uint256_t input) {
  bytes_t data;
  uint8_t bytes[32]; 
  intx::be::store(bytes, input);
  data.insert(data.end(), bytes, bytes + 32);
  return data;
}
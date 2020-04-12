#include <evm/big_int.h>
#include <evm/types.h>
#include <evm/hex.h>

uint256_t BigInt::fromBigEndianBytes(const bytes_t& bytes) {
  uint8_t data[WORD_SIZE];
  uint8_t offset = WORD_SIZE - bytes.size();
  std::fill_n(data, WORD_SIZE, 0);
  std::copy(bytes.begin(), bytes.end(), data + offset);
  return intx::be::load<uint256_t>(data);
}

uint256_t BigInt::fromHex(const std::string& hex) {
  bytes_t hexBytes = Hex::hexToBytes(hex);
  return BigInt::fromBigEndianBytes(hexBytes);
}

uint256_t BigInt::fromBytes(const bytes_t& bytes) {
  uint8_t data[WORD_SIZE];
  uint8_t offset = WORD_SIZE - bytes.size();
  std::fill_n(data, WORD_SIZE, 0);
  std::copy(bytes.begin(), bytes.end(), data + offset);
  return intx::le::load<uint256_t>(data);
}

uint256_t BigInt::fromCompressedKey(const compressed_key_t& compressedKey) {
  uint8_t data[WORD_SIZE];
  std::fill_n(data, WORD_SIZE, 0);
  std::copy(compressedKey.begin() + 1, compressedKey.end(), data);
  return intx::be::load<uint256_t>(data);
}

bytes_t BigInt::toBytes(const uint256_t& input) {
  bytes_t data;
  uint8_t bytes[32]; 
  intx::be::store(bytes, input);
  data.insert(data.end(), bytes, bytes + 32);
  return data;
}

std::array<uint8_t, 32> BigInt::toFixed32(const uint256_t& input) {
  std::array<uint8_t, 32> data {}; 
  uint8_t bytes[32]; 
  intx::be::store(bytes, input);
  std::move(std::begin(bytes), std::end(bytes), data.begin());
  return data;
}

uint256_t BigInt::load32(size_t begin, std::shared_ptr<bytes_t> bytes) {
  size_t end = std::min(begin + 32, bytes->size());
  uint8_t data[32] = {};
  for (size_t i = begin; i < end; i++)
    data[i - begin] = bytes->at(i);
  return intx::be::load<uint256_t>(data);
}
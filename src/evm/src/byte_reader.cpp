#include <evm/byte_reader.h>
#include <evm/big_int.h>

uint256_t ByteReader::read(uint16_t size) {
  uint16_t startPos = position;
  position += size; // move the ByteReader position forward
  bytes_t code = bytes_t(bytes.begin() + startPos, bytes.begin() + startPos + size);
  uint256_t word = BigInt::fromBigEndianBytes(code);
  return word;
}

uint16_t ByteReader::len() const {
  return bytes.size();
}
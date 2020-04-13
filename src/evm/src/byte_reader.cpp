#include <evm/byte_reader.h>
#include <evm/big_int.h>

uint256_t ByteReader::read(uint64_t size, std::shared_ptr<bytes_t> bytes) {
  uint64_t startPos = position;
  position += size; // move the ByteReader position forward
  bytes_t code = bytes_t(bytes->begin() + startPos, bytes->begin() + startPos + size);
  uint256_t word = BigInt::fromBigEndianBytes(code);
  return word;
}

uint64_t ByteReader::pc() {
  return position - 1;
}

uint8_t ByteReader::currentOp(std::shared_ptr<bytes_t> bytes) {
  return bytes->at(position);
}

void ByteReader::next() {
  position += 1;
}

void ByteReader::move(uint64_t to) {
  // printf("move_to{%llu}\n", to);
  position = to;
}

bool ByteReader::atEnd(std::shared_ptr<bytes_t> bytes) {
  return position >= bytes->size();
}
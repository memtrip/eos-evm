#include <evm/byte_reader.h>
#include <evm/big_int.h>

ByteReader::ByteReader(unsigned int positionArg, bytes_t& bytesArg) {
  position = positionArg;
  bytes = bytesArg;
}

uint256_t ByteReader::read(unsigned int size) {
  unsigned int startPos = position;
  position += size; // move the ByteReader position forward
  return uint256_t(
    BigInt::fromBigEndianBytes(
      bytes_t(bytes.begin() + startPos, bytes.begin() + startPos + size)
    )
  );
}

unsigned int ByteReader::len() {
  return bytes.size();
}
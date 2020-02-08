#include <algorithm>
#include "byte_reader.h"

ByteReader::ByteReader(unsigned int positionArg, unsigned char* bytesArg, unsigned int lenArg) {
  position = positionArg;
  bytes = bytesArg;
  len = lenArg;
}

uint256_t ByteReader::read(unsigned int size) {
  unsigned int pos = position;
  position += size;
  unsigned int max = std::min(pos + size, len);
  return uint256_t(0);
}
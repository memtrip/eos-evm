#include <iostream>
#include <algorithm>
#include "byte_reader.h"
#include "big_int.h"

ByteReader::ByteReader(unsigned int positionArg, char* bytesArg, unsigned int lenArg) {
  position = positionArg;
  bytes = bytesArg;
  len = lenArg;
}

uint256_t ByteReader::read(unsigned int size) {
  unsigned int startPos = position;
  position += size;
  char chunk[size];
  for (unsigned int i = 0; i < size; i++)
    chunk[i] = bytes[i + startPos];
  return uint256_t(BigInt::fromBytes(chunk, size));
}
#include "types.h"

class ByteReader {
  public:
    unsigned int position;
    unsigned char* bytes;
    unsigned int len;
    ByteReader(unsigned int positionArg, unsigned char* bytesArg, unsigned int lenArg);
    uint256_t read(unsigned int size);
};
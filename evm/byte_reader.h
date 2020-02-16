#include <vector>
#include "types.h"

class ByteReader {
  public:
    unsigned int position;
    bytes_t bytes;
    ByteReader(unsigned int positionArg, bytes_t& bytesArg);
    uint256_t read(unsigned int size);
    unsigned int len();
};
#include <vector>
#include "types.h"

class ByteReader {
  public:
    unsigned int position;
    std::vector<uint8_t> bytes;
    ByteReader(unsigned int positionArg, std::vector<uint8_t>& bytesArg);
    uint256_t read(unsigned int size);
    unsigned int len();
};
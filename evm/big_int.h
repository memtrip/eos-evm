#include "types.h"

class BigInt {
  public:
    static uint256_t fromBytes(char* bytes, int size);
};
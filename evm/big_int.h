#include "types.h"

class BigInt {
  public:
    static uint256_t fromBytes(char* bytes, int size);
    static void toBytes(uint256_t& value, char* output);
};
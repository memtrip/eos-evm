#include <vector>
#include "types.h"

class BigInt {
  public:
    static uint256_t fromBigEndianBytes(bytes_t bytes);
    static uint256_t fromBytes(bytes_t bytes);
    static bytes_t toBytes(uint256_t input);
};
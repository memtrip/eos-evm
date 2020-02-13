#include <vector>
#include "types.h"

class BigInt {
  public:
    static uint256_t fromBigEndianBytes(std::vector<uint8_t> bytes);
    static uint256_t fromBytes(std::vector<uint8_t> bytes);
    static uint256_t fromBytes(char* bytes, int size);
    static std::vector<uint8_t> toBytes(uint256_t const& input);
};
#include <vector>
#include "types.h"

class Hash {
  public:
    static uint256_t keccak256(std::vector<uint8_t>& bytes);
    static uint256_t keccak512(std::vector<uint8_t>& bytes);
};
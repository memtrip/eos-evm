#include "types.h"

class Jumps {
  public:
    static jump_set_t findDestinations(std::vector<uint8_t> bytes);
    static unsigned long verifyJump(uint256_t position, jump_set_t& jumps);
};
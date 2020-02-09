#include "types.h"

class Jumps {
  public:
    static jump_set_t findDestinations(char* byte_code, unsigned int size);
    static unsigned long verifyJump(uint256_t position, jump_set_t& jumps);
};
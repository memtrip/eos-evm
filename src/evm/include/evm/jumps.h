#include <evm/types.h>

class Jumps {
  public:
    static jump_set_t findDestinations(bytes_t bytes);
    static unsigned long verifyJump(uint256_t position, jump_set_t& jumps);
};
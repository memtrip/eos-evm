#include <evm/types.h>

class Jumps {
  public:
    static jump_set_t findDestinations(bytes_t& bytes);
    static uint64_t verifyJump(uint256_t position, jump_set_t& validDestinations);
};
#include <memory>
#include <evm/types.h>

class Jumps {
  public:
    static jump_set_t findDestinations(std::shared_ptr<bytes_t> bytes);
    static uint64_t verifyJump(const uint256_t& position, jump_set_t& validDestinations);
};
#include <memory>
#include <evm/types.h>

class Jumps {
  public:
    static jump_set_t findDestinations(std::shared_ptr<bytes_t> bytes);
    static uint64_t verifyJump(uint64_t position, const jump_set_t& validDestinations);
};
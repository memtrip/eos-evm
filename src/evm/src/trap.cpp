#include <evm/trap.h>
#include <evm/utils.h>

trap_t Trap::jump(uint64_t attemptedPosition) {
  JumpTrapInfo info {
    attemptedPosition
  };
  return create(TrapKind::TRAP_INVALID_JUMP, info);
}

trap_t Trap::create(TrapKind kind, trap_info_t info) {
  trap_t trap = std::make_pair(kind, info);
  // Utils::printTrap(trap);
  return trap;
}
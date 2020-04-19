#pragma once
#include <variant>
#include <utility>
#include <evm/types.h>

enum TrapKind {
  TRAP_STACK_UNDERFLOW,
  TRAP_OUT_OF_STACK,
  TRAP_INVALID_INSTRUCTION,
  TRAP_INVALID_JUMP,
  TRAP_INSUFFICIENT_FUNDS,
  TRAP_INVALID_CODE_ADDRESS
};

struct JumpTrapInfo {
  uint64_t attemptedPosition;
};

typedef std::variant<
  uint8_t,
  JumpTrapInfo
> trap_info_t;

typedef std::pair<TrapKind, trap_info_t> trap_t;

class Trap {
  public:
    static trap_t jump(uint64_t attemptedPosition) {
      JumpTrapInfo info {
        attemptedPosition
      };
      return create(TrapKind::TRAP_INVALID_JUMP, info);
    }

    static trap_t invalidCodeAddress() {
      return create(TrapKind::TRAP_INVALID_CODE_ADDRESS, 0);
    }

    static trap_t insufficientFunds() {
      return create(TrapKind::TRAP_INSUFFICIENT_FUNDS, 0);
    }

    static trap_t create(TrapKind kind, trap_info_t info) {
      trap_t trap = std::make_pair(kind, info);
      // Utils::printTrap(trap);
      return trap;
    }
};
#pragma once
#include <variant>
#include <utility>

enum TrapKind {
  TRAP_NONE,
  TRAP_STACK_UNDERFLOW,
  TRAP_OUT_OF_STACK,
  TRAP_INVALID_INSTRUCTION,
  TRAP_INVALID_JUMP,
  TRAP_CALL,
  TRAP_CREATE
};

struct JumpTrapInfo {
  uint64_t attemptedPosition;
};

typedef std::variant<
  JumpTrapInfo,
  uint8_t
> trap_info_t;

typedef std::pair<TrapKind, trap_info_t> trap_t;

class Trap {
  public:
    static trap_t jump(uint64_t attemptedPosition);
    static trap_t create(TrapKind kind, trap_info_t info);
};
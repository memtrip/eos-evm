#include <variant>
#include <evm/types.h>

enum ExecResult {
  STOPPED,
  DONE,
  CONTINUE,
  INTERPRETER_TRAP
};

enum InstructionResult {
  OK,
  UNUSED_GAS,
  JUMP_POSITION,
  STOP_EXEC_RETURN,
  STOP_EXEC,
  INSTRUCTION_TRAP
};

// stop execution
struct StopExecutionResult {
  uint256_t initOff;
  uint256_t initSize;
  bool apply;
};

// trap
enum TrapKind {
  TRAP_NONE,
  TRAP_CALL,
  TRAP_CREATE
};

struct TrapInfo {
  params_t params;
  uint256_t address;
};

typedef std::pair<TrapKind, TrapInfo> trap_t;

// instruction result
typedef std::variant<
  gas_t,
  uint256_t,
  StopExecutionResult,
  trap_t,
  unsigned char
> instruction_result_info_t;

typedef std::pair<InstructionResult, instruction_result_info_t> instruction_result_t;
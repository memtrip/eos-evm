#include <variant>
#include <evm/types.h>
#include <evm/return_data.h>

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

enum ExecResult {
  STOPPED,
  DONE,
  CONTINUE,
  INTERPRETER_TRAP
};

// exec result
typedef std::variant<
  gas_left_t,
  trap_t,
  uint8_t
> exec_result_info_t;

typedef std::pair<ExecResult, exec_result_info_t> exec_result_t;

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

// instruction result
typedef std::variant<
  uint256_t,
  StopExecutionResult,
  trap_t,
  uint8_t
> instruction_result_info_t;

typedef std::pair<InstructionResult, instruction_result_info_t> instruction_result_t;
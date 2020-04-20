#pragma once
#include <variant>
#include <evm/types.h>

struct NeedsReturn {
  gas_t gasLeft;
  uint64_t offset;
  uint64_t size;
  bool apply;
};
typedef NeedsReturn vm_data_t;

enum ExecResult {
  STOPPED,
  DONE_VOID,
  DONE_RETURN,
  CONTINUE,
  VM_TRAP,
  VM_OUT_OF_GAS
};

// exec result
typedef std::variant<
  gas_t,
  vm_data_t,
  trap_t
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
  gas_t gas;
  uint64_t initOff;
  uint64_t initSize;
  bool apply;
};

// instruction result
typedef std::variant<
  StopExecutionResult,
  trap_t,
  uint64_t
> instruction_result_info_t;

typedef std::pair<InstructionResult, instruction_result_info_t> instruction_result_t;
#pragma once
#include <variant>
#include <evm/types.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/trap.hpp>

enum ExecResult {
  STOPPED,
  DONE,
  CONTINUE,
  VM_TRAP,
  VM_OUT_OF_GAS,
  TRACE
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
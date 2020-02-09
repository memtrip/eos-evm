#import "types.h"

enum ExecResult: unsigned char {
  STOPPED = 0x40,
  DONE = 0x41,
  CONTINUE = 0x42,
  INTERPRETER_TRAP = 0x43
};

enum InstructionResult: unsigned char {
  OK = 0x21,
  UNUSED_GAS = 0x22,
  JUMP_POSITION = 0x23,
  JUMP_CONDITIONAL_POSITION = 0x24,
  STOP_EXEC_RETURN = 0x25,
  STOP_EXEC = 0x26,
  INSTRUCTION_TRAP = 0x27
};
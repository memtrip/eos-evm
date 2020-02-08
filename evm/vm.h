#include "byte_reader.h"
#include "stack.h"
#include "types.h"
#include "params.h"

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
  STOP_EXEC_RETURN = 0x24,
  STOP_EXEC = 0x25,
  INSTRUCTION_TRAP = 0x26
};

class VM {
  private:
    unsigned char last_stack_ret_len;
    StackMachine stack;
    ExecResult step(jump_set_t jumps, ByteReader& reader);
    ExecResult stepInner(ByteReader& reader);
    InstructionResult executeInstruction(instruct_t instruction, ByteReader& reader);
  public:
    ExecResult execute(char* bytesArg, unsigned int lenArg);
    // NOTE: exposed for testing
    uint256_t stackTop();
};
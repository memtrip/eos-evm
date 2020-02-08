#include "byte_reader.h"
#include "stack.h"
#include "types.h"

enum InstructionResult {
  OK = 0x21,
  UNUSED_GAS = 0x22,
  JUMP_POSITION = 0x23,
  STOP_EXEC_RETURN = 0x24,
  STOP_EXEC = 0x25,
  TRAP = 0x26
};

class VM {
  private:
    unsigned char last_stack_ret_len;
    StackMachine stack;
  public:
    void step(ByteReader* reader, jump_set_t jumps);
    unsigned int stepInner(ByteReader* reader);
    unsigned char execute(instruct_t instruction);
};
#include "byte_reader.h"
#include "stack.h"
#include "types.h"
#include "params.h"
#include "account_state.h"
#include "vm_result.h"

class VM {
  private:
    unsigned char last_stack_ret_len;

    ExecResult step(
      jump_set_t& jumps, 
      StackMachine& stack,
      ByteReader& reader, 
      AccountState& accountState
    );

    ExecResult stepInner(
      jump_set_t& jumps, 
      StackMachine& stack,
      ByteReader& reader, 
      AccountState& accountState
    );

    InstructionResult executeInstruction(
      instruct_t instruction, 
      StackMachine& stack,
      ByteReader& reader, 
      AccountState& accountState
    );

  public:
    ExecResult execute(char* bytesArg, unsigned int lenArg, StackMachine& stack, AccountState& accountState);
};
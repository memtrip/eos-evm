#include "byte_reader.h"
#include "stack.h"
#include "types.h"
#include "params.h"
#include "account_state.h"
#include "vm_result.h"
#include "memory.h"


class VM {
  private:
    unsigned char last_stack_ret_len;

    ExecResult step(
      jump_set_t& jumps, 
      Memory& memory,
      StackMachine& stack,
      ByteReader& reader, 
      AccountState& accountState,
      env_t envInfo
    );

    ExecResult stepInner(
      jump_set_t& jumps, 
      Memory& memory,
      StackMachine& stack,
      ByteReader& reader, 
      AccountState& accountState,
      env_t envInfo
    );

    InstructionResult executeInstruction(
      instruct_t instruction, 
      Memory& memory,
      StackMachine& stack,
      ByteReader& reader, 
      AccountState& accountState,
      env_t envInfo
    );

  public:
    ExecResult execute(
      std::vector<uint8_t> bytes, 
      Memory& memory,
      StackMachine& stack, 
      AccountState& accountState,
      env_t envInfo
    );
};
#include "byte_reader.h"
#include "stack.h"
#include <evm/types.h>
#include "account_state.h"
#include "vm_result.h"
#include <evm/memory.h>

class VM {
  private:
    unsigned char last_stack_ret_len;

    ExecResult step(
      jump_set_t& jumps, 
      Memory& memory,
      StackMachine& stack,
      ByteReader& reader, 
      AccountState& accountState,
      params_t& params,
      env_t env
    );

    ExecResult stepInner(
      jump_set_t& jumps, 
      Memory& memory,
      StackMachine& stack,
      ByteReader& reader, 
      AccountState& accountState,
      params_t& params,
      env_t env
    );

    instruction_result_t executeInstruction(
      instruct_t instruction, 
      Memory& memory,
      StackMachine& stack,
      ByteReader& reader, 
      AccountState& accountState,
      params_t& params,
      env_t env
    );

  public:
    ExecResult execute(
      Memory& memory,
      StackMachine& stack, 
      AccountState& accountState,
      params_t& params,
      env_t env
    );
};
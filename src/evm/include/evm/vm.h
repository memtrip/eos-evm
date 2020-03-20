#include "byte_reader.h"
#include "stack.h"
#include <evm/types.h>
#include "account_state.h"
#include "vm_result.h"
#include <evm/memory.h>
#include <evm/external.h>
#include <evm/gasometer.h>

class VM {
  public:
    explicit VM(
      params_t& p,
      const Gasometer& g = Gasometer(0),
      const StackMachine& s = StackMachine()
    ): params(p), gasometer(g), stack(s) {
      gasometer.currentGas = params.gas;
    };

    exec_result_t step(
      jump_set_t& jumps, 
      Memory& memory,
      ByteReader& reader, 
      AccountState& accountState,
      External& external,
      Call& call,
      env_t& env
    );
    exec_result_t stepInner(
      jump_set_t& jumps, 
      Memory& memory,
      ByteReader& reader, 
      AccountState& accountState,
      External& external,
      Call& call,
      env_t& env
    );
    instruction_result_t executeInstruction(
      gas_t gas,
      gas_t providedGas,
      instruct_t instruction, 
      Memory& memory,
      ByteReader& reader, 
      AccountState& accountState,
      External& external,
      Call& call,
      env_t& env
    );
    exec_result_t execute(
      Memory& memory,
      AccountState& accountState,
      External& external,
      Call& call,
      env_t& env
    );
    StackMachine stack;
  private:
    params_t params;
    Gasometer gasometer;
};
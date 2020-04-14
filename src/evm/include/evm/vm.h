#include <memory>
#include <evm/byte_reader.hpp>
#include <evm/stack.hpp>
#include <evm/types.h>
#include <evm/account_state.hpp>
#include <evm/vm_result.h>
#include <evm/memory.hpp>
#include <evm/external.h>
#include <evm/gasometer.h>
#include <evm/context.h>
#include <evm/operation.h>

class VM {
  public:
    VM(
      std::shared_ptr<StackMachine> stackArg,
      std::shared_ptr<Gasometer> gasometerArg
    ) {
      stack = stackArg;
      gasometer = gasometerArg;
    };
    exec_result_t execute(
      Operation& operation,
      std::shared_ptr<Context> context,
      std::shared_ptr<Memory> memory,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Call> call
    );
    exec_result_t step(
      Operation& operation,
      jump_set_t& jumps, 
      std::shared_ptr<Context> context,
      std::shared_ptr<GasCalculation> gasCalculation,
      std::shared_ptr<Memory> memory,
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Call> call
    );
    exec_result_t stepInner(
      Operation& operation,
      jump_set_t& jumps, 
      std::shared_ptr<Context> context,
      std::shared_ptr<GasCalculation> gasCalculation,
      std::shared_ptr<Memory> memory,
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Call> call
    );
    instruction_result_t executeCreateInstruction(
      Operation& operation,
      uint8_t opcode,
      gas_t providedGas,
      std::shared_ptr<Context> context,
      std::shared_ptr<Memory> memory,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Call> call
    );
    instruction_result_t executeCallInstruction(
      Operation& operation,
      uint8_t opcode,
      gas_t providedGas,
      std::shared_ptr<Context> context,
      std::shared_ptr<Memory> memory,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Call> call
    );
    std::shared_ptr<StackMachine> stack;
  private:
    std::shared_ptr<Gasometer> gasometer;
};
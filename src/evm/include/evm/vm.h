#include <memory>
#include <evm/byte_reader.h>
#include <evm/stack.h>
#include <evm/types.h>
#include <evm/account_state.h>
#include <evm/vm_result.h>
#include <evm/memory.h>
#include <evm/external.h>
#include <evm/gasometer.h>
#include <evm/context.h>
#include <evm/operation.h>

class VM {
  public:
    explicit VM(
      std::shared_ptr<Context> contextArg,
      std::shared_ptr<StackMachine> stackArg,
      const Gasometer& g = Gasometer(0),
      const Operation& o = Operation()
    ): gasometer(g), operation(o) {
      context = contextArg;
      stack = stackArg;
      gasometer.currentGas = context->gas;
    };
    exec_result_t execute(
      std::shared_ptr<Memory> memory,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Call> call
    );
    exec_result_t step(
      jump_set_t& jumps, 
      std::shared_ptr<GasCalculation> gasCalculation,
      std::shared_ptr<Memory> memory,
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Call> call
    );
    exec_result_t stepInner(
      jump_set_t& jumps, 
      std::shared_ptr<GasCalculation> gasCalculation,
      std::shared_ptr<Memory> memory,
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Call> call
    );
    instruction_result_t executeCreateInstruction(
      uint8_t opcode,
      gas_t providedGas,
      std::shared_ptr<Memory> memory,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Call> call
    );
    instruction_result_t executeCallInstruction(
      uint8_t opcode,
      gas_t providedGas,
      std::shared_ptr<Memory> memory,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Call> call
    );
    std::shared_ptr<StackMachine> stack;
  private:
    std::shared_ptr<Context> context;
    Gasometer gasometer;
    Operation operation;
};
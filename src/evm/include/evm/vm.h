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

class VM {
  public:
    explicit VM(
      std::shared_ptr<Context> contextArg,
      std::shared_ptr<StackMachine> stackArg,
      const Gasometer& g = Gasometer(0)
    ): gasometer(g) {
      context = contextArg;
      stack = stackArg;
      gasometer.currentGas = context->gas;
    };

    exec_result_t step(
      jump_set_t& jumps, 
      std::shared_ptr<Memory> memory,
      ByteReader& reader, 
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Call> call
    );
    exec_result_t stepInner(
      jump_set_t& jumps, 
      std::shared_ptr<Memory> memory,
      ByteReader& reader, 
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Call> call
    );
    instruction_result_t executeInstruction(
      gas_t gas,
      gas_t providedGas,
      instruct_t instruction, 
      std::shared_ptr<Memory> memory,
      ByteReader& reader, 
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Call> call
    );
    exec_result_t execute(
      std::shared_ptr<Memory> memory,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Call> call
    );
    std::shared_ptr<StackMachine> stack;
  private:
    std::shared_ptr<Context> context;
    Gasometer gasometer;
};
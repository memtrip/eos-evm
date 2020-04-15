#include <vector>
#include <set>
#include <tuple>
#include <evm/execute.h>
#include <evm/vm.h>
#include <evm/external.h>
#include <evm/hex.hpp>
#include <evm/operation.h>

finalization_result_t Execute::callWithStackDepth(
  Operation& operation,
  size_t stackDepth,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<External> external,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<Context> context,
  std::shared_ptr<Call> call
  /* tracer */
  /* vm_tracer */
) {
  std::shared_ptr<std::vector<uint256_t>> stackVector = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack =  std::make_shared<StackMachine>(stackVector);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);

  VM vm(stack, gasometer);

  exec_result_t vm_result = vm.execute(
    operation,
    context,
    memory, 
    accountState, 
    external, 
    call
  );

  switch (vm_result.first) {
    case ExecResult::STOPPED:
      {
        SlicePosition slicePosition { 0, 0 };

        Finalization finalization {
          0,
          false,
          slicePosition
        };

        return std::make_pair(
          FinalizationResult::FINALIZATION_OK,
          finalization
        );
      }
    case ExecResult::DONE:
      {
        gas_left_t gasLeft = std::get<gas_left_t>(vm_result.second);
        switch (gasLeft.first) {
          case KNOWN:
            {
              gas_t gasLeftValue = std::get<gas_t>(gasLeft.second); 

              SlicePosition slicePosition { 0, 0 };

              Finalization finalization {
                gasLeftValue,
                true,
                slicePosition
              };

              return std::make_pair(
                FinalizationResult::FINALIZATION_OK,
                finalization
              );
            }
          case NEEDS_RETURN:
            {
              NeedsReturn needsReturn = std::get<NeedsReturn>(gasLeft.second);

              Finalization finalization {
                needsReturn.gasLeft,
                needsReturn.apply,
                needsReturn.slicePosition
              };
   
              return std::make_pair(
                FinalizationResult::FINALIZATION_OK,
                finalization
              );
            }
        }
      }
    case ExecResult::VM_TRAP:
      {
        trap_t trap = std::get<trap_t>(vm_result.second);
        return std::make_pair(
          FinalizationResult::FINALIZATION_ERROR,
          trap
        );
      }
    case ExecResult::VM_OUT_OF_GAS:
      return std::make_pair(
        FinalizationResult::FINALIZATION_OUT_OF_GAS,
        0
      );
    case ExecResult::TRACE:
      {
        uint8_t position = std::get<uint8_t>(vm_result.second);
        return std::make_pair(
          FinalizationResult::FINALIZATION_TRACE,
          position
        );
      }
    case ExecResult::CONTINUE:
      // In reality this option is never reached
      return std::make_pair(
        FinalizationResult::FINALIZATION_ERROR,
        0
      );
  };
}
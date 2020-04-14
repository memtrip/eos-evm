#include <vector>
#include <set>
#include <tuple>
#include <evm/execute.h>
#include <evm/vm.h>
#include <evm/external.h>
#include <evm/hex.hpp>
#include <evm/operation.h>

finalization_result_t Execute::createWithStackDepth(
  size_t stackDepth,
  std::shared_ptr<External> external,
  std::shared_ptr<Context> context
  /* tracer */
  /* vm_tracer */
) {
  std::shared_ptr<bytes_t> existingCode = external->code(context->codeAddress);
  if (existingCode->size() > 0) {
    // handle this error properly
    return std::make_pair(
      FinalizationResult::FINALIZATION_ERROR,
      0
    );
  } else {
    printf("emplaceCode\n");
    external->emplaceCode(context->codeAddress, context->code);
    SlicePosition slicePosition { 0, 0 };

    Finalization finalization {
      context->gas,
      true,
      slicePosition
    };

    return std::make_pair(
      FinalizationResult::FINALIZATION_OK,
      finalization
    );
  }
}

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
    case STOPPED:
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
    case DONE:
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
    case VM_TRAP:
      return std::make_pair(
        FinalizationResult::FINALIZATION_ERROR,
        0
      );
    case VM_OUT_OF_GAS:
      return std::make_pair(
        FinalizationResult::FINALIZATION_OUT_OF_GAS,
        0
      );
    case TRACE:
      {
        uint8_t position = std::get<uint8_t>(vm_result.second);
        return std::make_pair(
          FinalizationResult::FINALIZATION_TRACE,
          position
        );
      }
    case CONTINUE:
      // In reality this option is never reached
      return std::make_pair(
        FinalizationResult::FINALIZATION_ERROR,
        0
      );
  };
}
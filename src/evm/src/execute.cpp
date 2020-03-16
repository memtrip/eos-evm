#include <set>
#include <tuple>
#include <evm/execute.h>
#include <evm/vm.h>
#include <evm/external.h>
#include <evm/hex.h>

finalization_result_t Execute::callWithStackDepth(
  params_t params,
  size_t stackDepth,
  Substate& substate,
  External& external,
  AccountState& accountState,
  env_t env,
  Call& call
  /* tracer */
  /* vm_tracer */
) {

  gas_t gas = params.gas;

  VM vm {};

  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);

  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  exec_result_t vm_result = vm.execute(
    mem, 
    sm, 
    accountState, 
    gasometer, 
    params, 
    external, 
    call, 
    env
  );

  delete memoryBytes;
  delete stackItems;

  switch (vm_result.first) {
    case STOPPED:
      {
        Finalization finalization {
          uint256_t(0),
          false,
          ReturnData::empty()
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
              uint256_t gas = std::get<uint256_t>(gasLeft.second); 

              Finalization finalization {
                gas,
                true,
                ReturnData::empty()
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
                needsReturn.data
              };
   
              return std::make_pair(
                FinalizationResult::FINALIZATION_OK,
                finalization
              );
            }
        }
      }
    case INTERPRETER_TRAP:
      return std::make_pair(
        FinalizationResult::FINALIZATION_ERROR,
        0
      );
    case CONTINUE:
      // In reality this option is never reached
      return std::make_pair(
        FinalizationResult::FINALIZATION_ERROR,
        0
      );
  };
}
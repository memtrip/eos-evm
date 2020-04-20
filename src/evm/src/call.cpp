#include <tuple>
#include <evm/call.h>
#include <evm/vm.h>

#include <evm/account_state.hpp>
#include <evm/gasometer.hpp>
#include <evm/big_int.hpp>
#include <evm/operation.h>

call_result_t Call::call(
  std::shared_ptr<Memory> memory,
  std::shared_ptr<Context> context,
  std::shared_ptr<External> external,
  std::shared_ptr<AccountState> accountState
) {

  Operation operation = Operation();

  std::shared_ptr<std::vector<uint256_t>> stackVector = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack =  std::make_shared<StackMachine>(stackVector);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);

  VM vm(stack, gasometer);

  exec_result_t vm_result = vm.execute(
    operation,
    context,
    memory, 
    accountState, 
    external
  );

  switch (vm_result.first) {
    case ExecResult::STOPPED:
      return std::make_pair(MessageCallResult::MESSAGE_CALL_SUCCESS, 0);
    case ExecResult::DONE_VOID:
    {
      gas_t gasLeft = std::get<gas_t>(vm_result.second);
      return std::make_pair(MessageCallResult::MESSAGE_CALL_SUCCESS, gasLeft);
    }
    case ExecResult::DONE_RETURN:
      {
        vm_data_t vmData = std::get<vm_data_t>(vm_result.second);
        if (vmData.apply) {
          MessageCallReturn messageCallReturn {
            vmData.gasLeft,
            vmData.offset,
            vmData.size
          };
          return std::make_pair(MessageCallResult::MESSAGE_CALL_RETURN, messageCallReturn);
        } else {
          return std::make_pair(MessageCallResult::MESSAGE_CALL_REVERTED, 0);
        }
      }
    case ExecResult::VM_TRAP:
      {
        trap_t trap = std::get<trap_t>(vm_result.second);
        return std::make_pair(MessageCallResult::MESSAGE_CALL_FAILED, trap);
      }
    case ExecResult::VM_OUT_OF_GAS:
      return std::make_pair(MessageCallResult::MESSAGE_CALL_OUT_OF_GAS, 0);
    case ExecResult::CONTINUE:
      return std::make_pair(MessageCallResult::MESSAGE_CALL_FAILED, 0);
  };
}
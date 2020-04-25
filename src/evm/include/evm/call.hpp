#pragma once
#include <memory>
#include <evm/types.h>
#include <evm/external.h>
#include <evm/vm.h>

#include <evm/pending_state.hpp>
#include <evm/context.hpp>
#include <evm/memory.hpp>

class Call {
  public:
    static call_result_t call(
      uint16_t stackDepth,
      std::shared_ptr<Memory> memory,
      std::shared_ptr<Context> context,
      std::shared_ptr<External> external,
      std::shared_ptr<PendingState> pendingState
    ) {

      uint16_t nextStackDepth = stackDepth + 1;
      pendingState->currentStackDepth = nextStackDepth;

      Operation operation = Operation();

      std::shared_ptr<std::vector<uint256_t>> stackVector = std::make_shared<std::vector<uint256_t>>();
      std::shared_ptr<StackMachine> stack =  std::make_shared<StackMachine>(stackVector);
      std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);

      VM vm(stack, gasometer);

      printf("nextStackDepth{%d}[", nextStackDepth);
      exec_result_t vm_result = vm.execute(
        nextStackDepth,
        operation,
        context,
        memory, 
        pendingState, 
        external
      );
      printf("]");

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
            MessageCallReturn messageCallReturn {
              vmData.gasLeft,
              vmData.offset,
              vmData.size
            };
            if (vmData.apply) {
              return std::make_pair(MessageCallResult::MESSAGE_CALL_RETURN, messageCallReturn);
            } else {
              pendingState->revert(nextStackDepth);
              return std::make_pair(MessageCallResult::MESSAGE_CALL_REVERTED, messageCallReturn);
            }
          }
        case ExecResult::VM_TRAP:
          {
            pendingState->revert(nextStackDepth);
            trap_t trap = std::get<trap_t>(vm_result.second);
            return std::make_pair(MessageCallResult::MESSAGE_CALL_FAILED, trap);
          }
        case ExecResult::VM_OUT_OF_GAS:
          {
            pendingState->revert(nextStackDepth);
            return std::make_pair(MessageCallResult::MESSAGE_CALL_OUT_OF_GAS, 0);
          }
        case ExecResult::CONTINUE:
          {
            pendingState->revert(nextStackDepth);
            return std::make_pair(MessageCallResult::MESSAGE_CALL_FAILED, 0);
          }
      };
    }
};
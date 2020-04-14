#include <tuple>
#include <evm/call.h>
#include <evm/vm.h>
#include <evm/return_data.h>
#include <evm/account_state.hpp>
#include <evm/gasometer.h>
#include <evm/execute.h>
#include <evm/big_int.hpp>
#include <evm/operation.h>

call_result_t Call::create(
  bool trap,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<Context> context,
  std::shared_ptr<External> external,
  std::shared_ptr<AccountState> accountState
) {
  return makeCall(
    ActionType::ACTION_CREATE,
    trap,
    memory,
    context,
    external,
    accountState
  );
}

call_result_t Call::call(
  bool trap,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<Context> context,
  std::shared_ptr<External> external,
  std::shared_ptr<AccountState> accountState
) {

  // TODO: move this up
  // bytes_t code = external->code(codeAddress);

  return makeCall(
    ActionType::ACTION_CALL,
    trap,
    memory,
    context,
    external,
    accountState
  );
}

call_result_t Call::makeCall(
  action_type_t callType,
  bool trap,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<Context> context,
  std::shared_ptr<External> external,
  std::shared_ptr<AccountState> accountState
) {

  Operation operation = Operation();

  std::shared_ptr<Call> innerCall = std::make_shared<Call>(stackDepth);

  finalization_result_t finalizationResult;

  switch (callType) {
    case ActionType::ACTION_CREATE:
    case ActionType::ACTION_CREATE2:
      {
        printf("ACTION_CREATE / ACTION_CREATE2\n");
        finalizationResult = Execute::createWithStackDepth(
          stackDepth + 1,
          external,
          context
        );
        break;
      }
    case ActionType::ACTION_CALL_CODE:
    case ActionType::ACTION_CALL:
    case ActionType::ACTION_STATIC_CALL:
    case ActionType::ACTION_DELEGATE_CALL:
      {
        finalizationResult = Execute::callWithStackDepth(
          operation,
          stackDepth + 1,
          memory,
          external,
          accountState,
          context,
          innerCall
        );
        break;
      }
  }

  switch (finalizationResult.first) {
    case FINALIZATION_OK:
      {
        Finalization finalization = std::get<Finalization>(finalizationResult.second);

        MessageCallReturn messageCallReturn {
          finalization.gasLeft,
          finalization.slicePosition
        };

        if (finalization.applyState) {
          return std::make_pair(
            MessageCallResult::MESSAGE_CALL_SUCCESS,
            messageCallReturn
          );
        } else {
          return std::make_pair(
            MessageCallResult::MESSAGE_CALL_REVERTED,
            messageCallReturn
          );
        }
      } 
    case FINALIZATION_OUT_OF_GAS:
      return std::make_pair(
        MessageCallResult::MESSAGE_CALL_OUT_OF_GAS,
        0 
      );
    case FINALIZATION_TRACE:
      {
        uint8_t position = std::get<uint8_t>(finalizationResult.second);
        return std::make_pair(
          MessageCallResult::MESSAGE_CALL_TRACE,
          position 
        );
      }
    case FINALIZATION_ERROR:
      return std::make_pair(
        MessageCallResult::MESSAGE_CALL_FAILED,
        0 
      );
  }
}
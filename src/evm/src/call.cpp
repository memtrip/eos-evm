#include <tuple>
#include <evm/call.h>
#include <evm/vm.h>
#include <evm/return_data.h>
#include <evm/account_state.h>
#include <evm/gasometer.h>
#include <evm/execute.h>
#include <evm/big_int.h>

call_result_t Call::create(
  bool trap,
  std::shared_ptr<Context> context,
  std::shared_ptr<External> external,
  std::shared_ptr<AccountState> accountState
) {
  return makeCall(
    ActionType::ACTION_CREATE,
    trap,
    context,
    external,
    accountState
  );
}

call_result_t Call::call(
  bool trap,
  std::shared_ptr<Context> context,
  std::shared_ptr<External> external,
  std::shared_ptr<AccountState> accountState
) {

  // TODO: move this up
  // bytes_t code = external->code(codeAddress);

  return makeCall(
    ActionType::ACTION_CALL,
    trap,
    context,
    external,
    accountState
  );
}

call_result_t Call::makeCall(
  action_type_t callType,
  bool trap,
  std::shared_ptr<Context> context,
  std::shared_ptr<External> external,
  std::shared_ptr<AccountState> accountState
) {

  std::shared_ptr<Call> innerCall = std::make_shared<Call>(stackDepth);

  finalization_result_t finalizationResult = Execute::callWithStackDepth(
    stackDepth + 1,
    external,
    accountState,
    context,
    innerCall
  );

  switch (finalizationResult.first) {
    case FINALIZATION_OK:
      {
        Finalization finalization = std::get<Finalization>(finalizationResult.second);

        MessageCallReturn messageCallReturn {
          finalization.gasLeft,
          finalization.returnData
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
#include <tuple>
#include <evm/call.h>
#include <evm/vm.h>
#include <evm/return_data.h>
#include <evm/account_state.hpp>
#include <evm/gasometer.hpp>
#include <evm/execute.h>
#include <evm/big_int.hpp>
#include <evm/operation.h>
#include <evm/trap.hpp>

call_result_t Call::create(
  bool trap,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<Context> context,
  std::shared_ptr<External> external,
  std::shared_ptr<AccountState> accountState
) {
  call_result_t callResult = makeCall(
    ActionType::ACTION_CREATE,
    trap,
    memory,
    context,
    external,
    accountState
  );

  if (callResult.first == MessageCallResult::MESSAGE_CALL_APPLY_CREATE) {
    
    MessageCallReturn messageCallReturn = std::get<MessageCallReturn>(callResult.second);

    std::shared_ptr<bytes_t> contractCode = memory->readSlice(
      messageCallReturn.slicePosition.offset, 
      messageCallReturn.slicePosition.size
    );

    emplace_t emplaceResult = external->emplaceCode(context->sender, 0, contractCode);

    switch (emplaceResult.first) {
      case EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND:
        return std::make_pair(
          MessageCallResult::MESSAGE_CALL_FAILED,
          Trap::invalidCodeAddress()
        );
      case EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS:
        {
          return std::make_pair(
            MessageCallResult::MESSAGE_CALL_FAILED,
            Trap::insufficientFunds()
          );
        }
      case EmplaceResult::EMPLACE_SUCCESS:
        break;
    }
  }

  return callResult;
}

call_result_t Call::call(
  bool trap,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<Context> context,
  std::shared_ptr<External> external,
  std::shared_ptr<AccountState> accountState
) {
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

  finalization_result_t finalizationResult = Execute::callWithStackDepth(
    operation,
    stackDepth + 1,
    memory,
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
          finalization.slicePosition
        };

        if (finalization.applyState) {
          if (finalization.slicePosition.size > 0) {
            return std::make_pair(
              MessageCallResult::MESSAGE_CALL_APPLY_CREATE,
              messageCallReturn
            );
          } else {
            return std::make_pair(
              MessageCallResult::MESSAGE_CALL_SUCCESS,
              messageCallReturn
            );
          }
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
      {
        trap_t trap = std::get<trap_t>(finalizationResult.second);
        return std::make_pair(
          MessageCallResult::MESSAGE_CALL_FAILED,
          trap
        );
      }
  }
}
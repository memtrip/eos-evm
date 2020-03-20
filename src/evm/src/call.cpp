#include <tuple>
#include <evm/call.h>
#include <evm/vm.h>
#include <evm/return_data.h>
#include <evm/account_state.h>
#include <evm/gasometer.h>
#include <evm/execute.h>
#include <evm/big_int.h>

call_result_t Call::execute(
  transaction_t& transaction,
  bytes_t& callerAddress,
  env_t& env,
  External& external,
  AccountState& accountState
) {

  switch (transaction.action) {
    case TransactionActionType::TRANSACTION_CREATE:
      return create(
        static_cast<gas_t>(transaction.gas_limit),
        BigInt::fromBytes(callerAddress),
        transaction.value,
        transaction.data,
        ActionType::ACTION_CREATE,
        true,
        env,
        external,
        accountState
      );
    case TransactionActionType::TRANSACTION_CALL:
      uint256_t address = BigInt::fromBytes(transaction.to);
      return call(
        static_cast<gas_t>(transaction.gas_limit),
        BigInt::fromBytes(callerAddress),
        address,
        transaction.value,
        transaction.data,
        address,
        ActionType::ACTION_CALL,
        true,
        env,
        external,
        accountState
      );
  }
}

call_result_t Call::create(
  gas_t gas,
  uint256_t address,
  uint256_t value,
  const bytes_t& code,
  action_type_t callType,
  bool trap,
  env_t& env,
  External& external,
  AccountState& accountState
) {

  params_t params = {
    address, /* codeAddress*/
    uint256_t(0), /* codeHash */
    uint256_t(1), /* codeVersion */
    address, /* address */
    address, /* sender */
    uint256_t(0), /* origin */
    gas, /* gas */
    uint256_t(0), /* gasPrice */
    value, /* value */
    code, /* code */
    bytes_t() /* data */ // TODO: does CREATE ever uses a data arguments
  };

  return makeCall(
    params,
    callType,
    trap,
    env,
    external,
    accountState
  );
}

call_result_t Call::call(
  gas_t gas,
  uint256_t senderAddress,
  uint256_t receiveAddress,
  uint256_t value,
  bytes_t& data,
  uint256_t codeAddress,
  action_type_t callType,
  bool trap,
  env_t& env,
  External& external,
  AccountState& accountState
) {

  bytes_t code = external.code(codeAddress);

  params_t params = {
    codeAddress, /* codeAddress*/
    uint256_t(0), /* codeHash */
    uint256_t(1), /* codeVersion */
    receiveAddress, /* address */
    senderAddress, /* sender */
    uint256_t(0), /* origin */
    gas, /* gas */
    uint256_t(0), /* gasPrice */
    value, /* value */
    code, /* code */
    bytes_t(data.begin(), data.end()) /* data */
  };

  return makeCall(
    params,
    callType,
    trap,
    env,
    external,
    accountState
  );
}

call_result_t Call::makeCall(
  params_t& params,
  action_type_t callType,
  bool trap,
  env_t& env,
  External& external,
  AccountState& accountState
) {

  finalization_result_t finalizationResult = Execute::callWithStackDepth(
    params,
    stackDepth + 1,
    external,
    accountState,
    env,
    *this
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
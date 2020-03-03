#include <evm/call.h>
#include <evm/vm.h>
#include <evm/return_data.h>
#include <evm/account_state.h>
#include <evm/gasometer.h>

call_result_t Call::call(
  uint256_t senderAddress,
  uint256_t receiveAddress,
  uint256_t value,
  bytes_t& data,
  uint256_t codeAddress,
  ActionType callType,
  bool trap,
  env_t env,
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
    value, /* value */
    code, /* code */
    bytes_t(data.begin(), data.end()) /* data */
  };

  VM vm {};

  Gasometer gasometer {};
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);

  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  Call innerCall {};

  ReturnData returnData = ReturnData::empty();
  exec_result_t vm_result = vm.execute(mem, sm, accountState, gasometer, params, external, returnData, innerCall, env);

  switch (vm_result.first) {
    case ExecResult::STOPPED:
      break;
    case ExecResult::DONE:
      break;
    case ExecResult::CONTINUE:
      break;
    case ExecResult::INTERPRETER_TRAP:
      break;
  }

  call_result_t result = std::make_pair(
    MessageCallResult::MESSAGE_CALL_FAILED,
    0
  );
  
  delete memoryBytes;

  return result;
}
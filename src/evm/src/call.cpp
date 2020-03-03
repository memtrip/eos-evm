#include <evm/call.h>
#include <evm/vm.h>
#include <evm/return_data.h>
#include <evm/account_state.h>

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

  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);

  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  Call innerCall {};

  ReturnData returnData = ReturnData::empty();
  vm.execute(mem, sm, accountState, params, external, returnData, innerCall, env);

  call_result_t result = std::make_pair(
    MessageCallResult::MESSAGE_CALL_FAILED,
    0
  );

  return result;
}
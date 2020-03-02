#include <evm/call.h>

call_result_t Call::call(
  uint256_t senderAddress,
  uint256_t receiveAddress,
  uint256_t value,
  bytes_t& data,
  uint256_t codeAddress,
  ActionType callType,
  bool trap,
  External& external
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

  call_result_t result = std::make_pair(
    MessageCallResult::MESSAGE_CALL_FAILED,
    0
  );

  return result;
}
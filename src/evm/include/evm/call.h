#pragma once
#include <evm/types.h>
#include <evm/return_data.h>
#include <evm/external.h>

enum MessageCallResult {
  MESSAGE_CALL_SUCCESS,
  MESSAGE_CALL_FAILED,
  MESSAGE_CALL_REVERTED
};

struct MessageCallReturn {
  uint256_t value;
  ReturnData returnData;
};

typedef std::variant<
  uint8_t,
  MessageCallReturn
> call_result_data_t;

typedef std::pair<MessageCallResult, call_result_data_t> call_result_t;

class Call {
  public:
    call_result_t call(
      uint256_t senderAddress,
      uint256_t receiveAddress,
      uint256_t value,
      bytes_t& data,
      uint256_t codeAddress,
      ActionType callType,
      bool trap,
      External& external
    );
};
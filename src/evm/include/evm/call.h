#pragma once
#include <memory>
#include <evm/types.h>

#include <evm/call.h>
#include <evm/external.h>
#include <evm/account_state.hpp>
#include <evm/context.hpp>
#include <evm/memory.hpp>
#include <evm/vm_result.h>

// message call result
enum MessageCallResult {
  MESSAGE_CALL_SUCCESS,
  MESSAGE_CALL_RETURN,
  MESSAGE_CALL_FAILED,
  MESSAGE_CALL_REVERTED,
  MESSAGE_CALL_OUT_OF_GAS
};

struct MessageCallReturn {
  gas_t gasLeft;
  uint64_t offset;
  uint64_t size;
};

typedef std::variant<
  gas_t,
  trap_t,
  MessageCallReturn
> call_result_data_t;

typedef std::pair<MessageCallResult, call_result_data_t> call_result_t;

class Call {
  public:
    explicit Call(uint16_t s): stackDepth(s) { };
    call_result_t call(
      std::shared_ptr<Memory> memory,
      std::shared_ptr<Context> context,
      std::shared_ptr<External> external,
      std::shared_ptr<AccountState> accountState
    );
  private:
    uint16_t stackDepth;
};
#pragma once
#include <evm/types.h>
#include <evm/return_data.h>
#include <evm/account_state.h>
#include <evm/call.h>

struct Finalization {
  uint256_t gasLeft;
  bool applyState;
  ReturnData returnData;
};

typedef std::variant<
  uint8_t,
  Finalization
> finalization_t;

enum FinalizationResult {
  FINALIZATION_OK,
  FINALIZATION_OUT_OF_GAS,
  FINALIZATION_ERROR,
  FINALIZATION_TRACE
};

typedef std::pair<
  FinalizationResult,
  finalization_t
> finalization_result_t;

class Execute {
  public:
    static finalization_result_t callWithStackDepth(
      params_t& params,
      size_t stackDepth,
      External& external,
      AccountState& accountState,
      env_t& env,
      Call& call
      /* tracer */
      /* vm_tracer */
    );
};
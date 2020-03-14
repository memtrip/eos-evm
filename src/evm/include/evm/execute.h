#pragma once
#include <evm/types.h>
#include <evm/return_data.h>
#include <evm/account_state.h>
#include <evm/call.h>

struct Substate {
  std::set<uint256_t> suicides;
  std::set<uint256_t> touched;
  uint64_t sstoreClearsRefund;
  std::vector<uint256_t> contractsCreated;
};

typedef Substate substate_t;

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
  FINALIZATION_ERROR
};

typedef std::pair<
  FinalizationResult,
  finalization_t
> finalization_result_t;

class Execute {
  public:
    static finalization_result_t callWithStackDepth(
      params_t params,
      size_t stackDepth,
      Substate& substate,
      External& external,
      AccountState& accountState,
      env_t env,
      Call& call
      /* tracer */
      /* vm_tracer */
    );
};
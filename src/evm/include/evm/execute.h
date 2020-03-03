#pragma once
#include <evm/types.h>
#include <evm/return_data.h>

struct Substate {
  std::set<uint256_t> suicides;
  std::set<uint256_t> touched;
  uint64_t sstoreClearsRefund;
  std::vector<uint256_t> contractsCreated;
};

struct FinalizationResult {
  uint256_t gasLeft;
  bool applyState;
  ReturnData returnData;
};

class Execute {
  public:
    FinalizationResult callWithStackDepth(
      Params params,
      Substate substate,
      size_t stackDepth
      /* tracer */
      /* vm_tracer */
    );
};
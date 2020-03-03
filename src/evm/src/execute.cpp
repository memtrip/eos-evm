#include <set>
#include <evm/execute.h>

FinalizationResult Execute::callWithStackDepth(
  Params params,
  Substate substate,
  size_t stackDepth
  /* tracer */
  /* vm_tracer */
) {

  ReturnData empty = ReturnData::empty();

  FinalizationResult finalizationResult {
    uint256_t(0),
    true,
    empty
  };
  
  return finalizationResult;
}
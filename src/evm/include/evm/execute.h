#pragma once
#include <memory>
#include <evm/types.h>
#include <evm/return_data.h>
#include <evm/account_state.hpp>
#include <evm/call.h>
#include <evm/operation.h>

struct Finalization {
  gas_t gasLeft;
  bool applyState;
  SlicePosition slicePosition;
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
    static finalization_result_t createWithStackDepth(
      size_t stackDepth,
      std::shared_ptr<External> external,
      std::shared_ptr<Context> context
      /* tracer */
      /* vm_tracer */
    );

    static finalization_result_t callWithStackDepth(
      Operation& operation,
      size_t stackDepth,
      std::shared_ptr<Memory> memory,
      std::shared_ptr<External> external,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<Context> context,
      std::shared_ptr<Call> call
      /* tracer */
      /* vm_tracer */
    );
};
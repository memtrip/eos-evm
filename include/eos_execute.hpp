#pragma once
#include <evm/call.h>
#include <evm/types.h>
#include <evm/account_state.h>

#include <eos_external.hpp>
#include <eos_system.hpp>

class eos_execute {
  public:
    static call_result_t transaction(transaction_t& transaction, bytes_t& callerAddress) {
      eos_external external {};
      AccountState accountState(&external);
      Call call(0);
      env_t env = eos_system::env();
      call_result_t result = call.execute(
        transaction,
        callerAddress,
        env,
        external,
        accountState
      );
      return result;
    }
};
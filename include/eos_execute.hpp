#pragma once
#include <evm/call.h>
#include <evm/types.h>
#include <evm/account_state.h>

#include <eos_external.hpp>
#include <eos_system.hpp>

class eos_execute {
  public:
    static call_result_t transaction(transaction_t transaction, bytes_t callerAddress) {
      eos_external external {};
      account_store_t* accountItems = new account_store_t();
      AccountState accountState(accountItems, &ext);
      Call call(0);
      call_result_t result = call.execute(
        transaction,
        callerAddress,
        eos_system::env(),
        external,
        accountState
      );
      return result;
    }
};
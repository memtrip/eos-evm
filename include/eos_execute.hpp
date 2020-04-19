#pragma once
#include <memory>
#include <evm/call.h>
#include <evm/types.h>
#include <evm/account_state.hpp>
#include <evm/big_int.hpp>
#include <evm/context.hpp>
#include <evm/overflow.hpp>
#include <evm/external.h>

#include <eos_external.hpp>
#include <eos_system.hpp>

class eos_execute {
  public:
    static call_result_t transaction(
      uint256_t address,
      std::shared_ptr<std::vector<RLPItem>> rlp, 
      std::shared_ptr<bytes_t> data,
      std::shared_ptr<Memory> memory,
      std::shared_ptr<External> external,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<Call> call
    ) {
      env_t env = eos_system::env();

      call_result_t result;

      switch (Transaction::type(rlp)) {
        case TransactionActionType::TRANSACTION_CREATE:
          {
            std::shared_ptr<Context> context = Context::makeCreate(env, address, rlp);
            result = call->create(
              true,
              memory,
              context,
              external,
              accountState
            );
            break;
          }
        case TransactionActionType::TRANSACTION_CALL:
          {
            std::shared_ptr<Context> context = Context::makeCall(env, address, rlp, external);
            result = call->call(
              true,
              memory,
              context,
              external,
              accountState
            );
            break;
        }
      }
      return result;
    }
};
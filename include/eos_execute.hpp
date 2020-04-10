#pragma once
#include <memory>
#include <evm/call.h>
#include <evm/types.h>
#include <evm/account_state.h>
#include <evm/big_int.h>
#include <evm/context.h>
#include <evm/overflow.h>
#include <evm/external.h>

#include <eos_external.hpp>
#include <eos_system.hpp>

class eos_execute {
  public:
    static call_result_t transaction(
      uint256_t address,
      std::shared_ptr<std::vector<RLPItem>> rlp, 
      std::shared_ptr<bytes_t> data,
      std::shared_ptr<External> external,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<Call> call
    ) {
      env_t env = eos_system::env();

      call_result_t result;

      switch (Transaction::type(rlp)) {
        case TransactionActionType::TRANSACTION_CREATE:
          {
            std::shared_ptr<Context> context = std::make_shared<Context>(
              env.chainId,
              env.blockNumber,
              env.timestamp,
              env.gasLimit,
              env.coinbase,
              env.difficulty,
              env.blockHash,
              address,
              uint256_t(0),
              uint256_t(0),
              address,
              address,
              uint256_t(0),
              Transaction::gasLimit(rlp),
              Transaction::gasPrice(rlp),
              Transaction::value(rlp),
              data,
              std::shared_ptr<bytes_t>()
            );
            result = call->create(
              true,
              context,
              external,
              accountState
            );
            break;
          }
        case TransactionActionType::TRANSACTION_CALL:
          {
            std::shared_ptr<Context> context = std::make_shared<Context>(
              env.chainId,
              env.blockNumber,
              env.timestamp,
              env.gasLimit,
              env.coinbase,
              env.difficulty,
              env.blockHash,
              address,
              uint256_t(0),
              uint256_t(0),
              address,
              address,
              uint256_t(0),
              Transaction::gasLimit(rlp),
              Transaction::gasPrice(rlp),
              Transaction::value(rlp),
              external->code(address), /* TODO: this should happen in eos_evm.cpp */
              data
            );
            result = call->call(
              true,
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
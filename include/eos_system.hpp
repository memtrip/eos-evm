#pragma once
#include <eosio/system.hpp>
#include <eosio/transaction.hpp>
#include <evm/types.h>

class eos_system {
  public:
    static uint64_t timestamp() {
      return eosio::current_block_time().to_time_point().time_since_epoch().count();
    }

    static uint64_t block_num() {
      return eosio::tapos_block_num();
    }

    static env_t env() {
      return {
        block_num(), /* blockNumber */
        timestamp(), /* timestamp */
        21000, /* gasLimit */
        1 /* chainId */
      };
    }
};
#pragma once
#include <eosio/system.hpp>
#include <eosio/transaction.hpp>
#include <evm/types.h>

class eos_system {
  public:
    static uint256_t timestamp() {
      return uint256_t(eosio::current_block_time().to_time_point().time_since_epoch().count());
    }

    static uint256_t block_num() {
      return uint256_t(eosio::tapos_block_num());
    }

    static env_t env() {
      return {
        uint256_t(0),
        block_num(), /* blockNumber */
        timestamp(), /* timestamp */
        uint256_t(10000000), /* gasLimit */
        uint256_t(0), /* coinbase */
        uint256_t(0), /* difficulty */
        uint256_t(0) /* blockHash */
      };
    }
};
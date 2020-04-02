#pragma once
#include <eosio/system.hpp>
#include <eosio/transaction.hpp>
#include <evm/types.h>

class eos_system {
  public:
    static env_t env() {
      return {
        uint256_t(0),
        uint256_t(eosio::tapos_block_num()), /* blockNumber */
        uint256_t(eosio::current_block_time().to_time_point().time_since_epoch().count()), /* timestamp */
        uint256_t(10000000), /* gasLimit */
        uint256_t(0), /* coinbase */
        uint256_t(0), /* difficulty */
        uint256_t(0) /* blockHash */
      };
    }
};
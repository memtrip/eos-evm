#pragma once
#include <eosio/system.hpp>
#include <eosio/transaction.hpp>

class eos_system {
  public:
    static uint64_t timestamp() {
      return eosio::current_block_time().to_time_point().time_since_epoch().count();
    }

    static uint64_t block_num() {
      return eosio::tapos_block_num();
    }
};
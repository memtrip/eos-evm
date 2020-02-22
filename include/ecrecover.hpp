#pragma once
#include <eosio/system.hpp>
#include <eosio/transaction.hpp>
#include <evm/types.h>

class ecrecover {
  public:
    static string recover(bytes_t signature, bytes_t digest) {
      return "d1c81da825345ebe56e5d49107d10cd0738036ec";
    }
};
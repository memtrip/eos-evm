#include <stdio.h>
#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>

TEST_CASE("Address", "[params]") {
  // given
  // (ADDRESS 30)
  std::string bytecode_str = "30";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str));
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, params, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9a" == Utils::uint256_2str(sm.top()));
}

TEST_CASE("Origin", "[params]") {
  // given
  // (ORIGIN 32)
  std::string bytecode_str = "32";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str));
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, params, Utils::env());

  // then
  CHECK("00000000000000000000000000000000000000000000000000000000001283fe" == Utils::uint256_2str(sm.top()));
}

TEST_CASE("Caller", "[params]") {
  // given
  // (CALLER 33)
  std::string bytecode_str = "33";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str));
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, params, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9e" == Utils::uint256_2str(sm.top()));
}
#include <stdio.h>
#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>

TEST_CASE("shift left ", "[shift]") {
  std::string bytecode_str = "600560011b6000526001601ff3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str));
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  mem.resize(32);
  vm.execute(mem, sm, as, params, Utils::env());

  // then
  // TODO: assert against return data
}

TEST_CASE("shift right ", "[shift]") {
  std::string bytecode_str = "600560011c6000526001601ff3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str));
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  mem.resize(32);
  vm.execute(mem, sm, as, params, Utils::env());

  // then
  // TODO: assert against return data
}

TEST_CASE("sar", "[shift]") {
  std::string bytecode_str = "600160000360021d60005260016000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str));
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  mem.resize(32);
  vm.execute(mem, sm, as, params, Utils::env());

  // then
  // TODO: assert against return data
}
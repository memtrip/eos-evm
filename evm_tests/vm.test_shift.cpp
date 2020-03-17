#include <stdio.h>
#include <variant>
#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

TEST_CASE("shift left ", "[shift]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60ff1b";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  REQUIRE("8000000000000000000000000000000000000000000000000000000000000000" 
    == Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("shift left (2)", "[shift]") {
  std::string bytecode_str = "7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60011b";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  REQUIRE("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" 
    == Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("shift left (3)", "[shift]") {
  std::string bytecode_str = "600560011b";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  REQUIRE("000000000000000000000000000000000000000000000000000000000000000a" 
    == Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("shift right ", "[shift]") {
  std::string bytecode_str = "7f800000000000000000000000000000000000000000000000000000000000000060011c";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  REQUIRE("4000000000000000000000000000000000000000000000000000000000000000" 
    == Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("shift right (1)", "[shift]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60011c";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  REQUIRE("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" 
    == Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("shift right (2)", "[shift]") {
  std::string bytecode_str = "600560011c";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  REQUIRE("0000000000000000000000000000000000000000000000000000000000000002" == Utils::uint256_2str(sm.top()));
}

TEST_CASE("sar", "[shift]") {
  std::string bytecode_str = "7f800000000000000000000000000000000000000000000000000000000000000060011d";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  mem.resize(32);
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  REQUIRE("c000000000000000000000000000000000000000000000000000000000000000" 
    == Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("sar (1)", "[shift]") {
  std::string bytecode_str = "7f400000000000000000000000000000000000000000000000000000000000000060fe1d";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  mem.resize(32);
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  REQUIRE("0000000000000000000000000000000000000000000000000000000000000001" 
    == Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("sar (2)", "[shift]") {
  std::string bytecode_str = "7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60f81d";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  mem.resize(32);
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  REQUIRE("000000000000000000000000000000000000000000000000000000000000007f" 
    == Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("sar (3)", "[shift]") {
  std::string bytecode_str = "600160000360021d";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  mem.resize(32);
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  REQUIRE("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" == Utils::uint256_2str(sm.top())
  );
}
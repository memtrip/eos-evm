#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

TEST_CASE("Blockhash (stub)", "[env]") {
  // given
  // (PUSH1 ((60)00))
  // (BLOCKHASH 40)
  std::string bytecode_str = "600040";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(StackMachine::STUB == sm.top());
}

TEST_CASE("Coinbase (stub)", "[env]") {
  // given
  // (COINBASE 41)
  std::string bytecode_str = "41";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(StackMachine::STUB == sm.top());
}

TEST_CASE("Difficulty (stub)", "[env]") {
  // given
  // (DIFFICULTY 44)
  std::string bytecode_str = "44";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(StackMachine::STUB == sm.top());
}

TEST_CASE("Timestamp", "[env]") {
  // given
  // (TIMESTAMP 42)
  std::string bytecode_str = "42";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(1581632422128 == sm.top());
}

TEST_CASE("Number", "[env]") {
  // given
  // (NUMBER 43)
  std::string bytecode_str = "43";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(16339169 == sm.top());
}

TEST_CASE("Gas limit", "[env]") {
  // given
  // (GASLIMIT 45)
  std::string bytecode_str = "45";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(100000 == sm.top());
}

TEST_CASE("Chain id", "[env]") {
  // given
  // (CHAINID 45)
  std::string bytecode_str = "46";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(1 == sm.top());
}

TEST_CASE("Call value", "[env]") {
  // given
  // (CALLVALUE 34)
  std::string bytecode_str = "34";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(34 == sm.top());
}
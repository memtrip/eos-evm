#include <stdio.h>
#include "catch.hpp"
#include "utils.h"
#include "vm.h"

TEST_CASE("Blockhash", "[stub]") {
  // given
  // (PUSH1 ((60)00))
  // (BLOCKHASH 40)
  std::string bytecode_str = "600040";
  bytes_t bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK(StackMachine::STUB == sm.top());
}

TEST_CASE("Coinbase", "[stub]") {
  // given
  // (COINBASE 41)
  std::string bytecode_str = "41";
  bytes_t bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK(StackMachine::STUB == sm.top());
}

TEST_CASE("Difficulty", "[env]") {
  // given
  // (DIFFICULTY 44)
  std::string bytecode_str = "44";
  bytes_t bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK(StackMachine::STUB == sm.top());
}

TEST_CASE("Timestamp", "[env]") {
  // given
  // (TIMESTAMP 42)
  std::string bytecode_str = "42";
  bytes_t bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK(1581632422128 == sm.top());
}

TEST_CASE("Number", "[env]") {
  // given
  // (NUMBER 43)
  std::string bytecode_str = "43";
  bytes_t bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK(16339169 == sm.top());
}

TEST_CASE("Gas limit", "[env]") {
  // given
  // (GASLIMIT 45)
  std::string bytecode_str = "45";
  bytes_t bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK(100000 == sm.top());
}

TEST_CASE("Chain id", "[env]") {
  // given
  // (CHAINID 45)
  std::string bytecode_str = "46";
  bytes_t bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK(1 == sm.top());
}
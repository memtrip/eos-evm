#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

TEST_CASE("Push1", "[push]") {
  // given
  // (PUSH1 ((60)06))
	// (PUSH1 ((60)03))
  // (ADD (01))
  std::string bytecode_str = "6006600301";
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000009" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Push2", "[push]") {
  // given
  // (PUSH2 ((61)AB00))
	// (PUSH2 ((61)AC00))
  // (ADD (01))
  std::string bytecode_str = "61AB0061AC0001";
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
  CHECK("0000000000000000000000000000000000000000000000000000000000015700" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Push3", "[push]") {
  // given
  // (PUSH3 ((62)AB00EF))
	// (PUSH3 ((62)AC00EF))
  // (ADD (01))
  std::string bytecode_str = "62AB00EF62AC00EF01";
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
  CHECK("00000000000000000000000000000000000000000000000000000000015701de" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Push4", "[push]") {
  // given
  // (PUSH4 ((63)12345678))
	// (PUSH4 ((63)12345300))
  // (ADD (01))
  std::string bytecode_str = "6312345678631234530001";
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
  CHECK("000000000000000000000000000000000000000000000000000000002468a978" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Push5", "[push]") {
  // given
  // (PUSH5 ((64)1234567812))
	// (PUSH5 ((64)1234530012))
  // (ADD (01))
  std::string bytecode_str = "64123456781264123453001201";
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
  CHECK("0000000000000000000000000000000000000000000000000000002468a97824" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Push6", "[push]") {
  // given
  // (PUSH6 ((65)123456781234))
	// (PUSH6 ((65)123453001234))
  // (ADD (01))
  std::string bytecode_str = "651234567812346512345300123401";
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
  CHECK("00000000000000000000000000000000000000000000000000002468a9782468" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Push7", "[push]") {
  // given
  // (PUSH7 ((66)10000000000012))
	// (PUSH7 ((66)10000000000012))
  // (ADD (01))
  std::string bytecode_str = "6610000000000012661000000000001201";
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
  CHECK("0000000000000000000000000000000000000000000000000020000000000024" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Push8", "[push]") {
  // given
  // (PUSH8 ((67)1000000000000012))
	// (PUSH8 ((67)1000000000000012))
  // (ADD (01))
  std::string bytecode_str = "67100000000000001267100000000000001201";
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
  CHECK("0000000000000000000000000000000000000000000000002000000000000024" == 
    Utils::uint256_2str(sm.top())
  );
}
#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

TEST_CASE("Save to memory", "[memory]") {
  // given
  // (PUSH1 ((60)06))
  // (PUSH1 ((60)00))
  // (MSTORE (52))
  std::string bytecode_str = "6006600052";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  ReturnData returnData = ReturnData::empty();
  Call call {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  mem.resize(32); // TODO: this should happen via requirements (memoryRequiredSize)
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000006" == 
    Utils::uint256_2str(mem.read(uint256_t(0x00)))
  );
}

TEST_CASE("Save to memory, and retreive", "[memory]") {
  // given
  // (PUSH1 ((60)06))
  // (PUSH1 ((60)00))
  // (MSTORE (52))
  // (PUSH1 ((60)00))
  // (MLOAD (51))
  std::string bytecode_str = "6006600052600051";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  ReturnData returnData = ReturnData::empty();
  Call call {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  mem.resize(32); // TODO: this should happen via requirements (memoryRequiredSize)
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000006" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Save to memory, retreive, and apply addition", "[memory]") {
  // given
  // (PUSH1 ((60)06))
	// (PUSH1 ((60)00))
  // (MSTORE (52))
  // (PUSH1 ((60)12))
  // (MLOAD (51))
  // (ADD (01))
  std::string bytecode_str = "6006600052601260005101";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  ReturnData returnData = ReturnData::empty();
  Call call {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  mem.resize(32); // TODO: this should happen via requirements (memoryRequiredSize)
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000018" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Save byte to memory, retreive, and apply addition", "[memory]") {
  // given
  // (PUSH1 ((60)06))
	// (PUSH1 ((60)00))
  // (MSTORE8 (53))
  // (PUSH1 ((60)12))
  // (PUSH1 ((60)00))
  // (MLOAD (51))
  // (ADD (01))
  std::string bytecode_str = "6006601F53601260005101";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  ReturnData returnData = ReturnData::empty();
  Call call {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  mem.resize(32); // TODO: this should happen via requirements (memoryRequiredSize)
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000018" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Save byte to memory (1)", "[memory]") {
  // given
  // (PUSH1 ((60)06))
	// (PUSH1 ((60)00))
  // (MSTORE8 (53))
  // (PUSH1 ((60)12))
  // (PUSH1 ((60)00))
  // (MLOAD (51))
  // (ADD (01))
  std::string bytecode_str = "6006601F53601260005101";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  ReturnData returnData = ReturnData::empty();
  Call call {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  mem.resize(32); // TODO: this should happen via requirements (memoryRequiredSize)
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000018" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Memory size", "[memory]") {
  // given
  // (MEMSIZE (59))
  std::string bytecode_str = "59";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  ReturnData returnData = ReturnData::empty();
  Call call {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  mem.resize(32); // TODO: this should happen via requirements (memoryRequiredSize)
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000020" /* 32 in hex */ == 
    Utils::uint256_2str(sm.top())
  );
}


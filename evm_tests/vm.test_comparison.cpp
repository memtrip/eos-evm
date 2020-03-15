#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

TEST_CASE("Less than comparison truthy", "[LT]") {
  // given
  // (PUSH1 ((60) 03))
	// (PUSH1 ((60) 01))
	// (LT (10))
  std::string bytecode_str = "6003600110";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Less than comparison not true", "[LT]") {
  // given
  // (PUSH1 ((60) 01))
	// (PUSH1 ((60) 03))
	// (LT (10))
  std::string bytecode_str = "6001600310";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Greater than comparison truthy", "[GT]") {
  // given
  // (PUSH1 ((60) 01))
	// (PUSH1 ((60) 03))
	// (GT (11))
  std::string bytecode_str = "6001600311";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Greater than comparison not true", "[GT]") {
  // given
  // (PUSH1 ((60) 03))
	// (PUSH1 ((60) 01))
	// (GT (11))
  std::string bytecode_str = "6003600111";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Equal comparison truthy", "[EQ]") {
  // given
  // (PUSH1 ((60) 03))
	// (PUSH1 ((60) 03))
	// (EQ (14))
  std::string bytecode_str = "6003600314";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Equal comparison not true", "[EQ]") {
  // given
  // (PUSH1 ((60) 03))
	// (PUSH1 ((60) 01))
	// (EQ (14))
  std::string bytecode_str = "6003600114";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Is zero comparison truthy", "[ISZERO]") {
  // given
  // (PUSH1 ((60) 00))
	// (ISZERO (15))
  std::string bytecode_str = "600015";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Is zero comparison not true", "[ISZERO]") {
  // given
  // (PUSH1 ((60) 01))
	// (ISZERO (15))
  std::string bytecode_str = "600115";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Comparison with many instructions", "[comparison]") {
  std::string bytecode_str = "601665012365124623818181811060005511600155146002556415235412358014600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);
  store_item_t item3 = Utils::accountStoreValue(2, accountItems);
  store_item_t item4 = Utils::accountStoreValue(3, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item1.second)
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(item2.second)
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item3.second)
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(item4.second)
  );
}
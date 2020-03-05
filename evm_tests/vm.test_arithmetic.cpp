#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

TEST_CASE("Add two large numbers", "[arithmetic]") {
  // given
  // (PUSH32 ((7f)fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff))
	// (PUSH32 ((7f)fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff))
	// (ADD (01))
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01";
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
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Multiply two numbers", "[arithmetic]") {
  // given
  // (PUSH1 ((60)03))
	// (PUSH1 ((60)03))
	// (MUL (02))
  std::string bytecode_str = "6003600302";
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
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000009" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Multiply two larger numbers", "[arithmetic]") {
  // given
  // (PUSH2 ((61)0A10))
	// (PUSH2 ((61)0B12))
	// (MUL (02))
  std::string bytecode_str = "6016601602";
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
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  CHECK("00000000000000000000000000000000000000000000000000000000000001e4" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Multiply and store", "[arithmetic]") {
  // given
  // (PUSH6 ((65) 012365124623))
	// (PUSH3 ((62) 654321))
	// (SWAP1 90)
  // (MUL 02)
  // (PUSH1 ((60) 00))
  // (SSTORE 55)
  std::string bytecode_str = "65012365124623626543219002600055";
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
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  store_item_t item = Utils::accountStoreValue(0, accountItems);

  CHECK("000000000000000000000000000000000000000000000000734349397b853383" == 
    Utils::uint256_2str(item.second)
  );
}

TEST_CASE("Subtract two numbers", "[arithmetic]") {
  // given
  // (PUSH1 ((60)03))
	// (PUSH1 ((60)05))
	// (SUB (03))
  std::string bytecode_str = "6003600503";
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
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Subtract and store", "[arithmetic]") {
  // given
  // (PUSH6 ((65)012365124623))
	// (PUSH3 ((62)654321))
  // (SWAP1 90)
  // (SUB 03)
	// (PUSH1 (60)00)
  // (SSTORE 55)
  std::string bytecode_str = "65012365124623626543219003600055";
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
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  store_item_t item = Utils::accountStoreValue(0, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000012364ad0302" == 
    Utils::uint256_2str(item.second)
  );
}

TEST_CASE("Divide two numbers", "[arithmetic]") {
  // given
  // (PUSH1 ((60)02))
	// (PUSH1 ((60)04))
	// (DIV (04))
  std::string bytecode_str = "6002600404";
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
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Divide 2 / 0", "[arithmetic]") {
  // given
  // (PUSH1 ((60)00))
	// (PUSH1 ((60)02))
	// (DIV (04))
  std::string bytecode_str = "6000600204";
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
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Divide and store", "[arithmetic]") {
  // given
  // (PUSH6 ((65)012365124623))
	// (PUSH3 ((62)654321))
  // (SWAP1 (90))
  // (DIV (04))
	// (PUSH1 (60)00)
  // (SSTORE 55)
  std::string bytecode_str = "65012365124623626543219004600055";
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
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  store_item_t item = Utils::accountStoreValue(0, accountItems);

  CHECK("000000000000000000000000000000000000000000000000000000000002e0ac" == 
    Utils::uint256_2str(item.second)
  );
}

TEST_CASE("Divide by zero and store", "[arithmetic]") {
  // given
  // (PUSH6 ((65)012365124623))
	// (PUSH1 ((60)00))
  // (SWAP1 (90))
  // (DIV (04))
	// (PUSH1 (60)00)
  // (SSTORE 55)
  std::string bytecode_str = "6501236512462360009004600055";
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
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  store_item_t item = Utils::accountStoreValue(0, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item.second)
  );
}

TEST_CASE("Mod and store", "[arithmetic]") {
  std::string bytecode_str = "650123651246236265432290066000556501236512462360009006600155";
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
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000076b4b" == 
    Utils::uint256_2str(item1.second)
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item2.second)
  );
}


TEST_CASE("Modulus 8 % 2", "[arithmetic]") {
  // given
  // (PUSH1 ((60)02))
	// (PUSH1 ((60)08))
	// (MOD (06))
  std::string bytecode_str = "6002600806";
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
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Modulus 5 % 2", "[arithmetic]") {
  // given
  // (PUSH1 ((60)05))
	// (PUSH1 ((60)02))
	// (MOD (06))
  std::string bytecode_str = "6002600506";
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
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Modulus 2 % 0", "[arithmetic]") {
  // given
  // (PUSH1 ((60)02))
	// (PUSH1 ((60)00))
	// (MOD (06))
  std::string bytecode_str = "6000600206";
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
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Byte", "[arithmetic]") {
  std::string bytecode_str = "60f061ffff1a600055610fff601f1a600155";
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
  vm.execute(mem, sm, as, gasometer, params, ext, returnData, call, Utils::env());

  // then
  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item1.second)
  );

  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" == 
    Utils::uint256_2str(item2.second)
  );
}
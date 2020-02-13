#include <stdio.h>
#include "catch.hpp"
#include "utils.h"
#include "vm.h"

TEST_CASE("Add two large numbers", "[ADD]") {
  // given
  // (PUSH32 ((7f)fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff))
	// (PUSH32 ((7f)fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff))
	// (ADD (01))
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Multiply two numbers", "[MUL]") {
  // given
  // (PUSH1 ((60)03))
	// (PUSH1 ((60)03))
	// (MUL (02))
  std::string bytecode_str = "6003600302";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("9" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Multiply two larger numbers", "[MUL]") {
  // given
  // (PUSH2 ((61)0A10))
	// (PUSH2 ((61)0B12))
	// (MUL (02))
  std::string bytecode_str = "6016601602";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("1e4" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Multiply and store", "[MUL]") {
  // given
  // (PUSH6 ((65) 012365124623))
	// (PUSH3 ((62) 654321))
	// (SWAP1 90)
  // (MUL 02)
  // (PUSH1 ((60) 00))
  // (SSTORE 55)
  std::string bytecode_str = "65012365124623626543219002600055";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  store_item_t item = Utils::accountStoreValue(0, accountItems);

  CHECK("734349397b853383" == 
    Utils::uint256_2str(item.second)
  );
}

TEST_CASE("Subtract two numbers", "[SUB]") {
  // given
  // (PUSH1 ((60)03))
	// (PUSH1 ((60)05))
	// (SUB (03))
  std::string bytecode_str = "6003600503";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("2" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Subtract and store", "[SUB]") {
  // given
  // (PUSH6 ((65)012365124623))
	// (PUSH3 ((62)654321))
  // (SWAP1 90)
  // (SUB 03)
	// (PUSH1 (60)00)
  // (SSTORE 55)
  std::string bytecode_str = "65012365124623626543219003600055";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  store_item_t item = Utils::accountStoreValue(0, accountItems);

  CHECK("12364ad0302" == 
    Utils::uint256_2str(item.second)
  );
}

TEST_CASE("Divide two numbers", "[DIV]") {
  // given
  // (PUSH1 ((60)02))
	// (PUSH1 ((60)04))
	// (DIV (04))
  std::string bytecode_str = "6002600404";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("2" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Divide 2 / 0", "[DIV]") {
  // given
  // (PUSH1 ((60)00))
	// (PUSH1 ((60)02))
	// (DIV (04))
  std::string bytecode_str = "6000600204";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("0" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Divide and store", "[DIV]") {
  // given
  // (PUSH6 ((65)012365124623))
	// (PUSH3 ((62)654321))
  // (SWAP1 (90))
  // (DIV (04))
	// (PUSH1 (60)00)
  // (SSTORE 55)
  std::string bytecode_str = "65012365124623626543219004600055";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  store_item_t item = Utils::accountStoreValue(0, accountItems);

  CHECK("2e0ac" == 
    Utils::uint256_2str(item.second)
  );
}

TEST_CASE("Divide by zero and store", "[DIV]") {
  // given
  // (PUSH6 ((65)012365124623))
	// (PUSH1 ((60)00))
  // (SWAP1 (90))
  // (DIV (04))
	// (PUSH1 (60)00)
  // (SSTORE 55)
  std::string bytecode_str = "6501236512462360009004600055";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  store_item_t item = Utils::accountStoreValue(0, accountItems);

  CHECK("0" == 
    Utils::uint256_2str(item.second)
  );
}

TEST_CASE("Mod and store", "[MOD]") {
  std::string bytecode_str = "650123651246236265432290066000556501236512462360009006600155";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);

  CHECK("76b4b" == 
    Utils::uint256_2str(item1.second)
  );

  CHECK("0" == 
    Utils::uint256_2str(item2.second)
  );
}


TEST_CASE("Modulus 8 % 2", "[MOD]") {
  // given
  // (PUSH1 ((60)02))
	// (PUSH1 ((60)08))
	// (MOD (06))
  std::string bytecode_str = "6002600806";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("0" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Modulus 5 % 2", "[MOD]") {
  // given
  // (PUSH1 ((60)05))
	// (PUSH1 ((60)02))
	// (MOD (06))
  std::string bytecode_str = "6002600506";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("1" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Modulus 2 % 0", "[MOD]") {
  // given
  // (PUSH1 ((60)02))
	// (PUSH1 ((60)00))
	// (MOD (06))
  std::string bytecode_str = "6000600206";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("0" == 
    Utils::uint256_2str(sm.top())
  );
}
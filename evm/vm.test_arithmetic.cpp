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
  std::map<uint256_t, uint256_t>* accountItems = new std::map<uint256_t,uint256_t>();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as);

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
  std::map<uint256_t, uint256_t>* accountItems = new std::map<uint256_t,uint256_t>();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as);

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
  std::map<uint256_t, uint256_t>* accountItems = new std::map<uint256_t,uint256_t>();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as);

  // then
  CHECK("1e4" == 
    Utils::uint256_2str(sm.top())
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
  std::map<uint256_t, uint256_t>* accountItems = new std::map<uint256_t,uint256_t>();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as);

  // then
  CHECK("2" == 
    Utils::uint256_2str(sm.top())
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
  std::map<uint256_t, uint256_t>* accountItems = new std::map<uint256_t,uint256_t>();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as);

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
  std::map<uint256_t, uint256_t>* accountItems = new std::map<uint256_t,uint256_t>();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as);

  // then
  CHECK("0" == 
    Utils::uint256_2str(sm.top())
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
  std::map<uint256_t, uint256_t>* accountItems = new std::map<uint256_t,uint256_t>();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as);

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
  std::map<uint256_t, uint256_t>* accountItems = new std::map<uint256_t,uint256_t>();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as);

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
  std::map<uint256_t, uint256_t>* accountItems = new std::map<uint256_t,uint256_t>();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as);

  // then
  CHECK("0" == 
    Utils::uint256_2str(sm.top())
  );
}
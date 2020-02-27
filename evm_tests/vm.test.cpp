#include <stdio.h>
#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include "external_mock.h"

TEST_CASE("Duplicate stack item", "[DUP1]") {
  // given
  // (PUSH1 ((60)02))
	// (PUSH1 ((60)03))
	// (DUP1 (80))
  std::string bytecode_str = "6002600380";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str));
  ExternalMock ext {};
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, params, ext, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" == 
    Utils::uint256_2str(sm.top())
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" == 
    Utils::uint256_2str(sm.peek(1))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" == 
    Utils::uint256_2str(sm.peek(2))
  );
}

TEST_CASE("Duplicate stack item at 16", "[DUP1]") {
  // given
  // (PUSH1 ((60)01))
	// (PUSH1 ((60)02))
  // (PUSH1 ((60)03))
	// (PUSH1 ((60)04))
  // (PUSH1 ((60)05))
	// (PUSH1 ((60)06))
  // (PUSH1 ((60)07))
	// (PUSH1 ((60)08))
	// (PUSH1 ((60)09))
  // (PUSH1 ((60)10))
	// (PUSH1 ((60)11))
	// (PUSH1 ((60)12))
  // (PUSH1 ((60)13))
	// (PUSH1 ((60)14))
	// (PUSH1 ((60)15))
  // (PUSH1 ((60)16))
	// (DUP16 (8F))
  std::string bytecode_str = "60016002600360046005600660076008600960106011601260136014601560168F";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str));
  ExternalMock ext {};
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, params, ext, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Swap stack item", "[SWAP1]") {
  // given
  // (PUSH1 ((60)02))
	// (PUSH1 ((60)03))
	// (SWAP1 (90))
  std::string bytecode_str = "6002600390";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str));
  ExternalMock ext {};
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, params, ext, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" == 
    Utils::uint256_2str(sm.top())
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" == 
    Utils::uint256_2str(sm.peek(1))
  );
}

TEST_CASE("Swap stack item at 16", "[SWAP16]") {
  // given
  // (PUSH1 ((60)01))
	// (PUSH1 ((60)02))
  // (PUSH1 ((60)03))
	// (PUSH1 ((60)04))
  // (PUSH1 ((60)05))
	// (PUSH1 ((60)06))
  // (PUSH1 ((60)07))
	// (PUSH1 ((60)08))
	// (PUSH1 ((60)09))
  // (PUSH1 ((60)10))
	// (PUSH1 ((60)11))
	// (PUSH1 ((60)12))
  // (PUSH1 ((60)13))
	// (PUSH1 ((60)14))
	// (PUSH1 ((60)15))
  // (PUSH1 ((60)16))
  // (PUSH1 ((60)17))
	// (SWAP16 (9F))
  std::string bytecode_str = "600160026003600460056006600760086009601060116012601360146015601660179F";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str));
  ExternalMock ext {};
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, params, ext, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(sm.top())
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000017" == 
    Utils::uint256_2str(sm.peek(16))
  );
}

TEST_CASE("Program counter", "[PC]") {
  // given
  // (PUSH1 ((60)01))
	// (PUSH1 ((60)02))
  // (PUSH1 ((60)03))
	// (PUSH1 ((60)04))
  // (PUSH1 ((60)05))
	// (PUSH1 ((60)06))
  // (PUSH1 ((60)07))
  // (PC (58))
  std::string bytecode_str = "600160026003600460056006600758";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str));
  ExternalMock ext {};
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, params, ext, Utils::env());

  // then
  CHECK("000000000000000000000000000000000000000000000000000000000000000e" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Pop", "[POP]") {
  // given
  // (PUSH1 ((60)01))
	// (PUSH1 ((60)02))
  // (PUSH1 ((60)03))
	// (PUSH1 ((60)04))
  // (PUSH1 ((60)05))
	// (PUSH1 ((60)06))
  // (PUSH1 ((60)07))
  // (PC (58))
  std::string bytecode_str = "60f060aa50600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str));
  ExternalMock ext {};
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, params, ext, Utils::env());

  // then
  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("00000000000000000000000000000000000000000000000000000000000000f0" == 
    Utils::uint256_2str(item1.second)
  );
}
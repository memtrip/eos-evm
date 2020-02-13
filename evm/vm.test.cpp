#include <stdio.h>
#include "catch.hpp"
#include "utils.h"
#include "vm.h"

TEST_CASE("Duplicate stack item", "[DUP1]") {
  // given
  // (PUSH1 ((60)02))
	// (PUSH1 ((60)03))
	// (DUP1 (80))
  std::string bytecode_str = "6002600380";
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
  CHECK("3" == 
    Utils::uint256_2str(sm.top())
  );
  CHECK("3" == 
    Utils::uint256_2str(sm.peek(1))
  );
  CHECK("2" == 
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

TEST_CASE("Swap stack item", "[SWAP1]") {
  // given
  // (PUSH1 ((60)02))
	// (PUSH1 ((60)03))
	// (SWAP1 (90))
  std::string bytecode_str = "6002600390";
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
  CHECK("3" == 
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
  CHECK("17" == 
    Utils::uint256_2str(sm.peek(16))
  );
}

// // TEST_CASE("Comparison", "[c]") {
// //   // given
// //   // (PUSH1 ((60)02))
// // 	// (PUSH1 ((60)00))
// // 	// (MOD (06))
// //   std::string bytecode_str = "65012365124623626543219002600055";
// //   char bytecode_array[bytecode_str.length() / 2];
// //   Utils::hex2bin(bytecode_str, bytecode_array);
// //   VM vm {};
// //   std::map<uint256_t, uint256_t>* accountItems = new std::map<uint256_t,uint256_t>();
// //   AccountState as(accountItems);
// //   std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
// //   StackMachine sm(stackItems);

// //   // when
// //   vm.execute(bytes, mem, sm, as);

// //   // then
// //   CHECK("?" == 
// //     Utils::uint256_2str(sm.top())
// //   );
// // }

// // TEST_CASE("Comparison", "[c]") {
// //   // given
// //   // (PUSH1 ((60)02))
// // 	// (PUSH1 ((60)00))
// // 	// (MOD (06))
// //   std::string bytecode_str = "601665012365124623818181811060005511600155146002556415235412358014600355";
// //   char bytecode_array[bytecode_str.length() / 2];
// //   Utils::hex2bin(bytecode_str, bytecode_array);
// //   VM vm {};
// //   std::map<uint256_t, uint256_t>* accountItems = new std::map<uint256_t,uint256_t>();
// //   AccountState as(accountItems);
// //   std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
// //    StackMachine sm(stackItems);

// //   // when
// //   vm.execute(bytes, mem, sm, as);

// //   // then
// //   CHECK("?" == 
// //     Utils::uint256_2str(sm.top())
// //   );
// // }
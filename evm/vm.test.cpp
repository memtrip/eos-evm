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
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};
  AccountState accountState {};
  StackMachine sm {};

  // when
  vm.execute(bytecode_array, sizeof(bytecode_array), sm, accountState);

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
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};
  AccountState accountState {};
  StackMachine sm {};

  // when
  vm.execute(bytecode_array, sizeof(bytecode_array), sm, accountState);

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
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};
  AccountState accountState {};
  StackMachine sm {};

  // when
  vm.execute(bytecode_array, sizeof(bytecode_array), sm, accountState);

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
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};
  AccountState accountState {};
  StackMachine sm {};

  // when
  vm.execute(bytecode_array, sizeof(bytecode_array), sm, accountState);

  // then
  CHECK("1" == 
    Utils::uint256_2str(sm.top())
  );
  CHECK("17" == 
    Utils::uint256_2str(sm.peek(16))
  );
}

// TEST_CASE("Comparison", "[c]") {
//   // given
//   // (PUSH1 ((60)02))
// 	// (PUSH1 ((60)00))
// 	// (MOD (06))
//   std::string bytecode_str = "601665012365124623818181811060005511600155146002556415235412358014600355";
//   char bytecode_array[bytecode_str.length() / 2];
//   Utils::hex2bin(bytecode_str, bytecode_array);
//   VM vm {};
//   AccountState accountState {};
//   StackMachine sm {};

//   // when
//   vm.execute(bytecode_array, sizeof(bytecode_array), sm, accountState);

//   // then
//   CHECK("?" == 
//     Utils::uint256_2str(sm.top())
//   );
// }
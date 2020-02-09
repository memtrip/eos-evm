#include <stdio.h>
#include "catch.hpp"
#include "utils.h"
#include "vm.h"

// TODO: this test should asser that the account store has set values
// TEST_CASE("Jumps", "[jumps]") {
//   // given
//   // (PUSH1 ((60)06))
// 	 // (PUSH1 ((60)03))
//   // (JUMP (56))
// 	 // (MUL (02))
// 	 // (DIV (04))
//   std::string bytecode_str = "600160015560066000555b60016000540380806000551560245760015402600155600a565b";
//   char bytecode_array[bytecode_str.length() / 2];
//   Utils::hex2bin(bytecode_str, bytecode_array);
//   VM vm {};
//   AccountState accountState {};
//   StackMachine sm {};

//   // when
//   vm.execute(bytecode_array, sizeof(bytecode_array), sm, accountState);

//   // then
//   CHECK("2" == 
//     Utils::uint256_2str(sm.top())
//   );
// }

// TEST_CASE("Conditional jump to destination truthy", "[jumps]") {
//   // given
//   // (PUSH1 ((60)06))
// 	// (PUSH1 ((60)03))
//   // (LT (10))
//   // (PUSH1 ((60)03))
//   // (JUMPI (57))
// 	// (MUL (02))
//   // (JUMPDEST (5B))
//   // (PUSH1 ((60)03))
//   // (PUSH1 ((60)02))
//   // (PUSH1 ((60)10))
// 	// (DIV (04))
//   std::string bytecode_str = "6006600310600357025B60036002601004";
//   char bytecode_array[bytecode_str.length() / 2];
//   Utils::hex2bin(bytecode_str, bytecode_array);
//   VM vm {};
//   AccountState accountState {};
//   StackMachine sm {};

//   // when
//   vm.execute(bytecode_array, sizeof(bytecode_array), sm, accountState);

//   // then
//   CHECK("5" == 
//     Utils::uint256_2str(sm.top())
//   );
// }

TEST_CASE("Unconditional jump to destination", "[jumps]") {
  // given
  // (PUSH1 ((60)03))
	// (PUSH1 ((60)06))
  // (PUSH1 ((60)08))
  // (JUMP (56))
	// (MUL (02))
  // (JUMPDEST (5B))
	// (DIV (04))
  std::string bytecode_str = "60036006600856025B04";
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
}
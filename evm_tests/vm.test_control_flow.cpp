#include <stdio.h>
#include "catch.hpp"
#include "utils.h"
#include "vm.h"

TEST_CASE("Conditional jump to destination truthy", "[jumps]") {
  // given
  // (PUSH1 ((60)06))
	// (PUSH1 ((60)03))
  // (LT (10))
  // (PUSH1 ((60)0F))
  // (JUMPI (57))
  // (PUSH1 ((60)06))
	// (PUSH1 ((60)03))
	// (MUL (02))
  // (STOP (00))
  // (JUMPDEST (5B))
  // (PUSH1 ((60)02))
  // (PUSH1 ((60)10))
	// (DIV (04))
  std::string bytecode_str = "6006600310600F57600660030200025B6002601604";
  bytes_t bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Conditional jump to destination not true", "[jumps]") {
  // given
  // (PUSH1 ((60)03))
	// (PUSH1 ((60)06))
  // (LT (10))
  // (PUSH1 ((60)0F))
  // (JUMPI (57))
  // (PUSH1 ((60)06))
	// (PUSH1 ((60)03))
	// (MUL (02))
  // (STOP (00))
  // (JUMPDEST (5B))
  // (PUSH1 ((60)02))
  // (PUSH1 ((60)10))
	// (DIV (04))
  std::string bytecode_str = "6003600610600F57600660030200025B6002601604";
  bytes_t bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000012" == 
    Utils::uint256_2str(sm.top())
  );
}

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
  bytes_t bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" == 
    Utils::uint256_2str(sm.top())
  );
}

// TODO: uses SLOAD
// TEST_CASE("Jumps", "[jumps]") {
//   std::string bytecode_str = "600160015560066000555b60016000540380806000551560245760015402600155600a565b";
//   bytes_t bytes = Utils::hex2bin(bytecode_str);
//   VM vm {};
//   account_store_t* accountItems = new account_store_t();
//   AccountState as(accountItems);
//   bytes_t* memoryBytes = new bytes_t();
//   Memory mem(memoryBytes);
//   std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
//   StackMachine sm(stackItems);

//   // when
//   vm.execute(bytes, mem, sm, as, Utils::env());

//   // then
//   store_item_t item1 = Utils::accountStoreValue(0, accountItems);
//   store_item_t item2 = Utils::accountStoreValue(1, accountItems);

//   CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
//     Utils::uint256_2str(item1.second)
//   );

//   CHECK("0000000000000000000000000000000000000000000000000000000000000078" == 
//     Utils::uint256_2str(item2.second)
//   );
// }
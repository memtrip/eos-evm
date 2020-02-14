#include <stdio.h>
#include "catch.hpp"
#include "utils.h"
#include "vm.h"

TEST_CASE("Byte", "[signed_]") {
  // std::string bytecode_str = "60f061ffff1a600055610fff601f1a600155";
  // std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  // VM vm {};
  // account_store_t* accountItems = new account_store_t();
  // AccountState as(accountItems);
  // std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  // Memory mem(memoryBytes);
  // std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  // StackMachine sm(stackItems);

  // // when
  // vm.execute(bytes, mem, sm, as, Utils::env());

  // // then
  // store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  // store_item_t item2 = Utils::accountStoreValue(1, accountItems);

  // CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
  //   Utils::uint256_2str(item1.second)
  // );

  // CHECK("00000000000000000000000000000000000000000000000000000000000000ff" == 
  //   Utils::uint256_2str(item2.second)
  // );
}
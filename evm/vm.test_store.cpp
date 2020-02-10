#include <stdio.h>
#include "catch.hpp"
#include "utils.h"
#include "vm.h"

TEST_CASE("Store two values", "[store]") {
  // given
  // (PUSH1 ((60) 01))
	// (PUSH1 ((60) 02))
	// (SSTORE (55))
  std::string bytecode_str = "6001600255";
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};
  std::map<uint256_t, uint256_t>* accountItems = new std::map<uint256_t,uint256_t>();
  AccountState as(accountItems);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  // vm.execute(bytecode_array, sizeof(bytecode_array), sm, as);

  // then
  // CHECK(uint256_t(2) == 
  //   Utils::accountStoreValue(uint256_t(1), accountItems)
  // );
}
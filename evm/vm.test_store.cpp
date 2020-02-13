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
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  std::map<uint256_t, uint256_t>* accountItems = new std::map<uint256_t,uint256_t>();
  AccountState as(accountItems);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  // vm.execute(bytes, sm, as);

  // then
  // CHECK(uint256_t(2) == 
  //   Utils::accountStoreValue(uint256_t(1), accountItems)
  // );
}
#include <stdio.h>
#include "catch.hpp"
#include "utils.h"
#include <evm/vm.h>
#include <evm/hex.h>

TEST_CASE("Hash zero", "[sha3]") {
  // given
  // (PUSH1 ((60) 00))
	// (PUSH1 ((60) 00))
	// (SHA3 (20))
  std::string bytecode_str = "6000600020";
  bytes_t bytes = Hex::hexToBytes(bytecode_str);
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
  REQUIRE("c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470" == 
    Utils::uint256_2str(sm.top())
  );
}
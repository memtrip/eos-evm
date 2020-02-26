#include <stdio.h>
#include "catch.hpp"
#include "utils.h"
#include <evm/vm.h>
#include <evm/hex.h>

TEST_CASE("Store two values", "[store]") {
  // given
  // (PUSH1 ((60) 02))
	// (PUSH1 ((60) 01))
	// (SSTORE (55))
  std::string bytecode_str = "6002600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str));
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, params, Utils::env());

  // then
  store_item_t item = Utils::accountStoreValue(0, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000000002" == 
    Utils::uint256_2str(item.second)
  );
}
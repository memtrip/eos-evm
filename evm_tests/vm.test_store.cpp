#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

TEST_CASE("Store two values", "[store]") {
  // given
  // (PUSH1 ((60) 02))
	// (PUSH1 ((60) 01))
	// (SSTORE (55))
  std::string bytecode_str = "6002600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  store_item_t item = Utils::accountStoreValue(0, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000000002" == 
    Utils::uint256_2str(item.second)
  );
}
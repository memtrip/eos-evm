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
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};
  env_t env = Utils::env();

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" == 
    Utils::uint256_2str(accountState.get(0x01))
  );
}
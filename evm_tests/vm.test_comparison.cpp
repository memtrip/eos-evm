#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

TEST_CASE("Less than comparison truthy", "[LT]") {
  // given
  // (PUSH1 ((60) 03))
	// (PUSH1 ((60) 01))
	// (LT (10))
  std::string bytecode_str = "6003600110";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};
  env_t env = Utils::env();

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(vm.stack.top())
  );
}

TEST_CASE("Less than comparison not true", "[LT]") {
  // given
  // (PUSH1 ((60) 01))
	// (PUSH1 ((60) 03))
	// (LT (10))
  std::string bytecode_str = "6001600310";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};
  env_t env = Utils::env();

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(vm.stack.top())
  );
}

TEST_CASE("Greater than comparison truthy", "[GT]") {
  // given
  // (PUSH1 ((60) 01))
	// (PUSH1 ((60) 03))
	// (GT (11))
  std::string bytecode_str = "6001600311";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};
  env_t env = Utils::env();

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(vm.stack.top())
  );
}

TEST_CASE("Greater than comparison not true", "[GT]") {
  // given
  // (PUSH1 ((60) 03))
	// (PUSH1 ((60) 01))
	// (GT (11))
  std::string bytecode_str = "6003600111";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};
  env_t env = Utils::env();

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(vm.stack.top())
  );
}

TEST_CASE("Equal comparison truthy", "[EQ]") {
  // given
  // (PUSH1 ((60) 03))
	// (PUSH1 ((60) 03))
	// (EQ (14))
  std::string bytecode_str = "6003600314";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};
  env_t env = Utils::env();

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(vm.stack.top())
  );
}

TEST_CASE("Equal comparison not true", "[EQ]") {
  // given
  // (PUSH1 ((60) 03))
	// (PUSH1 ((60) 01))
	// (EQ (14))
  std::string bytecode_str = "6003600114";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};
  env_t env = Utils::env();

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(vm.stack.top())
  );
}

TEST_CASE("Is zero comparison truthy", "[ISZERO]") {
  // given
  // (PUSH1 ((60) 00))
	// (ISZERO (15))
  std::string bytecode_str = "600015";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};
  env_t env = Utils::env();

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(vm.stack.top())
  );
}

TEST_CASE("Is zero comparison not true", "[ISZERO]") {
  // given
  // (PUSH1 ((60) 01))
	// (ISZERO (15))
  std::string bytecode_str = "600115";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};
  env_t env = Utils::env();

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(vm.stack.top())
  );
}

TEST_CASE("Comparison with many instructions", "[comparison]") {
  std::string bytecode_str = "601665012365124623818181811060005511600155146002556415235412358014600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};
  env_t env = Utils::env();

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState.get(0x00))
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(accountState.get(0x01))
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState.get(0x02))
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(accountState.get(0x03))
  );
}
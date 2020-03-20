#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

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
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" == 
    Utils::uint256_2str(vm.stack.top())
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000012" == 
    Utils::uint256_2str(vm.stack.top())
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" == 
    Utils::uint256_2str(vm.stack.top())
  );
}

TEST_CASE("Jumps", "[jumps]") {
  std::string bytecode_str = "600160015560066000555b60016000540380806000551560245760015402600155600a565b";
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

  CHECK("0000000000000000000000000000000000000000000000000000000000000078" == 
    Utils::uint256_2str(accountState.get(0x01))
  );
}
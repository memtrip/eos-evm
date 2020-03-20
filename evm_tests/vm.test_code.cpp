#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

TEST_CASE("extcodesize and extcodecopy", "[code]") {

  std::string bytecode_str = "333b60006000333c600051600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  ext.codeResponder.push_back(std::make_pair(uint256_t(0xea0e9e), Hex::hexToBytes("6005600055")));
  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};
  env_t env = Utils::env();

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("6005600055000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState.get(0x00))
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9e" ==
    Utils::uint256_2str(ext.codeSpy[0])
  );
}

TEST_CASE("codesize", "[code]") {

  std::string bytecode_str = "7f000000000000000000000000000000000000000000000000000000000000000138";
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000022" == 
    Utils::uint256_2str(vm.stack.top())
  );
}

TEST_CASE("calldataload", "[code]") {

  std::string bytecode_str = "600135600055";
  std::string calldata_str = "0123ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), Hex::hexToBytes(calldata_str));
  ExternalMock ext {};
  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};
  env_t env = Utils::env();

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("23ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23" == 
    Utils::uint256_2str(accountState.get(0x00))
  );
}
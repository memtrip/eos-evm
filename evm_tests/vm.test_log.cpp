#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include "external_mock.h"

TEST_CASE("Log address", "[log]") {
  // given
  std::string bytecode_str = "60006000a0";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str));
  ExternalMock ext {};
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, params, ext, Utils::env());

  // then
  CHECK(1 == ext.logSpy.size());
  CHECK(0 == ext.logSpy[0].first.size());
  CHECK(0 == ext.logSpy[0].second.size());
}

TEST_CASE("Log sender", "[log]") {
  // given
  std::string bytecode_str = "60ff6000533360206000a1";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str));
  ExternalMock ext {};
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, params, ext, Utils::env());

  // then
  CHECK(1 == ext.logSpy.size());
  CHECK(1 == ext.logSpy[0].first.size());
  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9e" == 
    Utils::uint256_2str(ext.logSpy[0].first[0])
  );
  CHECK("ff00000000000000000000000000000000000000000000000000000000000000" == 
    Hex::bytesToHex(ext.logSpy[0].second)
  );
}
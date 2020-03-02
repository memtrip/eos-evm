#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include "external_mock.h"

TEST_CASE("extcodesize and extcodecopy", "[code]") {

  std::string bytecode_str = "333b60006000333c600051600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  ext.codeResponse = Hex::hexToBytes("6005600055");
  VM vm {};
  ReturnData returnData = ReturnData::empty();
  Call call {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, params, ext, returnData, call, Utils::env());

  // then
  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("6005600055000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item1.second)
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9e" ==
    Utils::uint256_2str(ext.codeSpy[0])
  );
}

TEST_CASE("codesize", "[code]") {

  std::string bytecode_str = "7f000000000000000000000000000000000000000000000000000000000000000138";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  ReturnData returnData = ReturnData::empty();
  Call call {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, params, ext, returnData, call, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000022" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("calldataload", "[code]") {

  std::string bytecode_str = "600135600055";
  std::string calldata_str = "0123ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), Hex::hexToBytes(calldata_str));
  ExternalMock ext {};
  VM vm {};
  ReturnData returnData = ReturnData::empty();
  Call call {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, params, ext, returnData, call, Utils::env());

  // then
  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("23ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23" == 
    Utils::uint256_2str(item1.second)
  );
}
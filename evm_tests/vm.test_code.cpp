#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include "external_mock.h"

TEST_CASE("extcodecopy", "[code]") {

  std::string bytecode_str = "333b60006000333c600051600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str));
  ExternalMock ext {};
  ext.codeResponse = Hex::hexToBytes("6005600055");
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
  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("6005600055000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item1.second)
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9e" ==
    Utils::uint256_2str(ext.codeSpy[0])
  );
}
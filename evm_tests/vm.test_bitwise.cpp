#include <stdio.h>
#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include "external_mock.h"

TEST_CASE("Bitwise AND", "[bitwise]") {
  // (PUSH1 ((60)03))
  // (PUSH1 ((60)09))
  // (AND (16))
  std::string bytecode_str = "6003600916";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Bitwise OR", "[bitwise]") {
  // (PUSH1 ((60)02))
  // (PUSH1 ((60)04))
  // (AND (17))
  std::string bytecode_str = "6002600417";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000006" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Bitwise XOR", "[bitwise]") {
  // (PUSH1 ((60)02))
  // (PUSH1 ((60)07))
  // (XOR (18))
  std::string bytecode_str = "6002600718";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000005" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Bitops", "[bitwise]") {
  std::string bytecode_str = "60ff610ff08181818116600055176001551860025560008015600355198015600455600555";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
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

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);
  store_item_t item3 = Utils::accountStoreValue(2, accountItems);
  store_item_t item4 = Utils::accountStoreValue(3, accountItems);
  store_item_t item5 = Utils::accountStoreValue(4, accountItems);
  store_item_t item6 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("00000000000000000000000000000000000000000000000000000000000000f0" == Utils::uint256_2str(item1.second));
  CHECK("0000000000000000000000000000000000000000000000000000000000000fff" == Utils::uint256_2str(item2.second));
  CHECK("0000000000000000000000000000000000000000000000000000000000000f0f" == Utils::uint256_2str(item3.second));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == Utils::uint256_2str(item4.second));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == Utils::uint256_2str(item5.second));
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" == Utils::uint256_2str(item6.second));
}
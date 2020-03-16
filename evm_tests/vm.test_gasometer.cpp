#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include <evm/big_int.h>
#include "external_mock.h"

TEST_CASE("Add two large numbers, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(79988 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" == 
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("Store the result of an SHA3 hash, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "6000600020600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(79961 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470" == 
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("Address, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "30600055";
  params_t params = {
    uint256_t(0xea0e9f), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    uint256_t(0xea0e9e), /* sender */
    uint256_t(0x1283fe), /* origin */
    100000, /* gas */
    uint256_t(0), /* gasPrice */
    uint256_t(0), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    bytes_t() /* data */
  };
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(79995 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("0000000000000000000000000f572e5295c57f15886f9b263e2f6d2d6c7b5ec6" == 
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("Origin, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "32600055";
  params_t params = {
    uint256_t(0xea0e9f), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    uint256_t(0xea0e9e), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f2947def4cf144679da39c4c32bdc35681")), /* origin */
    100000, /* gas */
    uint256_t(0), /* gasPrice */
    uint256_t(0), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    bytes_t() /* data */
  };
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(79995 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("000000000000000000000000cd1722f2947def4cf144679da39c4c32bdc35681" == 
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("Self balance, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "4760ff55";
  uint256_t address = BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"));
  params_t params = {
    uint256_t(0xea0e9f), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    address, /* address */
    uint256_t(0xea0e9e), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* origin */
    100000, /* gas */
    uint256_t(0), /* gasPrice */
    uint256_t(0), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    bytes_t() /* data */
  };
  ExternalMock ext {};
  ext.balanceResponder.push_back(std::make_pair(address, 1025.0));

  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(79992 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000000401" == 
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("Sender, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "33600055";
  params_t params = {
    uint256_t(0xea0e9f), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f2947def4cf144679da39c4c32bdc35681")), /* sender */
    uint256_t(0xea0e9e), /* origin */
    100000, /* gas */
    uint256_t(0), /* gasPrice */
    uint256_t(0), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    bytes_t() /* data */
  };
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(79995 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("000000000000000000000000cd1722f2947def4cf144679da39c4c32bdc35681" == 
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("Chain id, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "46600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(79995 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("Extcodecopy verify gas", "[gasometer]") {
  // given
  uint256_t address = BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"));
  uint256_t sender = BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"));
  std::string bytecode_str = "333b60006000333c600051600055";
  params_t params = {
    uint256_t(0xea0e9f), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    address, /* address */
    sender, /* sender */
    uint256_t(0xea0e9e), /* origin */
    100000, /* gas */
    uint256_t(0), /* gasPrice */
    uint256_t(0), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    bytes_t() /* data */
  };

  ExternalMock ext {};
  ext.codeResponder.push_back(std::make_pair(sender, Hex::hexToBytes("6005600055")));

  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(79935 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("6005600055000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item1.second)
  );
}
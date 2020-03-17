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
  AccountState accountState(accountItems, &ext);
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
  AccountState accountState(accountItems, &ext);
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
  AccountState accountState(accountItems, &ext);
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
  AccountState accountState(accountItems, &ext);
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
  AccountState accountState(accountItems, &ext);
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
  AccountState accountState(accountItems, &ext);
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
  AccountState accountState(accountItems, &ext);
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
  uint256_t sender = BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f2947def4cf144679da39c4c32bdc35681"));
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
  AccountState accountState(accountItems, &ext);
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

TEST_CASE("Blockhash, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "600040600055";
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
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(79974 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("f1250fd89a1c3e517ae92cc1f73865c594bfad34db20f3b3396af4efe19d3bfb" == 
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("Calldataload verify gas", "[gasometer]") {
  // given
  uint256_t address = BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"));
  uint256_t sender = BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f2947def4cf144679da39c4c32bdc35681"));
  std::string bytecode_str = "600135600055";
  std::string data_str = "0123ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23";
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
    Hex::hexToBytes(data_str) /* data */
  };
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(79991 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("23ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23" == 
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("Multiply, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "65012365124623626543219002600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(79983 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("000000000000000000000000000000000000000000000000734349397b853383" == 
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("Subtract, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "65012365124623626543219003600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(79985 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000012364ad0302" == 
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("Division, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "65012365124623626543219004600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(79983 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("000000000000000000000000000000000000000000000000000000000002e0ac" == 
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("Div zero, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "6501236512462360009004600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(94983 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("Mod, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "650123651246236265432290066000556501236512462360009006600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(74966 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000076b4b" == 
    Utils::uint256_2str(item1.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("SMOD, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "650123651246236265432290076000556501236512462360009007600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(74966 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000076b4b" == 
    Utils::uint256_2str(item1.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("SDIV, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "650123651246236265432290056000556501236512462360009005600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(74966 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);

  CHECK("000000000000000000000000000000000000000000000000000000000002e0ac" == 
    Utils::uint256_2str(item1.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("Exp, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "6016650123651246230a6000556001650123651246230a6001556000650123651246230a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(39923 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);
  store_item_t item3 = Utils::accountStoreValue(2, accountItems);

  CHECK("90fd23767b60204c3d6fc8aec9e70a42a3f127140879c133a20129a597ed0c59" == 
    Utils::uint256_2str(item1.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000012365124623" == 
    Utils::uint256_2str(item2.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(item3.second)
  );
}

TEST_CASE("Comparison, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "601665012365124623818181811060005511600155146002556415235412358014600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(49952 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);
  store_item_t item3 = Utils::accountStoreValue(2, accountItems);
  store_item_t item4 = Utils::accountStoreValue(3, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item1.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(item2.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item3.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(item4.second)
  );
}

TEST_CASE("Signed comparison, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "60106000036010818112600055136001556010601060000381811260025513600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(49940 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);
  store_item_t item3 = Utils::accountStoreValue(2, accountItems);
  store_item_t item4 = Utils::accountStoreValue(3, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item1.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(item2.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(item3.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item4.second)
  );
}

TEST_CASE("Bitops, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "60ff610ff08181818116600055176001551860025560008015600355198015600455600555";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(44937 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);
  store_item_t item3 = Utils::accountStoreValue(2, accountItems);
  store_item_t item4 = Utils::accountStoreValue(3, accountItems);
  store_item_t item5 = Utils::accountStoreValue(4, accountItems);

  CHECK("00000000000000000000000000000000000000000000000000000000000000f0" == 
    Utils::uint256_2str(item1.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000fff" == 
    Utils::uint256_2str(item2.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000f0f" == 
    Utils::uint256_2str(item3.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(item4.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item4.second)
  );
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" == 
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("Add mod - mul mod, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "60ff60f060108282820860005509600155600060f0601082828208196002550919600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(19914 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);
  store_item_t item3 = Utils::accountStoreValue(2, accountItems);
  store_item_t item4 = Utils::accountStoreValue(3, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(item1.second)
  );
  CHECK("000000000000000000000000000000000000000000000000000000000000000f" == 
    Utils::uint256_2str(item2.second)
  );
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" == 
    Utils::uint256_2str(item3.second)
  );
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" == 
    Utils::uint256_2str(item4.second)
  );
}

TEST_CASE("Byte, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "60f061ffff1a600055610fff601f1a600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(19914 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item1.second)
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" == 
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("Signextend, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "610fff60020b60005560ff60200b600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(59972 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000000fff" == 
    Utils::uint256_2str(item1.second)
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" == 
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("Pop, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "60f060aa50600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(79989 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);

  CHECK("00000000000000000000000000000000000000000000000000000000000000f0" == 
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("Extops, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "5a6001555836553a600255386003553460045560016001526016590454600555";
  params_t params = {
    uint256_t(0xea0e9f), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* sender */
    uint256_t(0xea0e9e), /* origin */
    150000, /* gas */
    uint256_t(0x32), /* gasPrice */
    uint256_t(0x99), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    bytes_t() /* data */
  };
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(29898 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);
  store_item_t item3 = Utils::accountStoreValue(2, accountItems);
  store_item_t item4 = Utils::accountStoreValue(3, accountItems);
  store_item_t item5 = Utils::accountStoreValue(4, accountItems);
  store_item_t item6 = Utils::accountStoreValue(5, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000000004" == 
    Utils::uint256_2str(item1.second)
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000249ee" == 
    Utils::uint256_2str(item2.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000032" == 
    Utils::uint256_2str(item3.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000020" == 
    Utils::uint256_2str(item4.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000099" == 
    Utils::uint256_2str(item5.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000032" == 
    Utils::uint256_2str(item6.second)
  );
}

TEST_CASE("Jumps, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "600160015560066000555b60016000540380806000551560245760015402600155600a565b";
  params_t params = {
    uint256_t(0xea0e9f), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* sender */
    uint256_t(0xea0e9e), /* origin */
    150000, /* gas */
    uint256_t(0x32), /* gasPrice */
    uint256_t(0x99), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    bytes_t() /* data */
  };
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  CHECK(54117 == Utils::gasLeft(result));

  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item1.second)
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000078" == 
    Utils::uint256_2str(item2.second)
  );
}
#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

TEST_CASE("signed division", "[signed]") {
  std::string bytecode_str = "650123651246236265432290056000556501236512462360009005600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);

  CHECK("000000000000000000000000000000000000000000000000000000000002e0ac" == 
    Utils::uint256_2str(item1.second)
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("signed mod", "[signed]") {
  std::string bytecode_str = "650123651246236265432290076000556501236512462360009007600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000076b4b" == 
    Utils::uint256_2str(item1.second)
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("add mod, mul mod", "[signed]") {
  std::string bytecode_str = "60ff60f060108282820860005509600155600060f0601082828208196002550919600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
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

TEST_CASE("exponent", "[signed]") {
  std::string bytecode_str = "6016650123651246230a6000556001650123651246230a6001556000650123651246230a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
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

TEST_CASE("signextend", "[signed]") {
  std::string bytecode_str = "610fff60020b60005560ff60200b600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000000fff" == 
    Utils::uint256_2str(item1.second)
  );

  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" == 
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("signed comparison", "[signed]") {
  std::string bytecode_str = "60106000036010818112600055136001556010601060000381811260025513600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
    Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, Utils::env());

  // then
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
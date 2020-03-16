#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include <evm/big_int.h>
#include "external_mock.h"

TEST_CASE("mloadMemExp______b12ca5b81a2d597d774f63fd3e6301a3808c7090e1b5ee00ea980c846ddadf32", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("00")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01f4153d80")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0100")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "630fffffff51";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* origin */
    gas_t(0x800570), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0de0b6b3a7640000")), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
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
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("mloadOutOfGasError2______8df8c3070849692634e4e7af44885da9c5d41df0717fd6d337aa7d5bfed56d52", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("00")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f4240")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0100")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "6272482551600155";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0de0b6b3a7640000")), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
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
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}


TEST_CASE("jump0_foreverOutOfGas______06656a40346ccda59a2d1852d9bb59447d34fb9eb80706e378c5a067e337a080", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("00")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f4240")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0100")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "5b600056";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0de0b6b3a7640000")), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
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
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("DynamicJump0_foreverOutOfGas______68b687a344b0f44d7459e095f05f6b302ee3f5d15b3c3e7765d5642fb1f46689", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("00")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f4240")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0100")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "5b600060000156";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0de0b6b3a7640000")), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
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
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("BlockNumberDynamicJump0_foreverOutOfGas______0900beba73811b8aafaefadcff3a7cd9954ccb5e4986b9cf03ca44881efd4e9c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("02")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f4240")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0100")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "5b600060000156";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0de0b6b3a7640000")), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
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
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("JDfromStorageDynamicJump0_foreverOutOfGas______a3046ce1b7f78c109aa36c29db004850ad5b3b4129d9085849b7af04b719826c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("02")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f4240")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0100")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "5b600060000156";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0de0b6b3a7640000")), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
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
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("mstore8MemExp______df32f3b06a7e748f5fdd93a878f7687f4f28864f8a5956d8e3a4fff7463b47f0", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("00")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01f4153d80")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0100")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "60f1630fffffff53";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* origin */
    gas_t(0x800570), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0de0b6b3a7640000")), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
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
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}
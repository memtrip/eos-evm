//
// Auto generated based off the Ethereum tests found here:
// https://github.com/ethereum/tests/blob/develop/VMTests/
//
#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include <evm/big_int.h>
#include "external_mock.h"

TEST_CASE("201503110206PYTHON______ad34ff6291ab537633ab5e7163537b24617cc4edb2f45eac65bed9d2c009cfc3", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("012c")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("02")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f4240")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "4045404145454441343987ff3735043055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* origin */
    gas_t(0x2710), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0de0b6b3a7640000")), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
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
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("201503111844PYTHON______a8049871a173837bf8fbfab3352baf9bb9e33d0ffa2bd20ba6246a70d9c1b165", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("012c")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("02")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f4240")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "65424555";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* origin */
    gas_t(0x2710), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0de0b6b3a7640000")), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
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
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("201503112218PYTHON______6fc205d30fd7493b6e120e18c91e1e41f6fe334b94abadbac37d2817066ebccb", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("012c")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("02")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f4240")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "4041";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* origin */
    gas_t(0x2710), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0de0b6b3a7640000")), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
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
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("201503110219PYTHON______93dd23cbf213b07ac96a1fdfc826f41475452fea6da2e4f8d3f5d206e9a1adb9", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("012c")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("02")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f4240")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "4040459143404144809759886d608f";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* origin */
    gas_t(0x2710), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0de0b6b3a7640000")), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
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
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("201503102320PYTHON______38aa9ba7f7836987852734619b0192d42434bd7106da17663d5fc85d81a1e6cf", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("012c")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("02")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f4240")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "434342444244454597";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* origin */
    gas_t(0x2710), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0de0b6b3a7640000")), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
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
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("201503110346PYTHON_PUSH24______953cb389f468c0d45697c57895679d7675ab43de963ad34a0ee547b8d27d10c8", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("012c")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("02")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f4240")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "7745414245403745f31387900a8d55";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* origin */
    gas_t(0x2710), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0de0b6b3a7640000")), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
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
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}



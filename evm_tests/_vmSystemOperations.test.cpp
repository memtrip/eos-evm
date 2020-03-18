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

TEST_CASE("return0______1cd2b9480f1f5bdd82e8026b6342008ef84d318c3f9f173eae7d09e50eaf26b3", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("00")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("989680")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0100")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "603760005360005160005560016000f3";
  bytes_t data_bytes = Hex::hexToBytes("aa");

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("17")), /* value */
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
  CHECK("3700000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState.get(0x00))
  );
}

TEST_CASE("return1______5cd716a8e8d460b10e0dc1b3d5b6394f0c388e0e36246bf124478b0cb86a1f76", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("00")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("989680")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0100")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "603760005360005160005560026000f3";
  bytes_t data_bytes = Hex::hexToBytes("aa");

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("17")), /* value */
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
  CHECK("3700000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState.get(0x00))
  );
}

TEST_CASE("suicideSendEtherToMe______0cf005812e9c99dc87bdd8463a9849a0164a9e02b3d09eaab228267d6c8c703e", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("00")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("989680")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0100")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "30ff";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* origin */
    gas_t(0x03e8), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0186a0")), /* value */
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

TEST_CASE("TestNameRegistrator______7e0e4bcbcbe8bcaf9a8535e65d4c6665db752910953b5eafc63da8f7cdff20b7", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("00")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f4240")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0100")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "6000355415600957005b60203560003555";
  bytes_t data_bytes = Hex::hexToBytes("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffafffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa");

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
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa" ==
    Utils::uint256_2str(
      accountState.get(
        BigInt::fromBigEndianBytes(Hex::hexToBytes("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa"))
      )
    )
  );
}

TEST_CASE("suicideNotExistingAccount______ba450a40efb62a9fb6e16e3bced0afde8d0b08b9c0f78979f35fc45b9de72816", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("00")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("989680")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0100")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "73aa1722f3947def4cf144679da39c4c32bdc35681ff";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* origin */
    gas_t(0x03e8), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0186a0")), /* value */
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

TEST_CASE("return2______4181cbf262c1dc2cdc186e007ec6c13466bd031b190b07874b1177a00717deeb", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("00")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("989680")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0100")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "603760005360005160005560216000f3";
  bytes_t data_bytes = Hex::hexToBytes("aa");

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("17")), /* value */
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
  CHECK("3700000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState.get(0x00))
  );
}

TEST_CASE("suicide0______56c8766e8a1687dfe807b1e8f2d0454267f432c7e3035ff5fa9c27a2d594739d", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("00")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("989680")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0100")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "33ff";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* origin */
    gas_t(0x03e8), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0186a0")), /* value */
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



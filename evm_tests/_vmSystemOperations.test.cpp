//
// 20.04.2020
// Auto generated based off the Ethereum tests found here:
// https://github.com/ethereum/tests/blob/develop/VMTests/
//
#include "catch.hpp"
#include "test_utils.hpp"
#include <memory>
#include <evm/utils.hpp>
#include <evm/vm.h>
#include <evm/hex.hpp>

#include <evm/call.h>
#include <evm/gasometer.hpp>
#include <evm/big_int.hpp>
#include "external_mock.hpp"
#include <evm/operation.h>

TEST_CASE("return0______1cd2b9480f1f5bdd82e8026b6342008ef84d318c3f9f173eae7d09e50eaf26b3", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("989680"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "603760005360005160005560016000f3";
  bytes_t data_bytes = Hex::hexToBytes("aa");

  params_t params = {
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* address */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* sender */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
    TestUtils::fromHex("17"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK("3700000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("return1______5cd716a8e8d460b10e0dc1b3d5b6394f0c388e0e36246bf124478b0cb86a1f76", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("989680"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "603760005360005160005560026000f3";
  bytes_t data_bytes = Hex::hexToBytes("aa");

  params_t params = {
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* address */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* sender */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
    TestUtils::fromHex("17"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK("3700000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("suicideSendEtherToMe______0cf005812e9c99dc87bdd8463a9849a0164a9e02b3d09eaab228267d6c8c703e", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("989680"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "30ff";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x03e8), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
    TestUtils::fromHex("0186a0"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, context, mem, accountState, external);

  // then
}

TEST_CASE("TestNameRegistrator______7e0e4bcbcbe8bcaf9a8535e65d4c6665db752910953b5eafc63da8f7cdff20b7", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6000355415600957005b60203560003555";
  bytes_t data_bytes = Hex::hexToBytes("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffafffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa");

  params_t params = {
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa" ==
    Utils::uint256_2str(
      accountState->get(external, 
        TestUtils::fromHex("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa"),
        context->codeAddress
      )
    )
  );
}

TEST_CASE("suicideNotExistingAccount______ba450a40efb62a9fb6e16e3bced0afde8d0b08b9c0f78979f35fc45b9de72816", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("989680"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "73aa1722f3947def4cf144679da39c4c32bdc35681ff";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x03e8), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
    TestUtils::fromHex("0186a0"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, context, mem, accountState, external);

  // then
}

TEST_CASE("return2______4181cbf262c1dc2cdc186e007ec6c13466bd031b190b07874b1177a00717deeb", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("989680"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "603760005360005160005560216000f3";
  bytes_t data_bytes = Hex::hexToBytes("aa");

  params_t params = {
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* address */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* sender */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
    TestUtils::fromHex("17"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK("3700000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("suicide0______56c8766e8a1687dfe807b1e8f2d0454267f432c7e3035ff5fa9c27a2d594739d", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("989680"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "33ff";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x03e8), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
    TestUtils::fromHex("0186a0"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, context, mem, accountState, external);

  // then
}



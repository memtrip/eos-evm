//
// 11.04.2020
// Auto generated based off the Ethereum tests found here:
// https://github.com/ethereum/tests/blob/develop/VMTests/
//
#include "catch.hpp"
#include <memory>
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include <evm/big_int.h>
#include "external_mock.h"
#include <evm/operation.h>

TEST_CASE("slt1______ed3559af4c3e3d1f16995417fd3ce8b2d5d289b2debd9d34e7d103af59a64f4a", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6002600003600012600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("or2______2c00a57a80d580130b60d9deda2890eccef876d65ea95b4c43bbb1a4dd0cecd5", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6001600317600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("sgt3______46e9db07c8df7ae98ca90780aeaf1b5a64a02cda8b54068c021dd897d8c56ab5", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600013600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("xor2______cbff7fbed032981ae1743bb8965aaf666a481933ad201acde2a755b4e24ee7d7", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6001600318600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("byte4______2ada67be185a5b95ca62844c81c52e64b00614d02b64cbf9253baf2a7566e2ae", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6780402010080402016004601f031a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000010" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("not5______0748608e64f72417803be26086c812c31a590a1a95f26e9af0bedc573bddf7e7", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600060000319600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("eq2______ae4e87a6dad61b0aa93103ef5906eaeeb3733413e00cb1d2524ee7119383b375", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff14600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("byte8______d8241a95a99ed5c0c39a8d26a9c809b0f62d56817af1fba2368cd2400f2e17a1", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "678040201008040201601f601f031a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("and0______53831e569b6ec2b12b840d539617bd382a07e3700db75ba43d88b45c488abeea", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6002600216600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("and1______d92d694f1df1088e777abdb7e6a441d9c71e4e634886410c4c65bff718a6f675", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6001600216600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("byte9______29129062d256e9717217835274e382615224df82e97c8567aa472d206a2e4111", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6780402010080402016020601f051a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("not4______aee8ec9908daccb907c7076b988b58caffaa8ba68141534a0767d041fbfcb729", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000319600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("byte5______c2f04b6c8ad9f10c1c6302aaa1b1faa4bb90e700d062d6cf2ad06f7f8009d115", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6780402010080402016005601f031a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000020" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("xor3______2e67a0c6dbf54b8eaa761a710775d8f516fb5d4afff97ec05f2bf2b0ca89e9a7", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7f0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff18600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("fedcba9876543210fedcba9876543210fedcba9876543210fedcba9876543210" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("sgt2______b9b0e8560b1da602351ee89d9385bd7bd33d19a5e4bc4ae1dbddc76ebf87a0ad", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff13600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("or3______e86a2ab7088faca5e880fab11b2cf61601e941f621330eceec13296405f02e2b", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7f0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff17600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("slt0______2fa0aa23a17f6f906146df0f152b09727ed44e560ba9ca9b357285f2ec0b38c3", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6000600260000312600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("not3______98f29555aca23bee7693ee4962daafe489d8c024dfc8db3da4252ee438d15d64", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600260000319600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("lt0______3f82794b3ab7a1381f800f045fe2a52a2c742a5bf5a0c262cfb6be574d305879", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6000600260000310600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("8ac7230489e80000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("gt2______4b0191dbc7944ec9b47ede8560ad03500238397635dc897707fd45937b0d762b", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff11600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("or4______0529771970ae1453127c9560e68b8274a9662ddf5684bdc7c6a5bd925fedbd27", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee17600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("xor4______c3087ab19e23a572ebb996067c96ae4e3a83fbfe7a3253e347130c9767afb7be", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee18600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("1111111111111111111111111111111111111111111111111111111111111111" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("byte2______88e635fca6798de38b2831eaf5aa1d7ccc10a703006fc531c431a07a6f0ad9b7", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6780402010080402016002601f031a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000004" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("byte3______f182ba9431c0afa8951345caab69362ef0d08befe7af3ba46c0150f194528281", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6780402010080402016003601f031a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000008" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("xor5______208791127a38c44787ac9739f8e2d42eafcc94924b718326bb2f41c0641fe68e", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeefeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee18600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("1111111111111111111111111111101111111111111111111111111111111111" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("sgt4______952942a91ed7040913a6bb27488e09877b1c0eff4b14fcc9e515f8ffde6a2016", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6003600003600560000313600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("or5______4c9eb19946147a54071f850e4812bd9b75e200b344b9bd27cb1d8af2c4674933", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeefeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee17600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("gt3______2c4b8f3a0bd648007898638b2bf6ab5f170741704abc751161d5f90f0494d666", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600011600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("lt1______63a727c86d3f482ccf6a02dbded8c26b306938192e9a6008f4ad74c7a5efd8fd", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6002600003600010600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("8ac7230489e80000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("not2______324eba656aca54db2f9828012cc52c412e67ea3976e1e806698486b3f755b5eb", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff19600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("and4______e21e8e11b9513679c36fd3f2877d5ef73d302169e669d42569e9b28e07ee85f5", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee16600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("gt0______c17427d3c9acd0c27322e9bb49e967e2240aa803764c4ccf202d94ef4cb9939c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6000600260000311600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("iszero0______c7730a4eae5d80429b5e6a822a0c8c4dc6bece946d3d6902a5fddb2fc120fa04", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff15600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("lt2______2e2c7923db8f0fc63497824b409ae8c0eba04c0e352fe50ae0a5cc00469d9498", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff10600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("8ac7230489e80000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("not1______986682dadca33278653a19f30a97e9db367c671a612d67a4535d20510e2d625e", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600219600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffd" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("byte0______ca8eddefff06f7e6cb91dd60e11a7dd107ced29e7c88ef06da7952e8cfd38d45", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6780402010080402016000601f031a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("slt4______ed936fea46872027bbe365872786c5ab0e1356dfae7bc9c81150fdaa86cb443f", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6003600003600560000312600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("byte1______bb1c4e33835be3cbddbd232873e7ee350b4f971f725bf3b1c56c7e4f456d690a", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6780402010080402016001601f031a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("not0______3235e2a1af7340deea07b964fc3532b19092832b2c9592d3c777a659e97a01ba", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600019600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("lt3______ba2bc4205d1ca31e29315edfc5708f300f44cb02936b9da05a9097b26f97d71a", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600010600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("iszero1______1fc0ad71c14401598db2286ee499a76e21de97cbb63ee987afd5f603d34ef903", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600015600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("gt1______98d2099f8676c20a4806282a1fbe0968231046a99e137070724adbc117447290", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6002600003600011600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("byteBN______43da3e8490c4e2724415c26642284184fbbcb7e128d59d7693386f3da3c2d08e", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "641234523456601f1a8001600155";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("00000000000000000000000000000000000000000000000000000000000000ac" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
}

TEST_CASE("and5______1bbd8a8b90a8f84cb52e9514c9a02cd594e6e731065b54087cfa7afc9ccd2fc2", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeefeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee16600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("eeeeeeeeeeeeeeeeeeeeeeeeeeeeefeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("byte6______2f99689c10d739d33cec8c8062c608a1b01c61686ca12f01d2e9fe2b73d1ee0f", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6780402010080402016006601f031a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000040" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("xor0______e08c105ef68171d063c469dd9b2a23da11aac894df3ee20271da79681250fc9b", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6002600218600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("sgt1______671a4ef36d8c59426ca6b9eeb8cc46cfb41716888e2f2df3852eb03e9c14dbb1", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6002600003600013600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("or0______dcc4012a46120cba05d501bbffe31a249fd5445b29b3f7e8e2133e9098e735e4", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6002600217600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("slt3______32f573a07264be5090d1b383aac1d8803ab95f9420e0d8a849de627095f954ee", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600012600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("and2______b8c8c36bba987b4b5e5172ea00931076b8169ff8a8ff0d48244637c3dbe1eba1", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6001600316600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("byte11______57be2a02bebea1ac84a6d1bbb3f15f0ab9d9339fa706131cd052c9275a0ec871", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "67804020100804020160001a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("iszeo2______4e5ea4236cff2cb1176ad44dba65cb26dec72438acaa1e35600292b1bee87a71", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600260000315600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("eq0______e9cd05b4ad632b287637f3682cb5bd3d39957b0a859fcaf2740c3a84bff603f2", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6003600003600560000314600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("eq1______71d72425d2c1777c6991d09b38aed473c3dc3b9b370b8397c0d48e68a29b3aac", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6000600014600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("byte10______866a8493a1363ce7e4595429147e8892ee6abb300fe15732d93c8d6b5c3c84f7", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6780402010080402017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("and3______d37be2fe655f6f4348e3ab48e7b0f832505ab4800835a50e516c726bc6f59cf1", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7f0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff16600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("slt2______92e953b3e18b0939fd97afb7875129e10860293931b9cb840b50f1559489ac16", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff12600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("or1______791c257002ce8dd940a5391775fd4eac1836f7eb55304f658a32485f79d4993f", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6001600217600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("sgt0______c5194500b062e2d1bf6dd6607185c661b6500d51c7146603f7f4ed31795b5d23", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6000600260000313600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("xor1______417302c7876ef9a5209b50fcbd9ea4a70ca3d74748ed4f92f0c3164c0584c313", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6001600218600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("byte7______c4d404f87e398a368fb2b0cb2165358ecdd92a97a2bbffcd0f8e833fc942976b", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6780402010080402016007601f031a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
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
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000080" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}



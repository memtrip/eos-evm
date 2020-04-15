//
// 11.04.2020
// Auto generated based off the Ethereum tests found here:
// https://github.com/ethereum/tests/blob/develop/VMTests/
//
#include "catch.hpp"
#include <memory>
#include <evm/utils.hpp>
#include <evm/vm.h>
#include <evm/hex.hpp>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.hpp>
#include <evm/big_int.hpp>
#include "external_mock.hpp"
#include <evm/operation.h>

TEST_CASE("gaslimit______f1250fd89a1c3e517ae92cc1f73865c594bfad34db20f3b3396af4efe19d3bfb", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "45600055";
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
  VM vm(stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, context, mem, accountState, external, call);

  // then
  CHECK("00000000000000000000000000000000000000000000000000000000000f4240" ==
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("number______404caf239c3e0ad4394c1417b728d10e1f68a8eee3963425d9e391f4f3ec023c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("01"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "43600055";
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
  VM vm(stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, context, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("difficulty______30c06d1988994e3f4e738e60b1e0d6b8734fb576e3b2580151251c5f058fa9c6", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "44600055";
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
  VM vm(stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, context, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000100" ==
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("coinbase______9f5df0c263c2b48fbf48db70ec64ddf3efa5f1651ced1fedf933ee239e9c851d", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "41600055";
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
  VM vm(stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, context, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000002adc25665018aa1fe0e6bc666dac8fc2697ff9ba" ==
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("timestamp______44c8782a2b04af7092f76bfa83b1cb24e590722db220b32a52e4e249e596def4", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "42600055";
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
  VM vm(stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, context, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}



#include <stdio.h>
#include <variant>
#include "catch.hpp"
#include <memory>
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

TEST_CASE("shift left, write to memory, return", "[return_memory]") {
  std::string bytecode_str = "600560011b6000526001601ff3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  env_t env = Utils::env();
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
  VM vm(context, stack);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, mem, accountState, external, call);

  // then
  REQUIRE(ExecResult::DONE == result.first);

  gas_left_t gasResult = std::get<gas_left_t>(result.second);
  REQUIRE(GasType::NEEDS_RETURN == gasResult.first);

  NeedsReturn needsReturn = std::get<NeedsReturn>(gasResult.second);
  bytes_t returnDataSlice = Utils::returnDataSlice(needsReturn.data);
  CHECK("0a" == Hex::bytesToHex(returnDataSlice));
}

TEST_CASE("shift right, write to memory, return", "[return_memory]") {
  std::string bytecode_str = "600560011c6000526001601ff3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  env_t env = Utils::env();
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
  VM vm(context, stack);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, mem, accountState, external, call);

  // then
  REQUIRE(ExecResult::DONE == result.first);

  gas_left_t gasResult = std::get<gas_left_t>(result.second);
  REQUIRE(GasType::NEEDS_RETURN == gasResult.first);

  NeedsReturn needsReturn = std::get<NeedsReturn>(gasResult.second);
  bytes_t returnDataSlice = Utils::returnDataSlice(needsReturn.data);
  CHECK("02" == Hex::bytesToHex(returnDataSlice));
}

TEST_CASE("sar, write to memory, revert", "[return_memory]") {
  std::string bytecode_str = "600160000360021d60005260016000fd";
  bytes_t codeBytes = Hex::hexToBytes(bytecode_str);
  bytes_t emptyBytes = bytes_t();
  params_t params =  Utils::params(codeBytes, emptyBytes);
  env_t env = Utils::env();
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
  VM vm(context, stack);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, mem, accountState, external, call);

  // then
  REQUIRE(ExecResult::DONE == result.first);

  gas_left_t gasResult = std::get<gas_left_t>(result.second);
  REQUIRE(GasType::NEEDS_RETURN == gasResult.first);

  NeedsReturn needsReturn = std::get<NeedsReturn>(gasResult.second);
  bytes_t returnDataSlice = Utils::returnDataSlice(needsReturn.data);
  CHECK("ff" == Hex::bytesToHex(returnDataSlice));
}
#include "catch.hpp"
#include <memory>
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

TEST_CASE("Create the most basic contract", "[create]") {
  std::string bytecode_str = "6080604052348015600f57600080fd5b50603580601d6000396000f300";
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

  ReturnData returnData = ReturnData::empty();
  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t vm_result = vm.execute(operation, mem, accountState, external, call);

  // then
  REQUIRE(ExecResult::DONE == vm_result.first);

  // and then
  gas_left_t gasLeft = std::get<gas_left_t>(vm_result.second);

  REQUIRE(GasType::NEEDS_RETURN == gasLeft.first);

  // and then
  NeedsReturn needsReturn = std::get<NeedsReturn>(gasLeft.second);

  CHECK("" == 
    Hex::bytesToHex(needsReturn.data.mem)
  );
}

TEST_CASE("Create contract using CODECOPY", "[create]") {
  std::string bytecode_str = "608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390a160b8806100826000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a723158209551755b4e59ca6cf78d79f5356d91565950805937074458700610f23c6ecf9b64736f6c63430005100032";
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

  ReturnData returnData = ReturnData::empty();
  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t vm_result = vm.execute(operation, mem, accountState, external, call);

  // then
  REQUIRE(ExecResult::DONE == vm_result.first);

  // and then
  gas_left_t gasLeft = std::get<gas_left_t>(vm_result.second);

  REQUIRE(GasType::NEEDS_RETURN == gasLeft.first);

  // and then
  NeedsReturn needsReturn = std::get<NeedsReturn>(gasLeft.second);

  CHECK("6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a723158209551755b4e59ca6cf78d79f5356d91565950805937074458700610f23c6ecf9b64736f6c63430005100032" == 
    Hex::bytesToHex(needsReturn.data.mem)
  );

  REQUIRE(1 == external->logSpy.size());
  CHECK(1 == external->logSpy[0].first.size());
  CHECK("b8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad6" == 
    Utils::uint256_2str(external->logSpy[0].first[0])
  );
}

TEST_CASE("Create contract using CREATE", "[create]") {
  std::string bytecode_str = "608060405234801561001057600080fd5b5060405161001d9061007e565b604051809103906000f080158015610039573d6000803e3d6000fd5b506000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555061008b565b61013a8061016883390190565b60cf806100996000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063bc33657a14602d575b600080fd5b60336075565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a72315820d9d1db44331e8aef66d876ff3bdf5c632d0ca766882d6e738a2c7b978d29077364736f6c63430005100032608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390a160b8806100826000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a7231582071c7fe98a34e7c0c2e10ae018de7d3708ce7189591eff656e9cbf717bc03c1f664736f6c63430005100032";
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
  exec_result_t vm_result = vm.execute(operation, mem, accountState, external, call);

  // then
  REQUIRE(ExecResult::DONE == vm_result.first);

  // and then
  gas_left_t gasLeft = std::get<gas_left_t>(vm_result.second);

  REQUIRE(GasType::NEEDS_RETURN == gasLeft.first);

  // and then
  NeedsReturn needsReturn = std::get<NeedsReturn>(gasLeft.second);

  CHECK("6080604052348015600f57600080fd5b506004361060285760003560e01c8063bc33657a14602d575b600080fd5b60336075565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a72315820d9d1db44331e8aef66d876ff3bdf5c632d0ca766882d6e738a2c7b978d29077364736f6c63430005100032" == 
    Hex::bytesToHex(needsReturn.data.mem)
  );
}
#include "catch.hpp"
#include "test_utils.hpp"
#include "external_mock.hpp"

#include <memory>

#include <evm/utils.hpp>
#include <evm/vm.h>
#include <evm/hex.hpp>
#include <evm/call.h>
#include <evm/gasometer.hpp>
#include <evm/big_int.hpp>

TEST_CASE("Create the most basic contract using COPYCODE", "[create]") {
  bytes_t codeBytes =  Hex::hexToBytes("6080604052348015600f57600080fd5b50603580601d6000396000f300");
  bytes_t emptyBytes = bytes_t();
  env_t env = Utils::env();
  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    uint256_t(0xea0e9a), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"),
    uint256_t(0x1283fe), /* origin */
    100000,
    uint256_t(0),
    uint256_t(0),
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>(bytes_t())
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

  exec_result_t vm_result = vm.execute(operation, context, mem, accountState, external);

  // then
  REQUIRE(ExecResult::DONE_RETURN == vm_result.first);

  // and then
  NeedsReturn needsReturn = std::get<NeedsReturn>(vm_result.second);

  REQUIRE(true == needsReturn.apply);

  std::string code = mem->sliceAsString(needsReturn.offset, needsReturn.size);

  CHECK("0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000" == 
    code
  );
}

TEST_CASE("Create contract using CODECOPY", "[create]") {
  bytes_t codeBytes = Hex::hexToBytes("608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390a160b8806100826000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a723158209551755b4e59ca6cf78d79f5356d91565950805937074458700610f23c6ecf9b64736f6c63430005100032");
  env_t env = Utils::env();
  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    uint256_t(0xea0e9a), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"),
    uint256_t(0x1283fe), /* origin */
    100000,
    uint256_t(0),
    uint256_t(0),
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>()
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
  exec_result_t vm_result = vm.execute(operation, context, mem, accountState, external);

  // then
  REQUIRE(ExecResult::DONE_RETURN == vm_result.first);

  // and then
  NeedsReturn needsReturn = std::get<NeedsReturn>(vm_result.second);

  REQUIRE(true == needsReturn.apply);

  std::string code = mem->sliceAsString(needsReturn.offset, needsReturn.size);

  CHECK("6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a723158209551755b4e59ca6cf78d79f5356d91565950805937074458700610f23c6ecf9b64736f6c63430005100032" == 
    code
  );

  REQUIRE(1 == external->logSpy.size());
  CHECK(1 == external->logSpy[0].first.size());
  CHECK("b8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad6" == 
    Utils::uint256_2str(external->logSpy[0].first[0])
  );

  REQUIRE(0 == external->emplaceSpy.size());
}

TEST_CASE("Create contract using CREATE (1)", "[create]") {

  bytes_t codeBytes = Hex::hexToBytes("7c601080600c6000396000f3006000355415600957005b60203560003555600052601d60036017f0600055");

  env_t env = Utils::env();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    uint256_t(0xea0e9a), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"),
    uint256_t(0x1283fe), /* origin */
    100000,
    uint256_t(0),
    uint256_t(0),
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>()
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

  exec_result_t vm_result = vm.execute(operation, context, mem, accountState, external);

  // then
  REQUIRE(ExecResult::DONE_VOID == vm_result.first);

  REQUIRE(1 == external->emplaceSpy.size());

  std::string code = external->emplaceSpy[0].second;

  CHECK("601080600c6000396000f3006000355415600957005b60203560003555" == 
    code
  );
}

TEST_CASE("Create contract using CREATE (2)", "[create]") {
  bytes_t codeBytes = Hex::hexToBytes("6460016000fd6000526005601b6017f0600055");

  env_t env = Utils::env();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    uint256_t(0xea0e9a), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"),
    uint256_t(0x1283fe), /* origin */
    100000,
    uint256_t(0),
    uint256_t(0),
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>()
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

  exec_result_t vm_result = vm.execute(operation, context, mem, accountState, external);

  // then
  REQUIRE(ExecResult::DONE_VOID == vm_result.first);

  REQUIRE(1 == external->emplaceSpy.size());

  std::string code = external->emplaceSpy[0].second;

  CHECK("60016000fd" == 
    code
  );
}

TEST_CASE("Create main contract using COPYCODE, and a child contract with CREATE (1)", "[create]") {

  bytes_t codeBytes = Hex::hexToBytes(
    "608060405234801561001057600080fd5b5060405161001d9061007e565b604051809103906000f080158015610039573d6000803e3d6000fd5b506000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555061008b565b61013a8061016883390190565b60cf806100996000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063bc33657a14602d575b600080fd5b60336075565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a72315820d9d1db44331e8aef66d876ff3bdf5c632d0ca766882d6e738a2c7b978d29077364736f6c63430005100032608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390a160b8806100826000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a7231582071c7fe98a34e7c0c2e10ae018de7d3708ce7189591eff656e9cbf717bc03c1f664736f6c63430005100032"
  );
  env_t env = Utils::env();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    uint256_t(0xea0e9a), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"),
    uint256_t(0x1283fe), /* origin */
    100000,
    uint256_t(0),
    uint256_t(0),
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>()
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
  exec_result_t vm_result = vm.execute(operation, context, mem, accountState, external);

  // then
  REQUIRE(ExecResult::DONE_RETURN == vm_result.first);

  NeedsReturn needsReturn = std::get<NeedsReturn>(vm_result.second);

  REQUIRE(true == needsReturn.apply);

  std::string code = mem->sliceAsString(needsReturn.offset, needsReturn.size);

  CHECK("6080604052348015600f57600080fd5b506004361060285760003560e01c8063bc33657a14602d575b600080fd5b60336075565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a72315820d9d1db44331e8aef66d876ff3bdf5c632d0ca766882d6e738a2c7b978d29077364736f6c63430005100032" == 
    code
  );

  REQUIRE(1 == external->emplaceSpy.size());

  std::string childCode = external->emplaceSpy[0].second;

  CHECK("608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390a160b8806100826000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a7231582071c7fe98a34e7c0c2e10ae018de7d3708ce7189591eff656e9cbf717bc03c1f664736f6c63430005100032" == 
    childCode
  );
}

TEST_CASE("Create contract using CREATE2", "[create]") {

  bytes_t codeBytes = Hex::hexToBytes(
    "6080604052348015600f57600080fd5b5060cb8061001e6000396000f3fe608060405260043610601c5760003560e01c806373d98e39146021575b600080fd5b60276029565b005b7fbbbf55a6f5ae8ee75e6fb8f92a93e32841ed3055bf2139469c60bbc79a455da73334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a156fea265627a7a7231582069c4265b77ab1bd39221ac01c9f6f1adacb2f5a7beeccf724523846fa4aaf8ba64736f6c63430005100032"
  );
  env_t env = Utils::env();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    uint256_t(0xea0e9a), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"),
    uint256_t(0x1283fe), /* origin */
    100000,
    uint256_t(0),
    uint256_t(0),
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>()
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
  exec_result_t vm_result = vm.execute(operation, context, mem, accountState, external);

  // then
  REQUIRE(ExecResult::DONE_RETURN == vm_result.first);

  NeedsReturn needsReturn = std::get<NeedsReturn>(vm_result.second);

  REQUIRE(true == needsReturn.apply);

  std::string code = mem->sliceAsString(needsReturn.offset, needsReturn.size);

  CHECK("608060405260043610601c5760003560e01c806373d98e39146021575b600080fd5b60276029565b005b7fbbbf55a6f5ae8ee75e6fb8f92a93e32841ed3055bf2139469c60bbc79a455da73334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a156fea265627a7a7231582069c4265b77ab1bd39221ac01c9f6f1adacb2f5a7beeccf724523846fa4aaf8ba64736f6c63430005100032" == 
    code
  );
}
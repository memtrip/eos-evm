#include "catch.hpp"
#include "test_utils.hpp"
#include "external_mock.hpp"

#include <memory>

#include <evm/utils.hpp>
#include <evm/vm.h>
#include <evm/hex.hpp>
#include <evm/gasometer.hpp>
#include <evm/big_int.hpp>

TEST_CASE("Malformed CREATE statement will not create a contract", "[create_revert]") {
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
    150000,
    uint256_t(0),
    uint256_t(0),
    false,  
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>()
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  exec_result_t vm_result = vm.execute(0, operation, context, mem, pendingState, external);

  // then
  REQUIRE(ExecResult::DONE_VOID == vm_result.first);
}

TEST_CASE("Impossible contract will not be created", "[create_revert]") {
  bytes_t codeBytes = Hex::hexToBytes("608060405234801561001057600080fd5b503073ffffffffffffffffffffffffffffffffffffffff1663f8a8fd6d6040518163ffffffff1660e01b815260040160206040518083038186803b15801561005757600080fd5b505afa15801561006b573d6000803e3d6000fd5b505050506040513d602081101561008157600080fd5b8101908080519060200190929190505050506087806100a16000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063f8a8fd6d14602d575b600080fd5b60336049565b6040518082815260200191505060405180910390f35b6000600290509056fea265627a7a72315820523c8d6f31779c4cb02b3588d0ce28924193ddb9e749963217fe3dfa92849bab64736f6c63430005100032");
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
    false,  
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>()
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  exec_result_t vm_result = vm.execute(0, operation, context, mem, pendingState, external);

  // then
  REQUIRE(ExecResult::DONE_RETURN == vm_result.first);

  NeedsReturn needsReturn = std::get<NeedsReturn>(vm_result.second);

  // and then
  REQUIRE(false == needsReturn.apply);
}
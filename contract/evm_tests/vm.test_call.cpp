#include "catch.hpp"
#include <memory>
#include <evm/utils.hpp>
#include <evm/vm.h>
#include <evm/hex.hpp>

#include <evm/call.hpp>
#include <evm/gasometer.hpp>
#include <evm/big_int.hpp>
#include "external_mock.hpp"
#include "test_utils.hpp"

TEST_CASE("Call contract code (1)", "[call]") {
  bytes_t codeBytes = Hex::hexToBytes("6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a7231582071c7fe98a34e7c0c2e10ae018de7d3708ce7189591eff656e9cbf717bc03c1f664736f6c63430005100032");
  bytes_t dataBytes = Hex::hexToBytes("771602f700000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000002");
  env_t env = Utils::env();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    uint256_t(0xea0e9a), /* codeAddress */
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xea0e9e), /* sender */
    uint256_t(0x1283fe), /* origin */
    100000,
    uint256_t(0),
    uint256_t(0),
    false,
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>(dataBytes)
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

  CHECK(true == needsReturn.apply);

  CHECK("[0000000000000000000000000000000000000000000000000000000000000003]" == 
    Hex::bytesToWordOutput(mem->memory, needsReturn.offset, needsReturn.size)
  );
}

TEST_CASE("Call contract code (2)", "[call]") {
  bytes_t codeBytes = Hex::hexToBytes("608060405260043610601c5760003560e01c806373d98e39146021575b600080fd5b60276029565b005b7fbbbf55a6f5ae8ee75e6fb8f92a93e32841ed3055bf2139469c60bbc79a455da73334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a156fea265627a7a7231582069c4265b77ab1bd39221ac01c9f6f1adacb2f5a7beeccf724523846fa4aaf8ba64736f6c63430005100032");
  bytes_t dataBytes = Hex::hexToBytes("73d98e39");
  env_t env = Utils::env();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    uint256_t(0xea0e9a), /* codeAddress */
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xea0e9e), /* sender */
    uint256_t(0x1283fe), /* origin */
    100000,
    uint256_t(0),
    uint256_t(2),
    false,
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>(dataBytes)
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
  REQUIRE(ExecResult::DONE_VOID == vm_result.first);

  CHECK(1 == pendingState->logs.size());

  CHECK(1 == pendingState->logs[0].topics.size());

  // abi_encoded(address,uint256)
  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9e0000000000000000000000000000000000000000000000000000000000000002" ==
    Hex::bytesToHex(pendingState->logs[0].data)
  );
}
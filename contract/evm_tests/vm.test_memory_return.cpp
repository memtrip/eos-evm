#include "catch.hpp"
#include "test_utils.hpp"
#include "external_mock.hpp"

#include <variant>
#include <memory>

#include <evm/utils.hpp>
#include <evm/vm.h>
#include <evm/hex.hpp>
#include <evm/gasometer.hpp>
#include <evm/big_int.hpp>

TEST_CASE("shift left, write to memory, return", "[return_memory]") {
  std::string bytecode_str = "600560011b6000526001601ff3";
  bytes_t codeBytes = Hex::hexToBytes(bytecode_str);
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  exec_result_t result = vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  REQUIRE(ExecResult::DONE_RETURN == result.first);

  NeedsReturn needsReturn = std::get<NeedsReturn>(result.second);

  bytes_t returnBytes = mem->readSlice(needsReturn.offset, needsReturn.size);
  CHECK("0a" == TestUtils::bytesToHex(returnBytes));
}

TEST_CASE("shift right, write to memory, return", "[return_memory]") {
  std::string bytecode_str = "600560011c6000526001601ff3";
  bytes_t codeBytes = Hex::hexToBytes(bytecode_str);
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  exec_result_t result = vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  REQUIRE(ExecResult::DONE_RETURN == result.first);

  NeedsReturn needsReturn = std::get<NeedsReturn>(result.second);

  bytes_t returnBytes = mem->readSlice(needsReturn.offset, needsReturn.size);
  CHECK("02" == TestUtils::bytesToHex(returnBytes));
}

TEST_CASE("sar, write to memory, revert", "[return_memory]") {
  std::string bytecode_str = "600160000360021d60005260016000fd";
  bytes_t codeBytes = Hex::hexToBytes(bytecode_str);
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  exec_result_t result = vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  REQUIRE(ExecResult::DONE_RETURN == result.first);

  NeedsReturn needsReturn = std::get<NeedsReturn>(result.second);

  bytes_t returnBytes = mem->readSlice(needsReturn.offset, needsReturn.size);
  CHECK("ff" == TestUtils::bytesToHex(returnBytes));
}
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

TEST_CASE("Log empty (LOG0)", "[log]") {
  // given
  std::string bytecode_str = "60006000a0";
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
    uint256_t(0xea0e9e), /* sender */
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
  CHECK(99619 == Utils::gasLeft(result));

  // then
  CHECK(1 == pendingState->logs.size());
  CHECK(0 == pendingState->logs[0].topics.size());
  CHECK(0 == pendingState->logs[0].data.size());
}

TEST_CASE("Log sender (LOG1)", "[log]") {
  // given
  std::string bytecode_str = "60ff6000533360206000a1";
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
    uint256_t(0xea0e9e), /* sender */
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
  CHECK(98974 == Utils::gasLeft(result));

  // then
  CHECK(1 == pendingState->logs.size());
  CHECK(1 == pendingState->logs[0].topics.size());
  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9e" == 
    Utils::uint256_2str(pendingState->logs[0].topics[0])
  );
  CHECK("ff00000000000000000000000000000000000000000000000000000000000000" == 
    Hex::bytesToHex(pendingState->logs[0].data)
  );
}

TEST_CASE("Log origin and sender (LOG2)", "[log]") {
  // given
  std::string bytecode_str = "60ff600053333260206000a2";
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
    uint256_t(0xea0e9e), /* sender */
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
  CHECK(98597 == Utils::gasLeft(result));

  // then
  CHECK(1 == pendingState->logs.size());
  CHECK(2 == pendingState->logs[0].topics.size());
  CHECK("00000000000000000000000000000000000000000000000000000000001283fe" == 
    Utils::uint256_2str(pendingState->logs[0].topics[0])
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9e" == 
    Utils::uint256_2str(pendingState->logs[0].topics[1])
  );
  CHECK("ff00000000000000000000000000000000000000000000000000000000000000" == 
    Hex::bytesToHex(pendingState->logs[0].data)
  );
}

TEST_CASE("Log caller, origin, sender (LOG3)", "[log]") {
  // given
  std::string bytecode_str = "60ff60005333323060206000a3";
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
    uint256_t(0xea0e9e), /* sender */
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
  CHECK(98220 == Utils::gasLeft(result));

  // then
  CHECK(1 == pendingState->logs.size());
  CHECK(3 == pendingState->logs[0].topics.size());
  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9a" == 
    Utils::uint256_2str(pendingState->logs[0].topics[0])
  );
  CHECK("00000000000000000000000000000000000000000000000000000000001283fe" == 
    Utils::uint256_2str(pendingState->logs[0].topics[1])
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9e" == 
    Utils::uint256_2str(pendingState->logs[0].topics[2])
  );
  CHECK("ff00000000000000000000000000000000000000000000000000000000000000" == 
    Hex::bytesToHex(pendingState->logs[0].data)
  );
}

TEST_CASE("Log number, caller, origin and sender (LOG4)", "[log]") {
  // given
  std::string bytecode_str = "60ff6000534333323060206000a4";
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
    uint256_t(0xea0e9e), /* sender */
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
  CHECK(97843 == Utils::gasLeft(result));

  // then
  CHECK(1 == pendingState->logs.size());
  CHECK(4 == pendingState->logs[0].topics.size());
  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9a" == 
    Utils::uint256_2str(pendingState->logs[0].topics[0])
  );
  CHECK("00000000000000000000000000000000000000000000000000000000001283fe" == 
    Utils::uint256_2str(pendingState->logs[0].topics[1])
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9e" == 
    Utils::uint256_2str(pendingState->logs[0].topics[2])
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000f950e1" == 
    Utils::uint256_2str(pendingState->logs[0].topics[3])
  );
  CHECK("ff00000000000000000000000000000000000000000000000000000000000000" == 
    Hex::bytesToHex(pendingState->logs[0].data)
  );
}
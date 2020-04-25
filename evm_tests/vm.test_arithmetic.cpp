#include "catch.hpp"
#include "test_utils.hpp"
#include "external_mock.hpp"

#include <memory>

#include <evm/utils.hpp>
#include <evm/vm.h>
#include <evm/hex.hpp>
#include <evm/gasometer.hpp>
#include <evm/hash.hpp>
#include <evm/big_int.hpp>

TEST_CASE("Add two large numbers", "[arithmetic]") {
  // given
  // (PUSH32 ((7f)fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff))
	// (PUSH32 ((7f)fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff))
	// (ADD (01))
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01";
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

  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" == 
    Utils::uint256_2str(vm.stack->top())
  );
}

TEST_CASE("Multiply two numbers", "[arithmetic]") {
  // given
  // (PUSH1 ((60)03))
	// (PUSH1 ((60)03))
	// (MUL (02))
  std::string bytecode_str = "6003600302";
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

  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000009" == 
    Utils::uint256_2str(vm.stack->top())
  );
}

TEST_CASE("Multiply two larger numbers", "[arithmetic]") {
  // given
  // (PUSH2 ((61)0A10))
	// (PUSH2 ((61)0B12))
	// (MUL (02))
  std::string bytecode_str = "6016601602";
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

  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("00000000000000000000000000000000000000000000000000000000000001e4" == 
    Utils::uint256_2str(vm.stack->top())
  );
}

TEST_CASE("Multiply and store", "[arithmetic]") {
  // given
  // (PUSH6 ((65) 012365124623))
	// (PUSH3 ((62) 654321))
	// (SWAP1 90)
  // (MUL 02)
  // (PUSH1 ((60) 00))
  // (SSTORE 55)
  std::string bytecode_str = "65012365124623626543219002600055";
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

  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("000000000000000000000000000000000000000000000000734349397b853383" == 
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("Subtract two numbers", "[arithmetic]") {
  // given
  // (PUSH1 ((60)03))
	// (PUSH1 ((60)05))
	// (SUB (03))
  std::string bytecode_str = "6003600503";
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

  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" == 
    Utils::uint256_2str(vm.stack->top())
  );
}

TEST_CASE("Subtract and store", "[arithmetic]") {
  // given
  // (PUSH6 ((65)012365124623))
	// (PUSH3 ((62)654321))
  // (SWAP1 90)
  // (SUB 03)
	// (PUSH1 (60)00)
  // (SSTORE 55)
  std::string bytecode_str = "65012365124623626543219003600055";
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

  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000012364ad0302" == 
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("Divide two numbers", "[arithmetic]") {
  // given
  // (PUSH1 ((60)02))
	// (PUSH1 ((60)04))
	// (DIV (04))
  std::string bytecode_str = "6002600404";
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

  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" == 
    Utils::uint256_2str(vm.stack->top())
  );
}

TEST_CASE("Divide 2 / 0", "[arithmetic]") {
  // given
  // (PUSH1 ((60)00))
	// (PUSH1 ((60)02))
	// (DIV (04))
  std::string bytecode_str = "6000600204";
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

  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(vm.stack->top())
  );
}

TEST_CASE("Divide and store", "[arithmetic]") {
  // given
  // (PUSH6 ((65)012365124623))
	// (PUSH3 ((62)654321))
  // (SWAP1 (90))
  // (DIV (04))
	// (PUSH1 (60)00)
  // (SSTORE 55)
  std::string bytecode_str = "65012365124623626543219004600055";
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

  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("000000000000000000000000000000000000000000000000000000000002e0ac" == 
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("Divide by zero and store", "[arithmetic]") {
  // given
  // (PUSH6 ((65)012365124623))
	// (PUSH1 ((60)00))
  // (SWAP1 (90))
  // (DIV (04))
	// (PUSH1 (60)00)
  // (SSTORE 55)
  std::string bytecode_str = "6501236512462360009004600055";
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

  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("Mod and store", "[arithmetic]") {
  std::string bytecode_str = "650123651246236265432290066000556501236512462360009006600155";
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

  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000076b4b" == 
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(pendingState->getState(uint256_t(0x01), context->codeAddress, external))
  );
}


TEST_CASE("Modulus 8 % 2", "[arithmetic]") {
  // given
  // (PUSH1 ((60)02))
	// (PUSH1 ((60)08))
	// (MOD (06))
  std::string bytecode_str = "6002600806";
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

  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(vm.stack->top())
  );
}

TEST_CASE("Modulus 5 % 2", "[arithmetic]") {
  // given
  // (PUSH1 ((60)05))
	// (PUSH1 ((60)02))
	// (MOD (06))
  std::string bytecode_str = "6002600506";
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

  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(vm.stack->top())
  );
}

TEST_CASE("Modulus 2 % 0", "[arithmetic]") {
  // given
  // (PUSH1 ((60)02))
	// (PUSH1 ((60)00))
	// (MOD (06))
  std::string bytecode_str = "6000600206";
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

  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(vm.stack->top())
  );
}

TEST_CASE("Byte", "[arithmetic]") {
  std::string bytecode_str = "60f061ffff1a600055610fff601f1a600155";
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

  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );

  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" == 
    Utils::uint256_2str(pendingState->getState(uint256_t(0x01), context->codeAddress, external))
  );
}
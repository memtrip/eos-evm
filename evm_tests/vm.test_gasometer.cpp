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
#include <evm/hash.hpp>

TEST_CASE("Add two large numbers, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01600055";
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


  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(79988 == Utils::gasLeft(result));

  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("Store the result of an SHA3 hash, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "6000600020600055";
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


  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(79961 == Utils::gasLeft(result));

  CHECK("c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("Address, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "30600055";
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    uint256_t(0xea0e9a),
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
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(79995 == Utils::gasLeft(result));

  CHECK("0000000000000000000000000f572e5295c57f15886f9b263e2f6d2d6c7b5ec6" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("Origin, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "32600055";
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
    uint256_t(0x1283fe),
    TestUtils::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
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
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(79995 == Utils::gasLeft(result));

  CHECK("000000000000000000000000cd1722f2947def4cf144679da39c4c32bdc35681" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("Self balance, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "4760ff55";
  bytes_t codeBytes = Hex::hexToBytes(bytecode_str);
  uint256_t address = TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6");
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
    address, /* address */
    uint256_t(0xea0e9e), /* sender */
    address, /* origin */
    100000,
    uint256_t(0),
    uint256_t(0),
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>()
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();
  external->balanceResponder.push_back(std::make_pair(address, 1025));

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
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(79992 == Utils::gasLeft(result));
}

TEST_CASE("Sender, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "33600055";
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
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
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(79995 == Utils::gasLeft(result));

  CHECK("000000000000000000000000cd1722f2947def4cf144679da39c4c32bdc35681" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("Chain id, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "46600055";
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


  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(79995 == Utils::gasLeft(result));

  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("Extcodecopy verify gas", "[gasometer]") {
  // given
  uint256_t address = TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6");
  uint256_t sender = TestUtils::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681");
  std::string bytecode_str = "333b60006000333c600051600055";
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
    uint256_t(0xea0e9f), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    address, /* address */
    sender, /* sender */
    uint256_t(0xea0e9e), /* origin */
    100000, /* gas */
    uint256_t(0), /* gasPrice */
    uint256_t(0), /* value */
    std::make_shared<bytes_t>(codeBytes), /* code */
    std::make_shared<bytes_t>() /* data */
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();
  external->codeResponder.push_back(std::make_pair(sender, Hex::hexToBytes("6005600055")));

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
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(79935 == Utils::gasLeft(result));

  CHECK("6005600055000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("Blockhash, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "600040600055";
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    uint256_t(0xea0e9e), /* sender */
    TestUtils::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
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
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(79974 == Utils::gasLeft(result));

  CHECK("f1250fd89a1c3e517ae92cc1f73865c594bfad34db20f3b3396af4efe19d3bfb" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("Calldataload verify gas", "[gasometer]") {
  // given
  uint256_t address = TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6");
  uint256_t sender = TestUtils::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681");

  bytes_t codeBytes = Hex::hexToBytes("600135600055");
  bytes_t dataBytes = Hex::hexToBytes("0123ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23");

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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), 
    TestUtils::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"),
    uint256_t(0x1283fe), /* origin */
    100000,
    uint256_t(0),
    uint256_t(0),
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>(dataBytes)
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
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(79991 == Utils::gasLeft(result));

  CHECK("23ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("Multiply, store the result, verify gas", "[gasometer]") {
  // given
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


  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(79983 == Utils::gasLeft(result));

  CHECK("000000000000000000000000000000000000000000000000734349397b853383" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("Subtract, store the result, verify gas", "[gasometer]") {
  // given
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


  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(79985 == Utils::gasLeft(result));

  CHECK("0000000000000000000000000000000000000000000000000000012364ad0302" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("Division, store the result, verify gas", "[gasometer]") {
  // given
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


  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(79983 == Utils::gasLeft(result));

  CHECK("000000000000000000000000000000000000000000000000000000000002e0ac" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("Div zero, store the result, verify gas", "[gasometer]") {
  // given
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


  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(94983 == Utils::gasLeft(result));

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("Mod, store the result, verify gas", "[gasometer]") {
  // given
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


  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(74966 == Utils::gasLeft(result));

  CHECK("0000000000000000000000000000000000000000000000000000000000076b4b" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x01), context->codeAddress))
  );
}

TEST_CASE("SMOD, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "650123651246236265432290076000556501236512462360009007600155";
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


  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(74966 == Utils::gasLeft(result));

  CHECK("0000000000000000000000000000000000000000000000000000000000076b4b" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x01), context->codeAddress))
  );
}

TEST_CASE("SDIV, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "650123651246236265432290056000556501236512462360009005600155";
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


  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(74966 == Utils::gasLeft(result));

  CHECK("000000000000000000000000000000000000000000000000000000000002e0ac" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x01), context->codeAddress))
  );
}

TEST_CASE("Exp, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "6016650123651246230a6000556001650123651246230a6001556000650123651246230a600255";
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


  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(39923 == Utils::gasLeft(result));

  CHECK("90fd23767b60204c3d6fc8aec9e70a42a3f127140879c133a20129a597ed0c59" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000012365124623" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("Comparison, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "601665012365124623818181811060005511600155146002556415235412358014600355";
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


  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(49952 == Utils::gasLeft(result));

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x02), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x03), context->codeAddress))
  );
}

TEST_CASE("Signed comparison, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "60106000036010818112600055136001556010601060000381811260025513600355";
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


  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(49940 == Utils::gasLeft(result));

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x02), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x03), context->codeAddress))
  );
}

TEST_CASE("Bitops, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "60ff610ff08181818116600055176001551860025560008015600355198015600455600555";
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
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    uint256_t(0xea0e9a), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"),
    uint256_t(0x1283fe), /* origin */
    150000,
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
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(44937 == Utils::gasLeft(result));

  CHECK("00000000000000000000000000000000000000000000000000000000000000f0" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000fff" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000f0f" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x02), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x03), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x04), context->codeAddress))
  );
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x05), context->codeAddress))
  );
}

TEST_CASE("Add mod - mul mod, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "60ff60f060108282820860005509600155600060f0601082828208196002550919600355";
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


  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(19914 == Utils::gasLeft(result));

  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
  CHECK("000000000000000000000000000000000000000000000000000000000000000f" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x01), context->codeAddress))
  );
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x02), context->codeAddress))
  );
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x03), context->codeAddress))
  );
}

TEST_CASE("Byte, store the result, verify gas", "[gasometer]") {
  // given
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


  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(74976 == Utils::gasLeft(result));

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x01), context->codeAddress))
  );
}

TEST_CASE("Signextend, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "610fff60020b60005560ff60200b600155";
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


  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(59972 == Utils::gasLeft(result));

  CHECK("0000000000000000000000000000000000000000000000000000000000000fff" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x01), context->codeAddress))
  );
}

TEST_CASE("Pop, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "60f060aa50600055";
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


  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(79989 == Utils::gasLeft(result));

  CHECK("00000000000000000000000000000000000000000000000000000000000000f0" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("Extops, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "5a6001555836553a600255386003553460045560016001526016590454600555";
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
    uint256_t(0xea0e9f), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* sender */
    uint256_t(0xea0e9e), /* origin */
    150000, /* gas */
    uint256_t(0x32), /* gasPrice */
    uint256_t(0x99), /* value */
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
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(29898 == Utils::gasLeft(result));

  CHECK("0000000000000000000000000000000000000000000000000000000000000004" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x00), context->codeAddress))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000249ee" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000032" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x02), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000020" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x03), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000099" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x04), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000032" == 
    Utils::uint256_2str(accountState->get(external, uint256_t(0x05), context->codeAddress))
  );
}

TEST_CASE("Jumps, store the result, verify gas", "[gasometer]") {
  // given
  std::string bytecode_str = "600160015560066000555b60016000540380806000551560245760015402600155600a565b";

  bytes_t codeBytes = Hex::hexToBytes(bytecode_str);
  params_t params = {
    uint256_t(), /* codeAddress*/
    uint256_t(), /* codeHash */
    uint256_t(0), /* codeVersion */
    uint256_t(0), /* address */
    uint256_t(0), /* sender */
    uint256_t(0), /* origin */
    150000, /* gas */
    uint256_t(0x32), /* gasPrice */
    uint256_t(0), /* value */
    codeBytes, /* code */
    bytes_t() /* data */
  };
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
  exec_result_t result = vm.execute(operation, context, mem, accountState, external);

  // then
  CHECK(54117 == Utils::gasLeft(result));
}
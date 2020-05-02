//
// 01.05.2020
// Auto generated based off the Ethereum tests found here:
// https://github.com/ethereum/tests/blob/develop/VMTests/
//
#include "catch.hpp"
#include "test_utils.hpp"
#include <memory>
#include <evm/utils.hpp>
#include <evm/vm.h>
#include <evm/hex.hpp>

#include <evm/call.hpp>
#include <evm/gasometer.hpp>
#include <evm/big_int.hpp>
#include "external_mock.hpp"
#include <evm/operation.hpp>

TEST_CASE("calldataload_BigOffset______e118bc308ccdd052ea601f5cfa51d32fc907952cb1cd16e673bff87f8c9fe203", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7f420000000000000000000000000000000000000000000000000000000000000035600055");
  bytes_t data_bytes = Hex::hexToBytes("4200000000000000000000000000000000000000000000000000000000000000");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
}

TEST_CASE("calldatacopy2______3acb5771658d79d6ff4e17b69cfeea9bcc5e51ab11afb0c511b4d7be801e71d4", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60006001600037600051600055");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
}

TEST_CASE("address0______37a0fc3337fde7233f427195a290be689e01aa752a8394b0ae56306fd97d3624", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("30600055");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000f572e5295c57f15886f9b263e2f6d2d6c7b5ec6" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("calldatacopy2_return______4268c07197871b5b5c14bcda3f746a2bb787c8dba2d987bf3c1fb0bc1fc4db4c", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60006001600037600051600055596000f3");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
}

TEST_CASE("calldataload2______0274681bf0559ab144aa2273cd566d1b32bcc58843ca142e8c6e6fd567196882", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600535600055");
  bytes_t data_bytes = Hex::hexToBytes("123456789abcdef00000000000000000000000000000000000000000000000000024");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("bcdef00000000000000000000000000000000000000000000000000024000000" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("origin______4d51cb9ee576e04b08a74a6a4ba3f10284ee1f735dd068abd7a0e551324f45be", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("32600055");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("000000000000000000000000cd1722f3947def4cf144679da39c4c32bdc35681" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("calldatacopy_DataIndexTooHigh______72c5c7337895354e6d12b41ef4f144db87f945068a1a20134168f7e63f61a0d7", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600037600051600055");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
}

TEST_CASE("address1______2f317db88316ea284d36c3031d82818be81d6cf63d1bba9437dd22705282fe27", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("30600055");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* address */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* sender */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("000000000000000000000000cd1722f3947def4cf144679da39c4c32bdc35681" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("calldatacopyUnderFlow______55ea90b15f19bf8f4838c35234d202eab4473284e5895af23b885368f34200a1", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6001600237");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
}

TEST_CASE("calldatacopy_DataIndexTooHigh_return______640a52c64dfe9f43c6c5bb1aa4fc2a95839f352533e95fabe5493ff142b210c7", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600037600051600055596000f3");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
}

TEST_CASE("caller______79214a9fde65ef8c878dbf8e03a06a75483536d289ad19e56b95fdef57b1da3d", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("33600055");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("000000000000000000000000cd1722f3947def4cf144679da39c4c32bdc35681" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("gasprice______b94e3c994e54e24b85ef80fc16f53827cd26ef01fa4a96908a20e646f57d1e48", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("3a600055");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("075bcd15"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("00000000000000000000000000000000000000000000000000000000075bcd15" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("codecopy0______9354634ed14a9667c8c883c3a4eceaae263bcd3d4fe47683aa0f38f45fe877e9", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60056000600039600051600055");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("6005600060000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("calldatacopyZeroMemExpansion_return______b00f6239c55457bfec8870ad2ffaa42b2b53228c4f610eba391b8ce561dc9d4f", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60006000600037600051600055596000f3");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
}

TEST_CASE("calldatacopy1_return______671deccb615f7d6e58bc195d11ad4fde489a6a07581f9e32e029e6cf42dba991", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016001600037600051600055596000f3");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("3400000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("calldatasize2______cbd842b7c2ff77d176d3d7b5f200e908c22e47ee9a7d0f5294be85c917119f1e", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("36600055");
  bytes_t data_bytes = Hex::hexToBytes("230000000000000000000000000000000000000000000000000000000000000023");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000021" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("codecopyZeroMemExpansion______41a8841a95018c2d228db91d29d0b75992f9a166e4207362e79d17229974ddfd", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60006000600039600051600055");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
}

TEST_CASE("calldatacopy_sec______9c7568cda862ed10722f83b99c948af03cb38ae4042d45fa55aae12cca979f88", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6005565b005b6042601f536101036000601f3760005180606014600357640badc0ffee60ff55");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000badc0ffee" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0xff), context->codeAddress, external))
  );
}

TEST_CASE("calldatasize1______7db2dda9d80c7eac5ae82d3e2573e7f9b47ad6cb0c5545824e2500e85ec1cc3c", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("36600055");
  bytes_t data_bytes = Hex::hexToBytes("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000021" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("calldatacopyZeroMemExpansion______99d8509de4a25c88abd0647c68310552c67f395a92f4e6a8e67cc3707af076c5", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60006000600037600051600055");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
}

TEST_CASE("codecopy_DataIndexTooHigh______f6fac567f89aaca85c34c5a88b98870d1f7e2509b26ec566232c5d107741c6f4", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60087ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600039600051600055");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
}

TEST_CASE("codesize______632259bbd9962abfa58ec3b9e7b80a8f3babcdb47592bbc511fa5e4c0bc3ce3f", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("38600055");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000004" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("calldataloadSizeTooHighPartial______8090196f324f686f77a7d362987f8697cfc7b6b3bd86d702a212d790ec12ef0f", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600a35600055");
  bytes_t data_bytes = Hex::hexToBytes("123456789abcdef00000000000000000000000000000000000000000000024");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000240000000000000000000000" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("calldatacopy_DataIndexTooHigh2______bf92d18c0d12f1e9d48a5cf116ece7559ad36d67383a8b25792b4b6003180304", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60097ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600037600051600055");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
}

TEST_CASE("calldatasize0______e638e627686d20765a98fa8cfab03c642bdf33216a5869e742994072c8fd051e", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("36600055");
  bytes_t data_bytes = Hex::hexToBytes("2560");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("calldataloadSizeTooHigh______0a556d7e2b38d3ac82c12938237c81673868011512d36133443339bc000d56c5", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa35600055");
  bytes_t data_bytes = Hex::hexToBytes("123456789abcdef00000000000000000000000000000000000000000000000000024");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
}

TEST_CASE("calldatacopy0______761871556943693860bdddd26da931c7c3f5a6c8ab95f680aa9d5854135dacd0", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60026001600037600051600055");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("3456000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("calldatacopy0_return______4f9c0f3aff470ea35ad2fd5a81a593742f875409dbc51200199dd0f2baab261d", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60026001600037600051600055596000f3");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("3456000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("calldataload0______3bfae7447ad076b4da51568b72acb70e9bd946fbf68a79705015c4600d9d99de", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600035600055");
  bytes_t data_bytes = Hex::hexToBytes("2560");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("2560000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("calldatacopy_DataIndexTooHigh2_return______990882750573f3f5938a3f2cd66b0f41c842538f70d70045e179d246b8a076e0", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60097ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600037600051600055596000f3");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
}

TEST_CASE("calldataload1______3cda66b7abff563a2178c736c6ff9235784bbc4083083c1880268c1f32281606", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600135600055");
  bytes_t data_bytes = Hex::hexToBytes("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("callvalue______4eabc176dc48df11702d9ddf6e8501c62035436adb16aa7cd79769ab273d583a", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("34600055");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000de0b6b3a7640000" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("calldatacopy1______65659a844a3d4458eb82347f1ef56c3657abdb06f7166b033329db7c2c8cdb78", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016001600037600051600055");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("0f4240"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("3b9aca00"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
    false,
    std::make_shared<bytes_t>(code_bytes),
    std::make_shared<bytes_t>(data_bytes)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>();
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  std::shared_ptr<Memory> mem = std::make_shared<Memory>();
  Operation operation = Operation();

  // when
  vm.execute(0, operation, context, mem, pendingState, external);

  // then
  CHECK("3400000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}



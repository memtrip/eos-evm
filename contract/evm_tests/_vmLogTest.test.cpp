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

TEST_CASE("log2_logMemsizeTooHigh______9fb39d1608049d1d5455c7409514acc175724f2b1e43102d17b631862c3bc1a4", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd600052600060007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6001a2");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log1_nonEmptyMem______f3e28ff95bf5e800cd43ab50df02e0c38e9fa2b8205732a9ef4a9c7c4a881da6", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600052600060206000a1");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log4_logMemsizeZero______c7e7169c36cc57a6425d03859449560d8d7f48c189f2af5d90710d24de096912", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd600052600060006000600060006001a4");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log1_emptyMem______3284dac984331ac8d612e2bb4994f34e19f76861ed5294388fe95c283bd500fc", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600060006000a1");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log0_logMemsizeZero______e5b6bb2501704a5d2b73c86a3e02be967fdfc90fb58f2b4f5e6e3750406792ef", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260006001a0");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log2_emptyMem______6cc6686c11bbd223248c591c4c90a38f469fdb2571b7b6279a116ee07147b4be", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6000600060006000a2");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log4_nonEmptyMem_logMemSize1_logMemStart31______4f7869f982d0f61e794df14e64040914832b8e4f7d643c94bb9d2694ce228450", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260006000600060006001601fa4");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log1_logMemsizeZero______583cfb6cec3eb602dc034886dfc2e2171da94941d0bbb8c36156bcf50d2b6827", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd600052600060006001a1");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log2_Caller______bf2bb94ebe5938744184e8a6f7b2a5eaa274b40d3a92b6802153133a1f8d64ef", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff60005333600060206000a2");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log1_logMemsizeTooHigh______17e5a63a7a389f823678de07caa666ff5148749e4697b54e304dd9407312c672", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6001a1");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log2_logMemsizeZero______686ccc981e9622bcfeb6161ad1d9f71a70d91b3d828ee46bffb105be3394dbab", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000526000600060006001a2");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log2_logMemStartTooHigh______d45766f7e33ecc09cc11f00e216474469c49933a5777d8599ad60fd51e1ab3e1", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000526000600060017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa2");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log3_logMemsizeZero______69bd3e5dcb7e699abcb3faa58aa9a80a6ff20e8287c8f4981f4973cbba96e192", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260006000600060006001a3");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log2_MaxTopic______d3c300433ba07e9e91cab5d9ad174a159012c1975b3b69c3ceedb895132265c6", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000527fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60206000a2");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log1_logMemStartTooHigh______b6a326587a3dbbd977d24a247338ade2c2feed85e53de7b8067809c00034cd6d", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd600052600060017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa1");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log0_nonEmptyMem______0cfc646681837311fb39e1273123794960fbb9ea4e424578f87a551a36df6fae", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60005260206000a0");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log0_logMemsizeTooHigh______04fe0fcd01a67dcc0bbc0ea972f7af4c8695a6b63170a53ac5d11ce437bc7904", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000527fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6001a0");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log_2logs______59ad5528d89751649749405f4a5cd70d8a03875afb90fa0d4d6824d3d96a390f", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60005260206000a060106002a0");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log1_Caller______33df8d2b8c92e29404110e09be9bd88bc1f685e12067c07e534f683ccebc5ac7", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff6000533360206000a1");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log3_nonEmptyMem_logMemSize1______baeb20e8806b5cf814426f11178bd4d5ac34165b77a660713d5202e166784e72", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260006000600060016000a3");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log0_nonEmptyMem_logMemSize1______a20cb10f863eb27a33608f41f9d3de3d25a37da55aadb03a2a794cc5dedcaa05", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260016000a0");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log4_Caller______8ea00f94cec5a457cac5de1731aa75c588c13d2eab55297aa7a3b62c268add1f", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff6000533360006000600060206000a4");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log4_logMemsizeTooHigh______13b51aeb36d62dac84da56023d6406a59c83490d2640d4d6abdf89c2d55c9fed", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260006000600060007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6001a4");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log4_nonEmptyMem______a3c64c86ba9a76871b7c3c281a0454708cdb5e91ca611b55df194bab9a1fafaf", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600052600060006000600060206000a4");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log1_MaxTopic______0a4c414906a74571451b62d5cbccfd73c420f46831681365491d35d780a1c98a", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000527fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60206000a1");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log3_logMemsizeTooHigh______f2c5e55c6680ac4b66054f399561cbe97badde7f2f3292132ab9d36b2b160464", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000526000600060007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6001a3");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log3_PC______8d7beb47cc14822075ce2fbac294728f8faba640e26a7ed370eafa8e590df2d0", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff60005358585860206000a3");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log3_nonEmptyMem_logMemSize1_logMemStart31______bda2d24ce0f250b08877fc4e9da8c2952804af9662c3af30db45995f0cd80ce4", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000526000600060006001601fa3");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log3_logMemStartTooHigh______9810608d983312d9f5ab12cd9358825f20f92ca174905c314a551082406dea1a", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260006000600060017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa3");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log1_nonEmptyMem_logMemSize1______49ec0b89dab4beb39bb4dbc58191f465ef09c133df05d7444cc5dfc95274360f", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd600052600060016000a1");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log4_MaxTopic______1928e2558239ffc6fbb18068e3f1428cd7e60eb06e8dd308bce1938f5ee7144a", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000527fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60206000a4");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log3_Caller______fae584b1f6d4f92ed0b072ce8f7842b2ca367ab838949e51830c9ca8f70713c5", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff600053336000600060206000a3");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log3_nonEmptyMem______1d2ad4f6f79e0161150ea4ae333a9df11e1099df23fff0eb0844c70f77dabe60", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60005260006000600060206000a3");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log3_MaxTopic______b7120956567b5710f9dd49ac0db7e43d839a6a026598143cff9b58d02e61193a", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000527fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60206000a3");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log1_nonEmptyMem_logMemSize1_logMemStart31______dfba77e757549bc564c542df0e94e48a135e817f9f53455000827eaafeffb307", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260006001601fa1");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log2_nonEmptyMem_logMemSize1______0db120840474461ba7c4de523260af515ca7424bc998312fd5cbd21a955e627e", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000526000600060016000a2");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log2_nonEmptyMem_logMemSize1_logMemStart31______fad1ccc7b33b11ea24c70737aa879fd8172c7ba8b413bca9002e360f15cb0377", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd600052600060006001601fa2");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log3_emptyMem______f39ac12e960ba98b1d6d52dbe564caded52a338cb16b7924869a1b8c2a77188c", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60006000600060006000a3");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log4_logMemStartTooHigh______b231ee785a24fab97ccfb8dde384ecbb03ea86bd9c5b7a8e7c602b7f1b347ab7", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd600052600060006000600060017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa4");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log4_nonEmptyMem_logMemSize1______2e590a92288accca39422740f9b8c7d946723b636dcaf988e583438247ef8e75", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd600052600060006000600060016000a4");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log2_nonEmptyMem______a1c8ae74a72e0723f39e564ff0843ed03b579c9e7ae7b0c13d755c78a4589705", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6000526000600060206000a2");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log4_PC______1c6a8d77e5986d32795ac6f8757849527822e91848f34f531cc5c81cfbcdebcd", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff6000535858585860206000a4");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log4_emptyMem______1d899abc32e13324725840e9b79042f03f389f1ab1a3fb013b9a2d49261d795b", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600060006000600060006000a4");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log0_nonEmptyMem_logMemSize1_logMemStart31______777ce021b26b0e4f62b98b595d6ee69ce21d83027c2975ef24f51af29416b9fa", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000526001601fa0");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log0_logMemStartTooHigh______7cc27fdfcb258a0528c94496e60e3b10907a4d241b9d9e685e72597c472aa1b1", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa0");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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

TEST_CASE("log0_emptyMem______dddfbdc5d0776cd04613d3515648fa20eb5dc10a86b4e393b1ef818a28c82095", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60006000a0");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
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



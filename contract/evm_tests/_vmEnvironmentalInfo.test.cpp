//
// 14.05.2020
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

TEST_CASE("calldataload_BigOffset______e92194914f8eaa68524e2fbd430f8f434ac585013b8a47ed3a179130f33a5184", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7f42000000000000000000000000000000000000000000000000000000000000003560005500");
  bytes_t data_bytes = Hex::hexToBytes("4200000000000000000000000000000000000000000000000000000000000000");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
}

TEST_CASE("calldatacopy2______8bd27dcf56a5fc6cf1e944b4b93ab7a6d3e89a899a249a336e46c7d6d41271cd", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6000600160003760005160005500");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
}

TEST_CASE("address0______d2153e7f4d59454f16f00abb1e2fe2e172830e6164f5be2cd29761f6bef47194", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("3060005500");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("0000000000000000000000000f572e5295c57f15886f9b263e2f6d2d6c7b5ec6" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("calldatacopy2_return______68cfce0f6a821a80c32d144556d14eacab7bd2e7f56176ba64f3daa4e62484db", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60006001600037600051600055596000f300");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
}

TEST_CASE("calldataload2______b87662d5ecb0ee70b88059bfce95d2dde81bc573aae982f6a835a4d4aa13ed0e", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60053560005500");
  bytes_t data_bytes = Hex::hexToBytes("123456789abcdef00000000000000000000000000000000000000000000000000024");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("bcdef00000000000000000000000000000000000000000000000000024000000" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("origin______98200000626ee316522fa419c3bc652ea21bf9fc8cc5ea8da5f5045ea96c2efb", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("3260005500");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("000000000000000000000000a94f5374fce5edbc8e2a8697c15331677e6ebf0b" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("calldatacopy_DataIndexTooHigh______9d64252755a4f9037cba23e34e5f2f0d12201f7c808f81b5726d3c832584b65b", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa60003760005160005500");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
}

TEST_CASE("address1______f156ae1427e2919d529829c4ff6775b7453b4822937c24013fc85f8a300acbd2", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("3060005500");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* address */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* sender */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("000000000000000000000000cd1722f3947def4cf144679da39c4c32bdc35681" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("calldatacopyUnderFlow______2e6145527d0c175c6a7409d38c2befafab1f84a53f2f5ea654c5682da0dfee09", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600260013700");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
}

TEST_CASE("calldatacopy_DataIndexTooHigh_return______b09dd546a2a371e7d8a47fd28b61955fba17b10614c42ae6e37814868350caa1", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600037600051600055596000f300");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
}

TEST_CASE("caller______294550434578dd4f562656972febcc0615b576ae02da6fefd456f92a83f3a178", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("3360005500");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("000000000000000000000000a94f5374fce5edbc8e2a8697c15331677e6ebf0b" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("gasprice______19456c127f98922cc89869a50acef218af8b65c62e46e4d7786e3de31d907948", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("3a60005500");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("000000000000000000000000000000000000000000000000000000000000000c" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("codecopy0______9853f1b117bb3cca0030545f0aa096c9f249d2b327e3e15916c6b73227551d86", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6005600060003960005160005500");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("6005600060000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("calldatacopyZeroMemExpansion_return______06f76845fe79e1e25af55961b3b19d90654d23179cc8e74b6ae93a1cac50a1ed", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60006000600037600051600055596000f300");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
}

TEST_CASE("calldatacopy1_return______ff4a0ade893a383451dbfeec7f650cbc8b743c69a9af7dce8e35562d6f6fe4bf", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016001600037600051600055596000f300");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("3400000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("calldatasize2______1ad1119299f35a1ba1fddf097a4fcdbf6753c1a26439b5b9683a089667089d0f", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("3660005500");
  bytes_t data_bytes = Hex::hexToBytes("230000000000000000000000000000000000000000000000000000000000000023");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000021" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("codecopyZeroMemExpansion______70f6e78f5f8ffaed53ec5b52d17e22424c5c110d043e59dd78349a6e176829df", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6000600060003960005160005500");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
}

TEST_CASE("calldatacopy_sec______15323dbe31a91339553ce7d5197229c685d975fb40bd35739f7397b8b779fe72", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6005565b005b6042601f536101036000601f3760005180606014600357640badc0ffee60ff55");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000badc0ffee" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0xff),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0xff), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("calldatasize1______ad1349d5e6d70cf38b831de08f866ee8902618a667da450eb279c5b39fb94784", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("3660005500");
  bytes_t data_bytes = Hex::hexToBytes("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000021" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("calldatacopyZeroMemExpansion______ce6a997314ad1ba5b483f764ed64699624914cccb230499752652d6b63aa301f", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6000600060003760005160005500");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
}

TEST_CASE("codecopy_DataIndexTooHigh______6a5a1aa1f2dddb2c524ed6f1e216814462dfcb91f5001c0392dcc903bd47ee3c", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60087ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa60003960005160005500");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
}

TEST_CASE("codesize______65b39c55e2e41f5faf305f21e2761639a3d4eb8fe21e233e0c48d69fc6621752", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("3860005500");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000005" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("calldataloadSizeTooHighPartial______2a812d43752bf76dc6cfe8efba32c0d1a3cd6c15f4646651e9cae9a1fe1bc7a3", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600a3560005500");
  bytes_t data_bytes = Hex::hexToBytes("123456789abcdef00000000000000000000000000000000000000000000024");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000240000000000000000000000" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("calldatacopy_DataIndexTooHigh2______164fa3d98d49e4d745f3b63bb9d093b75be9fec10da729a5b2b228ba1092958b", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60097ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa60003760005160005500");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
}

TEST_CASE("calldatasize0______cfb2c972fc3666c4e23f3f8c958393431ae18ce0954b95ce9fc32ad6575f714e", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("3660005500");
  bytes_t data_bytes = Hex::hexToBytes("2560");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("calldataloadSizeTooHigh______3b3ed1426074a870b48afb77b67c46c8c7b59f0bbe563c5ba8d29ade563049f5", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa3560005500");
  bytes_t data_bytes = Hex::hexToBytes("123456789abcdef00000000000000000000000000000000000000000000000000024");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
}

TEST_CASE("calldatacopy0______f51dcaa74870531418fc87e57f55edd955e428ddfdd4650e41984bd544f0425f", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6002600160003760005160005500");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("3456000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("calldatacopy0_return______340beddeffa11c976a3185b6332be05a6e98fb258ae85e085cb432b148859db8", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60026001600037600051600055596000f300");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("3456000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("calldataload0______4bed34e4fa23bc5d6619dfddc54ea8eee9dea401022363ad16e0b39acef239ca", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60003560005500");
  bytes_t data_bytes = Hex::hexToBytes("2560");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("2560000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("calldatacopy_DataIndexTooHigh2_return______fcddba5ae383bede89e8d2a03ebf05069f5f3221ffa516faa7fa309c263e5888", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60097ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600037600051600055596000f300");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
}

TEST_CASE("calldataload1______97a1ddaa3b85cbb0cf2e43c7f250e64c8f7efa0abb0e9a4abe7458b63f618537", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60013560005500");
  bytes_t data_bytes = Hex::hexToBytes("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("callvalue______ffc2710e200fe7f6535015c9ec15a74a7238e126942376a557aaeeaf7f9a99f3", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("3460005500");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0a"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}

TEST_CASE("calldatacopy1______6c09d2420e8dc4d5508ec35f60140762086aad4b142f433da7f43000ea2d9366", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6001600160003760005160005500");
  bytes_t data_bytes = Hex::hexToBytes("1234567890abcdef01234567890abcdef0");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
    TestUtils::fromHex("03e8"), /* timestamp */
    TestUtils::fromHex("7fffffffffffffff"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("020000"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* sender */
    TestUtils::fromHex("a94f5374fce5edbc8e2a8697c15331677e6ebf0b"), /* origin */
    gas_t(0x174876e800), /* gas */
    TestUtils::fromHex("0c"), /* gasPrice */
    TestUtils::fromHex("0b"), /* value */
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
  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  // when
  vm.execute(0, context, mem, operation, gasCalculation, pendingState, external);

  // then
  CHECK("3400000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(
      pendingState->getState(
        uint256_t(0x00),
        context->codeAddress, [external, context] () {
          return external->storageAt(uint256_t(0x00), context->codeAddress);
        }
      )
    )
  );
}



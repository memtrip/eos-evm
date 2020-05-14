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

TEST_CASE("sha3_0______b99ef89ec788de6255a65927490820dc07d19dc71b40115513c7aa518465ef20", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600060002060005500");
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
  CHECK("c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470" ==
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

TEST_CASE("sha3_memSizeNoQuadraticCost31______7bd0bcdfd4ed3cd89ee9c763c8975326daf6a12e132d6ebb11120ea0af469c2d", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016103c02060005500");
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
    gas_t(0x0100000000), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
    TestUtils::fromHex("7c"), /* value */
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
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
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

TEST_CASE("sha3_memSizeQuadraticCost63______4d8a8b59f65435245ba2fea14c0a92bf735bac63f97e5955f50767e93102b0b9", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016107c02060005500");
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
    gas_t(0x0100000000), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
    TestUtils::fromHex("7c"), /* value */
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
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
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

TEST_CASE("sha3_1______ece29a11a21213fddea869679952a15d24f89ccfd2bf45d7a00ff003df498ceb", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600560042060005500");
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
    gas_t(0x0186a0), /* gas */
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
  CHECK("c41589e7559804ea4a2080dad19d876a024ccb05117835447d72ce08c1d020ec" ==
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

TEST_CASE("sha3_memSizeQuadraticCost65______c7611dde7c250d3c5a84af161483675030397c9fdb92ffc10b2e002f0aab93c0", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016108002060005500");
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
    gas_t(0x0100000000), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
    TestUtils::fromHex("7c"), /* value */
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
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
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

TEST_CASE("sha3_memSizeQuadraticCost32______1082cc892869c28a6d15724217c7f7383b4032632c74b77d112052950436eca3", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016103e02060005500");
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
    gas_t(0x0100000000), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
    TestUtils::fromHex("7c"), /* value */
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
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
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

TEST_CASE("sha3_bigOffset______ab8775e308b58ee75d3ef19d554c74e8ffb9c4376907a328b953d71a68f40ae3", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60027e0fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff2060005500");
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
    gas_t(0x010000000000), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
    TestUtils::fromHex("7c"), /* value */
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

TEST_CASE("sha3_6______bbd86d101066e8b383a6cbf5c4101779825de64cd97f97bbbca14d44010e33fa", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff2060005500");
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
    gas_t(0x0186a0), /* gas */
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

TEST_CASE("sha3_memSizeQuadraticCost33______ed7993323c0c82f074fe9edcaca291adb2270752b1ebe7c875d221d2f03e45d2", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016104002060005500");
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
    gas_t(0x0100000000), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
    TestUtils::fromHex("7c"), /* value */
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
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
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

TEST_CASE("sha3_memSizeQuadraticCost64______3b256f546c6cbdbe9661e3bd5310f1bacb2456c7ef5b490e8437cc60ce528c55", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016107e02060005500");
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
    gas_t(0x0100000000), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
    TestUtils::fromHex("7c"), /* value */
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
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
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

TEST_CASE("sha3_memSizeQuadraticCost64_2______4ad5c8a3eb5039f86c15c25bf291ccfd47ae2defdfcef7f961348cfcca8d5877", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60206107e02060005500");
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
    gas_t(0x0100000000), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
    TestUtils::fromHex("7c"), /* value */
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
  CHECK("290decd9548b62a8d60345a988386fc84ba6bc95484008f6362f93160ef3e563" ==
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

TEST_CASE("sha3_4______1a753ff8e419c74ac7cdafedbb77ea085c33f3503beb0090d6b25173cf180c5c", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6064640fffffffff2060005500");
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
    gas_t(0x0186a0), /* gas */
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

TEST_CASE("sha3_5______fdf4310e913f6039c9c5b0d741f0e4bbaa54e233cede4c7f3fc2e39769749bea", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("640fffffffff6127102060005500");
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
    gas_t(0x0186a0), /* gas */
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

TEST_CASE("sha3_bigSize______e140749a85369fcc3c6177951bc816b073deb941cf910b5927acb2ee8adfb059", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff2060005500");
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
    gas_t(0x010000000000), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
    TestUtils::fromHex("7c"), /* value */
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

TEST_CASE("sha3_2______0a41ee61592815f2e8ea81001358719f022ed41f4fdd4fea73c789af3dcd7d36", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600a600a2060005500");
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
    gas_t(0x0186a0), /* gas */
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
  CHECK("6bd2dd6bd408cbee33429358bf24fdc64612fbf8b1b4db604518f40ffd34b607" ==
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

TEST_CASE("sha3_memSizeQuadraticCost32_zeroSize______1f9a4d4b0235fbd4b45a48b1bc9790de0aecb64ea89dea73a13a14c7f25f723c", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60006104002060005500");
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
    gas_t(0x0100000000), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
    TestUtils::fromHex("7c"), /* value */
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
  CHECK("c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470" ==
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

TEST_CASE("sha3_3______36cb8a641285b7dcbf2be71e4ecd3abf358bd3b24daace8768460906d54e4cac", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("620fffff6103e82060005500");
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
    gas_t(0x0186a0), /* gas */
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

TEST_CASE("sha3_bigOffset2______2a72ad916044fc2fa16f2490b7a25216d042d81ab073964ead1e3231692b9b05", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600263010000002060005500");
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
    gas_t(0x1000000000), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
    TestUtils::fromHex("00"), /* value */
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
  CHECK("54a8c0ab653c15bfb48b47fd011ba2b9617af01cb45cab344acd57c924d56798" ==
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



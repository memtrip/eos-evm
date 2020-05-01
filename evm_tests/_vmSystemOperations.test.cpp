//
// 25.04.2020
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

TEST_CASE("return0______1cd2b9480f1f5bdd82e8026b6342008ef84d318c3f9f173eae7d09e50eaf26b3", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("603760005360005160005560016000f3");
  bytes_t data_bytes = Hex::hexToBytes("aa");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("989680"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* address */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* sender */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
    TestUtils::fromHex("17"), /* value */
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
  CHECK("3700000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("return1______5cd716a8e8d460b10e0dc1b3d5b6394f0c388e0e36246bf124478b0cb86a1f76", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("603760005360005160005560026000f3");
  bytes_t data_bytes = Hex::hexToBytes("aa");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("989680"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* address */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* sender */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
    TestUtils::fromHex("17"), /* value */
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
  CHECK("3700000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("suicideSendEtherToMe______0cf005812e9c99dc87bdd8463a9849a0164a9e02b3d09eaab228267d6c8c703e", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("30ff");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("989680"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x03e8), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
    TestUtils::fromHex("0186a0"), /* value */
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

TEST_CASE("TestNameRegistrator______7e0e4bcbcbe8bcaf9a8535e65d4c6665db752910953b5eafc63da8f7cdff20b7", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6000355415600957005b60203560003555");
  bytes_t data_bytes = Hex::hexToBytes("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffafffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa");

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
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
    TestUtils::fromHex("0de0b6b3a7640000"), /* value */
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
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa" ==
    Utils::uint256_2str(
      pendingState->getState(
        TestUtils::fromHex("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa"),
        context->codeAddress,
        external
      )
    )
  );
}

TEST_CASE("suicideNotExistingAccount______ba450a40efb62a9fb6e16e3bced0afde8d0b08b9c0f78979f35fc45b9de72816", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("73aa1722f3947def4cf144679da39c4c32bdc35681ff");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("989680"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x03e8), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
    TestUtils::fromHex("0186a0"), /* value */
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

TEST_CASE("return2______4181cbf262c1dc2cdc186e007ec6c13466bd031b190b07874b1177a00717deeb", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("603760005360005160005560216000f3");
  bytes_t data_bytes = Hex::hexToBytes("aa");

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("989680"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* address */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* sender */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* origin */
    gas_t(0x0186a0), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
    TestUtils::fromHex("17"), /* value */
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
  CHECK("3700000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("suicide0______56c8766e8a1687dfe807b1e8f2d0454267f432c7e3035ff5fa9c27a2d594739d", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("33ff");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("989680"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x03e8), /* gas */
    TestUtils::fromHex("5af3107a4000"), /* gasPrice */
    TestUtils::fromHex("0186a0"), /* value */
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



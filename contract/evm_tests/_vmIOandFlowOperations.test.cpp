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

TEST_CASE("jumpAfterStop______1527b83fd9a930436902b171302c40812a33a035bf148e5c40f362e811b1ad54", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6006560060015b6002600355");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x03), context->codeAddress, external))
  );
}

TEST_CASE("JDfromStorageDynamicJump0_withoutJumpdest______696ced07844f15bee009a7c294048b5bf531923787279c19bf1c3150a46bf0ff", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6023600760005401566001600255");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  external->storageResponder.push_back(std::make_pair(
    uint256_t(0x00),
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000004"))
  ));

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

TEST_CASE("DynamicJumpStartWithJumpDest______4fb19acd65703dce630cb655f52e98d2de72d8a790d53b895d0e7bce603d4166", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("5b586000555960115758600052596000575b58600055");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000012" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("jump0_jumpdest0______4bf0cfbeda98acdd577972c6a7abcd20f60ab1b48328ce3f804e3cefa7c77bdb", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("602360075660015b600255");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000023" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x02), context->codeAddress, external))
  );
}

TEST_CASE("sstore_load_1______28c5c7cfbcf28dd967743a82487d71c5d17eca75a90f019d227970c0ff927155", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff60005560ee600a55606454601455");
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
  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000000ee" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x0a), context->codeAddress, external))
  );
}

TEST_CASE("loop_stacklimit_1020______e3a67d3fc9f35b9e0db39be074d9160030b23790e568d0387f9d8f7e4190e40a", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6000345b60019003906001018180600357600052600152600059f3");
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
    TestUtils::fromHex("03fc"), /* value */
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

TEST_CASE("msize0______41daa7a08f4c4f0380b60446927c8a3d3f077fdd63de63ab8736353cf7c92d86", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff60005259600055");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000020" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("jumpiToUintmaxPlus1______58d51b8cb46082033f726f1bca929fb1713048436d52029e31f5bfcaaaded691", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6001640100000009575b5b6001600155");
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

TEST_CASE("mstore8WordToBigError______e7f6dfe7bcd73d4ee7ec71238711bd20d21eafc11b4b5e6c54ed69b2daf3c8bd", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600153600151600155");
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
  CHECK("ff00000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x01), context->codeAddress, external))
  );
}

TEST_CASE("jumpInsidePushWithJumpDest______d200f4e72a16a6960609912d97797b467afb3a98c1eef6f9eed2006c4111a7f3", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600456655b6001600155");
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

TEST_CASE("DynamicJump_value3______a1477eeb656e1f4d09c07f020a088cc099f6661fce88f137754b1d45550d7218", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016002600334565b5050600052596000f35b50600052596000f35b600052596000f3");
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
    TestUtils::fromHex("1b"), /* value */
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

TEST_CASE("indirect_jump1______33d6b4fa4d999fa02f0b584e925eef1e0b1f55bfe6bd8ba3bd0339ab20739a34", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600460030156005b6001600052596000f3");
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

TEST_CASE("JDfromStorageDynamicJump0_AfterJumpdest______06126bb58e44948750e412ea81a3140fcc72b63acec0090939706f3ceb403ae8", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60236008600054015660015b600255");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  external->storageResponder.push_back(std::make_pair(
    uint256_t(0x00),
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000004"))
  ));

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

TEST_CASE("DynamicJumpJD_DependsOnJumps1______853f3f35881b9db63508e68d34cf87a1a3697fdc969821c0659462242d859c2b", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600a436006575b5660015b6001600155");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x01), context->codeAddress, external))
  );
}

TEST_CASE("DynamicJumpi0______394cae3e06d120cc1a5df5e14cfae3598d62e1fefa06dce4055c6ff59c367b63", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("602360016009600301576001600255");
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

TEST_CASE("DynamicJumpi1______31d323d1c24dd2c2ea5a4e18fd0765bfa1be189add7e395b2679bf5a98e492ab", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("602360006009600301576001600255");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x02), context->codeAddress, external))
  );
}

TEST_CASE("DynamicJumpJD_DependsOnJumps0______e96143bec9697fb0d565026f5fcc5ed70833bf89eb8c63aa87e0155b4e61d8f4", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6009436006575b566001");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("01"), /* blockNumber */
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

TEST_CASE("DynamicJumpi1_jumpdest______fb4060a7f68c0f3ad9643dcfc93fa90ea0fe6123e65499ae65f400e22db20bcc", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60236001600a6003015760015b600255");
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

TEST_CASE("DynamicJumpiOutsideBoundary______d550aa41047204857f27b7a80a1309520f3e59b41a87ef3e40492032706e5a88", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60017ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0600301576002600355");
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

TEST_CASE("codecopyMemExp______baf738ce30cb457d16aa2f71f866ce00ddb998371757f2c6a30a5d1ca3a9e135", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff60ff630fffffff630fffffff39");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("01f4153d80"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x01f4153d80), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
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

TEST_CASE("DynamicJump_value2______00631169ba52dbbd3d7ac8529dd960c6b297226c0f177ee3e0ef8bd202b4b1ff", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016002600334565b5050600052596000f35b50600052596000f35b600052596000f3");
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
    TestUtils::fromHex("12"), /* value */
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

TEST_CASE("return1______fe0798e0775da11e784482b44b51322ad70f4deaa8ce8643841257d3abee2e1f", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6001620f4240f3");
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

TEST_CASE("mloadMemExp______b12ca5b81a2d597d774f63fd3e6301a3808c7090e1b5ee00ea980c846ddadf32", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("630fffffff51");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("01f4153d80"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x800570), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
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

TEST_CASE("jumpInsidePushWithoutJumpDest______451d199b9c77c3a3297bb20ba2a01c238e984283e3690b22c9614121c878d8ec", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60055661eeff");
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

TEST_CASE("JDfromStorageDynamicJumpifInsidePushWithoutJumpDest______561fed985eda1bbc4448ad363f6fa69a1d1b503d9d7e0017bcd49aaaf916f333", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016007600054015761eeff");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  external->storageResponder.push_back(std::make_pair(
    uint256_t(0x00),
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000004"))
  ));

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

TEST_CASE("jumpOntoJump______b7af74ccb70e4242810a2f47181f0c95ee1b9558385cff3a33896f29c7775d7e", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("565b600056");
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

TEST_CASE("BlockNumberDynamicJumpifInsidePushWithoutJumpDest______3fccd0c56ebfd40dea69fec03d009967a80ddf93e9a68af81efd2d1645e27fcb", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6001600743015761eeff");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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

TEST_CASE("DynamicJumpifInsidePushWithJumpDest______05f764377385769e93afe47dbc0293921c211b4e68afce30f18cba4bb5955420", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6001600660030157655b6001600155");
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

TEST_CASE("JDfromStorageDynamicJumpInsidePushWithoutJumpDest______53a491adcc7da05748ad36809954552784007b884cd960e05ebb07a2ddd0452b", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6005600054015661eeff");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  external->storageResponder.push_back(std::make_pair(
    uint256_t(0x00),
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000004"))
  ));

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

TEST_CASE("msize1______1bc7a7187b3aa498df95faec7fa0258d950df3afb6205db0f9e2997ffb7ec512", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("64ffffffffff60005259600055");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000020" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("DynamicJumpiAfterStop______d61d45e9d5ea3e13d2a8a33965c9c620207156e0b4baf2dfed9a0288c7e8053b", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016008600301570060015b6002600355");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x03), context->codeAddress, external))
  );
}

TEST_CASE("jumpHigh______a7725bef6c1ff691ae5ad3b73c3b44a6d16f9c9b1c0e57671d7ff59fe9ac9800", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("630fffffff565b5b6001600155");
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

TEST_CASE("loop_stacklimit_1021______c1bb4f6ff68cafca82606ffe4fbed88358dc3b19be5e69714e96478d8571c0fc", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6000345b60019003906001018180600357600052600152600059f3");
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
    TestUtils::fromHex("03fd"), /* value */
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

TEST_CASE("bad_indirect_jump2______6dd2730ab6f27b43eead1633f104f5d60d6a98fa7c81d5a8ba0d2f6434706813", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016003600302576000600056");
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

TEST_CASE("sstore_load_0______371f51e169fa8f7740cef83f469ff5f02034d301d027b0267cd999c9ea5ca633", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff60005560ee600a55600054601455");
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
  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000000ee" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x0a), context->codeAddress, external))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x14), context->codeAddress, external))
  );
}

TEST_CASE("jumpTo1InstructionafterJump_noJumpDest______91502d2804896fda92630c93005fc5c0e26591bac75b7fff576409271f81cdb6", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6003566001600055");
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
    gas_t(0x2710), /* gas */
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

TEST_CASE("for_loop1______5e12e078316618a30275a5c133a960d17d242cc3726855a805c112193d39a59e", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600a6080525b6000608051111560265760a0516080510160a0526001608051036080526005565b");
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

TEST_CASE("DynamicJump0_jumpdest2______a7e9d9f046151930ef4b51b8dacce5304ce74c3f5ead80f1e52f783b1a704378", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6023600a6008506003015660015b600255");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000023" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x02), context->codeAddress, external))
  );
}

TEST_CASE("mstore0______78e3311be5943f4a7995e11b3fe7e41fa432fae150d687201c617c70ae40f6d7", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600152600151600155");
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
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x01), context->codeAddress, external))
  );
}

TEST_CASE("JDfromStorageDynamicJump0_jumpdest0______2f836ba88951147677580e5de7d8d40b0ca72938894aa351096945d7962c8f62", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60236007600054015660015b600255");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  external->storageResponder.push_back(std::make_pair(
    uint256_t(0x00),
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000004"))
  ));

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
  CHECK("0000000000000000000000000000000000000000000000000000000000000023" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x02), context->codeAddress, external))
  );
}

TEST_CASE("BlockNumberDynamicJumpiOutsideBoundary______db80ec0400be086e2a316a91ee7a5f87db06ff6a5b0ad27a50ba692049a54b1c", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60017ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff04301576002600355");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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

TEST_CASE("jumpifInsidePushWithJumpDest______790a546e29160af651f091890cd367d79d28b345f43847fa5d19b6a0dab087e9", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6001600657655b6001600155");
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

TEST_CASE("JDfromStorageDynamicJumpInsidePushWithJumpDest______561a67bc9db1011fb26151b03adcc53b2f4f55e03292c1e98e3361250c87d38a", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60046000540156655b6001600155");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  external->storageResponder.push_back(std::make_pair(
    uint256_t(0x00),
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000004"))
  ));

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

TEST_CASE("BlockNumberDynamicJumpifInsidePushWithJumpDest______4b52bc3a45a966d0032eb01b3fdb8a225af48fa4f5a017b5dff3d4d88d710337", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016006430157655b6001600155");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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

TEST_CASE("DynamicJump_valueUnderflow______37f012edfeaa13e4819617af0e8dc2fd71d738a2463b1f61bfd86de0ef980f1b", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016002600334565b5050600052596000f35b50600052596000f35b505050600052596000f3");
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
    TestUtils::fromHex("1b"), /* value */
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

TEST_CASE("DynamicJumpInsidePushWithJumpDest______3f3586292e12e696029f38f833fe8c7cea86a0e7cda83c0cbe783aa2c3b22b0c", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600460030156655b6001600155");
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

TEST_CASE("DynamicJumpPathologicalTest1______dfbad553b0e28f37f6a5d72740e2ae6bf17ce1b19c62caf2cc2a99c0d1d84e05", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("435660615b4343025660615b60615b605b6001600155");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("04"), /* blockNumber */
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

TEST_CASE("jump0_withoutJumpdest______4023b9b32fabb7baeb154e319422cc24e852c858eb124713508a241df86f3969", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60236007566001600255");
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

TEST_CASE("jumpToUint64maxPlus1______17b7f86769171233d32af7b23fc33ba8e71f03a64f0625aadfe65a696dff36a6", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6801000000000000000b565b5b6001600155");
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

TEST_CASE("jumpi1______27f04b183d459deb05bc15b1281b0e300307950da1968f669bd8cbec2b200044", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("602360006009576001600255");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x02), context->codeAddress, external))
  );
}

TEST_CASE("mloadOutOfGasError2______8df8c3070849692634e4e7af44885da9c5d41df0717fd6d337aa7d5bfed56d52", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6272482551600155");
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

TEST_CASE("BlockNumberDynamicJumpInsidePushWithJumpDest______ca0f21a5f52a8d4f2d6e1eed650f68d5f8f40e567cf17984aacc228adfa578ab", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6004430156655b6001600155");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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

TEST_CASE("DynamicJumpifInsidePushWithoutJumpDest______cadedb13e141e3b7bf1f0763cc831dace3ff150fc623e81fb00e798168d01188", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600160076003015761eeff");
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

TEST_CASE("mloadError0______27a14368a9e5b964986445d0436e67f685ab0171ea0359b9a112fdc07d98bf53", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600051600055");
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

TEST_CASE("DynamicJump0_AfterJumpdest______605f607251cd4a7c73bd7c814edcada6a9008fcd2896af2caf371beb31db196b", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("602360086003015660015b600255");
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

TEST_CASE("JDfromStorageDynamicJumpiOutsideBoundary______3c7f35eb2fe3c2ed05679b25f89e81e50fa959c8a665cf4545552f75a3b7140b", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60017ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff060005401576002600355");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  external->storageResponder.push_back(std::make_pair(
    uint256_t(0x00),
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000004"))
  ));

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

TEST_CASE("mloadError1______f5841cfbab0e35ad5727493bc7b6e0cd075735640637e817001de707085c2608", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6017600152600051600155");
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

TEST_CASE("jumpToUintmaxPlus1______6897e3a469257a7905bf719e9ae36ac49f830eab122209a9c2e89c879cdaa2d7", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("640100000007565b5b6001600155");
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

TEST_CASE("jumpi0______86fb0cc0becb3234b287df55e90da9a860eff30714976e3395b25ee2e2b47c48", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("602360016009576001600255");
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

TEST_CASE("JDfromStorageDynamicJumpifInsidePushWithJumpDest______f15ca2a706c969bb0f9f4b7101efd666eebae5520f893a586a7a529b0dc7d4d8", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600160066000540157655b6001600155");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  external->storageResponder.push_back(std::make_pair(
    uint256_t(0x00),
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000004"))
  ));

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

TEST_CASE("DynamicJumpPathologicalTest0______6862ac2a8fad0b3c043493fcd9c9a7e8a549c9f3ef34019ac0d7bcfd096a8040", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("435660615b4343025660615b60615b5b5b6001600155");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("04"), /* blockNumber */
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x01), context->codeAddress, external))
  );
}

TEST_CASE("DynamicJump0_withoutJumpdest______84c524e0cafc2ddcebdef720e46a23d10061f4a35bb06bfe7bdfe444990593a6", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60236007600301566001600255");
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

TEST_CASE("jumpTo1InstructionafterJump_jumpdestFirstInstruction______1e05b7560aba357248c8fdddd62e9b8dfb943cc2c3bb9569c5d44c2322899ff4", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("5b6003565b6001600055");
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
    gas_t(0x2710), /* gas */
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

TEST_CASE("jumpifInsidePushWithoutJumpDest______c69048c65f19388408ec0027e2c9372b393d057d91c9e0eff2ea96f8bb59f66b", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600160075761eeff");
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

TEST_CASE("mstore1______424433d76d1f8d1622fa9796c232dbd9f31ddc1231efae876f6494ee7d1ccab2", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600201600152600151600155");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x01), context->codeAddress, external))
  );
}

TEST_CASE("jump0_AfterJumpdest3______dc15eff9141416358f3f9960ef23b930d70b7cb8d3e13d7d5b6832954605d062", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6023600b6008505660015b600255");
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

TEST_CASE("BlockNumberDynamicJump0_withoutJumpdest______6f1fc4a9e5dff3e5d3071c576aba5b2ee1f30d7dcace92e6c6d230cfd415efd7", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("602360074301566001600255");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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

TEST_CASE("BlockNumberDynamicJump0_jumpdest0______80bfa0a5db107e6f083dccdd3091e35add39a4eaac4a8757de8a3e4008c5d646", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6023600743015660015b600255");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000023" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x02), context->codeAddress, external))
  );
}

TEST_CASE("DynamicJumpPathologicalTest3______a906b3dcb41da1cdacb67bdf49111ecd2bdaab0e3584dbd3993ef0f0555766f6", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("435631615b60615b60615b606001600155");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("07"), /* blockNumber */
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

TEST_CASE("swapAt52becameMstore______b014aac7021775f56b763921bf12a663ca35c4aa230888cd7908edfa705b1413", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600260035255");
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

TEST_CASE("calldatacopyMemExp______fcf33988ecf7e66eae80382111d1128eb302e201be169ca20b306eac49231142", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff60ff630fffffff630fffffff37");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("01f4153d80"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x01f4153d80), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
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

TEST_CASE("mstore8_0______0a5e67d6603b41a69f94c4d3dcc06da69c17c841ba0cdc8e15a5203e89d217a7", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600153600151600155");
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
  CHECK("ff00000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x01), context->codeAddress, external))
  );
}

TEST_CASE("JDfromStorageDynamicJump0_jumpdest2______efe088c5366793bcb3339225486608b15750524274baf8d5f9f592c0d5e327f2", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6023600a600850600054015660015b600255");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  external->storageResponder.push_back(std::make_pair(
    uint256_t(0x00),
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000004"))
  ));

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
  CHECK("0000000000000000000000000000000000000000000000000000000000000023" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x02), context->codeAddress, external))
  );
}

TEST_CASE("DynamicJump0_jumpdest0______3ab9d036e3e345909b19022f4c3b80d081d214eb5c79b8e94e0f2c660ab01ec7", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("602360076003015660015b600255");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000023" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x02), context->codeAddress, external))
  );
}

TEST_CASE("DynamicJump0_AfterJumpdest3______b7367314ce66b1a937c05550ac901971b5850d2a0ef03acf1feb4d6c9f38925d", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6023600b6008506003015660015b600255");
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

TEST_CASE("jump0_AfterJumpdest______8e933f0185d188f6eeb002d4ac8dace70a34a196e4c59932957eaac4cef27849", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("602360085660015b600255");
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

TEST_CASE("jump1______c86900065dc3ca2743c247f2c7f305795833184ab64acf0c6911a899533ab628", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("620fffff620fffff0156");
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

TEST_CASE("deadCode_1______110e1eaddae6dda0225d4f4b430da33494473d9ec10d765e7a5324d3e1ab26c8", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6001600053596000f300000000000000005b00");
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

TEST_CASE("memory1______4962a1d10a8792cd1ad8a08ac500002adec8cc965fd1fb4d1c45cb3e558a9de6", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600260005360036001536000516001510160025260406000f3");
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

TEST_CASE("log1MemExp______241dbcb0d33d25f1db0b51b65c38c4e3ef2f5b52c799264979423508e3fcf934", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff60ff630fffffffa1");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("01f4153d80"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x01f4153d80), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
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

TEST_CASE("dupAt51becameMload______28d2da26fb721ff16c42b1d398e7410f85560c3373bcc0a424ee1d025bf25ba6", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600260035155");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("jump0_foreverOutOfGas______06656a40346ccda59a2d1852d9bb59447d34fb9eb80706e378c5a067e337a080", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("5b600056");
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

TEST_CASE("jump0_outOfBoundary______9442ba4b2e4625b3ba5d7a3c43a5c1bcbb0f71fb8977d9cb291a58f956e5d014", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60236007566001600255");
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

TEST_CASE("JDfromStorageDynamicJumpi0______14e786db1b2df2c2a40be1a80c61baec311572eb481a3afd1b31fb95a3ad937d", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60236001600960005401576001600255");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  external->storageResponder.push_back(std::make_pair(
    uint256_t(0x00),
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000004"))
  ));

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

TEST_CASE("kv1______e9c18f1395a9a5e541d26c02b68f69e413953c380102c17d783cc18b5092bbf2", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("33604555602d80600f6000396000f3604554331415602c575b366080511015602b576020608051013560805135556040608051016080526009565b5b");
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
  CHECK("000000000000000000000000cd1722f3947def4cf144679da39c4c32bdc35681" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x45), context->codeAddress, external))
  );
}

TEST_CASE("JDfromStorageDynamicJumpi1______f90389bdfe2c1600f16db3b5ff8289b55a9f3d2c56dd18403c4e636440a98a9d", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60236000600960005401576001600255");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  external->storageResponder.push_back(std::make_pair(
    uint256_t(0x00),
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000004"))
  ));

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
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x02), context->codeAddress, external))
  );
}

TEST_CASE("BlockNumberDynamicJumpiAfterStop______7331cec587701bf695329ad94c7e62963827209faffac3b24eb59341ccb1a925", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600160084301570060015b6002600355");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x03), context->codeAddress, external))
  );
}

TEST_CASE("jumpdestBigList______6e4f2dfe68bb0ae1bdce8e6385b098b9984176b12f76273d1a1f7e34f46d85db", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6009565b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b");
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
    gas_t(0x05f5e100), /* gas */
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

TEST_CASE("stackjump1______21d7234c731f6e2e771b45ce8ba46f258fcfee3c1c1f9060d5246302ef5f151e", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6004600660096014565b600a03600052596000f35b60005201600956");
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

TEST_CASE("byte1______4bbf3058007fbacf83926bd908a1f886cb4403aa10a95030f2da18e1ad68707b", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7f112233445566778899001122334455667788990011223344556677889900aabb60001a7f112233445566778899001122334455667788990011223344556677889900aabb60011a7f112233445566778899001122334455667788990011223344556677889900aabb60021a7f112233445566778899001122334455667788990011223344556677889900aabb60031a7f112233445566778899001122334455667788990011223344556677889900aabb60041a7f112233445566778899001122334455667788990011223344556677889900aabb60051a7f112233445566778899001122334455667788990011223344556677889900aabb60061a7f112233445566778899001122334455667788990011223344556677889900aabb60071a7f112233445566778899001122334455667788990011223344556677889900aabb60081a7f112233445566778899001122334455667788990011223344556677889900aabb60091a7f112233445566778899001122334455667788990011223344556677889900aabb600a1a7f112233445566778899001122334455667788990011223344556677889900aabb600b1a7f112233445566778899001122334455667788990011223344556677889900aabb600c1a7f112233445566778899001122334455667788990011223344556677889900aabb600d1a7f112233445566778899001122334455667788990011223344556677889900aabb600e1a7f112233445566778899001122334455667788990011223344556677889900aabb600f1a7f112233445566778899001122334455667788990011223344556677889900aabb60101a7f112233445566778899001122334455667788990011223344556677889900aabb60111a7f112233445566778899001122334455667788990011223344556677889900aabb60121a7f112233445566778899001122334455667788990011223344556677889900aabb60131a7f112233445566778899001122334455667788990011223344556677889900aabb60141a7f112233445566778899001122334455667788990011223344556677889900aabb60151a7f112233445566778899001122334455667788990011223344556677889900aabb60161a7f112233445566778899001122334455667788990011223344556677889900aabb60171a7f112233445566778899001122334455667788990011223344556677889900aabb60181a7f112233445566778899001122334455667788990011223344556677889900aabb60191a7f112233445566778899001122334455667788990011223344556677889900aabb601a1a7f112233445566778899001122334455667788990011223344556677889900aabb601b1a7f112233445566778899001122334455667788990011223344556677889900aabb601c1a7f112233445566778899001122334455667788990011223344556677889900aabb601d1a7f112233445566778899001122334455667788990011223344556677889900aabb601e1a7f112233445566778899001122334455667788990011223344556677889900aabb601f1a7f112233445566778899001122334455667788990011223344556677889900aabb60201a7f112233445566778899001122334455667788990011223344556677889900aabb6107de1a6000600055");
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

TEST_CASE("jumpTo1InstructionafterJump______88eb8cc46a28df3e813fc9d859aaa7c10bd7246272ed7af7c7e119e18e7c6592", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6003565b6001600055");
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
    gas_t(0x2710), /* gas */
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

TEST_CASE("jumpi1_jumpdest______ad83573b03f45ffbef8bfcea78a8cb61b1c793b36475000cf9222dea41696717", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60236001600a5760015b600255");
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

TEST_CASE("BlockNumberDynamicJump0_jumpdest2______e86a87e0b5cde7d47f1e5dc295600ecc60b7344b3fb4ad64609d6b87fae642f8", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6023600a60085043015660015b600255");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000023" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x02), context->codeAddress, external))
  );
}

TEST_CASE("DynamicJump0_foreverOutOfGas______68b687a344b0f44d7459e095f05f6b302ee3f5d15b3c3e7765d5642fb1f46689", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("5b600060000156");
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

TEST_CASE("for_loop2______2764d5106d8f416d7f03ab65334b580f66eff1a74fa4c3fc4b2488dbb621d3c1", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60006080525b600a608051101560265760a0516080510160a0526001608051016080526005565b");
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

TEST_CASE("mstore8_1______85ba59a62f13c9f29b37207e79bf61c2bfb361b6b703ac5ec0f82801edd6cdec", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff60015360ee600253600051600155");
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
  CHECK("00ffee0000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x01), context->codeAddress, external))
  );
}

TEST_CASE("BlockNumberDynamicJump0_foreverOutOfGas______0900beba73811b8aafaefadcff3a7cd9954ccb5e4986b9cf03ca44881efd4e9c", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("5b600060000156");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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

TEST_CASE("BlockNumberDynamicJump0_AfterJumpdest______edd08521b4a9bc311f2ba99d15c867d9a98da1e9665d9b173ff85621e170e896", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6023600843015660015b600255");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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

TEST_CASE("indirect_jump4______bec771ce98d114d7dacd0f1f33426b85e6092d65bfd73945ea07831737a0d310", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60006007600501576001600052005b");
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

TEST_CASE("jumpDynamicJumpSameDest______c1d46387eefa48a995ad56844ced0803c7e2441369d569c7669933b1ebecc2c8", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6002600401565b600360005260206000f3600656");
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

TEST_CASE("DynamicJumpPathologicalTest2______957bc609a0322452da86a59c96e7eea17c5463dcd7bad6ed97b57c6460a90b80", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("435631615b60615b60615b606001600155");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("04"), /* blockNumber */
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

TEST_CASE("DyanmicJump0_outOfBoundary______a2ae635e97f7381a5af1ea432d210faf19f4f84e8e0e6874bd48005674bfea92", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6023600760005401566001600255");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  external->storageResponder.push_back(std::make_pair(
    uint256_t(0x00),
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000004"))
  ));

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

TEST_CASE("pop1______f87d71b88a272f122f6ea9dbd4680f8b4bf659a1b2bae4634398e6ecdcc9f487", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("5060026003600455");
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

TEST_CASE("JDfromStorageDynamicJumpiAfterStop______80d903064c1050cf1a2e527b8938e610e77822d55c83cf4a07e18586baa0bec1", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6001600860005401570060015b6002600355");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  external->storageResponder.push_back(std::make_pair(
    uint256_t(0x00),
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000004"))
  ));

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
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x03), context->codeAddress, external))
  );
}

TEST_CASE("msize2______7a68500c2697ce7d4e5140214c087b3f152770295239abebdae1f81695167994", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("64ffffffffff60005261eeee60205259600055");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000040" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("DynamicJumpAfterStop______5ba8a9cb65319cdc8e574e0eb59695b55158e6d723945bac3b96573a576a86a8", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6008600101560060015b6002600355");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x03), context->codeAddress, external))
  );
}

TEST_CASE("JDfromStorageDynamicJump0_foreverOutOfGas______a3046ce1b7f78c109aa36c29db004850ad5b3b4129d9085849b7af04b719826c", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("5b600060000156");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  external->storageResponder.push_back(std::make_pair(
    uint256_t(0x00),
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000004"))
  ));

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

TEST_CASE("mstoreWordToBigError______25c31b75a7912e1384ff3347dc511c5d1b384e6f40cfb0dffaa65176abcc1613", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600152600151600155");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("01f4153d80"), /* gasLimit */
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
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x01), context->codeAddress, external))
  );
}

TEST_CASE("bad_indirect_jump1______15744a7158d6982822dc8a0c272c329f8dfdf93810e8f2f3f468a56db9bd2d90", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("601b602502565b");
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

TEST_CASE("jumpiToUint64maxPlus1______43b7965f24cac2b1b88fb4781bccd2cbcdcc1569812c2c9e28ebded71ebd172e", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016801000000000000000d575b5b6001600155");
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

TEST_CASE("mstoreMemExp______eb43769a562c8a34bcb776fd312cc723bf2e8f4e64c75d7d3e36451760d9fd44", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60f1630fffffff52");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("01f4153d80"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x01f4153d80), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
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

TEST_CASE("stack_loop______10cdba5fde4ef3d4d21af05732cf685986623a9055ef0d62dfb00f2a415e9264", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60015b6001810380600257600053600153600253600353600453600553600653600753600853600953596000f3");
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

TEST_CASE("jump0_jumpdest2______3aba479e0b0de29b2fac29ac62deb3e37d9fff0a79ed3a1953a7afa7e19b17da", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6023600a6008505660015b600255");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000023" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x02), context->codeAddress, external))
  );
}

TEST_CASE("sstore_underflow______805b307827e4870e9e3bf9655a71a4ca5c327223280c4c3125522d053732de4b", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600155");
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

TEST_CASE("JDfromStorageDynamicJump0_AfterJumpdest3______52880726a50d86ffdaea78e4a5d3293643688543eea049172fbf51e564f28f5b", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6023600b600850600054015660015b600255");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  external->storageResponder.push_back(std::make_pair(
    uint256_t(0x00),
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000004"))
  ));

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

TEST_CASE("BlockNumberDynamicJumpi0______620bba922f5a1732f512d726a26e71b09d3837018a66a9aacb581b212a4f4b13", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6023600160094301576001600255");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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

TEST_CASE("indirect_jump3______1ca405a29132ed02b16a4e4f1d869eb73904f23759d971c3a7e287260fa13f7b", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6001600460050157005b6001600052596000f3");
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

TEST_CASE("DynamicJump_value1______20503c4d21019e3d9d87b95365a0d0417fb7e163265f938d6e3f685377a2c5da", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016002600334565b5050600052596000f35b50600052596000f35b600052596000f3");
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
    TestUtils::fromHex("08"), /* value */
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

TEST_CASE("return2______dbf688e0c2f5f4907b91cf9d71f3dc94ccbdcd3153ece4d2017e0367c0f0ef66", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6001608052600060805111601b57600160005260206000f3602b565b602760005260206000f360026080525b");
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

TEST_CASE("BlockNumberDynamicJumpi1_jumpdest______420810639c740487f7b8d18b29f28dcfb7d762b1aa4aa9b9f8b91928da66a539", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60236001600a43015760015b600255");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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

TEST_CASE("jumpiOutsideBoundary______7d536d76f1c00c063b374bdcd155229427e5fe4867ae5ac41d42516c88ebff0d", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff576002600355");
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

TEST_CASE("mstore8MemExp______df32f3b06a7e748f5fdd93a878f7687f4f28864f8a5956d8e3a4fff7463b47f0", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60f1630fffffff53");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("01f4153d80"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x800570), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
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

TEST_CASE("jumpi_at_the_end______db58f5762f6dccaf9a4daa5053fe18bc36fc597c379acbbb8dc7d41897e0fd1b", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600a6000525b6000516001900380600052600557");
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
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x03e8), /* gas */
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

TEST_CASE("gas1______158673d626e8f5b04cbad00e6bcf8bce2a081b61bf98ca0ad11b78e52921444a", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("5a600055");
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
  CHECK("000000000000000000000000000000000000000000000000000000000001869e" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("pc0______824c240179768ed6999ca7357c185b25d2368e5526cde066fa103caa26fe8dea", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("58600055");
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

TEST_CASE("when______18527242394f1a6921ffb94f5938e5c13a8dc892cb123edf424d17c32be5140d", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600060011115600e57600d6080525b");
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

TEST_CASE("pc1______5e897dc9ac93e7c8c0502f846914c81cacb26796ab75d517dd862fc1f193256c", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff60005558600055");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000005" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("gasOverFlow______01dd61c063b45f54e62e912f6711a3c04bcaba16f40890da37774adedcf5d201", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60035b600190038060025768010000000000000016565b63badf000d60115500");
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

TEST_CASE("jumpiAfterStop______ec2d355d1d27a71fadd654c9a7b8a7b90bc68dce10416448f803d452ef1d474d", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60016008570060015b6002600355");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x03), context->codeAddress, external))
  );
}

TEST_CASE("gas0______344499133ac967decfa379dd507e6df8c81e13b014db2676d943cdd2ed3c09c6", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("64ffffffffff60005261eeee605a525a600055");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000018680" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("BlockNumberDynamicJumpInsidePushWithoutJumpDest______183a4ce2d0f208630db92539aaf4e38fc3025b44a2842e19e39e956465449fe5", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600543015661eeff");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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

TEST_CASE("indirect_jump2______74d76db6a1761e44af7dea37c2ed941aac2add09cff11950033033cbe6f83248", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("600860060156005b6001600052005b6002600052596000f3");
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

TEST_CASE("JDfromStorageDynamicJumpi1_jumpdest______cc7eadaee4927a2753204e40d7028ae1ed3e1ef4c9a2e8a79460a3e07f5bcafe", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60236001600a600054015760015b600255");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  external->storageResponder.push_back(std::make_pair(
    uint256_t(0x00),
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000004"))
  ));

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

TEST_CASE("BlockNumberDynamicJump0_AfterJumpdest3______1e86dccd54bd74436a1bbfe11302b675761fc6138ebd1461231acd29ee97b0f0", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6023600b60085043015660015b600255");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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

TEST_CASE("mstore_mload0______f3bd75c796896dcdbf77a7b2af45f3299ebe20db7e30d22031edc990bffb0416", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6017600052600051600155");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000017" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x01), context->codeAddress, external))
  );
}

TEST_CASE("BlockNumberDynamicJumpi1______91d6fe3848fbdafff10b7bd503d560f2c614d6b53ed16b51821d3026f4a3a544", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6023600060094301576001600255");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x02), context->codeAddress, external))
  );
}

TEST_CASE("JDfromStorageDynamicJump1______bf061c0eb83d11c310f7ec309e56c3629f715727b41cc0e0772991060404cfc9", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("620fffff620fffff016000540156");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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
  external->storageResponder.push_back(std::make_pair(
    uint256_t(0x00),
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000004"))
  ));

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

TEST_CASE("sstore_load_2______6eeaf23d94ef3fc20edf8997eea5636ef20031039916c445404cfbe6ed8fbd42", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff60005560ee60015560dd600255600154600a55600254601455");
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

TEST_CASE("sha3MemExp______6672d6b321654fc8397f1a89903d0fb859013f50a4483c33e7b14b08ba490886", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60ff630fffffff20");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("00"), /* blockNumber */
    TestUtils::fromHex("01"), /* timestamp */
    TestUtils::fromHex("01f4153d80"), /* gasLimit */
    TestUtils::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    TestUtils::fromHex("0100"), /* difficulty */
    TestUtils::fromHex(""), /* blockHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    TestUtils::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x01f4153d80), /* gas */
    TestUtils::fromHex("01"), /* gasPrice */
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

TEST_CASE("DynamicJump1______2369bac56afc1e0946f608c52027fbc88faf3844cdc2fa46954a0916221b8432", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("620fffff620fffff0160030156");
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

TEST_CASE("DynamicJumpInsidePushWithoutJumpDest______4e320bace2f65884d59f95dbbba6e4f9aea39e243bffd309be9bb6c5a3c1bedb", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("60056003015661eeff");
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

TEST_CASE("msize3______e5a676b6ba865c05ea6cf933a2805cb286a664d1bee6544604cc96fdd79f1be4", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("64ffffffffff60005261eeee605a5259600055");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000080" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x00), context->codeAddress, external))
  );
}

TEST_CASE("pop0______46af5c256e1cdc6525f63332c78c39e0583ad9afe06e29a1a2cad8efcc801fd4", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("6002600360045055");
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(pendingState->getState(uint256_t(0x03), context->codeAddress, external))
  );
}

TEST_CASE("BlockNumberDynamicJump1______88e43b5985cc4dfbcbc8476c570157e6e7bc0ee0cb3609e9e9f3dd9aa2a3a528", "[vm]") {
  bytes_t code_bytes = Hex::hexToBytes("620fffff620fffff01430156");
  bytes_t data_bytes = bytes_t();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    uint256_t(1), /* chainId */
    TestUtils::fromHex("02"), /* blockNumber */
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



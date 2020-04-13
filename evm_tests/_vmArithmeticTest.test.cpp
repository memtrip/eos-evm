//
// 11.04.2020
// Auto generated based off the Ethereum tests found here:
// https://github.com/ethereum/tests/blob/develop/VMTests/
//
#include "catch.hpp"
#include <memory>
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include <evm/big_int.h>
#include "external_mock.h"
#include <evm/operation.h>

TEST_CASE("mulmoddivByZero______d2f1f45a525dd3c94e60ba59a808bfa6f526ff1517294eacdf4d09d9d33415d5", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60006001600509600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("sub0______6e271b6ee17cb23f68d252f5c2bddad3c667f05dc922fd4839721727eb10ee0f", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6001601703600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000016" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_29______d1d28e8369ccb0a73475421072fcba58bc0491a0a30c1541d47076a0284609a2", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "601d6101000a600055601d60ff0a600155601d6101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000010000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("000000e48814fe44fc1a8f78642d946d7c879b39a055b6988e438647446a1cff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000011ea4a49e3a9ee435d23f98a8826a875a9ae54cb3090d5c3fd547961d01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("signextend_BigByteBigByte______5cd096028c09eba94315bd6d591ae9cb76413b56bac1aeada8d337d47c59be10", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0b600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_22______c0e0c1457caeab0bedb354de662de3741cd90362ec3fe970cbd5565c8e164a1f", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60166101000a6101000a600055601660ff0a6101000a60015560166101010a6101000a60025560166101000a60ff0a600355601660ff0a60ff0a60045560166101010a60ff0a60055560166101000a6101010a600655601660ff0a6101010a60075560166101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("9ec55c33085514ff7f0000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("ec447e662ac08957d7e290a421dbf54c0aaf43aadc9cc465ad0b02f071ea00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("dc9178d3bab470096f01477c859b5f4173986640b659426412a653465c1600ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("b68fb921f7aa6aff810000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("dcf0a770777610503596ae0311af46c171151ed45107d7e7bb8f74bb5bea0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("4d65773387993928c95c861274232d3fb6f6b7fe1b22e4e61a30e71172160101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_8______eabf261994e71ba3fab018f76089ada2039bf58f8547a549aca6f9605bb7e452", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("05f5e100"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60086101000a6101000a600055600860ff0a6101000a60015560086101010a6101000a60025560086101000a60ff0a600355600860ff0a60ff0a60045560086101010a60ff0a60055560086101000a6101010a600655600860ff0a6101010a60075560086101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x989680), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("230041a0e7602d6e459609ed39081ec55c33085514ff7f000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("c407d8a413ef9079ead457ed686a05ac81039c0cae0a7f6afd01e8461ff800ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("67a397e0692385e4cd83853aabce220a94d449e885fa867e96d3ef5e180800ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("70add926e753655d6d0ebe9c0f81368fb921f7aa6aff81000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("0bdce80b8378e43f13d454b9d0a4c83cf311b8eaa45d5122cfd544a217f80101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("629c25790e1488998877a9ecdf0fb69637e77d8a4bdc1b46270093ba20080101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("mul4______98024d8b456973580b82d5dfcc6e3d389628d673e12d43ff8653a44b435fbee6", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7f800000000000000000000000000000000000000000000000000000000000000002600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("8000000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_13______9a5723090752b32355ffaefd5d4b998f17196c358567128240bb0f8e83a1d375", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600d6101000a600055600d60ff0a600155600d6101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000100000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("00000000000000000000000000000000000000f34ce4c5ffad5104361db20cff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("000000000000000000000000000000000000010d4f20d00dbab909cc1e4e0d01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("mulmod3______a4466904098f2aa254af6f260446e643504d5993d6226da4cf88c82942018de1", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60036000036001600509600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000005" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("exp6______05a538a5941013f6dc6dfb36f122b6d6840d86e5cb69af7da789e71d14c54937", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "61010160010a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("addmodDivByZero1______858b669ae5775b5aeae36c69828eb74ecfa9498698f01ae8d1ba73328b466d96", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60006001600008600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("expPowerOf256Of256_18______9aae91d4c3217ab1ae7ac11ca2cdce036b3be2c2bc426f515bbc1b1e4a9a48eb", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60126101000a6101000a600055601260ff0a6101000a60015560126101010a6101000a60025560126101000a60ff0a600355601260ff0a60ff0a60045560126101010a60ff0a60055560126101000a6101010a600655601260ff0a6101010a60075560126101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("698218879ec55c33085514ff7f00000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("8a2cbd9f40794e2205b13306f2aa0a43c60823c64b95d8601fa4f1e521ee00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("c1b5a1e3a81da51b10d84e880f0113ff67b863ddad3faf1f4ecf413f101200ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("c9b0f000b68fb921f7aa6aff8100000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("410be68e49452a1fbcd863bf6e8d637f8eae4979c34c88d552afbcc20fee0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("f540cb714754b5b1eb0373833833bd7fb0ee925ce8b92962500b7a1c22120101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("smod5______7b7e7c70fbcb291a99ff4ae3f8d46a67b94183a8cf3c5a93aff9262c81bd3aa7", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000307600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x2710), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("expPowerOf256_25______fce87c81a0e08fa580701f25ecc21b487f85741090abd8a7614cabf6b90e42ae", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60196101000a600055601960ff0a60015560196101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000100000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("00000000000000e823349d2286a5ec3de3529625f683e56c0903589efad418ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("000000000000011a352e3c45325c4583eb6149e1b7d4e73f709bbb72fd2c1901" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("mulmoddivByZero3______7f1443cbcb5f817b38aed7b0dd96af4d58e8025b71a380e14af792c24fc2d8fa", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60006000600009600103600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_33______dcdd8d12914af51d9ebd69cf0085106850fcc496b40c13bdc30d5a5440b561ce", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60216101000a600055602160ff0a60015560216101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("fb4c498e11e3f82e714be514ef024675bb48d678bd192222cd2e783d4df020ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("25f3884075dd08b8fb400789097aa95df8750bd17be0d83c9a0fb7ed52102101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_4______5758fdc80aadf2b69e7e75acfa05239e6c5d9d5ad1374b1cac0d19477a861b72", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60046101000a6101000a600055600460ff0a6101000a60015560046101010a6101000a60025560046101000a60ff0a600355600460ff0a60ff0a60045560046101010a60ff0a60055560046101000a6101010a600655600460ff0a6101010a60075560046101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("e6540ce46eaf70da9d644015a661e0e245b13f307cb3885514ff7f0000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("6526b38b05a6325b80e1c84ab41dc934fd70f33f1bd0eab3d1f61a4707fc00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("e959516cd27e5d8fd487b72db2989b3ec2ba9fb7ead41554526fe5a3040400ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("e7498a48c6ce2530bbe814ee3440c8c44fffab7ad8a277aa6aff810000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("2dffa3e901e5a392d15b79f4193d2168147d2aa7c55870b46c3a905d03fc0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("e16ea721c96539edb4f7fb82de0dad8cccb1e7a6966a6777635f6fb908040101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("sdiv7______2b55fc5f5e58371ec9404c0b8c5e009c45c2c2efdbb5f8856cec1e847f588dba", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6019600160000305600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("divByNonZero1______fcd51ef794022b0a97b5d1c20e12e1a725cdd126f9a42fc135a79bc15e95e447", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6018601704600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("addmod1_overflow2______bef2a19f1d2f3d74ad56dcff0d4f94046bf73b3b27472e2d92b415dceebe9ca0", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60056000600160000308600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x2710), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("expPowerOf256Of256_14______58cc5ba032541e61180d5bb54913a3b14ba2db81e6e455d45fd0504bb1a69da4", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600e6101000a6101000a600055600e60ff0a6101000a600155600e6101010a6101000a600255600e6101000a60ff0a600355600e60ff0a60ff0a600455600e6101010a60ff0a600555600e6101000a6101010a600655600e60ff0a6101010a600755600e6101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("db9902ec698218879ec55c33085514ff7f000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("83fab06c6c8fef761ebbb9534c06ac2a9d61820623008069062ff3b1e1f200ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("3f791dd183ed5b963bd86e0dba1a9dd5b8ceeb078f15c73062f1942fd40e00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("e0bfa28fc9b0f000b68fb921f7aa6aff81000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("8133b760dfae27560eb490f235ddfa301f058dee4f01f3fe4b3567d0d3f20101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("cd4cd0124e983af71620fb5f98275965c6a8bebc4b8adc288b63224ee20e0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_15______ce849f731f8f9cfdb8c922cac2e16d847e6af0bea8958367c172b277020c7819", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600f6101000a6101000a600055600f60ff0a6101000a600155600f6101010a6101000a600255600f6101000a60ff0a600355600f60ff0a60ff0a600455600f6101010a60ff0a600555600f6101000a6101010a600655600f60ff0a6101010a600755600f6101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("9882ec698218879ec55c33085514ff7f00000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("75c4915e18b96704209738f5ca765568bb4dc4113d56683977825a132c8dfeff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("5c76839bf5a80b1da705dbdf43e4dd6770cd7501af11ff2dab7918dfe18f00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("bf228fc9b0f000b68fb921f7aa6aff8100000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("c6a29131e7594004bc2aa79f0d2c402a1409c57c77d284c14b1a3ab0ff8fff01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("e6b3e5cf6ec90e532fef7d08455ebf92a03e9e3f6e224ea0febdf1a9f08f0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("divByNonZero0______70dda40426c888f3c2b4505f99842373bae332be0976cb37dd6b4f8f950e7314", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6002600504600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("addmod1_overflow3______37950a5f52df8d7eb5241267f3b45a759284d77a88e876990c6ee5b1c0f48857", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60056001600160000308600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("sdiv6______e7b278490909bf62877a08100ade05781f50a8e1057283f7b8c734a0aec01dee", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60007f800000000000000000000000000000000000000000000000000000000000000060000305600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("expPowerOf256Of256_5______b03dff0692fa130237d4d29c2879391227fd71f95a3efec5d191667dc7a5ac8a", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60056101000a6101000a600055600560ff0a6101000a60015560056101010a6101000a60025560056101000a60ff0a600355600560ff0a60ff0a60045560056101010a60ff0a60055560056101000a6101010a600655600560ff0a6101010a60075560056101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("b581ac185aad71db2d177c286929c4c22809e5dcb3085514ff7f000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("75789eb2a64bc971389fbd11a1e6d7abbf95ad25e23fb9aa25e73a0bfc83feff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("fc403fa42ceb6a0d0d3321bd9b2d8af25b1b667f87a04f496c78168d078500ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("cec5ec213b9cb5811f6ae00428fd7b6ef5a1af39a1f7aa6aff81000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("70ab32233202b98d382d17713fa0be391eaf74f85ba1740c9c3238c4ed85ff01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("b622672a213faa79b32185ff93a7b27a8499e48f7b032cdb4d1a70300c850101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_32______9a7aca6dc6ad1b3e6bbf7596f5d5f35e917f8e4be05eb7d962bf9e2852345fa5", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60206101000a600055602060ff0a60015560206101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("e1dd29730112f6ef1d8edabfd4c3c60c823d865cd592abcdf0bdec64a1efe001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("2203ef98a7ce0ef9bf3c04038583f6b2ab4d27e3ed8e5285b6e32c8b61f02001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("divBoostBug______d2e783985274bb48def6615bebddaf86d9ebdcf49e03f93a9854166ce999b166", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7f01dae6076b981dae6076b981dae6076b981dae6076b981dae6076b981dae60777fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffba04600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000089" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("mulmoddivByZero2______dade878a93b655f3a61789e38fb21ece3dd658e3e58d13a23bd5dcf5af668ef6", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60006000600109600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("addmod1_overflowDiff______fd000aecad4faf960141a35e708c6686bf6d29b917347ec0f793b8a62393ed8b", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60056002600003600160000308600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000004" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_24______e4c8a16c072ceeebfd96c18dbd58a9088c910a9d2b9e35f9114ff0ecfb526d10", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60186101000a600055601860ff0a60015560186101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000001000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000e90c40de00872d19573a8d23493fc3a9151e217a1913e801" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000001191c122a1b1745008367f9509126ae39066a3189e9141801" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("smod4______131b0f2f206b381215517d412fb1ea7564a8152d2f4d4cd6ab3bff2cee6b2198", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6000600260000307600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("expPowerOf256Of256_19______82899697a114c2742a99d07558e3ff58075aed7ac8d0b4624e336727ed10644b", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60136101000a6101000a600055601360ff0a6101000a60015560136101010a6101000a60025560136101000a60ff0a600355601360ff0a60ff0a60045560136101010a60ff0a60055560136101000a6101010a600655601360ff0a6101010a60075560136101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("8218879ec55c33085514ff7f0000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("b795ad7ac24cfbb7435cf53bd3584f3d4b2709935635c3ceb66e761ff091feff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("1f0bb7be91a0ccd0cca93d75cf03de3e6b56fe8f1c54242617665327219300ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("b0f000b68fb921f7aa6aff810000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("ad571756ecbff1bfdef064861e5e92c5d897a9cc380e54bdbaabd80bb793ff01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("d8b5b531989e689f700dcdb43ab90e79a49dfbbb5a13dbf751df98bb34930101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("mulmod2______79bc8735a59de453773cbcd0053df3cd759b8d55ece41192570ed00471f038ac", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60036001600560000309600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("exp7______618bedd207234fc5c4da314056bc9550ecb1c3ace2bd12dd6ee9a305a58b1853", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "61010160020a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("mul5______df427409c23049ff69ae32648441bacf7f46bfa8380019c6d1effaefa428d3e1", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7f80000000000000000000000000000000000000000000000000000000000000007f800000000000000000000000000000000000000000000000000000000000000002600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("expPowerOf256_12______2e2fede61e970560166c4fa485d48bc644ee46ba312aae472afd3c861f73799c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600c6101000a600055600c60ff0a600155600c6101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000001000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000f44125ebeb98e9ee2441f401" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("00000000000000000000000000000000000000010c42ddf21b9f19efdc420c01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_9______f93cdd3e162869675b64e4a5e5bb04307b799762656cb3e2db858aeeb6195767", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60096101000a6101000a600055600960ff0a6101000a60015560096101010a6101000a60025560096101000a60ff0a600355600960ff0a60ff0a60045560096101010a60ff0a60055560096101000a6101010a600655600960ff0a6101010a60075560096101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("53017d8eb210db2c8cd4a299079ec55c33085514ff7f00000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("48be09b6c6ae2aa660f1972125cecbb1038b5d236ecf766ba786e2c4e887feff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("2e350d847ba73dc2099f83f532951c47269d9fd7e411b50bae00a9581f8900ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("013ab9e1f0df89a184b4d07080b68fb921f7aa6aff8100000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("f387ed41c1050f9da667f429a3e8fb30b61a55ede97d7b8acd797a03cd89ff01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("525696c22bb3ce00fd2e3f6bbb9b4ea1046a5e31fcff2fedf8f8c74d28890101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("signextend_BigByte_0______ed96ff1a29a7869a15e633346c24da243ef11761dbfac1fe6b6e54629e3d265a", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0b600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("expPowerOf256Of256_23______6ff02117a4131900b84bb38b99a97e590f197792f742bd27678797d0976c2c3d", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60176101000a6101000a600055601760ff0a6101000a60015560176101010a6101000a60025560176101000a60ff0a600355601760ff0a60ff0a60045560176101010a60ff0a60055560176101000a6101010a600655601760ff0a6101010a60075560176101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("c55c33085514ff7f000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("537ca0f03f974303005f1e6693b55b72315a166841732e42b8353724a495feff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("86418797ec60058de6cca47dfdbee79923ac49d7801e01840041ca76719700ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("8fb921f7aa6aff81000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("56a55341ab8d4318f1cfb55d5f21e2ba35d7e070a72bac6b2b21baae5f97ff01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("55ddd0ec77909de6d8311116cf520398e816f928b06fdd90ec239d0488970101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_1______308cd7ec273573ca2f8a96a8300b5469c13bdf78fa4c4f643d154e501333fc3f", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60016101000a600055600160ff0a60015560016101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000100" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("mulmod1_overflow______8746002a182b1690ee3c6f9285ae2f6293abc8531dce20c6a81c632dea5b06c2", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60056002600160000309600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x2710), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("sub1______9c03702b06e54741e8c89a52f479d93892f0186c3d8cd469dd8c1ef4987c0d55", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6003600203600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_28______02bf29a25df27bb8f98935cb17cdd2e1b37c3963178dfd245c681919697c6750", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "601c6101000a600055601c60ff0a600155601c6101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000100000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("00000000e56d8280c5c1dc6be448760a77f47c1750f146fd962467ee3579e401" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("000000011d871d80b9e4ff369ba3f4b3ce9beb6f2bb9931fe9243807cd7a1c01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_23______abfb8b178f10c9de69b1ee116db59a0f9a127e78c370610d4593c8aab78771a6", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60176101000a600055601760ff0a60015560176101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000010000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("000000000000000000e9f63715159cc9e33a7502256eae721b304e6fea0316ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("00000000000000000118040e1bff182cd3afb8410f81a5092fd6939debfd1701" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("addmod0______1315e3365bbf4b0d1ea7d5f885974318055ca1dc25f54a106df8f76f3dfd34d5", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60026002600108600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("add0______2d47e8f287f580e1e0ec6b926375f8fee1142475cbf3bdcdf9305e618b66cb40", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_28______f0bed14e403ae3cbb67dfbf7e93be879d04590226ad07c947e5d76e1ef45a4e4", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "601c6101000a6101000a600055601c60ff0a6101000a600155601c6101010a6101000a600255601c6101000a60ff0a600355601c60ff0a60ff0a600455601c6101010a60ff0a600555601c6101000a6101010a600655601c60ff0a6101010a600755601c6101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("14ff7f0000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("ffd368e44b3f85cb81ae394c9809ca9fa2db46a83d7880a912ab6d4a87e400ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("0981ad53c19b15a94bcf0bf20235dd0da9df25f46ae635029fe2062e6c1c00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("6aff810000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("19df06ffa28250867006726405fbc05d43dc2f9d2f025006db089bd46be40101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("243fffe3a4f2982f45055c08f379648ab886da8027a7401117a8e0b8881c0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("mulmod2_1______ad3c90c6e0cbacf8ba3baab6c0f8540ec0ff24038b0768dadabf67efac5e07ed", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60036001600560000309600360056000030614600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("smod8_byZero______d21aca0c1e7c0240084f3604e37698a1495ee8777b0dcb2d3a61b714d7288683", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600d600060c86000030703600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff3" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_2______249a51e755ea2cd7bdbc704a8b3825fc01d8145221332c23e605cda095415004", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60026101000a6101000a600055600260ff0a6101000a60015560026101010a6101000a60025560026101000a60ff0a600355600260ff0a60ff0a60045560026101010a60ff0a60055560026101000a6101010a600655600260ff0a6101010a60075560026101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("4ee4ceeaac565c81f55a87c43f82f7c889ef4fc7c679671e28d594ff7f000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("82f46a1b4e34d66712910615d2571d75606ceac51fa8ca8c58cf6ca881fe00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("81c9fcefa5de158ae2007f25d35c0d11cd735342a48905955a5a6852800200ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("666ac362902470ed850709e2a29969d10cba09debc03c38d172aeaff81000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("eb30a3c678a01bde914548f98f3366dc0ffe9f85384ebf1111d03dad7ffe0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("72d0a7939b6303ce1d46e6e3f1b8be303bfdb2b00f41ad8076b0975782020101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_19______91e9804a3d43e6f2e973625ca587f4e8583bec88aa3c53c333a24bfd50e911f7", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60136101000a600055601360ff0a60015560136101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000100000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("00000000000000000000000000eda745f6fd3851d68db3866a315cdfc85512ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000113aed851d6c1fca84402033e297b27c9ab1301" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("signextend_bigBytePlus1______e1d4c88c2ad5fbe82fefe183562d1533a0408cce7501f79d294a2207637afd23", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "66f000000000000161ffff0b600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("00000000000000000000000000000000000000000000000000f0000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("sdivByZero2______0395bca3ef9221cdfca63d08eceb32873be670cae868547e38aa1a42c29e41d9", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600160007ffffffffffffffffffffffffffffffffffffffffffffffffffffffffcf923bdff6000030501600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("sdiv1______65482c2a8e74781262c4db10d43d8c7731628b313a56e48a8dfdc9af9a1e4164", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6000037fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff05600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("addmod1_overflow4______d256203dabe38a3e460b068f5f85039a7f3db2f87cdd47c4eba6631f1eebe846", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60056002600160000308600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_12______8e662f9b2bcc90eacdf00d0f18353ff17d7bada18f5ea2260030951429e0ff62", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600c6101000a6101000a600055600c60ff0a6101000a600155600c6101010a6101000a600255600c6101000a60ff0a600355600c60ff0a60ff0a600455600c6101010a60ff0a600555600c6101000a6101010a600655600c60ff0a6101010a600755600c6101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("b0e95b83a36ce98218879ec55c33085514ff7f00000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("c482ab56ec19186dc48c88f30861a850b2253b1ea6dc021589e569bd47f400ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("cf45c7f9af4bbe4a83055b55b97777ad5e0a3f08b129c9ae208c5d713c0c00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("a5cbb62a421049b0f000b68fb921f7aa6aff8100000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("3bde6ca66dffe1bf5d727c3edea74c7a4af43b3912e6256d37705c8f3bf40101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("3f49a1e40c5213aa4ffed57eb4c1ad2d181b2aaa289e9d59c2256c43480c0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_32______6391696ba6998cd4f6154479524ffa7c1fd2970c481100e6885eacbba5700f64", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60206101000a6101000a600055602060ff0a6101000a60015560206101010a6101000a60025560206101000a60ff0a600355602060ff0a60ff0a60045560206101010a60ff0a60055560206101000a6101010a600655602060ff0a6101010a60075560206101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("b8247842bb5ce75c08d0c251669ed5870fa24a22952e5db3a7c66c59ffe000ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("ee526e5a06f2a990b2bf6c951e5feabf0e07ee16877296e1be872db9e02000ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("eda7d024b6de40a9d3b966e71f10a4667edc5b71cab07aeabcac6249dfe00101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("512ecfaeeb11205f0833e1054dcb1300488e0954be5af77a49e143aa00200101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_6______2513b1044fefd548846b5188b80ed9633303bbbf23522518925608b2916bbc6c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60066101000a600055600660ff0a60015560066101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000001000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000fa0eec0efa01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000001060f140f0601" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_24______cbbb2605b3283fff77ffccb39e107bd2a9353d0f25fb2fa43dc94f5db1c9f1f3", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60186101000a6101000a600055601860ff0a6101000a60015560186101010a6101000a60025560186101000a60ff0a600355601860ff0a60ff0a60045560186101010a60ff0a60055560186101000a6101010a600655601860ff0a6101010a60075560186101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("5c33085514ff7f00000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("d542e526003539ead104274aff2d78332366e29d328c2161f0c120731fe800ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("c706cb25e8384ce9bb5c9cb48415238ba03e16c448e292c0a101843b081800ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("b921f7aa6aff8100000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("4ca55f89202c524cb0f1cb3195d13c8d94a9f7a05c59e1d4031577c707e80101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("8c4b0574e9156b80035f3ecdcf1fe79d273ed7559747a4322bcd338f20180101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("expPowerOf2_32______1c83675482424298675a170ac78731d2fd4660aa4a42739a1ba1e6032e3a736a", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "602060020a600055601f60020a600155602160020a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000100000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000080000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000200000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("signextend_0_BigByte______9690d6442d8ff89edda5c528ab4e1cb01ee09ba06c4e0c59d78be6d82259c40b", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000b600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("mod1______efb4ba86b8ead1a13d49883472aa7876f6c2f22d094d84a22e0aa206bcf0443e", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60027fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff06600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("sdiv_i256min______0fb4aa11ee10780f512ea76b238c096b781768ac4048e45d4b5ce3aa8f0a987d", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60016000037f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000305600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_15______5b661530dd5092ea6c0916ede1eac91b3650b6eb747c7fb5b51c86e6c638b29c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600f6101000a600055600f60ff0a600155600f6101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000001000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000f1673e495873f60f7eb5acc6970eff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("00000000000000000000000000000000010f6acc60cea63c3698c056c7690f01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("mul2______d78a8768183f5c845b70898608b589cea44445d770bac7d08071fbccd9122d7a", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6017600002600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("exp0______becfe094fe303afc738e2960a64d60ec529d99bf137a608b055ba1ae426f5040", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600260020a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000004" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("signextend_BitIsNotSetInHigherByte______d7fe1705027d2eaee0adc232f8c10fad41b29b39323215fba98de942695a2ba0", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "62126af460010b600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000006af4" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("smod3______065fa0c03f285a3f544803b152a83747c02e25bfa2534c5aaae56128a836d245", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600260000307600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("smod2______0ae154b4126001a661cccd291c9f3a10cc9051e554a729f22dc26cb32f37c7f4", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6003600560000307600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("signextend_Overflow_dj42______7670c75ec39bedeeac949ccec613c786efedd311a4f2a05ce3b28b1822f67b3b", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6005565b005b61800080680100000000000000010b6180011160035763badf000d601155";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("mulmod4______d0eab7707b7c4159ec4e9b68f395056a16fefb9a701a45e137b8993127870fb1", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6064601b60250960005360006001f3";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("exp1______865320dd21d6636f4bf6f450f1df11b3df505304b74e57940db08814078b7208", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_14______61841ab9a30c340ba56febf6d767ab19f91d9bb32ddd7a0c5ee5fdf080faf829", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600e6101000a600055600e60ff0a600155600e6101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000010000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("000000000000000000000000000000000000f25997e139ada3b331e7945af201" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000010e5c6ff0ddc873c2d5ea6c5b0e01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("mul3______ea10c103a01bd1ae9bf5e1b964928ced5f84e6dbcdaa589400d20efcc3f6f787", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6001601702600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000017" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("smod_i256min1______1ac5584b891146649c93c9adb684f955bb539884cb37173d6765c46b37a39c50", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60016000037f800000000000000000000000000000000000000000000000000000000000000060000307600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("expPowerOf2_64______8e369c41de5a6a6e3c87ed3f76e2a56d98b8283b18c9ef028d4829ed286d3b75", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "604060020a600055603f60020a600155604160020a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000010000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000008000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000020000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("mod0______44970c0ef5fc5d700edaf9be35380d95cc5f91ac6f813a57046b9e1884afab0e", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6003600206600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_25______681b6391573ae3638d187cb462c2ceac81bb651942fa2a4039c54835a82bc251", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60196101000a6101000a600055601960ff0a6101000a60015560196101010a6101000a60025560196101000a60ff0a600355601960ff0a60ff0a60045560196101010a60ff0a60055560196101000a6101010a600655601960ff0a6101010a60075560196101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("33085514ff7f0000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("7f510dd7198cac0a92ff7ea80451838c0dfa12114c41a0ef05907397f897feff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("1275e752b6aee228ecba5e9b57ef1111deff3c651e2cfbf2cccd13151f9900ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("21f7aa6aff810000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("6646340ad51a03bb710caf05756b685b33c7dad62ae68d369243700ead99ff01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("29d80e8060ef2221929bb18215586c742686d6860e028ca0456b443238990101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_7______ccc726de1f10bdaaee5b164f93a976e78f4c031e826a8237bb03f46113e00059", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60076101000a600055600760ff0a60015560076101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000100000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("00000000000000000000000000000000000000000000000000f914dd22eb06ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000107152323150701" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_33______52733d6f69e238cd513f28e3fe30dc303493edb9c0637029e448f0e974b1c940", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60216101000a6101000a600055602160ff0a6101000a60015560216101010a6101000a60025560216101000a60ff0a600355602160ff0a60ff0a60045560216101010a60ff0a60055560216101000a6101010a600655602160ff0a6101010a60075560216101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("8dcb65b5494eba78cd6756a6f9851f6e26d0f2bb9ecd7e9abd7e9b11209ffeff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("6694bb31b20cd625f3756897dae6d738f2e64467b5b6f10fa3e07763ffa100ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("e678999aeffd1f1f45081f64de7f80ab083dd7df04721ed64ee04c03bda1ff01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("39b68fb9898dd7568abd178397251ce8226a25c1d305a4e79573333520a10101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_13______d7052bc90b7237c69a4efdf860a687a529c09e545ddc74ab104923c720ad0b91", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600d6101000a6101000a600055600d60ff0a6101000a600155600d6101010a6101000a600255600d6101000a60ff0a600355600d60ff0a60ff0a600455600d6101010a60ff0a600555600d6101000a6101010a600655600d60ff0a6101010a600755600d6101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("e02639036c698218879ec55c33085514ff7f0000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("8be664bde946d939ce551b948b503787942d2a7734509288c1b62fd5c48bfeff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("a923a28e7a75aef26c51580ffc686879e4a0b404b089bdbcd751d88b478d00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("41ac5ea30fc9b0f000b68fb921f7aa6aff810000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("0daa3a177ec975cb69bb4acf4a6e1be7bcc1ad33d1ffad97510f9fea9d8dff01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("19e6822beb889be28310060f4fb9741bfd50a31fa81ec65de21f7b02548d0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("sdiv0______f0994462e2dd8cc0e076a7379a5a88a01a40586601ff426717cf1d678cd4385d", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000305600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_18______5a677d007106e82a37e13f3560fa0e97f88bad6f826a0b63740fc4b25d0b5a15", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60126101000a600055601260ff0a60015560126101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000001000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000ee95dbd2d0085a30be71f86293f0d098ee01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000001129c3c15c100fbac976a98a583f730991201" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_3______54eb95326b641250ce064811abbd4d246395a7fedaffa684b00c7667b04ec00c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60036101000a6101000a600055600360ff0a6101000a60015560036101010a6101000a60025560036101000a60ff0a600355600360ff0a60ff0a60045560036101010a60ff0a60055560036101000a6101010a600655600360ff0a6101010a60075560036101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("109a00e1370d2d2922bf892e85becb54297354b2e5c75388d514ff7f00000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("54a792f15e9aba7e4ad9e716bc169eea3a6e2e9c49bf9b335874613c8081feff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("5d24a14d8e5e039372cd0f6a0f31e9ed6b75adba9f16b1c5b3edd5ba818300ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("298e2f316b4ccded5ebf515998d9ec20df69404b04a441782a6aff8100000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("4335694e98f372183c62a2339fa4ad161e9b4c42240bdc9452abffd07783ff01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("f0f0820797315acd063056bba76f6a9c3e281cdb5197a233967ca94684830101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("signextend_AlmostBiggestByte______fbfe54fdecb381ce1abdf7dcd95076ae6a3ce4cdd49d414df4798399a536f517", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe0b600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("addmod3_0______45cf97d25ad676aeea9764fcff1d6e7ec78270b322af420c5a3a668f8807222f", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60026003600003600160040814600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("mulmod2_0______e7772703144f24ed842d6df70931910c59e3cf48885caa204e1cfc66109d56aa", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60036001600560000309600360056000030714600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("expPowerOf256Of256_29______eea0d96d36132886c8e85240f2ce145ee5d78888bfb08cbfc937c4eb29d76075", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "601d6101000a6101000a600055601d60ff0a6101000a600155601d6101010a6101000a600255601d6101000a60ff0a600355601d60ff0a60ff0a600455601d6101010a60ff0a600555601d6101000a6101010a600655601d60ff0a6101010a600755601d6101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ff7f000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("41e065d46e0349cfe624c4e8a2034aea1f7edfff80e511cd8067d488949bfeff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("a84162ca6675a22c4c79dfc4ea15f760db5a04dbf04246764199b668879d00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("ff81000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("1226984faa6b05ebdbd45d8477fa4fd5b55bfd5061de03c319282b153d9dff01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("5cc9e6b0b749fd94541ad00364bdec2fca7816981ca3e38f485decc7a49d0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("signextend_BigBytePlus1_2______ab3be4aeefd25904d80c1a58bec3280e86ce66085d4871343424179945748003", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60ff68f000000000000000010b600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("add1______d67a2f100d1736e3bc391e1ed2aea12f7fe8b1b9009c854c07c188c70a28d0cf", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60047fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("addmod1______2ff6c05f22a0669f6a2cbfe5d7706c016e3849448e53e6261251584908c4f683", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60026002600003600160000308600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_22______6c41658d1a70ae8cbafb18046c8863fdf6d5b2ecd6fedaac9597d0b23580ddc9", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60166101000a600055601660ff0a60015560166101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000100000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("00000000000000000000eae1182d42dfa98cc73c3e63d280f30e3e8cfce6ea01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000116ed20fb041418baf4c37d91efb553dbfa9904e71601" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_10______21b4b949d4f8bc1ab587529fc2373e244edd0374433a99ef3b288334d65adb9b", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600a6101000a6101000a600055600a60ff0a6101000a600155600a6101010a6101000a600255600a6101000a60ff0a600355600a60ff0a60ff0a600455600a6101010a60ff0a600555600a6101000a6101010a600655600a60ff0a6101010a600755600a6101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("fe0f60957dc223578a0298879ec55c33085514ff7f0000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("c1ea45f348b5d351c4d8fe5c77da979cadc33d866acc42e981278896b1f600ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("56ddb29bca94fb986ac0a40188b3b53f3216b3559bd8324a77ea8bd8a80a00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("2d49ff6b0bbe177ae9317000b68fb921f7aa6aff810000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("185fa9eab94cfe3016b69657e83b23fd24cc6960218254231c3db627a7f60101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("a7a0223829f26d6c635368034320563df4aa5eb62efc87a42bb35f69b20a0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("sdiv3______0b700f5943e191289b5c0bee1e9c8d4cae53ef77c61f055af8df241c94d2d8a0", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6002600003600405600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("sdivByZero0______8527a93d7cd284bffde534c9240234c0325249bc55a94cbc7bbee86e0abc6a3c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6000600003600360000305600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("mulmod1_overflow3______cea734f62c2074f0e7220b0a22f7cffe76276077677881ecbcc503a8a9b624b7", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600560027f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff09600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000004" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expXY_success______671a3326670385e9a6a354d8b382a4b62cdd57425bc6d6e67384360f61a67510", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6000356000556020356001556001546000540a600255";
  bytes_t data_bytes = Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000000f");

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("000000000000000000000000000000000000000000000000000000000000000f" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000008000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_0______005d6e42bfd4e4c18da7d75bdaa44190606fd695395f0758c89c9911ab5218c5", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60006101000a6101000a600055600060ff0a6101000a60015560006101010a6101000a60025560006101000a60ff0a600355600060ff0a60ff0a60045560006101010a60ff0a60055560006101000a6101010a600655600060ff0a6101010a60075560006101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000100" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000100" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000100" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("div1______aad64e6d9e7887c570b9203d54147d896b21832207288f19a71473bf9539cd13", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60027ffedcba9876543210fedcba9876543210fedcba9876543210fedcba98765432100460005260206000f3";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("add2______4f9cfe5905693f7a54fedaa484e51920df01a064e3c9c5bd1e479d506060787d", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("expPowerOf256_8______c1a5c8ebaaa46926bf87a4cfe02f647400e739fac7761296761beaf6ae2ac0b0", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60086101000a600055600860ff0a60015560086101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000010000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("000000000000000000000000000000000000000000000000f81bc845c81bf801" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("000000000000000000000000000000000000000000000001081c3846381c0801" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("expPowerOf2_256______12737b4806aed49d7ab7eb74ddda1f35510496a85e1e478a3704f75b24ee136f", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "61010060020a60005560ff60020a60015561010160020a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("8000000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
}

TEST_CASE("expPowerOf2_128______07c52f2c971e3f0c01c5e6ff304223399f96a48fcdc3434fa2a0938124de37b3", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "608060020a600055607f60020a600155608160020a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000100000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000080000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000200000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("addmod2______0d2340969d1058d6112d1aaaafd1e242260a075b9801fc37576ce9df1cf847f1", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60036001600660000308600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_21______c1c01fc64a2e345e6bb31672d7f8bc063b652f80d0f75002d1c49d36a9c7b3bb", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60156101000a600055601560ff0a60015560156101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000001000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000ebcce5125534de6b326ead10e3645765a4312e14ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("000000000000000000000115d749b152c1576391324b46a90c47946632d21501" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("not1______e3aa182b2227b5b90343ecfd84d5e7ecdc8ef49a282262a4651d4809aafc6e67", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6201e2406000526000511960005260206000f3";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("smod1______d9e61a2b0310599d823b17276f69995d294e799066503dcd6bd06a62b6b17c7f", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6003600003600507600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("divByZero______5872a3754ed6c302fcba58fd2332eb0e9d1eaebac9e83d906e5317f10711de16", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6000600204600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("exp2______bd970c7eba2b9d704a1afd3831e8c17073a5c1080806048085d89dccdbee0bfa", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "637fffffff637fffffff0a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("bc8cccccccc888888880000000aaaaaab00000000fffffffffffffff7fffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("mul0______45cd7403ec890b29ae80f0d74b103c96059310c00ecc103470031fd88875573c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6003600202600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000006" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_17______f8e9fd0755c46024b28013f53f8259f6dd3827cc79db275a26c326cfcc6e92d6", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60116101000a600055601160ff0a60015560116101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000010000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("000000000000000000000000000000ef856134040c669755c7c022b6a77810ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("000000000000000000000000000001118ab1645ca45755422870354ea8881101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("smod_i256min2______2482d9bf2796986ef35654b87d92ccc1132251b51dc9ad3d8bde2e45e8659d56", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600160016000037f80000000000000000000000000000000000000000000000000000000000000006000030703600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("fibbonacci_unrolled______6ca8d6f0f1975e8ffe105ae83d44902ae15cc738402d3921eda5194feac10303", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6001600181810181810181810181810181810181810181810181810181810181810181810181810181810181810181810181810181810160005260206000f3";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("mod3______e8738afe9d6d4a8e2a3f430ea09cfcaa563a4779254b91c81374e5a297409634", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6000600306600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("expPowerOf256Of256_26______466a34547f08dfadfe7b8170595dbcd4a85e8841d60e17d45535efadf41e6a24", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "601a6101000a6101000a600055601a60ff0a6101000a600155601a6101010a6101000a600255601a6101000a60ff0a600355601a60ff0a60ff0a600455601a6101010a60ff0a600555601a6101000a6101010a600655601a60ff0a6101010a600755601a6101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("085514ff7f000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("1d164db738eb6893868b361ad2803f97be35764456e82a837667a693d1e600ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("8b92c24abebf376a5aab5ff4dfd3538a03d38a10bced2aae8e1a8a85b81a00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("f7aa6aff81000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("6931bda98c70e860a1f6a5224940f1ec7e6734cd9456c95806384f7cb7e60101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("3402a9db66492dfc2a220715e76243469462f24edc56903ba1d8e96ed21a0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_4______c2d1ac475be3d9708dd091aeee22a87804a4004cbe6a382c63f1d4d304764b57", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60046101000a600055600460ff0a60015560046101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000100000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000fc05fc01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000104060401" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_30______479e812da82943e323dfedc14ea5728ff43add90f4b8440158a12862c97a54f2", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "601e6101000a6101000a600055601e60ff0a6101000a600155601e6101010a6101000a600255601e6101000a60ff0a600355601e60ff0a60ff0a600455601e6101010a60ff0a600555601e6101000a6101010a600655601e60ff0a6101010a600755601e6101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("7f00000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("e9772778f50fa0a69cd10fa019ac56d72ac7a7d7af26c4ba28415c8f41e200ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("33f0385ef73feebdb952e5adb643dd0fa178fd9271578219ad50a73d241e00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("8100000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("fd405cce8f73dffc04a6f0ff6ffc6bf7961876d09c5b4933a68f0cc623e20101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("c5a8f4566fd2e96e4ce3a8b3ec0863e7b20bc3b2f3dc5261ba8a0174421e0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("sub4______05d9e4b327336db04e1b79dd21df56bd61361029dd7b4efb33e94315f6f1fe42", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff03600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("signextend_BitIsNotSet______ad6c39d9aab1ff75cc4d29e0952352a880d3239b3dcd9ac284b8738fac7debe9", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "62122f6a60000b600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("000000000000000000000000000000000000000000000000000000000000006a" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_31______c0c9812a4aec910c25f698f7851d356969417e40a66756b8579024fb5ad6946c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "601f6101000a6101000a600055601f60ff0a6101000a600155601f6101010a6101000a600255601f6101000a60ff0a600355601f60ff0a60ff0a600455601f6101010a60ff0a600555601f6101000a6101010a600655601f60ff0a6101010a600755601f6101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("f9cb87f5b1ab58602f52a1e9d392e5675b86a59a53943a8d4ec2a915dc9dfeff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("893d729a64e318860ec5047e70e598da163eb41e71e74b04dfd4712d419f00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("ee5f2839c1b4f6ca05e6fdb04e2fb49c0f860b3765c27dc781a150cb7f9fff01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("b4c358e3c6bcddfb509ea487d733df0e1854f29c3b6bfd4a8caabe3f609f0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("signextend_BitIsSetInHigherByte______ac72667a2e447bdbe107272ec54041d01f13e9d0ad67be9f35ceb797fa8fa3d9", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6212faf460010b600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffaf4" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_5______6146ceb91510b1cb9c01dab28929f5c50ab7351b971631b79b4e55ec4f9d0758", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60056101000a600055600560ff0a60015560056101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000010000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("000000000000000000000000000000000000000000000000000000fb09f604ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("000000000000000000000000000000000000000000000000000001050a0a0501" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_27______4cb84dd85410e6e10a6fb0903c5336c92f1f3b1183b37b0d69793ab6eeff538a", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "601b6101000a6101000a600055601b60ff0a6101000a600155601b6101010a6101000a600255601b6101000a60ff0a600355601b60ff0a60ff0a600455601b6101010a60ff0a600555601b6101000a6101010a600655601b60ff0a6101010a600755601b6101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("5514ff7f00000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("178918ffbcb401d4efd2f7dfb4d01a897172267f0f491121ac52dd614899feff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("38ecff71480ca0b422f2ed6f780d5fead2ae234a49104b10a86f7f0dd19b00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("aa6aff8100000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("d02811cb5dc1d80567e810532b235b7672f5c78cd6e89bb511d5e2d8f79bff01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("1b4e6404f474c18055d30bb8987672f59e97980d6f9de1764c0fbec5ec9b0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("expPowerOf2_2______a2bac0fecd9bb22498ef34248c689e040dff1c9551695bb52490005655252a90", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600260020a600055600160020a600155600360020a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000004" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000008" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("addmodDivByZero______07a2c67042f0a0a767dabddeff135071990a3121c53e59388d423f7312d97732", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60006001600408600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("mod2______1f5ca72bfa3c2c922df107ec65b03875606654bc9323bbe4d0d6917cc70b78a0", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600006600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("mul1______62739e6b84ff552b35b894761b28b32935dd20af24275507ba8fb2823e21a3fa", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff02600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_16______9b8e345adf5a89c6fd364d4f668a7bd07dafbe8d54035b530c17592ffc0a7867", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60106101000a600055601060ff0a60015560106101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000100000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("00000000000000000000000000000000f075d70b0f1b82196f36f719d077f001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("00000000000000000000000000000001107a372d2f74e272cf59171e30781001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("exp3______60cc7f7666a3c4ef52e3af53332f1cf55f8a6b0bffe0395fa9236bb58d6600d8", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "637fffffff60000a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("smod0______657d85189406a5174b2e2c8d2a156aa8bd3844d715a6a21cca3f977769de8ddf", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6003600003600560000307600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_20______d1c3af7ccb5c6194e2169b9e2f961b10e1899b7fefde762a18e4962171293562", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60146101000a600055601460ff0a60015560146101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000010000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("000000000000000000000000ecb99eb1063b1984b725d2e3c72b82e88cbdec01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("00000000000000000000000114c2872a2898bea4ec46054167a4a2f174be1401" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("addmod3______90b707def53d6810926ea7b4b409adf597e5ab856e36916ad59bd0080b3493c1", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60036000036001600408600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000005" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_9______1c9cbff4e50f2007147b4c1ee0f4f1bce34cc34003bdf76c682d6f8fe096a842", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60096101000a600055600960ff0a60015560096101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000001000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000f723ac7d8253dc08ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("00000000000000000000000000000000000000000000010924547e7e54240901" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("add3______3bd86a492ae4e00b1432d5458d920592919816b61704a200a619a4519dc033f6", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6000600001600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("expPowerOf256Of256_1______cfa261cd17404f41ad16a6c50f85e826ba31c9ef0f4fb07330baccb7fceaf896", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60016101000a6101000a600055600160ff0a6101000a60015560016101010a6101000a60025560016101000a60ff0a600355600160ff0a60ff0a60045560016101010a60ff0a60055560016101000a6101010a600655600160ff0a6101010a60075560016101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("06c3acd330b959ad6efabce6d2d2125e73a88a65a9880d203dddf5957f7f0001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("8f965a06da0ac41dcb3a34f1d8ab7d8fee620a94faa42c395997756b007ffeff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("bce9265d88a053c18bc229ebff404c1534e1db43de85131da0179fe9ff8100ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("02b5e9d7a094c19f5ebdd4f2e618f859ed15e4f1f0351f286bf849eb7f810001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("c73b7a6f68385c653a24993bb72eea0e4ba17470816ec658cf9c5bedfd81ff01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("b89fc178355660fe1c92c7d8ff11524702fad6e2255447946442356b00810101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("mulmod1_overflow2______39bbcf3f466015094b1966b488fb130f5f43e7f754742dcd73ab9fe36b175140", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600560027f800000000000000000000000000000000000000000000000000000000000000009600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("sdiv2______f23ddbb1007d7edd1cc43aa31e6754f5bffc664fd470d83d4ba9c5d73f92e05a", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6004600003600260000305600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("sdivByZero1______da488af1640adb0d5fe53576afb146ba3e48b79d6fb20ebc0a723810c957347c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000305600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("expPowerOf256Of256_11______0b1366d68a11bbb8b60d5458d1c5f75983c677beda062040a2a12217dcd6dd92", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600b6101000a6101000a600055600b60ff0a6101000a600155600b6101010a6101000a600255600b6101000a60ff0a600355600b60ff0a60ff0a600455600b6101010a60ff0a600555600b6101000a6101010a600655600b60ff0a6101010a600755600b6101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("e1440264b8ee0cea0218879ec55c33085514ff7f000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("29575fdce377b23043e489e358581474bc863187fa85f9945473a2be5889feff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("3df8c030ec521fb109c4d887dbbc14c7c9c9921b27058e3503971b60b18b00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("67799740340daf4a30f000b68fb921f7aa6aff81000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("540a4e4635b40585e09ff10b63ffe310dd717fca5c0a51570091e25e378bff01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("dbbaef5c49ffee61b08cde6ebc8dba6e9a62d56c2355d1980cb9e790bc8b0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("divByZero_2______78d75e4a3fa542827bcd7d0ea0219c73036b1894b4f4f1d2db5115e9d6b82245", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60076000600d0401600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000007" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("smod7______a36ed55f2f8ba020ce5a62ef6e40d293dd21f437a822cd6f33b5525c8af00c8c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000307600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x2710), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("addmodDivByZero3______9d7b88296068c5ed1620b7eaad6d1790e9140bd888ff108169d44055223777a3", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60016000600060000803600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("sdiv9______18566af59c50610c4d0730ca3171edb8079ef515fe3580e356caf81401a54bab", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6001600160000305600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("exp4______3e3173753802a0d3265703667247f978ebbe5f0e2d22c9cf94f0c09efb3a2ac2", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6000637fffffff0a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("mulmod1______ed3024180ecf5192c2c72e6c0e0c646a31121a9c2d81f8fc661cc404c2c49175", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60036002600003600160000309600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("expPowerOf256_11______b1c6926a4ec774b5eb1dc422f228e11e96f892b8bbb40a525ba97ac9f30b610a", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600b6101000a600055600b60ff0a600155600b6101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000010000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("000000000000000000000000000000000000000000f5365c4833ccb6a4c90aff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000010b37a64bcfcf4aa5370b01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("mul6______93939ec6ec2137f19afdb9596236ff35ae94068ba39563ed649153ed975d8a9d", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff02600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_20______c3555c8b166600d82076a8dace17cdba2e354cc84b92e88080ae847533a1f39e", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60146101000a6101000a600055601460ff0a6101000a60015560146101010a6101000a60025560146101000a60ff0a600355601460ff0a60ff0a60045560146101010a60ff0a60055560146101000a6101010a600655601460ff0a6101010a60075560146101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("18879ec55c33085514ff7f000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("67e4797dc21f02ce4a7c52218c7dbea5d212e6c244e24f0ba4c08613c7ec00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("a1ce1a085f258785846939cc1d2e8725ac94ad4dff8913234e00679fb41400ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("f000b68fb921f7aa6aff81000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("cce501857a1cb45473915a28082af950e0f78f7e2de68ce748adb661b3ec0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("3b2e28d274a16c08b58a23bad63bba6d7b09685769d1f68ca3873bedc8140101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_2______c16dec87b8f5f4457c20c3ef8bba3a291ca99433d10c52a8c95844ae4c80f774", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60026101000a600055600260ff0a60015560026101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000010000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("000000000000000000000000000000000000000000000000000000000000fe01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000010201" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("sub2______2a70037d8d25f8333be090608c64a57f9d894ba31647d9ca910f1d68f6f91d73", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6017600003600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe9" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("signextendInvalidByteNumber______fafb83f281612538c3b8a0ad616214c94f232a83b661ddeb2913d44c86c5e1f8", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "62126af460500b600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000126af4" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_16______7abe4db41b9db5ddba7e759a19f56721bfda3633d9a209a61885770b48730ba0", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60106101000a6101000a600055601060ff0a6101000a60015560106101010a6101000a60025560106101000a60ff0a600355601060ff0a60ff0a60045560106101010a60ff0a60055560106101000a6101010a600655601060ff0a6101010a60075560106101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("82ec698218879ec55c33085514ff7f0000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("3122f4bcdf6dd8b265cd18eb6af28c879aed44a35e0bf59273e39e6c7ff000ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("6a2b3bc87a02c29b9d27757df43047ecd0f15485270fca27417a701c701000ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("228fc9b0f000b68fb921f7aa6aff810000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("88e1259502eef93d46060aacc9e2ff506c734dade0b6714ab12d17e46ff00101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("4a103813c12c12169b218296bb0a9eae80cf8d2b158aa70eb990f99480100101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("modByZero______60d18d29ddc0d3fada77384fd6a1fdb5c8db6f39cac1d49150133ad4c876111e", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6001600060030603600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("divByNonZero3______18eb2a03d9fb6139351c9348177f453fae7b4d0147cb61f0bc054cc94611fc79", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6001600104600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("exp8______8cc82dc5b40b6997018e4dd9ed813adc10d48b61aa086c3d44b89c02180d9286", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600060000a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("sdiv5______900ae8a1b5b71f5af75af223f8157cca4eac7224648cae647c2e9973be2db508", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60016000037f800000000000000000000000000000000000000000000000000000000000000060000305600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("8000000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf2_16______d929b716ca2db29bb5383636946442ae3b248a8044221ae84cebd98b40bf3fa2", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "601060020a600055600f60020a600155601160020a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000010000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000008000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000020000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_6______0b504c01aa8be1b0f4d75843a158f9ece56004fdfb31cbdd8ea631b19bd31c2e", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60066101000a6101000a600055600660ff0a6101000a60015560066101010a6101000a60025560066101000a60ff0a600355600660ff0a60ff0a60045560066101010a60ff0a60055560066101000a6101010a600655600660ff0a6101010a60075560066101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("1948059de1def03c4ec35fc22c2bb8f2bf45dc33085514ff7f00000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("41f818a8e24eb6d7bb7b193b4f2b5fdcf4bd0d453f2ac3499d8830d391fa00ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("ede6fe4a943dfb5d967a2b85d6728759d40d2ef0ae4bc28bbb1867f98c0600ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("083c936cbaad5de592badc2e142fe4ebd6103921f7aa6aff8100000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("57385019fe4e0939ca3f35c37cadfaf52fba5b1cdfb02def3866e8068bfa0101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("810ac878bd98428f6be8c6426ba9f9da09e3e33bf4fe10bfa3f8b12c92060101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_31______49c27829894da6d63678e456733ea6fdc70f2757967ba5abbf180965428758ee", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "601f6101000a600055601f60ff0a600155601f6101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0100000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("00e2bfe95c5d7067567402dd9d7235fc088ac84eab8113bf8d7e3c288d2f1eff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0120e30c8c1bb25c9d2219ea196c17ded3d775b231bbd28005b131fa90d11f01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("sdiv_i256min2______90030696ae4a357369cc2782a28d4815a9935a9de909919b56b4a35e73a6fe1f", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60016000037f800000000000000000000000000000000000000000000000000000000000000060000305600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("8000000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("addmod2_1______98bb343b4feee04868cc71c50989783b808acc50b1c98e7ade4776e994906b50", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60036001600660000308600360056000030614600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("mulmoddivByZero1______a98185211df6a24ee07ad038dcac863c96507e63593dfa4ba40e268dec182118", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60006001600009600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("add4______84ab9087035c1a89c5fb97de39f5a70014a07ccd234033a86345e1023a9e3f63", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600101600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("addmodBigIntCast______08fea224001a172ce28f79d64d39b6ae2010c93b8db2a22eceaf648b4864410b", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600560017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff08600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_27______0b01e16cc7bd26138401de1bc3b8243c48d1b0a460b24a562fa58b5b6a2af2d1", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "601b6101000a600055601b60ff0a600155601b6101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000001000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000e653d6571cdebb270b53c9d44c40bcd425165d5af1157d6ba11aff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("00000000011c6ab2cdebf906306b38bbf7d6c52648e2d6bc63859e996e5f1b01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_26______6dccbbcb0ee8cd7d2f5843ad5ddf775a3226c7bf803ec5e6a6c6743745cf39a9", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "601a6101000a600055601a60ff0a600155601a6101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000010000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("000000000000e73b116885641f4651a56f438fd08d61869cfa55465bd944e601" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000011b4f636a81778ea1c96f4cab2b998cbc26b00c572e7029451a01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("mulUnderFlow______f00e90cf7a2da69a3d545bd6f562a8277dd75b34d1ef2c4a939be0f95768ec61", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600102600155";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("mulmod3_0______0070f9a443a2322b95c7b5087c03809c2f1998b04ba560d40d23e94daef7f961", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60026003600003600160050914600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("sdiv_i256min3______c515fc2566610c432b0de0dd441f64fa3786ed7b2f921e19ddd23ff00251d920", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6000037fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff05600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("01"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("addmod2_0______15d55915fdfbaed97e9812ea54813c07e1882f34b815255f6d795104a5320369", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60036001600660000308600360056000030714600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("stop______e2fb82d7e038c48bcb3dc482432600771264d43e043100f7c8ac802958a7e94f", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "00";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("signextend_bitIsSet______079a0a92b727ced019553f0b8d57e0a53cf85803f09a10ea969030cfd302439a", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "62122ff460000b600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff4" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_30______48e0ff7a9fb61234eb98e08920d2f6edc07d27fb3d8ce297e801640882ba2a77", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "601e6101000a600055601e60ff0a600155601e6101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0001000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000e3a38ce946b71e74e8ebc966d90f0b139e66b560e1f5b542c0fd25b2e201" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("00011fc34942d8d9831a0811d8412aecf1e1f58031ffbc16699c151cddb31e01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("sdiv_dejavu______6018ba5a8727b5f6c60678c66c95b410fcc2b2c14fe8b47e88aede7f66c73244", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600560096000030580600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x989680), /* gas */
    BigInt::fromHex("01"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf2_8______b501d810365e03840b7f8635052551bd05c65ee103cdbd989438d3dbdcfb6ac3", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600860020a600055600760020a600155600960020a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000100" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000080" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000200" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_7______987100c02d0255c99706c19220a994ab2b46102fc6893ad08aca44c16626ce19", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60076101000a6101000a600055600760ff0a6101000a60015560076101010a6101000a60025560076101000a60ff0a600355600760ff0a60ff0a60045560076101010a60ff0a60055560076101000a6101010a600655600760ff0a6101010a60075560076101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("8bb02654111ad8c60ad8af132283a81f455c33085514ff7f0000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("a8f75c129dbb8466d6703a2a0b8212131b3248d70e2478862ac40fe17485feff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("5fd4d2de580383ee59f5e800ddb3f1717ceae03aede19d3dec5e5a69918700ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("c8624230b524b85d6340da48a5db20370fb921f7aa6aff810000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("287b58a5a13cd7f454468ca616c181712f5ed25433a7d5a894b6ced35f87ff01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("09930d11ac2804fa977bf951593c8dff8498779cc0cdc5812a4fba2f98870101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("expXY______b1f48c92fc069d4c6db24060394e4753fd7768e6d8c71dcf842e09536b0bf6a2", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6000356000556020356001556001546000540a600255";
  bytes_t data_bytes = Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000100000000000f");

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("000000000000000000000000000000000000000000000000000100000000000f" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
}

TEST_CASE("mulmod1_overflow4______e299f946769fce28c47007d1e2e2313465406917bacadaf1cfabf05f86db6844", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600560027f800000000000000000000000000000000000000000000000000000000000000109600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("sdiv4______3065d6c46735c24934865e9b79e22fb6f62c23bf23882402a1690dfe873bfe74", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6004600003600505600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("divByNonZero2______07c53576e7fa46c1ee1d5f30da0d479a49411004f70ea23881c6af61096d6347", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6018600004600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("expPowerOf256Of256_17______d7a8e01c7d7ef07a3ab3091cf3116a4f6ec8efab1f5dabc6abdab919a3e96f08", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60116101000a6101000a600055601160ff0a6101000a60015560116101010a6101000a60025560116101000a60ff0a600355601160ff0a60ff0a60045560116101010a60ff0a60055560116101000a6101010a600655601160ff0a6101010a60075560116101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("ec698218879ec55c33085514ff7f000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("722ad218eb1995a2d257c4c06d8de993c203cfc8e3512df7d633e17e908ffeff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("8ac9b5ec08d74612cb29f941481d274b51721af2296207c0da8d24667f9100ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("8fc9b0f000b68fb921f7aa6aff81000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("81d5ff63680841482299f3eab616446dcd336f537c0c565aa4112ab95d91ff01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("9c6ca90dac4e97dea02ac969e8649ee9e6232e0c3f4797411151cb8f90910101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("sub3______0e65bb014804438d489adaded93fa290d960a3c2400d795a7da572d8dd6c0e94", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600003600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_3______4ab92df5bf373064de3eeb8b359d28c9f1146673cf826d2ec82e531fc379a3e1", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60036101000a600055600360ff0a60015560036101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000001000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000fd02ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000001030301" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256Of256_21______10c6f39a124dba927aaa49875627683b285895b497464e74a1202217096e2089", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60156101000a6101000a600055601560ff0a6101000a60015560156101010a6101000a60025560156101000a60ff0a600355601560ff0a60ff0a60045560156101010a60ff0a60055560156101000a6101010a600655601560ff0a6101010a60075560156101010a6101010a600855";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("879ec55c33085514ff7f00000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x03), context->codeAddress))
  );
  CHECK("7fd07055ff50cdfe4b4bd9a15133d72d3607d92eb7ac81bac93db7ff4c93feff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x04), context->codeAddress))
  );
  CHECK("665ac5c769e87f61d5993abc26522fbfca2734d76a63216b2d550d29c79500ff" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x05), context->codeAddress))
  );
  CHECK("00b68fb921f7aa6aff8100000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x06), context->codeAddress))
  );
  CHECK("1c93db67c9884bc694686d69a25a5d7ed089841d5ce147fdd7199ab00d95ff01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x07), context->codeAddress))
  );
  CHECK("485053d8ff66be52036597520344fac87b6a305426a9e49221d3f934dc950101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x08), context->codeAddress))
  );
}

TEST_CASE("expPowerOf2_4______631f6dc2dc4c0da8fcd51e6b47631de57699ba5552f74bfffcf0c1db19ff0900", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600460020a600055600360020a600155600560020a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000010" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000008" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000020" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("signextend_00______f2d0e5f5e92b4fabe5f8849039ea24659f13dd41ab170684ac9ad4713806ccf6", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600060000b600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("mod4______1251fd388dafce899b3b8aaa3c1609354b876b279fb749c000888334946e9bc4", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6003600260000306600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("expPowerOf256_10______136a6ef3b914e46f9118f5d870a74dd1a4e9a3cfc97c84f412d81c07af01b036", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600a6101000a600055600a60ff0a600155600a6101010a600255";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000100000000000000000000" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
  CHECK("00000000000000000000000000000000000000000000f62c88d104d1882cf601" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x01), context->codeAddress))
  );
  CHECK("000000000000000000000000000000000000000000010a2d78d2fcd2782d0a01" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x02), context->codeAddress))
  );
}

TEST_CASE("mul7______68228cd9e856bee3481b095c8d1d2ab9fa30a0a1b1fbe697e3a8b01dfb6778e4", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7001234567890abcdef0fedcba09876543217001234567890abcdef0fedcba09876543217001234567890abcdef0fedcba0987654321020260005260206000f3";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("sdiv8______ea05e5ca26b556596f9d6e65f84d238632215eb308b26b1da829b48a4f07e9a1", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6001600003600160000305600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("exp5______e6fc1d5718f3d1bcbc540b19ad2c208aab3e582d581278b7d692ea4b733deecd", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60016101010a600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000101" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}

TEST_CASE("mulmod0______15ef0419e36c1c1b45577f633dde9b4f4c0fc16258a46060ac228551fd5b9168", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60026002600109600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("addmodDivByZero2______ac86e7a61c79097514f97614f6afbd86d3f7d6e529c48b15a318ecbbf22e75f4", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60006000600108600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("arith1______e8665046be1f18c3372a4cdc4aab1ffc95156012239eaca43fd5c6c388f25075", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("989680"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6001600190016007026005016002900460049060016021900560150160030260059007600303600960110a60005260086000f3";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0f4240), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
}

TEST_CASE("smod6______23d40161e481cfa284f74d8d7a49de035d09bf5fc3f565f80292f804f92cf81f", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000307600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f2947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    params.address,
    params.codeHash,
    params.codeVersion,
    params.address,
    params.sender,
    params.origin,
    params.gas,
    params.gasPrice,
    params.value,
    std::make_shared<bytes_t>(params.code),
    std::make_shared<bytes_t>(params.data)
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(context, stack, gasometer);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  vm.execute(operation, mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState->get(uint256_t(0x00), context->codeAddress))
  );
}



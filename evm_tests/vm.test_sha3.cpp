#include "catch.hpp"
#include <memory>
#include <evm/utils.hpp>
#include <evm/vm.h>
#include <evm/hex.hpp>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.hpp>
#include <evm/big_int.hpp>
#include "external_mock.h"

TEST_CASE("Hash zero", "[sha3]") {
  // given
  // (PUSH1 ((60) 00))
	// (PUSH1 ((60) 00))
	// (SHA3 (20))
  std::string bytecode_str = "6000600020";
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
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"),
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
  vm.execute(operation, context, mem, accountState, external, call);

  // then
  REQUIRE("c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470" == 
    Utils::uint256_2str(vm.stack->top())
  );
}
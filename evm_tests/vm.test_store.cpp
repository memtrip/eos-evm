#include "catch.hpp"
#include <memory>
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

TEST_CASE("Store two values", "[store]") {
  // given
  // (PUSH1 ((60) 02))
	// (PUSH1 ((60) 01))
	// (SSTORE (55))
  std::string bytecode_str = "6002600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  env_t env = Utils::env();
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
  VM vm(context, stack);

  std::shared_ptr<Call> call = std::make_shared<Call>(0);
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external);
  std::shared_ptr<Memory> mem = std::make_shared<Memory>();

  // when
  vm.execute(mem, accountState, external, call);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" == 
    Utils::uint256_2str(accountState->get(0x01))
  );
}
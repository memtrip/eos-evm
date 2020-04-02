#include "catch.hpp"
#include <memory>
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

TEST_CASE("Conditional jump to destination truthy", "[jumps]") {
  // given
  // (PUSH1 ((60)06))
	// (PUSH1 ((60)03))
  // (LT (10))
  // (PUSH1 ((60)0F))
  // (JUMPI (57))
  // (PUSH1 ((60)06))
	// (PUSH1 ((60)03))
	// (MUL (02))
  // (STOP (00))
  // (JUMPDEST (5B))
  // (PUSH1 ((60)02))
  // (PUSH1 ((60)10))
	// (DIV (04))
  std::string bytecode_str = "6006600310600F57600660030200025B6002601604";
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
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" == 
    Utils::uint256_2str(vm.stack->top())
  );
}

TEST_CASE("Conditional jump to destination not true", "[jumps]") {
  // given
  // (PUSH1 ((60)03))
	// (PUSH1 ((60)06))
  // (LT (10))
  // (PUSH1 ((60)0F))
  // (JUMPI (57))
  // (PUSH1 ((60)06))
	// (PUSH1 ((60)03))
	// (MUL (02))
  // (STOP (00))
  // (JUMPDEST (5B))
  // (PUSH1 ((60)02))
  // (PUSH1 ((60)10))
	// (DIV (04))
  std::string bytecode_str = "6003600610600F57600660030200025B6002601604";
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000012" == 
    Utils::uint256_2str(vm.stack->top())
  );
}

TEST_CASE("Unconditional jump to destination", "[jumps]") {
  // given
  // (PUSH1 ((60)03))
	// (PUSH1 ((60)06))
  // (PUSH1 ((60)08))
  // (JUMP (56))
	// (MUL (02))
  // (JUMPDEST (5B))
	// (DIV (04))
  std::string bytecode_str = "60036006600856025B04";
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
    Utils::uint256_2str(vm.stack->top())
  );
}

TEST_CASE("Jumps", "[jumps]") {
  std::string bytecode_str = "600160015560066000555b60016000540380806000551560245760015402600155600a565b";
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState->get(0x00))
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000078" == 
    Utils::uint256_2str(accountState->get(0x01))
  );
}
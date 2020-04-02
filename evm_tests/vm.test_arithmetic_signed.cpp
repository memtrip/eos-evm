#include "catch.hpp"
#include <memory>
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

TEST_CASE("signed division", "[signed]") {
  std::string bytecode_str = "650123651246236265432290056000556501236512462360009005600155";
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
  CHECK("000000000000000000000000000000000000000000000000000000000002e0ac" == 
    Utils::uint256_2str(accountState->get(0x00))
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState->get(0x01))
  );
}

TEST_CASE("signed mod", "[signed]") {
  std::string bytecode_str = "650123651246236265432290076000556501236512462360009007600155";
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
  CHECK("0000000000000000000000000000000000000000000000000000000000076b4b" == 
    Utils::uint256_2str(accountState->get(0x00))
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState->get(0x01))
  );
}

TEST_CASE("add mod, mul mod", "[signed]") {
  std::string bytecode_str = "60ff60f060108282820860005509600155600060f0601082828208196002550919600355";
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(accountState->get(0x00))
  );

  CHECK("000000000000000000000000000000000000000000000000000000000000000f" == 
    Utils::uint256_2str(accountState->get(0x01))
  );

  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" == 
    Utils::uint256_2str(accountState->get(0x02))
  );

  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" == 
    Utils::uint256_2str(accountState->get(0x03))
  );
}

TEST_CASE("exponent", "[signed]") {
  std::string bytecode_str = "6016650123651246230a6000556001650123651246230a6001556000650123651246230a600255";
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
  CHECK("90fd23767b60204c3d6fc8aec9e70a42a3f127140879c133a20129a597ed0c59" == 
    Utils::uint256_2str(accountState->get(0x00))
  );

  CHECK("0000000000000000000000000000000000000000000000000000012365124623" == 
    Utils::uint256_2str(accountState->get(0x01))
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(accountState->get(0x02))
  );
}

TEST_CASE("signextend", "[signed]") {
  std::string bytecode_str = "610fff60020b60005560ff60200b600155";
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
  CHECK("0000000000000000000000000000000000000000000000000000000000000fff" == 
    Utils::uint256_2str(accountState->get(0x00))
  );

  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" == 
    Utils::uint256_2str(accountState->get(0x01))
  );
}

TEST_CASE("signed comparison", "[signed]") {
  std::string bytecode_str = "60106000036010818112600055136001556010601060000381811260025513600355";
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

  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(accountState->get(0x01))
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(accountState->get(0x02))
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(accountState->get(0x03))
  );
}
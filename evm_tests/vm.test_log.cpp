#include "catch.hpp"
#include <memory>
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

TEST_CASE("Log empty (LOG0)", "[log]") {
  // given
  std::string bytecode_str = "60006000a0";
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
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);

  // when
  exec_result_t result = vm.execute(mem, accountState, external, call);

  // then
  CHECK(99619 == Utils::gasLeft(result));

  // then
  CHECK(1 == external->logSpy.size());
  CHECK(0 == external->logSpy[0].first.size());
  CHECK(0 == external->logSpy[0].second.size());
}

TEST_CASE("Log sender (LOG1)", "[log]") {
  // given
  std::string bytecode_str = "60ff6000533360206000a1";
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
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);

  // when
  exec_result_t result = vm.execute(mem, accountState, external, call);

  // then
  CHECK(98974 == Utils::gasLeft(result));

  // then
  CHECK(1 == external->logSpy.size());
  CHECK(1 == external->logSpy[0].first.size());
  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9e" == 
    Utils::uint256_2str(external->logSpy[0].first[0])
  );
  CHECK("ff00000000000000000000000000000000000000000000000000000000000000" == 
    Hex::bytesToHex(external->logSpy[0].second)
  );
}

TEST_CASE("Log origin and sender (LOG2)", "[log]") {
  // given
  std::string bytecode_str = "60ff600053333260206000a2";
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
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);

  // when
  exec_result_t result = vm.execute(mem, accountState, external, call);

  // then
  CHECK(98977 == Utils::gasLeft(result));

  // then
  CHECK(1 == external->logSpy.size());
  CHECK(2 == external->logSpy[0].first.size());
  CHECK("00000000000000000000000000000000000000000000000000000000001283fe" == 
    Utils::uint256_2str(external->logSpy[0].first[0])
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9e" == 
    Utils::uint256_2str(external->logSpy[0].first[1])
  );
  CHECK("ff00000000000000000000000000000000000000000000000000000000000000" == 
    Hex::bytesToHex(external->logSpy[0].second)
  );
}

TEST_CASE("Log caller, origin, sender (LOG3)", "[log]") {
  // given
  std::string bytecode_str = "60ff60005333323060206000a3";
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
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);

  // when
  exec_result_t result = vm.execute(mem, accountState, external, call);

  // then
  CHECK(98977 == Utils::gasLeft(result));

  // then
  CHECK(1 == external->logSpy.size());
  CHECK(3 == external->logSpy[0].first.size());
  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9a" == 
    Utils::uint256_2str(external->logSpy[0].first[0])
  );
  CHECK("00000000000000000000000000000000000000000000000000000000001283fe" == 
    Utils::uint256_2str(external->logSpy[0].first[1])
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9e" == 
    Utils::uint256_2str(external->logSpy[0].first[2])
  );
  CHECK("ff00000000000000000000000000000000000000000000000000000000000000" == 
    Hex::bytesToHex(external->logSpy[0].second)
  );
}

TEST_CASE("Log number, caller, origin and sender (LOG4)", "[log]") {
  // given
  std::string bytecode_str = "60ff6000534333323060206000a4";
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
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(external, cacheItems);
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);

  // when
  exec_result_t result = vm.execute(mem, accountState, external, call);

  // then
  CHECK(79935 == Utils::gasLeft(result));

  // then
  CHECK(1 == external->logSpy.size());
  CHECK(4 == external->logSpy[0].first.size());
  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9a" == 
    Utils::uint256_2str(external->logSpy[0].first[0])
  );
  CHECK("00000000000000000000000000000000000000000000000000000000001283fe" == 
    Utils::uint256_2str(external->logSpy[0].first[1])
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000ea0e9e" == 
    Utils::uint256_2str(external->logSpy[0].first[2])
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000f950e1" == 
    Utils::uint256_2str(external->logSpy[0].first[3])
  );
  CHECK("ff00000000000000000000000000000000000000000000000000000000000000" == 
    Hex::bytesToHex(external->logSpy[0].second)
  );
}
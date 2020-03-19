#include <stdio.h>
#include <variant>
#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include "external_mock.h"

TEST_CASE("shift left, write to memory, return", "[return_memory]") {
  std::string bytecode_str = "600560011b6000526001601ff3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};
  env_t env = Utils::env();

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  REQUIRE(ExecResult::DONE == result.first);

  gas_left_t gasResult = std::get<gas_left_t>(result.second);
  REQUIRE(GasType::NEEDS_RETURN == gasResult.first);

  NeedsReturn needsReturn = std::get<NeedsReturn>(gasResult.second);
  bytes_t returnDataSlice = Utils::returnDataSlice(needsReturn.data);
  CHECK("0a" == Hex::bytesToHex(returnDataSlice));
}

TEST_CASE("shift right, write to memory, return", "[return_memory]") {
  std::string bytecode_str = "600560011c6000526001601ff3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};
  env_t env = Utils::env();

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  REQUIRE(ExecResult::DONE == result.first);

  gas_left_t gasResult = std::get<gas_left_t>(result.second);
  REQUIRE(GasType::NEEDS_RETURN == gasResult.first);

  NeedsReturn needsReturn = std::get<NeedsReturn>(gasResult.second);
  bytes_t returnDataSlice = Utils::returnDataSlice(needsReturn.data);
  CHECK("02" == Hex::bytesToHex(returnDataSlice));
}

TEST_CASE("sar, write to memory, revert", "[return_memory]") {
  std::string bytecode_str = "600160000360021d60005260016000fd";
  bytes_t codeBytes = Hex::hexToBytes(bytecode_str);
  bytes_t emptyBytes = bytes_t();
  params_t params =  Utils::params(codeBytes, emptyBytes);
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};
  env_t env = Utils::env();

  // when
  exec_result_t result = vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  REQUIRE(ExecResult::DONE == result.first);

  gas_left_t gasResult = std::get<gas_left_t>(result.second);
  REQUIRE(GasType::NEEDS_RETURN == gasResult.first);

  NeedsReturn needsReturn = std::get<NeedsReturn>(gasResult.second);
  bytes_t returnDataSlice = Utils::returnDataSlice(needsReturn.data);
  CHECK("ff" == Hex::bytesToHex(returnDataSlice));
}
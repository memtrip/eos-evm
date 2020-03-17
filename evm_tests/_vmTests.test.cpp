//
// Auto generated based off the Ethereum tests found here:
// https://github.com/ethereum/tests/blob/develop/VMTests/
//
#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include <evm/big_int.h>
#include "external_mock.h"

TEST_CASE("suicide______4622c577440f9db4b3954a1de60bf2fac55886dcb0ec4ecaf906c25bc77372e7", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("00")), /* blockNumber */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("01")), /* timestamp */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f4240")), /* gasLimit */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba")), /* coinbase */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0100")), /* difficulty */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("")) /* blockHash */
  };

  std::string bytecode_str = "33ff";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6")), /* address */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* sender */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("cd1722f3947def4cf144679da39c4c32bdc35681")), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("5af3107a4000")), /* gasPrice */
    BigInt::fromBigEndianBytes(Hex::hexToBytes("0de0b6b3a7640000")), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState accountState(accountItems, &ext);
  Gasometer gasometer(params.gas);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}



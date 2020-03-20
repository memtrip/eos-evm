//
// 19.03.2020
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

TEST_CASE("sha3_0______55a13dc9cd0457c545a8ff9a046a83facd094f8bc1b0aa57a04d58a47f1cca2c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6000600020600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x174876e800), /* gas */
    BigInt::fromHex("3b9aca00"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470" ==
    Utils::uint256_2str(accountState.get(0x00))
  );
}

TEST_CASE("sha3_memSizeNoQuadraticCost31______f3e15daec7cb9cd515321d21f091a8863aad12e0555b5d0a2ab01d345da4a609", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60016103c020600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0100000000), /* gas */
    BigInt::fromHex("01"), /* gasPrice */
    BigInt::fromHex("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
    Utils::uint256_2str(accountState.get(0x00))
  );
}

TEST_CASE("sha3_memSizeQuadraticCost63______c707d289675e51f41e5ddb0cfa077b7108e8e29550c5976b3eceb5da3038f7b2", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60016107c020600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0100000000), /* gas */
    BigInt::fromHex("01"), /* gasPrice */
    BigInt::fromHex("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
    Utils::uint256_2str(accountState.get(0x00))
  );
}

TEST_CASE("sha3_1______25997633273316ca1cf2258035f3cf723789e01c837f12095561c96a96d43fd8", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6005600420600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("c41589e7559804ea4a2080dad19d876a024ccb05117835447d72ce08c1d020ec" ==
    Utils::uint256_2str(accountState.get(0x00))
  );
}

TEST_CASE("sha3_memSizeQuadraticCost65______2af3a55f4752f20404afb7c3a1c889d4c21d8b5581a382704e0421cec66aab9f", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600161080020600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0100000000), /* gas */
    BigInt::fromHex("01"), /* gasPrice */
    BigInt::fromHex("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
    Utils::uint256_2str(accountState.get(0x00))
  );
}

TEST_CASE("sha3_memSizeQuadraticCost32______ce67ec8d13841600bc8076b4136260645e72100c4eb9caab7cfaba6c22e143d2", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60016103e020600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0100000000), /* gas */
    BigInt::fromHex("01"), /* gasPrice */
    BigInt::fromHex("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
    Utils::uint256_2str(accountState.get(0x00))
  );
}

TEST_CASE("sha3_bigOffset______9df88aa7ae0baf4b6db458e8101233391101b3343a26dd91ff31335ea40a00dd", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60027e0fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff20600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x010000000000), /* gas */
    BigInt::fromHex("01"), /* gasPrice */
    BigInt::fromHex("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
}

TEST_CASE("sha3_6______db7522537756de38606a515817f7f953d63869199afbdb2ef97441a6500b6655", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff20600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
}

TEST_CASE("sha3_memSizeQuadraticCost33______66fefc4166dd60603843813c9413995b2a0658047d0973cf1776a158581e9141", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600161040020600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0100000000), /* gas */
    BigInt::fromHex("01"), /* gasPrice */
    BigInt::fromHex("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
    Utils::uint256_2str(accountState.get(0x00))
  );
}

TEST_CASE("sha3_memSizeQuadraticCost64______b38d9ca851b3236eb73cb13cad9fea6e605e035f9d6f4628d20d190d9503f330", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60016107e020600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0100000000), /* gas */
    BigInt::fromHex("01"), /* gasPrice */
    BigInt::fromHex("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
    Utils::uint256_2str(accountState.get(0x00))
  );
}

TEST_CASE("sha3_memSizeQuadraticCost64_2______d185939aec4f4aae503167ad5a5f8b40aa65f4a532c2014ed9f905678cbbd3b3", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60206107e020600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0100000000), /* gas */
    BigInt::fromHex("01"), /* gasPrice */
    BigInt::fromHex("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("290decd9548b62a8d60345a988386fc84ba6bc95484008f6362f93160ef3e563" ==
    Utils::uint256_2str(accountState.get(0x00))
  );
}

TEST_CASE("sha3_4______f05a375db651dc62f2409f548bdd0db74a50cdc163feb25d1f65be155db69ea5", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6064640fffffffff20600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
}

TEST_CASE("sha3_5______58a094eff7761aa13888ad9b24ead0f78207f29b7b27ec19e07f9ab7ca3e6b57", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "640fffffffff61271020600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
}

TEST_CASE("sha3_bigSize______794cb1a0b26deee9fb2c7a1bec1e0c6b499a91b9b6e2024f31ef10ade8074b52", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff20600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x010000000000), /* gas */
    BigInt::fromHex("01"), /* gasPrice */
    BigInt::fromHex("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
}

TEST_CASE("sha3_2______296af237a14112e306707e5f8e6ef1c64c19f67c4bd35fbfabbfe5a94e3dd430", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600a600a20600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("6bd2dd6bd408cbee33429358bf24fdc64612fbf8b1b4db604518f40ffd34b607" ==
    Utils::uint256_2str(accountState.get(0x00))
  );
}

TEST_CASE("sha3_memSizeQuadraticCost32_zeroSize______2da0644da1e2765b44f104b09873de52632c04765c752ee2428e215cae0c821c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600061040020600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0100000000), /* gas */
    BigInt::fromHex("01"), /* gasPrice */
    BigInt::fromHex("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470" ==
    Utils::uint256_2str(accountState.get(0x00))
  );
}

TEST_CASE("sha3_3______de2716629e8c598d97f20e648cce8062238e5a4c5b02d88386f72fd0d61cd905", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "620fffff6103e820600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0186a0), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
}

TEST_CASE("sha3_bigOffset2______6d4d1bdba5c2a7921d8c4c6145cf926eb73e32012534729620645a6d7c86c20a", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6002630100000020600055";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x0100000000), /* gas */
    BigInt::fromHex("01"), /* gasPrice */
    BigInt::fromHex("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm(params);
  Call call(0);
  AccountState accountState(&ext);
  Memory mem {};

  // when
  vm.execute(mem, accountState, ext, call, env);

  // then
  CHECK("54a8c0ab653c15bfb48b47fd011ba2b9617af01cb45cab344acd57c924d56798" ==
    Utils::uint256_2str(accountState.get(0x00))
  );
}



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

TEST_CASE("dup3______b67364d451119d543fde8c6e2eaffd8108ca8cdb9fc44bb4d60b985e601ce6c3", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60036002600182600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push13______f87790ab58643f0f368549d883f39e63730eb67364362db04def43491dc0fcea", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6c33445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000033445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push6______20352e83bb4bd243245e03766739469d2a5d1dee980035e85a5b62dc0a3ff8dd", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "65aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("swap4______3cc1b87e1def29c23a3142f8fb160db3f8574b7e20ba1327b10ea54c15c94964", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600460036002600160039355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState.get(0x04))
  );
}

TEST_CASE("dup13______bf66efdee3944574d78fbbc235fab6b51ea5b5a2cf62d2dfca49fc3e761862e3", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600d600c600b600a6009600860076006600560046003600260018c600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("000000000000000000000000000000000000000000000000000000000000000d" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push29______4a85eb183184082fff2036f2ea2d5667a1df1232d507db83e137d608ec994091", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7c33445566778899aabbccddeeff00112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("00000033445566778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("swap2error______732f92c884d3a29d05e243f2b105b345ecd1813624591f5220e60e12d89b3ace", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7f10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff60039155";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("swap8______b0ef60e4ab69728a4c5daa24707b90e5e2e9b4f778a790e7915f68daf82174bb", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6008600760066005600460036002600160039755";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState.get(0x08))
  );
}

TEST_CASE("push33______077208da2bec8e9beec0a1217689d1d4d085b682688bfebd048fed80ed067c8b", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60656107d26204a0c763026921f4640bc5588eb165372d0f1dca6e661ba1d901961c71670c55f7bc23038e3868056bc75e2d630fffff69021e19e0c9bab24000016a085d1c6e8050f0ea1c71bd6b0688be36543f3c36e638e37a6c03d41f73d55d0d482ae55555376dc76810d0fe03c91964d31c71c6f46e615dd0360c07d931663b14e38e38b16f2da3f99955a3adcf27ebb1caaaaaaa6e7014ccba6a8bb1ed35bd86bf065c71c71c2b7109491c5d4781b79c9009de6bfb8e38e38de8720414a0f6fdec81304d4c563e740bffffffffa573118427b3b4a05bc8a8a4de8459868000000000017406eb15e7331e727940d4ac54b7cdca1c71c71c71bd750567a91c9fefc96ebaa626a22f98c5e638e38e38e37a76032abd16c5b68006e15d5aa307e383f4e55555555555377701a6427bdc4f0d58eab5f48a3ec67f64e21c71c71c71c6f478080dd0a0c9b9ff2c2a0c740b06853a0a980ee38e38e38e38b17903c679cb5e8f2f9cb3b5d6652b0e7334f746faaaaaaaaaaaaa6e7a01b873815917ebb2bf3b890a1af495d6235bae3c71c71c71c71c2b7b07ae4cca96e1a55dfa49c85ad3c3e60e426b92fb8e38e38e38e38de87c036018bf074e292bcc7d6c8bea0f9699443046178bffffffffffffffa57d0e7d34c64a9c85d4460dbbca87196b61618a4bd2168000000000000000017e05b901f48a5b994d6572502bc4ea43140486666416aa1c71c71c71c71c71bd7f047889870c178fc477414ea231d70467a388fffe31b4e638e38e38e38e38e37a";
  bytes_t data_bytes = bytes_t();

  params_t params = {
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6"), /* address */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* sender */
    BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"), /* origin */
    gas_t(0x20), /* gas */
    BigInt::fromHex("5af3107a4000"), /* gasPrice */
    BigInt::fromHex("0de0b6b3a7640000"), /* value */
    Hex::hexToBytes(bytecode_str), /* code */
    data_bytes /* data */
  };

  ExternalMock ext {};

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("push25______f6511eb983bed5be1f13a344fbfcbfca8779b10270e17f6db6f8dbccecf3406a", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "78778899aabbccddeeff00112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("00000000000000778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("swap10______d6eefdfd9775c34cc3853e86cda54e692d21b27ae5a411000e1d81754220aa13", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600a60096008600760066005600460036002600160039955";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState.get(0x0a))
  );
}

TEST_CASE("swap11______5815c1b934def10dcee373880ebbfa1a0f0d9b50bf73b74e90698f2bdf922201", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600b600a60096008600760066005600460036002600160039a55";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState.get(0x0b))
  );
}

TEST_CASE("push24______0b803a0bab1d0263a15c9b4327f91c8aa3db96de090e4057822d8fda4a89e8f7", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "778899aabbccddeeff00112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("00000000000000008899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push32______f977ad4f4ba30494360ef3c1109f0eec63195cb8a4dc02e335529c5a71985270", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7f10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("swap9______8bd1272a471faa1ba776b44899e39b51abd4dc778e1c7b14c352e265fedd6bbc", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60096008600760066005600460036002600160039855";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState.get(0x09))
  );
}

TEST_CASE("push28______a68c1cd274a700c3998e8a2824b87bf4bcea8559f2565c8bb633ff9a9f8f95e6", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7b445566778899aabbccddeeff00112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("00000000445566778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("swap5______15e65157fc078609a17c0a49a12fcd66952f3df931be63c90d12b822ee4ea956", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6005600460036002600160039455";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState.get(0x05))
  );
}

TEST_CASE("dup12______3decf581cdc53a2cc283c919081d7b5a9659bf3905c153fee26fc03857f8f656", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600c600b600a6009600860076006600560046003600260018b600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("000000000000000000000000000000000000000000000000000000000000000c" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push7______fd5302474303fb4a6a8360477916e2c1ee530993c2b336907109d021b95ae2e5", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6699aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000099aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push12______efd96f408cbfdff412ecaae356c6b1e48edf7df1a5f517cb6732d628fdf48b13", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6b445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("dup2______b40c551023460432955c0c11180e5c13cb0ea11616a5dd22d475a306e8acbd15", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6002600181600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("dup9______b4b1fc6f5cfcf793f11c9864a854b5cc79a2dbb2d87be72b517612615888c121", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60096008600760066005600460036002600188600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000009" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push19______802f7d9d36053e12703ed315251bbfee933b4bcaeb16721e4744fcbd63144fef", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "72ddeeff00112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("00000000000000000000000000ddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push23______3eae4e6c909ac53548a0006397d40484a8173e11ee9332df1e7ae5b3b0a18647", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7699aabbccddeeff00112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("00000000000000000099aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("swap16______b09afdcdd393eff8a1656a0b3124b1492f1375232a3243fa413166ed6ce7a3f5", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6010600f600e600d600c600b600a60096008600760066005600460036002600160039f55";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState.get(0x10))
  );
}

TEST_CASE("dup5______f2d4e02c337ab8b63b3360e946a77435e695207ddcf50cb856072cb793e989e7", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6005600460036002600184600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000005" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push32AndSuicide______6f3fd0fde9853507cadb8c8882461470b463d5928dcea37fdf6d42e76ca42e94", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fff10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("push15______24fb81e0b527a61bf6304ebfc005f2c2f7045e69a4eede3dcc1a203c51a97e13", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6e112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push32Undefined3______09630b43bc0f6895178f52bdade60c0b93398a7343780373a80a40b4bdb3d6bc", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7f";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("dup15______fc8f9f4a5c21f4779a4476e64e5ac9bfb7908d18a066476165a18f2fbc9fd48a", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600f600e600d600c600b600a6009600860076006600560046003600260018e600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("000000000000000000000000000000000000000000000000000000000000000f" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("swap2______b10f0cb24eda2b4df170b037adae875a80c12cca909b0d0372c252ef35340ed8", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6002600160039155";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState.get(0x02))
  );
}

TEST_CASE("push32Undefined2______77e275f6face7fb0aec71c687e63fce8a78c31e433f88e2e121c8b7851e2748c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7f0102030000000000000000000000000000000000000000000000000000000000600055";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0102030000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(accountState.get(0x00))
  );
}

TEST_CASE("dup14______84d89703aec77b537e1a9b8ca09682df0126677f5cafee64dd2e41faf87175ac", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600e600d600c600b600a6009600860076006600560046003600260018d600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("000000000000000000000000000000000000000000000000000000000000000e" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("swap3______396c1fc538ae74ceb295e25d29a5ece7d4bbd6807b48adc736d56c3db90651cd", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60036002600160039255";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("swapjump1______2e9446e737a45b6c198cfd1fdeea2f889705138ac54e7569093144c12953f164", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600560026001600c575050005b9060016116575050005b035b0360005260016003611ff3";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("push1______977bf38a869183f69e1e65e4b5f638ddc858637f53305fdddb972675e7f22e56", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60ff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push14______e89970db1842ac3d55f3232afd30ad13312c950177efca5c2e0ba3214e67870a", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6d2233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000002233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("dup4______3ae9f14681bc189949b3279cfcc0a8e06369fc9d90d5c10f6816471812b623d1", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600460036002600183600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000004" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push22______c7a093a13117bb9c6133f6327fee327e966a2140103d676578a1c084dc96875f", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "75aabbccddeeff00112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("00000000000000000000aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push18______46272027f0bfb84a1015bb9004a39d7826216d18d675d6379d65e3e79c1aa3df", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "71eeff00112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000eeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("dup8______6f166e5bef326158e7739b0a666015fb2d9715948805b1b99540809dcf48477f", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6008600760066005600460036002600187600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000008" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("swap14______4ccb75f67ac3e9b2d45eebcf12e463dae9d0c3144bdbe71ed36722095ecbd091", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600e600d600c600b600a60096008600760066005600460036002600160039d55";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState.get(0x0e))
  );
}

TEST_CASE("push21______2875bbf0680c0472ead156b68b4ef36c49c60cc2b38c0d369f64680528120341", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "74bbccddeeff00112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000bbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push2______03e50e47ef941b3d715799fd5ec14273d095cecc8d55c36444b40cd0667097bf", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "61eeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("000000000000000000000000000000000000000000000000000000000000eeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push17______e04d7497dcfb1a17c770c42fb9a4d84cef738de77252ec75bb3e945718464027", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "70ff00112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("000000000000000000000000000000ff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("dup7______9164c3d5aae743abd16b7041da296858da0d16759c2d3ae33ebcc5a63fc8ea04", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600760066005600460036002600186600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000007" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push32FillUpInputWithZerosAtTheEnd______97c6dc2159c394514d03134cd4d7ab007d5cbd66630603b5a88f095ab95f29ac", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7fff10112233445566778899aabbccddeeff00112233445566778899aabbccdd";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("dup6______75d72704baab3592b96f045596085afc546c7b6663598d7629249161dc0a7be4", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60066005600460036002600185600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000006" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push16______93b8df963d8064b20c21fd6d2ec38e8610b82b1c4e6abd66abdc85a85a842827", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6f10112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000010112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push3______07386593821578410dec2cc7fd7fa6b3ec0bf4dd1432dce10a66cf510523c741", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "62ddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000ddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("dup16______4a6afa1042040869ee0ca80f1a089430650b1fcb7fe06a182beec6573cd8621b", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6010600f600e600d600c600b600a6009600860076006600560046003600260018f600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000010" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("swap1______9947c63cb21668a1bc833b1421f2b27c94869a07528394c7b08586cac92bb8b1", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7f10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff60039055";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==
    Utils::uint256_2str(
      accountState.get(
        BigInt::fromHex("10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff")
      )
    )
  );
}

TEST_CASE("push32Undefined______c5eb519d971fc829741f24376f38ed1ec4e8b3bda89c1edde8ff7c77268f5956", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7f010203600055";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("push20______f0d95eafed710e98a32bea9f87771d93518f17b5c4b4276b85ba12d70d58dd7c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "73ccddeeff00112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("000000000000000000000000ccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("swap15______b76feedef6e378c9df2722f2e63fd8103db788729de5f3f941aaa5e6b2a59a9c", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600f600e600d600c600b600a60096008600760066005600460036002600160039e55";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState.get(0x0f))
  );
}

TEST_CASE("swap6______d5c33d7cb59842ed6f86031de4050c194534f125a2126e69c01ef662e71c7ecc", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60066005600460036002600160039555";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState.get(0x06))
  );
}

TEST_CASE("dup11______d54b150f74faf24dbb3288c5c2343a5640d47d09ad2cad7c1e05d32a00139438", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600b600a6009600860076006600560046003600260018a600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push4______830bd0d331f6bfc2fd8e1977ba30d1e7b359397714d414207f0a62a1ca2370d3", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "63ccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("00000000000000000000000000000000000000000000000000000000ccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push11______70ae0190ed5fb932a7ad6626fabd9fabc1d0afdd7a32d63adce68d86092c63d0", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6a5566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000005566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("dup2error______de71b4a383746d454f73d98244eec6c4ccc89fbb3c77ad3a8e1f4bee2b104c17", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7f10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff81600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}

TEST_CASE("dup1______e7b9288ecb9f8e8021e319ae0e7116acf5934f12b95a9f4e923fe356b71e8cde", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7f10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff80600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("swap12______3f50ed713331e02d6566d694aded7f56f52a4e0e158a35e66ec89669f9ec7665", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600c600b600a60096008600760066005600460036002600160039b55";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState.get(0x0c))
  );
}

TEST_CASE("push27______f869a2e724e3dc60a9de54f9eda2c4b4f50823ae979e645bf44905df36b89876", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7a5566778899aabbccddeeff00112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("00000000005566778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push31______f93339c6cf8aae8b47c31ca25032cc05154361b77a4f844fac3ea2854ef55e0f", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7e112233445566778899aabbccddeeff00112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("00112233445566778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push8______bd93b9780c53aca4d7ec72f9636a485ee7056a23dbc0f13fa44eb38a03e728a9", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "678899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000008899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push9______719e7221544d5478ac49ed63e0c80c06b5b4177c3b777a7612b65b8516cc5ba5", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "68778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push30______236223536f879e3412159fcc6e2de0376009d47a03b763cee0cd93ea43835eee", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7d2233445566778899aabbccddeeff00112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("00002233445566778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push26______4553b78606f97fcbaf3c1a88cee84db0095cf08d254ed679f3af3d79b2f55b22", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "7966778899aabbccddeeff00112233445566778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("00000000000066778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("swap13______61e6f3f3f7163e13eb94244e435798bb04efb7f219ddabaa29b20f6561867764", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600d600c600b600a60096008600760066005600460036002600160039c55";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState.get(0x0d))
  );
}

TEST_CASE("push10______0eab62f5133e7161bd1e2c8cf609b007060a17f0d985c5911e85a39107573385", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "6966778899aabbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000066778899aabbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push5______8ab94cf0099a8c2ebe5cc7a7c235e4cf167b35e8a54dcc35a7b4e328877a1502", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "64bbccddeeff600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("000000000000000000000000000000000000000000000000000000bbccddeeff" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("swap7______cb70e89a4bb85d521668d0b0b2f50e2e94271bfd78d457b38215c31980c34cef", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600760066005600460036002600160039655";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(accountState.get(0x07))
  );
}

TEST_CASE("dup10______63492541583da57d2792ec1c9af921370d1b4a5e583c88df55ee5c8f7b54e07d", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "600a60096008600760066005600460036002600189600355";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==
    Utils::uint256_2str(accountState.get(0x03))
  );
}

TEST_CASE("push1_missingStack______28a9f042879f16ed880928a48c2a64ae9a5b3730def5ec03fe73944d1ec6c5ee", "[vm]") {
  env_t env = {
    uint256_t(1), /* chainId */
    BigInt::fromHex("00"), /* blockNumber */
    BigInt::fromHex("01"), /* timestamp */
    BigInt::fromHex("0f4240"), /* gasLimit */
    BigInt::fromHex("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba"), /* coinbase */
    BigInt::fromHex("0100"), /* difficulty */
    BigInt::fromHex("") /* blockHash */
  };

  std::string bytecode_str = "60";
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

  VM vm {};
  Call call(0);
  AccountState accountState(&ext);
  Gasometer gasometer(params.gas);
  Memory mem {};
  StackMachine sm {};

  // when
  vm.execute(mem, sm, accountState, gasometer, params, ext, call, env);

  // then
}



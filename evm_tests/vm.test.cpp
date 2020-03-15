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
#include "external_mock.h"

TEST_CASE("calldataload_BigOffset______e118bc308ccdd052ea601f5cfa51d32fc907952cb1cd16e673bff87f8c9fe203", "[vm]") {
  std::string bytecode_str = "7f420000000000000000000000000000000000000000000000000000000000000035600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("calldatacopy2______3acb5771658d79d6ff4e17b69cfeea9bcc5e51ab11afb0c511b4d7be801e71d4", "[vm]") {
  std::string bytecode_str = "60006001600037600051600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("address0______37a0fc3337fde7233f427195a290be689e01aa752a8394b0ae56306fd97d3624", "[vm]") {
  std::string bytecode_str = "30600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("calldatacopy2_return______4268c07197871b5b5c14bcda3f746a2bb787c8dba2d987bf3c1fb0bc1fc4db4c", "[vm]") {
  std::string bytecode_str = "60006001600037600051600055596000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("calldataload2______0274681bf0559ab144aa2273cd566d1b32bcc58843ca142e8c6e6fd567196882", "[vm]") {
  std::string bytecode_str = "600535600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("bcdef00000000000000000000000000000000000000000000000000024000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("origin______4d51cb9ee576e04b08a74a6a4ba3f10284ee1f735dd068abd7a0e551324f45be", "[vm]") {
  std::string bytecode_str = "32600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("cd1722f3947def4cf144679da39c4c32bdc35681" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("calldatacopy_DataIndexTooHigh______72c5c7337895354e6d12b41ef4f144db87f945068a1a20134168f7e63f61a0d7", "[vm]") {
  std::string bytecode_str = "60ff7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600037600051600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("address1______2f317db88316ea284d36c3031d82818be81d6cf63d1bba9437dd22705282fe27", "[vm]") {
  std::string bytecode_str = "30600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("cd1722f3947def4cf144679da39c4c32bdc35681" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("calldatacopyUnderFlow______55ea90b15f19bf8f4838c35234d202eab4473284e5895af23b885368f34200a1", "[vm]") {
  std::string bytecode_str = "6001600237";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("calldatacopy_DataIndexTooHigh_return______640a52c64dfe9f43c6c5bb1aa4fc2a95839f352533e95fabe5493ff142b210c7", "[vm]") {
  std::string bytecode_str = "60ff7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600037600051600055596000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("caller______79214a9fde65ef8c878dbf8e03a06a75483536d289ad19e56b95fdef57b1da3d", "[vm]") {
  std::string bytecode_str = "33600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("cd1722f3947def4cf144679da39c4c32bdc35681" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("gasprice______b94e3c994e54e24b85ef80fc16f53827cd26ef01fa4a96908a20e646f57d1e48", "[vm]") {
  std::string bytecode_str = "3a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("075bcd15" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("codecopy0______9354634ed14a9667c8c883c3a4eceaae263bcd3d4fe47683aa0f38f45fe877e9", "[vm]") {
  std::string bytecode_str = "60056000600039600051600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("6005600060000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("calldatacopyZeroMemExpansion_return______b00f6239c55457bfec8870ad2ffaa42b2b53228c4f610eba391b8ce561dc9d4f", "[vm]") {
  std::string bytecode_str = "60006000600037600051600055596000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("calldatacopy1_return______671deccb615f7d6e58bc195d11ad4fde489a6a07581f9e32e029e6cf42dba991", "[vm]") {
  std::string bytecode_str = "60016001600037600051600055596000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("3400000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("calldatasize2______cbd842b7c2ff77d176d3d7b5f200e908c22e47ee9a7d0f5294be85c917119f1e", "[vm]") {
  std::string bytecode_str = "36600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("21" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("codecopyZeroMemExpansion______41a8841a95018c2d228db91d29d0b75992f9a166e4207362e79d17229974ddfd", "[vm]") {
  std::string bytecode_str = "60006000600039600051600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("calldatacopy_sec______9c7568cda862ed10722f83b99c948af03cb38ae4042d45fa55aae12cca979f88", "[vm]") {
  std::string bytecode_str = "6005565b005b6042601f536101036000601f3760005180606014600357640badc0ffee60ff55";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("0badc0ffee" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("calldatasize1______7db2dda9d80c7eac5ae82d3e2573e7f9b47ad6cb0c5545824e2500e85ec1cc3c", "[vm]") {
  std::string bytecode_str = "36600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("21" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("calldatacopyZeroMemExpansion______99d8509de4a25c88abd0647c68310552c67f395a92f4e6a8e67cc3707af076c5", "[vm]") {
  std::string bytecode_str = "60006000600037600051600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("codecopy_DataIndexTooHigh______f6fac567f89aaca85c34c5a88b98870d1f7e2509b26ec566232c5d107741c6f4", "[vm]") {
  std::string bytecode_str = "60087ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600039600051600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("codesize______632259bbd9962abfa58ec3b9e7b80a8f3babcdb47592bbc511fa5e4c0bc3ce3f", "[vm]") {
  std::string bytecode_str = "38600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("04" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("calldataloadSizeTooHighPartial______8090196f324f686f77a7d362987f8697cfc7b6b3bd86d702a212d790ec12ef0f", "[vm]") {
  std::string bytecode_str = "600a35600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("240000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("calldatacopy_DataIndexTooHigh2______bf92d18c0d12f1e9d48a5cf116ece7559ad36d67383a8b25792b4b6003180304", "[vm]") {
  std::string bytecode_str = "60097ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600037600051600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("calldatasize0______e638e627686d20765a98fa8cfab03c642bdf33216a5869e742994072c8fd051e", "[vm]") {
  std::string bytecode_str = "36600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("calldataloadSizeTooHigh______0a556d7e2b38d3ac82c12938237c81673868011512d36133443339bc000d56c5", "[vm]") {
  std::string bytecode_str = "7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa35600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("calldatacopy0______761871556943693860bdddd26da931c7c3f5a6c8ab95f680aa9d5854135dacd0", "[vm]") {
  std::string bytecode_str = "60026001600037600051600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("3456000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("calldatacopy0_return______4f9c0f3aff470ea35ad2fd5a81a593742f875409dbc51200199dd0f2baab261d", "[vm]") {
  std::string bytecode_str = "60026001600037600051600055596000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("3456000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("calldataload0______3bfae7447ad076b4da51568b72acb70e9bd946fbf68a79705015c4600d9d99de", "[vm]") {
  std::string bytecode_str = "600035600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("2560000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("calldatacopy_DataIndexTooHigh2_return______990882750573f3f5938a3f2cd66b0f41c842538f70d70045e179d246b8a076e0", "[vm]") {
  std::string bytecode_str = "60097ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa600037600051600055596000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("calldataload1______3cda66b7abff563a2178c736c6ff9235784bbc4083083c1880268c1f32281606", "[vm]") {
  std::string bytecode_str = "600135600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff23" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("callvalue______4eabc176dc48df11702d9ddf6e8501c62035436adb16aa7cd79769ab273d583a", "[vm]") {
  std::string bytecode_str = "34600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("0de0b6b3a7640000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("calldatacopy1______65659a844a3d4458eb82347f1ef56c3657abdb06f7166b033329db7c2c8cdb78", "[vm]") {
  std::string bytecode_str = "60016001600037600051600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("3400000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("mulmoddivByZero______d2f1f45a525dd3c94e60ba59a808bfa6f526ff1517294eacdf4d09d9d33415d5", "[vm]") {
  std::string bytecode_str = "60006001600509600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("sub0______6e271b6ee17cb23f68d252f5c2bddad3c667f05dc922fd4839721727eb10ee0f", "[vm]") {
  std::string bytecode_str = "6001601703600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("16" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_29______d1d28e8369ccb0a73475421072fcba58bc0491a0a30c1541d47076a0284609a2", "[vm]") {
  std::string bytecode_str = "601d6101000a600055601d60ff0a600155601d6101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("011ea4a49e3a9ee435d23f98a8826a875a9ae54cb3090d5c3fd547961d01" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("e48814fe44fc1a8f78642d946d7c879b39a055b6988e438647446a1cff" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("010000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("signextend_BigByteBigByte______5cd096028c09eba94315bd6d591ae9cb76413b56bac1aeada8d337d47c59be10", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0b600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256Of256_22______c0e0c1457caeab0bedb354de662de3741cd90362ec3fe970cbd5565c8e164a1f", "[vm]") {
  std::string bytecode_str = "60166101000a6101000a600055601660ff0a6101000a60015560166101010a6101000a60025560166101000a60ff0a600355601660ff0a60ff0a60045560166101010a60ff0a60055560166101000a6101010a600655601660ff0a6101010a60075560166101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("4d65773387993928c95c861274232d3fb6f6b7fe1b22e4e61a30e71172160101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("dcf0a770777610503596ae0311af46c171151ed45107d7e7bb8f74bb5bea0101" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("b68fb921f7aa6aff810000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("dc9178d3bab470096f01477c859b5f4173986640b659426412a653465c1600ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("ec447e662ac08957d7e290a421dbf54c0aaf43aadc9cc465ad0b02f071ea00ff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("9ec55c33085514ff7f0000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("expPowerOf256Of256_8______eabf261994e71ba3fab018f76089ada2039bf58f8547a549aca6f9605bb7e452", "[vm]") {
  std::string bytecode_str = "60086101000a6101000a600055600860ff0a6101000a60015560086101010a6101000a60025560086101000a60ff0a600355600860ff0a60ff0a60045560086101010a60ff0a60055560086101000a6101010a600655600860ff0a6101010a60075560086101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("629c25790e1488998877a9ecdf0fb69637e77d8a4bdc1b46270093ba20080101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("0bdce80b8378e43f13d454b9d0a4c83cf311b8eaa45d5122cfd544a217f80101" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("70add926e753655d6d0ebe9c0f81368fb921f7aa6aff81000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("67a397e0692385e4cd83853aabce220a94d449e885fa867e96d3ef5e180800ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("c407d8a413ef9079ead457ed686a05ac81039c0cae0a7f6afd01e8461ff800ff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("230041a0e7602d6e459609ed39081ec55c33085514ff7f000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("mul4______98024d8b456973580b82d5dfcc6e3d389628d673e12d43ff8653a44b435fbee6", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7f800000000000000000000000000000000000000000000000000000000000000002600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("8000000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_13______9a5723090752b32355ffaefd5d4b998f17196c358567128240bb0f8e83a1d375", "[vm]") {
  std::string bytecode_str = "600d6101000a600055600d60ff0a600155600d6101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("010d4f20d00dbab909cc1e4e0d01" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("f34ce4c5ffad5104361db20cff" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("0100000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("mulmod3______a4466904098f2aa254af6f260446e643504d5993d6226da4cf88c82942018de1", "[vm]") {
  std::string bytecode_str = "60036000036001600509600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("05" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("exp6______05a538a5941013f6dc6dfb36f122b6d6840d86e5cb69af7da789e71d14c54937", "[vm]") {
  std::string bytecode_str = "61010160010a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("addmodDivByZero1______858b669ae5775b5aeae36c69828eb74ecfa9498698f01ae8d1ba73328b466d96", "[vm]") {
  std::string bytecode_str = "60006001600008600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("expPowerOf256Of256_18______9aae91d4c3217ab1ae7ac11ca2cdce036b3be2c2bc426f515bbc1b1e4a9a48eb", "[vm]") {
  std::string bytecode_str = "60126101000a6101000a600055601260ff0a6101000a60015560126101010a6101000a60025560126101000a60ff0a600355601260ff0a60ff0a60045560126101010a60ff0a60055560126101000a6101010a600655601260ff0a6101010a60075560126101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("f540cb714754b5b1eb0373833833bd7fb0ee925ce8b92962500b7a1c22120101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("410be68e49452a1fbcd863bf6e8d637f8eae4979c34c88d552afbcc20fee0101" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("c9b0f000b68fb921f7aa6aff8100000000000000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("c1b5a1e3a81da51b10d84e880f0113ff67b863ddad3faf1f4ecf413f101200ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("8a2cbd9f40794e2205b13306f2aa0a43c60823c64b95d8601fa4f1e521ee00ff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("698218879ec55c33085514ff7f00000000000000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("smod5______7b7e7c70fbcb291a99ff4ae3f8d46a67b94183a8cf3c5a93aff9262c81bd3aa7", "[vm]") {
  std::string bytecode_str = "7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000307600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("expPowerOf256_25______fce87c81a0e08fa580701f25ecc21b487f85741090abd8a7614cabf6b90e42ae", "[vm]") {
  std::string bytecode_str = "60196101000a600055601960ff0a60015560196101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("011a352e3c45325c4583eb6149e1b7d4e73f709bbb72fd2c1901" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("e823349d2286a5ec3de3529625f683e56c0903589efad418ff" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("0100000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("mulmoddivByZero3______7f1443cbcb5f817b38aed7b0dd96af4d58e8025b71a380e14af792c24fc2d8fa", "[vm]") {
  std::string bytecode_str = "60006000600009600103600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_33______dcdd8d12914af51d9ebd69cf0085106850fcc496b40c13bdc30d5a5440b561ce", "[vm]") {
  std::string bytecode_str = "60216101000a600055602160ff0a60015560216101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);

  // then
  CHECK("25f3884075dd08b8fb400789097aa95df8750bd17be0d83c9a0fb7ed52102101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("fb4c498e11e3f82e714be514ef024675bb48d678bd192222cd2e783d4df020ff" ==
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("expPowerOf256Of256_4______5758fdc80aadf2b69e7e75acfa05239e6c5d9d5ad1374b1cac0d19477a861b72", "[vm]") {
  std::string bytecode_str = "60046101000a6101000a600055600460ff0a6101000a60015560046101010a6101000a60025560046101000a60ff0a600355600460ff0a60ff0a60045560046101010a60ff0a60055560046101000a6101010a600655600460ff0a6101010a60075560046101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("e16ea721c96539edb4f7fb82de0dad8cccb1e7a6966a6777635f6fb908040101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("2dffa3e901e5a392d15b79f4193d2168147d2aa7c55870b46c3a905d03fc0101" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("e7498a48c6ce2530bbe814ee3440c8c44fffab7ad8a277aa6aff810000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("e959516cd27e5d8fd487b72db2989b3ec2ba9fb7ead41554526fe5a3040400ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("6526b38b05a6325b80e1c84ab41dc934fd70f33f1bd0eab3d1f61a4707fc00ff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("e6540ce46eaf70da9d644015a661e0e245b13f307cb3885514ff7f0000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("sdiv7______2b55fc5f5e58371ec9404c0b8c5e009c45c2c2efdbb5f8856cec1e847f588dba", "[vm]") {
  std::string bytecode_str = "6019600160000305600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("divByNonZero1______fcd51ef794022b0a97b5d1c20e12e1a725cdd126f9a42fc135a79bc15e95e447", "[vm]") {
  std::string bytecode_str = "6018601704600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("addmod1_overflow2______bef2a19f1d2f3d74ad56dcff0d4f94046bf73b3b27472e2d92b415dceebe9ca0", "[vm]") {
  std::string bytecode_str = "60056000600160000308600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("expPowerOf256Of256_14______58cc5ba032541e61180d5bb54913a3b14ba2db81e6e455d45fd0504bb1a69da4", "[vm]") {
  std::string bytecode_str = "600e6101000a6101000a600055600e60ff0a6101000a600155600e6101010a6101000a600255600e6101000a60ff0a600355600e60ff0a60ff0a600455600e6101010a60ff0a600555600e6101000a6101010a600655600e60ff0a6101010a600755600e6101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("cd4cd0124e983af71620fb5f98275965c6a8bebc4b8adc288b63224ee20e0101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("8133b760dfae27560eb490f235ddfa301f058dee4f01f3fe4b3567d0d3f20101" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("e0bfa28fc9b0f000b68fb921f7aa6aff81000000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("3f791dd183ed5b963bd86e0dba1a9dd5b8ceeb078f15c73062f1942fd40e00ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("83fab06c6c8fef761ebbb9534c06ac2a9d61820623008069062ff3b1e1f200ff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("db9902ec698218879ec55c33085514ff7f000000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("expPowerOf256Of256_15______ce849f731f8f9cfdb8c922cac2e16d847e6af0bea8958367c172b277020c7819", "[vm]") {
  std::string bytecode_str = "600f6101000a6101000a600055600f60ff0a6101000a600155600f6101010a6101000a600255600f6101000a60ff0a600355600f60ff0a60ff0a600455600f6101010a60ff0a600555600f6101000a6101010a600655600f60ff0a6101010a600755600f6101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("e6b3e5cf6ec90e532fef7d08455ebf92a03e9e3f6e224ea0febdf1a9f08f0101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("c6a29131e7594004bc2aa79f0d2c402a1409c57c77d284c14b1a3ab0ff8fff01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("bf228fc9b0f000b68fb921f7aa6aff8100000000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("5c76839bf5a80b1da705dbdf43e4dd6770cd7501af11ff2dab7918dfe18f00ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("75c4915e18b96704209738f5ca765568bb4dc4113d56683977825a132c8dfeff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("9882ec698218879ec55c33085514ff7f00000000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("divByNonZero0______70dda40426c888f3c2b4505f99842373bae332be0976cb37dd6b4f8f950e7314", "[vm]") {
  std::string bytecode_str = "6002600504600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("addmod1_overflow3______37950a5f52df8d7eb5241267f3b45a759284d77a88e876990c6ee5b1c0f48857", "[vm]") {
  std::string bytecode_str = "60056001600160000308600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sdiv6______e7b278490909bf62877a08100ade05781f50a8e1057283f7b8c734a0aec01dee", "[vm]") {
  std::string bytecode_str = "60007f800000000000000000000000000000000000000000000000000000000000000060000305600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("expPowerOf256Of256_5______b03dff0692fa130237d4d29c2879391227fd71f95a3efec5d191667dc7a5ac8a", "[vm]") {
  std::string bytecode_str = "60056101000a6101000a600055600560ff0a6101000a60015560056101010a6101000a60025560056101000a60ff0a600355600560ff0a60ff0a60045560056101010a60ff0a60055560056101000a6101010a600655600560ff0a6101010a60075560056101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("b622672a213faa79b32185ff93a7b27a8499e48f7b032cdb4d1a70300c850101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("70ab32233202b98d382d17713fa0be391eaf74f85ba1740c9c3238c4ed85ff01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("cec5ec213b9cb5811f6ae00428fd7b6ef5a1af39a1f7aa6aff81000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("fc403fa42ceb6a0d0d3321bd9b2d8af25b1b667f87a04f496c78168d078500ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("75789eb2a64bc971389fbd11a1e6d7abbf95ad25e23fb9aa25e73a0bfc83feff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("b581ac185aad71db2d177c286929c4c22809e5dcb3085514ff7f000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("expPowerOf256_32______9a7aca6dc6ad1b3e6bbf7596f5d5f35e917f8e4be05eb7d962bf9e2852345fa5", "[vm]") {
  std::string bytecode_str = "60206101000a600055602060ff0a60015560206101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);

  // then
  CHECK("2203ef98a7ce0ef9bf3c04038583f6b2ab4d27e3ed8e5285b6e32c8b61f02001" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("e1dd29730112f6ef1d8edabfd4c3c60c823d865cd592abcdf0bdec64a1efe001" ==
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("divBoostBug______d2e783985274bb48def6615bebddaf86d9ebdcf49e03f93a9854166ce999b166", "[vm]") {
  std::string bytecode_str = "7f01dae6076b981dae6076b981dae6076b981dae6076b981dae6076b981dae60777fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffba04600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("89" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("mulmoddivByZero2______dade878a93b655f3a61789e38fb21ece3dd658e3e58d13a23bd5dcf5af668ef6", "[vm]") {
  std::string bytecode_str = "60006000600109600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("addmod1_overflowDiff______fd000aecad4faf960141a35e708c6686bf6d29b917347ec0f793b8a62393ed8b", "[vm]") {
  std::string bytecode_str = "60056002600003600160000308600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("04" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_24______e4c8a16c072ceeebfd96c18dbd58a9088c910a9d2b9e35f9114ff0ecfb526d10", "[vm]") {
  std::string bytecode_str = "60186101000a600055601860ff0a60015560186101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("01191c122a1b1745008367f9509126ae39066a3189e9141801" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("e90c40de00872d19573a8d23493fc3a9151e217a1913e801" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("01000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("smod4______131b0f2f206b381215517d412fb1ea7564a8152d2f4d4cd6ab3bff2cee6b2198", "[vm]") {
  std::string bytecode_str = "6000600260000307600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("expPowerOf256Of256_19______82899697a114c2742a99d07558e3ff58075aed7ac8d0b4624e336727ed10644b", "[vm]") {
  std::string bytecode_str = "60136101000a6101000a600055601360ff0a6101000a60015560136101010a6101000a60025560136101000a60ff0a600355601360ff0a60ff0a60045560136101010a60ff0a60055560136101000a6101010a600655601360ff0a6101010a60075560136101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("d8b5b531989e689f700dcdb43ab90e79a49dfbbb5a13dbf751df98bb34930101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("ad571756ecbff1bfdef064861e5e92c5d897a9cc380e54bdbaabd80bb793ff01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("b0f000b68fb921f7aa6aff810000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("1f0bb7be91a0ccd0cca93d75cf03de3e6b56fe8f1c54242617665327219300ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("b795ad7ac24cfbb7435cf53bd3584f3d4b2709935635c3ceb66e761ff091feff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("8218879ec55c33085514ff7f0000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("mulmod2______79bc8735a59de453773cbcd0053df3cd759b8d55ece41192570ed00471f038ac", "[vm]") {
  std::string bytecode_str = "60036001600560000309600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("exp7______618bedd207234fc5c4da314056bc9550ecb1c3ace2bd12dd6ee9a305a58b1853", "[vm]") {
  std::string bytecode_str = "61010160020a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("mul5______df427409c23049ff69ae32648441bacf7f46bfa8380019c6d1effaefa428d3e1", "[vm]") {
  std::string bytecode_str = "7f80000000000000000000000000000000000000000000000000000000000000007f800000000000000000000000000000000000000000000000000000000000000002600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("expPowerOf256_12______2e2fede61e970560166c4fa485d48bc644ee46ba312aae472afd3c861f73799c", "[vm]") {
  std::string bytecode_str = "600c6101000a600055600c60ff0a600155600c6101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("010c42ddf21b9f19efdc420c01" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("f44125ebeb98e9ee2441f401" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("01000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("expPowerOf256Of256_9______f93cdd3e162869675b64e4a5e5bb04307b799762656cb3e2db858aeeb6195767", "[vm]") {
  std::string bytecode_str = "60096101000a6101000a600055600960ff0a6101000a60015560096101010a6101000a60025560096101000a60ff0a600355600960ff0a60ff0a60045560096101010a60ff0a60055560096101000a6101010a600655600960ff0a6101010a60075560096101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("525696c22bb3ce00fd2e3f6bbb9b4ea1046a5e31fcff2fedf8f8c74d28890101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("f387ed41c1050f9da667f429a3e8fb30b61a55ede97d7b8acd797a03cd89ff01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("013ab9e1f0df89a184b4d07080b68fb921f7aa6aff8100000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("2e350d847ba73dc2099f83f532951c47269d9fd7e411b50bae00a9581f8900ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("48be09b6c6ae2aa660f1972125cecbb1038b5d236ecf766ba786e2c4e887feff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("53017d8eb210db2c8cd4a299079ec55c33085514ff7f00000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("signextend_BigByte_0______ed96ff1a29a7869a15e633346c24da243ef11761dbfac1fe6b6e54629e3d265a", "[vm]") {
  std::string bytecode_str = "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0b600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("expPowerOf256Of256_23______6ff02117a4131900b84bb38b99a97e590f197792f742bd27678797d0976c2c3d", "[vm]") {
  std::string bytecode_str = "60176101000a6101000a600055601760ff0a6101000a60015560176101010a6101000a60025560176101000a60ff0a600355601760ff0a60ff0a60045560176101010a60ff0a60055560176101000a6101010a600655601760ff0a6101010a60075560176101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("55ddd0ec77909de6d8311116cf520398e816f928b06fdd90ec239d0488970101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("56a55341ab8d4318f1cfb55d5f21e2ba35d7e070a72bac6b2b21baae5f97ff01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("8fb921f7aa6aff81000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("86418797ec60058de6cca47dfdbee79923ac49d7801e01840041ca76719700ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("537ca0f03f974303005f1e6693b55b72315a166841732e42b8353724a495feff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("c55c33085514ff7f000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("expPowerOf256_1______308cd7ec273573ca2f8a96a8300b5469c13bdf78fa4c4f643d154e501333fc3f", "[vm]") {
  std::string bytecode_str = "60016101000a600055600160ff0a60015560016101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("0101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("ff" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("0100" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("mulmod1_overflow______8746002a182b1690ee3c6f9285ae2f6293abc8531dce20c6a81c632dea5b06c2", "[vm]") {
  std::string bytecode_str = "60056002600160000309600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("sub1______9c03702b06e54741e8c89a52f479d93892f0186c3d8cd469dd8c1ef4987c0d55", "[vm]") {
  std::string bytecode_str = "6003600203600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_28______02bf29a25df27bb8f98935cb17cdd2e1b37c3963178dfd245c681919697c6750", "[vm]") {
  std::string bytecode_str = "601c6101000a600055601c60ff0a600155601c6101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("011d871d80b9e4ff369ba3f4b3ce9beb6f2bb9931fe9243807cd7a1c01" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("e56d8280c5c1dc6be448760a77f47c1750f146fd962467ee3579e401" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("0100000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("expPowerOf256_23______abfb8b178f10c9de69b1ee116db59a0f9a127e78c370610d4593c8aab78771a6", "[vm]") {
  std::string bytecode_str = "60176101000a600055601760ff0a60015560176101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("0118040e1bff182cd3afb8410f81a5092fd6939debfd1701" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("e9f63715159cc9e33a7502256eae721b304e6fea0316ff" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("010000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("addmod0______1315e3365bbf4b0d1ea7d5f885974318055ca1dc25f54a106df8f76f3dfd34d5", "[vm]") {
  std::string bytecode_str = "60026002600108600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("add0______2d47e8f287f580e1e0ec6b926375f8fee1142475cbf3bdcdf9305e618b66cb40", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256Of256_28______f0bed14e403ae3cbb67dfbf7e93be879d04590226ad07c947e5d76e1ef45a4e4", "[vm]") {
  std::string bytecode_str = "601c6101000a6101000a600055601c60ff0a6101000a600155601c6101010a6101000a600255601c6101000a60ff0a600355601c60ff0a60ff0a600455601c6101010a60ff0a600555601c6101000a6101010a600655601c60ff0a6101010a600755601c6101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("243fffe3a4f2982f45055c08f379648ab886da8027a7401117a8e0b8881c0101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("19df06ffa28250867006726405fbc05d43dc2f9d2f025006db089bd46be40101" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("6aff810000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("0981ad53c19b15a94bcf0bf20235dd0da9df25f46ae635029fe2062e6c1c00ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("ffd368e44b3f85cb81ae394c9809ca9fa2db46a83d7880a912ab6d4a87e400ff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("14ff7f0000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("mulmod2_1______ad3c90c6e0cbacf8ba3baab6c0f8540ec0ff24038b0768dadabf67efac5e07ed", "[vm]") {
  std::string bytecode_str = "60036001600560000309600360056000030614600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("smod8_byZero______d21aca0c1e7c0240084f3604e37698a1495ee8777b0dcb2d3a61b714d7288683", "[vm]") {
  std::string bytecode_str = "600d600060c86000030703600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff3" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256Of256_2______249a51e755ea2cd7bdbc704a8b3825fc01d8145221332c23e605cda095415004", "[vm]") {
  std::string bytecode_str = "60026101000a6101000a600055600260ff0a6101000a60015560026101010a6101000a60025560026101000a60ff0a600355600260ff0a60ff0a60045560026101010a60ff0a60055560026101000a6101010a600655600260ff0a6101010a60075560026101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("72d0a7939b6303ce1d46e6e3f1b8be303bfdb2b00f41ad8076b0975782020101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("eb30a3c678a01bde914548f98f3366dc0ffe9f85384ebf1111d03dad7ffe0101" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("666ac362902470ed850709e2a29969d10cba09debc03c38d172aeaff81000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("81c9fcefa5de158ae2007f25d35c0d11cd735342a48905955a5a6852800200ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("82f46a1b4e34d66712910615d2571d75606ceac51fa8ca8c58cf6ca881fe00ff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("4ee4ceeaac565c81f55a87c43f82f7c889ef4fc7c679671e28d594ff7f000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("expPowerOf256_19______91e9804a3d43e6f2e973625ca587f4e8583bec88aa3c53c333a24bfd50e911f7", "[vm]") {
  std::string bytecode_str = "60136101000a600055601360ff0a60015560136101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("0113aed851d6c1fca84402033e297b27c9ab1301" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("eda745f6fd3851d68db3866a315cdfc85512ff" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("0100000000000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("signextend_bigBytePlus1______e1d4c88c2ad5fbe82fefe183562d1533a0408cce7501f79d294a2207637afd23", "[vm]") {
  std::string bytecode_str = "66f000000000000161ffff0b600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("f0000000000001" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sdivByZero2______0395bca3ef9221cdfca63d08eceb32873be670cae868547e38aa1a42c29e41d9", "[vm]") {
  std::string bytecode_str = "600160007ffffffffffffffffffffffffffffffffffffffffffffffffffffffffcf923bdff6000030501600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sdiv1______65482c2a8e74781262c4db10d43d8c7731628b313a56e48a8dfdc9af9a1e4164", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6000037fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff05600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("addmod1_overflow4______d256203dabe38a3e460b068f5f85039a7f3db2f87cdd47c4eba6631f1eebe846", "[vm]") {
  std::string bytecode_str = "60056002600160000308600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256Of256_12______8e662f9b2bcc90eacdf00d0f18353ff17d7bada18f5ea2260030951429e0ff62", "[vm]") {
  std::string bytecode_str = "600c6101000a6101000a600055600c60ff0a6101000a600155600c6101010a6101000a600255600c6101000a60ff0a600355600c60ff0a60ff0a600455600c6101010a60ff0a600555600c6101000a6101010a600655600c60ff0a6101010a600755600c6101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("3f49a1e40c5213aa4ffed57eb4c1ad2d181b2aaa289e9d59c2256c43480c0101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("3bde6ca66dffe1bf5d727c3edea74c7a4af43b3912e6256d37705c8f3bf40101" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("a5cbb62a421049b0f000b68fb921f7aa6aff8100000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("cf45c7f9af4bbe4a83055b55b97777ad5e0a3f08b129c9ae208c5d713c0c00ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("c482ab56ec19186dc48c88f30861a850b2253b1ea6dc021589e569bd47f400ff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("b0e95b83a36ce98218879ec55c33085514ff7f00000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("expPowerOf256Of256_32______6391696ba6998cd4f6154479524ffa7c1fd2970c481100e6885eacbba5700f64", "[vm]") {
  std::string bytecode_str = "60206101000a6101000a600055602060ff0a6101000a60015560206101010a6101000a60025560206101000a60ff0a600355602060ff0a60ff0a60045560206101010a60ff0a60055560206101000a6101010a600655602060ff0a6101010a60075560206101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);
  store_item_t item6 = Utils::accountStoreValue(6, accountItems);

  // then
  CHECK("512ecfaeeb11205f0833e1054dcb1300488e0954be5af77a49e143aa00200101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("eda7d024b6de40a9d3b966e71f10a4667edc5b71cab07aeabcac6249dfe00101" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("01" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("ee526e5a06f2a990b2bf6c951e5feabf0e07ee16877296e1be872db9e02000ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("b8247842bb5ce75c08d0c251669ed5870fa24a22952e5db3a7c66c59ffe000ff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("01" ==
    Utils::uint256_2str(item5.second)
  );
  CHECK("01" ==
    Utils::uint256_2str(item6.second)
  );
}

TEST_CASE("expPowerOf256_6______2513b1044fefd548846b5188b80ed9633303bbbf23522518925608b2916bbc6c", "[vm]") {
  std::string bytecode_str = "60066101000a600055600660ff0a60015560066101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("01060f140f0601" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("fa0eec0efa01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("01000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("expPowerOf256Of256_24______cbbb2605b3283fff77ffccb39e107bd2a9353d0f25fb2fa43dc94f5db1c9f1f3", "[vm]") {
  std::string bytecode_str = "60186101000a6101000a600055601860ff0a6101000a60015560186101010a6101000a60025560186101000a60ff0a600355601860ff0a60ff0a60045560186101010a60ff0a60055560186101000a6101010a600655601860ff0a6101010a60075560186101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("8c4b0574e9156b80035f3ecdcf1fe79d273ed7559747a4322bcd338f20180101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("4ca55f89202c524cb0f1cb3195d13c8d94a9f7a05c59e1d4031577c707e80101" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("b921f7aa6aff8100000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("c706cb25e8384ce9bb5c9cb48415238ba03e16c448e292c0a101843b081800ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("d542e526003539ead104274aff2d78332366e29d328c2161f0c120731fe800ff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("5c33085514ff7f00000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("expPowerOf2_32______1c83675482424298675a170ac78731d2fd4660aa4a42739a1ba1e6032e3a736a", "[vm]") {
  std::string bytecode_str = "602060020a600055601f60020a600155602160020a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("0200000000" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("80000000" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("0100000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("signextend_0_BigByte______9690d6442d8ff89edda5c528ab4e1cb01ee09ba06c4e0c59d78be6d82259c40b", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000b600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("mod1______efb4ba86b8ead1a13d49883472aa7876f6c2f22d094d84a22e0aa206bcf0443e", "[vm]") {
  std::string bytecode_str = "60027fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff06600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sdiv_i256min______0fb4aa11ee10780f512ea76b238c096b781768ac4048e45d4b5ce3aa8f0a987d", "[vm]") {
  std::string bytecode_str = "60016000037f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000305600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_15______5b661530dd5092ea6c0916ede1eac91b3650b6eb747c7fb5b51c86e6c638b29c", "[vm]") {
  std::string bytecode_str = "600f6101000a600055600f60ff0a600155600f6101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("010f6acc60cea63c3698c056c7690f01" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("f1673e495873f60f7eb5acc6970eff" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("01000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("mul2______d78a8768183f5c845b70898608b589cea44445d770bac7d08071fbccd9122d7a", "[vm]") {
  std::string bytecode_str = "6017600002600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("exp0______becfe094fe303afc738e2960a64d60ec529d99bf137a608b055ba1ae426f5040", "[vm]") {
  std::string bytecode_str = "600260020a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("04" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("signextend_BitIsNotSetInHigherByte______d7fe1705027d2eaee0adc232f8c10fad41b29b39323215fba98de942695a2ba0", "[vm]") {
  std::string bytecode_str = "62126af460010b600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("6af4" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("smod3______065fa0c03f285a3f544803b152a83747c02e25bfa2534c5aaae56128a836d245", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600260000307600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("smod2______0ae154b4126001a661cccd291c9f3a10cc9051e554a729f22dc26cb32f37c7f4", "[vm]") {
  std::string bytecode_str = "6003600560000307600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("signextend_Overflow_dj42______7670c75ec39bedeeac949ccec613c786efedd311a4f2a05ce3b28b1822f67b3b", "[vm]") {
  std::string bytecode_str = "6005565b005b61800080680100000000000000010b6180011160035763badf000d601155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("mulmod4______d0eab7707b7c4159ec4e9b68f395056a16fefb9a701a45e137b8993127870fb1", "[vm]") {
  std::string bytecode_str = "6064601b60250960005360006001f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("exp1______865320dd21d6636f4bf6f450f1df11b3df505304b74e57940db08814078b7208", "[vm]") {
  std::string bytecode_str = "7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_14______61841ab9a30c340ba56febf6d767ab19f91d9bb32ddd7a0c5ee5fdf080faf829", "[vm]") {
  std::string bytecode_str = "600e6101000a600055600e60ff0a600155600e6101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("010e5c6ff0ddc873c2d5ea6c5b0e01" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("f25997e139ada3b331e7945af201" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("010000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("mul3______ea10c103a01bd1ae9bf5e1b964928ced5f84e6dbcdaa589400d20efcc3f6f787", "[vm]") {
  std::string bytecode_str = "6001601702600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("17" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("smod_i256min1______1ac5584b891146649c93c9adb684f955bb539884cb37173d6765c46b37a39c50", "[vm]") {
  std::string bytecode_str = "60016000037f800000000000000000000000000000000000000000000000000000000000000060000307600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("expPowerOf2_64______8e369c41de5a6a6e3c87ed3f76e2a56d98b8283b18c9ef028d4829ed286d3b75", "[vm]") {
  std::string bytecode_str = "604060020a600055603f60020a600155604160020a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("020000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("8000000000000000" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("010000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("mod0______44970c0ef5fc5d700edaf9be35380d95cc5f91ac6f813a57046b9e1884afab0e", "[vm]") {
  std::string bytecode_str = "6003600206600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256Of256_25______681b6391573ae3638d187cb462c2ceac81bb651942fa2a4039c54835a82bc251", "[vm]") {
  std::string bytecode_str = "60196101000a6101000a600055601960ff0a6101000a60015560196101010a6101000a60025560196101000a60ff0a600355601960ff0a60ff0a60045560196101010a60ff0a60055560196101000a6101010a600655601960ff0a6101010a60075560196101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("29d80e8060ef2221929bb18215586c742686d6860e028ca0456b443238990101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("6646340ad51a03bb710caf05756b685b33c7dad62ae68d369243700ead99ff01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("21f7aa6aff810000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("1275e752b6aee228ecba5e9b57ef1111deff3c651e2cfbf2cccd13151f9900ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("7f510dd7198cac0a92ff7ea80451838c0dfa12114c41a0ef05907397f897feff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("33085514ff7f0000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("expPowerOf256_7______ccc726de1f10bdaaee5b164f93a976e78f4c031e826a8237bb03f46113e00059", "[vm]") {
  std::string bytecode_str = "60076101000a600055600760ff0a60015560076101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("0107152323150701" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("f914dd22eb06ff" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("0100000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("expPowerOf256Of256_33______52733d6f69e238cd513f28e3fe30dc303493edb9c0637029e448f0e974b1c940", "[vm]") {
  std::string bytecode_str = "60216101000a6101000a600055602160ff0a6101000a60015560216101010a6101000a60025560216101000a60ff0a600355602160ff0a60ff0a60045560216101010a60ff0a60055560216101000a6101010a600655602160ff0a6101010a60075560216101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);
  store_item_t item6 = Utils::accountStoreValue(6, accountItems);

  // then
  CHECK("39b68fb9898dd7568abd178397251ce8226a25c1d305a4e79573333520a10101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("e678999aeffd1f1f45081f64de7f80ab083dd7df04721ed64ee04c03bda1ff01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("01" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("6694bb31b20cd625f3756897dae6d738f2e64467b5b6f10fa3e07763ffa100ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("8dcb65b5494eba78cd6756a6f9851f6e26d0f2bb9ecd7e9abd7e9b11209ffeff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("01" ==
    Utils::uint256_2str(item5.second)
  );
  CHECK("01" ==
    Utils::uint256_2str(item6.second)
  );
}

TEST_CASE("expPowerOf256Of256_13______d7052bc90b7237c69a4efdf860a687a529c09e545ddc74ab104923c720ad0b91", "[vm]") {
  std::string bytecode_str = "600d6101000a6101000a600055600d60ff0a6101000a600155600d6101010a6101000a600255600d6101000a60ff0a600355600d60ff0a60ff0a600455600d6101010a60ff0a600555600d6101000a6101010a600655600d60ff0a6101010a600755600d6101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("19e6822beb889be28310060f4fb9741bfd50a31fa81ec65de21f7b02548d0101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("0daa3a177ec975cb69bb4acf4a6e1be7bcc1ad33d1ffad97510f9fea9d8dff01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("41ac5ea30fc9b0f000b68fb921f7aa6aff810000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("a923a28e7a75aef26c51580ffc686879e4a0b404b089bdbcd751d88b478d00ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("8be664bde946d939ce551b948b503787942d2a7734509288c1b62fd5c48bfeff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("e02639036c698218879ec55c33085514ff7f0000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("sdiv0______f0994462e2dd8cc0e076a7379a5a88a01a40586601ff426717cf1d678cd4385d", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000305600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_18______5a677d007106e82a37e13f3560fa0e97f88bad6f826a0b63740fc4b25d0b5a15", "[vm]") {
  std::string bytecode_str = "60126101000a600055601260ff0a60015560126101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("01129c3c15c100fbac976a98a583f730991201" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("ee95dbd2d0085a30be71f86293f0d098ee01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("01000000000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("expPowerOf256Of256_3______54eb95326b641250ce064811abbd4d246395a7fedaffa684b00c7667b04ec00c", "[vm]") {
  std::string bytecode_str = "60036101000a6101000a600055600360ff0a6101000a60015560036101010a6101000a60025560036101000a60ff0a600355600360ff0a60ff0a60045560036101010a60ff0a60055560036101000a6101010a600655600360ff0a6101010a60075560036101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("f0f0820797315acd063056bba76f6a9c3e281cdb5197a233967ca94684830101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("4335694e98f372183c62a2339fa4ad161e9b4c42240bdc9452abffd07783ff01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("298e2f316b4ccded5ebf515998d9ec20df69404b04a441782a6aff8100000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("5d24a14d8e5e039372cd0f6a0f31e9ed6b75adba9f16b1c5b3edd5ba818300ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("54a792f15e9aba7e4ad9e716bc169eea3a6e2e9c49bf9b335874613c8081feff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("109a00e1370d2d2922bf892e85becb54297354b2e5c75388d514ff7f00000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("signextend_AlmostBiggestByte______fbfe54fdecb381ce1abdf7dcd95076ae6a3ce4cdd49d414df4798399a536f517", "[vm]") {
  std::string bytecode_str = "7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe7ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe0b600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("addmod3_0______45cf97d25ad676aeea9764fcff1d6e7ec78270b322af420c5a3a668f8807222f", "[vm]") {
  std::string bytecode_str = "60026003600003600160040814600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("mulmod2_0______e7772703144f24ed842d6df70931910c59e3cf48885caa204e1cfc66109d56aa", "[vm]") {
  std::string bytecode_str = "60036001600560000309600360056000030714600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("expPowerOf256Of256_29______eea0d96d36132886c8e85240f2ce145ee5d78888bfb08cbfc937c4eb29d76075", "[vm]") {
  std::string bytecode_str = "601d6101000a6101000a600055601d60ff0a6101000a600155601d6101010a6101000a600255601d6101000a60ff0a600355601d60ff0a60ff0a600455601d6101010a60ff0a600555601d6101000a6101010a600655601d60ff0a6101010a600755601d6101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("5cc9e6b0b749fd94541ad00364bdec2fca7816981ca3e38f485decc7a49d0101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("1226984faa6b05ebdbd45d8477fa4fd5b55bfd5061de03c319282b153d9dff01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("ff81000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("a84162ca6675a22c4c79dfc4ea15f760db5a04dbf04246764199b668879d00ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("41e065d46e0349cfe624c4e8a2034aea1f7edfff80e511cd8067d488949bfeff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("ff7f000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("signextend_BigBytePlus1_2______ab3be4aeefd25904d80c1a58bec3280e86ce66085d4871343424179945748003", "[vm]") {
  std::string bytecode_str = "60ff68f000000000000000010b600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("add1______d67a2f100d1736e3bc391e1ed2aea12f7fe8b1b9009c854c07c188c70a28d0cf", "[vm]") {
  std::string bytecode_str = "60047fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("03" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("addmod1______2ff6c05f22a0669f6a2cbfe5d7706c016e3849448e53e6261251584908c4f683", "[vm]") {
  std::string bytecode_str = "60026002600003600160000308600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_22______6c41658d1a70ae8cbafb18046c8863fdf6d5b2ecd6fedaac9597d0b23580ddc9", "[vm]") {
  std::string bytecode_str = "60166101000a600055601660ff0a60015560166101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("0116ed20fb041418baf4c37d91efb553dbfa9904e71601" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("eae1182d42dfa98cc73c3e63d280f30e3e8cfce6ea01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("0100000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("expPowerOf256Of256_10______21b4b949d4f8bc1ab587529fc2373e244edd0374433a99ef3b288334d65adb9b", "[vm]") {
  std::string bytecode_str = "600a6101000a6101000a600055600a60ff0a6101000a600155600a6101010a6101000a600255600a6101000a60ff0a600355600a60ff0a60ff0a600455600a6101010a60ff0a600555600a6101000a6101010a600655600a60ff0a6101010a600755600a6101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("a7a0223829f26d6c635368034320563df4aa5eb62efc87a42bb35f69b20a0101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("185fa9eab94cfe3016b69657e83b23fd24cc6960218254231c3db627a7f60101" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("2d49ff6b0bbe177ae9317000b68fb921f7aa6aff810000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("56ddb29bca94fb986ac0a40188b3b53f3216b3559bd8324a77ea8bd8a80a00ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("c1ea45f348b5d351c4d8fe5c77da979cadc33d866acc42e981278896b1f600ff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("fe0f60957dc223578a0298879ec55c33085514ff7f0000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("sdiv3______0b700f5943e191289b5c0bee1e9c8d4cae53ef77c61f055af8df241c94d2d8a0", "[vm]") {
  std::string bytecode_str = "6002600003600405600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sdivByZero0______8527a93d7cd284bffde534c9240234c0325249bc55a94cbc7bbee86e0abc6a3c", "[vm]") {
  std::string bytecode_str = "6000600003600360000305600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("mulmod1_overflow3______cea734f62c2074f0e7220b0a22f7cffe76276077677881ecbcc503a8a9b624b7", "[vm]") {
  std::string bytecode_str = "600560027f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff09600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("04" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expXY_success______671a3326670385e9a6a354d8b382a4b62cdd57425bc6d6e67384360f61a67510", "[vm]") {
  std::string bytecode_str = "6000356000556020356001556001546000540a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("8000" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("0f" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("02" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("expPowerOf256Of256_0______005d6e42bfd4e4c18da7d75bdaa44190606fd695395f0758c89c9911ab5218c5", "[vm]") {
  std::string bytecode_str = "60006101000a6101000a600055600060ff0a6101000a60015560006101010a6101000a60025560006101000a60ff0a600355600060ff0a60ff0a60045560006101010a60ff0a60055560006101000a6101010a600655600060ff0a6101010a60075560006101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);
  store_item_t item6 = Utils::accountStoreValue(6, accountItems);
  store_item_t item7 = Utils::accountStoreValue(7, accountItems);
  store_item_t item8 = Utils::accountStoreValue(8, accountItems);

  // then
  CHECK("0101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("0101" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("0101" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("ff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("ff" ==
    Utils::uint256_2str(item5.second)
  );
  CHECK("0100" ==
    Utils::uint256_2str(item6.second)
  );
  CHECK("0100" ==
    Utils::uint256_2str(item7.second)
  );
  CHECK("0100" ==
    Utils::uint256_2str(item8.second)
  );
}

TEST_CASE("div1______aad64e6d9e7887c570b9203d54147d896b21832207288f19a71473bf9539cd13", "[vm]") {
  std::string bytecode_str = "60027ffedcba9876543210fedcba9876543210fedcba9876543210fedcba98765432100460005260206000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("add2______4f9cfe5905693f7a54fedaa484e51920df01a064e3c9c5bd1e479d506060787d", "[vm]") {
  std::string bytecode_str = "60017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("expPowerOf256_8______c1a5c8ebaaa46926bf87a4cfe02f647400e739fac7761296761beaf6ae2ac0b0", "[vm]") {
  std::string bytecode_str = "60086101000a600055600860ff0a60015560086101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("01081c3846381c0801" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("f81bc845c81bf801" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("010000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("expPowerOf2_256______12737b4806aed49d7ab7eb74ddda1f35510496a85e1e478a3704f75b24ee136f", "[vm]") {
  std::string bytecode_str = "61010060020a60005560ff60020a60015561010160020a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("8000000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf2_128______07c52f2c971e3f0c01c5e6ff304223399f96a48fcdc3434fa2a0938124de37b3", "[vm]") {
  std::string bytecode_str = "608060020a600055607f60020a600155608160020a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("0200000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("80000000000000000000000000000000" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("0100000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("addmod2______0d2340969d1058d6112d1aaaafd1e242260a075b9801fc37576ce9df1cf847f1", "[vm]") {
  std::string bytecode_str = "60036001600660000308600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_21______c1c01fc64a2e345e6bb31672d7f8bc063b652f80d0f75002d1c49d36a9c7b3bb", "[vm]") {
  std::string bytecode_str = "60156101000a600055601560ff0a60015560156101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("0115d749b152c1576391324b46a90c47946632d21501" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("ebcce5125534de6b326ead10e3645765a4312e14ff" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("01000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("not1______e3aa182b2227b5b90343ecfd84d5e7ecdc8ef49a282262a4651d4809aafc6e67", "[vm]") {
  std::string bytecode_str = "6201e2406000526000511960005260206000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("smod1______d9e61a2b0310599d823b17276f69995d294e799066503dcd6bd06a62b6b17c7f", "[vm]") {
  std::string bytecode_str = "6003600003600507600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("divByZero______5872a3754ed6c302fcba58fd2332eb0e9d1eaebac9e83d906e5317f10711de16", "[vm]") {
  std::string bytecode_str = "6000600204600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("exp2______bd970c7eba2b9d704a1afd3831e8c17073a5c1080806048085d89dccdbee0bfa", "[vm]") {
  std::string bytecode_str = "637fffffff637fffffff0a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("bc8cccccccc888888880000000aaaaaab00000000fffffffffffffff7fffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("mul0______45cd7403ec890b29ae80f0d74b103c96059310c00ecc103470031fd88875573c", "[vm]") {
  std::string bytecode_str = "6003600202600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("06" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_17______f8e9fd0755c46024b28013f53f8259f6dd3827cc79db275a26c326cfcc6e92d6", "[vm]") {
  std::string bytecode_str = "60116101000a600055601160ff0a60015560116101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("01118ab1645ca45755422870354ea8881101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("ef856134040c669755c7c022b6a77810ff" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("010000000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("smod_i256min2______2482d9bf2796986ef35654b87d92ccc1132251b51dc9ad3d8bde2e45e8659d56", "[vm]") {
  std::string bytecode_str = "600160016000037f80000000000000000000000000000000000000000000000000000000000000006000030703600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("fibbonacci_unrolled______6ca8d6f0f1975e8ffe105ae83d44902ae15cc738402d3921eda5194feac10303", "[vm]") {
  std::string bytecode_str = "6001600181810181810181810181810181810181810181810181810181810181810181810181810181810181810181810181810181810160005260206000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("mod3______e8738afe9d6d4a8e2a3f430ea09cfcaa563a4779254b91c81374e5a297409634", "[vm]") {
  std::string bytecode_str = "6000600306600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("expPowerOf256Of256_26______466a34547f08dfadfe7b8170595dbcd4a85e8841d60e17d45535efadf41e6a24", "[vm]") {
  std::string bytecode_str = "601a6101000a6101000a600055601a60ff0a6101000a600155601a6101010a6101000a600255601a6101000a60ff0a600355601a60ff0a60ff0a600455601a6101010a60ff0a600555601a6101000a6101010a600655601a60ff0a6101010a600755601a6101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("3402a9db66492dfc2a220715e76243469462f24edc56903ba1d8e96ed21a0101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("6931bda98c70e860a1f6a5224940f1ec7e6734cd9456c95806384f7cb7e60101" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("f7aa6aff81000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("8b92c24abebf376a5aab5ff4dfd3538a03d38a10bced2aae8e1a8a85b81a00ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("1d164db738eb6893868b361ad2803f97be35764456e82a837667a693d1e600ff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("085514ff7f000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("expPowerOf256_4______c2d1ac475be3d9708dd091aeee22a87804a4004cbe6a382c63f1d4d304764b57", "[vm]") {
  std::string bytecode_str = "60046101000a600055600460ff0a60015560046101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("0104060401" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("fc05fc01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("0100000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("expPowerOf256Of256_30______479e812da82943e323dfedc14ea5728ff43add90f4b8440158a12862c97a54f2", "[vm]") {
  std::string bytecode_str = "601e6101000a6101000a600055601e60ff0a6101000a600155601e6101010a6101000a600255601e6101000a60ff0a600355601e60ff0a60ff0a600455601e6101010a60ff0a600555601e6101000a6101010a600655601e60ff0a6101010a600755601e6101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("c5a8f4566fd2e96e4ce3a8b3ec0863e7b20bc3b2f3dc5261ba8a0174421e0101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("fd405cce8f73dffc04a6f0ff6ffc6bf7961876d09c5b4933a68f0cc623e20101" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("8100000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("33f0385ef73feebdb952e5adb643dd0fa178fd9271578219ad50a73d241e00ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("e9772778f50fa0a69cd10fa019ac56d72ac7a7d7af26c4ba28415c8f41e200ff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("7f00000000000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("sub4______05d9e4b327336db04e1b79dd21df56bd61361029dd7b4efb33e94315f6f1fe42", "[vm]") {
  std::string bytecode_str = "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff03600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("signextend_BitIsNotSet______ad6c39d9aab1ff75cc4d29e0952352a880d3239b3dcd9ac284b8738fac7debe9", "[vm]") {
  std::string bytecode_str = "62122f6a60000b600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("6a" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256Of256_31______c0c9812a4aec910c25f698f7851d356969417e40a66756b8579024fb5ad6946c", "[vm]") {
  std::string bytecode_str = "601f6101000a6101000a600055601f60ff0a6101000a600155601f6101010a6101000a600255601f6101000a60ff0a600355601f60ff0a60ff0a600455601f6101010a60ff0a600555601f6101000a6101010a600655601f60ff0a6101010a600755601f6101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("b4c358e3c6bcddfb509ea487d733df0e1854f29c3b6bfd4a8caabe3f609f0101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("ee5f2839c1b4f6ca05e6fdb04e2fb49c0f860b3765c27dc781a150cb7f9fff01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("01" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("893d729a64e318860ec5047e70e598da163eb41e71e74b04dfd4712d419f00ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("f9cb87f5b1ab58602f52a1e9d392e5675b86a59a53943a8d4ec2a915dc9dfeff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("01" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("signextend_BitIsSetInHigherByte______ac72667a2e447bdbe107272ec54041d01f13e9d0ad67be9f35ceb797fa8fa3d9", "[vm]") {
  std::string bytecode_str = "6212faf460010b600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffaf4" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_5______6146ceb91510b1cb9c01dab28929f5c50ab7351b971631b79b4e55ec4f9d0758", "[vm]") {
  std::string bytecode_str = "60056101000a600055600560ff0a60015560056101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("01050a0a0501" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("fb09f604ff" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("010000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("expPowerOf256Of256_27______4cb84dd85410e6e10a6fb0903c5336c92f1f3b1183b37b0d69793ab6eeff538a", "[vm]") {
  std::string bytecode_str = "601b6101000a6101000a600055601b60ff0a6101000a600155601b6101010a6101000a600255601b6101000a60ff0a600355601b60ff0a60ff0a600455601b6101010a60ff0a600555601b6101000a6101010a600655601b60ff0a6101010a600755601b6101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("1b4e6404f474c18055d30bb8987672f59e97980d6f9de1764c0fbec5ec9b0101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("d02811cb5dc1d80567e810532b235b7672f5c78cd6e89bb511d5e2d8f79bff01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("aa6aff8100000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("38ecff71480ca0b422f2ed6f780d5fead2ae234a49104b10a86f7f0dd19b00ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("178918ffbcb401d4efd2f7dfb4d01a897172267f0f491121ac52dd614899feff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("5514ff7f00000000000000000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("expPowerOf2_2______a2bac0fecd9bb22498ef34248c689e040dff1c9551695bb52490005655252a90", "[vm]") {
  std::string bytecode_str = "600260020a600055600160020a600155600360020a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("08" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("02" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("04" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("addmodDivByZero______07a2c67042f0a0a767dabddeff135071990a3121c53e59388d423f7312d97732", "[vm]") {
  std::string bytecode_str = "60006001600408600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("mod2______1f5ca72bfa3c2c922df107ec65b03875606654bc9323bbe4d0d6917cc70b78a0", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600006600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("mul1______62739e6b84ff552b35b894761b28b32935dd20af24275507ba8fb2823e21a3fa", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff02600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_16______9b8e345adf5a89c6fd364d4f668a7bd07dafbe8d54035b530c17592ffc0a7867", "[vm]") {
  std::string bytecode_str = "60106101000a600055601060ff0a60015560106101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("01107a372d2f74e272cf59171e30781001" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("f075d70b0f1b82196f36f719d077f001" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("0100000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("exp3______60cc7f7666a3c4ef52e3af53332f1cf55f8a6b0bffe0395fa9236bb58d6600d8", "[vm]") {
  std::string bytecode_str = "637fffffff60000a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("smod0______657d85189406a5174b2e2c8d2a156aa8bd3844d715a6a21cca3f977769de8ddf", "[vm]") {
  std::string bytecode_str = "6003600003600560000307600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_20______d1c3af7ccb5c6194e2169b9e2f961b10e1899b7fefde762a18e4962171293562", "[vm]") {
  std::string bytecode_str = "60146101000a600055601460ff0a60015560146101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("0114c2872a2898bea4ec46054167a4a2f174be1401" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("ecb99eb1063b1984b725d2e3c72b82e88cbdec01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("010000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("addmod3______90b707def53d6810926ea7b4b409adf597e5ab856e36916ad59bd0080b3493c1", "[vm]") {
  std::string bytecode_str = "60036000036001600408600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("05" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_9______1c9cbff4e50f2007147b4c1ee0f4f1bce34cc34003bdf76c682d6f8fe096a842", "[vm]") {
  std::string bytecode_str = "60096101000a600055600960ff0a60015560096101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("010924547e7e54240901" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("f723ac7d8253dc08ff" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("01000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("add3______3bd86a492ae4e00b1432d5458d920592919816b61704a200a619a4519dc033f6", "[vm]") {
  std::string bytecode_str = "6000600001600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("expPowerOf256Of256_1______cfa261cd17404f41ad16a6c50f85e826ba31c9ef0f4fb07330baccb7fceaf896", "[vm]") {
  std::string bytecode_str = "60016101000a6101000a600055600160ff0a6101000a60015560016101010a6101000a60025560016101000a60ff0a600355600160ff0a60ff0a60045560016101010a60ff0a60055560016101000a6101010a600655600160ff0a6101010a60075560016101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("b89fc178355660fe1c92c7d8ff11524702fad6e2255447946442356b00810101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("c73b7a6f68385c653a24993bb72eea0e4ba17470816ec658cf9c5bedfd81ff01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("02b5e9d7a094c19f5ebdd4f2e618f859ed15e4f1f0351f286bf849eb7f810001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("bce9265d88a053c18bc229ebff404c1534e1db43de85131da0179fe9ff8100ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("8f965a06da0ac41dcb3a34f1d8ab7d8fee620a94faa42c395997756b007ffeff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("06c3acd330b959ad6efabce6d2d2125e73a88a65a9880d203dddf5957f7f0001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("mulmod1_overflow2______39bbcf3f466015094b1966b488fb130f5f43e7f754742dcd73ab9fe36b175140", "[vm]") {
  std::string bytecode_str = "600560027f800000000000000000000000000000000000000000000000000000000000000009600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sdiv2______f23ddbb1007d7edd1cc43aa31e6754f5bffc664fd470d83d4ba9c5d73f92e05a", "[vm]") {
  std::string bytecode_str = "6004600003600260000305600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("sdivByZero1______da488af1640adb0d5fe53576afb146ba3e48b79d6fb20ebc0a723810c957347c", "[vm]") {
  std::string bytecode_str = "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000305600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("expPowerOf256Of256_11______0b1366d68a11bbb8b60d5458d1c5f75983c677beda062040a2a12217dcd6dd92", "[vm]") {
  std::string bytecode_str = "600b6101000a6101000a600055600b60ff0a6101000a600155600b6101010a6101000a600255600b6101000a60ff0a600355600b60ff0a60ff0a600455600b6101010a60ff0a600555600b6101000a6101010a600655600b60ff0a6101010a600755600b6101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("dbbaef5c49ffee61b08cde6ebc8dba6e9a62d56c2355d1980cb9e790bc8b0101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("540a4e4635b40585e09ff10b63ffe310dd717fca5c0a51570091e25e378bff01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("67799740340daf4a30f000b68fb921f7aa6aff81000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("3df8c030ec521fb109c4d887dbbc14c7c9c9921b27058e3503971b60b18b00ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("29575fdce377b23043e489e358581474bc863187fa85f9945473a2be5889feff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("e1440264b8ee0cea0218879ec55c33085514ff7f000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("divByZero_2______78d75e4a3fa542827bcd7d0ea0219c73036b1894b4f4f1d2db5115e9d6b82245", "[vm]") {
  std::string bytecode_str = "60076000600d0401600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("07" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("smod7______a36ed55f2f8ba020ce5a62ef6e40d293dd21f437a822cd6f33b5525c8af00c8c", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000307600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("addmodDivByZero3______9d7b88296068c5ed1620b7eaad6d1790e9140bd888ff108169d44055223777a3", "[vm]") {
  std::string bytecode_str = "60016000600060000803600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sdiv9______18566af59c50610c4d0730ca3171edb8079ef515fe3580e356caf81401a54bab", "[vm]") {
  std::string bytecode_str = "6001600160000305600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("exp4______3e3173753802a0d3265703667247f978ebbe5f0e2d22c9cf94f0c09efb3a2ac2", "[vm]") {
  std::string bytecode_str = "6000637fffffff0a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("mulmod1______ed3024180ecf5192c2c72e6c0e0c646a31121a9c2d81f8fc661cc404c2c49175", "[vm]") {
  std::string bytecode_str = "60036002600003600160000309600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("expPowerOf256_11______b1c6926a4ec774b5eb1dc422f228e11e96f892b8bbb40a525ba97ac9f30b610a", "[vm]") {
  std::string bytecode_str = "600b6101000a600055600b60ff0a600155600b6101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("010b37a64bcfcf4aa5370b01" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("f5365c4833ccb6a4c90aff" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("010000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("mul6______93939ec6ec2137f19afdb9596236ff35ae94068ba39563ed649153ed975d8a9d", "[vm]") {
  std::string bytecode_str = "7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff02600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256Of256_20______c3555c8b166600d82076a8dace17cdba2e354cc84b92e88080ae847533a1f39e", "[vm]") {
  std::string bytecode_str = "60146101000a6101000a600055601460ff0a6101000a60015560146101010a6101000a60025560146101000a60ff0a600355601460ff0a60ff0a60045560146101010a60ff0a60055560146101000a6101010a600655601460ff0a6101010a60075560146101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("3b2e28d274a16c08b58a23bad63bba6d7b09685769d1f68ca3873bedc8140101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("cce501857a1cb45473915a28082af950e0f78f7e2de68ce748adb661b3ec0101" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("f000b68fb921f7aa6aff81000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("a1ce1a085f258785846939cc1d2e8725ac94ad4dff8913234e00679fb41400ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("67e4797dc21f02ce4a7c52218c7dbea5d212e6c244e24f0ba4c08613c7ec00ff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("18879ec55c33085514ff7f000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("expPowerOf256_2______c16dec87b8f5f4457c20c3ef8bba3a291ca99433d10c52a8c95844ae4c80f774", "[vm]") {
  std::string bytecode_str = "60026101000a600055600260ff0a60015560026101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("010201" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("fe01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("010000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("sub2______2a70037d8d25f8333be090608c64a57f9d894ba31647d9ca910f1d68f6f91d73", "[vm]") {
  std::string bytecode_str = "6017600003600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe9" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("signextendInvalidByteNumber______fafb83f281612538c3b8a0ad616214c94f232a83b661ddeb2913d44c86c5e1f8", "[vm]") {
  std::string bytecode_str = "62126af460500b600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("126af4" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256Of256_16______7abe4db41b9db5ddba7e759a19f56721bfda3633d9a209a61885770b48730ba0", "[vm]") {
  std::string bytecode_str = "60106101000a6101000a600055601060ff0a6101000a60015560106101010a6101000a60025560106101000a60ff0a600355601060ff0a60ff0a60045560106101010a60ff0a60055560106101000a6101010a600655601060ff0a6101010a60075560106101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("4a103813c12c12169b218296bb0a9eae80cf8d2b158aa70eb990f99480100101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("88e1259502eef93d46060aacc9e2ff506c734dade0b6714ab12d17e46ff00101" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("228fc9b0f000b68fb921f7aa6aff810000000000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("6a2b3bc87a02c29b9d27757df43047ecd0f15485270fca27417a701c701000ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("3122f4bcdf6dd8b265cd18eb6af28c879aed44a35e0bf59273e39e6c7ff000ff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("82ec698218879ec55c33085514ff7f0000000000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("modByZero______60d18d29ddc0d3fada77384fd6a1fdb5c8db6f39cac1d49150133ad4c876111e", "[vm]") {
  std::string bytecode_str = "6001600060030603600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("divByNonZero3______18eb2a03d9fb6139351c9348177f453fae7b4d0147cb61f0bc054cc94611fc79", "[vm]") {
  std::string bytecode_str = "6001600104600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("exp8______8cc82dc5b40b6997018e4dd9ed813adc10d48b61aa086c3d44b89c02180d9286", "[vm]") {
  std::string bytecode_str = "600060000a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sdiv5______900ae8a1b5b71f5af75af223f8157cca4eac7224648cae647c2e9973be2db508", "[vm]") {
  std::string bytecode_str = "60016000037f800000000000000000000000000000000000000000000000000000000000000060000305600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("8000000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf2_16______d929b716ca2db29bb5383636946442ae3b248a8044221ae84cebd98b40bf3fa2", "[vm]") {
  std::string bytecode_str = "601060020a600055600f60020a600155601160020a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("020000" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("8000" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("010000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("expPowerOf256Of256_6______0b504c01aa8be1b0f4d75843a158f9ece56004fdfb31cbdd8ea631b19bd31c2e", "[vm]") {
  std::string bytecode_str = "60066101000a6101000a600055600660ff0a6101000a60015560066101010a6101000a60025560066101000a60ff0a600355600660ff0a60ff0a60045560066101010a60ff0a60055560066101000a6101010a600655600660ff0a6101010a60075560066101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("810ac878bd98428f6be8c6426ba9f9da09e3e33bf4fe10bfa3f8b12c92060101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("57385019fe4e0939ca3f35c37cadfaf52fba5b1cdfb02def3866e8068bfa0101" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("083c936cbaad5de592badc2e142fe4ebd6103921f7aa6aff8100000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("ede6fe4a943dfb5d967a2b85d6728759d40d2ef0ae4bc28bbb1867f98c0600ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("41f818a8e24eb6d7bb7b193b4f2b5fdcf4bd0d453f2ac3499d8830d391fa00ff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("1948059de1def03c4ec35fc22c2bb8f2bf45dc33085514ff7f00000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("expPowerOf256_31______49c27829894da6d63678e456733ea6fdc70f2757967ba5abbf180965428758ee", "[vm]") {
  std::string bytecode_str = "601f6101000a600055601f60ff0a600155601f6101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("0120e30c8c1bb25c9d2219ea196c17ded3d775b231bbd28005b131fa90d11f01" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("e2bfe95c5d7067567402dd9d7235fc088ac84eab8113bf8d7e3c288d2f1eff" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("0100000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("sdiv_i256min2______90030696ae4a357369cc2782a28d4815a9935a9de909919b56b4a35e73a6fe1f", "[vm]") {
  std::string bytecode_str = "60016000037f800000000000000000000000000000000000000000000000000000000000000060000305600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("8000000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("addmod2_1______98bb343b4feee04868cc71c50989783b808acc50b1c98e7ade4776e994906b50", "[vm]") {
  std::string bytecode_str = "60036001600660000308600360056000030614600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("mulmoddivByZero1______a98185211df6a24ee07ad038dcac863c96507e63593dfa4ba40e268dec182118", "[vm]") {
  std::string bytecode_str = "60006001600009600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("add4______84ab9087035c1a89c5fb97de39f5a70014a07ccd234033a86345e1023a9e3f63", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600101600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("addmodBigIntCast______08fea224001a172ce28f79d64d39b6ae2010c93b8db2a22eceaf648b4864410b", "[vm]") {
  std::string bytecode_str = "600560017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff08600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_27______0b01e16cc7bd26138401de1bc3b8243c48d1b0a460b24a562fa58b5b6a2af2d1", "[vm]") {
  std::string bytecode_str = "601b6101000a600055601b60ff0a600155601b6101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("011c6ab2cdebf906306b38bbf7d6c52648e2d6bc63859e996e5f1b01" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("e653d6571cdebb270b53c9d44c40bcd425165d5af1157d6ba11aff" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("01000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("expPowerOf256_26______6dccbbcb0ee8cd7d2f5843ad5ddf775a3226c7bf803ec5e6a6c6743745cf39a9", "[vm]") {
  std::string bytecode_str = "601a6101000a600055601a60ff0a600155601a6101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("011b4f636a81778ea1c96f4cab2b998cbc26b00c572e7029451a01" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("e73b116885641f4651a56f438fd08d61869cfa55465bd944e601" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("010000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("mulUnderFlow______f00e90cf7a2da69a3d545bd6f562a8277dd75b34d1ef2c4a939be0f95768ec61", "[vm]") {
  std::string bytecode_str = "600102600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("mulmod3_0______0070f9a443a2322b95c7b5087c03809c2f1998b04ba560d40d23e94daef7f961", "[vm]") {
  std::string bytecode_str = "60026003600003600160050914600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("sdiv_i256min3______c515fc2566610c432b0de0dd441f64fa3786ed7b2f921e19ddd23ff00251d920", "[vm]") {
  std::string bytecode_str = "7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6000037fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff05600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("addmod2_0______15d55915fdfbaed97e9812ea54813c07e1882f34b815255f6d795104a5320369", "[vm]") {
  std::string bytecode_str = "60036001600660000308600360056000030714600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("stop______e2fb82d7e038c48bcb3dc482432600771264d43e043100f7c8ac802958a7e94f", "[vm]") {
  std::string bytecode_str = "00";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("signextend_bitIsSet______079a0a92b727ced019553f0b8d57e0a53cf85803f09a10ea969030cfd302439a", "[vm]") {
  std::string bytecode_str = "62122ff460000b600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff4" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_30______48e0ff7a9fb61234eb98e08920d2f6edc07d27fb3d8ce297e801640882ba2a77", "[vm]") {
  std::string bytecode_str = "601e6101000a600055601e60ff0a600155601e6101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("011fc34942d8d9831a0811d8412aecf1e1f58031ffbc16699c151cddb31e01" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("e3a38ce946b71e74e8ebc966d90f0b139e66b560e1f5b542c0fd25b2e201" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("01000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("sdiv_dejavu______6018ba5a8727b5f6c60678c66c95b410fcc2b2c14fe8b47e88aede7f66c73244", "[vm]") {
  std::string bytecode_str = "600560096000030580600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf2_8______b501d810365e03840b7f8635052551bd05c65ee103cdbd989438d3dbdcfb6ac3", "[vm]") {
  std::string bytecode_str = "600860020a600055600760020a600155600960020a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("0200" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("80" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("0100" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("expPowerOf256Of256_7______987100c02d0255c99706c19220a994ab2b46102fc6893ad08aca44c16626ce19", "[vm]") {
  std::string bytecode_str = "60076101000a6101000a600055600760ff0a6101000a60015560076101010a6101000a60025560076101000a60ff0a600355600760ff0a60ff0a60045560076101010a60ff0a60055560076101000a6101010a600655600760ff0a6101010a60075560076101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("09930d11ac2804fa977bf951593c8dff8498779cc0cdc5812a4fba2f98870101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("287b58a5a13cd7f454468ca616c181712f5ed25433a7d5a894b6ced35f87ff01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("c8624230b524b85d6340da48a5db20370fb921f7aa6aff810000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("5fd4d2de580383ee59f5e800ddb3f1717ceae03aede19d3dec5e5a69918700ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("a8f75c129dbb8466d6703a2a0b8212131b3248d70e2478862ac40fe17485feff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("8bb02654111ad8c60ad8af132283a81f455c33085514ff7f0000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("expXY______b1f48c92fc069d4c6db24060394e4753fd7768e6d8c71dcf842e09536b0bf6a2", "[vm]") {
  std::string bytecode_str = "6000356000556020356001556001546000540a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);

  // then
  CHECK("0100000000000f" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("02" ==
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("mulmod1_overflow4______e299f946769fce28c47007d1e2e2313465406917bacadaf1cfabf05f86db6844", "[vm]") {
  std::string bytecode_str = "600560027f800000000000000000000000000000000000000000000000000000000000000109600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("03" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sdiv4______3065d6c46735c24934865e9b79e22fb6f62c23bf23882402a1690dfe873bfe74", "[vm]") {
  std::string bytecode_str = "6004600003600505600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("divByNonZero2______07c53576e7fa46c1ee1d5f30da0d479a49411004f70ea23881c6af61096d6347", "[vm]") {
  std::string bytecode_str = "6018600004600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("expPowerOf256Of256_17______d7a8e01c7d7ef07a3ab3091cf3116a4f6ec8efab1f5dabc6abdab919a3e96f08", "[vm]") {
  std::string bytecode_str = "60116101000a6101000a600055601160ff0a6101000a60015560116101010a6101000a60025560116101000a60ff0a600355601160ff0a60ff0a60045560116101010a60ff0a60055560116101000a6101010a600655601160ff0a6101010a60075560116101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("9c6ca90dac4e97dea02ac969e8649ee9e6232e0c3f4797411151cb8f90910101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("81d5ff63680841482299f3eab616446dcd336f537c0c565aa4112ab95d91ff01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("8fc9b0f000b68fb921f7aa6aff81000000000000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("8ac9b5ec08d74612cb29f941481d274b51721af2296207c0da8d24667f9100ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("722ad218eb1995a2d257c4c06d8de993c203cfc8e3512df7d633e17e908ffeff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("ec698218879ec55c33085514ff7f000000000000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("sub3______0e65bb014804438d489adaded93fa290d960a3c2400d795a7da572d8dd6c0e94", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600003600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_3______4ab92df5bf373064de3eeb8b359d28c9f1146673cf826d2ec82e531fc379a3e1", "[vm]") {
  std::string bytecode_str = "60036101000a600055600360ff0a60015560036101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("01030301" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("fd02ff" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("01000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("expPowerOf256Of256_21______10c6f39a124dba927aaa49875627683b285895b497464e74a1202217096e2089", "[vm]") {
  std::string bytecode_str = "60156101000a6101000a600055601560ff0a6101000a60015560156101010a6101000a60025560156101000a60ff0a600355601560ff0a60ff0a60045560156101010a60ff0a60055560156101000a6101010a600655601560ff0a6101010a60075560156101010a6101010a600855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);
  store_item_t item3 = Utils::accountStoreValue(3, accountItems);
  store_item_t item4 = Utils::accountStoreValue(4, accountItems);
  store_item_t item5 = Utils::accountStoreValue(5, accountItems);

  // then
  CHECK("485053d8ff66be52036597520344fac87b6a305426a9e49221d3f934dc950101" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("1c93db67c9884bc694686d69a25a5d7ed089841d5ce147fdd7199ab00d95ff01" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("b68fb921f7aa6aff8100000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item2.second)
  );
  CHECK("665ac5c769e87f61d5993abc26522fbfca2734d76a63216b2d550d29c79500ff" ==
    Utils::uint256_2str(item3.second)
  );
  CHECK("7fd07055ff50cdfe4b4bd9a15133d72d3607d92eb7ac81bac93db7ff4c93feff" ==
    Utils::uint256_2str(item4.second)
  );
  CHECK("879ec55c33085514ff7f00000000000000000000000000000000000000000001" ==
    Utils::uint256_2str(item5.second)
  );
}

TEST_CASE("expPowerOf2_4______631f6dc2dc4c0da8fcd51e6b47631de57699ba5552f74bfffcf0c1db19ff0900", "[vm]") {
  std::string bytecode_str = "600460020a600055600360020a600155600560020a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("20" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("08" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("10" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("signextend_00______f2d0e5f5e92b4fabe5f8849039ea24659f13dd41ab170684ac9ad4713806ccf6", "[vm]") {
  std::string bytecode_str = "600060000b600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("mod4______1251fd388dafce899b3b8aaa3c1609354b876b279fb749c000888334946e9bc4", "[vm]") {
  std::string bytecode_str = "6003600260000306600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("expPowerOf256_10______136a6ef3b914e46f9118f5d870a74dd1a4e9a3cfc97c84f412d81c07af01b036", "[vm]") {
  std::string bytecode_str = "600a6101000a600055600a60ff0a600155600a6101010a600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("010a2d78d2fcd2782d0a01" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("f62c88d104d1882cf601" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("0100000000000000000000" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("mul7______68228cd9e856bee3481b095c8d1d2ab9fa30a0a1b1fbe697e3a8b01dfb6778e4", "[vm]") {
  std::string bytecode_str = "7001234567890abcdef0fedcba09876543217001234567890abcdef0fedcba09876543217001234567890abcdef0fedcba0987654321020260005260206000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("sdiv8______ea05e5ca26b556596f9d6e65f84d238632215eb308b26b1da829b48a4f07e9a1", "[vm]") {
  std::string bytecode_str = "6001600003600160000305600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("exp5______e6fc1d5718f3d1bcbc540b19ad2c208aab3e582d581278b7d692ea4b733deecd", "[vm]") {
  std::string bytecode_str = "60016101010a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("0101" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("mulmod0______15ef0419e36c1c1b45577f633dde9b4f4c0fc16258a46060ac228551fd5b9168", "[vm]") {
  std::string bytecode_str = "60026002600109600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("addmodDivByZero2______ac86e7a61c79097514f97614f6afbd86d3f7d6e529c48b15a318ecbbf22e75f4", "[vm]") {
  std::string bytecode_str = "60006000600108600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("arith1______e8665046be1f18c3372a4cdc4aab1ffc95156012239eaca43fd5c6c388f25075", "[vm]") {
  std::string bytecode_str = "6001600190016007026005016002900460049060016021900560150160030260059007600303600960110a60005260086000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("smod6______23d40161e481cfa284f74d8d7a49de035d09bf5fc3f565f80292f804f92cf81f", "[vm]") {
  std::string bytecode_str = "7f7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000307600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("dup3______b67364d451119d543fde8c6e2eaffd8108ca8cdb9fc44bb4d60b985e601ce6c3", "[vm]") {
  std::string bytecode_str = "60036002600182600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("03" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push13______f87790ab58643f0f368549d883f39e63730eb67364362db04def43491dc0fcea", "[vm]") {
  std::string bytecode_str = "6c33445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("33445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push6______20352e83bb4bd243245e03766739469d2a5d1dee980035e85a5b62dc0a3ff8dd", "[vm]") {
  std::string bytecode_str = "65aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("swap4______3cc1b87e1def29c23a3142f8fb160db3f8574b7e20ba1327b10ea54c15c94964", "[vm]") {
  std::string bytecode_str = "600460036002600160039355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("dup13______bf66efdee3944574d78fbbc235fab6b51ea5b5a2cf62d2dfca49fc3e761862e3", "[vm]") {
  std::string bytecode_str = "600d600c600b600a6009600860076006600560046003600260018c600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("0d" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push29______4a85eb183184082fff2036f2ea2d5667a1df1232d507db83e137d608ec994091", "[vm]") {
  std::string bytecode_str = "7c33445566778899aabbccddeeff00112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("33445566778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("swap2error______732f92c884d3a29d05e243f2b105b345ecd1813624591f5220e60e12d89b3ace", "[vm]") {
  std::string bytecode_str = "7f10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff60039155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("swap8______b0ef60e4ab69728a4c5daa24707b90e5e2e9b4f778a790e7915f68daf82174bb", "[vm]") {
  std::string bytecode_str = "6008600760066005600460036002600160039755";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push33______077208da2bec8e9beec0a1217689d1d4d085b682688bfebd048fed80ed067c8b", "[vm]") {
  std::string bytecode_str = "60656107d26204a0c763026921f4640bc5588eb165372d0f1dca6e661ba1d901961c71670c55f7bc23038e3868056bc75e2d630fffff69021e19e0c9bab24000016a085d1c6e8050f0ea1c71bd6b0688be36543f3c36e638e37a6c03d41f73d55d0d482ae55555376dc76810d0fe03c91964d31c71c6f46e615dd0360c07d931663b14e38e38b16f2da3f99955a3adcf27ebb1caaaaaaa6e7014ccba6a8bb1ed35bd86bf065c71c71c2b7109491c5d4781b79c9009de6bfb8e38e38de8720414a0f6fdec81304d4c563e740bffffffffa573118427b3b4a05bc8a8a4de8459868000000000017406eb15e7331e727940d4ac54b7cdca1c71c71c71bd750567a91c9fefc96ebaa626a22f98c5e638e38e38e37a76032abd16c5b68006e15d5aa307e383f4e55555555555377701a6427bdc4f0d58eab5f48a3ec67f64e21c71c71c71c6f478080dd0a0c9b9ff2c2a0c740b06853a0a980ee38e38e38e38b17903c679cb5e8f2f9cb3b5d6652b0e7334f746faaaaaaaaaaaaa6e7a01b873815917ebb2bf3b890a1af495d6235bae3c71c71c71c71c2b7b07ae4cca96e1a55dfa49c85ad3c3e60e426b92fb8e38e38e38e38de87c036018bf074e292bcc7d6c8bea0f9699443046178bffffffffffffffa57d0e7d34c64a9c85d4460dbbca87196b61618a4bd2168000000000000000017e05b901f48a5b994d6572502bc4ea43140486666416aa1c71c71c71c71c71bd7f047889870c178fc477414ea231d70467a388fffe31b4e638e38e38e38e38e37a";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("push25______f6511eb983bed5be1f13a344fbfcbfca8779b10270e17f6db6f8dbccecf3406a", "[vm]") {
  std::string bytecode_str = "78778899aabbccddeeff00112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("swap10______d6eefdfd9775c34cc3853e86cda54e692d21b27ae5a411000e1d81754220aa13", "[vm]") {
  std::string bytecode_str = "600a60096008600760066005600460036002600160039955";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("swap11______5815c1b934def10dcee373880ebbfa1a0f0d9b50bf73b74e90698f2bdf922201", "[vm]") {
  std::string bytecode_str = "600b600a60096008600760066005600460036002600160039a55";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push24______0b803a0bab1d0263a15c9b4327f91c8aa3db96de090e4057822d8fda4a89e8f7", "[vm]") {
  std::string bytecode_str = "778899aabbccddeeff00112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("8899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push32______f977ad4f4ba30494360ef3c1109f0eec63195cb8a4dc02e335529c5a71985270", "[vm]") {
  std::string bytecode_str = "7f10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("swap9______8bd1272a471faa1ba776b44899e39b51abd4dc778e1c7b14c352e265fedd6bbc", "[vm]") {
  std::string bytecode_str = "60096008600760066005600460036002600160039855";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push28______a68c1cd274a700c3998e8a2824b87bf4bcea8559f2565c8bb633ff9a9f8f95e6", "[vm]") {
  std::string bytecode_str = "7b445566778899aabbccddeeff00112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("445566778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("swap5______15e65157fc078609a17c0a49a12fcd66952f3df931be63c90d12b822ee4ea956", "[vm]") {
  std::string bytecode_str = "6005600460036002600160039455";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("dup12______3decf581cdc53a2cc283c919081d7b5a9659bf3905c153fee26fc03857f8f656", "[vm]") {
  std::string bytecode_str = "600c600b600a6009600860076006600560046003600260018b600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("0c" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push7______fd5302474303fb4a6a8360477916e2c1ee530993c2b336907109d021b95ae2e5", "[vm]") {
  std::string bytecode_str = "6699aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("99aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push12______efd96f408cbfdff412ecaae356c6b1e48edf7df1a5f517cb6732d628fdf48b13", "[vm]") {
  std::string bytecode_str = "6b445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("dup2______b40c551023460432955c0c11180e5c13cb0ea11616a5dd22d475a306e8acbd15", "[vm]") {
  std::string bytecode_str = "6002600181600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("dup9______b4b1fc6f5cfcf793f11c9864a854b5cc79a2dbb2d87be72b517612615888c121", "[vm]") {
  std::string bytecode_str = "60096008600760066005600460036002600188600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("09" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push19______802f7d9d36053e12703ed315251bbfee933b4bcaeb16721e4744fcbd63144fef", "[vm]") {
  std::string bytecode_str = "72ddeeff00112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push23______3eae4e6c909ac53548a0006397d40484a8173e11ee9332df1e7ae5b3b0a18647", "[vm]") {
  std::string bytecode_str = "7699aabbccddeeff00112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("99aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("swap16______b09afdcdd393eff8a1656a0b3124b1492f1375232a3243fa413166ed6ce7a3f5", "[vm]") {
  std::string bytecode_str = "6010600f600e600d600c600b600a60096008600760066005600460036002600160039f55";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("dup5______f2d4e02c337ab8b63b3360e946a77435e695207ddcf50cb856072cb793e989e7", "[vm]") {
  std::string bytecode_str = "6005600460036002600184600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("05" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push32AndSuicide______6f3fd0fde9853507cadb8c8882461470b463d5928dcea37fdf6d42e76ca42e94", "[vm]") {
  std::string bytecode_str = "7fff10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("push15______24fb81e0b527a61bf6304ebfc005f2c2f7045e69a4eede3dcc1a203c51a97e13", "[vm]") {
  std::string bytecode_str = "6e112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push32Undefined3______09630b43bc0f6895178f52bdade60c0b93398a7343780373a80a40b4bdb3d6bc", "[vm]") {
  std::string bytecode_str = "7f";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("dup15______fc8f9f4a5c21f4779a4476e64e5ac9bfb7908d18a066476165a18f2fbc9fd48a", "[vm]") {
  std::string bytecode_str = "600f600e600d600c600b600a6009600860076006600560046003600260018e600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("0f" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("swap2______b10f0cb24eda2b4df170b037adae875a80c12cca909b0d0372c252ef35340ed8", "[vm]") {
  std::string bytecode_str = "6002600160039155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push32Undefined2______77e275f6face7fb0aec71c687e63fce8a78c31e433f88e2e121c8b7851e2748c", "[vm]") {
  std::string bytecode_str = "7f0102030000000000000000000000000000000000000000000000000000000000600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("0102030000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("dup14______84d89703aec77b537e1a9b8ca09682df0126677f5cafee64dd2e41faf87175ac", "[vm]") {
  std::string bytecode_str = "600e600d600c600b600a6009600860076006600560046003600260018d600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("0e" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("swap3______396c1fc538ae74ceb295e25d29a5ece7d4bbd6807b48adc736d56c3db90651cd", "[vm]") {
  std::string bytecode_str = "60036002600160039255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("swapjump1______2e9446e737a45b6c198cfd1fdeea2f889705138ac54e7569093144c12953f164", "[vm]") {
  std::string bytecode_str = "600560026001600c575050005b9060016116575050005b035b0360005260016003611ff3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("push1______977bf38a869183f69e1e65e4b5f638ddc858637f53305fdddb972675e7f22e56", "[vm]") {
  std::string bytecode_str = "60ff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push14______e89970db1842ac3d55f3232afd30ad13312c950177efca5c2e0ba3214e67870a", "[vm]") {
  std::string bytecode_str = "6d2233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("2233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("dup4______3ae9f14681bc189949b3279cfcc0a8e06369fc9d90d5c10f6816471812b623d1", "[vm]") {
  std::string bytecode_str = "600460036002600183600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("04" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push22______c7a093a13117bb9c6133f6327fee327e966a2140103d676578a1c084dc96875f", "[vm]") {
  std::string bytecode_str = "75aabbccddeeff00112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push18______46272027f0bfb84a1015bb9004a39d7826216d18d675d6379d65e3e79c1aa3df", "[vm]") {
  std::string bytecode_str = "71eeff00112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("eeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("dup8______6f166e5bef326158e7739b0a666015fb2d9715948805b1b99540809dcf48477f", "[vm]") {
  std::string bytecode_str = "6008600760066005600460036002600187600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("08" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("swap14______4ccb75f67ac3e9b2d45eebcf12e463dae9d0c3144bdbe71ed36722095ecbd091", "[vm]") {
  std::string bytecode_str = "600e600d600c600b600a60096008600760066005600460036002600160039d55";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push21______2875bbf0680c0472ead156b68b4ef36c49c60cc2b38c0d369f64680528120341", "[vm]") {
  std::string bytecode_str = "74bbccddeeff00112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("bbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push2______03e50e47ef941b3d715799fd5ec14273d095cecc8d55c36444b40cd0667097bf", "[vm]") {
  std::string bytecode_str = "61eeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("eeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push17______e04d7497dcfb1a17c770c42fb9a4d84cef738de77252ec75bb3e945718464027", "[vm]") {
  std::string bytecode_str = "70ff00112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("dup7______9164c3d5aae743abd16b7041da296858da0d16759c2d3ae33ebcc5a63fc8ea04", "[vm]") {
  std::string bytecode_str = "600760066005600460036002600186600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("07" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push32FillUpInputWithZerosAtTheEnd______97c6dc2159c394514d03134cd4d7ab007d5cbd66630603b5a88f095ab95f29ac", "[vm]") {
  std::string bytecode_str = "7fff10112233445566778899aabbccddeeff00112233445566778899aabbccdd";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("dup6______75d72704baab3592b96f045596085afc546c7b6663598d7629249161dc0a7be4", "[vm]") {
  std::string bytecode_str = "60066005600460036002600185600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("06" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push16______93b8df963d8064b20c21fd6d2ec38e8610b82b1c4e6abd66abdc85a85a842827", "[vm]") {
  std::string bytecode_str = "6f10112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("10112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push3______07386593821578410dec2cc7fd7fa6b3ec0bf4dd1432dce10a66cf510523c741", "[vm]") {
  std::string bytecode_str = "62ddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("dup16______4a6afa1042040869ee0ca80f1a089430650b1fcb7fe06a182beec6573cd8621b", "[vm]") {
  std::string bytecode_str = "6010600f600e600d600c600b600a6009600860076006600560046003600260018f600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("10" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("swap1______9947c63cb21668a1bc833b1421f2b27c94869a07528394c7b08586cac92bb8b1", "[vm]") {
  std::string bytecode_str = "7f10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff60039055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("03" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push32Undefined______c5eb519d971fc829741f24376f38ed1ec4e8b3bda89c1edde8ff7c77268f5956", "[vm]") {
  std::string bytecode_str = "7f010203600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("push20______f0d95eafed710e98a32bea9f87771d93518f17b5c4b4276b85ba12d70d58dd7c", "[vm]") {
  std::string bytecode_str = "73ccddeeff00112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("swap15______b76feedef6e378c9df2722f2e63fd8103db788729de5f3f941aaa5e6b2a59a9c", "[vm]") {
  std::string bytecode_str = "600f600e600d600c600b600a60096008600760066005600460036002600160039e55";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("swap6______d5c33d7cb59842ed6f86031de4050c194534f125a2126e69c01ef662e71c7ecc", "[vm]") {
  std::string bytecode_str = "60066005600460036002600160039555";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("dup11______d54b150f74faf24dbb3288c5c2343a5640d47d09ad2cad7c1e05d32a00139438", "[vm]") {
  std::string bytecode_str = "600b600a6009600860076006600560046003600260018a600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("0b" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push4______830bd0d331f6bfc2fd8e1977ba30d1e7b359397714d414207f0a62a1ca2370d3", "[vm]") {
  std::string bytecode_str = "63ccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push11______70ae0190ed5fb932a7ad6626fabd9fabc1d0afdd7a32d63adce68d86092c63d0", "[vm]") {
  std::string bytecode_str = "6a5566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("5566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("dup2error______de71b4a383746d454f73d98244eec6c4ccc89fbb3c77ad3a8e1f4bee2b104c17", "[vm]") {
  std::string bytecode_str = "7f10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff81600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("dup1______e7b9288ecb9f8e8021e319ae0e7116acf5934f12b95a9f4e923fe356b71e8cde", "[vm]") {
  std::string bytecode_str = "7f10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff80600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("10112233445566778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("swap12______3f50ed713331e02d6566d694aded7f56f52a4e0e158a35e66ec89669f9ec7665", "[vm]") {
  std::string bytecode_str = "600c600b600a60096008600760066005600460036002600160039b55";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push27______f869a2e724e3dc60a9de54f9eda2c4b4f50823ae979e645bf44905df36b89876", "[vm]") {
  std::string bytecode_str = "7a5566778899aabbccddeeff00112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("5566778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push31______f93339c6cf8aae8b47c31ca25032cc05154361b77a4f844fac3ea2854ef55e0f", "[vm]") {
  std::string bytecode_str = "7e112233445566778899aabbccddeeff00112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("112233445566778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push8______bd93b9780c53aca4d7ec72f9636a485ee7056a23dbc0f13fa44eb38a03e728a9", "[vm]") {
  std::string bytecode_str = "678899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("8899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push9______719e7221544d5478ac49ed63e0c80c06b5b4177c3b777a7612b65b8516cc5ba5", "[vm]") {
  std::string bytecode_str = "68778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push30______236223536f879e3412159fcc6e2de0376009d47a03b763cee0cd93ea43835eee", "[vm]") {
  std::string bytecode_str = "7d2233445566778899aabbccddeeff00112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("2233445566778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push26______4553b78606f97fcbaf3c1a88cee84db0095cf08d254ed679f3af3d79b2f55b22", "[vm]") {
  std::string bytecode_str = "7966778899aabbccddeeff00112233445566778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("66778899aabbccddeeff00112233445566778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("swap13______61e6f3f3f7163e13eb94244e435798bb04efb7f219ddabaa29b20f6561867764", "[vm]") {
  std::string bytecode_str = "600d600c600b600a60096008600760066005600460036002600160039c55";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push10______0eab62f5133e7161bd1e2c8cf609b007060a17f0d985c5911e85a39107573385", "[vm]") {
  std::string bytecode_str = "6966778899aabbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("66778899aabbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push5______8ab94cf0099a8c2ebe5cc7a7c235e4cf167b35e8a54dcc35a7b4e328877a1502", "[vm]") {
  std::string bytecode_str = "64bbccddeeff600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("bbccddeeff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("swap7______cb70e89a4bb85d521668d0b0b2f50e2e94271bfd78d457b38215c31980c34cef", "[vm]") {
  std::string bytecode_str = "600760066005600460036002600160039655";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("dup10______63492541583da57d2792ec1c9af921370d1b4a5e583c88df55ee5c8f7b54e07d", "[vm]") {
  std::string bytecode_str = "600a60096008600760066005600460036002600189600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("0a" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("push1_missingStack______28a9f042879f16ed880928a48c2a64ae9a5b3730def5ec03fe73944d1ec6c5ee", "[vm]") {
  std::string bytecode_str = "60";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("slt1______ed3559af4c3e3d1f16995417fd3ce8b2d5d289b2debd9d34e7d103af59a64f4a", "[vm]") {
  std::string bytecode_str = "6002600003600012600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("or2______2c00a57a80d580130b60d9deda2890eccef876d65ea95b4c43bbb1a4dd0cecd5", "[vm]") {
  std::string bytecode_str = "6001600317600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("03" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sgt3______46e9db07c8df7ae98ca90780aeaf1b5a64a02cda8b54068c021dd897d8c56ab5", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600013600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("xor2______cbff7fbed032981ae1743bb8965aaf666a481933ad201acde2a755b4e24ee7d7", "[vm]") {
  std::string bytecode_str = "6001600318600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("byte4______2ada67be185a5b95ca62844c81c52e64b00614d02b64cbf9253baf2a7566e2ae", "[vm]") {
  std::string bytecode_str = "6780402010080402016004601f031a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("10" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("not5______0748608e64f72417803be26086c812c31a590a1a95f26e9af0bedc573bddf7e7", "[vm]") {
  std::string bytecode_str = "600060000319600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("eq2______ae4e87a6dad61b0aa93103ef5906eaeeb3733413e00cb1d2524ee7119383b375", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff14600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("byte8______d8241a95a99ed5c0c39a8d26a9c809b0f62d56817af1fba2368cd2400f2e17a1", "[vm]") {
  std::string bytecode_str = "678040201008040201601f601f031a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("and0______53831e569b6ec2b12b840d539617bd382a07e3700db75ba43d88b45c488abeea", "[vm]") {
  std::string bytecode_str = "6002600216600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("and1______d92d694f1df1088e777abdb7e6a441d9c71e4e634886410c4c65bff718a6f675", "[vm]") {
  std::string bytecode_str = "6001600216600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("byte9______29129062d256e9717217835274e382615224df82e97c8567aa472d206a2e4111", "[vm]") {
  std::string bytecode_str = "6780402010080402016020601f051a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("not4______aee8ec9908daccb907c7076b988b58caffaa8ba68141534a0767d041fbfcb729", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60000319600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("byte5______c2f04b6c8ad9f10c1c6302aaa1b1faa4bb90e700d062d6cf2ad06f7f8009d115", "[vm]") {
  std::string bytecode_str = "6780402010080402016005601f031a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("20" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("xor3______2e67a0c6dbf54b8eaa761a710775d8f516fb5d4afff97ec05f2bf2b0ca89e9a7", "[vm]") {
  std::string bytecode_str = "7f0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff18600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("fedcba9876543210fedcba9876543210fedcba9876543210fedcba9876543210" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sgt2______b9b0e8560b1da602351ee89d9385bd7bd33d19a5e4bc4ae1dbddc76ebf87a0ad", "[vm]") {
  std::string bytecode_str = "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff13600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("or3______e86a2ab7088faca5e880fab11b2cf61601e941f621330eceec13296405f02e2b", "[vm]") {
  std::string bytecode_str = "7f0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff17600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("slt0______2fa0aa23a17f6f906146df0f152b09727ed44e560ba9ca9b357285f2ec0b38c3", "[vm]") {
  std::string bytecode_str = "6000600260000312600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("not3______98f29555aca23bee7693ee4962daafe489d8c024dfc8db3da4252ee438d15d64", "[vm]") {
  std::string bytecode_str = "600260000319600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("lt0______3f82794b3ab7a1381f800f045fe2a52a2c742a5bf5a0c262cfb6be574d305879", "[vm]") {
  std::string bytecode_str = "6000600260000310600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("gt2______4b0191dbc7944ec9b47ede8560ad03500238397635dc897707fd45937b0d762b", "[vm]") {
  std::string bytecode_str = "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff11600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("or4______0529771970ae1453127c9560e68b8274a9662ddf5684bdc7c6a5bd925fedbd27", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee17600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("xor4______c3087ab19e23a572ebb996067c96ae4e3a83fbfe7a3253e347130c9767afb7be", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee18600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("1111111111111111111111111111111111111111111111111111111111111111" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("byte2______88e635fca6798de38b2831eaf5aa1d7ccc10a703006fc531c431a07a6f0ad9b7", "[vm]") {
  std::string bytecode_str = "6780402010080402016002601f031a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("04" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("byte3______f182ba9431c0afa8951345caab69362ef0d08befe7af3ba46c0150f194528281", "[vm]") {
  std::string bytecode_str = "6780402010080402016003601f031a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("08" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("xor5______208791127a38c44787ac9739f8e2d42eafcc94924b718326bb2f41c0641fe68e", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeefeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee18600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("1111111111111111111111111111101111111111111111111111111111111111" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sgt4______952942a91ed7040913a6bb27488e09877b1c0eff4b14fcc9e515f8ffde6a2016", "[vm]") {
  std::string bytecode_str = "6003600003600560000313600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("or5______4c9eb19946147a54071f850e4812bd9b75e200b344b9bd27cb1d8af2c4674933", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeefeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee17600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("gt3______2c4b8f3a0bd648007898638b2bf6ab5f170741704abc751161d5f90f0494d666", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600011600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("lt1______63a727c86d3f482ccf6a02dbded8c26b306938192e9a6008f4ad74c7a5efd8fd", "[vm]") {
  std::string bytecode_str = "6002600003600010600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("not2______324eba656aca54db2f9828012cc52c412e67ea3976e1e806698486b3f755b5eb", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff19600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("and4______e21e8e11b9513679c36fd3f2877d5ef73d302169e669d42569e9b28e07ee85f5", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee16600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("gt0______c17427d3c9acd0c27322e9bb49e967e2240aa803764c4ccf202d94ef4cb9939c", "[vm]") {
  std::string bytecode_str = "6000600260000311600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("iszero0______c7730a4eae5d80429b5e6a822a0c8c4dc6bece946d3d6902a5fddb2fc120fa04", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff15600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("lt2______2e2c7923db8f0fc63497824b409ae8c0eba04c0e352fe50ae0a5cc00469d9498", "[vm]") {
  std::string bytecode_str = "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff10600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("not1______986682dadca33278653a19f30a97e9db367c671a612d67a4535d20510e2d625e", "[vm]") {
  std::string bytecode_str = "600219600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffd" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("byte0______ca8eddefff06f7e6cb91dd60e11a7dd107ced29e7c88ef06da7952e8cfd38d45", "[vm]") {
  std::string bytecode_str = "6780402010080402016000601f031a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("slt4______ed936fea46872027bbe365872786c5ab0e1356dfae7bc9c81150fdaa86cb443f", "[vm]") {
  std::string bytecode_str = "6003600003600560000312600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("byte1______bb1c4e33835be3cbddbd232873e7ee350b4f971f725bf3b1c56c7e4f456d690a", "[vm]") {
  std::string bytecode_str = "6780402010080402016001601f031a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("not0______3235e2a1af7340deea07b964fc3532b19092832b2c9592d3c777a659e97a01ba", "[vm]") {
  std::string bytecode_str = "600019600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("lt3______ba2bc4205d1ca31e29315edfc5708f300f44cb02936b9da05a9097b26f97d71a", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600010600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("iszero1______1fc0ad71c14401598db2286ee499a76e21de97cbb63ee987afd5f603d34ef903", "[vm]") {
  std::string bytecode_str = "600015600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("gt1______98d2099f8676c20a4806282a1fbe0968231046a99e137070724adbc117447290", "[vm]") {
  std::string bytecode_str = "6002600003600011600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("byteBN______43da3e8490c4e2724415c26642284184fbbcb7e128d59d7693386f3da3c2d08e", "[vm]") {
  std::string bytecode_str = "641234523456601f1a8001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ac" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("and5______1bbd8a8b90a8f84cb52e9514c9a02cd594e6e731065b54087cfa7afc9ccd2fc2", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7feeeeeeeeeeeeeeeeeeeeeeeeeeeeefeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee16600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("eeeeeeeeeeeeeeeeeeeeeeeeeeeeefeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("byte6______2f99689c10d739d33cec8c8062c608a1b01c61686ca12f01d2e9fe2b73d1ee0f", "[vm]") {
  std::string bytecode_str = "6780402010080402016006601f031a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("40" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("xor0______e08c105ef68171d063c469dd9b2a23da11aac894df3ee20271da79681250fc9b", "[vm]") {
  std::string bytecode_str = "6002600218600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("sgt1______671a4ef36d8c59426ca6b9eeb8cc46cfb41716888e2f2df3852eb03e9c14dbb1", "[vm]") {
  std::string bytecode_str = "6002600003600013600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("or0______dcc4012a46120cba05d501bbffe31a249fd5445b29b3f7e8e2133e9098e735e4", "[vm]") {
  std::string bytecode_str = "6002600217600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("slt3______32f573a07264be5090d1b383aac1d8803ab95f9420e0d8a849de627095f954ee", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600012600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("and2______b8c8c36bba987b4b5e5172ea00931076b8169ff8a8ff0d48244637c3dbe1eba1", "[vm]") {
  std::string bytecode_str = "6001600316600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("byte11______57be2a02bebea1ac84a6d1bbb3f15f0ab9d9339fa706131cd052c9275a0ec871", "[vm]") {
  std::string bytecode_str = "67804020100804020160001a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("iszeo2______4e5ea4236cff2cb1176ad44dba65cb26dec72438acaa1e35600292b1bee87a71", "[vm]") {
  std::string bytecode_str = "600260000315600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("eq0______e9cd05b4ad632b287637f3682cb5bd3d39957b0a859fcaf2740c3a84bff603f2", "[vm]") {
  std::string bytecode_str = "6003600003600560000314600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("eq1______71d72425d2c1777c6991d09b38aed473c3dc3b9b370b8397c0d48e68a29b3aac", "[vm]") {
  std::string bytecode_str = "6000600014600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("byte10______866a8493a1363ce7e4595429147e8892ee6abb300fe15732d93c8d6b5c3c84f7", "[vm]") {
  std::string bytecode_str = "6780402010080402017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("and3______d37be2fe655f6f4348e3ab48e7b0f832505ab4800835a50e516c726bc6f59cf1", "[vm]") {
  std::string bytecode_str = "7f0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff16600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("slt2______92e953b3e18b0939fd97afb7875129e10860293931b9cb840b50f1559489ac16", "[vm]") {
  std::string bytecode_str = "60007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff12600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("or1______791c257002ce8dd940a5391775fd4eac1836f7eb55304f658a32485f79d4993f", "[vm]") {
  std::string bytecode_str = "6001600217600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("03" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sgt0______c5194500b062e2d1bf6dd6607185c661b6500d51c7146603f7f4ed31795b5d23", "[vm]") {
  std::string bytecode_str = "6000600260000313600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("xor1______417302c7876ef9a5209b50fcbd9ea4a70ca3d74748ed4f92f0c3164c0584c313", "[vm]") {
  std::string bytecode_str = "6001600218600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("03" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("byte7______c4d404f87e398a368fb2b0cb2165358ecdd92a97a2bbffcd0f8e833fc942976b", "[vm]") {
  std::string bytecode_str = "6780402010080402016007601f031a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("80" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("gaslimit______f1250fd89a1c3e517ae92cc1f73865c594bfad34db20f3b3396af4efe19d3bfb", "[vm]") {
  std::string bytecode_str = "45600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("0f4240" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("number______404caf239c3e0ad4394c1417b728d10e1f68a8eee3963425d9e391f4f3ec023c", "[vm]") {
  std::string bytecode_str = "43600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("difficulty______30c06d1988994e3f4e738e60b1e0d6b8734fb576e3b2580151251c5f058fa9c6", "[vm]") {
  std::string bytecode_str = "44600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("0100" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("coinbase______9f5df0c263c2b48fbf48db70ec64ddf3efa5f1651ced1fedf933ee239e9c851d", "[vm]") {
  std::string bytecode_str = "41600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("2adc25665018aa1fe0e6bc666dac8fc2697ff9ba" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("timestamp______44c8782a2b04af7092f76bfa83b1cb24e590722db220b32a52e4e249e596def4", "[vm]") {
  std::string bytecode_str = "42600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("jumpAfterStop______1527b83fd9a930436902b171302c40812a33a035bf148e5c40f362e811b1ad54", "[vm]") {
  std::string bytecode_str = "6006560060015b6002600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("JDfromStorageDynamicJump0_withoutJumpdest______696ced07844f15bee009a7c294048b5bf531923787279c19bf1c3150a46bf0ff", "[vm]") {
  std::string bytecode_str = "6023600760005401566001600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("DynamicJumpStartWithJumpDest______4fb19acd65703dce630cb655f52e98d2de72d8a790d53b895d0e7bce603d4166", "[vm]") {
  std::string bytecode_str = "5b586000555960115758600052596000575b58600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("12" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("jump0_jumpdest0______4bf0cfbeda98acdd577972c6a7abcd20f60ab1b48328ce3f804e3cefa7c77bdb", "[vm]") {
  std::string bytecode_str = "602360075660015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("23" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sstore_load_1______28c5c7cfbcf28dd967743a82487d71c5d17eca75a90f019d227970c0ff927155", "[vm]") {
  std::string bytecode_str = "60ff60005560ee600a55606454601455";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);

  // then
  CHECK("ee" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("ff" ==
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("loop_stacklimit_1020______e3a67d3fc9f35b9e0db39be074d9160030b23790e568d0387f9d8f7e4190e40a", "[vm]") {
  std::string bytecode_str = "6000345b60019003906001018180600357600052600152600059f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("msize0______41daa7a08f4c4f0380b60446927c8a3d3f077fdd63de63ab8736353cf7c92d86", "[vm]") {
  std::string bytecode_str = "60ff60005259600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("20" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("jumpiToUintmaxPlus1______58d51b8cb46082033f726f1bca929fb1713048436d52029e31f5bfcaaaded691", "[vm]") {
  std::string bytecode_str = "6001640100000009575b5b6001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("mstore8WordToBigError______e7f6dfe7bcd73d4ee7ec71238711bd20d21eafc11b4b5e6c54ed69b2daf3c8bd", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600153600151600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ff00000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("jumpInsidePushWithJumpDest______d200f4e72a16a6960609912d97797b467afb3a98c1eef6f9eed2006c4111a7f3", "[vm]") {
  std::string bytecode_str = "600456655b6001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("DynamicJump_value3______a1477eeb656e1f4d09c07f020a088cc099f6661fce88f137754b1d45550d7218", "[vm]") {
  std::string bytecode_str = "60016002600334565b5050600052596000f35b50600052596000f35b600052596000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("indirect_jump1______33d6b4fa4d999fa02f0b584e925eef1e0b1f55bfe6bd8ba3bd0339ab20739a34", "[vm]") {
  std::string bytecode_str = "600460030156005b6001600052596000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("JDfromStorageDynamicJump0_AfterJumpdest______06126bb58e44948750e412ea81a3140fcc72b63acec0090939706f3ceb403ae8", "[vm]") {
  std::string bytecode_str = "60236008600054015660015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("DynamicJumpJD_DependsOnJumps1______853f3f35881b9db63508e68d34cf87a1a3697fdc969821c0659462242d859c2b", "[vm]") {
  std::string bytecode_str = "600a436006575b5660015b6001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("DynamicJumpi0______394cae3e06d120cc1a5df5e14cfae3598d62e1fefa06dce4055c6ff59c367b63", "[vm]") {
  std::string bytecode_str = "602360016009600301576001600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("DynamicJumpi1______31d323d1c24dd2c2ea5a4e18fd0765bfa1be189add7e395b2679bf5a98e492ab", "[vm]") {
  std::string bytecode_str = "602360006009600301576001600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("DynamicJumpJD_DependsOnJumps0______e96143bec9697fb0d565026f5fcc5ed70833bf89eb8c63aa87e0155b4e61d8f4", "[vm]") {
  std::string bytecode_str = "6009436006575b566001";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("DynamicJumpi1_jumpdest______fb4060a7f68c0f3ad9643dcfc93fa90ea0fe6123e65499ae65f400e22db20bcc", "[vm]") {
  std::string bytecode_str = "60236001600a6003015760015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("DynamicJumpiOutsideBoundary______d550aa41047204857f27b7a80a1309520f3e59b41a87ef3e40492032706e5a88", "[vm]") {
  std::string bytecode_str = "60017ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0600301576002600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("codecopyMemExp______baf738ce30cb457d16aa2f71f866ce00ddb998371757f2c6a30a5d1ca3a9e135", "[vm]") {
  std::string bytecode_str = "60ff60ff630fffffff630fffffff39";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("DynamicJump_value2______00631169ba52dbbd3d7ac8529dd960c6b297226c0f177ee3e0ef8bd202b4b1ff", "[vm]") {
  std::string bytecode_str = "60016002600334565b5050600052596000f35b50600052596000f35b600052596000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("return1______fe0798e0775da11e784482b44b51322ad70f4deaa8ce8643841257d3abee2e1f", "[vm]") {
  std::string bytecode_str = "6001620f4240f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("mloadMemExp______b12ca5b81a2d597d774f63fd3e6301a3808c7090e1b5ee00ea980c846ddadf32", "[vm]") {
  std::string bytecode_str = "630fffffff51";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jumpInsidePushWithoutJumpDest______451d199b9c77c3a3297bb20ba2a01c238e984283e3690b22c9614121c878d8ec", "[vm]") {
  std::string bytecode_str = "60055661eeff";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("JDfromStorageDynamicJumpifInsidePushWithoutJumpDest______561fed985eda1bbc4448ad363f6fa69a1d1b503d9d7e0017bcd49aaaf916f333", "[vm]") {
  std::string bytecode_str = "60016007600054015761eeff";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jumpOntoJump______b7af74ccb70e4242810a2f47181f0c95ee1b9558385cff3a33896f29c7775d7e", "[vm]") {
  std::string bytecode_str = "565b600056";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("BlockNumberDynamicJumpifInsidePushWithoutJumpDest______3fccd0c56ebfd40dea69fec03d009967a80ddf93e9a68af81efd2d1645e27fcb", "[vm]") {
  std::string bytecode_str = "6001600743015761eeff";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("DynamicJumpifInsidePushWithJumpDest______05f764377385769e93afe47dbc0293921c211b4e68afce30f18cba4bb5955420", "[vm]") {
  std::string bytecode_str = "6001600660030157655b6001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("JDfromStorageDynamicJumpInsidePushWithoutJumpDest______53a491adcc7da05748ad36809954552784007b884cd960e05ebb07a2ddd0452b", "[vm]") {
  std::string bytecode_str = "6005600054015661eeff";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("msize1______1bc7a7187b3aa498df95faec7fa0258d950df3afb6205db0f9e2997ffb7ec512", "[vm]") {
  std::string bytecode_str = "64ffffffffff60005259600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("20" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("DynamicJumpiAfterStop______d61d45e9d5ea3e13d2a8a33965c9c620207156e0b4baf2dfed9a0288c7e8053b", "[vm]") {
  std::string bytecode_str = "60016008600301570060015b6002600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("jumpHigh______a7725bef6c1ff691ae5ad3b73c3b44a6d16f9c9b1c0e57671d7ff59fe9ac9800", "[vm]") {
  std::string bytecode_str = "630fffffff565b5b6001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("loop_stacklimit_1021______c1bb4f6ff68cafca82606ffe4fbed88358dc3b19be5e69714e96478d8571c0fc", "[vm]") {
  std::string bytecode_str = "6000345b60019003906001018180600357600052600152600059f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("bad_indirect_jump2______6dd2730ab6f27b43eead1633f104f5d60d6a98fa7c81d5a8ba0d2f6434706813", "[vm]") {
  std::string bytecode_str = "60016003600302576000600056";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("sstore_load_0______371f51e169fa8f7740cef83f469ff5f02034d301d027b0267cd999c9ea5ca633", "[vm]") {
  std::string bytecode_str = "60ff60005560ee600a55600054601455";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);
  store_item_t item2 = Utils::accountStoreValue(2, accountItems);

  // then
  CHECK("ff" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("ee" ==
    Utils::uint256_2str(item1.second)
  );
  CHECK("ff" ==
    Utils::uint256_2str(item2.second)
  );
}

TEST_CASE("jumpTo1InstructionafterJump_noJumpDest______91502d2804896fda92630c93005fc5c0e26591bac75b7fff576409271f81cdb6", "[vm]") {
  std::string bytecode_str = "6003566001600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("for_loop1______5e12e078316618a30275a5c133a960d17d242cc3726855a805c112193d39a59e", "[vm]") {
  std::string bytecode_str = "600a6080525b6000608051111560265760a0516080510160a0526001608051036080526005565b";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("DynamicJump0_jumpdest2______a7e9d9f046151930ef4b51b8dacce5304ce74c3f5ead80f1e52f783b1a704378", "[vm]") {
  std::string bytecode_str = "6023600a6008506003015660015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("23" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("mstore0______78e3311be5943f4a7995e11b3fe7e41fa432fae150d687201c617c70ae40f6d7", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600152600151600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("JDfromStorageDynamicJump0_jumpdest0______2f836ba88951147677580e5de7d8d40b0ca72938894aa351096945d7962c8f62", "[vm]") {
  std::string bytecode_str = "60236007600054015660015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);

  // then
  CHECK("23" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("04" ==
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("BlockNumberDynamicJumpiOutsideBoundary______db80ec0400be086e2a316a91ee7a5f87db06ff6a5b0ad27a50ba692049a54b1c", "[vm]") {
  std::string bytecode_str = "60017ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff04301576002600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jumpifInsidePushWithJumpDest______790a546e29160af651f091890cd367d79d28b345f43847fa5d19b6a0dab087e9", "[vm]") {
  std::string bytecode_str = "6001600657655b6001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("JDfromStorageDynamicJumpInsidePushWithJumpDest______561a67bc9db1011fb26151b03adcc53b2f4f55e03292c1e98e3361250c87d38a", "[vm]") {
  std::string bytecode_str = "60046000540156655b6001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("BlockNumberDynamicJumpifInsidePushWithJumpDest______4b52bc3a45a966d0032eb01b3fdb8a225af48fa4f5a017b5dff3d4d88d710337", "[vm]") {
  std::string bytecode_str = "60016006430157655b6001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("DynamicJump_valueUnderflow______37f012edfeaa13e4819617af0e8dc2fd71d738a2463b1f61bfd86de0ef980f1b", "[vm]") {
  std::string bytecode_str = "60016002600334565b5050600052596000f35b50600052596000f35b505050600052596000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("DynamicJumpInsidePushWithJumpDest______3f3586292e12e696029f38f833fe8c7cea86a0e7cda83c0cbe783aa2c3b22b0c", "[vm]") {
  std::string bytecode_str = "600460030156655b6001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("DynamicJumpPathologicalTest1______dfbad553b0e28f37f6a5d72740e2ae6bf17ce1b19c62caf2cc2a99c0d1d84e05", "[vm]") {
  std::string bytecode_str = "435660615b4343025660615b60615b605b6001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jump0_withoutJumpdest______4023b9b32fabb7baeb154e319422cc24e852c858eb124713508a241df86f3969", "[vm]") {
  std::string bytecode_str = "60236007566001600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jumpToUint64maxPlus1______17b7f86769171233d32af7b23fc33ba8e71f03a64f0625aadfe65a696dff36a6", "[vm]") {
  std::string bytecode_str = "6801000000000000000b565b5b6001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jumpi1______27f04b183d459deb05bc15b1281b0e300307950da1968f669bd8cbec2b200044", "[vm]") {
  std::string bytecode_str = "602360006009576001600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("mloadOutOfGasError2______8df8c3070849692634e4e7af44885da9c5d41df0717fd6d337aa7d5bfed56d52", "[vm]") {
  std::string bytecode_str = "6272482551600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("BlockNumberDynamicJumpInsidePushWithJumpDest______ca0f21a5f52a8d4f2d6e1eed650f68d5f8f40e567cf17984aacc228adfa578ab", "[vm]") {
  std::string bytecode_str = "6004430156655b6001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("DynamicJumpifInsidePushWithoutJumpDest______cadedb13e141e3b7bf1f0763cc831dace3ff150fc623e81fb00e798168d01188", "[vm]") {
  std::string bytecode_str = "600160076003015761eeff";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("mloadError0______27a14368a9e5b964986445d0436e67f685ab0171ea0359b9a112fdc07d98bf53", "[vm]") {
  std::string bytecode_str = "600051600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("DynamicJump0_AfterJumpdest______605f607251cd4a7c73bd7c814edcada6a9008fcd2896af2caf371beb31db196b", "[vm]") {
  std::string bytecode_str = "602360086003015660015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("JDfromStorageDynamicJumpiOutsideBoundary______3c7f35eb2fe3c2ed05679b25f89e81e50fa959c8a665cf4545552f75a3b7140b", "[vm]") {
  std::string bytecode_str = "60017ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff060005401576002600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("mloadError1______f5841cfbab0e35ad5727493bc7b6e0cd075735640637e817001de707085c2608", "[vm]") {
  std::string bytecode_str = "6017600152600051600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("jumpToUintmaxPlus1______6897e3a469257a7905bf719e9ae36ac49f830eab122209a9c2e89c879cdaa2d7", "[vm]") {
  std::string bytecode_str = "640100000007565b5b6001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jumpi0______86fb0cc0becb3234b287df55e90da9a860eff30714976e3395b25ee2e2b47c48", "[vm]") {
  std::string bytecode_str = "602360016009576001600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("JDfromStorageDynamicJumpifInsidePushWithJumpDest______f15ca2a706c969bb0f9f4b7101efd666eebae5520f893a586a7a529b0dc7d4d8", "[vm]") {
  std::string bytecode_str = "600160066000540157655b6001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("DynamicJumpPathologicalTest0______6862ac2a8fad0b3c043493fcd9c9a7e8a549c9f3ef34019ac0d7bcfd096a8040", "[vm]") {
  std::string bytecode_str = "435660615b4343025660615b60615b5b5b6001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("DynamicJump0_withoutJumpdest______84c524e0cafc2ddcebdef720e46a23d10061f4a35bb06bfe7bdfe444990593a6", "[vm]") {
  std::string bytecode_str = "60236007600301566001600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jumpTo1InstructionafterJump_jumpdestFirstInstruction______1e05b7560aba357248c8fdddd62e9b8dfb943cc2c3bb9569c5d44c2322899ff4", "[vm]") {
  std::string bytecode_str = "5b6003565b6001600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jumpifInsidePushWithoutJumpDest______c69048c65f19388408ec0027e2c9372b393d057d91c9e0eff2ea96f8bb59f66b", "[vm]") {
  std::string bytecode_str = "600160075761eeff";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("mstore1______424433d76d1f8d1622fa9796c232dbd9f31ddc1231efae876f6494ee7d1ccab2", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600201600152600151600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("jump0_AfterJumpdest3______dc15eff9141416358f3f9960ef23b930d70b7cb8d3e13d7d5b6832954605d062", "[vm]") {
  std::string bytecode_str = "6023600b6008505660015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("BlockNumberDynamicJump0_withoutJumpdest______6f1fc4a9e5dff3e5d3071c576aba5b2ee1f30d7dcace92e6c6d230cfd415efd7", "[vm]") {
  std::string bytecode_str = "602360074301566001600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("BlockNumberDynamicJump0_jumpdest0______80bfa0a5db107e6f083dccdd3091e35add39a4eaac4a8757de8a3e4008c5d646", "[vm]") {
  std::string bytecode_str = "6023600743015660015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("23" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("DynamicJumpPathologicalTest3______a906b3dcb41da1cdacb67bdf49111ecd2bdaab0e3584dbd3993ef0f0555766f6", "[vm]") {
  std::string bytecode_str = "435631615b60615b60615b606001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("swapAt52becameMstore______b014aac7021775f56b763921bf12a663ca35c4aa230888cd7908edfa705b1413", "[vm]") {
  std::string bytecode_str = "600260035255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("calldatacopyMemExp______fcf33988ecf7e66eae80382111d1128eb302e201be169ca20b306eac49231142", "[vm]") {
  std::string bytecode_str = "60ff60ff630fffffff630fffffff37";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("mstore8_0______0a5e67d6603b41a69f94c4d3dcc06da69c17c841ba0cdc8e15a5203e89d217a7", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600153600151600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ff00000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("JDfromStorageDynamicJump0_jumpdest2______efe088c5366793bcb3339225486608b15750524274baf8d5f9f592c0d5e327f2", "[vm]") {
  std::string bytecode_str = "6023600a600850600054015660015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);

  // then
  CHECK("23" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("04" ==
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("DynamicJump0_jumpdest0______3ab9d036e3e345909b19022f4c3b80d081d214eb5c79b8e94e0f2c660ab01ec7", "[vm]") {
  std::string bytecode_str = "602360076003015660015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("23" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("DynamicJump0_AfterJumpdest3______b7367314ce66b1a937c05550ac901971b5850d2a0ef03acf1feb4d6c9f38925d", "[vm]") {
  std::string bytecode_str = "6023600b6008506003015660015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jump0_AfterJumpdest______8e933f0185d188f6eeb002d4ac8dace70a34a196e4c59932957eaac4cef27849", "[vm]") {
  std::string bytecode_str = "602360085660015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jump1______c86900065dc3ca2743c247f2c7f305795833184ab64acf0c6911a899533ab628", "[vm]") {
  std::string bytecode_str = "620fffff620fffff0156";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("deadCode_1______110e1eaddae6dda0225d4f4b430da33494473d9ec10d765e7a5324d3e1ab26c8", "[vm]") {
  std::string bytecode_str = "6001600053596000f300000000000000005b00";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("memory1______4962a1d10a8792cd1ad8a08ac500002adec8cc965fd1fb4d1c45cb3e558a9de6", "[vm]") {
  std::string bytecode_str = "600260005360036001536000516001510160025260406000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log1MemExp______241dbcb0d33d25f1db0b51b65c38c4e3ef2f5b52c799264979423508e3fcf934", "[vm]") {
  std::string bytecode_str = "60ff60ff630fffffffa1";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("dupAt51becameMload______28d2da26fb721ff16c42b1d398e7410f85560c3373bcc0a424ee1d025bf25ba6", "[vm]") {
  std::string bytecode_str = "600260035155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("jump0_foreverOutOfGas______06656a40346ccda59a2d1852d9bb59447d34fb9eb80706e378c5a067e337a080", "[vm]") {
  std::string bytecode_str = "5b600056";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jump0_outOfBoundary______9442ba4b2e4625b3ba5d7a3c43a5c1bcbb0f71fb8977d9cb291a58f956e5d014", "[vm]") {
  std::string bytecode_str = "60236007566001600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("JDfromStorageDynamicJumpi0______14e786db1b2df2c2a40be1a80c61baec311572eb481a3afd1b31fb95a3ad937d", "[vm]") {
  std::string bytecode_str = "60236001600960005401576001600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("kv1______e9c18f1395a9a5e541d26c02b68f69e413953c380102c17d783cc18b5092bbf2", "[vm]") {
  std::string bytecode_str = "33604555602d80600f6000396000f3604554331415602c575b366080511015602b576020608051013560805135556040608051016080526009565b5b";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("cd1722f3947def4cf144679da39c4c32bdc35681" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("JDfromStorageDynamicJumpi1______f90389bdfe2c1600f16db3b5ff8289b55a9f3d2c56dd18403c4e636440a98a9d", "[vm]") {
  std::string bytecode_str = "60236000600960005401576001600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("04" ==
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("BlockNumberDynamicJumpiAfterStop______7331cec587701bf695329ad94c7e62963827209faffac3b24eb59341ccb1a925", "[vm]") {
  std::string bytecode_str = "600160084301570060015b6002600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("jumpdestBigList______6e4f2dfe68bb0ae1bdce8e6385b098b9984176b12f76273d1a1f7e34f46d85db", "[vm]") {
  std::string bytecode_str = "6009565b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b5b";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("stackjump1______21d7234c731f6e2e771b45ce8ba46f258fcfee3c1c1f9060d5246302ef5f151e", "[vm]") {
  std::string bytecode_str = "6004600660096014565b600a03600052596000f35b60005201600956";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("byte1______4bbf3058007fbacf83926bd908a1f886cb4403aa10a95030f2da18e1ad68707b", "[vm]") {
  std::string bytecode_str = "7f112233445566778899001122334455667788990011223344556677889900aabb60001a7f112233445566778899001122334455667788990011223344556677889900aabb60011a7f112233445566778899001122334455667788990011223344556677889900aabb60021a7f112233445566778899001122334455667788990011223344556677889900aabb60031a7f112233445566778899001122334455667788990011223344556677889900aabb60041a7f112233445566778899001122334455667788990011223344556677889900aabb60051a7f112233445566778899001122334455667788990011223344556677889900aabb60061a7f112233445566778899001122334455667788990011223344556677889900aabb60071a7f112233445566778899001122334455667788990011223344556677889900aabb60081a7f112233445566778899001122334455667788990011223344556677889900aabb60091a7f112233445566778899001122334455667788990011223344556677889900aabb600a1a7f112233445566778899001122334455667788990011223344556677889900aabb600b1a7f112233445566778899001122334455667788990011223344556677889900aabb600c1a7f112233445566778899001122334455667788990011223344556677889900aabb600d1a7f112233445566778899001122334455667788990011223344556677889900aabb600e1a7f112233445566778899001122334455667788990011223344556677889900aabb600f1a7f112233445566778899001122334455667788990011223344556677889900aabb60101a7f112233445566778899001122334455667788990011223344556677889900aabb60111a7f112233445566778899001122334455667788990011223344556677889900aabb60121a7f112233445566778899001122334455667788990011223344556677889900aabb60131a7f112233445566778899001122334455667788990011223344556677889900aabb60141a7f112233445566778899001122334455667788990011223344556677889900aabb60151a7f112233445566778899001122334455667788990011223344556677889900aabb60161a7f112233445566778899001122334455667788990011223344556677889900aabb60171a7f112233445566778899001122334455667788990011223344556677889900aabb60181a7f112233445566778899001122334455667788990011223344556677889900aabb60191a7f112233445566778899001122334455667788990011223344556677889900aabb601a1a7f112233445566778899001122334455667788990011223344556677889900aabb601b1a7f112233445566778899001122334455667788990011223344556677889900aabb601c1a7f112233445566778899001122334455667788990011223344556677889900aabb601d1a7f112233445566778899001122334455667788990011223344556677889900aabb601e1a7f112233445566778899001122334455667788990011223344556677889900aabb601f1a7f112233445566778899001122334455667788990011223344556677889900aabb60201a7f112233445566778899001122334455667788990011223344556677889900aabb6107de1a6000600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("jumpTo1InstructionafterJump______88eb8cc46a28df3e813fc9d859aaa7c10bd7246272ed7af7c7e119e18e7c6592", "[vm]") {
  std::string bytecode_str = "6003565b6001600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jumpi1_jumpdest______ad83573b03f45ffbef8bfcea78a8cb61b1c793b36475000cf9222dea41696717", "[vm]") {
  std::string bytecode_str = "60236001600a5760015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("BlockNumberDynamicJump0_jumpdest2______e86a87e0b5cde7d47f1e5dc295600ecc60b7344b3fb4ad64609d6b87fae642f8", "[vm]") {
  std::string bytecode_str = "6023600a60085043015660015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("23" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("DynamicJump0_foreverOutOfGas______68b687a344b0f44d7459e095f05f6b302ee3f5d15b3c3e7765d5642fb1f46689", "[vm]") {
  std::string bytecode_str = "5b600060000156";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("for_loop2______2764d5106d8f416d7f03ab65334b580f66eff1a74fa4c3fc4b2488dbb621d3c1", "[vm]") {
  std::string bytecode_str = "60006080525b600a608051101560265760a0516080510160a0526001608051016080526005565b";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("mstore8_1______85ba59a62f13c9f29b37207e79bf61c2bfb361b6b703ac5ec0f82801edd6cdec", "[vm]") {
  std::string bytecode_str = "60ff60015360ee600253600051600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffee0000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("BlockNumberDynamicJump0_foreverOutOfGas______0900beba73811b8aafaefadcff3a7cd9954ccb5e4986b9cf03ca44881efd4e9c", "[vm]") {
  std::string bytecode_str = "5b600060000156";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("BlockNumberDynamicJump0_AfterJumpdest______edd08521b4a9bc311f2ba99d15c867d9a98da1e9665d9b173ff85621e170e896", "[vm]") {
  std::string bytecode_str = "6023600843015660015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("indirect_jump4______bec771ce98d114d7dacd0f1f33426b85e6092d65bfd73945ea07831737a0d310", "[vm]") {
  std::string bytecode_str = "60006007600501576001600052005b";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("jumpDynamicJumpSameDest______c1d46387eefa48a995ad56844ced0803c7e2441369d569c7669933b1ebecc2c8", "[vm]") {
  std::string bytecode_str = "6002600401565b600360005260206000f3600656";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("DynamicJumpPathologicalTest2______957bc609a0322452da86a59c96e7eea17c5463dcd7bad6ed97b57c6460a90b80", "[vm]") {
  std::string bytecode_str = "435631615b60615b60615b606001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("DyanmicJump0_outOfBoundary______a2ae635e97f7381a5af1ea432d210faf19f4f84e8e0e6874bd48005674bfea92", "[vm]") {
  std::string bytecode_str = "6023600760005401566001600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("pop1______f87d71b88a272f122f6ea9dbd4680f8b4bf659a1b2bae4634398e6ecdcc9f487", "[vm]") {
  std::string bytecode_str = "5060026003600455";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("JDfromStorageDynamicJumpiAfterStop______80d903064c1050cf1a2e527b8938e610e77822d55c83cf4a07e18586baa0bec1", "[vm]") {
  std::string bytecode_str = "6001600860005401570060015b6002600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);
  store_item_t item1 = Utils::accountStoreValue(1, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
  CHECK("04" ==
    Utils::uint256_2str(item1.second)
  );
}

TEST_CASE("msize2______7a68500c2697ce7d4e5140214c087b3f152770295239abebdae1f81695167994", "[vm]") {
  std::string bytecode_str = "64ffffffffff60005261eeee60205259600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("40" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("DynamicJumpAfterStop______5ba8a9cb65319cdc8e574e0eb59695b55158e6d723945bac3b96573a576a86a8", "[vm]") {
  std::string bytecode_str = "6008600101560060015b6002600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("JDfromStorageDynamicJump0_foreverOutOfGas______a3046ce1b7f78c109aa36c29db004850ad5b3b4129d9085849b7af04b719826c", "[vm]") {
  std::string bytecode_str = "5b600060000156";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("mstoreWordToBigError______25c31b75a7912e1384ff3347dc511c5d1b384e6f40cfb0dffaa65176abcc1613", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600152600151600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("bad_indirect_jump1______15744a7158d6982822dc8a0c272c329f8dfdf93810e8f2f3f468a56db9bd2d90", "[vm]") {
  std::string bytecode_str = "601b602502565b";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jumpiToUint64maxPlus1______43b7965f24cac2b1b88fb4781bccd2cbcdcc1569812c2c9e28ebded71ebd172e", "[vm]") {
  std::string bytecode_str = "60016801000000000000000d575b5b6001600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("mstoreMemExp______eb43769a562c8a34bcb776fd312cc723bf2e8f4e64c75d7d3e36451760d9fd44", "[vm]") {
  std::string bytecode_str = "60f1630fffffff52";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("stack_loop______10cdba5fde4ef3d4d21af05732cf685986623a9055ef0d62dfb00f2a415e9264", "[vm]") {
  std::string bytecode_str = "60015b6001810380600257600053600153600253600353600453600553600653600753600853600953596000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jump0_jumpdest2______3aba479e0b0de29b2fac29ac62deb3e37d9fff0a79ed3a1953a7afa7e19b17da", "[vm]") {
  std::string bytecode_str = "6023600a6008505660015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("23" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sstore_underflow______805b307827e4870e9e3bf9655a71a4ca5c327223280c4c3125522d053732de4b", "[vm]") {
  std::string bytecode_str = "600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("JDfromStorageDynamicJump0_AfterJumpdest3______52880726a50d86ffdaea78e4a5d3293643688543eea049172fbf51e564f28f5b", "[vm]") {
  std::string bytecode_str = "6023600b600850600054015660015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("BlockNumberDynamicJumpi0______620bba922f5a1732f512d726a26e71b09d3837018a66a9aacb581b212a4f4b13", "[vm]") {
  std::string bytecode_str = "6023600160094301576001600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("indirect_jump3______1ca405a29132ed02b16a4e4f1d869eb73904f23759d971c3a7e287260fa13f7b", "[vm]") {
  std::string bytecode_str = "6001600460050157005b6001600052596000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("DynamicJump_value1______20503c4d21019e3d9d87b95365a0d0417fb7e163265f938d6e3f685377a2c5da", "[vm]") {
  std::string bytecode_str = "60016002600334565b5050600052596000f35b50600052596000f35b600052596000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("return2______dbf688e0c2f5f4907b91cf9d71f3dc94ccbdcd3153ece4d2017e0367c0f0ef66", "[vm]") {
  std::string bytecode_str = "6001608052600060805111601b57600160005260206000f3602b565b602760005260206000f360026080525b";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("BlockNumberDynamicJumpi1_jumpdest______420810639c740487f7b8d18b29f28dcfb7d762b1aa4aa9b9f8b91928da66a539", "[vm]") {
  std::string bytecode_str = "60236001600a43015760015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jumpiOutsideBoundary______7d536d76f1c00c063b374bdcd155229427e5fe4867ae5ac41d42516c88ebff0d", "[vm]") {
  std::string bytecode_str = "60017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff576002600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("mstore8MemExp______df32f3b06a7e748f5fdd93a878f7687f4f28864f8a5956d8e3a4fff7463b47f0", "[vm]") {
  std::string bytecode_str = "60f1630fffffff53";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jumpi_at_the_end______db58f5762f6dccaf9a4daa5053fe18bc36fc597c379acbbb8dc7d41897e0fd1b", "[vm]") {
  std::string bytecode_str = "600a6000525b6000516001900380600052600557";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("gas1______158673d626e8f5b04cbad00e6bcf8bce2a081b61bf98ca0ad11b78e52921444a", "[vm]") {
  std::string bytecode_str = "5a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01869e" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("pc0______824c240179768ed6999ca7357c185b25d2368e5526cde066fa103caa26fe8dea", "[vm]") {
  std::string bytecode_str = "58600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("when______18527242394f1a6921ffb94f5938e5c13a8dc892cb123edf424d17c32be5140d", "[vm]") {
  std::string bytecode_str = "600060011115600e57600d6080525b";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("pc1______5e897dc9ac93e7c8c0502f846914c81cacb26796ab75d517dd862fc1f193256c", "[vm]") {
  std::string bytecode_str = "60ff60005558600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("05" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("gasOverFlow______01dd61c063b45f54e62e912f6711a3c04bcaba16f40890da37774adedcf5d201", "[vm]") {
  std::string bytecode_str = "60035b600190038060025768010000000000000016565b63badf000d60115500";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("jumpiAfterStop______ec2d355d1d27a71fadd654c9a7b8a7b90bc68dce10416448f803d452ef1d474d", "[vm]") {
  std::string bytecode_str = "60016008570060015b6002600355";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("gas0______344499133ac967decfa379dd507e6df8c81e13b014db2676d943cdd2ed3c09c6", "[vm]") {
  std::string bytecode_str = "64ffffffffff60005261eeee605a525a600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("018680" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("BlockNumberDynamicJumpInsidePushWithoutJumpDest______183a4ce2d0f208630db92539aaf4e38fc3025b44a2842e19e39e956465449fe5", "[vm]") {
  std::string bytecode_str = "600543015661eeff";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("indirect_jump2______74d76db6a1761e44af7dea37c2ed941aac2add09cff11950033033cbe6f83248", "[vm]") {
  std::string bytecode_str = "600860060156005b6001600052005b6002600052596000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("JDfromStorageDynamicJumpi1_jumpdest______cc7eadaee4927a2753204e40d7028ae1ed3e1ef4c9a2e8a79460a3e07f5bcafe", "[vm]") {
  std::string bytecode_str = "60236001600a600054015760015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("BlockNumberDynamicJump0_AfterJumpdest3______1e86dccd54bd74436a1bbfe11302b675761fc6138ebd1461231acd29ee97b0f0", "[vm]") {
  std::string bytecode_str = "6023600b60085043015660015b600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("mstore_mload0______f3bd75c796896dcdbf77a7b2af45f3299ebe20db7e30d22031edc990bffb0416", "[vm]") {
  std::string bytecode_str = "6017600052600051600155";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("17" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("BlockNumberDynamicJumpi1______91d6fe3848fbdafff10b7bd503d560f2c614d6b53ed16b51821d3026f4a3a544", "[vm]") {
  std::string bytecode_str = "6023600060094301576001600255";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("01" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("JDfromStorageDynamicJump1______bf061c0eb83d11c310f7ec309e56c3629f715727b41cc0e0772991060404cfc9", "[vm]") {
  std::string bytecode_str = "620fffff620fffff016000540156";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("sstore_load_2______6eeaf23d94ef3fc20edf8997eea5636ef20031039916c445404cfbe6ed8fbd42", "[vm]") {
  std::string bytecode_str = "60ff60005560ee60015560dd600255600154600a55600254601455";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("sha3MemExp______6672d6b321654fc8397f1a89903d0fb859013f50a4483c33e7b14b08ba490886", "[vm]") {
  std::string bytecode_str = "60ff630fffffff20";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("DynamicJump1______2369bac56afc1e0946f608c52027fbc88faf3844cdc2fa46954a0916221b8432", "[vm]") {
  std::string bytecode_str = "620fffff620fffff0160030156";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("DynamicJumpInsidePushWithoutJumpDest______4e320bace2f65884d59f95dbbba6e4f9aea39e243bffd309be9bb6c5a3c1bedb", "[vm]") {
  std::string bytecode_str = "60056003015661eeff";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("msize3______e5a676b6ba865c05ea6cf933a2805cb286a664d1bee6544604cc96fdd79f1be4", "[vm]") {
  std::string bytecode_str = "64ffffffffff60005261eeee605a5259600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("80" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("pop0______46af5c256e1cdc6525f63332c78c39e0583ad9afe06e29a1a2cad8efcc801fd4", "[vm]") {
  std::string bytecode_str = "6002600360045055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("02" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("BlockNumberDynamicJump1______88e43b5985cc4dfbcbc8476c570157e6e7bc0ee0cb3609e9e9f3dd9aa2a3a528", "[vm]") {
  std::string bytecode_str = "620fffff620fffff01430156";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("201503110206PYTHON______ad34ff6291ab537633ab5e7163537b24617cc4edb2f45eac65bed9d2c009cfc3", "[vm]") {
  std::string bytecode_str = "4045404145454441343987ff3735043055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("201503111844PYTHON______a8049871a173837bf8fbfab3352baf9bb9e33d0ffa2bd20ba6246a70d9c1b165", "[vm]") {
  std::string bytecode_str = "65424555";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("201503112218PYTHON______6fc205d30fd7493b6e120e18c91e1e41f6fe334b94abadbac37d2817066ebccb", "[vm]") {
  std::string bytecode_str = "4041";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("201503110219PYTHON______93dd23cbf213b07ac96a1fdfc826f41475452fea6da2e4f8d3f5d206e9a1adb9", "[vm]") {
  std::string bytecode_str = "4040459143404144809759886d608f";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("201503102320PYTHON______38aa9ba7f7836987852734619b0192d42434bd7106da17663d5fc85d81a1e6cf", "[vm]") {
  std::string bytecode_str = "434342444244454597";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("201503110346PYTHON_PUSH24______953cb389f468c0d45697c57895679d7675ab43de963ad34a0ee547b8d27d10c8", "[vm]") {
  std::string bytecode_str = "7745414245403745f31387900a8d55";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("sha3_0______55a13dc9cd0457c545a8ff9a046a83facd094f8bc1b0aa57a04d58a47f1cca2c", "[vm]") {
  std::string bytecode_str = "6000600020600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sha3_memSizeNoQuadraticCost31______f3e15daec7cb9cd515321d21f091a8863aad12e0555b5d0a2ab01d345da4a609", "[vm]") {
  std::string bytecode_str = "60016103c020600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sha3_memSizeQuadraticCost63______c707d289675e51f41e5ddb0cfa077b7108e8e29550c5976b3eceb5da3038f7b2", "[vm]") {
  std::string bytecode_str = "60016107c020600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sha3_1______25997633273316ca1cf2258035f3cf723789e01c837f12095561c96a96d43fd8", "[vm]") {
  std::string bytecode_str = "6005600420600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("c41589e7559804ea4a2080dad19d876a024ccb05117835447d72ce08c1d020ec" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sha3_memSizeQuadraticCost65______2af3a55f4752f20404afb7c3a1c889d4c21d8b5581a382704e0421cec66aab9f", "[vm]") {
  std::string bytecode_str = "600161080020600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sha3_memSizeQuadraticCost32______ce67ec8d13841600bc8076b4136260645e72100c4eb9caab7cfaba6c22e143d2", "[vm]") {
  std::string bytecode_str = "60016103e020600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sha3_bigOffset______9df88aa7ae0baf4b6db458e8101233391101b3343a26dd91ff31335ea40a00dd", "[vm]") {
  std::string bytecode_str = "60027e0fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff20600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("sha3_6______db7522537756de38606a515817f7f953d63869199afbdb2ef97441a6500b6655", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff20600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("sha3_memSizeQuadraticCost33______66fefc4166dd60603843813c9413995b2a0658047d0973cf1776a158581e9141", "[vm]") {
  std::string bytecode_str = "600161040020600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sha3_memSizeQuadraticCost64______b38d9ca851b3236eb73cb13cad9fea6e605e035f9d6f4628d20d190d9503f330", "[vm]") {
  std::string bytecode_str = "60016107e020600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sha3_memSizeQuadraticCost64_2______d185939aec4f4aae503167ad5a5f8b40aa65f4a532c2014ed9f905678cbbd3b3", "[vm]") {
  std::string bytecode_str = "60206107e020600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("290decd9548b62a8d60345a988386fc84ba6bc95484008f6362f93160ef3e563" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sha3_4______f05a375db651dc62f2409f548bdd0db74a50cdc163feb25d1f65be155db69ea5", "[vm]") {
  std::string bytecode_str = "6064640fffffffff20600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("sha3_5______58a094eff7761aa13888ad9b24ead0f78207f29b7b27ec19e07f9ab7ca3e6b57", "[vm]") {
  std::string bytecode_str = "640fffffffff61271020600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("sha3_bigSize______794cb1a0b26deee9fb2c7a1bec1e0c6b499a91b9b6e2024f31ef10ade8074b52", "[vm]") {
  std::string bytecode_str = "7effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff20600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("sha3_2______296af237a14112e306707e5f8e6ef1c64c19f67c4bd35fbfabbfe5a94e3dd430", "[vm]") {
  std::string bytecode_str = "600a600a20600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("6bd2dd6bd408cbee33429358bf24fdc64612fbf8b1b4db604518f40ffd34b607" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sha3_memSizeQuadraticCost32_zeroSize______2da0644da1e2765b44f104b09873de52632c04765c752ee2428e215cae0c821c", "[vm]") {
  std::string bytecode_str = "600061040020600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("sha3_3______de2716629e8c598d97f20e648cce8062238e5a4c5b02d88386f72fd0d61cd905", "[vm]") {
  std::string bytecode_str = "620fffff6103e820600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("sha3_bigOffset2______6d4d1bdba5c2a7921d8c4c6145cf926eb73e32012534729620645a6d7c86c20a", "[vm]") {
  std::string bytecode_str = "6002630100000020600055";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("54a8c0ab653c15bfb48b47fd011ba2b9617af01cb45cab344acd57c924d56798" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("return0______1cd2b9480f1f5bdd82e8026b6342008ef84d318c3f9f173eae7d09e50eaf26b3", "[vm]") {
  std::string bytecode_str = "603760005360005160005560016000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("3700000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("return1______5cd716a8e8d460b10e0dc1b3d5b6394f0c388e0e36246bf124478b0cb86a1f76", "[vm]") {
  std::string bytecode_str = "603760005360005160005560026000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("3700000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("suicideSendEtherToMe______0cf005812e9c99dc87bdd8463a9849a0164a9e02b3d09eaab228267d6c8c703e", "[vm]") {
  std::string bytecode_str = "30ff";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("TestNameRegistrator______7e0e4bcbcbe8bcaf9a8535e65d4c6665db752910953b5eafc63da8f7cdff20b7", "[vm]") {
  std::string bytecode_str = "6000355415600957005b60203560003555";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("suicideNotExistingAccount______ba450a40efb62a9fb6e16e3bced0afde8d0b08b9c0f78979f35fc45b9de72816", "[vm]") {
  std::string bytecode_str = "73aa1722f3947def4cf144679da39c4c32bdc35681ff";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("return2______4181cbf262c1dc2cdc186e007ec6c13466bd031b190b07874b1177a00717deeb", "[vm]") {
  std::string bytecode_str = "603760005360005160005560216000f3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

  store_item_t item0 = Utils::accountStoreValue(0, accountItems);

  // then
  CHECK("3700000000000000000000000000000000000000000000000000000000000000" ==
    Utils::uint256_2str(item0.second)
  );
}

TEST_CASE("suicide0______56c8766e8a1687dfe807b1e8f2d0454267f432c7e3035ff5fa9c27a2d594739d", "[vm]") {
  std::string bytecode_str = "33ff";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log2_logMemsizeTooHigh______9fb39d1608049d1d5455c7409514acc175724f2b1e43102d17b631862c3bc1a4", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd600052600060007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6001a2";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("log1_nonEmptyMem______f3e28ff95bf5e800cd43ab50df02e0c38e9fa2b8205732a9ef4a9c7c4a881da6", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600052600060206000a1";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log4_logMemsizeZero______c7e7169c36cc57a6425d03859449560d8d7f48c189f2af5d90710d24de096912", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd600052600060006000600060006001a4";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log1_emptyMem______3284dac984331ac8d612e2bb4994f34e19f76861ed5294388fe95c283bd500fc", "[vm]") {
  std::string bytecode_str = "600060006000a1";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log0_logMemsizeZero______e5b6bb2501704a5d2b73c86a3e02be967fdfc90fb58f2b4f5e6e3750406792ef", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260006001a0";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log2_emptyMem______6cc6686c11bbd223248c591c4c90a38f469fdb2571b7b6279a116ee07147b4be", "[vm]") {
  std::string bytecode_str = "6000600060006000a2";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log4_nonEmptyMem_logMemSize1_logMemStart31______4f7869f982d0f61e794df14e64040914832b8e4f7d643c94bb9d2694ce228450", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260006000600060006001601fa4";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log1_logMemsizeZero______583cfb6cec3eb602dc034886dfc2e2171da94941d0bbb8c36156bcf50d2b6827", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd600052600060006001a1";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log2_Caller______bf2bb94ebe5938744184e8a6f7b2a5eaa274b40d3a92b6802153133a1f8d64ef", "[vm]") {
  std::string bytecode_str = "60ff60005333600060206000a2";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log1_logMemsizeTooHigh______17e5a63a7a389f823678de07caa666ff5148749e4697b54e304dd9407312c672", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6001a1";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("log2_logMemsizeZero______686ccc981e9622bcfeb6161ad1d9f71a70d91b3d828ee46bffb105be3394dbab", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000526000600060006001a2";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log2_logMemStartTooHigh______d45766f7e33ecc09cc11f00e216474469c49933a5777d8599ad60fd51e1ab3e1", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000526000600060017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa2";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("log3_logMemsizeZero______69bd3e5dcb7e699abcb3faa58aa9a80a6ff20e8287c8f4981f4973cbba96e192", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260006000600060006001a3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log2_MaxTopic______d3c300433ba07e9e91cab5d9ad174a159012c1975b3b69c3ceedb895132265c6", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000527fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60206000a2";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log1_logMemStartTooHigh______b6a326587a3dbbd977d24a247338ade2c2feed85e53de7b8067809c00034cd6d", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd600052600060017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa1";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("log0_nonEmptyMem______0cfc646681837311fb39e1273123794960fbb9ea4e424578f87a551a36df6fae", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60005260206000a0";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log0_logMemsizeTooHigh______04fe0fcd01a67dcc0bbc0ea972f7af4c8695a6b63170a53ac5d11ce437bc7904", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000527fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6001a0";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("log_2logs______59ad5528d89751649749405f4a5cd70d8a03875afb90fa0d4d6824d3d96a390f", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60005260206000a060106002a0";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log1_Caller______33df8d2b8c92e29404110e09be9bd88bc1f685e12067c07e534f683ccebc5ac7", "[vm]") {
  std::string bytecode_str = "60ff6000533360206000a1";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log3_nonEmptyMem_logMemSize1______baeb20e8806b5cf814426f11178bd4d5ac34165b77a660713d5202e166784e72", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260006000600060016000a3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log0_nonEmptyMem_logMemSize1______a20cb10f863eb27a33608f41f9d3de3d25a37da55aadb03a2a794cc5dedcaa05", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260016000a0";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log4_Caller______8ea00f94cec5a457cac5de1731aa75c588c13d2eab55297aa7a3b62c268add1f", "[vm]") {
  std::string bytecode_str = "60ff6000533360006000600060206000a4";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log4_logMemsizeTooHigh______13b51aeb36d62dac84da56023d6406a59c83490d2640d4d6abdf89c2d55c9fed", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260006000600060007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6001a4";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("log4_nonEmptyMem______a3c64c86ba9a76871b7c3c281a0454708cdb5e91ca611b55df194bab9a1fafaf", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff600052600060006000600060206000a4";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log1_MaxTopic______0a4c414906a74571451b62d5cbccfd73c420f46831681365491d35d780a1c98a", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000527fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60206000a1";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log3_logMemsizeTooHigh______f2c5e55c6680ac4b66054f399561cbe97badde7f2f3292132ab9d36b2b160464", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000526000600060007fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6001a3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("log3_PC______8d7beb47cc14822075ce2fbac294728f8faba640e26a7ed370eafa8e590df2d0", "[vm]") {
  std::string bytecode_str = "60ff60005358585860206000a3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log3_nonEmptyMem_logMemSize1_logMemStart31______bda2d24ce0f250b08877fc4e9da8c2952804af9662c3af30db45995f0cd80ce4", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000526000600060006001601fa3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log3_logMemStartTooHigh______9810608d983312d9f5ab12cd9358825f20f92ca174905c314a551082406dea1a", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260006000600060017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("log1_nonEmptyMem_logMemSize1______49ec0b89dab4beb39bb4dbc58191f465ef09c133df05d7444cc5dfc95274360f", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd600052600060016000a1";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log4_MaxTopic______1928e2558239ffc6fbb18068e3f1428cd7e60eb06e8dd308bce1938f5ee7144a", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000527fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60206000a4";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log3_Caller______fae584b1f6d4f92ed0b072ce8f7842b2ca367ab838949e51830c9ca8f70713c5", "[vm]") {
  std::string bytecode_str = "60ff600053336000600060206000a3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log3_nonEmptyMem______1d2ad4f6f79e0161150ea4ae333a9df11e1099df23fff0eb0844c70f77dabe60", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60005260006000600060206000a3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log3_MaxTopic______b7120956567b5710f9dd49ac0db7e43d839a6a026598143cff9b58d02e61193a", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000527fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff60206000a3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log1_nonEmptyMem_logMemSize1_logMemStart31______dfba77e757549bc564c542df0e94e48a135e817f9f53455000827eaafeffb307", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260006001601fa1";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log2_nonEmptyMem_logMemSize1______0db120840474461ba7c4de523260af515ca7424bc998312fd5cbd21a955e627e", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000526000600060016000a2";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log2_nonEmptyMem_logMemSize1_logMemStart31______fad1ccc7b33b11ea24c70737aa879fd8172c7ba8b413bca9002e360f15cb0377", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd600052600060006001601fa2";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log3_emptyMem______f39ac12e960ba98b1d6d52dbe564caded52a338cb16b7924869a1b8c2a77188c", "[vm]") {
  std::string bytecode_str = "60006000600060006000a3";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log4_logMemStartTooHigh______b231ee785a24fab97ccfb8dde384ecbb03ea86bd9c5b7a8e7c602b7f1b347ab7", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd600052600060006000600060017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa4";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("log4_nonEmptyMem_logMemSize1______2e590a92288accca39422740f9b8c7d946723b636dcaf988e583438247ef8e75", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd600052600060006000600060016000a4";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log2_nonEmptyMem______a1c8ae74a72e0723f39e564ff0843ed03b579c9e7ae7b0c13d755c78a4589705", "[vm]") {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff6000526000600060206000a2";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log4_PC______1c6a8d77e5986d32795ac6f8757849527822e91848f34f531cc5c81cfbcdebcd", "[vm]") {
  std::string bytecode_str = "60ff6000535858585860206000a4";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log4_emptyMem______1d899abc32e13324725840e9b79042f03f389f1ab1a3fb013b9a2d49261d795b", "[vm]") {
  std::string bytecode_str = "600060006000600060006000a4";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log0_nonEmptyMem_logMemSize1_logMemStart31______777ce021b26b0e4f62b98b595d6ee69ce21d83027c2975ef24f51af29416b9fa", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd6000526001601fa0";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("log0_logMemStartTooHigh______7cc27fdfcb258a0528c94496e60e3b10907a4d241b9d9e685e72597c472aa1b1", "[vm]") {
  std::string bytecode_str = "7faabbffffffffffffffffffffffffffffffffffffffffffffffffffffffffccdd60005260017fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa0";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("log0_emptyMem______dddfbdc5d0776cd04613d3515648fa20eb5dc10a86b4e393b1ef818a28c82095", "[vm]") {
  std::string bytecode_str = "60006000a0";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("loop-mul______9862bc727536901c182cf2638655d9b9f3b45ee0e0ea8030084b5cae38b4b7d0", "[vm]") {
  std::string bytecode_str = "606060405260e060020a6000350463eb8ac9218114601c575b6002565b3460025760646004356024356000675851f42d4c957f2d6714057b7ef767814f82805b600086146076575050938102840180820285018082029560001995909501949190603f565b60408051918252519081900360200190f35b50949594505050505056";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("loop-exp-nop-1M______b6fa0af7e999498530fc565052fd9465f33fae61a400d370a6ea56f917ae7dfb", "[vm]") {
  std::string bytecode_str = "606060405260e060020a60003504633392ffc8811461003f5780633c77b95c1461006a578063ce67bda6146100c2578063ebbbe00b146100e8575b610002565b346100025761010e600435602435604435600082815b83811015610120579085900a90600101610055565b346100025761010e600435602435604435600082815b83811015610120579085900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a90601001610080565b346100025761010e6004356024356044356000805b82811015610129575b6001016100d7565b346100025761010e6004356024356044356000805b82811015610129575b6010016100fd565b60408051918252519081900360200190f35b50949350505050565b5091939250505056";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("manyFunctions100______a93da81ce1ea6b18ce5a5f95f19ee134cfe381ce597da0ac756b9fe46e51dd3e", "[vm]") {
  std::string bytecode_str = "60e060020a60003504806301f99ad7146108c3578063023a624a146108d857806303bdecf5146108ed57806305fe035f14610902578063082d8f4914610917578063090bf3b71461092c5780630bd9c534146109415780630c4bfa94146109565780630e20ebe21461096b5780630f76de0d1461098057806310cfcc191461099557806313ce15a9146109aa578063140dcec4146109bf57806314d07a3e146109d45780631687f112146109e957806316eb6603146109fe578063172cf71714610a135780631bd6f59614610a285780631cdb857114610a3d5780631cf74ece14610a525780631d09ba2c14610a675780631f69aa5114610a7c578063223dcc7414610a9157806325e524d314610aa6578063261de7c414610abb5780632632924d14610ad05780632909cc5d14610ae55780632981699814610afa5780632a85a45d14610b0f5780632ca36da014610b245780632cbf1f0d14610b395780632d0f557314610b4e5780632d97867814610b6357806331db9efd14610b7857806332064db714610b8d57806332931fbb14610ba2578063355f51a014610bb7578063361bb34014610bcc578063364ddb0e14610be15780633792a01814610bf657806338c68f8f14610c0b57806338e586fd14610c20578063392d42ae14610c3557806339a87bd914610c4a5780633a95a33214610c5f5780633b8ecdf914610c745780633cf0659a14610c895780633eaf992314610c9e5780633fe97ead14610cb35780633ff11c8b14610cc8578063404efc5314610cdd578063407fce7b14610cf257806340c3b18714610d07578063440208c314610d1c57806344e86b2f14610d31578063455df57914610d465780634689ab4d14610d5b57806346be2e0c14610d70578063487cd86f14610d8557806348e6178214610d9a57806349d4a34414610daf5780634a0f597414610dc45780634bc24ec514610dd95780634c2fe45614610dee5780634cc885d414610e035780634eaaad7b14610e185780634eb166af14610e2d5780635050093414610e42578063506bff1114610e57578063508762c114610e6c578063526938f814610e8157806354400c6014610e96578063559510d814610eab57806355a5f70214610ec057806356ca528f14610ed5578063570a2a1614610eea5780635dab2e0f14610eff5780635dca53d314610f1457806362017ebc14610f29578063621a25f814610f3e578063626d4a3614610f5357806362b6a28214610f6857806364faf22c14610f7d57806366d7ffde14610f9257806367b886e814610fa757806367e902c714610fbc57806369d7774014610fd15780636b7ae8e614610fe65780636c3b659114610ffb5780636e54181e146110105780636e978d91146110255780636f63d2ec1461103a578063706332d11461104f57806370ac4bb9146110645780637138ef521461107957806371dd46a91461108e57806372a7c229146110a35780637376fc8d146110b8578063738a2679146110cd57806374552650146110e2578063746fc8d0146110f757806379254bb81461110c5780637adaa3f8146111215780637e4eb35b14611136578063885ec18e1461114b5780638b9ff6b6146111605780638ce113dc146111755780638defbc5e1461118a5780638f4613d51461119f5780638fdc24ba146111b45780639002dba4146111c957806391d15735146111de57806391d43b23146111f357806393b14daa1461120857806394d63afd1461121d57806395805dad1461123257806396f68782146112475780639740e4a21461125c578063981290131461127157806399a3f0e8146112865780639acb1ad41461129b5780639be07908146112b05780639c15be0b146112c55780639d451c4d146112da5780639d8ee943146112ef5780639ef6ca0f14611304578063a0db0a2214611319578063a18e2eb91461132e578063a408384914611343578063a57544da14611358578063a5a83e4d1461136d578063a6843f3414611382578063a6dacdd714611397578063a8c4c8bc146113ac578063aa058a73146113c1578063aad62da2146113d6578063aaf3e4f4146113eb578063ab81e77314611400578063abc93aee14611415578063abde33f71461142a578063b114b96c1461143f578063b3df873714611454578063b4174cb014611469578063b5d02a561461147e578063b731e84814611493578063b7b96723146114a8578063bbcded7a146114bd578063bbececa9146114d2578063beca7440146114e7578063bf8981c0146114fc578063c028c67414611511578063c2385fa614611526578063c319a02c1461153b578063c569bae014611550578063c6715f8114611565578063c7b98dec1461157a578063c9acab841461158f578063ca9efc73146115a4578063cad80024146115b9578063cdadb0fa146115ce578063cdbdf391146115e3578063cf460fa5146115f8578063cf69318a1461160d578063d1835b8c14611622578063d353a1cb14611637578063d3e141e01461164c578063d5ec7e1d14611661578063d7ead1de14611676578063d90b02aa1461168b578063d959e244146116a0578063d9e68b44146116b5578063daacb24f146116ca578063dc12a805146116df578063dd946033146116f4578063dda5142414611709578063de6612171461171e578063dfb9560c14611733578063e03827d214611748578063e21720001461175d578063e2c718d814611772578063e3da539914611787578063e48e603f1461179c578063e5f9ec29146117b1578063e6c0459a146117c6578063e70addec146117db578063e7a01215146117f0578063ea7f4d2714611805578063ebb6c59f1461181a578063ed6302be1461182f578063ed64b36b14611844578063eecd278914611859578063f0ed14e01461186e578063f0f2134414611883578063f1e328f914611898578063f1e6f4cd146118ad578063f32fe995146118c2578063f75165c6146118d7578063f7ed71d0146118ec578063f80f44f314611901578063f8bc050514611916578063fbd3c51a1461192b578063fd72009014611940578063fed3a3001461195557005b6108ce600435612edf565b8060005260206000f35b6108e3600435612fb5565b8060005260206000f35b6108f8600435613f47565b8060005260206000f35b61090d600435612a11565b8060005260206000f35b6109226004356127ec565b8060005260206000f35b61093760043561215c565b8060005260206000f35b61094c6004356128c2565b8060005260206000f35b61096160043561310f565b8060005260206000f35b610976600435614e0b565b8060005260206000f35b61098b600435613269565b8060005260206000f35b6109a0600435611a82565b8060005260206000f35b6109b5600435613e71565b8060005260206000f35b6109ca600435611dd2565b8060005260206000f35b6109df6004356120d0565b8060005260206000f35b6109f4600435613755565b8060005260206000f35b610a096004356134e3565b8060005260206000f35b610a1e6004356137e1565b8060005260206000f35b610a3360043561382b565b8060005260206000f35b610a48600435612b0b565b8060005260206000f35b610a5d60043561386d565b8060005260206000f35b610a726004356131e5565b8060005260206000f35b610a876004356143e9565b8060005260206000f35b610a9c60043561319b565b8060005260206000f35b610ab1600435612e11565b8060005260206000f35b610ac660043561234a565b8060005260206000f35b610adb6004356121e8565b8060005260206000f35b610af06004356119f6565b8060005260206000f35b610b05600435613bff565b8060005260206000f35b610b1a600435612606565b8060005260206000f35b610b2f6004356126d4565b8060005260206000f35b610b44600435613bb5565b8060005260206000f35b610b59600435612462565b8060005260206000f35b610b6e600435611e14565b8060005260206000f35b610b836004356149ab565b8060005260206000f35b610b98600435611c26565b8060005260206000f35b610bad600435612a7f565b8060005260206000f35b610bc2600435613457565b8060005260206000f35b610bd760043561340d565b8060005260206000f35b610bec60043561363d565b8060005260206000f35b610c01600435612e53565b8060005260206000f35b610c1660043561477b565b8060005260206000f35b610c2b600435612c6d565b8060005260206000f35b610c40600435612648565b8060005260206000f35b610c55600435612274565b8060005260206000f35b610c6a6004356138f9565b8060005260206000f35b610c7f600435612b55565b8060005260206000f35b610c94600435611eea565b8060005260206000f35b610ca9600435613ebb565b8060005260206000f35b610cbe600435613499565b8060005260206000f35b610cd3600435614807565b8060005260206000f35b610ce8600435611fb8565b8060005260206000f35b610cfd600435613083565b8060005260206000f35b610d126004356125bc565b8060005260206000f35b610d27600435613041565b8060005260206000f35b610d3c6004356140a1565b8060005260206000f35b610d516004356147bd565b8060005260206000f35b610d66600435611c70565b8060005260206000f35b610d7b600435612300565b8060005260206000f35b610d906004356123d6565b8060005260206000f35b610da5600435612c23565b8060005260206000f35b610dba600435614faf565b8060005260206000f35b610dcf600435612044565b8060005260206000f35b610de4600435613ae7565b8060005260206000f35b610df9600435614cf3565b8060005260206000f35b610e0e600435613d17565b8060005260206000f35b610e2360043561412d565b8060005260206000f35b610e38600435614177565b8060005260206000f35b610e4d60043561208e565b8060005260206000f35b610e62600435612dc7565b8060005260206000f35b610e77600435612f29565b8060005260206000f35b610e8c6004356124a4565b8060005260206000f35b610ea1600435611b58565b8060005260206000f35b610eb66004356136c9565b8060005260206000f35b610ecb600435613227565b8060005260206000f35b610ee0600435611acc565b8060005260206000f35b610ef5600435613687565b8060005260206000f35b610f0a6004356146a5565b8060005260206000f35b610f1f6004356121a6565b8060005260206000f35b610f346004356132f5565b8060005260206000f35b610f49600435613da3565b8060005260206000f35b610f5e60043561379f565b8060005260206000f35b610f73600435612878565b8060005260206000f35b610f88600435611b0e565b8060005260206000f35b610f9d600435611ea0565b8060005260206000f35b610fb2600435614ed9565b8060005260206000f35b610fc7600435614bdb565b8060005260206000f35b610fdc600435614c1d565b8060005260206000f35b610ff1600435614245565b8060005260206000f35b6110066004356146ef565b8060005260206000f35b61101b60043561428f565b8060005260206000f35b611030600435614ac3565b8060005260206000f35b611045600435613de5565b8060005260206000f35b61105a6004356132b3565b8060005260206000f35b61106f6004356122be565b8060005260206000f35b611084600435612e9d565b8060005260206000f35b611099600435611b9a565b8060005260206000f35b6110ae6004356127aa565b8060005260206000f35b6110c3600435613e2f565b8060005260206000f35b6110d8600435614849565b8060005260206000f35b6110ed600435614dc1565b8060005260206000f35b61110260043561333f565b8060005260206000f35b61111760043561211a565b8060005260206000f35b61112c600435612692565b8060005260206000f35b611141600435612904565b8060005260206000f35b611156600435612d3b565b8060005260206000f35b61116b600435614b91565b8060005260206000f35b611180600435613a5b565b8060005260206000f35b611195600435612232565b8060005260206000f35b6111aa600435612f6b565b8060005260206000f35b6111bf600435614d35565b8060005260206000f35b6111d4600435611a40565b8060005260206000f35b6111e9600435612ff7565b8060005260206000f35b6111fe60043561431b565b8060005260206000f35b611213600435613159565b8060005260206000f35b611228600435612b97565b8060005260206000f35b61123d600435612990565b8060005260206000f35b611252600435613b73565b8060005260206000f35b611267600435614961565b8060005260206000f35b61127c600435613381565b8060005260206000f35b611291600435613fd3565b8060005260206000f35b6112a660043561257a565b8060005260206000f35b6112bb600435614501565b8060005260206000f35b6112d0600435613d59565b8060005260206000f35b6112e56004356143a7565b8060005260206000f35b6112fa60043561405f565b8060005260206000f35b61130f60043561238c565b8060005260206000f35b611324600435612be1565b8060005260206000f35b611339600435613f89565b8060005260206000f35b61134e60043561294e565b8060005260206000f35b6113636004356124ee565b8060005260206000f35b611378600435614b4f565b8060005260206000f35b61138d6004356133cb565b8060005260206000f35b6113a26004356139cf565b8060005260206000f35b6113b7600435613c8b565b8060005260206000f35b6113cc600435612cf9565b8060005260206000f35b6113e1600435614a79565b8060005260206000f35b6113f66004356149ed565b8060005260206000f35b61140b600435613b29565b8060005260206000f35b611420600435613ccd565b8060005260206000f35b611435600435611f76565b8060005260206000f35b61144a600435614ff1565b8060005260206000f35b61145f600435613525565b8060005260206000f35b61147460043561356f565b8060005260206000f35b6114896004356129dc565b8060005260206000f35b61149e600435614ca9565b8060005260206000f35b6114b3600435612d85565b8060005260206000f35b6114c86004356141b9565b8060005260206000f35b6114dd600435614475565b8060005260206000f35b6114f26004356135fb565b8060005260206000f35b611507600435612530565b8060005260206000f35b61151c600435614663565b8060005260206000f35b611531600435614433565b8060005260206000f35b611546600435614f23565b8060005260206000f35b61155b600435614c67565b8060005260206000f35b611570600435611d3e565b8060005260206000f35b611585600435612a3d565b8060005260206000f35b61159a600435613a11565b8060005260206000f35b6115af600435614619565b8060005260206000f35b6115c4600435613985565b8060005260206000f35b6115d9600435613943565b8060005260206000f35b6115ee600435612418565b8060005260206000f35b6116036004356119b4565b8060005260206000f35b611618600435613a9d565b8060005260206000f35b61162d600435611cb2565b8060005260206000f35b6116426004356129d2565b8060005260206000f35b611657600435612caf565b8060005260206000f35b61166c600435611d88565b8060005260206000f35b611681600435614203565b8060005260206000f35b61169660043561458d565b8060005260206000f35b6116ab600435611f2c565b8060005260206000f35b6116c0600435612a23565b8060005260206000f35b6116d5600435612836565b8060005260206000f35b6116ea6004356138b7565b8060005260206000f35b6116ff6004356145d7565b8060005260206000f35b61171460043561454b565b8060005260206000f35b6117296004356142d1565b8060005260206000f35b61173e600435611e5e565b8060005260206000f35b611753600435614015565b8060005260206000f35b611768600435613c41565b8060005260206000f35b61177d600435611be4565b8060005260206000f35b611792600435614b05565b8060005260206000f35b6117a7600435613713565b8060005260206000f35b6117bc6004356135b1565b8060005260206000f35b6117d16004356144bf565b8060005260206000f35b6117e660043561491f565b8060005260206000f35b6117fb600435612ac9565b8060005260206000f35b6118106004356130cd565b8060005260206000f35b6118256004356140eb565b8060005260206000f35b61183a600435614f65565b8060005260206000f35b61184f60043561196a565b8060005260206000f35b6118646004356148d5565b8060005260206000f35b611879600435614d7f565b8060005260206000f35b61188e600435612002565b8060005260206000f35b6118a3600435613efd565b8060005260206000f35b6118b860043561271e565b8060005260206000f35b6118cd600435614e4d565b8060005260206000f35b6118e2600435611cfc565b8060005260206000f35b6118f7600435612760565b8060005260206000f35b61190c600435614e97565b8060005260206000f35b61192160043561435d565b8060005260206000f35b611936600435614731565b8060005260206000f35b61194b600435614893565b8060005260206000f35b611960600435614a37565b8060005260206000f35b6000600061197f61197a846129dc565b6129dc565b9050605d60020a811015611992576119a2565b61199b816119f6565b91506119ae565b6119ab816119b4565b91505b50919050565b600060006119c1836129dc565b9050605e60020a8110156119d4576119e4565b6119dd81611a40565b91506119f0565b6119ed81611a82565b91505b50919050565b60006000611a0b611a06846129dc565b6129dc565b9050605e60020a811015611a1e57611a2e565b611a2781611a82565b9150611a3a565b611a3781611a40565b91505b50919050565b60006000611a4d836129dc565b9050605f60020a811015611a6057611a70565b611a6981611acc565b9150611a7c565b611a7981611b0e565b91505b50919050565b60006000611a97611a92846129dc565b6129dc565b9050605f60020a811015611aaa57611aba565b611ab381611b0e565b9150611ac6565b611ac381611acc565b91505b50919050565b60006000611ad9836129dc565b9050606060020a811015611aec57611afc565b611af581611b58565b9150611b08565b611b0581611b9a565b91505b50919050565b60006000611b23611b1e846129dc565b6129dc565b9050606060020a811015611b3657611b46565b611b3f81611b9a565b9150611b52565b611b4f81611b58565b91505b50919050565b60006000611b65836129dc565b9050606160020a811015611b7857611b88565b611b8181611be4565b9150611b94565b611b9181611c26565b91505b50919050565b60006000611baf611baa846129dc565b6129dc565b9050606160020a811015611bc257611bd2565b611bcb81611c26565b9150611bde565b611bdb81611be4565b91505b50919050565b60006000611bf1836129dc565b9050606260020a811015611c0457611c14565b611c0d81611c70565b9150611c20565b611c1d81611cb2565b91505b50919050565b60006000611c3b611c36846129dc565b6129dc565b9050606260020a811015611c4e57611c5e565b611c5781611cb2565b9150611c6a565b611c6781611c70565b91505b50919050565b60006000611c7d836129dc565b9050606360020a811015611c9057611ca0565b611c9981611cfc565b9150611cac565b611ca981611d88565b91505b50919050565b60006000611cc7611cc2846129dc565b6129dc565b9050606360020a811015611cda57611cea565b611ce381611d88565b9150611cf6565b611cf381611cfc565b91505b50919050565b60006000611d09836129dc565b9050606460020a811015611d1c57611d2c565b611d2581611dd2565b9150611d38565b611d3581611e14565b91505b50919050565b60006000611d53611d4e846129dc565b6129dc565b9050607a60020a811015611d6657611d76565b611d6f81613269565b9150611d82565b611d7f81613227565b91505b50919050565b60006000611d9d611d98846129dc565b6129dc565b9050606460020a811015611db057611dc0565b611db981611e14565b9150611dcc565b611dc981611dd2565b91505b50919050565b60006000611ddf836129dc565b9050606560020a811015611df257611e02565b611dfb81611e5e565b9150611e0e565b611e0b81611ea0565b91505b50919050565b60006000611e29611e24846129dc565b6129dc565b9050606560020a811015611e3c57611e4c565b611e4581611ea0565b9150611e58565b611e5581611e5e565b91505b50919050565b60006000611e6b836129dc565b9050606660020a811015611e7e57611e8e565b611e8781611eea565b9150611e9a565b611e9781611f2c565b91505b50919050565b60006000611eb5611eb0846129dc565b6129dc565b9050606660020a811015611ec857611ed8565b611ed181611f2c565b9150611ee4565b611ee181611eea565b91505b50919050565b60006000611ef7836129dc565b9050606760020a811015611f0a57611f1a565b611f1381611f76565b9150611f26565b611f2381611fb8565b91505b50919050565b60006000611f41611f3c846129dc565b6129dc565b9050606760020a811015611f5457611f64565b611f5d81611fb8565b9150611f70565b611f6d81611f76565b91505b50919050565b60006000611f83836129dc565b9050606860020a811015611f9657611fa6565b611f9f81612002565b9150611fb2565b611faf81612044565b91505b50919050565b60006000611fcd611fc8846129dc565b6129dc565b9050606860020a811015611fe057611ff0565b611fe981612044565b9150611ffc565b611ff981612002565b91505b50919050565b6000600061200f836129dc565b9050606960020a81101561202257612032565b61202b8161208e565b915061203e565b61203b816120d0565b91505b50919050565b60006000612059612054846129dc565b6129dc565b9050606960020a81101561206c5761207c565b612075816120d0565b9150612088565b6120858161208e565b91505b50919050565b6000600061209b836129dc565b9050606a60020a8110156120ae576120be565b6120b78161211a565b91506120ca565b6120c78161215c565b91505b50919050565b600060006120e56120e0846129dc565b6129dc565b9050606a60020a8110156120f857612108565b6121018161215c565b9150612114565b6121118161211a565b91505b50919050565b60006000612127836129dc565b9050606b60020a81101561213a5761214a565b612143816121a6565b9150612156565b612153816121e8565b91505b50919050565b6000600061217161216c846129dc565b6129dc565b9050606b60020a81101561218457612194565b61218d816121e8565b91506121a0565b61219d816121a6565b91505b50919050565b600060006121b3836129dc565b9050606c60020a8110156121c6576121d6565b6121cf81612232565b91506121e2565b6121df81612274565b91505b50919050565b600060006121fd6121f8846129dc565b6129dc565b9050606c60020a81101561221057612220565b61221981612274565b915061222c565b61222981612232565b91505b50919050565b6000600061223f836129dc565b9050606d60020a81101561225257612262565b61225b816122be565b915061226e565b61226b81612300565b91505b50919050565b60006000612289612284846129dc565b6129dc565b9050606d60020a81101561229c576122ac565b6122a581612300565b91506122b8565b6122b5816122be565b91505b50919050565b600060006122cb836129dc565b9050606e60020a8110156122de576122ee565b6122e78161234a565b91506122fa565b6122f78161238c565b91505b50919050565b60006000612315612310846129dc565b6129dc565b9050606e60020a81101561232857612338565b6123318161238c565b9150612344565b6123418161234a565b91505b50919050565b60006000612357836129dc565b9050606f60020a81101561236a5761237a565b612373816123d6565b9150612386565b61238381612418565b91505b50919050565b600060006123a161239c846129dc565b6129dc565b9050606f60020a8110156123b4576123c4565b6123bd81612418565b91506123d0565b6123cd816123d6565b91505b50919050565b600060006123e3836129dc565b9050607060020a8110156123f657612406565b6123ff81612462565b9150612412565b61240f816124a4565b91505b50919050565b6000600061242d612428846129dc565b6129dc565b9050607060020a81101561244057612450565b612449816124a4565b915061245c565b61245981612462565b91505b50919050565b6000600061246f836129dc565b9050607160020a81101561248257612492565b61248b816124ee565b915061249e565b61249b81612530565b91505b50919050565b600060006124b96124b4846129dc565b6129dc565b9050607160020a8110156124cc576124dc565b6124d581612530565b91506124e8565b6124e5816124ee565b91505b50919050565b600060006124fb836129dc565b9050607260020a81101561250e5761251e565b6125178161257a565b915061252a565b612527816125bc565b91505b50919050565b60006000612545612540846129dc565b6129dc565b9050607260020a81101561255857612568565b612561816125bc565b9150612574565b6125718161257a565b91505b50919050565b60006000612587836129dc565b9050607360020a81101561259a576125aa565b6125a381612606565b91506125b6565b6125b381612648565b91505b50919050565b600060006125d16125cc846129dc565b6129dc565b9050607360020a8110156125e4576125f4565b6125ed81612648565b9150612600565b6125fd81612606565b91505b50919050565b60006000612613836129dc565b9050607460020a81101561262657612636565b61262f81612692565b9150612642565b61263f816126d4565b91505b50919050565b6000600061265d612658846129dc565b6129dc565b9050607460020a81101561267057612680565b612679816126d4565b915061268c565b61268981612692565b91505b50919050565b6000600061269f836129dc565b9050607560020a8110156126b2576126c2565b6126bb8161271e565b91506126ce565b6126cb81612760565b91505b50919050565b600060006126e96126e4846129dc565b6129dc565b9050607560020a8110156126fc5761270c565b61270581612760565b9150612718565b6127158161271e565b91505b50919050565b6000600061272b836129dc565b9050607660020a81101561273e5761274e565b612747816127aa565b915061275a565b612757816127ec565b91505b50919050565b60006000612775612770846129dc565b6129dc565b9050607660020a81101561278857612798565b612791816127ec565b91506127a4565b6127a1816127aa565b91505b50919050565b600060006127b7836129dc565b9050607760020a8110156127ca576127da565b6127d381612836565b91506127e6565b6127e381612878565b91505b50919050565b600060006128016127fc846129dc565b6129dc565b9050607760020a81101561281457612824565b61281d81612878565b9150612830565b61282d81612836565b91505b50919050565b60006000612843836129dc565b9050607860020a81101561285657612866565b61285f816128c2565b9150612872565b61286f81612904565b91505b50919050565b6000600061288d612888846129dc565b6129dc565b9050607860020a8110156128a0576128b0565b6128a981612904565b91506128bc565b6128b9816128c2565b91505b50919050565b600060006128cf836129dc565b9050607960020a8110156128e2576128f2565b6128eb8161294e565b91506128fe565b6128fb81611d3e565b91505b50919050565b60006000612919612914846129dc565b6129dc565b9050607960020a81101561292c5761293c565b61293581611d3e565b9150612948565b6129458161294e565b91505b50919050565b6000600061295b836129dc565b9050607a60020a81101561296e5761297e565b61297781613227565b915061298a565b61298781613269565b91505b50919050565b6000600061299d836129dc565b9050604e60020a8110156129b0576129c0565b6129b981612a7f565b91506129cc565b6129c981612a3d565b91505b50919050565b6000819050919050565b600060007f5851f42d4c957f2c0000000000000000000000000000000000000000000000019050828102600101915050919050565b6000612a1c826129d2565b9050919050565b6000612a36612a31836129dc565b6129d2565b9050919050565b60006000612a4a836129dc565b9050604f60020a811015612a5d57612a6d565b612a6681612ac9565b9150612a79565b612a7681612b0b565b91505b50919050565b60006000612a94612a8f846129dc565b6129dc565b9050604f60020a811015612aa757612ab7565b612ab081612b0b565b9150612ac3565b612ac081612ac9565b91505b50919050565b60006000612ad6836129dc565b9050605060020a811015612ae957612af9565b612af281612b55565b9150612b05565b612b0281612b97565b91505b50919050565b60006000612b20612b1b846129dc565b6129dc565b9050605060020a811015612b3357612b43565b612b3c81612b97565b9150612b4f565b612b4c81612b55565b91505b50919050565b60006000612b62836129dc565b9050605160020a811015612b7557612b85565b612b7e81612be1565b9150612b91565b612b8e81612c23565b91505b50919050565b60006000612bac612ba7846129dc565b6129dc565b9050605160020a811015612bbf57612bcf565b612bc881612c23565b9150612bdb565b612bd881612be1565b91505b50919050565b60006000612bee836129dc565b9050605260020a811015612c0157612c11565b612c0a81612c6d565b9150612c1d565b612c1a81612caf565b91505b50919050565b60006000612c38612c33846129dc565b6129dc565b9050605260020a811015612c4b57612c5b565b612c5481612caf565b9150612c67565b612c6481612c6d565b91505b50919050565b60006000612c7a836129dc565b9050605360020a811015612c8d57612c9d565b612c9681612cf9565b9150612ca9565b612ca681612d3b565b91505b50919050565b60006000612cc4612cbf846129dc565b6129dc565b9050605360020a811015612cd757612ce7565b612ce081612d3b565b9150612cf3565b612cf081612cf9565b91505b50919050565b60006000612d06836129dc565b9050605460020a811015612d1957612d29565b612d2281612d85565b9150612d35565b612d3281612dc7565b91505b50919050565b60006000612d50612d4b846129dc565b6129dc565b9050605460020a811015612d6357612d73565b612d6c81612dc7565b9150612d7f565b612d7c81612d85565b91505b50919050565b60006000612d92836129dc565b9050605560020a811015612da557612db5565b612dae81612e11565b9150612dc1565b612dbe81612e53565b91505b50919050565b60006000612ddc612dd7846129dc565b6129dc565b9050605560020a811015612def57612dff565b612df881612e53565b9150612e0b565b612e0881612e11565b91505b50919050565b60006000612e1e836129dc565b9050605660020a811015612e3157612e41565b612e3a81612e9d565b9150612e4d565b612e4a81612edf565b91505b50919050565b60006000612e68612e63846129dc565b6129dc565b9050605660020a811015612e7b57612e8b565b612e8481612edf565b9150612e97565b612e9481612e9d565b91505b50919050565b60006000612eaa836129dc565b9050605760020a811015612ebd57612ecd565b612ec681612f29565b9150612ed9565b612ed681612f6b565b91505b50919050565b60006000612ef4612eef846129dc565b6129dc565b9050605760020a811015612f0757612f17565b612f1081612f6b565b9150612f23565b612f2081612f29565b91505b50919050565b60006000612f36836129dc565b9050605860020a811015612f4957612f59565b612f5281612fb5565b9150612f65565b612f6281612ff7565b91505b50919050565b60006000612f80612f7b846129dc565b6129dc565b9050605860020a811015612f9357612fa3565b612f9c81612ff7565b9150612faf565b612fac81612fb5565b91505b50919050565b60006000612fc2836129dc565b9050605960020a811015612fd557612fe5565b612fde81613041565b9150612ff1565b612fee81613083565b91505b50919050565b6000600061300c613007846129dc565b6129dc565b9050605960020a81101561301f5761302f565b61302881613083565b915061303b565b61303881613041565b91505b50919050565b6000600061304e836129dc565b9050605a60020a81101561306157613071565b61306a816130cd565b915061307d565b61307a8161310f565b91505b50919050565b60006000613098613093846129dc565b6129dc565b9050605a60020a8110156130ab576130bb565b6130b48161310f565b91506130c7565b6130c4816130cd565b91505b50919050565b600060006130da836129dc565b9050605b60020a8110156130ed576130fd565b6130f681613159565b9150613109565b6131068161319b565b91505b50919050565b6000600061312461311f846129dc565b6129dc565b9050605b60020a81101561313757613147565b6131408161319b565b9150613153565b61315081613159565b91505b50919050565b60006000613166836129dc565b9050605c60020a81101561317957613189565b613182816131e5565b9150613195565b6131928161196a565b91505b50919050565b600060006131b06131ab846129dc565b6129dc565b9050605c60020a8110156131c3576131d3565b6131cc8161196a565b91506131df565b6131dc816131e5565b91505b50919050565b600060006131f2836129dc565b9050605d60020a81101561320557613215565b61320e816119b4565b9150613221565b61321e816119f6565b91505b50919050565b60006000613234836129dc565b9050607b60020a81101561324757613257565b613250816132b3565b9150613263565b613260816132f5565b91505b50919050565b6000600061327e613279846129dc565b6129dc565b9050607b60020a811015613291576132a1565b61329a816132f5565b91506132ad565b6132aa816132b3565b91505b50919050565b600060006132c0836129dc565b9050607c60020a8110156132d3576132e3565b6132dc8161333f565b91506132ef565b6132ec81613381565b91505b50919050565b6000600061330a613305846129dc565b6129dc565b9050607c60020a81101561331d5761332d565b61332681613381565b9150613339565b6133368161333f565b91505b50919050565b6000600061334c836129dc565b9050607d60020a81101561335f5761336f565b613368816133cb565b915061337b565b6133788161340d565b91505b50919050565b60006000613396613391846129dc565b6129dc565b9050607d60020a8110156133a9576133b9565b6133b28161340d565b91506133c5565b6133c2816133cb565b91505b50919050565b600060006133d8836129dc565b9050607e60020a8110156133eb576133fb565b6133f481613457565b9150613407565b61340481613499565b91505b50919050565b6000600061342261341d846129dc565b6129dc565b9050607e60020a81101561343557613445565b61343e81613499565b9150613451565b61344e81613457565b91505b50919050565b60006000613464836129dc565b9050607f60020a81101561347757613487565b613480816134e3565b9150613493565b61349081613525565b91505b50919050565b600060006134ae6134a9846129dc565b6129dc565b9050607f60020a8110156134c1576134d1565b6134ca81613525565b91506134dd565b6134da816134e3565b91505b50919050565b600060006134f0836129dc565b9050608060020a81101561350357613513565b61350c8161356f565b915061351f565b61351c816135b1565b91505b50919050565b6000600061353a613535846129dc565b6129dc565b9050608060020a81101561354d5761355d565b613556816135b1565b9150613569565b6135668161356f565b91505b50919050565b6000600061357c836129dc565b9050608160020a81101561358f5761359f565b613598816135fb565b91506135ab565b6135a88161363d565b91505b50919050565b600060006135c66135c1846129dc565b6129dc565b9050608160020a8110156135d9576135e9565b6135e28161363d565b91506135f5565b6135f2816135fb565b91505b50919050565b60006000613608836129dc565b9050608260020a81101561361b5761362b565b61362481613687565b9150613637565b613634816136c9565b91505b50919050565b6000600061365261364d846129dc565b6129dc565b9050608260020a81101561366557613675565b61366e816136c9565b9150613681565b61367e81613687565b91505b50919050565b60006000613694836129dc565b9050608360020a8110156136a7576136b7565b6136b081613713565b91506136c3565b6136c081613755565b91505b50919050565b600060006136de6136d9846129dc565b6129dc565b9050608360020a8110156136f157613701565b6136fa81613755565b915061370d565b61370a81613713565b91505b50919050565b60006000613720836129dc565b9050608460020a81101561373357613743565b61373c8161379f565b915061374f565b61374c816137e1565b91505b50919050565b6000600061376a613765846129dc565b6129dc565b9050608460020a81101561377d5761378d565b613786816137e1565b9150613799565b6137968161379f565b91505b50919050565b600060006137ac836129dc565b9050608560020a8110156137bf576137cf565b6137c88161382b565b91506137db565b6137d88161386d565b91505b50919050565b600060006137f66137f1846129dc565b6129dc565b9050608560020a81101561380957613819565b6138128161386d565b9150613825565b6138228161382b565b91505b50919050565b60006000613838836129dc565b9050608660020a81101561384b5761385b565b613854816138b7565b9150613867565b613864816138f9565b91505b50919050565b6000600061388261387d846129dc565b6129dc565b9050608660020a811015613895576138a5565b61389e816138f9565b91506138b1565b6138ae816138b7565b91505b50919050565b600060006138c4836129dc565b9050608760020a8110156138d7576138e7565b6138e081613943565b91506138f3565b6138f081613985565b91505b50919050565b6000600061390e613909846129dc565b6129dc565b9050608760020a81101561392157613931565b61392a81613985565b915061393d565b61393a81613943565b91505b50919050565b60006000613950836129dc565b9050608860020a81101561396357613973565b61396c816139cf565b915061397f565b61397c81613a11565b91505b50919050565b6000600061399a613995846129dc565b6129dc565b9050608860020a8110156139ad576139bd565b6139b681613a11565b91506139c9565b6139c6816139cf565b91505b50919050565b600060006139dc836129dc565b9050608960020a8110156139ef576139ff565b6139f881613a5b565b9150613a0b565b613a0881613a9d565b91505b50919050565b60006000613a26613a21846129dc565b6129dc565b9050608960020a811015613a3957613a49565b613a4281613a9d565b9150613a55565b613a5281613a5b565b91505b50919050565b60006000613a68836129dc565b9050608a60020a811015613a7b57613a8b565b613a8481613ae7565b9150613a97565b613a9481613b29565b91505b50919050565b60006000613ab2613aad846129dc565b6129dc565b9050608a60020a811015613ac557613ad5565b613ace81613b29565b9150613ae1565b613ade81613ae7565b91505b50919050565b60006000613af4836129dc565b9050608b60020a811015613b0757613b17565b613b1081613b73565b9150613b23565b613b2081613bb5565b91505b50919050565b60006000613b3e613b39846129dc565b6129dc565b9050608b60020a811015613b5157613b61565b613b5a81613bb5565b9150613b6d565b613b6a81613b73565b91505b50919050565b60006000613b80836129dc565b9050608c60020a811015613b9357613ba3565b613b9c81613bff565b9150613baf565b613bac81613c41565b91505b50919050565b60006000613bca613bc5846129dc565b6129dc565b9050608c60020a811015613bdd57613bed565b613be681613c41565b9150613bf9565b613bf681613bff565b91505b50919050565b60006000613c0c836129dc565b9050608d60020a811015613c1f57613c2f565b613c2881613c8b565b9150613c3b565b613c3881613ccd565b91505b50919050565b60006000613c56613c51846129dc565b6129dc565b9050608d60020a811015613c6957613c79565b613c7281613ccd565b9150613c85565b613c8281613c8b565b91505b50919050565b60006000613c98836129dc565b9050608e60020a811015613cab57613cbb565b613cb481613d17565b9150613cc7565b613cc481613d59565b91505b50919050565b60006000613ce2613cdd846129dc565b6129dc565b9050608e60020a811015613cf557613d05565b613cfe81613d59565b9150613d11565b613d0e81613d17565b91505b50919050565b60006000613d24836129dc565b9050608f60020a811015613d3757613d47565b613d4081613da3565b9150613d53565b613d5081613de5565b91505b50919050565b60006000613d6e613d69846129dc565b6129dc565b9050608f60020a811015613d8157613d91565b613d8a81613de5565b9150613d9d565b613d9a81613da3565b91505b50919050565b60006000613db0836129dc565b9050609060020a811015613dc357613dd3565b613dcc81613e2f565b9150613ddf565b613ddc81613e71565b91505b50919050565b60006000613dfa613df5846129dc565b6129dc565b9050609060020a811015613e0d57613e1d565b613e1681613e71565b9150613e29565b613e2681613e2f565b91505b50919050565b60006000613e3c836129dc565b9050609160020a811015613e4f57613e5f565b613e5881613ebb565b9150613e6b565b613e6881613efd565b91505b50919050565b60006000613e86613e81846129dc565b6129dc565b9050609160020a811015613e9957613ea9565b613ea281613efd565b9150613eb5565b613eb281613ebb565b91505b50919050565b60006000613ec8836129dc565b9050609260020a811015613edb57613eeb565b613ee481613f47565b9150613ef7565b613ef481613f89565b91505b50919050565b60006000613f12613f0d846129dc565b6129dc565b9050609260020a811015613f2557613f35565b613f2e81613f89565b9150613f41565b613f3e81613f47565b91505b50919050565b60006000613f54836129dc565b9050609360020a811015613f6757613f77565b613f7081613fd3565b9150613f83565b613f8081614015565b91505b50919050565b60006000613f9e613f99846129dc565b6129dc565b9050609360020a811015613fb157613fc1565b613fba81614015565b9150613fcd565b613fca81613fd3565b91505b50919050565b60006000613fe0836129dc565b9050609460020a811015613ff357614003565b613ffc8161405f565b915061400f565b61400c816140a1565b91505b50919050565b6000600061402a614025846129dc565b6129dc565b9050609460020a81101561403d5761404d565b614046816140a1565b9150614059565b6140568161405f565b91505b50919050565b6000600061406c836129dc565b9050609560020a81101561407f5761408f565b614088816140eb565b915061409b565b6140988161412d565b91505b50919050565b600060006140b66140b1846129dc565b6129dc565b9050609560020a8110156140c9576140d9565b6140d28161412d565b91506140e5565b6140e2816140eb565b91505b50919050565b600060006140f8836129dc565b9050609660020a81101561410b5761411b565b61411481614177565b9150614127565b614124816141b9565b91505b50919050565b6000600061414261413d846129dc565b6129dc565b9050609660020a81101561415557614165565b61415e816141b9565b9150614171565b61416e81614177565b91505b50919050565b60006000614184836129dc565b9050609760020a811015614197576141a7565b6141a081614203565b91506141b3565b6141b081614245565b91505b50919050565b600060006141ce6141c9846129dc565b6129dc565b9050609760020a8110156141e1576141f1565b6141ea81614245565b91506141fd565b6141fa81614203565b91505b50919050565b60006000614210836129dc565b9050609860020a81101561422357614233565b61422c8161428f565b915061423f565b61423c816142d1565b91505b50919050565b6000600061425a614255846129dc565b6129dc565b9050609860020a81101561426d5761427d565b614276816142d1565b9150614289565b6142868161428f565b91505b50919050565b6000600061429c836129dc565b9050609960020a8110156142af576142bf565b6142b88161431b565b91506142cb565b6142c88161435d565b91505b50919050565b600060006142e66142e1846129dc565b6129dc565b9050609960020a8110156142f957614309565b6143028161435d565b9150614315565b6143128161431b565b91505b50919050565b60006000614328836129dc565b9050609a60020a81101561433b5761434b565b614344816143a7565b9150614357565b614354816143e9565b91505b50919050565b6000600061437261436d846129dc565b6129dc565b9050609a60020a81101561438557614395565b61438e816143e9565b91506143a1565b61439e816143a7565b91505b50919050565b600060006143b4836129dc565b9050609b60020a8110156143c7576143d7565b6143d081614433565b91506143e3565b6143e081614475565b91505b50919050565b600060006143fe6143f9846129dc565b6129dc565b9050609b60020a81101561441157614421565b61441a81614475565b915061442d565b61442a81614433565b91505b50919050565b60006000614440836129dc565b9050609c60020a81101561445357614463565b61445c816144bf565b915061446f565b61446c81614501565b91505b50919050565b6000600061448a614485846129dc565b6129dc565b9050609c60020a81101561449d576144ad565b6144a681614501565b91506144b9565b6144b6816144bf565b91505b50919050565b600060006144cc836129dc565b9050609d60020a8110156144df576144ef565b6144e88161454b565b91506144fb565b6144f88161458d565b91505b50919050565b60006000614516614511846129dc565b6129dc565b9050609d60020a81101561452957614539565b6145328161458d565b9150614545565b6145428161454b565b91505b50919050565b60006000614558836129dc565b9050609e60020a81101561456b5761457b565b614574816145d7565b9150614587565b61458481614619565b91505b50919050565b600060006145a261459d846129dc565b6129dc565b9050609e60020a8110156145b5576145c5565b6145be81614619565b91506145d1565b6145ce816145d7565b91505b50919050565b600060006145e4836129dc565b9050609f60020a8110156145f757614607565b61460081614663565b9150614613565b614610816146a5565b91505b50919050565b6000600061462e614629846129dc565b6129dc565b9050609f60020a81101561464157614651565b61464a816146a5565b915061465d565b61465a81614663565b91505b50919050565b60006000614670836129dc565b905060a060020a81101561468357614693565b61468c816146ef565b915061469f565b61469c81614731565b91505b50919050565b600060006146ba6146b5846129dc565b6129dc565b905060a060020a8110156146cd576146dd565b6146d681614731565b91506146e9565b6146e6816146ef565b91505b50919050565b600060006146fc836129dc565b905060a160020a81101561470f5761471f565b6147188161477b565b915061472b565b614728816147bd565b91505b50919050565b60006000614746614741846129dc565b6129dc565b905060a160020a81101561475957614769565b614762816147bd565b9150614775565b6147728161477b565b91505b50919050565b60006000614788836129dc565b905060a260020a81101561479b576147ab565b6147a481614807565b91506147b7565b6147b481614849565b91505b50919050565b600060006147d26147cd846129dc565b6129dc565b905060a260020a8110156147e5576147f5565b6147ee81614849565b9150614801565b6147fe81614807565b91505b50919050565b60006000614814836129dc565b905060a360020a81101561482757614837565b61483081614893565b9150614843565b614840816148d5565b91505b50919050565b6000600061485e614859846129dc565b6129dc565b905060a360020a81101561487157614881565b61487a816148d5565b915061488d565b61488a81614893565b91505b50919050565b600060006148a0836129dc565b905060a460020a8110156148b3576148c3565b6148bc8161491f565b91506148cf565b6148cc81614961565b91505b50919050565b600060006148ea6148e5846129dc565b6129dc565b905060a460020a8110156148fd5761490d565b61490681614961565b9150614919565b6149168161491f565b91505b50919050565b6000600061492c836129dc565b905060a560020a81101561493f5761494f565b614948816149ab565b915061495b565b614958816149ed565b91505b50919050565b60006000614976614971846129dc565b6129dc565b905060a560020a81101561498957614999565b614992816149ed565b91506149a5565b6149a2816149ab565b91505b50919050565b600060006149b8836129dc565b905060a660020a8110156149cb576149db565b6149d481614a37565b91506149e7565b6149e481614a79565b91505b50919050565b60006000614a026149fd846129dc565b6129dc565b905060a660020a811015614a1557614a25565b614a1e81614a79565b9150614a31565b614a2e81614a37565b91505b50919050565b60006000614a44836129dc565b905060a760020a811015614a5757614a67565b614a6081614ac3565b9150614a73565b614a7081614b05565b91505b50919050565b60006000614a8e614a89846129dc565b6129dc565b905060a760020a811015614aa157614ab1565b614aaa81614b05565b9150614abd565b614aba81614ac3565b91505b50919050565b60006000614ad0836129dc565b905060a860020a811015614ae357614af3565b614aec81614b4f565b9150614aff565b614afc81614b91565b91505b50919050565b60006000614b1a614b15846129dc565b6129dc565b905060a860020a811015614b2d57614b3d565b614b3681614b91565b9150614b49565b614b4681614b4f565b91505b50919050565b60006000614b5c836129dc565b905060a960020a811015614b6f57614b7f565b614b7881614bdb565b9150614b8b565b614b8881614c1d565b91505b50919050565b60006000614ba6614ba1846129dc565b6129dc565b905060a960020a811015614bb957614bc9565b614bc281614c1d565b9150614bd5565b614bd281614bdb565b91505b50919050565b60006000614be8836129dc565b905060aa60020a811015614bfb57614c0b565b614c0481614c67565b9150614c17565b614c1481614ca9565b91505b50919050565b60006000614c32614c2d846129dc565b6129dc565b905060aa60020a811015614c4557614c55565b614c4e81614ca9565b9150614c61565b614c5e81614c67565b91505b50919050565b60006000614c74836129dc565b905060ab60020a811015614c8757614c97565b614c9081614cf3565b9150614ca3565b614ca081614d35565b91505b50919050565b60006000614cbe614cb9846129dc565b6129dc565b905060ab60020a811015614cd157614ce1565b614cda81614d35565b9150614ced565b614cea81614cf3565b91505b50919050565b60006000614d00836129dc565b905060ac60020a811015614d1357614d23565b614d1c81614d7f565b9150614d2f565b614d2c81614dc1565b91505b50919050565b60006000614d4a614d45846129dc565b6129dc565b905060ac60020a811015614d5d57614d6d565b614d6681614dc1565b9150614d79565b614d7681614d7f565b91505b50919050565b60006000614d8c836129dc565b905060ad60020a811015614d9f57614daf565b614da881614e0b565b9150614dbb565b614db881614e4d565b91505b50919050565b60006000614dd6614dd1846129dc565b6129dc565b905060ad60020a811015614de957614df9565b614df281614e4d565b9150614e05565b614e0281614e0b565b91505b50919050565b60006000614e18836129dc565b905060ae60020a811015614e2b57614e3b565b614e3481614e97565b9150614e47565b614e4481614ed9565b91505b50919050565b60006000614e62614e5d846129dc565b6129dc565b905060ae60020a811015614e7557614e85565b614e7e81614ed9565b9150614e91565b614e8e81614e97565b91505b50919050565b60006000614ea4836129dc565b905060af60020a811015614eb757614ec7565b614ec081614f23565b9150614ed3565b614ed081614f65565b91505b50919050565b60006000614eee614ee9846129dc565b6129dc565b905060af60020a811015614f0157614f11565b614f0a81614f65565b9150614f1d565b614f1a81614f23565b91505b50919050565b60006000614f30836129dc565b905060b060020a811015614f4357614f53565b614f4c81614faf565b9150614f5f565b614f5c81614ff1565b91505b50919050565b60006000614f7a614f75846129dc565b6129dc565b905060b060020a811015614f8d57614f9d565b614f9681614ff1565b9150614fa9565b614fa681614faf565b91505b50919050565b60006000614fbc836129dc565b905060b160020a811015614fcf57614fdf565b614fd881612a11565b9150614feb565b614fe881612a23565b91505b50919050565b60006000615006615001846129dc565b6129dc565b905060b160020a81101561501957615029565b61502281612a23565b9150615035565b61503281612a11565b91505b5091905056";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("loop-exp-4b-100k______a6616d3c0d567d66a39509265b0da159f3e37e491c7a6ef78995324ae0ba559b", "[vm]") {
  std::string bytecode_str = "606060405260e060020a60003504633392ffc8811461003f5780633c77b95c1461006a578063ce67bda6146100c2578063ebbbe00b146100e8575b610002565b346100025761010e600435602435604435600082815b83811015610120579085900a90600101610055565b346100025761010e600435602435604435600082815b83811015610120579085900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a90601001610080565b346100025761010e6004356024356044356000805b82811015610129575b6001016100d7565b346100025761010e6004356024356044356000805b82811015610129575b6010016100fd565b60408051918252519081900360200190f35b50949350505050565b5091939250505056";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("loop-divadd-10M______8cbe4da3d582b59b481644f6c0fdee99b20263faf1fb8ce8e34a9fc4e146a077", "[vm]") {
  std::string bytecode_str = "606060405263ffffffff60e060020a60003504166315d42327811461004257806359e3e1ea14610070578063c4f8b9fb1461009e578063e01330bb146100c9575bfe5b341561004a57fe5b61005e6004356024356044356064356100f4565b60408051918252519081900360200190f35b341561007857fe5b61005e60043560243560443560643561011e565b60408051918252519081900360200190f35b34156100a657fe5b61005e600435602435604435610152565b60408051918252519081900360200190f35b34156100d157fe5b61005e600435602435604435610179565b60408051918252519081900360200190f35b600084815b83811015610110578486830991505b6001016100f9565b8192505b5050949350505050565b600084815b8381101561011057858281151561013657fe5b04850191505b600101610123565b8192505b5050949350505050565b600083815b8381101561016c57908401905b600101610157565b8192505b50509392505050565b600083815b8381101561016c57908402905b60010161017e565b8192505b505093925050505600a165627a7a72305820065081bd1e9fdffccd251332523241eaabd0fb1881a06529599a9c67d0a568e50029";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("loop-add-10M______5c0bcc64ea53ba66564fffc011787768e911914b980b779def109e39e7b8a5c2", "[vm]") {
  std::string bytecode_str = "606060405263ffffffff60e060020a60003504166315d42327811461004257806359e3e1ea14610070578063c4f8b9fb1461009e578063e01330bb146100c9575bfe5b341561004a57fe5b61005e6004356024356044356064356100f4565b60408051918252519081900360200190f35b341561007857fe5b61005e60043560243560443560643561011e565b60408051918252519081900360200190f35b34156100a657fe5b61005e600435602435604435610152565b60408051918252519081900360200190f35b34156100d157fe5b61005e600435602435604435610179565b60408051918252519081900360200190f35b600084815b83811015610110578486830991505b6001016100f9565b8192505b5050949350505050565b600084815b8381101561011057858281151561013657fe5b04850191505b600101610123565b8192505b5050949350505050565b600083815b8381101561016c57908401905b600101610157565b8192505b50509392505050565b600083815b8381101561016c57908402905b60010161017e565b8192505b505093925050505600a165627a7a72305820065081bd1e9fdffccd251332523241eaabd0fb1881a06529599a9c67d0a568e50029";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("ackermann33______9ca98b508adbdde3ddffac1cb761f46e4a972d5dcc060f51cbec1ce11f17ac84", "[vm]") {
  std::string bytecode_str = "60e060020a6000350480632839e92814601e57806361047ff414603457005b602a6004356024356047565b8060005260206000f35b603d6004356099565b8060005260206000f35b600082600014605457605e565b8160010190506093565b81600014606957607b565b60756001840360016047565b90506093565b609060018403608c85600186036047565b6047565b90505b92915050565b6000816000148060a95750816001145b60b05760b7565b81905060cf565b60c1600283036099565b60cb600184036099565b0190505b91905056";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());

}

TEST_CASE("ackermann32______2c220fb24fa74c1103827f156dee5953dbb59bc82e00c9d44e838175dc67e5ba", "[vm]") {
  std::string bytecode_str = "60e060020a6000350480632839e92814601e57806361047ff414603457005b602a6004356024356047565b8060005260206000f35b603d6004356099565b8060005260206000f35b600082600014605457605e565b8160010190506093565b81600014606957607b565b60756001840360016047565b90506093565b609060018403608c85600186036047565b6047565b90505b92915050565b6000816000148060a95750816001145b60b05760b7565b81905060cf565b60c1600283036099565b60cb600184036099565b0190505b91905056";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("loop-mulmod-2M______e7bcb6168cc420c350cb8e46fc0e4193087cec3caf5ec8e1037eb8e0cb8890e1", "[vm]") {
  std::string bytecode_str = "606060405263ffffffff60e060020a60003504166315d4232781146022575b6000565b346000576038600435602435604435606435604a565b60408051918252519081900360200190f35b600084815b838110156064578486830991505b600101604f565b8192505b50509493505050505600a165627a7a723058200b2f52fbc8327bac47da1762338f70ad17310de956a58bbbca8ee58378f357900029";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("loop-exp-1b-1M______dc13c59f93368d567ca54b18844958fd2634507758610cc03e3a8e3ed19f2b1e", "[vm]") {
  std::string bytecode_str = "606060405260e060020a60003504633392ffc8811461003f5780633c77b95c1461006a578063ce67bda6146100c2578063ebbbe00b146100e8575b610002565b346100025761010e600435602435604435600082815b83811015610120579085900a90600101610055565b346100025761010e600435602435604435600082815b83811015610120579085900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a90601001610080565b346100025761010e6004356024356044356000805b82811015610129575b6001016100d7565b346100025761010e6004356024356044356000805b82811015610129575b6010016100fd565b60408051918252519081900360200190f35b50949350505050565b5091939250505056";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("loop-exp-32b-100k______c441959642aba02713db192952a1ab606b7de70410504696abbe9e24c787d3a3", "[vm]") {
  std::string bytecode_str = "606060405260e060020a60003504633392ffc8811461003f5780633c77b95c1461006a578063ce67bda6146100c2578063ebbbe00b146100e8575b610002565b346100025761010e600435602435604435600082815b83811015610120579085900a90600101610055565b346100025761010e600435602435604435600082815b83811015610120579085900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a90601001610080565b346100025761010e6004356024356044356000805b82811015610129575b6001016100d7565b346100025761010e6004356024356044356000805b82811015610129575b6010016100fd565b60408051918252519081900360200190f35b50949350505050565b5091939250505056";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("ackermann31______ec9c697bacfc0222a155e3dfb773c7af8d830fd04dcb7dd5cfabc11ef286dbff", "[vm]") {
  std::string bytecode_str = "60e060020a6000350480632839e92814601e57806361047ff414603457005b602a6004356024356047565b8060005260206000f35b603d6004356099565b8060005260206000f35b600082600014605457605e565b8160010190506093565b81600014606957607b565b60756001840360016047565b90506093565b609060018403608c85600186036047565b6047565b90505b92915050565b6000816000148060a95750816001145b60b05760b7565b81905060cf565b60c1600283036099565b60cb600184036099565b0190505b91905056";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("loop-exp-8b-100k______7af55eaae7594831f1c1a4ed4fbc9d2fec423b5de4319079187ae66183eb26c5", "[vm]") {
  std::string bytecode_str = "606060405260e060020a60003504633392ffc8811461003f5780633c77b95c1461006a578063ce67bda6146100c2578063ebbbe00b146100e8575b610002565b346100025761010e600435602435604435600082815b83811015610120579085900a90600101610055565b346100025761010e600435602435604435600082815b83811015610120579085900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a90601001610080565b346100025761010e6004356024356044356000805b82811015610129575b6001016100d7565b346100025761010e6004356024356044356000805b82811015610129575b6010016100fd565b60408051918252519081900360200190f35b50949350505050565b5091939250505056";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("fibonacci10______aa39e6e6cb25a56031874d788400c4ca511cba5b20cc82b63f25270006cd3d7b", "[vm]") {
  std::string bytecode_str = "60e060020a6000350480632839e92814601e57806361047ff414603457005b602a6004356024356047565b8060005260206000f35b603d6004356099565b8060005260206000f35b600082600014605457605e565b8160010190506093565b81600014606957607b565b60756001840360016047565b90506093565b609060018403608c85600186036047565b6047565b90505b92915050565b6000816000148060a95750816001145b60b05760b7565b81905060cf565b60c1600283036099565b60cb600184036099565b0190505b91905056";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("loop-exp-16b-100k______e3c31a352e72a71e814fb5324abb479c88ff30b29f6191ca097483536bba1121", "[vm]") {
  std::string bytecode_str = "606060405260e060020a60003504633392ffc8811461003f5780633c77b95c1461006a578063ce67bda6146100c2578063ebbbe00b146100e8575b610002565b346100025761010e600435602435604435600082815b83811015610120579085900a90600101610055565b346100025761010e600435602435604435600082815b83811015610120579085900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a90601001610080565b346100025761010e6004356024356044356000805b82811015610129575b6001016100d7565b346100025761010e6004356024356044356000805b82811015610129575b6010016100fd565b60408051918252519081900360200190f35b50949350505050565b5091939250505056";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("loop-divadd-unr100-10M______11eb4a4dbb8a456df4bd281916d914690f0994d7bbf808822d1fea68dbd04073", "[vm]") {
  std::string bytecode_str = "60606040526000357c0100000000000000000000000000000000000000000000000000000000900463ffffffff1680635bc0d2f11461003b575bfe5b341561004357fe5b610074600480803590602001909190803590602001909190803590602001909190803590602001909190505061008a565b6040518082815260200191505060405180910390f35b600060006000869150600090505b838110156108185785828115156100ab57fe5b049150848201915085828115156100be57fe5b049150848201915085828115156100d157fe5b049150848201915085828115156100e457fe5b049150848201915085828115156100f757fe5b0491508482019150858281151561010a57fe5b0491508482019150858281151561011d57fe5b0491508482019150858281151561013057fe5b0491508482019150858281151561014357fe5b0491508482019150858281151561015657fe5b0491508482019150858281151561016957fe5b0491508482019150858281151561017c57fe5b0491508482019150858281151561018f57fe5b049150848201915085828115156101a257fe5b049150848201915085828115156101b557fe5b049150848201915085828115156101c857fe5b049150848201915085828115156101db57fe5b049150848201915085828115156101ee57fe5b0491508482019150858281151561020157fe5b0491508482019150858281151561021457fe5b0491508482019150858281151561022757fe5b0491508482019150858281151561023a57fe5b0491508482019150858281151561024d57fe5b0491508482019150858281151561026057fe5b0491508482019150858281151561027357fe5b0491508482019150858281151561028657fe5b0491508482019150858281151561029957fe5b049150848201915085828115156102ac57fe5b049150848201915085828115156102bf57fe5b049150848201915085828115156102d257fe5b049150848201915085828115156102e557fe5b049150848201915085828115156102f857fe5b0491508482019150858281151561030b57fe5b0491508482019150858281151561031e57fe5b0491508482019150858281151561033157fe5b0491508482019150858281151561034457fe5b0491508482019150858281151561035757fe5b0491508482019150858281151561036a57fe5b0491508482019150858281151561037d57fe5b0491508482019150858281151561039057fe5b049150848201915085828115156103a357fe5b049150848201915085828115156103b657fe5b049150848201915085828115156103c957fe5b049150848201915085828115156103dc57fe5b049150848201915085828115156103ef57fe5b0491508482019150858281151561040257fe5b0491508482019150858281151561041557fe5b0491508482019150858281151561042857fe5b0491508482019150858281151561043b57fe5b0491508482019150858281151561044e57fe5b0491508482019150858281151561046157fe5b0491508482019150858281151561047457fe5b0491508482019150858281151561048757fe5b0491508482019150858281151561049a57fe5b049150848201915085828115156104ad57fe5b049150848201915085828115156104c057fe5b049150848201915085828115156104d357fe5b049150848201915085828115156104e657fe5b049150848201915085828115156104f957fe5b0491508482019150858281151561050c57fe5b0491508482019150858281151561051f57fe5b0491508482019150858281151561053257fe5b0491508482019150858281151561054557fe5b0491508482019150858281151561055857fe5b0491508482019150858281151561056b57fe5b0491508482019150858281151561057e57fe5b0491508482019150858281151561059157fe5b049150848201915085828115156105a457fe5b049150848201915085828115156105b757fe5b049150848201915085828115156105ca57fe5b049150848201915085828115156105dd57fe5b049150848201915085828115156105f057fe5b0491508482019150858281151561060357fe5b0491508482019150858281151561061657fe5b0491508482019150858281151561062957fe5b0491508482019150858281151561063c57fe5b0491508482019150858281151561064f57fe5b0491508482019150858281151561066257fe5b0491508482019150858281151561067557fe5b0491508482019150858281151561068857fe5b0491508482019150858281151561069b57fe5b049150848201915085828115156106ae57fe5b049150848201915085828115156106c157fe5b049150848201915085828115156106d457fe5b049150848201915085828115156106e757fe5b049150848201915085828115156106fa57fe5b0491508482019150858281151561070d57fe5b0491508482019150858281151561072057fe5b0491508482019150858281151561073357fe5b0491508482019150858281151561074657fe5b0491508482019150858281151561075957fe5b0491508482019150858281151561076c57fe5b0491508482019150858281151561077f57fe5b0491508482019150858281151561079257fe5b049150848201915085828115156107a557fe5b049150848201915085828115156107b857fe5b049150848201915085828115156107cb57fe5b049150848201915085828115156107de57fe5b049150848201915085828115156107f157fe5b0491508482019150858281151561080457fe5b04915084820191505b606481019050610098565b8192505b50509493505050505600a165627a7a72305820c38c20b72770ea745144fec130354270a65a17f75c8e4d1ad15808766d62bcdc0029";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("fibonacci16______64fac88f45e60627f6828c45c53c43b0a1e245a25f011b88ad9e51994b179ca1", "[vm]") {
  std::string bytecode_str = "60e060020a6000350480632839e92814601e57806361047ff414603457005b602a6004356024356047565b8060005260206000f35b603d6004356099565b8060005260206000f35b600082600014605457605e565b8160010190506093565b81600014606957607b565b60756001840360016047565b90506093565b609060018403608c85600186036047565b6047565b90505b92915050565b6000816000148060a95750816001145b60b05760b7565b81905060cf565b60c1600283036099565b60cb600184036099565b0190505b91905056";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("loop-exp-2b-100k______d546cccc293768c0dfbf21a81cb82dcc7fe19e709cc85d697b22d1a12004ac7c", "[vm]") {
  std::string bytecode_str = "606060405260e060020a60003504633392ffc8811461003f5780633c77b95c1461006a578063ce67bda6146100c2578063ebbbe00b146100e8575b610002565b346100025761010e600435602435604435600082815b83811015610120579085900a90600101610055565b346100025761010e600435602435604435600082815b83811015610120579085900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a85900a90601001610080565b346100025761010e6004356024356044356000805b82811015610129575b6001016100d7565b346100025761010e6004356024356044356000805b82811015610129575b6010016100fd565b60408051918252519081900360200190f35b50949350505050565b5091939250505056";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}

TEST_CASE("suicide______4622c577440f9db4b3954a1de60bf2fac55886dcb0ec4ecaf906c25bc77372e7", "[vm]") {
  std::string bytecode_str = "33ff";
  params_t params =  Utils::params(Hex::hexToBytes(bytecode_str), bytes_t());
  ExternalMock ext {};
  VM vm {};
  Call call(0);
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  Gasometer gasometer(0);
  bytes_t* memoryBytes = new bytes_t();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(mem, sm, as, gasometer, params, ext, call, Utils::env());


  // then
}



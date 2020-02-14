#include <stdio.h>
#include "catch.hpp"
#include "utils.h"
#include "vm.h"

TEST_CASE("Less than comparison truthy", "[LT]") {
  // given
  // (PUSH1 ((60) 03))
	// (PUSH1 ((60) 01))
	// (LT (10))
  std::string bytecode_str = "6003600110";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Less than comparison not true", "[LT]") {
  // given
  // (PUSH1 ((60) 01))
	// (PUSH1 ((60) 03))
	// (LT (10))
  std::string bytecode_str = "6001600310";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Greater than comparison truthy", "[GT]") {
  // given
  // (PUSH1 ((60) 01))
	// (PUSH1 ((60) 03))
	// (GT (11))
  std::string bytecode_str = "6001600311";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Greater than comparison not true", "[GT]") {
  // given
  // (PUSH1 ((60) 03))
	// (PUSH1 ((60) 01))
	// (GT (11))
  std::string bytecode_str = "6003600111";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Equal comparison truthy", "[EQ]") {
  // given
  // (PUSH1 ((60) 03))
	// (PUSH1 ((60) 03))
	// (EQ (14))
  std::string bytecode_str = "6003600314";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Equal comparison not true", "[EQ]") {
  // given
  // (PUSH1 ((60) 03))
	// (PUSH1 ((60) 01))
	// (EQ (14))
  std::string bytecode_str = "6003600114";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Is zero comparison truthy", "[ISZERO]") {
  // given
  // (PUSH1 ((60) 00))
	// (ISZERO (15))
  std::string bytecode_str = "600015";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Is zero comparison not true", "[ISZERO]") {
  // given
  // (PUSH1 ((60) 01))
	// (ISZERO (15))
  std::string bytecode_str = "600115";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Comparison with many instructions", "[comparison]") {
  std::string bytecode_str = "601665012365124623818181811060005511600155146002556415235412358014600355";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  VM vm {};
  account_store_t* accountItems = new account_store_t();
  AccountState as(accountItems);
  std::vector<uint8_t>* memoryBytes = new std::vector<uint8_t>();
  Memory mem(memoryBytes);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytes, mem, sm, as, Utils::env());

  // then
  store_item_t item1 = Utils::accountStoreValue(0, accountItems);
  store_item_t item2 = Utils::accountStoreValue(1, accountItems);
  store_item_t item3 = Utils::accountStoreValue(2, accountItems);
  store_item_t item4 = Utils::accountStoreValue(3, accountItems);

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item1.second)
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(item2.second)
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(item3.second)
  );

  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(item4.second)
  );
}
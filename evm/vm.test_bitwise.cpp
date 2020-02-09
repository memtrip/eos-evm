#include <stdio.h>
#include "catch.hpp"
#include "utils.h"
#include "vm.h"

TEST_CASE("Bitwise AND", "[bitwise]") {
  // (PUSH1 ((60)03))
  // (PUSH1 ((60)09))
  // (AND (16))
  std::string bytecode_str = "6003600916";
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};
  std::map<uint256_t, uint256_t>* accountItems = new std::map<uint256_t,uint256_t>();
  AccountState as(accountItems);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytecode_array, sizeof(bytecode_array), sm, as);

  // then
  CHECK("1" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Bitwise OR", "[bitwise]") {
  // (PUSH1 ((60)02))
  // (PUSH1 ((60)04))
  // (AND (17))
  std::string bytecode_str = "6002600417";
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};
  std::map<uint256_t, uint256_t>* accountItems = new std::map<uint256_t,uint256_t>();
  AccountState as(accountItems);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytecode_array, sizeof(bytecode_array), sm, as);

  // then
  CHECK("6" == 
    Utils::uint256_2str(sm.top())
  );
}

TEST_CASE("Bitwise XOR", "[bitwise]") {
  // (PUSH1 ((60)02))
  // (PUSH1 ((60)07))
  // (XOR (18))
  std::string bytecode_str = "6002600718";
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};
  std::map<uint256_t, uint256_t>* accountItems = new std::map<uint256_t,uint256_t>();
  AccountState as(accountItems);
  std::vector<uint256_t>* stackItems = new std::vector<uint256_t>();
  StackMachine sm(stackItems);

  // when
  vm.execute(bytecode_array, sizeof(bytecode_array), sm, as);

  // then
  CHECK("5" == 
    Utils::uint256_2str(sm.top())
  );
}
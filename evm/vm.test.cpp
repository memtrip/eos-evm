#include <stdio.h>
#include "catch.hpp"
#include "utils.h"
#include "vm.h"

TEST_CASE("Add two numbers", "[ADD]") {
  // given
  // (PUSH32 ((7f)fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff))
	// (PUSH32 ((7f)fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff))
	// (ADD (01))
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01";
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};

  // when
  vm.execute(bytecode_array, sizeof(bytecode_array));

  // then
  CHECK("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe" == 
    Utils::uint256_2str(vm.stackTop())
  );
}

TEST_CASE("Subtract two numbers", "[SUB]") {
  // given
  // (PUSH1 ((60)05))
	// (PUSH1 ((60)03))
	// (SUB (01))
  std::string bytecode_str = "6005600303";
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};

  // when
  vm.execute(bytecode_array, sizeof(bytecode_array));

  // then
  CHECK("2" == 
    Utils::uint256_2str(vm.stackTop())
  );
}
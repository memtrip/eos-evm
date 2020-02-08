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
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};

  // when
  vm.execute(bytecode_array, sizeof(bytecode_array));

  // then
  CHECK("1" == 
    Utils::uint256_2str(vm.stackTop())
  );
}

TEST_CASE("Less than comparison not true", "[LT]") {
  // given
  // (PUSH1 ((60) 01))
	// (PUSH1 ((60) 03))
	// (LT (10))
  std::string bytecode_str = "6001600310";
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};

  // when
  vm.execute(bytecode_array, sizeof(bytecode_array));

  // then
  CHECK("0" == 
    Utils::uint256_2str(vm.stackTop())
  );
}

TEST_CASE("Greater than comparison truthy", "[GT]") {
  // given
  // (PUSH1 ((60) 01))
	// (PUSH1 ((60) 03))
	// (GT (11))
  std::string bytecode_str = "6001600311";
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};

  // when
  vm.execute(bytecode_array, sizeof(bytecode_array));

  // then
  CHECK("1" == 
    Utils::uint256_2str(vm.stackTop())
  );
}

TEST_CASE("Greater than comparison not true", "[GT]") {
  // given
  // (PUSH1 ((60) 03))
	// (PUSH1 ((60) 01))
	// (GT (11))
  std::string bytecode_str = "6003600111";
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};

  // when
  vm.execute(bytecode_array, sizeof(bytecode_array));

  // then
  CHECK("0" == 
    Utils::uint256_2str(vm.stackTop())
  );
}

TEST_CASE("Equal comparison truthy", "[EQ]") {
  // given
  // (PUSH1 ((60) 03))
	// (PUSH1 ((60) 03))
	// (EQ (14))
  std::string bytecode_str = "6003600314";
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};

  // when
  vm.execute(bytecode_array, sizeof(bytecode_array));

  // then
  CHECK("1" == 
    Utils::uint256_2str(vm.stackTop())
  );
}

TEST_CASE("Equal comparison not true", "[EQ]") {
  // given
  // (PUSH1 ((60) 03))
	// (PUSH1 ((60) 01))
	// (EQ (14))
  std::string bytecode_str = "6003600114";
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};

  // when
  vm.execute(bytecode_array, sizeof(bytecode_array));

  // then
  CHECK("0" == 
    Utils::uint256_2str(vm.stackTop())
  );
}

TEST_CASE("Is zero comparison truthy", "[ISZERO]") {
  // given
  // (PUSH1 ((60) 00))
	// (ISZERO (15))
  std::string bytecode_str = "600015";
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};

  // when
  vm.execute(bytecode_array, sizeof(bytecode_array));

  // then
  CHECK("1" == 
    Utils::uint256_2str(vm.stackTop())
  );
}

TEST_CASE("Is zero comparison not true", "[ISZERO]") {
  // given
  // (PUSH1 ((60) 01))
	// (ISZERO (15))
  std::string bytecode_str = "600115";
  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);
  VM vm {};

  // when
  vm.execute(bytecode_array, sizeof(bytecode_array));

  // then
  CHECK("0" == 
    Utils::uint256_2str(vm.stackTop())
  );
}
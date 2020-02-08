#include <stdio.h>
#include <vector>
#include "catch.hpp"
#include "instruction.h"
#include "utils.h"
#include "types.h"
#include "opcode.h"

std::vector<instruct_t> parse(std::string bytecode_str) {
  std::vector<instruct_t> values = std::vector<instruct_t>();

  char bytecode_array[bytecode_str.length() / 2];
  Utils::hex2bin(bytecode_str, bytecode_array);

  int position = 0;

  while (position < sizeof(bytecode_array)) {
    char index = bytecode_array[position];
    int instruction = Instruction::values[index];
    values.push_back(instruction);
    position++;
  }

  return values;
}

TEST_CASE("Instruction lookup 00-0B", "[instruction]" ) {
  // given
  std::vector<instruct_t> instructions = parse("000102030405060708090A0B");

  // ((STOP (0x00)), 0, 0, ZERO)
  REQUIRE(0x00 == Instruction::opcode(instructions.at(0)));
  REQUIRE(0x00 == Instruction::args(instructions.at(0)));
  REQUIRE(0x00 == Instruction::ret(instructions.at(0)));
  REQUIRE(0x00 == Instruction::tier(instructions.at(0)));

  // ((ADD (0x01)), 2, 1, VERY_LOW)
  REQUIRE(0x01 == Instruction::opcode(instructions.at(1)));
  REQUIRE(0x02 == Instruction::args(instructions.at(1)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(1)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(1)));

  // ((MUL (0x02)), 2, 1, LOW)
  REQUIRE(0x02 == Instruction::opcode(instructions.at(2)));
  REQUIRE(0x02 == Instruction::args(instructions.at(2)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(2)));
  REQUIRE(0x03 == Instruction::tier(instructions.at(2)));

  // ((SUB (0x03)), 2, 1, VERY_LOW)
  REQUIRE(0x03 == Instruction::opcode(instructions.at(3)));
  REQUIRE(0x02 == Instruction::args(instructions.at(3)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(3)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(3)));

  // ((DIV (0x04)), 2, 1, LOW)
  REQUIRE(0x04 == Instruction::opcode(instructions.at(4)));
  REQUIRE(0x02 == Instruction::args(instructions.at(4)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(4)));
  REQUIRE(0x03 == Instruction::tier(instructions.at(4)));

  // ((SDIV (0x05)), 2, 1, LOW)
  REQUIRE(0x05 == Instruction::opcode(instructions.at(5)));
  REQUIRE(0x02 == Instruction::args(instructions.at(5)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(5)));
  REQUIRE(0x03 == Instruction::tier(instructions.at(5)));

  // ((MOD (0x06)), 2, 1, LOW)
  REQUIRE(0x06 == Instruction::opcode(instructions.at(6)));
  REQUIRE(0x02 == Instruction::args(instructions.at(6)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(6)));
  REQUIRE(0x03 == Instruction::tier(instructions.at(6)));

  // ((SMOD (0x07)), 2, 1, LOW)
  REQUIRE(0x07 == Instruction::opcode(instructions.at(7)));
  REQUIRE(0x02 == Instruction::args(instructions.at(7)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(7)));
  REQUIRE(0x03 == Instruction::tier(instructions.at(7)));

  // ((ADDMOD (0x08)), 3, 1, MID)
  REQUIRE(0x08 == Instruction::opcode(instructions.at(8)));
  REQUIRE(0x03 == Instruction::args(instructions.at(8)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(8)));
  REQUIRE(0x04 == Instruction::tier(instructions.at(8)));

  // ((MULMOD (0x09)), 3, 1, MID)
  REQUIRE(0x09 == Instruction::opcode(instructions.at(9)));
  REQUIRE(0x03 == Instruction::args(instructions.at(9)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(9)));
  REQUIRE(0x04 == Instruction::tier(instructions.at(9)));

  // ((EXP (0x0A)), 2, 1, SPECIAL)
  REQUIRE(0x0A == Instruction::opcode(instructions.at(10)));
  REQUIRE(0x02 == Instruction::args(instructions.at(10)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(10)));
  REQUIRE(0x07 == Instruction::tier(instructions.at(10)));

  // ((SIGNEXTEND (0x0B)), 2, 1, SPECIAL)
  REQUIRE(0x0B == Instruction::opcode(instructions.at(11)));
  REQUIRE(0x02 == Instruction::args(instructions.at(11)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(11)));
  REQUIRE(0x07 == Instruction::tier(instructions.at(11)));
}

TEST_CASE("Instruction lookup 10-20", "[instruction]" ) {
  // given
  std::vector<instruct_t> instructions = parse("101112131415161718191A1B1C1D20");

  REQUIRE(0x10 == Instruction::opcode(instructions.at(0)));
  REQUIRE(0x11 == Instruction::opcode(instructions.at(1)));
  REQUIRE(0x12 == Instruction::opcode(instructions.at(2)));
  REQUIRE(0x13 == Instruction::opcode(instructions.at(3)));
  REQUIRE(0x14 == Instruction::opcode(instructions.at(4)));
  REQUIRE(0x15 == Instruction::opcode(instructions.at(5)));
  REQUIRE(0x16 == Instruction::opcode(instructions.at(6)));
  REQUIRE(0x17 == Instruction::opcode(instructions.at(7)));
  REQUIRE(0x18 == Instruction::opcode(instructions.at(8)));
  REQUIRE(0x19 == Instruction::opcode(instructions.at(9)));
  REQUIRE(0x1A == Instruction::opcode(instructions.at(10)));
  REQUIRE(0x1B == Instruction::opcode(instructions.at(11)));
  REQUIRE(0x1C == Instruction::opcode(instructions.at(12)));
  REQUIRE(0x1D == Instruction::opcode(instructions.at(13)));
  REQUIRE(0x20 == Instruction::opcode(instructions.at(14)));
}

TEST_CASE("Instruction pushBytes(PUSH32)", "[pushBytes(PUSH32)]" ) {
  REQUIRE(32 == Instruction::pushBytes(Instruction::values[Opcode::PUSH32]));
}

TEST_CASE("Instruction pushBytes(PUSH1)", "[pushBytes(PUSH1)]" ) {
  REQUIRE(1 == Instruction::pushBytes(Instruction::values[Opcode::PUSH1]));
}
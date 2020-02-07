#include <stdio.h>
#include <vector>
#include "catch.hpp"
#include "instruction.h"
#include "utils.h"

std::vector<unsigned int> parse(std::string bytecode_str) {
  std::vector<unsigned int> values = std::vector<unsigned int>();

  char bytecode_array[bytecode_str.length() / 2];
  hex2bin(bytecode_str, bytecode_array);

  int position = 0;

  while (position < sizeof(bytecode_array)) {
    char index = bytecode_array[position];
    int instruction = evm::Instructions::values[index];
    values.push_back(instruction);
    position++;
  }

  return values;
}

unsigned char opcode(unsigned int instruction) {
  return byteAt(instruction, 3);
}

unsigned char args(unsigned int instruction) {
  return byteAt(instruction, 2);
} 

unsigned char ret(unsigned int instruction) {
  return byteAt(instruction, 1);
} 

unsigned char tier(unsigned int instruction) {
  return byteAt(instruction, 0);
} 

TEST_CASE("Instruction lookup 00-0B", "[instruction]" ) {

  std::vector<unsigned int> instructions = parse("000102030405060708090A0B");

  // ((STOP (0x00)), 0, 0, ZERO)
  REQUIRE(0x00 == opcode(instructions.at(0)));
  REQUIRE(0x00 == args(instructions.at(0)));
  REQUIRE(0x00 == ret(instructions.at(0)));
  REQUIRE(0x00 == tier(instructions.at(0)));

  // ((ADD (0x01)), 2, 1, VERY_LOW)
  REQUIRE(0x01 == opcode(instructions.at(1)));
  REQUIRE(0x02 == args(instructions.at(1)));
  REQUIRE(0x01 == ret(instructions.at(1)));
  REQUIRE(0x02 == tier(instructions.at(1)));

  // ((MUL (0x02)), 2, 1, LOW)
  REQUIRE(0x02 == opcode(instructions.at(2)));
  REQUIRE(0x02 == args(instructions.at(2)));
  REQUIRE(0x01 == ret(instructions.at(2)));
  REQUIRE(0x03 == tier(instructions.at(2)));

  // ((SUB (0x03)), 2, 1, VERY_LOW)
  REQUIRE(0x03 == opcode(instructions.at(3)));
  REQUIRE(0x02 == args(instructions.at(3)));
  REQUIRE(0x01 == ret(instructions.at(3)));
  REQUIRE(0x02 == tier(instructions.at(3)));

  // ((DIV (0x04)), 2, 1, LOW)
  REQUIRE(0x04 == opcode(instructions.at(4)));
  REQUIRE(0x02 == args(instructions.at(4)));
  REQUIRE(0x01 == ret(instructions.at(4)));
  REQUIRE(0x03 == tier(instructions.at(4)));

  // ((SDIV (0x05)), 2, 1, LOW)
  REQUIRE(0x05 == opcode(instructions.at(5)));
  REQUIRE(0x02 == args(instructions.at(5)));
  REQUIRE(0x01 == ret(instructions.at(5)));
  REQUIRE(0x03 == tier(instructions.at(5)));

  // ((MOD (0x06)), 2, 1, LOW)
  REQUIRE(0x06 == opcode(instructions.at(6)));
  REQUIRE(0x02 == args(instructions.at(6)));
  REQUIRE(0x01 == ret(instructions.at(6)));
  REQUIRE(0x03 == tier(instructions.at(6)));

  // ((SMOD (0x07)), 2, 1, LOW)
  REQUIRE(0x07 == opcode(instructions.at(7)));
  REQUIRE(0x02 == args(instructions.at(7)));
  REQUIRE(0x01 == ret(instructions.at(7)));
  REQUIRE(0x03 == tier(instructions.at(7)));

  // ((ADDMOD (0x08)), 3, 1, MID)
  REQUIRE(0x08 == opcode(instructions.at(8)));
  REQUIRE(0x03 == args(instructions.at(8)));
  REQUIRE(0x01 == ret(instructions.at(8)));
  REQUIRE(0x04 == tier(instructions.at(8)));

  // ((MULMOD (0x09)), 3, 1, MID)
  REQUIRE(0x09 == opcode(instructions.at(9)));
  REQUIRE(0x03 == args(instructions.at(9)));
  REQUIRE(0x01 == ret(instructions.at(9)));
  REQUIRE(0x04 == tier(instructions.at(9)));

  // ((EXP (0x0A)), 2, 1, SPECIAL)
  REQUIRE(0x0A == opcode(instructions.at(10)));
  REQUIRE(0x02 == args(instructions.at(10)));
  REQUIRE(0x01 == ret(instructions.at(10)));
  REQUIRE(0x07 == tier(instructions.at(10)));

  // ((SIGNEXTEND (0x0B)), 2, 1, SPECIAL)
  REQUIRE(0x0B == opcode(instructions.at(11)));
  REQUIRE(0x02 == args(instructions.at(11)));
  REQUIRE(0x01 == ret(instructions.at(11)));
  REQUIRE(0x07 == tier(instructions.at(11)));
}

TEST_CASE("Instruction lookup 10-20", "[instruction]" ) {

  std::vector<unsigned int> instructions = parse("101112131415161718191A1B1C1D20");

  REQUIRE(0x10 == opcode(instructions.at(0)));
  REQUIRE(0x11 == opcode(instructions.at(1)));
  REQUIRE(0x12 == opcode(instructions.at(2)));
  REQUIRE(0x13 == opcode(instructions.at(3)));
  REQUIRE(0x14 == opcode(instructions.at(4)));
  REQUIRE(0x15 == opcode(instructions.at(5)));
  REQUIRE(0x16 == opcode(instructions.at(6)));
  REQUIRE(0x17 == opcode(instructions.at(7)));
  REQUIRE(0x18 == opcode(instructions.at(8)));
  REQUIRE(0x19 == opcode(instructions.at(9)));
  REQUIRE(0x1A == opcode(instructions.at(10)));
  REQUIRE(0x1B == opcode(instructions.at(11)));
  REQUIRE(0x1C == opcode(instructions.at(12)));
  REQUIRE(0x1D == opcode(instructions.at(13)));
  REQUIRE(0x20 == opcode(instructions.at(14)));
}
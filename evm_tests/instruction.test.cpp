#include <stdio.h>
#include <vector>
#include "catch.hpp"
#include <evm/instruction.h>
#include <evm/utils.h>
#include <evm/types.h>
#include <evm/opcode.h>
#include <evm/hex.h>

std::vector<instruct_t> parse(std::string bytecode_str) {
  std::vector<instruct_t> values = std::vector<instruct_t>();

  bytes_t bytes = Hex::hexToBytes(bytecode_str);
  
  int position = 0;

  while (position < bytes.size()) {
    uint8_t index = bytes[position];
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

  // ((SIGNEXTEND (0x0B)), 2, 1, LOW)
  REQUIRE(0x0B == Instruction::opcode(instructions.at(11)));
  REQUIRE(0x02 == Instruction::args(instructions.at(11)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(11)));
  REQUIRE(0x03 == Instruction::tier(instructions.at(11)));
}

TEST_CASE("Instruction lookup 3d-0B", "[instruction]" ) {
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

  // ((SIGNEXTEND (0x0B)), 2, 1, LOW)
  REQUIRE(0x0B == Instruction::opcode(instructions.at(11)));
  REQUIRE(0x02 == Instruction::args(instructions.at(11)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(11)));
  REQUIRE(0x03 == Instruction::tier(instructions.at(11)));
}

TEST_CASE("Instruction lookup 10-1D", "[instruction]" ) {
  // given
  std::vector<instruct_t> instructions = parse("101112131415161718191A1B1C1D20");

  // ((LT (0x10)), 2, 1, VERY_LOW)
  REQUIRE(0x10 == Instruction::opcode(instructions.at(0)));
  REQUIRE(0x02 == Instruction::args(instructions.at(0)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(0)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(0)));

  // ((GT (0x11)), 2, 1, VERY_LOW)
  REQUIRE(0x11 == Instruction::opcode(instructions.at(1)));
  REQUIRE(0x02 == Instruction::args(instructions.at(1)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(1)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(1)));

  // ((SLT (0x12)), 2, 1, VERY_LOW)
  REQUIRE(0x12 == Instruction::opcode(instructions.at(2)));
  REQUIRE(0x02 == Instruction::args(instructions.at(2)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(2)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(2)));
  
  // ((SGT (0x13)), 2, 1, VERY_LOW)
  REQUIRE(0x13 == Instruction::opcode(instructions.at(3)));
  REQUIRE(0x02 == Instruction::args(instructions.at(3)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(3)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(3)));

  // ((EQ (0x14)), 2, 1, VERY_LOW)
  REQUIRE(0x14 == Instruction::opcode(instructions.at(4)));
  REQUIRE(0x02 == Instruction::args(instructions.at(4)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(4)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(4)));

  // ((ISZERO (0x15)), 1, 1, VERY_LOW)
  REQUIRE(0x15 == Instruction::opcode(instructions.at(5)));
  REQUIRE(0x01 == Instruction::args(instructions.at(5)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(5)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(5)));

  // ((AND (0x16)), 2, 1, VERY_LOW)
  REQUIRE(0x16 == Instruction::opcode(instructions.at(6)));
  REQUIRE(0x02 == Instruction::args(instructions.at(6)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(6)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(6)));

  // ((OR (0x17)), 2, 1, VERY_LOW)
  REQUIRE(0x17 == Instruction::opcode(instructions.at(7)));
  REQUIRE(0x02 == Instruction::args(instructions.at(7)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(7)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(7)));

  // ((XOR (0x18)), 2, 1, VERY_LOW)
  REQUIRE(0x18 == Instruction::opcode(instructions.at(8)));
  REQUIRE(0x02 == Instruction::args(instructions.at(8)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(8)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(8)));

  // ((NOT (0x19)), 2, 1, VERY_LOW)
  REQUIRE(0x19 == Instruction::opcode(instructions.at(9)));
  REQUIRE(0x01 == Instruction::args(instructions.at(9)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(9)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(9)));

  // ((BYTE (0x1A)), 2, 1, VERY_LOW)
  REQUIRE(0x1A == Instruction::opcode(instructions.at(10)));
  REQUIRE(0x02 == Instruction::args(instructions.at(10)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(10)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(10)));

  // ((SHL (0x1B)), 2, 1, VERY_LOW)
  REQUIRE(0x1B == Instruction::opcode(instructions.at(11)));
  REQUIRE(0x02 == Instruction::args(instructions.at(11)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(11)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(11)));

  // ((SHR (0x1C)), 2, 1, VERY_LOW)
  REQUIRE(0x1C == Instruction::opcode(instructions.at(12)));
  REQUIRE(0x02 == Instruction::args(instructions.at(12)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(12)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(12)));

  // ((SAR (0x1D)), 2, 1, VERY_LOW)
  REQUIRE(0x1D == Instruction::opcode(instructions.at(13)));
  REQUIRE(0x02 == Instruction::args(instructions.at(13)));
  REQUIRE(0x01 == Instruction::ret(instructions.at(13)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(13)));
}

TEST_CASE("Instruction lookup DUP1 - DUP16", "[instruction]" ) {

  // given
  std::vector<instruct_t> instructions = parse("808182838485868788898A8B8C8D8E8F");

  // ((DUP1 (0x80)), 1, 2, VERY_LOW)
  REQUIRE(0x80 == Instruction::opcode(instructions.at(0)));
  REQUIRE(1 == Instruction::args(instructions.at(0)));
  REQUIRE(2 == Instruction::ret(instructions.at(0)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(0)));
  
  // ((DUP2 (0x81)), 2, 3, VERY_LOW)
  REQUIRE(0x81 == Instruction::opcode(instructions.at(1)));
  REQUIRE(2 == Instruction::args(instructions.at(1)));
  REQUIRE(3 == Instruction::ret(instructions.at(1)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(1)));

  // ((DUP3 (0x82)), 3, 4, VERY_LOW)
  REQUIRE(0x82 == Instruction::opcode(instructions.at(2)));
  REQUIRE(3 == Instruction::args(instructions.at(2)));
  REQUIRE(4 == Instruction::ret(instructions.at(2)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(2)));

  // ((DUP4 (0x83)), 4, 5, VERY_LOW)
  REQUIRE(0x83 == Instruction::opcode(instructions.at(3)));
  REQUIRE(4 == Instruction::args(instructions.at(3)));
  REQUIRE(5 == Instruction::ret(instructions.at(3)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(3)));

  // ((DUP5 (0x84)), 5, 6, VERY_LOW)
  REQUIRE(0x84 == Instruction::opcode(instructions.at(4)));
  REQUIRE(5 == Instruction::args(instructions.at(4)));
  REQUIRE(6 == Instruction::ret(instructions.at(4)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(4)));

  // ((DUP6 (0x85)), 6, 7, VERY_LOW)
  REQUIRE(0x85 == Instruction::opcode(instructions.at(5)));
  REQUIRE(6 == Instruction::args(instructions.at(5)));
  REQUIRE(7 == Instruction::ret(instructions.at(5)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(5)));

  // ((DUP7 (0x86)), 7, 8, VERY_LOW)
  REQUIRE(0x86 == Instruction::opcode(instructions.at(6)));
  REQUIRE(7 == Instruction::args(instructions.at(6)));
  REQUIRE(8 == Instruction::ret(instructions.at(6)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(6)));

  // ((DUP8 (0x87)), 8, 9, VERY_LOW)
  REQUIRE(0x87 == Instruction::opcode(instructions.at(7)));
  REQUIRE(8 == Instruction::args(instructions.at(7)));
  REQUIRE(9 == Instruction::ret(instructions.at(7)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(7)));

  // ((DUP9 (0x88)), 9, 10, VERY_LOW)
  REQUIRE(0x88 == Instruction::opcode(instructions.at(8)));
  REQUIRE(9 == Instruction::args(instructions.at(8)));
  REQUIRE(10 == Instruction::ret(instructions.at(8)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(8)));

  // ((DUP10 (0x89)), 10, 11, VERY_LOW)
  REQUIRE(0x89 == Instruction::opcode(instructions.at(9)));
  REQUIRE(10 == Instruction::args(instructions.at(9)));
  REQUIRE(11 == Instruction::ret(instructions.at(9)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(9)));

  // ((DUP11 (0x8A)), 11, 12, VERY_LOW)
  REQUIRE(0x8A == Instruction::opcode(instructions.at(10)));
  REQUIRE(11 == Instruction::args(instructions.at(10)));
  REQUIRE(12 == Instruction::ret(instructions.at(10)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(10)));

  // ((DUP12 (0x8B)), 12, 13, VERY_LOW)
  REQUIRE(0x8B == Instruction::opcode(instructions.at(11)));
  REQUIRE(12 == Instruction::args(instructions.at(11)));
  REQUIRE(13 == Instruction::ret(instructions.at(11)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(11)));

  // ((DUP13 (0x8C)), 13, 14, VERY_LOW)
  REQUIRE(0x8C == Instruction::opcode(instructions.at(12)));
  REQUIRE(13 == Instruction::args(instructions.at(12)));
  REQUIRE(14 == Instruction::ret(instructions.at(12)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(12)));

  // ((DUP14 (0x8D)), 14, 15, VERY_LOW)
  REQUIRE(0x8D == Instruction::opcode(instructions.at(13)));
  REQUIRE(14 == Instruction::args(instructions.at(13)));
  REQUIRE(15 == Instruction::ret(instructions.at(13)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(13)));

  // ((DUP15 (0x8E)), 15, 16, VERY_LOW)
  REQUIRE(0x8E == Instruction::opcode(instructions.at(14)));
  REQUIRE(15 == Instruction::args(instructions.at(14)));
  REQUIRE(16 == Instruction::ret(instructions.at(14)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(14)));

  // ((DUP16 (0x8F)), 16, 17, VERY_LOW)
  REQUIRE(0x8F == Instruction::opcode(instructions.at(15)));
  REQUIRE(16 == Instruction::args(instructions.at(15)));
  REQUIRE(17 == Instruction::ret(instructions.at(15)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(15)));
}

TEST_CASE("Instruction lookup SWAP1 - SWAP16", "[instruction]" ) {

  // given
  std::vector<instruct_t> instructions = parse("909192939495969798999A9B9C9D9E9F");

  // ((SWAP1 (0x90)), 2, 2, VERY_LOW)
  REQUIRE(0x90 == Instruction::opcode(instructions.at(0)));
  REQUIRE(2 == Instruction::args(instructions.at(0)));
  REQUIRE(2 == Instruction::ret(instructions.at(0)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(0)));
  
  // ((SWAP2 (0x91)), 3, 3, VERY_LOW)
  REQUIRE(0x91 == Instruction::opcode(instructions.at(1)));
  REQUIRE(3 == Instruction::args(instructions.at(1)));
  REQUIRE(3 == Instruction::ret(instructions.at(1)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(1)));

  // ((SWAP3 (0x92)), 4, 4, VERY_LOW)
  REQUIRE(0x92 == Instruction::opcode(instructions.at(2)));
  REQUIRE(4 == Instruction::args(instructions.at(2)));
  REQUIRE(4 == Instruction::ret(instructions.at(2)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(2)));

  // ((SWAP4 (0x93)), 5, 5, VERY_LOW)
  REQUIRE(0x93 == Instruction::opcode(instructions.at(3)));
  REQUIRE(5 == Instruction::args(instructions.at(3)));
  REQUIRE(5 == Instruction::ret(instructions.at(3)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(3)));

  // ((SWAP5 (0x94)), 6, 6, VERY_LOW)
  REQUIRE(0x94 == Instruction::opcode(instructions.at(4)));
  REQUIRE(6 == Instruction::args(instructions.at(4)));
  REQUIRE(6 == Instruction::ret(instructions.at(4)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(4)));

  // ((SWAP6 (0x95)), 7, 7, VERY_LOW)
  REQUIRE(0x95 == Instruction::opcode(instructions.at(5)));
  REQUIRE(7 == Instruction::args(instructions.at(5)));
  REQUIRE(7 == Instruction::ret(instructions.at(5)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(5)));

  // ((SWAP7 (0x96)), 8, 8, VERY_LOW)
  REQUIRE(0x96 == Instruction::opcode(instructions.at(6)));
  REQUIRE(8 == Instruction::args(instructions.at(6)));
  REQUIRE(8 == Instruction::ret(instructions.at(6)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(6)));

  // ((SWAP8 (0x97)), 9, 9, VERY_LOW)
  REQUIRE(0x97 == Instruction::opcode(instructions.at(7)));
  REQUIRE(9 == Instruction::args(instructions.at(7)));
  REQUIRE(9 == Instruction::ret(instructions.at(7)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(7)));

  // ((SWAP9 (0x98)), 10, 10, VERY_LOW)
  REQUIRE(0x98 == Instruction::opcode(instructions.at(8)));
  REQUIRE(10 == Instruction::args(instructions.at(8)));
  REQUIRE(10 == Instruction::ret(instructions.at(8)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(8)));

  // ((SWAP10 (0x99)), 11, 11, VERY_LOW)
  REQUIRE(0x99 == Instruction::opcode(instructions.at(9)));
  REQUIRE(11 == Instruction::args(instructions.at(9)));
  REQUIRE(11 == Instruction::ret(instructions.at(9)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(9)));

  // ((SWAP11 (0x9A)), 12, 12, VERY_LOW)
  REQUIRE(0x9A == Instruction::opcode(instructions.at(10)));
  REQUIRE(12 == Instruction::args(instructions.at(10)));
  REQUIRE(12 == Instruction::ret(instructions.at(10)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(10)));

  // ((SWAP12 (0x9B)), 13, 13, VERY_LOW)
  REQUIRE(0x9B == Instruction::opcode(instructions.at(11)));
  REQUIRE(13 == Instruction::args(instructions.at(11)));
  REQUIRE(13 == Instruction::ret(instructions.at(11)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(11)));

  // ((SWAP13 (0x9C)), 14, 14, VERY_LOW)
  REQUIRE(0x9C == Instruction::opcode(instructions.at(12)));
  REQUIRE(14 == Instruction::args(instructions.at(12)));
  REQUIRE(14 == Instruction::ret(instructions.at(12)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(12)));

  // ((SWAP14 (0x9D)), 15, 15, VERY_LOW)
  REQUIRE(0x9D == Instruction::opcode(instructions.at(13)));
  REQUIRE(15 == Instruction::args(instructions.at(13)));
  REQUIRE(15 == Instruction::ret(instructions.at(13)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(13)));

  // ((SWAP15 (0x9E)), 16, 16, VERY_LOW)
  REQUIRE(0x9E == Instruction::opcode(instructions.at(14)));
  REQUIRE(16 == Instruction::args(instructions.at(14)));
  REQUIRE(16 == Instruction::ret(instructions.at(14)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(14)));

  // ((SWAP16 (0x9F)), 17, 17, VERY_LOW)
  REQUIRE(0x9F == Instruction::opcode(instructions.at(15)));
  REQUIRE(17 == Instruction::args(instructions.at(15)));
  REQUIRE(17 == Instruction::ret(instructions.at(15)));
  REQUIRE(0x02 == Instruction::tier(instructions.at(15)));
}


TEST_CASE("Instruction RETURN", "[instruction]" ) {

  std::vector<instruct_t> instructions = parse("f3");

  REQUIRE(0xf3 == Instruction::opcode(instructions.at(0)));
}

TEST_CASE("Instruction pushBytes(PUSH32)", "[instruction]" ) {
  REQUIRE(32 == Instruction::pushBytes(Instruction::values[Opcode::PUSH32]));
}

TEST_CASE("Instruction pushBytes(PUSH1)", "[instruction]" ) {
  REQUIRE(1 == Instruction::pushBytes(Instruction::values[Opcode::PUSH1]));
}

TEST_CASE("Instruction dupPosition(DUP16)", "[instruction]" ) {
  REQUIRE(15 == Instruction::dupPosition(Instruction::values[Opcode::DUP16]));
}

TEST_CASE("Instruction dupPosition(DUP10)", "[instruction]" ) {
  REQUIRE(9 == Instruction::dupPosition(Instruction::values[Opcode::DUP10]));
}

TEST_CASE("Instruction dupPosition(DUP5)", "[instruction]" ) {
  REQUIRE(4 == Instruction::dupPosition(Instruction::values[Opcode::DUP5]));
}

TEST_CASE("Instruction dupPosition(DUP1)", "[instruction]" ) {
  REQUIRE(0 == Instruction::dupPosition(Instruction::values[Opcode::DUP1]));
}

TEST_CASE("Instruction dupPosition(DUP13)", "[instruction]" ) {
  REQUIRE(12 == Instruction::dupPosition(Instruction::values[Opcode::DUP13]));
}

TEST_CASE("Instruction swapPosition(SWAP16)", "[instruction]" ) {
  REQUIRE(16 == Instruction::swapPosition(Instruction::values[Opcode::SWAP16]));
}

TEST_CASE("Instruction swapPosition(SWAP5)", "[instruction]" ) {
  REQUIRE(5 == Instruction::swapPosition(Instruction::values[Opcode::SWAP5]));
}

TEST_CASE("Instruction swapPosition(SWAP1)", "[instruction]" ) {
  REQUIRE(1 == Instruction::swapPosition(Instruction::values[Opcode::SWAP1]));
}

TEST_CASE("Instruction logBytes(LOG4)", "[instruction]" ) {
  REQUIRE(4 == Instruction::logTopics(Instruction::values[Opcode::LOG4]));
}

TEST_CASE("Instruction logBytes(LOG3)", "[instruction]" ) {
  REQUIRE(3 == Instruction::logTopics(Instruction::values[Opcode::LOG3]));
}

TEST_CASE("Instruction logBytes(LOG2)", "[instruction]" ) {
  REQUIRE(2 == Instruction::logTopics(Instruction::values[Opcode::LOG2]));
}

TEST_CASE("Instruction logBytes(LOG1)", "[instruction]" ) {
  REQUIRE(1 == Instruction::logTopics(Instruction::values[Opcode::LOG1]));
}

TEST_CASE("Instruction logBytes(LOG0)", "[instruction]" ) {
  REQUIRE(0 == Instruction::logTopics(Instruction::values[Opcode::LOG0]));
}
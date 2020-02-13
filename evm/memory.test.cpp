#include <vector>
#include "catch.hpp"
#include "memory.h"
#include "types.h"
#include "utils.h"

TEST_CASE("Memory write and read", "[memory]") {
  // given
  std::vector<uint8_t>* bytes = new std::vector<uint8_t>();
  Memory memory(bytes);
  
  // when
  memory.resize(0x80 + 32);

  memory.write(uint256_t(0x80), Utils::bigIntFromBigEndianBytes("abcdef"));

  REQUIRE("abcdef" == Utils::uint256_2str(memory.read(uint256_t(0x80)))); 
}

TEST_CASE("Memory write and read (1)", "[memory]") {
  // given
  std::vector<uint8_t>* bytes = new std::vector<uint8_t>();
  Memory memory(bytes);
  
  // when
  memory.resize(0x80 + 32);

  memory.write(uint256_t(0x80), uint256_t(0xabcdef));

  REQUIRE("abcdef" == Utils::uint256_2str(memory.read(uint256_t(0x80)))); 
}

TEST_CASE("Memory write and read (2)", "[memory]") {
  // given
  std::vector<uint8_t>* bytes = new std::vector<uint8_t>();
  Memory memory(bytes);
  
  // when
  memory.resize(32);
  memory.write(uint256_t(0x00), Utils::bigIntFromBigEndianBytes("06"));

  REQUIRE("6" == Utils::uint256_2str(memory.read(uint256_t(0x00)))); 
}

TEST_CASE("Memory write by byte and read", "[memory]") {
  // given
  std::vector<uint8_t>* bytes = new std::vector<uint8_t>();
  Memory memory(bytes);
  
  // when
  memory.resize(32);
  memory.writeByte(uint256_t(0x1d), uint256_t(0xab));
  memory.writeByte(uint256_t(0x1e), uint256_t(0xcd));
  memory.writeByte(uint256_t(0x1f), uint256_t(0xef));

  // then
  REQUIRE("abcdef" == Utils::uint256_2str(memory.read(uint256_t(0x00)))); 
}

TEST_CASE("Memory write single byte and read", "[memory]") {
  // given
  std::vector<uint8_t>* bytes = new std::vector<uint8_t>();
  Memory memory(bytes);
  
  // when
  memory.resize(32);
  memory.writeByte(uint256_t(0x1F), uint256_t(0x06));

  // then
  REQUIRE("6" == Utils::uint256_2str(memory.read(uint256_t(0x00)))); 
}
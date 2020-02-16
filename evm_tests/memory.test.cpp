#include <vector>
#include "catch.hpp"
#include "memory.h"
#include "types.h"
#include "utils.h"
#include "hex.h"

TEST_CASE("Memory write and read", "[memory]") {
  // given
  bytes_t* bytes = new bytes_t();
  Memory memory(bytes);
  
  // when
  memory.resize(0x80 + 32);

  memory.write(uint256_t(0x80), Utils::bigIntFromBigEndianBytes("abcdef"));

  REQUIRE("0000000000000000000000000000000000000000000000000000000000abcdef" == Utils::uint256_2str(memory.read(uint256_t(0x80)))); 
}

TEST_CASE("Memory write and read (1)", "[memory]") {
  // given
  bytes_t* bytes = new bytes_t();
  Memory memory(bytes);
  
  // when
  memory.resize(0x80 + 32);

  memory.write(uint256_t(0x80), uint256_t(0xabcdef));

  REQUIRE("0000000000000000000000000000000000000000000000000000000000abcdef" == Utils::uint256_2str(memory.read(uint256_t(0x80)))); 
}

TEST_CASE("Memory write and read (2)", "[memory]") {
  // given
  bytes_t* bytes = new bytes_t();
  Memory memory(bytes);
  
  // when
  memory.resize(32);
  memory.write(uint256_t(0x00), Utils::bigIntFromBigEndianBytes("06"));

  REQUIRE("0000000000000000000000000000000000000000000000000000000000000006" == Utils::uint256_2str(memory.read(uint256_t(0x00)))); 
}

TEST_CASE("Memory write by byte and read", "[memory]") {
  // given
  bytes_t* bytes = new bytes_t();
  Memory memory(bytes);
  
  // when
  memory.resize(32);
  memory.writeByte(uint256_t(0x1d), uint256_t(0xab));
  memory.writeByte(uint256_t(0x1e), uint256_t(0xcd));
  memory.writeByte(uint256_t(0x1f), uint256_t(0xef));

  // then
  REQUIRE("0000000000000000000000000000000000000000000000000000000000abcdef" == Utils::uint256_2str(memory.read(uint256_t(0x00)))); 
}

TEST_CASE("Memory write single byte and read", "[memory]") {
  // given
  bytes_t* bytes = new bytes_t();
  Memory memory(bytes);
  
  // when
  memory.resize(32);
  memory.writeByte(uint256_t(0x1F), uint256_t(0x06));

  // then
  REQUIRE("0000000000000000000000000000000000000000000000000000000000000006" == Utils::uint256_2str(memory.read(uint256_t(0x00)))); 
}

TEST_CASE("Memory read slice and write slice", "[memory]") {
  // given
  bytes_t* bytes = new bytes_t();
  Memory memory(bytes);
  
  // when
  memory.resize(32);

  bytes_t slice1 = Utils::hex2bin("aabbccee112233445566778899");
  memory.writeSlice(uint256_t(0x00), slice1);
  bytes_t readSlice1 = memory.readSlice(uint256_t(0x00), uint256_t(0x0D));
  REQUIRE("aabbccee112233445566778899" == Hex::bytesToHex(readSlice1)); 
  
  bytes_t slice2 = Utils::hex2bin("FFFF");
  memory.writeSlice(uint256_t(0x01), slice2);
  bytes_t readSlice2 = memory.readSlice(uint256_t(0x00), uint256_t(0x06));
  REQUIRE("aaffffee1122" == Hex::bytesToHex(readSlice2)); 

  bytes_t emptySlice = bytes_t();
  memory.writeSlice(uint256_t(0x1000), emptySlice);
  REQUIRE(32 == memory.size()); 
}
#include <stdio.h>
#include "catch.hpp"
#include "byte_reader.h"
#include "types.h"
#include "utils.h"

TEST_CASE("Byte Reader read(32)", "[byte_reader]" ) {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01600055";
  std::vector<uint8_t> bytes = Utils::hex2bin(bytecode_str);
  ByteReader byteReader(1, bytes);
  uint256_t item = byteReader.read(32);
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" == 
    Utils::uint256_2str(item)
  );
}

TEST_CASE("Byte Reader read(1)", "[byte_reader]" ) {
  std::vector<uint8_t> bytes = Utils::hex2bin("6001");
  ByteReader byteReader(1, bytes);
  uint256_t item = byteReader.read(1);
  CHECK("1" == 
    Utils::uint256_2str(item)
  );
}

TEST_CASE("Byte Reader read(17)", "[byte_reader]" ) {
  std::vector<uint8_t> bytes = Utils::hex2bin("6017");
  ByteReader byteReader(1, bytes);
  uint256_t item = byteReader.read(1);
  CHECK("17" == 
    Utils::uint256_2str(item)
  );
}

TEST_CASE("Byte Reader read(ABC9)", "[byte_reader]" ) {
  std::vector<uint8_t> bytes = Utils::hex2bin("ABC9");
  ByteReader byteReader(0, bytes);
  uint256_t item = byteReader.read(2);
  CHECK("abc9" == 
    Utils::uint256_2str(item)
  );
}

TEST_CASE("Byte Reader read(CD8967)", "[byte_reader]" ) {
  std::vector<uint8_t> bytes = Utils::hex2bin("CD8967");
  ByteReader byteReader(0, bytes);
  uint256_t item = byteReader.read(3);
  CHECK("cd8967" == 
    Utils::uint256_2str(item)
  );
}

TEST_CASE("Byte Reader read(AB78EE54)", "[byte_reader]" ) {
  std::vector<uint8_t> bytes = Utils::hex2bin("AB78EE54");
  ByteReader byteReader(0, bytes);
  uint256_t item = byteReader.read(4);
  CHECK("ab78ee54" == 
    Utils::uint256_2str(item)
  );
}

TEST_CASE("Byte Reader read(ABCDEF1234)", "[byte_reader]" ) {
  std::vector<uint8_t> bytes = Utils::hex2bin("ABCDEF1234");
  ByteReader byteReader(0, bytes);
  uint256_t item = byteReader.read(5);
  CHECK("abcdef1234" == 
    Utils::uint256_2str(item)
  );
}

TEST_CASE("Byte Reader read(ABCDEF123456)", "[byte_reader]" ) {
  std::vector<uint8_t> bytes = Utils::hex2bin("ABCDEF123456");
  ByteReader byteReader(0, bytes);
  uint256_t item = byteReader.read(6);
  CHECK("abcdef123456" == 
    Utils::uint256_2str(item)
  );
}
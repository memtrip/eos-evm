#include "catch.hpp"
#include "rlp.h"
#include "types.h"
#include "big_int.h"
#include "utils.h"

TEST_CASE("Empty byte array", "[rlp)]") {

  // given
  std::vector<uint8_t> bytes = std::vector<uint8_t>();
  std::vector<RLPItem> items = std::vector<RLPItem>();

  // when
  RLPDecode::decode(bytes, items);

  // then
  REQUIRE(0 == items.size()); 
}

//std::string str(v.begin(), v.end());

TEST_CASE("Small string", "[rlp)]") {

  // given
  std::vector<uint8_t> bytes = { 0x83, 'd', 'o', 'g' };
  std::vector<RLPItem> items = std::vector<RLPItem>();

  // when
  RLPDecode::decode(bytes, items);

  std::string result(items[0].bytes.begin(), items[0].bytes.end());

  // then
  REQUIRE(RLPType::STRING == items[0].type); 
  REQUIRE("dog" == result); 
}

TEST_CASE("Two small strings", "[rlp)]") {

  // given
  std::vector<uint8_t> bytes = { 
    0xc8, 0x83, 'c', 'a', 't',
    0x83, 'd', 'o', 'g'
  };
  std::vector<RLPItem> items = std::vector<RLPItem>();

  // when
  RLPDecode::decode(bytes, items);

  std::string result1(items[0].values[0].bytes.begin(), items[0].values[0].bytes.end());
  std::string result2(items[0].values[1].bytes.begin(), items[0].values[1].bytes.end());

  // then
  REQUIRE(RLPType::LIST == items[0].type); 
  REQUIRE("cat" == result1); 
  REQUIRE("dog" == result2); 
}

TEST_CASE("Null string", "[rlp)]") {

  // given
  std::vector<uint8_t> bytes = { 0x80 };
  std::vector<RLPItem> items = std::vector<RLPItem>();

  // when
  RLPDecode::decode(bytes, items);

  std::string result(items[0].bytes.begin(), items[0].bytes.end());

  // then
  REQUIRE(RLPType::STRING == items[0].type);
  REQUIRE("" == result);
}

TEST_CASE("Empty list", "[rlp)]") {

  // given
  std::vector<uint8_t> bytes = { 0xc0 };
  std::vector<RLPItem> items = std::vector<RLPItem>();

  // when
  RLPDecode::decode(bytes, items);

  std::string result(items[0].bytes.begin(), items[0].bytes.end());

  // then
  REQUIRE(RLPType::LIST == items[0].type);
  REQUIRE(0 == items[0].values.size());
}

TEST_CASE("Encoded integer (0x00)", "[rlp)]") {

  // given
  std::vector<uint8_t> bytes = { 0x00 };
  std::vector<RLPItem> items = std::vector<RLPItem>();

  // when
  RLPDecode::decode(bytes, items);

  // then
  REQUIRE(RLPType::STRING == items[0].type);
  REQUIRE(uint256_t(0) == BigInt::fromBigEndianBytes(items[0].bytes));
}

TEST_CASE("Encoded integer (0x0f)", "[rlp)]") {

  // given
  std::vector<uint8_t> bytes = { 0x0f };
  std::vector<RLPItem> items = std::vector<RLPItem>();

  // when
  RLPDecode::decode(bytes, items);

  // then
  REQUIRE(RLPType::STRING == items[0].type);
  REQUIRE(uint256_t(15) == BigInt::fromBigEndianBytes(items[0].bytes));
}

TEST_CASE("Encoded integer (0x82, 0x04, 0x00)", "[rlp)]") {

  // given
  std::vector<uint8_t> bytes = { 0x82, 0x04, 0x00 };
  std::vector<RLPItem> items = std::vector<RLPItem>();

  // when
  RLPDecode::decode(bytes, items);

  std::string result(items[0].bytes.begin(), items[0].bytes.end());

  // then
  REQUIRE(RLPType::STRING == items[0].type);
  REQUIRE(uint256_t(1024) == BigInt::fromBigEndianBytes(items[0].bytes));
}

TEST_CASE("Set", "[rlp)]") {

  // given
  std::vector<uint8_t> bytes = { 
    0xc7, 0xc0, 0xc1,0xc0,
    0xc3, 0xc0, 0xc1, 0xc0
  };

  std::vector<RLPItem> items = std::vector<RLPItem>();

  // when
  RLPDecode::decode(bytes, items);

  // then
  REQUIRE(1 == items.size());
  REQUIRE(3 == items[0].values.size());
  REQUIRE(0 == items[0].values[0].values.size());
  REQUIRE(1 == items[0].values[1].values.size());
  REQUIRE(2 == items[0].values[2].values.size());
  REQUIRE(0 == items[0].values[2].values[0].values.size());
  REQUIRE(1 == items[0].values[2].values[1].values.size());
}

TEST_CASE("Long string", "[rlp)]") {

  // given
  std::vector<uint8_t> bytes = { 
    0xb8, 0x38,
    'L', 'o', 'r', 'e',
    'm', ' ', 'i', 'p',
    's', 'u', 'm', ' ',
    'd', 'o', 'l', 'o',
    'r', ' ', 's', 'i',
    't', ' ', 'a', 'm',
    'e', 't', ',', ' ',
    'c', 'o', 'n', 's',
    'e', 'c', 't', 'e',
    't', 'u', 'r', ' ',
    'a', 'd', 'i', 'p',
    'i', 's', 'i', 'c',
    'i', 'n', 'g', ' ',
    'e', 'l', 'i', 't'
  };

  std::vector<RLPItem> items = std::vector<RLPItem>();

  // when
  RLPDecode::decode(bytes, items);

  // then
  std::string result(items[0].bytes.begin(), items[0].bytes.end());

  // then
  REQUIRE(RLPType::STRING == items[0].type);
  REQUIRE("Lorem ipsum dolor sit amet, consectetur adipisicing elit" == result);
}

TEST_CASE("Long string in bytes", "[rlp)]") {

  // given
  std::vector<uint8_t> bytes = { 
    0xc6, 0x82, 0x7a, 0x77,
    0xc1, 0x04, 0x01
  };

  std::vector<RLPItem> items = std::vector<RLPItem>();

  // when
  RLPDecode::decode(bytes, items);

  // then
  std::string result2(items[0].values[0].bytes.begin(), items[0].values[0].bytes.end());

  // then
  REQUIRE(RLPType::LIST == items[0].type);
  REQUIRE(3 == items[0].values.size());
  REQUIRE("zw" == result2);
  REQUIRE(uint256_t(4) == BigInt::fromBigEndianBytes(items[0].values[1].values[0].bytes));
  REQUIRE(uint256_t(1) == BigInt::fromBigEndianBytes(items[0].values[2].bytes));
}

TEST_CASE("Payload", "[rlp)]") {

  // given
  std::string hex = "F86E12F86B80881BC16D674EC8000094CD2A3D9F938E13CD947EC05ABC7FE734DF8DD8268609184E72A00064801BA0C52C114D4F5A3BA904A9B3036E5E118FE0DBB987FE3955DA20F2CD8F6C21AB9CA06BA4C2874299A55AD947DBC98A25EE895AABF6B625C26C435E84BFD70EDF2F69";

  std::vector<uint8_t> bytes = Utils::hex2bin(hex);

  std::vector<RLPItem> items = std::vector<RLPItem>();

  // when
  RLPDecode::decode(bytes, items);

  // then
  REQUIRE(RLPType::LIST == items[0].type);
  REQUIRE(2 == items[0].values.size());
  REQUIRE(9 == items[0].values[1].values.size());
}

TEST_CASE("Payload (1)", "[rlp)]") {

  // given
  std::string hex = "f85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870a801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  std::vector<uint8_t> bytes = Utils::hex2bin(hex);

  std::vector<RLPItem> items = std::vector<RLPItem>();

  // when
  RLPDecode::decode(bytes, items);

  // then
  REQUIRE(RLPType::LIST == items[0].type);
  REQUIRE(9 == items[0].values.size());

  // nonce
  CHECK(uint256_t(0) == 
    BigInt::fromBigEndianBytes(items[0].values[0].bytes)
  );

  // gas price
  CHECK(uint256_t(0x01) == 
    BigInt::fromBigEndianBytes(items[0].values[1].bytes)
  );

  // gas limit
  CHECK(uint256_t(0x5208) == 
    BigInt::fromBigEndianBytes(items[0].values[2].bytes)
  );

  // to
  CHECK("095e7baea6a6c7c4c2dfeb977efac326af552d87" == 
    Utils::bytesTohex(items[0].values[3].bytes)
  );

  // value
  CHECK(uint256_t(0x0a) == 
    BigInt::fromBigEndianBytes(items[0].values[4].bytes)
  );

  // data
  CHECK("" == 
    Utils::bytesTohex(items[0].values[5].bytes)
  );

  // v
  CHECK(uint256_t(27) == 
    BigInt::fromBigEndianBytes(items[0].values[6].bytes)
  );
  
  // r
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == 
    Utils::bytesTohex(items[0].values[7].bytes)
  );
  

  // s
  CHECK("efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == 
    Utils::bytesTohex(items[0].values[8].bytes)
  );
}
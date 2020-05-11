#include "catch.hpp"
#include <memory>
#include <evm/rlp_decode.hpp>
#include <evm/types.h>
#include <evm/big_int.hpp>
#include <evm/utils.hpp>
#include <evm/hex.hpp>
#include "test_utils.hpp"

TEST_CASE("Empty byte array", "[rlp_decode]") {

  // given
  bytes_t bytes = bytes_t();

  // when
  rlp_list_t* items = new rlp_list_t();
  RLPDecode::decode(bytes, items);

  // then
  REQUIRE(0 == items->size()); 

  delete items;
}

TEST_CASE("Small string", "[rlp_decode]") {

  // given
  bytes_t bytes = { 0x83, 'd', 'o', 'g' };

  // when
  rlp_list_t* items = new rlp_list_t();
  RLPDecode::decode(bytes, items);

  bytes_t decodedBytes = std::get<bytes_t>(items->at(0).value);

  std::string result(decodedBytes.begin(), decodedBytes.end());

  // then
  REQUIRE(RLPType::STRING == items->at(0).type); 
  REQUIRE("dog" == result); 

  delete items;
}

TEST_CASE("Two small strings", "[rlp_decode]") {

  // given
  bytes_t bytes = { 
    0xc8, 0x83, 'c', 'a', 't',
    0x83, 'd', 'o', 'g'
  };

  // when
  rlp_list_t* items = new rlp_list_t();
  RLPDecode::decode(bytes, items);

  bytes_t bytes1 = std::get<bytes_t>(std::get<rlp_list_t>(items->at(0).value)[0].value);
  bytes_t bytes2 = std::get<bytes_t>(std::get<rlp_list_t>(items->at(0).value)[1].value);

  std::string result1(bytes1.begin(), bytes1.end());
  std::string result2(bytes2.begin(), bytes2.end());

  // then
  REQUIRE(RLPType::LIST == items->at(0).type); 
  REQUIRE("cat" == result1); 
  REQUIRE("dog" == result2); 

  delete items;
}

TEST_CASE("Null string", "[rlp_decode]") {

  // given
  bytes_t bytes = { 0x80 };

  // when
  rlp_list_t* items = new rlp_list_t();
  RLPDecode::decode(bytes, items);

  bytes_t decodedBytes = std::get<bytes_t>(items->at(0).value);

  std::string result(decodedBytes.begin(), decodedBytes.end());

  // then
  REQUIRE(RLPType::STRING == items->at(0).type);
  REQUIRE("" == result);

  delete items;
}

TEST_CASE("Empty list", "[rlp_decode]") {

  // given
  bytes_t bytes = { 0xc0 };

  // when
  rlp_list_t* items = new rlp_list_t();
  RLPDecode::decode(bytes, items);

  rlp_list_t list = std::get<rlp_list_t>(items->at(0).value);

  // then
  REQUIRE(RLPType::LIST == items->at(0).type);
  REQUIRE(0 == list.size());

  delete items;
}

TEST_CASE("Encoded integer (0x00)", "[rlp_decode]") {

  // given
  bytes_t bytes = { 0x00 };

  // when
  rlp_list_t* items = new rlp_list_t();
  RLPDecode::decode(bytes, items);

  bytes_t decodedBytes = std::get<bytes_t>(items->at(0).value);

  // then
  REQUIRE(RLPType::STRING == items->at(0).type);
  REQUIRE(uint256_t(0) == BigInt::fromBigEndianBytes(decodedBytes));

  delete items;
}

TEST_CASE("Encoded integer (0x0f)", "[rlp_decode]") {

  // given
  bytes_t bytes = { 0x0f };

  // when
  rlp_list_t* items = new rlp_list_t();
  RLPDecode::decode(bytes, items);

  bytes_t decodedBytes = std::get<bytes_t>(items->at(0).value);

  // then
  REQUIRE(RLPType::STRING == items->at(0).type);
  REQUIRE(uint256_t(15) == BigInt::fromBigEndianBytes(decodedBytes));
  
  delete items;
}

TEST_CASE("Encoded integer (0x82, 0x04, 0x00)", "[rlp_decode]") {

  // given
  bytes_t bytes = { 0x82, 0x04, 0x00 };

  // when
  rlp_list_t* items = new rlp_list_t();
  RLPDecode::decode(bytes, items);

  bytes_t decodedBytes = std::get<bytes_t>(items->at(0).value);

  std::string result(decodedBytes.begin(), decodedBytes.end());

  // then
  REQUIRE(RLPType::STRING == items->at(0).type);
  REQUIRE(uint256_t(1024) == BigInt::fromBigEndianBytes(decodedBytes));

  delete items;
}

TEST_CASE("Set", "[rlp_decode]") {

  // given
  bytes_t bytes = { 
    0xc7, 0xc0, 0xc1,0xc0,
    0xc3, 0xc0, 0xc1, 0xc0
  };

  // when
  rlp_list_t* items = new rlp_list_t();
  RLPDecode::decode(bytes, items);

  // then
  rlp_list_t parentList = std::get<rlp_list_t>(items->at(0).value);

  rlp_list_t childList = std::get<rlp_list_t>(parentList[2].value);

  REQUIRE(1 == items->size());
  REQUIRE(3 == parentList.size());
  REQUIRE(0 == std::get<rlp_list_t>(parentList[0].value).size());
  REQUIRE(1 == std::get<rlp_list_t>(parentList[1].value).size());
  REQUIRE(2 == childList.size());
  REQUIRE(0 == std::get<rlp_list_t>(childList[0].value).size());
  REQUIRE(1 == std::get<rlp_list_t>(childList[1].value).size());

  delete items;
}

TEST_CASE("Long string", "[rlp_decode]") {

  // given
  bytes_t bytes = { 
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

  // when
  rlp_list_t* items = new rlp_list_t();
  RLPDecode::decode(bytes, items);

  bytes_t decodedBytes = std::get<bytes_t>(items->at(0).value);

  // then
  std::string result(decodedBytes.begin(), decodedBytes.end());

  // then
  REQUIRE(RLPType::STRING == items->at(0).type);
  REQUIRE("Lorem ipsum dolor sit amet, consectetur adipisicing elit" == result);

  delete items;
}

TEST_CASE("Long string in bytes", "[rlp_decode]") {

  // given
  bytes_t bytes = { 
    0xc6, 0x82, 0x7a, 0x77,
    0xc1, 0x04, 0x01
  };

  // when
  rlp_list_t* items = new rlp_list_t();
  RLPDecode::decode(bytes, items);

  rlp_list_t parentList = std::get<rlp_list_t>(items->at(0).value);

  // then
  bytes_t decodedBytes = std::get<bytes_t>(parentList[0].value);
  std::string result2(decodedBytes.begin(), decodedBytes.end());

  rlp_list_t childList1 = std::get<rlp_list_t>(parentList[1].value);
  bytes_t decodedBytes1 = std::get<bytes_t>(childList1[0].value);
  bytes_t decodedBytes2 = std::get<bytes_t>(parentList[2].value);

  // // then
  REQUIRE(RLPType::LIST == items->at(0).type);
  REQUIRE(3 == parentList.size());
  REQUIRE(RLPType::STRING == parentList[0].type);
  REQUIRE(RLPType::LIST == parentList[1].type);
  REQUIRE(RLPType::STRING == childList1[0].type);
  REQUIRE(RLPType::STRING == parentList[2].type);
  REQUIRE("zw" == result2);
  REQUIRE(uint256_t(4) == BigInt::fromBigEndianBytes(decodedBytes1));
  REQUIRE(uint256_t(1) == BigInt::fromBigEndianBytes(decodedBytes2));

  delete items;
}

TEST_CASE("Payload", "[rlp_decode]") {

  // given
  std::string hex = "F86E12F86B80881BC16D674EC8000094CD2A3D9F938E13CD947EC05ABC7FE734DF8DD8268609184E72A00064801BA0C52C114D4F5A3BA904A9B3036E5E118FE0DBB987FE3955DA20F2CD8F6C21AB9CA06BA4C2874299A55AD947DBC98A25EE895AABF6B625C26C435E84BFD70EDF2F69";

  bytes_t bytes = Hex::hexToBytes(hex);

  // when
  rlp_list_t* items = new rlp_list_t();
  RLPDecode::decode(bytes, items);

  rlp_list_t list = std::get<rlp_list_t>(items->at(0).value);
  rlp_list_t childList = std::get<rlp_list_t>(list[1].value);

  // then
  REQUIRE(RLPType::LIST == items->at(0).type);
  REQUIRE(2 == list.size());
  REQUIRE(9 == childList.size());

  delete items;
}

TEST_CASE("Payload (1)", "[rlp_decode]") {

  // given
  std::string hex = "f85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870a801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  bytes_t bytes = Hex::hexToBytes(hex);

  // when
  rlp_list_t* items = new rlp_list_t();
  RLPDecode::decode(bytes, items);

  rlp_list_t parentList = std::get<rlp_list_t>(items->at(0).value);

  // then
  REQUIRE(RLPType::LIST == items->at(0).type);
  REQUIRE(9 == parentList.size());

  // nonce
  CHECK(uint256_t(0) == 
    BigInt::fromBigEndianBytes(std::get<bytes_t>(parentList[0].value))
  );

  // gas price
  CHECK(uint256_t(0x01) == 
    BigInt::fromBigEndianBytes(std::get<bytes_t>(parentList[1].value))
  );

  // gas limit
  CHECK(uint256_t(0x5208) == 
    BigInt::fromBigEndianBytes(std::get<bytes_t>(parentList[2].value))
  );

  // to
  CHECK("095e7baea6a6c7c4c2dfeb977efac326af552d87" == 
    TestUtils::bytesToHex(std::get<bytes_t>(parentList[3].value))
  );

  // value
  CHECK(uint256_t(0x0a) == 
    BigInt::fromBigEndianBytes(std::get<bytes_t>(parentList[4].value))
  );

  // data
  CHECK("" == 
    TestUtils::bytesToHex(std::get<bytes_t>(parentList[5].value))
  );

  // v
  CHECK(uint256_t(27) == 
    BigInt::fromBigEndianBytes(std::get<bytes_t>(parentList[6].value))
  );
  
  // r
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == 
    TestUtils::bytesToHex(std::get<bytes_t>(parentList[7].value))
  );

  // s
  CHECK("efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == 
    TestUtils::bytesToHex(std::get<bytes_t>(parentList[8].value))
  );

  delete items;
}
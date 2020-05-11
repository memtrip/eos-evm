#include "catch.hpp"
#include <memory>
#include <evm/rlp_encode.hpp>
#include <evm/types.h>
#include <evm/big_int.hpp>
#include <evm/utils.hpp>
#include <evm/hex.hpp>
#include "test_utils.hpp"

TEST_CASE("empty string", "[rlp_encode]") {

  // given
  bytes_t bytes = {};

  RLPItem item {
    RLPType::STRING,
    bytes
  };

  // when
  bytes_t result = RLPEncode::encode(item);

  // then
  CHECK(1 == result.size());
  CHECK("80" == TestUtils::bytesToHex(result)); 
}

TEST_CASE("Short string", "[rlp_encode]") {

  // given
  bytes_t bytes = { 'd', 'o', 'g' };

  RLPItem item {
    RLPType::STRING,
    bytes
  };

  // when
  bytes_t result = RLPEncode::encode(item);

  // then
  CHECK(4 == result.size());
  CHECK("83646f67" == TestUtils::bytesToHex(result)); 
}

TEST_CASE("empty list", "[rlp_encode]") {

  // given
  RLPItem item {
    RLPType::LIST,
    rlp_list_t {}
  };

  // when
  bytes_t result = RLPEncode::encode(item);

  // then
  CHECK(1 == result.size());
  CHECK("c0" == TestUtils::bytesToHex(result)); 
}

TEST_CASE("Short string list", "[rlp_encode]") {

  // given
  bytes_t bytes1 = { 'c', 'a', 't' };
  bytes_t bytes2 = { 'd', 'o', 'g' };
  
  RLPItem item1 {
    RLPType::STRING,
    bytes1
  };

  RLPItem item2 {
    RLPType::STRING,
    bytes2
  };

  RLPItem itemList {
    RLPType::LIST,
    rlp_list_t { item1, item2 }
  };

  // when
  bytes_t result = RLPEncode::encode(itemList);

  // then
  CHECK(9 == result.size());
  CHECK("c88363617483646f67" == TestUtils::bytesToHex(result)); 
}

TEST_CASE("Mixed nested list", "[rlp_encode]") {

  // given
  bytes_t bytes1 = { 'z', 'w' };
  bytes_t bytes2 = { 0x04 };
  bytes_t bytes3 = { 0x01 };
  
  RLPItem string1 {
    RLPType::STRING,
    bytes1
  };

  RLPItem string2 {
    RLPType::STRING,
    bytes2
  };

  RLPItem string3 {
    RLPType::STRING,
    bytes3
  };

  RLPItem list1 {
    RLPType::LIST,
    rlp_list_t { string2 }
  };


  RLPItem itemList {
    RLPType::LIST,
    rlp_list_t { string1, list1, string3 }
  };

  // when
  bytes_t result = RLPEncode::encode(itemList);

  // then
  CHECK(7 == result.size());
  CHECK("c6827a77c10401" == TestUtils::bytesToHex(result)); 
}

TEST_CASE("Multiple nested lists", "[rlp_encode]") {

  // given
  bytes_t bytes1 = { 'z', 'w' };
  bytes_t bytes2 = { 0x04 };
  bytes_t bytes3 = { 0x01 };
  
  RLPItem item8 {
    RLPType::LIST,
    rlp_list_t {}
  };

  RLPItem item7 {
    RLPType::LIST,
    rlp_list_t { item8 }
  };

  RLPItem item6 {
    RLPType::LIST,
    rlp_list_t { }
  };

  RLPItem item5 {
    RLPType::LIST,
    rlp_list_t { item6, item7 }
  };

  RLPItem item4 {
    RLPType::LIST,
    rlp_list_t { }
  };

  RLPItem item3 {
    RLPType::LIST,
    rlp_list_t { item4 }
  };

  RLPItem item2 {
    RLPType::LIST,
    rlp_list_t { }
  };

  RLPItem item1 {
    RLPType::LIST,
    rlp_list_t { item2, item3, item5 }
  };

  // when
  bytes_t result = RLPEncode::encode(item1);

  // then
  CHECK(8 == result.size());
  CHECK("c7c0c1c0c3c0c1c0" == TestUtils::bytesToHex(result)); 
}

TEST_CASE("Single int", "[rlp_encode]") {

  // given
  bytes_t bytes = { 0x0f };
  rlp_list_t values;

  RLPItem item {
    RLPType::STRING,
    bytes
  };

  // when
  bytes_t result = RLPEncode::encode(item);

  // then
  CHECK(1 == result.size());
  CHECK("0f" == TestUtils::bytesToHex(result)); 
}

TEST_CASE("Int", "[rlp_encode]") {

  // given
  bytes_t bytes = { 0x04, 0x00 };

  RLPItem item {
    RLPType::STRING,
    bytes
  };

  // when
  bytes_t result = RLPEncode::encode(item);

  // then
  CHECK(3 == result.size());
  CHECK("820400" == TestUtils::bytesToHex(result)); 
}

TEST_CASE("Long string encode", "[rlp_encode]") {

  // given
  bytes_t bytes = { 
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
  rlp_list_t values;

  RLPItem item {
    RLPType::STRING,
    bytes
  };

  // when
  bytes_t result = RLPEncode::encode(item);

  // then
  CHECK(58 == result.size());
  CHECK("b8384c6f72656d20697073756d20646f6c6f722073697420616d65742c20636f6e7365637465747572206164697069736963696e6720656c6974" == 
    TestUtils::bytesToHex(result)
  ); 
}

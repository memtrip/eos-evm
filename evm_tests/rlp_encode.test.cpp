#include "catch.hpp"
#include "rlp.h"
#include "types.h"
#include "big_int.h"
#include "utils.h"

TEST_CASE("empty string", "[rlp_encode]") {

  // given
  bytes_t bytes = {};
  std::vector<RLPItem> values;

  RLPItem item {
    RLPType::STRING,
    bytes,
    values
  };

  // when
  bytes_t result = RLPEncode::encode(item);

  // then
  CHECK(1 == result.size());
  CHECK("80" == Utils::bytesTohex(result)); 
}

TEST_CASE("Short string", "[rlp_encode]") {

  // given
  bytes_t bytes = { 'd', 'o', 'g' };
  std::vector<RLPItem> values;

  RLPItem item {
    RLPType::STRING,
    bytes,
    values
  };

  // when
  bytes_t result = RLPEncode::encode(item);

  // then
  CHECK(4 == result.size());
  CHECK("83646f67" == Utils::bytesTohex(result)); 
}

TEST_CASE("empty list", "[rlp_encode]") {

  // given
  RLPItem item {
    RLPType::LIST,
    bytes_t {},
    std::vector<RLPItem> {}
  };

  // when
  bytes_t result = RLPEncode::encode(item);

  // then
  CHECK(1 == result.size());
  CHECK("c0" == Utils::bytesTohex(result)); 
}

TEST_CASE("Short string list", "[rlp_encode]") {

  // given
  bytes_t bytes1 = { 'c', 'a', 't' };
  bytes_t bytes2 = { 'd', 'o', 'g' };
  
  RLPItem item1 {
    RLPType::STRING,
    bytes1,
    std::vector<RLPItem> {}
  };

  RLPItem item2 {
    RLPType::STRING,
    bytes2,
    std::vector<RLPItem> {}
  };

  RLPItem itemList {
    RLPType::LIST,
    bytes_t {},
    std::vector<RLPItem> { item1, item2 }
  };

  // when
  bytes_t result = RLPEncode::encode(itemList);

  // then
  CHECK(9 == result.size());
  CHECK("c88363617483646f67" == Utils::bytesTohex(result)); 
}

TEST_CASE("Mixed nested list", "[rlp_encode]") {

  // given
  bytes_t bytes1 = { 'z', 'w' };
  bytes_t bytes2 = { 0x04 };
  bytes_t bytes3 = { 0x01 };
  
  RLPItem string1 {
    RLPType::STRING,
    bytes1,
    std::vector<RLPItem> {}
  };

  RLPItem string2 {
    RLPType::STRING,
    bytes2,
    std::vector<RLPItem> {}
  };

  RLPItem string3 {
    RLPType::STRING,
    bytes3,
    std::vector<RLPItem> {}
  };

  RLPItem list1 {
    RLPType::LIST,
    bytes_t {},
    std::vector<RLPItem> { string2 }
  };


  RLPItem itemList {
    RLPType::LIST,
    bytes_t {},
    std::vector<RLPItem> { string1, list1, string3 }
  };

  // when
  bytes_t result = RLPEncode::encode(itemList);

  // then
  CHECK(7 == result.size());
  CHECK("c6827a77c10401" == Utils::bytesTohex(result)); 
}


TEST_CASE("Single int", "[rlp_encode]") {

  // given
  bytes_t bytes = { 0x0f };
  std::vector<RLPItem> values;

  RLPItem item {
    RLPType::STRING,
    bytes,
    values
  };

  // when
  bytes_t result = RLPEncode::encode(item);

  // then
  CHECK(1 == result.size());
  CHECK("0f" == Utils::bytesTohex(result)); 
}

TEST_CASE("Int", "[rlp_encode]") {

  // given
  bytes_t bytes = { 0x04, 0x00 };
  std::vector<RLPItem> values;

  RLPItem item {
    RLPType::STRING,
    bytes,
    values
  };

  // when
  bytes_t result = RLPEncode::encode(item);

  // then
  CHECK(3 == result.size());
  CHECK("820400" == Utils::bytesTohex(result)); 
}
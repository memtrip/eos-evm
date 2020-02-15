#include "catch.hpp"
#include "rlp.h"
#include "types.h"
#include "big_int.h"
#include "utils.h"

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
  REQUIRE(4 == result.size());
  REQUIRE("83646f67" == Utils::bytesTohex(result)); 
}

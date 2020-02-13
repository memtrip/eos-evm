#include <stdio.h>
#include "catch.hpp"
#include "big_int.h"
#include "types.h"
#include "utils.h"

/**
  These tests assume little-endian byte ordering
*/

TEST_CASE("Instantiate uint256_t from big endian string", "[fromBigEndianBytes]") {
  CHECK("100000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(Utils::bigIntFromBigEndianBytes("0100000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("100000000000000" == 
    Utils::uint256_2str(Utils::bigIntFromBigEndianBytes("0100000000000000"))
  );
  CHECK("1" == 
    Utils::uint256_2str(Utils::bigIntFromBigEndianBytes("01"))
  );
  CHECK("15" == 
    Utils::uint256_2str(Utils::bigIntFromBigEndianBytes("15"))
  );
  CHECK("1700000000000000" == 
    Utils::uint256_2str(Utils::bigIntFromBigEndianBytes("1700000000000000"))
  );
  CHECK("2400000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(Utils::bigIntFromBigEndianBytes("2400000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("1" == 
    Utils::uint256_2str(Utils::bigIntFromBigEndianBytes("01"))
  );
  CHECK("a00000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(Utils::bigIntFromBigEndianBytes("0A00000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("a00000000000000" == 
    Utils::uint256_2str(Utils::bigIntFromBigEndianBytes("0A00000000000000"))
  );
  CHECK("abcd" == 
    Utils::uint256_2str(Utils::bigIntFromBigEndianBytes("abcd"))
  );
  CHECK("abcdef" == 
    Utils::uint256_2str(Utils::bigIntFromBigEndianBytes("abcdef"))
  );
  CHECK("abcdef12" == 
    Utils::uint256_2str(Utils::bigIntFromBigEndianBytes("abcdef12"))
  );
  CHECK("1000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(Utils::bigIntFromBigEndianBytes("1000000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("10" == 
    Utils::uint256_2str(Utils::bigIntFromBigEndianBytes("10"))
  );
  CHECK("fffffffffffffffffffffffffffffffa" == 
    Utils::uint256_2str(Utils::bigIntFromBigEndianBytes("fffffffffffffffffffffffffffffffA"))
  );
  CHECK("fa" == 
    Utils::uint256_2str(Utils::bigIntFromBigEndianBytes("fA"))
  );
  CHECK("ff" == 
    Utils::uint256_2str(Utils::bigIntFromBigEndianBytes("ff"))
  );
}

TEST_CASE("Instantiate char* from uint256_t (1)", "[big_int]") {
  std::vector<uint8_t> output = BigInt::toBytes(uint256_t(21));
  CHECK("15" == 
    Utils::uint256_2str(BigInt::fromBytes(output))
  );
}

TEST_CASE("Instantiate char* from uint256_t (2)", "[big_int]") {
  std::vector<uint8_t> output = BigInt::toBytes(uint256_t(2100));
  CHECK("834" == 
    Utils::bytesTohex(&output)
  );
}

TEST_CASE("Instantiate char* from uint256_t (3)", "[big_int]") {
  std::vector<uint8_t> output = BigInt::toBytes(uint256_t(0x80));
  CHECK("80" == 
    Utils::bytesTohex(&output)
  );
}

TEST_CASE("Instantiate char* from uint256_t (4)", "[big_int]") {
  std::vector<uint8_t> output = BigInt::toBytes(uint256_t(0xabcdef));
  CHECK("abcdef" == 
    Utils::bytesTohex(&output)
  );
}

TEST_CASE("Instantiate char* from uint256_t (5)", "[big_int]") {
  uint256_t value = uint256_t(0xabcdef12);
  std::vector<uint8_t> output = BigInt::toBytes(uint256_t(0xabcdef12));
  CHECK("abcdef12" == 
    Utils::bytesTohex(&output)
  );
}

TEST_CASE("Instantiate char* from uint256_t (6)", "[big_int]") {
  uint256_t value = Utils::bigIntFromBigEndianBytes("abcdef12");
  std::vector<uint8_t> output = BigInt::toBytes(value);
  CHECK("abcdef12" == 
    Utils::bytesTohex(&output)
  );
}

TEST_CASE("Instantiate char* from uint256_t (7)", "[big_int]") {
  std::vector<uint8_t> output = BigInt::toBytes(uint256_t(0xef));
  CHECK("ef" == 
    Utils::bytesTohex(&output)
  );
}
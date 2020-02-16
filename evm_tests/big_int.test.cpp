#include <iostream>
#include "catch.hpp"
#include "big_int.h"
#include "types.h"
#include "utils.h"

/**
  These tests assume little-endian byte ordering
*/

TEST_CASE("Instantiate uint256_t from big endian string", "[fromBigEndianBytes]") {
  CHECK("0100000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(Utils::hex2bin("0100000000000000000000000000000000000000000000000000000000000000")))
  );
  CHECK("0000000000000000000000000000000000000000000000000100000000000000" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(Utils::hex2bin("0100000000000000")))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(Utils::hex2bin("01")))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000015" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(Utils::hex2bin("15")))
  );
  CHECK("0000000000000000000000000000000000000000000000001700000000000000" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(Utils::hex2bin("1700000000000000")))
  );
  CHECK("2400000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(Utils::hex2bin("2400000000000000000000000000000000000000000000000000000000000000")))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(Utils::hex2bin("00000000000000000000000000000001")))
  );

  CHECK("0a00000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(Utils::hex2bin("0A00000000000000000000000000000000000000000000000000000000000000")))
  );
  CHECK("0000000000000000000000000000000000000000000000000a00000000000000" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(Utils::hex2bin("0A00000000000000")))
  );
  CHECK("000000000000000000000000000000000000000000000000000000000000abcd" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(Utils::hex2bin("abcd")))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000abcdef" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(Utils::hex2bin("abcdef")))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000abcdef12" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(Utils::hex2bin("abcdef12")))
  );
  CHECK("1000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(Utils::hex2bin("1000000000000000000000000000000000000000000000000000000000000000")))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000010" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(Utils::hex2bin("10")))
  );
  CHECK("00000000000000000000000000000000fffffffffffffffffffffffffffffffa" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(Utils::hex2bin("fffffffffffffffffffffffffffffffA")))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000000fa" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(Utils::hex2bin("fA")))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(Utils::hex2bin("ff")))
  );
}

TEST_CASE("Instantiate char* from uint256_t (1)", "[big_int]") {
  bytes_t output = BigInt::toBytes(uint256_t(21));
  CHECK("0000000000000000000000000000000000000000000000000000000000000015" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(output))
  );
}

TEST_CASE("Instantiate char* from uint256_t (2)", "[big_int]") {
  bytes_t output = BigInt::toBytes(uint256_t(2100));
  CHECK("0000000000000000000000000000000000000000000000000000000000000834" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(output))
  );
}

TEST_CASE("Instantiate char* from uint256_t (3)", "[big_int]") {
  bytes_t output = BigInt::toBytes(uint256_t(0x80));
  CHECK("0000000000000000000000000000000000000000000000000000000000000080" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(output))
  );
}

TEST_CASE("Instantiate char* from uint256_t (4)", "[big_int]") {
  bytes_t output = BigInt::toBytes(uint256_t(0xabcdef));
  CHECK("0000000000000000000000000000000000000000000000000000000000abcdef" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(output))
  );
}

TEST_CASE("Instantiate char* from uint256_t (5)", "[big_int]") {
  uint256_t value = uint256_t(0xabcdef12);
  bytes_t output = BigInt::toBytes(uint256_t(0xabcdef12));
  CHECK("00000000000000000000000000000000000000000000000000000000abcdef12" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(output))
  );
}

TEST_CASE("Instantiate char* from uint256_t (6)", "[big_int]") {
  uint256_t value = Utils::bigIntFromBigEndianBytes("abcdef12");
  bytes_t output = BigInt::toBytes(value);
  CHECK("00000000000000000000000000000000000000000000000000000000abcdef12" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(output))
  );
}

TEST_CASE("Instantiate char* from uint256_t (7)", "[big_int]") {
  bytes_t output = BigInt::toBytes(uint256_t(0xef));
  CHECK("00000000000000000000000000000000000000000000000000000000000000ef" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(output))
  );
}
#include <iostream>
#include "catch.hpp"
#include <memory>
#include <evm/big_int.hpp>
#include <evm/types.h>
#include <evm/hex.hpp>
#include <evm/utils.h>

/**
  These tests assume little-endian byte ordering
*/

TEST_CASE("Instantiate uint256_t from big endian string", "[fromBigEndianBytes]") {
  CHECK("0100000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(BigInt::fromHex("0100000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("0000000000000000000000000000000000000000000000000100000000000000" == 
    Utils::uint256_2str(BigInt::fromHex("0100000000000000"))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(BigInt::fromHex("01"))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000015" == 
    Utils::uint256_2str(BigInt::fromHex("15"))
  );
  CHECK("0000000000000000000000000000000000000000000000001700000000000000" == 
    Utils::uint256_2str(BigInt::fromHex("1700000000000000"))
  );
  CHECK("2400000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(BigInt::fromHex("2400000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(BigInt::fromHex("00000000000000000000000000000001"))
  );

  CHECK("0a00000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(BigInt::fromHex("0A00000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("0000000000000000000000000000000000000000000000000a00000000000000" == 
    Utils::uint256_2str(BigInt::fromHex("0A00000000000000"))
  );
  CHECK("000000000000000000000000000000000000000000000000000000000000abcd" == 
    Utils::uint256_2str(BigInt::fromHex("abcd"))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000abcdef" == 
    Utils::uint256_2str(BigInt::fromHex("abcdef"))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000abcdef12" == 
    Utils::uint256_2str(BigInt::fromHex("abcdef12"))
  );
  CHECK("1000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(BigInt::fromHex("1000000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000010" == 
    Utils::uint256_2str(BigInt::fromHex("10"))
  );
  CHECK("00000000000000000000000000000000fffffffffffffffffffffffffffffffa" == 
    Utils::uint256_2str(BigInt::fromHex("fffffffffffffffffffffffffffffffA"))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000000fa" == 
    Utils::uint256_2str(BigInt::fromHex("fA"))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" == 
    Utils::uint256_2str(BigInt::fromHex("ff"))
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

TEST_CASE("From compressed key", "[big_int]") {
  bytes_t output = Hex::hexToBytes("034005a4ab6b6eca2d03053038b8ea5f9b9e06c0d50092e0a15418524bb2c8b38e");

  compressed_key_t compressedKey;
  for (int i = 0; i < output.size(); i++) {
    compressedKey[i] = output[i];
  }

  CHECK("4005a4ab6b6eca2d03053038b8ea5f9b9e06c0d50092e0a15418524bb2c8b38e" == 
    Utils::uint256_2str(BigInt::fromCompressedKey(compressedKey))
  );
}
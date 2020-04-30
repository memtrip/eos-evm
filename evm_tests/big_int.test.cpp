#include "catch.hpp"
#include "test_utils.hpp"

#include <memory>

#include <evm/big_int.hpp>
#include <evm/types.h>
#include <evm/hex.hpp>
#include <evm/utils.hpp>

/**
  These tests assume little-endian byte ordering
*/

TEST_CASE("Instantiate uint256_t from big endian string", "[fromBigEndianBytes]") {
  CHECK("0100000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(TestUtils::fromHex("0100000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("0000000000000000000000000000000000000000000000000100000000000000" == 
    Utils::uint256_2str(TestUtils::fromHex("0100000000000000"))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(TestUtils::fromHex("01"))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000015" == 
    Utils::uint256_2str(TestUtils::fromHex("15"))
  );
  CHECK("0000000000000000000000000000000000000000000000001700000000000000" == 
    Utils::uint256_2str(TestUtils::fromHex("1700000000000000"))
  );
  CHECK("2400000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(TestUtils::fromHex("2400000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(TestUtils::fromHex("00000000000000000000000000000001"))
  );

  CHECK("0a00000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(TestUtils::fromHex("0A00000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("0000000000000000000000000000000000000000000000000a00000000000000" == 
    Utils::uint256_2str(TestUtils::fromHex("0A00000000000000"))
  );
  CHECK("000000000000000000000000000000000000000000000000000000000000abcd" == 
    Utils::uint256_2str(TestUtils::fromHex("abcd"))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000abcdef" == 
    Utils::uint256_2str(TestUtils::fromHex("abcdef"))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000abcdef12" == 
    Utils::uint256_2str(TestUtils::fromHex("abcdef12"))
  );
  CHECK("1000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(TestUtils::fromHex("1000000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("0000000000000000000000000000000000000000000000000000000000000010" == 
    Utils::uint256_2str(TestUtils::fromHex("10"))
  );
  CHECK("00000000000000000000000000000000fffffffffffffffffffffffffffffffa" == 
    Utils::uint256_2str(TestUtils::fromHex("fffffffffffffffffffffffffffffffA"))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000000fa" == 
    Utils::uint256_2str(TestUtils::fromHex("fA"))
  );
  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" == 
    Utils::uint256_2str(TestUtils::fromHex("ff"))
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

TEST_CASE("toFixed32", "[big_int]") {
  // given
  uint256_t value = BigInt::fromBigEndianBytes(Hex::hexToBytes("b8ea5f9b9e06c0d50092e0a15418524bb2c8b38e"));

  // when
  std::array<uint8_t, 32> result = BigInt::toFixed32(value);

  // then
  std::array<uint8_t, 32> expected {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xb8, 0xea, 0x5f, 0x9b, 0x9e, 0x06, 0xc0, 0xd5, 0x00, 0x92, 0xe0, 0xa1, 
    0x54, 0x18, 0x52, 0x4b, 0xb2, 0xc8, 0xb3, 0x8e
  };
  
  CHECK(expected == result);
}

TEST_CASE("toFixed32 with forward padding", "[big_int]") {
  // given
  uint256_t value = BigInt::fromBigEndianBytes(Hex::hexToBytes("000000000000000000000000b8ea5f9b9e06c0d50092e0a15418524bb2c8b38e"));

  // when
  std::array<uint8_t, 32> result = BigInt::toFixed32(value);

  // then
  std::array<uint8_t, 32> expected {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xb8, 0xea, 0x5f, 0x9b, 0x9e, 0x06, 0xc0, 0xd5, 0x00, 0x92, 0xe0, 0xa1, 
    0x54, 0x18, 0x52, 0x4b, 0xb2, 0xc8, 0xb3, 0x8e
  };
  
  CHECK(expected == result);
}

TEST_CASE("load32 from a set of bytes that is less than 32 bytes in size", "[big_int]") {

  // given
  bytes_t data = Hex::hexToBytes("00000073d98e39"); 

  uint256_t word1 = BigInt::load32(0, std::make_shared<bytes_t>(data));
  CHECK("00000073d98e3900000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(word1)
  );
}

TEST_CASE("load32 from various positions in a byte array that is more than 32 bytes in length", "[big_int]") {

  // given
  bytes_t data = Hex::hexToBytes("608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390a160b8806100826000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a723158209551755b4e59ca6cf78d79f5356d91565950805937074458700610f23c6ecf9b64736f6c63430005100032"); 

  uint256_t word1 = BigInt::load32(0, std::make_shared<bytes_t>(data));
  CHECK("608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8f9" == 
    Utils::uint256_2str(word1)
  );

  uint256_t word2 = BigInt::load32(1, std::make_shared<bytes_t>(data));
  CHECK("8060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8f97e" == 
    Utils::uint256_2str(word2)
  );

  uint256_t word3 = BigInt::load32(32, std::make_shared<bytes_t>(data));
  CHECK("7e55f0f0fd9eeb7fb46e030516363d4cfe1ad630604051808273ffffffffffff" == 
    Utils::uint256_2str(word3)
  );

  uint256_t word4 = BigInt::load32(47, std::make_shared<bytes_t>(data));
  CHECK("4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff16" == 
    Utils::uint256_2str(word4)
  );
}

TEST_CASE("load32 from slice [0..31]", "[big_int]") {

  // given
  bytes_t data = Hex::hexToBytes("608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8"); 

  uint256_t word1 = BigInt::load32(0, std::make_shared<bytes_t>(data));
  CHECK("608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d800" == 
    Utils::uint256_2str(word1)
  );
}

TEST_CASE("load32 from slice [31..32]", "[big_int]") {

  // given
  bytes_t data = Hex::hexToBytes("4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff16"); 

  uint256_t word1 = BigInt::load32(31, std::make_shared<bytes_t>(data));
  CHECK("1600000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(word1)
  );
}
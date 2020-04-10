#include <vector>
#include "catch.hpp"
#include <memory>
#include <evm/hash.h>
#include <evm/big_int.h>
#include <evm/utils.h>
#include <evm/hex.h>

TEST_CASE("keccak256", "[hash]" ) {
  bytes_t bytes = bytes_t();
  bytes_t hash = Hash::keccak256(bytes);
  REQUIRE("c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(hash))
  );
}

TEST_CASE("keccak256 1 byte", "[hash]" ) {
  bytes_t bytes = Hex::hexToBytes("00");
  bytes_t hash = Hash::keccak256(bytes);
  REQUIRE("bc36789e7a1e281436464229828f817d6612f7b477d66591ff96a9e064bcc98a" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(hash))
  );
}

TEST_CASE("keccak256 20 byte", "[hash]" ) {
  bytes_t bytes = Hex::hexToBytes("0000000000000000000000000000000000000000000000000000000000000000");
  bytes_t hash = Hash::keccak256(bytes);
  REQUIRE("290decd9548b62a8d60345a988386fc84ba6bc95484008f6362f93160ef3e563" == 
    Utils::uint256_2str(BigInt::fromBigEndianBytes(hash))
  );
}

TEST_CASE("keccak256 wlrd", "[hash]" ) {
  uint256_t word1 = BigInt::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681");
  uint256_t word2 = BigInt::fromHex("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6");
  uint256_t hash = Hash::keccak256Word(word1, word2);
  REQUIRE("d4aeab6b14081f43dd4fdf6ac0dc3b289fdd8dff4adf98254993e524e77993ae" == 
    Utils::uint256_2str(hash)
  );
}
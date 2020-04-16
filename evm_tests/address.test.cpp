#include "catch.hpp"
#include <memory>
#include <evm/address.hpp>
#include <evm/utils.hpp>
#include <evm/hex.hpp>
#include "test_utils.hpp"

TEST_CASE("accountIdentifierFromString", "[address]" ) {

  bytes_t accountIdentifier = Address::accountIdentifierFromString(
    "evm5", 
    "0x8d7332e9640fe8952e436dda2d5c2ac93d6870f3"
  );

  CHECK(20 == accountIdentifier.size());
  CHECK("86a2700da1f451fa70a0dd52225f986d552eda0f" == 
    TestUtils::bytesToHex(accountIdentifier)
  );
}

TEST_CASE("accountIdentifierFromBytes", "[address]" ) {

  bytes_t addressBytes = Hex::hexToBytes("8d7332e9640fe8952e436dda2d5c2ac93d6870f3");
  bytes_t accountIdentifier = Address::accountIdentifierFromBytes(
    "evm5", 
    addressBytes
  );

  CHECK(20 == accountIdentifier.size());
  CHECK("86a2700da1f451fa70a0dd52225f986d552eda0f" == 
    TestUtils::bytesToHex(accountIdentifier)
  );
}

TEST_CASE("Uncompressed public key", "[address]" ) {

  bytes_t ethereumPublicKey = Hex::hexToBytes("630f70ad9f6e943088a4677e9ccf132cb2ae8bafd4a1538b42cd78454e037730c6e09149f4bae8e136794e950a072368a0a3926083017d8b7b6c20d3f8a6f2e6");
  bytes_t address = Address::ethereumAddress(ethereumPublicKey);

  CHECK("7a5470ca3884388f8a284ac0c63eaf0695a200ea" == 
    TestUtils::bytesToHex(address)
  );
}

TEST_CASE("Ethereum address from sender and nonce", "[address]" ) {
  // given
  uint256_t senderAddress = BigInt::fromBigEndianBytes(Hex::hexToBytes("86a2700da1f451fa70a0dd52225f986d552eda0e"));
  uint256_t nonce = uint256_t(0x3412);

  // when
  address_t newAddress = Address::ethereumAddressFrom(senderAddress, nonce);

  // then
  CHECK("0000000000000000000000002c4cdf1918aea0508ed789d8c81828ab44dd475b" == 
    Hex::fixedToHex(newAddress)
  );
}

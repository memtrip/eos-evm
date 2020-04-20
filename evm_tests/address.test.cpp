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

TEST_CASE("Ethereum address from address, salt, and code hash", "[address]" ) {
  // given
  uint256_t address = BigInt::fromBigEndianBytes(Hex::hexToBytes("86a2700da1f451fa70a0dd52225f986d552eda0e"));
  uint256_t salt = uint256_t(0x3412);
  std::shared_ptr<bytes_t> codeBytes = std::make_shared<bytes_t>(
    Hex::hexToBytes("60806040526004361061001e5760003560e01c80635c60da1b14610126575b7f2230ca5690d71a74605e39bd522eea4bff3859bc627abd4ac5e473fcb8c5c3b05a6040518082815260200191505060405180910390a16000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff165a34600036604051808383808284378083019250505092505050600060405180830381858888f193505050503d80600081146100e5576040519150601f19603f3d011682016040523d82523d6000602084013e6100ea565b606091505b5050507f2230ca5690d71a74605e39bd522eea4bff3859bc627abd4ac5e473fcb8c5c3b05a6040518082815260200191505060405180910390a1005b34801561013257600080fd5b5061013b61017d565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a72315820a640f191ec583fbf9eec25b23042882a593697e120f7cea5230f7784081c042364736f6c63430005100032")
  );

  // when
  address_t newAddress = Address::ethereumAddressFrom(address, salt, codeBytes);

  // then
  CHECK("000000000000000000000000977f07e985ea2c0a034119c2f2e2eaa5d085f88d" == 
    Hex::fixedToHex(newAddress)
  );
}

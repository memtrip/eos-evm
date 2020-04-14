#include "catch.hpp"
#include <memory>
#include <evm/decompress_key.h>
#include <evm/hex.hpp>
#include "test_utils.hpp"

TEST_CASE("Decompress a compressed secp256k1 public key", "[decompress_key]" ) {

  // given
  bytes_t compressedKeyBytes = Hex::hexToBytes("025089107a9fca38bc287840fcf1977bd3fc2fd29ad0ea941ca4cbb29d4f58c0fd");

  std::array<char, 33> compressedKey;
  for (int i = 0; i < compressedKeyBytes.size(); i++) {
    compressedKey[i] = compressedKeyBytes[i];
  }

  // when
  bytes_t decompressedKey = DecompressKey::decompress(compressedKey);

  // then
  
  CHECK("5089107a9fca38bc287840fcf1977bd3fc2fd29ad0ea941ca4cbb29d4f58c0fdbb21be196cae80b767dc66e55068bdb10f94d9858367a16635f91aad21f66b20" == 
    TestUtils::bytesToHex(decompressedKey)
  );
}

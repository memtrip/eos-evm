#include "catch.hpp"
#include <evm/decompress_key.h>
#include <evm/hex.h>

TEST_CASE("Decompress a compressed secp256k1 public key", "[decompress_key]" ) {

  // given
  bytes_t compressedKeyBytes = Hex::hexToBytes("034005a4ab6b6eca2d03053038b8ea5f9b9e06c0d50092e0a15418524bb2c8b38e");

  std::array<char, 33> compressedKey;
  for (int i = 0; i < compressedKeyBytes.size(); i++) {
    compressedKey[i] = compressedKeyBytes[i];
  }

  // when
  bytes_t decompressedKey = DecompressKey::decompress(compressedKey);

  // then
  
  CHECK("4005a4ab6b6eca2d03053038b8ea5f9b9e06c0d50092e0a15418524bb2c8b38eae837535141729015cb88930199a40304fc5497fe56b5736441ca43eaa120829" == 
    Hex::bytesToHex(decompressedKey)
  );
}

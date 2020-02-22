#include <evm/types.h>
#include <evm/decompress_key.h>
#include <evm/hex.h>

uint256_t DecompressKey::p = BigInt::fromBigEndianBytes(
  Hex::hexToBytes("fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f")
);

bytes_t DecompressKey::decompress(compressed_key_t compressedKey) {
  bytes_t value;
  return value;
}
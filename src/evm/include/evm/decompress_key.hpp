#include <evm/types.h>
#include <evm/big_int.hpp>
#include <evm/hex.hpp>
#include <evm/utils.hpp>

class DecompressKey {
  public:
    static bytes_t decompress(compressed_key_t compressedKey) {
      uint256_t p = intx::be::load<uint256_t>({
        0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xfe, 
        0xff, 0xff, 0xfc, 0x2f
      });
      uint8_t yParity = static_cast<uint8_t>(compressedKey[0]) - 2;

      uint8_t data[WORD_SIZE];
      for (size_t i = 0; i < WORD_SIZE; i++)
        data[i] = compressedKey.at(i + 1);
      uint256_t x = intx::be::load<uint256_t>(data);

      uint256_t a = (pow_mod(x, 3, p) + 7) % p;
      uint256_t y = pow_mod(a, (p + 1) / 4, p);
      if (y % 2 != yParity)
        y = p - y;
      
      bytes_t uncompressedKey = BigInt::toBytes(x);
      bytes_t yBytes = BigInt::toBytes(y);

      uncompressedKey.insert(uncompressedKey.end(), yBytes.begin(), yBytes.end());

      return uncompressedKey;
    }
  private:
    static uint256_t pow_mod(uint256_t x, uint256_t y, const uint256_t& z) {
      uint256_t number = 1;
      while (y != 0) {
        if ((y & 1) != 0)
          number = intx::mulmod(number, x, z);
        y >>= 1;
        x = intx::mulmod(x, x, z);
      }
      return number;
    }
};
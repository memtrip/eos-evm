#include <evm/types.h>
#include <evm/big_int.h>

class DecompressKey {
  public:
    static bytes_t decompress(compressed_key_t compressedKey);
  private:
    static uint256_t p;
};
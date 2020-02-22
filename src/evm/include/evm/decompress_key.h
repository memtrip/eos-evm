#include <evm/types.h>

class DecompressKey {
  public:
    static bytes_t decompress(compressed_key_t compressedKey);
};
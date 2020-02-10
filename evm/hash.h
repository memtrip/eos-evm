#include "types.h"

class Hash {
  public:
    static uint256_t keccak256(char* data, unsigned int size);
    static uint256_t keccak512(char* data, unsigned int size);
};
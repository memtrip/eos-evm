#include <vector>
#include "types.h"

class Hash {
  public:
    static bytes_t keccak256(bytes_t& bytes);
    static bytes_t keccak512(bytes_t& bytes);
};
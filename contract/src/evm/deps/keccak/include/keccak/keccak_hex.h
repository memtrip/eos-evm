#include <string>
#include "hash_types.hpp"

class KeccakHex {
  public:
    static std::string toHex256(const ethash::hash256& h);
    static std::string toHex512(const ethash::hash512& h);
};
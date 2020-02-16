#include <evm/types.h>

class Overflow {
  public:
    static std::pair<unsigned int, bool> add(unsigned int value, unsigned int value2);
};
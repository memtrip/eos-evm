#include "types.h"

class Jumps {
  public:
    static jump_set_t find_destinations(char* byte_code, unsigned int size);
};
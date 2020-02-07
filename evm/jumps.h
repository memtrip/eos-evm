#include <set>

class Jumps {
  public:
    static std::set<unsigned int> find_destinations(char* byte_code, unsigned int size);
};
#include <vector>
#include "types.h"

class StackMachine {
  private:
    std::vector<uint256_t> stack;
  public:
    StackMachine();
    void pop(unsigned int n);
    void popOne();
    uint256_t peek(unsigned int n);
    void push(uint256_t item);
};
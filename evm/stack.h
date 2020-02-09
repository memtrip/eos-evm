#include <vector>
#include "types.h"

class StackMachine {
  public:
    StackMachine(std::vector<uint256_t>* stackArg);
    std::vector<uint256_t>* stack;
    void pop(unsigned int n);
    uint256_t peek(unsigned int n);
    void push(uint256_t item);
    void pushBool(bool value);
    void swapWithTop(unsigned int n);
    uint256_t top();
    void printSize();
    void putMap(std::map<uint256_t,uint256_t>* items);
    static uint256_t TRUE;
    static uint256_t FALSE;
};
#include <vector>
#include <evm/types.h>

class StackMachine {
  public:
    StackMachine(std::vector<uint256_t>* stackArg);
    std::vector<uint256_t>* stack;
    void pop(unsigned int n);
    uint256_t peek(unsigned int n);
    std::vector<uint256_t> peekMany(unsigned int offset, unsigned int n);
    void push(uint256_t item);
    void pushBool(bool value);
    void swapWithTop(unsigned int n);
    uint256_t top();
    void printSize();
    static uint256_t TRUE;
    static uint256_t FALSE;
    static uint256_t STUB;
};
#pragma once
#include <memory>
#include <vector>
#include <evm/types.h>

class StackMachine {
  public:
    StackMachine(std::shared_ptr<std::vector<uint256_t>> stackArg) { 
      stack = stackArg;
    };
    std::shared_ptr<std::vector<uint256_t>> stack;
    void pop(uint16_t n);
    uint256_t peek(uint16_t n);
    std::pair<uint256_t, uint256_t> topPair();
    std::vector<uint256_t> peekMany(uint16_t offset, uint16_t n);
    void push(uint256_t item);
    void pushBool(bool value);
    void swapWithTop(uint16_t n);
    uint256_t top();
    size_t size() const;
    static uint256_t TRUE;
    static uint256_t FALSE;
    static uint256_t STUB;
};
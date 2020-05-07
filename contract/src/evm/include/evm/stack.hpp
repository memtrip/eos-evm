#pragma once
#include <memory>
#include <vector>
#include <evm/types.h>

class StackMachine {
  public:
    std::vector<uint256_t> stack;

    StackMachine() { 
      stack = std::vector<uint256_t>();
      stack.reserve(1024);
    };

    void pop(uint16_t n) {
      stack.resize(stack.size() - n);
    }

    uint256_t peek(uint16_t n) {
      return stack.at(stack.size() - n - 1);
    }

    void push(const uint256_t& item) {
      stack.push_back(item);
    }

    void pushBool(bool value) {
      stack.push_back(value ? UINT256_ONE : UINT256_ZERO);
    }

    void swapWithTop(uint16_t n) {
      std::iter_swap(stack.end() - n - 1, stack.end() - 1);
    }

    uint256_t top() {
      return stack.at(stack.size() - 1);
    }

    size_t size() const {
      return stack.size();
    }
};
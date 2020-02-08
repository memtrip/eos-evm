#include <vector>
#include "stack.h"

StackMachine::StackMachine() {
  stack = std::vector<uint256_t>();
}

void StackMachine::pop(unsigned int n) {
  for (int i = 0; i < n; i++) {
    stack.pop_back();
  }
}

void StackMachine::popOne() {
  stack.pop_back();
}

uint256_t StackMachine::peek(unsigned int n) {
  return stack.at(stack.size() - n - 1);
}

void StackMachine::push(uint256_t item) {
  stack.push_back(item);
}
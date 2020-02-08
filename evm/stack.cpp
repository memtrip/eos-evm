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
  return stack[stack.size() - n - 1];
}

void StackMachine::push(uint256_t item) {
  stack.push_back(item);
}

void StackMachine::pushBool(bool value) {
  stack.push_back(value ? uint256_t(1) : uint256_t(0));
}

void StackMachine::swapWithTop(unsigned int n) {
  unsigned size = stack.size();
  std::swap(stack[size - n - 1], stack[size - 1]);
}
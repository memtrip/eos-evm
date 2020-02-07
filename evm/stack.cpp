#include "boost/multiprecision/cpp_int.hpp"
#include <vector>
#include "stack.h"

StackMachine::StackMachine() {
  stack = std::vector<boost::multiprecision::uint256_t>();
}

void StackMachine::pop(unsigned int n) {
  for (int i = 0; i < n; i++) {
    stack.pop_back();
  }
}

void StackMachine::popOne() {
  stack.pop_back();
}

boost::multiprecision::uint256_t StackMachine::peek(unsigned int n) {
  return stack.at(stack.size() - n - 1);
}

void StackMachine::push(boost::multiprecision::uint256_t item) {
  stack.push_back(item);
}
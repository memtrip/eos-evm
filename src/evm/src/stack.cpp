#include <vector>
#include <evm/stack.h>

StackMachine::StackMachine() {
  stack = std::vector<uint256_t>();
}

void StackMachine::pop(unsigned int n) {
  stack.resize(stack.size() - n);
}

uint256_t StackMachine::peek(unsigned int n) {
  return stack.at(stack.size() - n - 1);
}

std::vector<uint256_t> StackMachine::peekMany(unsigned int offset, unsigned int n) {
  std::vector<uint256_t> items;
  for (int i = offset; i < offset + n; i++) {
    items.push_back(peek(i));
  }
  return items;
}

void StackMachine::push(uint256_t item) {
  stack.push_back(item);
}

void StackMachine::pushBool(bool value) {
  stack.push_back(value ? StackMachine::TRUE : StackMachine::FALSE);
}

void StackMachine::swapWithTop(unsigned int n) {
  std::iter_swap(stack.end() - n - 1, stack.end() - 1);
}

uint256_t StackMachine::top() {
  return StackMachine::peek(0);
}

void StackMachine::printSize() {
  printf("size(%lu)", stack.size());
}

size_t StackMachine::size() {
  return stack.size();
}

uint256_t StackMachine::TRUE = uint256_t(1);

uint256_t StackMachine::FALSE = uint256_t(0);

uint256_t StackMachine::STUB = uint256_t(0xFFFFFFFFFFFFFFFF);
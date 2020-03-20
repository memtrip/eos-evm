#include <vector>
#include <evm/stack.h>

void StackMachine::pop(uint16_t n) {
  stack.resize(stack.size() - n);
}

uint256_t StackMachine::peek(uint16_t n) {
  return stack.at(stack.size() - n - 1);
}

std::pair<uint256_t, uint256_t> StackMachine::topPair() {
  uint256_t key = stack.at(stack.size() - 1);
  uint256_t value = stack.at(stack.size() - 2);
  return std::make_pair(key, value);
}

std::vector<uint256_t> StackMachine::peekMany(uint16_t offset, uint16_t n) {
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

void StackMachine::swapWithTop(uint16_t n) {
  std::iter_swap(stack.end() - n - 1, stack.end() - 1);
}

uint256_t StackMachine::top() {
  return StackMachine::peek(0);
}

size_t StackMachine::size() const {
  return stack.size();
}

uint256_t StackMachine::TRUE = uint256_t(1);

uint256_t StackMachine::FALSE = uint256_t(0);

uint256_t StackMachine::STUB = uint256_t(0xFFFFFFFFFFFFFFFF);
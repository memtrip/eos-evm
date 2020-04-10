#include <evm/stack.h>

void StackMachine::pop(uint16_t n) {
  stack->resize(stack->size() - n);
}

uint256_t& StackMachine::peek(uint16_t n) {
  return stack->at(stack->size() - n - 1);
}

void StackMachine::push(uint256_t item) {
  stack->push_back(item);
}

void StackMachine::pushBool(bool value) {
  stack->push_back(value ? UINT256_ONE : UINT256_ZERO);
}

void StackMachine::swapWithTop(uint16_t n) {
  std::iter_swap(stack->end() - n - 1, stack->end() - 1);
}

uint256_t& StackMachine::top() {
  return StackMachine::peek(0);
}

size_t StackMachine::size() const {
  return stack->size();
}

uint256_t StackMachine::STUB = uint256_t(0xFFFFFFFFFFFFFFFF);
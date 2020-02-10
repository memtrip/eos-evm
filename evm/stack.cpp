#include <vector>
#include "stack.h"
#include "utils.h"

StackMachine::StackMachine(std::vector<uint256_t>* stackArg) {
  stack = stackArg;
}

void StackMachine::pop(unsigned int n) {
  stack->resize(stack->size() - n);
}

uint256_t StackMachine::peek(unsigned int n) {
  return stack->at(stack->size() - n - 1);
}

void StackMachine::push(uint256_t item) {
  stack->push_back(item);
}

void StackMachine::pushBool(bool value) {
  stack->push_back(value ? StackMachine::TRUE : StackMachine::FALSE);
}

void StackMachine::swapWithTop(unsigned int n) {
  std::iter_swap(stack->end() - n - 1, stack->end() - 1);
}

uint256_t StackMachine::top() {
  return StackMachine::peek(0);
}

void StackMachine::putMap(std::map<uint256_t, uint256_t>* items) {
  std::vector<uint256_t> newVec = std::vector<uint256_t>(stack->end() - 2, stack->end() - 1);
  items->insert(std::make_pair(newVec[0], newVec[1]));
}

void StackMachine::printSize() {
  printf("size(%lu)", stack->size());
}

uint256_t StackMachine::TRUE = uint256_t(1);

uint256_t StackMachine::FALSE = uint256_t(0);
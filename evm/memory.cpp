#include <boost/numeric/conversion/cast.hpp>
#include "memory.h"
#include "overflow.h"

using boost::numeric_cast;

Memory::Memory(std::vector<char>* memoryArg) {
  memory = memoryArg;
}

unsigned int Memory::size() {
  return memory->size();
}

void Memory::resize(unsigned int newSize) {
  memory->resize(newSize);
}

void Memory::expand(unsigned int size) {
  if (size > memory->size()) {
    memory->resize(size);
  }
}

void Memory::writeByte(uint256_t offset, uint256_t value) {
  unsigned long off = numeric_cast<unsigned long>(offset);
  unsigned long val = numeric_cast<unsigned long>(val);
  // TODO: bit shift long to char
}

void Memory::write(uint256_t offset, uint256_t value) {
  unsigned long off = numeric_cast<unsigned long>(offset);
  // TODO: do
}

void Memory::read(uint256_t offset, uint256_t* value) {
  unsigned long off = numeric_cast<unsigned long>(offset);
  // TODO: from 
}

void Memory::writeSlice(uint256_t offset, Memory& memoryToWrite) {
  if (memoryToWrite.size() != 0) {
    unsigned long off = numeric_cast<unsigned long>(offset);
    // TODO: ?
  }
}

void Memory::readSlice(uint256_t initOffset, uint256_t initSize) {
  unsigned long off = numeric_cast<unsigned long>(initOffset);
  unsigned long size = numeric_cast<unsigned long>(initSize);
  // TODO: -_-
}

void Memory::writeableSlice(uint256_t initOffset, uint256_t initSize) {
  unsigned long off = numeric_cast<unsigned long>(initOffset);
  unsigned long size = numeric_cast<unsigned long>(initSize);
}

bool Memory::isValidRange(unsigned long offset, unsigned long size) {
  std::pair<unsigned int, bool> overflow = Overflow::add(offset, size);
  return size > 0 && !overflow.second;
}
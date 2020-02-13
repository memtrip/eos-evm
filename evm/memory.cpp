#include <boost/numeric/conversion/cast.hpp>
#include "memory.h"
#include "overflow.h"
#include "big_int.h"
#include "utils.h"

using boost::numeric_cast;

static constexpr size_t capacity = 4 * 1024;

Memory::Memory(std::vector<uint8_t>* memoryArg) {
  memory = memoryArg;
  memory->reserve(capacity);
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
  // TODO: check memory
  size_t index = numeric_cast<size_t>(offset);
  std::vector<uint8_t> bytes = BigInt::toBytes(value);
  memory->insert(memory->begin() + index, bytes.at(0));
}

void Memory::write(uint256_t offset, uint256_t value) {
  // TODO: check memory
  size_t index = numeric_cast<size_t>(offset);
  std::vector<uint8_t> bytes = BigInt::toBytes(value);
  memory->insert(memory->begin() + index + (WORD_SIZE - bytes.size()), std::begin(bytes), std::end(bytes));
}

uint256_t Memory::read(uint256_t offset) {
  // TODO: check memory
  size_t index = numeric_cast<size_t>(offset);
  return BigInt::fromBigEndianBytes(std::vector<uint8_t>(memory->begin() + index, memory->begin() + index + WORD_SIZE));
}

void Memory::writeSlice(uint256_t offset, Memory& memoryToWrite) {
  if (memoryToWrite.size() != 0) {
    unsigned long off = numeric_cast<unsigned long>(offset);
    // TODO: ?
  }
}

void Memory::readSlice(uint256_t initOffset, uint256_t initSize) {
  size_t off = numeric_cast<size_t>(initOffset);
  unsigned long size = numeric_cast<unsigned long>(initSize);
  // TODO: -_-
}

void Memory::writeableSlice(uint256_t initOffset, uint256_t initSize) {
  size_t off = numeric_cast<size_t>(initOffset);
  unsigned long size = numeric_cast<unsigned long>(initSize);
}

bool Memory::isValidRange(unsigned long offset, unsigned long size) {
  std::pair<unsigned int, bool> overflow = Overflow::add(offset, size);
  return size > 0 && !overflow.second;
}
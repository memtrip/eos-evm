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

void Memory::writeSlice(uint256_t offsetArg, std::vector<uint8_t> bytes) {
  if (bytes.size() != 0) {
    size_t offset = numeric_cast<size_t>(offsetArg);
    std::copy(bytes.begin(), bytes.end(), memory->begin() + offset);
  }
}

std::vector<uint8_t> Memory::readSlice(uint256_t offsetArg, uint256_t sizeArg) {
  size_t offset = numeric_cast<size_t>(offsetArg);
  size_t size = numeric_cast<size_t>(sizeArg);
  if (!isValidRange(offset, size)) {
    return std::vector<uint8_t>();
  } else {
    return std::vector<uint8_t>(memory->begin() + offset, memory->begin() + offset + size);
  }
}

void Memory::writeableSlice(uint256_t offsetArg, uint256_t sizeArg) {
  size_t offset = numeric_cast<size_t>(offsetArg);
  size_t size = numeric_cast<size_t>(sizeArg);
}

bool Memory::isValidRange(size_t offset, size_t size) {
  std::pair<unsigned int, bool> overflow = Overflow::add(offset, size);
  return size > 0 && !overflow.second;
}
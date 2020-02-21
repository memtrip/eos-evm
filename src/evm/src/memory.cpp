#include <evm/memory.h>
#include <evm/overflow.h>
#include <evm/big_int.h>

static constexpr size_t capacity = 4 * 1024;

Memory::Memory(bytes_t* memoryArg) {
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
  size_t index = static_cast<size_t>(offset);
  uint8_t byte = static_cast<uint8_t>(value);
  memory->insert(memory->begin() + index, byte);
}

void Memory::write(uint256_t offset, uint256_t value) {
  // TODO: check memory
  size_t index = static_cast<size_t>(offset);
  bytes_t bytes = BigInt::toBytes(value);
  memory->insert(memory->begin() + index + (WORD_SIZE - bytes.size()), std::begin(bytes), std::end(bytes));
}

uint256_t Memory::read(uint256_t offset) {
  // TODO: check memory
  size_t index = static_cast<size_t>(offset);
  return BigInt::fromBigEndianBytes(bytes_t(memory->begin() + index, memory->begin() + index + WORD_SIZE));
}

void Memory::writeSlice(uint256_t offsetArg, bytes_t bytes) {
  if (bytes.size() != 0) {
    size_t offset = static_cast<size_t>(offsetArg);
    std::copy(bytes.begin(), bytes.end(), memory->begin() + offset);
  }
}

bytes_t Memory::readSlice(uint256_t offsetArg, uint256_t sizeArg) {
  size_t offset = static_cast<size_t>(offsetArg);
  size_t size = static_cast<size_t>(sizeArg);
  if (!isValidRange(offset, size)) {
    return bytes_t();
  } else {
    return bytes_t(memory->begin() + offset, memory->begin() + offset + size);
  }
}

void Memory::writeableSlice(uint256_t offsetArg, uint256_t sizeArg) {
  size_t offset = static_cast<size_t>(offsetArg);
  size_t size = static_cast<size_t>(sizeArg);
}

bool Memory::isValidRange(size_t offset, size_t size) {
  std::pair<unsigned int, bool> overflow = Overflow::add(offset, size);
  return size > 0 && !overflow.second;
}
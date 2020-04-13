#include <algorithm>
#include <evm/memory.h>
#include <evm/overflow.h>
#include <evm/big_int.h>
#include <evm/hex.h>
#include <evm/utils.h>

uint64_t Memory::length() const {
  return memorySize;
}

void Memory::resize(uint64_t newSize) {
  uint64_t sizeChange = newSize - memorySize;
  memorySize = newSize;
  memory->resize(newSize);
  std::fill(memory->begin() + sizeChange, memory->end(), 0);
}

void Memory::expand(uint64_t size) {
  if (size > memorySize) {
    resize(size);
  }
}

void Memory::writeByte(uint64_t offset, const uint256_t& value) {
  bytes_t bytes = BigInt::toBytes(value);
  if (offset >= length()) return;
  uint8_t byte = bytes[bytes.size() - 1];
  memory->insert(memory->begin() + offset, byte);
}

void Memory::write(uint64_t offset, const uint256_t& word) {
  bytes_t bytes = BigInt::toBytes(word);
  uint64_t position = offset + (WORD_SIZE - bytes.size());
  if (position >= length()) return;
  memory->insert(memory->begin() + position, bytes.begin(), bytes.end());
}

uint256_t Memory::read(uint64_t offset) {
  if (offset >= length()) return UINT256_ZERO;
  bytes_t bytes = bytes_t(memory->begin() + offset, memory->begin() + offset + WORD_SIZE);
  return BigInt::fromBigEndianBytes(bytes);
}

void Memory::writeSlice(uint64_t offset, const bytes_t& bytes) {
  if (bytes.size() > 0) {
    std::copy(bytes.begin(), bytes.end(), memory->begin() + offset);
  }
}

void Memory::writeSlice(uint64_t offset, std::shared_ptr<bytes_t> bytes) {
  if (bytes->size() > 0) {
    std::copy(bytes->begin(), bytes->end(), memory->begin() + offset);
  }
}

std::shared_ptr<bytes_t> Memory::readSlice(uint64_t offset, uint64_t size) {
  if (!isValidRange(offset, size) 
    || offset > memorySize 
    || size > memorySize
  ) return std::make_shared<bytes_t>(bytes_t());
  return std::make_shared<bytes_t>(bytes_t(memory->begin() + offset, memory->begin() + offset + size));
}

bool Memory::isValidRange(uint64_t offset, uint64_t size) {
  overflow_t overflow = Overflow::add(offset, size);
  return size > 0 && !overflow.second;
}

void Memory::copyData(
  uint64_t destOffset, 
  uint64_t sourceOffset,
  uint64_t size,
  std::shared_ptr<bytes_t> data
) {

  uint64_t outputEnd;
  if (sourceOffset > data->size() || size > data->size() || sourceOffset + size > data->size()) {
    if (sourceOffset > data->size()) {
      std::fill(
        memory->begin() + destOffset,
        memory->begin() + destOffset + size, 
        0
      );
    } else {
      uint64_t writeableOffset = destOffset + data->size() - sourceOffset;
      uint64_t writeableSize = sourceOffset + size - data->size();
      std::fill(
        memory->begin() + writeableOffset, 
        memory->begin() + writeableOffset + writeableSize, 
        0
      );
    }
    outputEnd = data->size();
  } else {
    outputEnd = (size + sourceOffset); 
  }

  if (sourceOffset < data->size()) {
    bytes_t sliceBytes = bytes_t(data->begin() + sourceOffset, data->begin() + outputEnd);
    writeSlice(
      destOffset,
      sliceBytes
    );
  }
}
#include <algorithm>
#include <evm/memory.h>
#include <evm/overflow.h>
#include <evm/big_int.h>
#include <evm/hex.h>

static constexpr size_t capacity = 4 * 1024;

static const size_t MAX_RETURN_WASTE_BYTES = 16384;

Memory::Memory(bytes_t* memoryArg) {
  memory = memoryArg;
  memory->reserve(capacity);
  memorySize = 0;
}

size_t Memory::length() {
  return memorySize;
}

void Memory::resize(size_t newSize) {
  memorySize = newSize;
  memory->resize(newSize);
}

void Memory::expand(size_t size) {
  if (size > memorySize) {
    resize(size);
  }
}

void Memory::writeByte(uint256_t offset, uint256_t value) {
  size_t index = static_cast<size_t>(offset);
  bytes_t bytes = BigInt::toBytes(value);
  if (index >= length()) return;
  uint8_t byte = bytes[bytes.size() - 1];
  memory->insert(memory->begin() + index, byte);
}

void Memory::write(uint256_t offset, uint256_t value) {
  size_t index = static_cast<size_t>(offset);
  bytes_t bytes = BigInt::toBytes(value);
  size_t position = index + (WORD_SIZE - bytes.size());
  if (position >= length()) return;
  memory->insert(memory->begin() + position, std::begin(bytes), std::end(bytes));
}

uint256_t Memory::read(uint256_t offset) {
  size_t index = static_cast<size_t>(offset);
  if (index >= length()) return uint256_t(0);
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
  if (!isValidRange(offset, size) || offset > size) return bytes_t();
  return bytes_t(memory->begin() + offset, memory->begin() + offset + size);
}

void Memory::writeableSlice(uint256_t offsetArg, uint256_t sizeArg) {
  size_t offset = static_cast<size_t>(offsetArg);
  size_t size = static_cast<size_t>(sizeArg);
}

bool Memory::isValidRange(size_t offset, size_t size) {
  std::pair<unsigned int, bool> overflow = Overflow::add(offset, size);
  return size > 0 && !overflow.second;
}

ReturnData Memory::intoReturnData(uint256_t offsetArg, uint256_t sizeArg) {
  size_t offset = static_cast<size_t>(offsetArg);
  size_t size = static_cast<size_t>(sizeArg);

  if (!isValidRange(offset, size)) { 
    ReturnData returnData {
      bytes_t(),
      uint256_t(0),
      uint256_t(0)
    };
    return returnData;
  }

  if (offset == 0) resize(size);

  bytes_t data = bytes_t(memory->begin() + offset, memory->begin() + offset + size);
  ReturnData returnData {
    data,
    uint256_t(0),
    uint256_t(size)
  };
  return returnData;
}

void Memory::copyData(
  uint256_t destOffset, 
  uint256_t sourceOffset,
  uint256_t size,
  bytes_t data
) {

  uint256_t sourceSize = uint256_t(data.size());

  size_t outputEnd;
  if (sourceOffset > sourceSize || size > sourceSize || sourceOffset + size > sourceSize) {
    if (sourceOffset > sourceSize) {
      std::fill(
        memory->begin() + static_cast<size_t>(destOffset), 
        memory->begin() + static_cast<size_t>(size), 
        0
      );
    } else {
      std::fill(
        memory->begin() + static_cast<size_t>(destOffset + sourceSize - sourceOffset), 
        memory->begin() + static_cast<size_t>(sourceOffset + size - sourceSize), 
        0
      );
    }
    outputEnd = data.size();
  } else {
    outputEnd = static_cast<size_t>(size + sourceOffset); 
  }

  if (sourceOffset < sourceSize) {
    size_t outputBegin = static_cast<size_t>(sourceOffset);
    writeSlice(
      static_cast<size_t>(destOffset),
      bytes_t(data.begin() + outputBegin, data.begin() + outputEnd)
    );
  }
}
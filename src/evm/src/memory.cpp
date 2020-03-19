#include <algorithm>
#include <evm/memory.h>
#include <evm/overflow.h>
#include <evm/big_int.h>
#include <evm/hex.h>

static constexpr uint64_t capacity = 4 * 1024;

static const uint64_t MAX_RETURN_WASTE_BYTES = 16384;

Memory::Memory() {
  memory = bytes_t();
  memory.reserve(capacity);
  memorySize = 0;
}

uint64_t Memory::length() {
  return memorySize;
}

void Memory::resize(uint64_t newSize) {
  uint64_t sizeChange = newSize - memorySize;
  memorySize = newSize;
  memory.resize(newSize);
  std::fill(memory.begin() + sizeChange, memory.end(), 0);
}

void Memory::expand(uint64_t size) {
  if (size > memorySize) {
    resize(size);
  }
}

void Memory::writeByte(uint256_t offset, uint256_t value) {
  overflow_t index = Overflow::uint256Cast(offset);
  bytes_t bytes = BigInt::toBytes(value);
  if (index.second || index.first >= length()) return;
  uint8_t byte = bytes[bytes.size() - 1];
  memory.insert(memory.begin() + index.first, byte);
}

void Memory::write(uint256_t offset, uint256_t value) {
  overflow_t index = Overflow::uint256Cast(offset);
  bytes_t bytes = BigInt::toBytes(value);
  if (index.second) return;
  uint64_t position = index.first + (WORD_SIZE - bytes.size());
  if (position >= length()) return;
  memory.insert(memory.begin() + position, std::begin(bytes), std::end(bytes));
}

uint256_t Memory::read(uint256_t offset) {
  overflow_t index = Overflow::uint256Cast(offset);
  if (index.second || index.first >= length()) return uint256_t(0);
  bytes_t wordBytes = bytes_t(memory.begin() + index.first, memory.begin() + index.first + WORD_SIZE);
  return BigInt::fromBigEndianBytes(wordBytes);
}

void Memory::writeSlice(uint256_t offsetArg, bytes_t& bytes) {
  overflow_t offset = Overflow::uint256Cast(offsetArg);
  if (offset.second || bytes.size() != 0) {
    std::copy(bytes.begin(), bytes.end(), memory.begin() + offset.first);
  }
}

bytes_t Memory::readSlice(uint256_t offsetArg, uint256_t sizeArg) {
  overflow_t offset = Overflow::uint256Cast(offsetArg);
  overflow_t size = Overflow::uint256Cast(sizeArg);
  if (offset.second 
    || size.second 
    || !isValidRange(offset.first, size.first) 
    || offset.first > memorySize 
    || size.first > memorySize
  ) return bytes_t();
  return bytes_t(memory.begin() + offset.first, memory.begin() + offset.first + size.first);
}

bool Memory::isValidRange(uint64_t offset, uint64_t size) {
  overflow_t overflow = Overflow::add(offset, size);
  return size > 0 && !overflow.second;
}

ReturnData Memory::intoReturnData(uint256_t offsetArg, uint256_t sizeArg) {
  overflow_t offset = Overflow::uint256Cast(offsetArg);
  overflow_t size = Overflow::uint256Cast(sizeArg);

  if (offset.second || size.second || !isValidRange(offset.first, size.first)) { 
    ReturnData returnData {
      bytes_t(),
      uint256_t(0),
      uint256_t(0)
    };
    return returnData;
  }

  if (offset.first == 0) resize(size.first);

  bytes_t data = bytes_t(memory.begin() + offset.first, memory.begin() + offset.first + size.first);
  ReturnData returnData {
    data,
    uint256_t(0),
    uint256_t(size.first)
  };
  return returnData;
}

void Memory::copyData(
  uint256_t destOffset, 
  uint256_t sourceOffset,
  uint256_t size,
  bytes_t& data
) {

  uint256_t sourceSize = uint256_t(data.size());

  uint64_t outputEnd;
  if (sourceOffset > sourceSize || size > sourceSize || sourceOffset + size > sourceSize) {
    if (sourceOffset > sourceSize) {
      std::fill(
        memory.begin() + Overflow::uint256Cast(destOffset).first,
        memory.begin() + Overflow::uint256Cast(size).first, 
        0
      );
    } else {
      std::fill(
        memory.begin() + Overflow::uint256Cast(destOffset + sourceSize - sourceOffset).first, 
        memory.begin() + Overflow::uint256Cast(sourceOffset + size - sourceSize).first, 
        0
      );
    }
    outputEnd = data.size();
  } else {
    outputEnd = Overflow::uint256Cast(size + sourceOffset).first; 
  }

  if (sourceOffset < sourceSize) {
    uint64_t outputBegin = Overflow::uint256Cast(sourceOffset).first;
    bytes_t sliceBytes = bytes_t(data.begin() + outputBegin, data.begin() + outputEnd);
    writeSlice(
      Overflow::uint256Cast(destOffset).first,
      sliceBytes
    );
  }
}
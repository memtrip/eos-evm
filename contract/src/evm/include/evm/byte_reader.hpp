#pragma once
#include <vector>
#include <memory>
#include <evm/types.h>
#include <evm/big_int.hpp>

class ByteReader {
  private:
    uint64_t position;
  public:
    ByteReader(uint64_t positionArg) {
      position = positionArg;
    };

    uint256_t read(uint64_t size, std::shared_ptr<bytes_t> bytes) {
      uint64_t startPos = position;
      position += size; // move the ByteReader position forward
      return BigInt::load(startPos, size, bytes);
    }

    void next() {
      position += 1;
    }

    void move(uint64_t to) {
      position = to;
    }

    bool atEnd(std::shared_ptr<bytes_t> bytes) {
      return position >= bytes->size();
    }

    uint64_t pc() {
      return position - 1;
    }

    uint8_t currentOp(std::shared_ptr<bytes_t> bytes) {
      return bytes->at(position);
    }
};
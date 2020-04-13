#pragma once
#include <vector>
#include <memory>
#include <evm/types.h>

class ByteReader {
  public:
    ByteReader(uint64_t positionArg) {
      position = positionArg;
    };
    uint256_t read(uint64_t size, std::shared_ptr<bytes_t> bytes);
    void next();
    void move(uint64_t to);
    bool atEnd(std::shared_ptr<bytes_t> bytes);
    uint64_t pc();
    uint8_t currentOp(std::shared_ptr<bytes_t> bytes);
  private:
    uint64_t position;
};
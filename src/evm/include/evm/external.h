#pragma once
#include "types.h"

class External {
   public:
    virtual ~External() = default;
    virtual void log(std::vector<uint256_t> topics, bytes_t data) { };
    virtual bytes_t code(uint256_t address) { return bytes_t(); };
};
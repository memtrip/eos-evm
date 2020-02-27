#pragma once
#include "types.h"

class External {
   public:
    virtual ~External() = default;
    virtual void log(std::vector<uint256_t> topics, bytes_t data) { };
};
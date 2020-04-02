#pragma once
#include <memory>
#include "types.h"

class External {
   public:
    virtual ~External() = default;
    virtual void log(std::vector<uint256_t>& topics, bytes_t& data) { };
    virtual std::shared_ptr<bytes_t> code(uint256_t address) { return std::make_shared<bytes_t>(bytes_t()); };
    virtual double balance(uint256_t address) { return 0.0; };
    virtual bytes_t storageAt(uint256_t address) { return bytes_t(); };
    virtual void suicide(uint256_t address) { };
};
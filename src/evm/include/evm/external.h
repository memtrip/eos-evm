#pragma once
#include <memory>
#include "types.h"

class External {
   public:
    virtual ~External() = default;
    virtual void log(const std::vector<uint256_t>& topics, std::shared_ptr<bytes_t> data) { };
    virtual std::shared_ptr<bytes_t> code(const uint256_t& address) { return std::make_shared<bytes_t>(bytes_t()); };
    virtual double balance(const uint256_t& address) { return 0.0; };
    virtual bytes_t storageAt(const uint256_t& key, const uint256_t& codeAddress) { return bytes_t(); };
    virtual void suicide(const uint256_t& address) { };
    virtual emplace_t emplaceCode(const uint256_t& address, std::shared_ptr<bytes_t> code) { return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0); };
};
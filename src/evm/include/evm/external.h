#pragma once
#include <memory>
#include "types.h"

class External {
public:
  virtual ~External() = default;
  virtual uint64_t senderNonce() { return 0; }
  virtual uint64_t incrementNonce() { return 0; }
  virtual uint256_t senderAccountBalance() { return uint256_t(0); }
  virtual void log(const std::vector<uint256_t>& topics, const bytes_t& data) { };
  virtual std::shared_ptr<bytes_t> code(const uint256_t& address) { return std::make_shared<bytes_t>(); };
  virtual uint256_t balance(const uint256_t& addressWord) { return 0.0; };
  virtual uint256_t storageAt(const uint256_t& key, const uint256_t& codeAddress) { return uint256_t(0); };
  virtual emplace_t selfdestruct(const uint256_t& address) { 
    return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
  };
  virtual emplace_t transfer(const uint256_t& senderAddress, const uint256_t& toAddressWord, const uint256_t& value) {
    return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0); 
  };
  virtual emplace_t emplaceCode(
    const uint256_t& originWord,
    const uint256_t& codeAddressWord, 
    const uint256_t& endowment, 
    std::shared_ptr<bytes_t> code
  ) { 
    return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0); 
  };
};
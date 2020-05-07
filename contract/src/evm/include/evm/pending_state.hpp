#pragma once
#include <iterator>
#include <memory>
#include <evm/types.h>
#include <evm/external.h>

struct Log {
  uint64_t stackDepth;
  std::vector<uint256_t> topics;
  bytes_t data;
}; 
typedef Log log_t;

struct AccountState {
  uint64_t stackDepth;
  uint64_t nonce;
  uint256_t key;
  uint256_t value;
  uint256_t codeAddress;
};
typedef AccountState account_state_t;

struct {
  bool operator()(account_state_t a, account_state_t b) const {   
    return a.nonce < b.nonce;
  }   
} nonceOrder;

class PendingState {
  private:
    uint64_t stateNonce;
  public:
    uint64_t currentStackDepth;
    std::vector<log_t> logs;
    std::vector<account_state_t> accountState;
    // TODO: add the ability to track at which stackDepth emplaceCode changes occurred 
  
    void revert(uint64_t stackDepth) {
      logs.erase(std::remove_if(
        logs.begin(), logs.end(), [stackDepth](const log_t& log) { 
          return log.stackDepth >= stackDepth;
        }
      ), logs.end());
      accountState.erase(std::remove_if(
        accountState.begin(), accountState.end(), [stackDepth](const account_state_t& stateItem) { 
          return stateItem.stackDepth >= stackDepth;
        }
      ), accountState.end());
    }

    void log(const std::vector<uint256_t>& topics, bytes_t data) {
      logs.push_back({currentStackDepth, topics, data});
    }

    void putState(const uint256_t& key, const uint256_t& value, const uint256_t& codeAddress) {
      stateNonce += 1;
      accountState.push_back({currentStackDepth, stateNonce, key, value, codeAddress});
    }

    uint256_t getState(const uint256_t& key, const uint256_t& codeAddress, std::shared_ptr<External> external) {
      std::vector<account_state_t> results;
      std::copy_if(
        accountState.begin(), accountState.end(), std::back_inserter(results), [key, codeAddress](const account_state_t& stateItem) { 
          return stateItem.key == key && stateItem.codeAddress == codeAddress;
        }
      );

      if (results.size() > 0) {
        if (results.size() > 1) {
          std::sort(results.begin(), results.end(), nonceOrder);
        }
        return std::prev(results.end())->value;
      } else {
        return external->storageAt(key, codeAddress);
      }
    }
};


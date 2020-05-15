#pragma once
#include <iterator>
#include <numeric>
#include <evm/types.h>
#include <evm/overflow.hpp>
#include <evm/hex.hpp>
#include <evm/big_int.hpp>

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

enum BalanceChangeType {
  BALANCE_CHANGE_ADD,
  BALANCE_CHANGE_SUBTRACT
};

enum BalanceAddressType {
  BALANCE_ADDRESS_ACCOUNT,
  BALANCE_ADDRESS_CONTRACT
};

struct BalanceChange {
  uint64_t stackDepth;
  BalanceChangeType type;
  BalanceAddressType addressType;
  uint256_t address;
  uint256_t value;

  bool operator<(const BalanceChange& a) const {   
    return address < a.address;
  };

  bool operator==(const BalanceChange& a) const {   
    return address == a.address;
  };
};
typedef BalanceChange balance_change_t;

struct ResolvedBalance {
  BalanceAddressType addressType;
  uint256_t address;
};
typedef ResolvedBalance resolved_balance_t;
inline bool operator<(const resolved_balance_t& lhs, const resolved_balance_t& rhs) {
  return lhs.address < rhs.address;
}

struct AddressChange {
  uint64_t stackDepth;
  uint256_t address;
};
typedef AddressChange self_destruct_t;
typedef AddressChange contract_creation_t;

struct {
  bool operator()(account_state_t a, account_state_t b) const {   
    return a.nonce < b.nonce;
  }   
} nonceOrder;

struct {
  bool operator()(balance_change_t a, balance_change_t b) const {   
    return a.address < b.address;
  }   
} addressOrder;

class PendingState {
  private:
    uint64_t stateNonce;
    std::vector<contract_creation_t> contractCreated;
  public:
    uint64_t currentStackDepth;
    std::vector<log_t> logs;
    std::vector<account_state_t> accountState;
    std::vector<balance_change_t> balanceChange;
    std::vector<self_destruct_t> selfDestruct;
    std::vector<contract_creation_t> revertedContractCreation;
  
    void revert(uint64_t stackDepth) {
      logs.erase(std::remove_if(
        logs.begin(), logs.end(), [stackDepth](const log_t& item) { 
          return item.stackDepth >= stackDepth;
        }
      ), logs.end());
      accountState.erase(std::remove_if(
        accountState.begin(), accountState.end(), [stackDepth](const account_state_t& item) { 
          return item.stackDepth >= stackDepth;
        }
      ), accountState.end());
      balanceChange.erase(std::remove_if(
        balanceChange.begin(), balanceChange.end(), [stackDepth](const balance_change_t& item) { 
          return item.stackDepth >= stackDepth;
        }
      ), balanceChange.end());
      selfDestruct.erase(std::remove_if(
        selfDestruct.begin(), selfDestruct.end(), [stackDepth](const self_destruct_t& item) { 
          return item.stackDepth >= stackDepth;
        }
      ), selfDestruct.end());
      std::vector<contract_creation_t> revertedContracts;
      std::copy_if(
        contractCreated.begin(), contractCreated.end(), std::back_inserter(revertedContracts), [stackDepth](const contract_creation_t& item) { 
          return item.stackDepth >= stackDepth;
        }
      );
      if (revertedContracts.size() > 0) {
        revertedContractCreation.insert(
          revertedContractCreation.end(), 
          revertedContracts.begin(), 
          revertedContracts.end()
        );
      }
    }

    void log(const std::vector<uint256_t>& topics, bytes_t data) {
      logs.push_back({currentStackDepth, topics, data});
    }

    void putState(const uint256_t& key, const uint256_t& value, const uint256_t& codeAddress) {
      stateNonce += 1;
      accountState.push_back({currentStackDepth, stateNonce, key, value, codeAddress});
    }

    uint256_t getState(const uint256_t& key, const uint256_t& codeAddress) {
      return getState(key, codeAddress, [] (){
        return uint256_t(0);
      });
    }

    template <typename F>
    uint256_t getState(const uint256_t& key, const uint256_t& codeAddress, F&& external) {
      std::vector<account_state_t> results;
      std::copy_if(
        accountState.begin(), accountState.end(), std::back_inserter(results), [key, codeAddress](const account_state_t& item) { 
          return item.key == key && item.codeAddress == codeAddress;
        }
      );
 
      if (results.size() > 0) {
        if (results.size() > 1) {
          std::sort(results.begin(), results.end(), nonceOrder);
        }
        return std::prev(results.end())->value;
      } else {
        return external();
      }
    }

    void putBalanceChange(
      const BalanceChangeType type, 
      const BalanceAddressType addressType, 
      const uint256_t& address, 
      const uint256_t& value
    ) {
      balanceChange.push_back({currentStackDepth, type, addressType, address, value});
    }

    uint256_t balanceWithPendingChanges(const uint256_t& address, const uint256_t& persistedBalance) {
      return resolveAddressBalanceChanges(address, persistedBalance).second;
    }

    std::pair<BalanceAddressType, uint256_t> resolveAddressBalanceChanges(const uint256_t& address, const uint256_t& persistedBalance) {
      std::vector<balance_change_t> results;
      std::copy_if(
        balanceChange.begin(), balanceChange.end(), std::back_inserter(results), [address](const balance_change_t& item) { 
          return item.address == address;
        }
      );
      if (results.size() == 0) return std::make_pair(BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, persistedBalance);

      BalanceAddressType addressType = results[0].addressType;
      uint256_t pendingAdditions = uint256_t(0);
      uint256_t pendingSubtractions = uint256_t(0);
      for (int i = 0; i < results.size(); i++) {
        if (results[i].type == BalanceChangeType::BALANCE_CHANGE_ADD)
          pendingAdditions += results[i].value;
        if (results[i].type == BalanceChangeType::BALANCE_CHANGE_SUBTRACT)
          pendingSubtractions += results[i].value;
      }

      return std::make_pair(
        addressType,
        Overflow::sub(persistedBalance + pendingAdditions, pendingSubtractions).first
      );
    }

    std::set<resolved_balance_t> resolvedBalanceAddresses() {
      if (balanceChange.size() == 0) return std::set<resolved_balance_t>();
      std::set<resolved_balance_t> changedAddress;
      for (int i = 0; i < balanceChange.size(); i++) {
        changedAddress.insert({balanceChange[i].addressType, balanceChange[i].address});
      }
      return changedAddress;
    }

    void putSelfDestruct(const uint256_t& address) {
      selfDestruct.push_back({currentStackDepth, address});
    }

    void putContractCreate(const uint256_t& address) {
      contractCreated.push_back({currentStackDepth, address});
    }

    bool contractExists(const uint256_t& address) {
      // TODO: check that the contract hasn't been self destructed
      // TODO: check that a previously created contract has not been reverted
      return true;
    }
};


#include <vector>
#include <memory>
#include <eosio/eosio.hpp>
#include <eos_evm.hpp>
#include <evm/types.h>
#include <evm/external.h>
#include <evm/hash.hpp>
#include <evm/hex.hpp>
#include <evm/overflow.hpp>
#include <evm/pending_state.hpp>

class eos_external: public External {
  private:
    eos_evm* _contract;
    uint256_t _senderAddress;
    name _sender;
    uint256_t _senderAccountBalance;
    
    emplace_t outgoingTransfer(
      const uint256_t& toAddressWord, 
      const uint256_t& value,
      std::shared_ptr<PendingState> pendingState
    ) {
      if (pendingState->balanceWithPendingChanges(_senderAddress, _senderAccountBalance) < value) 
        return std::make_pair(EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS, 0);

      pendingState->putBalanceChange(
        BalanceChangeType::BALANCE_CHANGE_SUBTRACT,
        BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, 
        _senderAddress,
        value
      );

      address_t toAddress = BigInt::toFixed32(toAddressWord);

      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto accountCodeItr = accountCodeIdx.find(toAddress);
      if (accountCodeItr != accountCodeIdx.end()) {
        pendingState->putBalanceChange(
          BalanceChangeType::BALANCE_CHANGE_ADD,
          BalanceAddressType::BALANCE_ADDRESS_CONTRACT,
          toAddressWord,
          value
        );
        return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
      }

      eos_evm::account_table _account(_contract->get_self(), _contract->get_self().value);
      auto accountIdx = _account.get_index<name("accountid")>();
      auto accountItr = accountIdx.find(toAddress);
      if (accountItr != accountIdx.end()) {
        pendingState->putBalanceChange(
          BalanceChangeType::BALANCE_CHANGE_ADD,
          BalanceAddressType::BALANCE_ADDRESS_ACCOUNT,
          toAddressWord,
          value
        );
        return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
      }

      return std::make_pair(EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND, 0);
    }

    emplace_t contractTransfer(
      const uint256_t& senderAddressWord, 
      const uint256_t& toAddressWord, 
      const uint256_t& value,
      std::shared_ptr<PendingState> pendingState
    ) {
      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto senderAccountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto senderAccountCodeItr = senderAccountCodeIdx.find(BigInt::toFixed32(senderAddressWord));
      if (senderAccountCodeItr == senderAccountCodeIdx.end()) return std::make_pair(EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND, 0);

      uint256_t senderBalance = pendingState->balanceWithPendingChanges(
        senderAddressWord,
        BigInt::fromFixed32(senderAccountCodeItr->balance.extract_as_byte_array())
      );

      if (senderBalance < value) return std::make_pair(EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS, 0);

      pendingState->putBalanceChange(
        BalanceChangeType::BALANCE_CHANGE_SUBTRACT,
        BalanceAddressType::BALANCE_ADDRESS_CONTRACT,
        senderAddressWord,
        value
      );

      auto toAccountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto toAccountCodeItr = toAccountCodeIdx.find(BigInt::toFixed32(toAddressWord));
      if (toAccountCodeItr != toAccountCodeIdx.end()) {
        pendingState->putBalanceChange(
          BalanceChangeType::BALANCE_CHANGE_ADD,
          BalanceAddressType::BALANCE_ADDRESS_CONTRACT,
          toAddressWord,
          value
        );
        return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
      }

      eos_evm::account_table _account(_contract->get_self(), _contract->get_self().value);
      auto toAccountIdx = _account.get_index<name("accountid")>();
      auto toAccountItr = toAccountIdx.find(BigInt::toFixed32(toAddressWord));
      if (toAccountItr != toAccountIdx.end()) {
        pendingState->putBalanceChange(
          BalanceChangeType::BALANCE_CHANGE_ADD,
          BalanceAddressType::BALANCE_ADDRESS_ACCOUNT,
          toAddressWord,
          value
        );
        return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
      }

      return std::make_pair(EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND, 0);
    }

    emplace_t incomingTransfer(
      const uint256_t& senderAddress, 
      const uint256_t& value,
      std::shared_ptr<PendingState> pendingState
    ) {
      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto senderAccountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto senderAccountCodeItr = senderAccountCodeIdx.find(BigInt::toFixed32(senderAddress));
      if (senderAccountCodeItr == senderAccountCodeIdx.end()) return std::make_pair(EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND, 0);

      uint256_t senderBalance = pendingState->balanceWithPendingChanges(
        senderAddress,
        BigInt::fromFixed32(senderAccountCodeItr->balance.extract_as_byte_array())
      );

      if (senderBalance < value) return std::make_pair(EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS, 0);

      pendingState->putBalanceChange(
        BalanceChangeType::BALANCE_CHANGE_SUBTRACT,
        BalanceAddressType::BALANCE_ADDRESS_CONTRACT, 
        senderAddress,
        value
      );

      pendingState->putBalanceChange(
        BalanceChangeType::BALANCE_CHANGE_ADD,
        BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, 
        _senderAddress,
        value
      );

      return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
    }

    emplace_t debitContract(
      const uint256_t& ownerAddressWord,
      const uint256_t& endowment,
      std::shared_ptr<PendingState> pendingState
    ) {
      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto accountCodeItr = accountCodeIdx.find(BigInt::toFixed32(ownerAddressWord));
      if (accountCodeItr == accountCodeIdx.end()) return std::make_pair(EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND, 0);
      
      uint256_t ownerBalance = pendingState->balanceWithPendingChanges(
        ownerAddressWord, 
        BigInt::fromFixed32(accountCodeItr->balance.extract_as_byte_array())
      );

      if (ownerBalance < endowment) return std::make_pair(EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS, 0);
      
      pendingState->putBalanceChange(
        BalanceChangeType::BALANCE_CHANGE_SUBTRACT,
        BalanceAddressType::BALANCE_ADDRESS_CONTRACT, 
        ownerAddressWord,
        endowment
      );

      return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
    }

  public:
    eos_external(
      eos_evm* contract, 
      const uint256_t& senderAddress,
      const name& sender, 
      const uint256_t& senderAccountBalance
    ) {
      _contract = contract;
      _senderAddress = senderAddress;
      _sender = sender;
      _senderAccountBalance = senderAccountBalance;
    }

    uint256_t senderAccountBalance(std::shared_ptr<PendingState> pendingState) {
      return pendingState->balanceWithPendingChanges(_senderAddress, _senderAccountBalance);
    }

    void log(const std::vector<uint256_t>& topics, const bytes_t& data) {
      std::string output = "LOG(topics=[";
      for (int i = 0; i < topics.size(); i++) {
        bytes_t bytes = BigInt::toBytes(topics[i]);
        output += Hex::bytesToHex(bytes) + ",";
      }
      if (topics.size() > 0) output.pop_back();
      output += "], data=" + Hex::bytesToHex(data) + ")";
      eosio::print(output);
    }

    bytes_t code(const uint256_t& address, std::shared_ptr<PendingState> pendingState) {
      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto accountCodeItr = accountCodeIdx.find(BigInt::toFixed32(address));
      if (accountCodeItr != accountCodeIdx.end() && pendingState->contractExists(address)) return accountCodeItr->code;
      return bytes_t();
    }

    uint256_t balance(const uint256_t& addressWord, std::shared_ptr<PendingState> pendingState) {

      if (addressWord == _senderAddress) 
        return pendingState->balanceWithPendingChanges(_senderAddress, _senderAccountBalance);

      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto accountCodeItr = accountCodeIdx.find(BigInt::toFixed32(addressWord));
      if (accountCodeItr != accountCodeIdx.end()) {
        return pendingState->balanceWithPendingChanges(
          addressWord,
          BigInt::fromFixed32(accountCodeItr->balance.extract_as_byte_array())
        );
      }

      address_t address = BigInt::toFixed32(addressWord);
      eos_evm::account_table _account(_contract->get_self(), _contract->get_self().value);
      auto accountIdx = _account.get_index<name("accountid")>();
      auto accountItr = accountIdx.find(address);
      if (accountItr != accountIdx.end()) {
        printf("account");
        return pendingState->balanceWithPendingChanges(
          addressWord,
          BigInt::fromFixed32(accountItr->balance.extract_as_byte_array())
        );
      }

      return uint256_t(0);
    }

    uint256_t storageAt(const uint256_t& key, const uint256_t& codeAddress) {
      address_t address = BigInt::toFixed32(codeAddress);
      uint256_t compositeKey = Hash::keccak256WordPair(codeAddress, key);
      eos_evm::account_state_table _account_state(_contract->get_self(), _contract->get_self().value);
      auto idx = _account_state.get_index<name("statekey")>();
      auto itr = idx.find(BigInt::toFixed32(compositeKey));
      if (itr == idx.end()) return uint256_t(0); 
      return BigInt::fromFixed32(itr->value.extract_as_byte_array());
    }

    emplace_t selfdestruct(
      const uint256_t& contractAddressWord, 
      const uint256_t& refundAddressWord,
      std::shared_ptr<PendingState> pendingState
    ) {

      pendingState->putSelfDestruct(contractAddressWord);

      address_t contractAddress = BigInt::toFixed32(contractAddressWord);

      // TODO: this will be moved to eos_evm contract
      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto accountCodeItr = accountCodeIdx.find(contractAddress);
      if (accountCodeItr == accountCodeIdx.end()) return std::make_pair(EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND, 0);
      uint256_t refundBalance = BigInt::fromFixed32(accountCodeItr->balance.extract_as_byte_array());
      accountCodeIdx.erase(accountCodeItr);

      eos_evm::account_state_table _account_state(_contract->get_self(), _contract->get_self().value);
      auto accountStateIdx = _account_state.get_index<name("stateid")>();
      auto accountStateItr = accountStateIdx.find(contractAddress);
      while(accountStateItr != accountStateIdx.end()) {
        accountStateItr = accountStateIdx.erase(accountStateItr);
      }
      // TODO: this will be moved to resolvePendingChanges contract

      if (_senderAddress == refundAddressWord) {
        pendingState->putBalanceChange(
          BalanceChangeType::BALANCE_CHANGE_ADD,
          BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, 
          _senderAddress,
          refundBalance
        );

        return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
      } else {
        eos_evm::account_table _account(_contract->get_self(), _contract->get_self().value);
        auto accountIdx = _account.get_index<name("accountid")>();
        auto accountItr = accountIdx.find(BigInt::toFixed32(refundAddressWord));
        if (accountItr != accountIdx.end()) {
          // pendingState->putBalanceChange(
          //   BalanceChangeType::BALANCE_CHANGE_ADD,
          //   refundAddressWord,
          //   refundBalance
          // );
          // TODO: this will be moved to resolvePendingChanges
          accountIdx.modify(accountItr, _sender, [&](auto& account) {
            uint256_t newBalance = BigInt::fromFixed32(account.balance.extract_as_byte_array()) + refundBalance;
            account.balance = BigInt::toFixed32(newBalance);
          });
          // TODO: this will be moved to resolvePendingChanges
          return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
        }

        eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
        auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
        auto accountCodeItr = accountCodeIdx.find(BigInt::toFixed32(refundAddressWord));
        if (accountCodeItr != accountCodeIdx.end()) {
          // pendingState->putBalanceChange(
          //   BalanceChangeType::BALANCE_CHANGE_ADD,
          //   refundAddressWord,
          //   refundBalance
          // );
          // TODO: this will be moved to resolvePendingChanges
          accountCodeIdx.modify(accountCodeItr, _sender, [&](auto& account_code) {
            uint256_t newBalance = BigInt::fromFixed32(account_code.balance.extract_as_byte_array()) + refundBalance;
            account_code.balance = BigInt::toFixed32(newBalance);
          }); 
          // TODO: this will be moved to resolvePendingChanges
          return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
        }
      }

      return std::make_pair(EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND, 0);
    }

    emplace_t transfer(
      const uint256_t& senderAddressWord, 
      const uint256_t& toAddressWord, 
      const uint256_t& value,
      std::shared_ptr<PendingState> pendingState
    ) {
      if (_senderAddress == senderAddressWord) return outgoingTransfer(toAddressWord, value, pendingState);
      if (_senderAddress == toAddressWord) return incomingTransfer(senderAddressWord, value, pendingState);
      return contractTransfer(senderAddressWord, toAddressWord, value, pendingState);
    };

    uint256_t incrementContractNonce(const uint256_t& address) { 
      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto accountCodeItr = accountCodeIdx.find(BigInt::toFixed32(address));
      if (accountCodeItr == accountCodeIdx.end()) return uint256_t(0);
      uint64_t nextNonce = accountCodeItr->nonce + 1;
      accountCodeIdx.modify(accountCodeItr, _sender, [&](auto& account_code) {
        account_code.nonce = nextNonce;
      }); 
      return uint256_t(nextNonce);
    };

    emplace_t emplaceCodeAddress(
      const uint256_t& ownerAddressWord,
      const uint256_t& codeAddressWord, 
      const uint256_t& endowment,
      std::shared_ptr<PendingState> pendingState
    ) {

      if (pendingState->balanceWithPendingChanges(_senderAddress, _senderAccountBalance) < endowment) 
        return std::make_pair(EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS, 0);

      pendingState->putBalanceChange(
        BalanceChangeType::BALANCE_CHANGE_SUBTRACT,
        BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, 
        _senderAddress,
        endowment
      );

      pendingState->putBalanceChange(
        BalanceChangeType::BALANCE_CHANGE_ADD,
        BalanceAddressType::BALANCE_ADDRESS_CONTRACT, 
        codeAddressWord,
        endowment
      );

      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      _account_code.emplace(_sender, [&](auto& account_code) {
        account_code.pk = _account_code.available_primary_key();
        account_code.owner = BigInt::toFixed32(ownerAddressWord);
        account_code.address = BigInt::toFixed32(codeAddressWord);
        account_code.nonce = 1;
        account_code.balance =  BigInt::toFixed32(0);
      });

      return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
    }

    emplace_t emplaceParentCode(
      const uint256_t& codeAddressWord, 
      const uint256_t& endowment, 
      const bytes_t& code
    ) {
      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto accountCodeItr = accountCodeIdx.find(BigInt::toFixed32(codeAddressWord));
      if (accountCodeItr == accountCodeIdx.end()) return std::make_pair(EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND, 0);
      accountCodeIdx.modify(accountCodeItr, _sender, [&](auto& account_code) {
        account_code.code = code;
      }); 
      return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
    }

    emplace_t emplaceCode(
      const uint256_t& ownerAddressWord,
      const uint256_t& codeAddressWord, 
      const uint256_t& endowment, 
      const bytes_t& code,
      std::shared_ptr<PendingState> pendingState
    ) {

      emplace_t emplaceDebit = debitContract(ownerAddressWord, endowment, pendingState);
      if (emplaceDebit.first != EmplaceResult::EMPLACE_SUCCESS) return emplaceDebit;

      pendingState->putBalanceChange(
        BalanceChangeType::BALANCE_CHANGE_ADD,
        BalanceAddressType::BALANCE_ADDRESS_CONTRACT, 
        codeAddressWord,
        endowment
      );

      pendingState->putContractCreate(codeAddressWord);

      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      _account_code.emplace(_sender, [&](auto& account_code) {
        account_code.pk = _account_code.available_primary_key();
        account_code.owner = BigInt::toFixed32(ownerAddressWord);
        account_code.address = BigInt::toFixed32(codeAddressWord);
        account_code.nonce = 1;
        account_code.code = code;
        account_code.balance = BigInt::toFixed32(0);
      });

      return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
    }
};
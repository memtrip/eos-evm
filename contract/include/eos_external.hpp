#include <vector>
#include <memory>
#include <eosio/eosio.hpp>
#include <eos_evm.hpp>
#include <evm/types.h>
#include <evm/external.h>
#include <evm/hash.hpp>
#include <evm/utils.hpp>
#include <evm/hex.hpp>
#include <evm/overflow.hpp>

class eos_external: public External {
  private:
    eos_evm* _contract;
    uint256_t _senderAddress;
    name _sender;
    uint256_t _senderAccountBalance;
    uint64_t parentNonce;
    
    emplace_t outgoingTransfer(
      const uint256_t& senderAddress, 
      const uint256_t& toAddressWord, 
      const uint256_t& value
    ) {
      printf("[outgoingTransfer]");

      if (_senderAccountBalance < value) return std::make_pair(EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS, 0);
      _senderAccountBalance -= value;

      Utils::print256(toAddressWord, "toAddress");

      address_t toAddress = BigInt::toFixed32(toAddressWord);

      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto accountCodeItr = accountCodeIdx.find(toAddress);
      if (accountCodeItr != accountCodeIdx.end()) {
        accountCodeIdx.modify(accountCodeItr, _sender, [&](auto& account_code) {
          uint256_t newBalance = BigInt::fromFixed32(account_code.balance.extract_as_byte_array()) + value;
          account_code.balance = BigInt::toFixed32(newBalance);
        }); 
        return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
      }

      eos_evm::account_table _account(_contract->get_self(), _contract->get_self().value);
      auto accountIdx = _account.get_index<name("accountid")>();
      auto accountItr = accountIdx.find(toAddress);
      if (accountItr != accountIdx.end()) {
        accountIdx.modify(accountItr, _sender, [&](auto& account) {
          uint256_t newBalance = BigInt::fromFixed32(account.balance.extract_as_byte_array()) + value;
          account.balance = BigInt::toFixed32(newBalance);
        });
        return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
      }

      return std::make_pair(EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND, 0);
    }

    emplace_t contractTransfer(
      const uint256_t& senderAddressWord, 
      const uint256_t& toAddressWord, 
      const uint256_t& value
    ) {
      printf("[contractTransfer]");

      address_t senderAddress = BigInt::toFixed32(senderAddressWord);
      address_t toAddress = BigInt::toFixed32(toAddressWord);

      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto senderAccountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto senderAccountCodeItr = senderAccountCodeIdx.find(BigInt::toFixed32(toAddressWord));
      if (senderAccountCodeItr != senderAccountCodeIdx.end()) {
        uint256_t senderBalance = BigInt::fromFixed32(senderAccountCodeItr->balance.extract_as_byte_array());
        if (senderBalance < value) return std::make_pair(EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS, 0);
        senderAccountCodeIdx.modify(senderAccountCodeItr, _sender, [&](auto& account_code) {
          uint256_t newBalance = senderBalance - value;
          account_code.balance = BigInt::toFixed32(newBalance);
        }); 
      }

      auto toAccountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto toAccountCodeItr = toAccountCodeIdx.find(BigInt::toFixed32(toAddressWord));
      if (toAccountCodeItr != toAccountCodeIdx.end()) {
        toAccountCodeIdx.modify(toAccountCodeItr, _sender, [&](auto& account_code) {
          uint256_t newBalance = BigInt::fromFixed32(account_code.balance.extract_as_byte_array()) + value;
          account_code.balance = BigInt::toFixed32(newBalance);
        }); 
      }

      return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
    }

    emplace_t incomingTransfer(
      const uint256_t& senderAddress, 
      const uint256_t& toAddressWord, 
      const uint256_t& value
    ) {
      printf("[incomingTransfer]");
      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto senderAccountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto senderAccountCodeItr = senderAccountCodeIdx.find(BigInt::toFixed32(toAddressWord));
      if (senderAccountCodeItr != senderAccountCodeIdx.end()) {
        uint256_t senderBalance = BigInt::fromFixed32(senderAccountCodeItr->balance.extract_as_byte_array());
        if (senderBalance < value) return std::make_pair(EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS, 0);
        senderAccountCodeIdx.modify(senderAccountCodeItr, _sender, [&](auto& account_code) {
          uint256_t newBalance = senderBalance - value;
          account_code.balance = BigInt::toFixed32(newBalance);
        }); 
      }

      _senderAccountBalance += value;

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
      parentNonce = 1;
    }

    uint256_t senderAccountBalance() {
      return _senderAccountBalance;
    }

    void log(const std::vector<uint256_t>& topics, const bytes_t& data) {
      std::string output = "LOG(topics=[";
      for (int i = 0; i < topics.size(); i++) {
        output += Utils::uint256_2str(topics[i]) + ",";
      }
      if (topics.size() > 0) output.pop_back();
      output += "], data=" + Hex::bytesToHex(data) + ")";
      eosio::print(output);
    }

    bytes_t code(const uint256_t& address) {
      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto accountCodeItr = accountCodeIdx.find(BigInt::toFixed32(address));
      if (accountCodeItr == accountCodeIdx.end()) return bytes_t();
      return accountCodeItr->code;
    }

    uint256_t balance(const uint256_t& addressWord) {

      if (addressWord == _senderAddress) return _senderAccountBalance;

      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto accountCodeItr = accountCodeIdx.find(BigInt::toFixed32(addressWord));
      if (accountCodeItr != accountCodeIdx.end()) return BigInt::fromFixed32(accountCodeItr->balance.extract_as_byte_array());

      address_t address = BigInt::toFixed32(addressWord);
      eos_evm::account_table _account(_contract->get_self(), _contract->get_self().value);
      auto accountIdx = _account.get_index<name("accountid")>();
      auto accountItr = accountIdx.find(address);
      if (accountItr != accountIdx.end()) return BigInt::fromFixed32(accountItr->balance.extract_as_byte_array());

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

    emplace_t selfdestruct(const uint256_t& addressWord) {
      address_t address = BigInt::toFixed32(addressWord);
      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto accountCodeItr = accountCodeIdx.find(address);
      if (accountCodeItr == accountCodeIdx.end()) return std::make_pair(EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND, 0);

      _senderAccountBalance += BigInt::fromFixed32(accountCodeItr->balance.extract_as_byte_array());

      accountCodeIdx.erase(accountCodeItr);

      return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
    }

    emplace_t transfer(const uint256_t& senderAddressWord, const uint256_t& toAddressWord, const uint256_t& value) {
      if (_senderAddress == senderAddressWord) return outgoingTransfer(senderAddressWord, toAddressWord, value);
      if (_senderAddress == toAddressWord) return incomingTransfer(senderAddressWord, toAddressWord, value);
      return contractTransfer(senderAddressWord, toAddressWord, value);
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
      const uint256_t& endowment
    ) {
      if (_senderAccountBalance < endowment) return std::make_pair(EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS, 0);
      _senderAccountBalance -= endowment;

      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      _account_code.emplace(_sender, [&](auto& account_code) {
        account_code.pk = _account_code.available_primary_key();
        account_code.owner = BigInt::toFixed32(ownerAddressWord);
        account_code.address = BigInt::toFixed32(codeAddressWord);
        account_code.nonce = 1;
        account_code.balance = BigInt::toFixed32(endowment);
      });

      return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
    }

    emplace_t emplaceCode(
      const uint256_t& ownerAddressWord,
      const uint256_t& codeAddressWord, 
      const uint256_t& endowment, 
      const bytes_t& code
    ) {

      checksum256 ownerAddress;

      if (ownerAddressWord == _senderAddress) {
        eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
        auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
        auto accountCodeItr = accountCodeIdx.find(BigInt::toFixed32(codeAddressWord));
        printf("[emplace_code_parent]");
        if (accountCodeItr == accountCodeIdx.end()) return std::make_pair(EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND, 0);
        accountCodeIdx.modify(accountCodeItr, _sender, [&](auto& account_code) {
          account_code.code = code;
        }); 
        return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
      } else {
        // a smart contract is creating a contract
        eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
        auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
        auto accountCodeItr = accountCodeIdx.find(BigInt::toFixed32(ownerAddressWord));
        printf("[emplace_code_child]");
        if (accountCodeItr == accountCodeIdx.end()) return std::make_pair(EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND, 0);
        if (BigInt::fromFixed32(accountCodeItr->balance.extract_as_byte_array()) < endowment) return std::make_pair(EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS, 0);
        ownerAddress = accountCodeItr->address;
        accountCodeIdx.modify(accountCodeItr, _sender, [&](auto& account) {
          uint256_t newBalance = BigInt::fromFixed32(account.balance.extract_as_byte_array()) - endowment;
          account.balance = BigInt::toFixed32(newBalance);
        }); 
      }

      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      _account_code.emplace(_sender, [&](auto& account_code) {
        account_code.pk = _account_code.available_primary_key();
        account_code.owner = ownerAddress;
        account_code.address = BigInt::toFixed32(codeAddressWord);
        account_code.nonce = (codeAddressWord == _senderAddress) ? parentNonce : 1;
        account_code.code = code;
        account_code.balance = BigInt::toFixed32(endowment);
      });

      return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
    }
};
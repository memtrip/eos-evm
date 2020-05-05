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
    uint64_t _senderNonce;
    uint256_t _senderAccountBalance;

    TransferType determineTransferType(const uint256_t& senderAddress, const uint256_t& toAddressWord) {
      if (_senderAddress == senderAddress) return TransferType::TRANSFER_PARENT_OUTGOING;
      if (_senderAddress == toAddressWord) return TransferType::TRANSFER_PARENT_INCOMING;
      return TransferType::TRANSFER_ADHOC;
    }

    emplace_t transferAdhoc(const uint256_t& senderAddressWord, const uint256_t& toAddressWord, const uint256_t& value) {

      eos_evm::account_table _account(_contract->get_self(), _contract->get_self().value);

      address_t senderAddress = BigInt::toFixed32(senderAddressWord);
      address_t toAddress = BigInt::toFixed32(toAddressWord);

      auto senderAccountIdx = _account.get_index<name("accountid")>();
      auto senderAccountItr = senderAccountIdx.find(senderAddress);
      if (senderAccountItr == senderAccountIdx.end()) return std::make_pair(EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND, 0);
      senderAccountIdx.modify(senderAccountItr, _sender, [&](auto& account) {
        uint256_t newBalance = BigInt::fromFixed32(account.balance.extract_as_byte_array()) + value;
        account.balance = BigInt::toFixed32(newBalance);
      });

      auto toAccountIdx = _account.get_index<name("accountid")>();
      auto toAccountItr = toAccountIdx.find(toAddress);
      if (toAccountItr == toAccountIdx.end()) return std::make_pair(EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND, 0);
      toAccountIdx.modify(toAccountItr, _sender, [&](auto& account) {
        uint256_t newBalance = BigInt::fromFixed32(account.balance.extract_as_byte_array()) + value;
        account.balance = BigInt::toFixed32(newBalance);
      });

      return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
    }

    uint256_t subbalance(const uint256_t& contractAddress) {
      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto accountCodeItr = accountCodeIdx.find(BigInt::toFixed32(contractAddress));
      if (accountCodeItr == accountCodeIdx.end()) return uint256_t(0);
      return BigInt::fromFixed32(accountCodeItr->balance.extract_as_byte_array());
    }

  public:
    eos_external(
      eos_evm* contract, 
      const uint256_t& senderAddress,
      const name& sender, 
      uint64_t senderNonce, 
      const uint256_t& senderAccountBalance
    ) {
      _contract = contract;
      _senderAddress = senderAddress;
      _sender = sender;
      _senderNonce = senderNonce;
      _senderAccountBalance = senderAccountBalance;
    }

    uint64_t senderNonce() {
      return _senderNonce;
    }

    uint64_t incrementNonce() { 
      _senderNonce += 1;
      return _senderNonce; 
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
      if (addressWord == _senderAddress) {
        return _senderAccountBalance;
      } else {
        address_t address = BigInt::toFixed32(addressWord);
        eos_evm::account_table _account(_contract->get_self(), _contract->get_self().value);
        auto accountIdx = _account.get_index<name("accountid")>();
        auto accountItr = accountIdx.find(address);
        if (accountItr == accountIdx.end()) return subbalance(addressWord);
        return BigInt::fromFixed32(accountItr->balance.extract_as_byte_array());
      }
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

    emplace_t transfer(const uint256_t& senderAddress, const uint256_t& toAddressWord, const uint256_t& value) {

      TransferType transferType = determineTransferType(senderAddress, toAddressWord);
      if (transferType == TransferType::TRANSFER_ADHOC) return transferAdhoc(senderAddress, toAddressWord, value);

      address_t targetAddress = (transferType == TransferType::TRANSFER_PARENT_OUTGOING) 
        ? BigInt::toFixed32(toAddressWord)
        : BigInt::toFixed32(senderAddress);

      if (_senderAccountBalance < value) return std::make_pair(EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS, 0);

      eos_evm::account_table _account(_contract->get_self(), _contract->get_self().value);
      auto accountIdx = _account.get_index<name("accountid")>();
      auto accountItr = accountIdx.find(targetAddress);
      if (accountItr == accountIdx.end()) return std::make_pair(EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND, 0);
   
      accountIdx.modify(accountItr, _sender, [&](auto& account) {
        uint256_t newBalance = (transferType == TransferType::TRANSFER_PARENT_OUTGOING) 
          ? (BigInt::fromFixed32(account.balance.extract_as_byte_array()) + value) 
          : (BigInt::fromFixed32(account.balance.extract_as_byte_array()) - value);
        account.balance = BigInt::toFixed32(newBalance);
      });

      _senderAccountBalance = (transferType == TransferType::TRANSFER_PARENT_OUTGOING) 
        ? (_senderAccountBalance - value) 
        : (_senderAccountBalance + value);

      return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
    };

    emplace_t emplaceCode(
      const uint256_t& addressWord,
      const uint256_t& codeAddressWord, 
      const uint256_t& endowment, 
      const bytes_t& code
    ) {
      checksum256 originAddress;

      if (addressWord == _senderAddress) {
        if (_senderAccountBalance < endowment) return std::make_pair(EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS, 0);
        originAddress = BigInt::toFixed32(_senderAddress);
        _senderAccountBalance -= endowment;
      } else {
        // a smart contract is creating this contract
        eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
        auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
        auto accountCodeItr = accountCodeIdx.find(BigInt::toFixed32(addressWord));
        if (accountCodeItr == accountCodeIdx.end()) return std::make_pair(EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND, 0);
        if (BigInt::fromFixed32(accountCodeItr->balance.extract_as_byte_array()) < endowment) return std::make_pair(EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS, 0);
        originAddress = accountCodeItr->accountIdentifier;
        accountCodeIdx.modify(accountCodeItr, _sender, [&](auto& account) {
          uint256_t newBalance = BigInt::fromFixed32(account.balance.extract_as_byte_array()) - endowment;
          account.balance = BigInt::toFixed32(newBalance);
        }); 
      }

      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      _account_code.emplace(_sender, [&](auto& account_code) {
        account_code.pk = _account_code.available_primary_key();
        account_code.accountIdentifier = originAddress;
        account_code.address = BigInt::toFixed32(codeAddressWord);
        account_code.nonce = 1;
        account_code.code = code;
        account_code.balance = BigInt::toFixed32(endowment);
      });

      return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
    }
};
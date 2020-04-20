#include <vector>
#include <memory>
#include <eosio/eosio.hpp>
#include <evm/types.h>
#include <evm/external.h>
#include <evm/hash.hpp>
#include <evm/utils.hpp>
#include <evm/hex.hpp>
#include <eos_evm.hpp>
#include <eos_utils.hpp>

class eos_external: public External {
  private:
    eos_evm* _contract;
    name _sender;
    uint64_t _senderNonce;
    uint64_t _senderAccountBalance;

  public:
    eos_external(eos_evm* contract, const name& sender, uint64_t senderNonce, uint64_t senderAccountBalance) {
      _contract = contract;
      _sender = sender;
      _senderNonce = senderNonce;
      _senderAccountBalance = senderAccountBalance;
    }

    uint64_t senderAccountBalance() {
      return _senderAccountBalance;
    }

    void log(const std::vector<uint256_t>& topics, std::shared_ptr<bytes_t> data) {
      std::string output = "LOG(topics=[";
      for (int i = 0; i < topics.size(); i++) {
        output += Utils::uint256_2str(topics[i]) + ",";
      }
      if (topics.size() > 0) output.pop_back();
      output += "], data=" + Hex::bytesToHex(data) + ")";
      eosio::print(output);
    }

    std::shared_ptr<bytes_t> code(const uint256_t& address) {
      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto accountCodeItr = accountCodeIdx.find(BigInt::toFixed32(address));
      if (accountCodeItr == accountCodeIdx.end()) return std::make_shared<bytes_t>(bytes_t());
      return std::make_shared<bytes_t>(Hex::hexToBytes(accountCodeItr->code));
    }

    double balance(const uint256_t& addressWord) {
      address_t address = BigInt::toFixed32(addressWord);

      // get the account associated with the address
      eos_evm::account_table _account(_contract->get_self(), _contract->get_self().value);
      auto accountIdx = _account.get_index<name("accountid")>();
      auto accountItr = accountIdx.find(address);
      if (accountItr == accountIdx.end()) return 0; // TODO: handle this with an address not found

      return accountItr->balance.amount;
    }

    uint256_t storageAt(const uint256_t& key, const uint256_t& codeAddress) {

      address_t address = BigInt::toFixed32(codeAddress);

      // get the account associated with the address
      eos_evm::account_table _account(_contract->get_self(), _contract->get_self().value);
      auto accountIdx = _account.get_index<name("accountid")>();
      auto accountItr = accountIdx.find(address);
      if (accountItr == accountIdx.end()) return uint256_t(0);

      uint256_t compositeKey = Hash::keccak256WordPair(codeAddress, key);
      eos_evm::account_state_table _account_state(_contract->get_self(), accountItr->user.value);
      auto idx = _account_state.get_index<name("statekey")>();
      auto itr = idx.find(BigInt::toFixed32(compositeKey));
      if (itr == idx.end()) return uint256_t(0); 

      return eos_utils::checksum256ToWord(itr->value);
    }

    emplace_t selfdestruct(const uint256_t& addressWord) {
      address_t address = BigInt::toFixed32(addressWord);
      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto accountCodeItr = accountCodeIdx.find(address);
      if (accountCodeItr == accountCodeIdx.end()) return std::make_pair(EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND, 0);

      _senderAccountBalance += accountCodeItr->balance.amount;

      accountCodeIdx.erase(accountCodeItr);

      return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
    }

   /*
    * Create a new code entry under the scope of the account associated with the address.
    */
    emplace_t emplaceCode(
      const uint256_t& senderAddressWord, 
      uint64_t endowment, 
      std::shared_ptr<bytes_t> code,
      const AddressScheme addressScheme
    ) {
      address_t senderAddress = BigInt::toFixed32(senderAddressWord);

      if (_senderAccountBalance < endowment) return std::make_pair(EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS, endowment);

      // TODO: support the CREATE2 address scheme
      address_t codeAddress;
      switch (addressScheme) {
        case AddressScheme::LEGACY:
          codeAddress = Address::ethereumAddressFrom(senderAddressWord, uint256_t(_senderNonce));
          break;
        case AddressScheme::EIP_1014:
          codeAddress = Address::ethereumAddressFrom(senderAddressWord, uint256_t(eosio::tapos_block_num()), code);
          break;
      }

      // create a new code record
      eos_evm::account_code_table _account_code(_contract->get_self(), _contract->get_self().value);
      _account_code.emplace(_sender, [&](auto& account_code) {
        account_code.pk = _account_code.available_primary_key();
        account_code.accountIdentifier = senderAddress;
        account_code.address = codeAddress;
        account_code.nonce = 1;
        account_code.code = Hex::bytesToHex(code);
        account_code.balance = eosio::asset(endowment, eos_evm::CONTRACT_SYMBOL);
      });

      _senderAccountBalance -= endowment;

      return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, codeAddress);
    }
};
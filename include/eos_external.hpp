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
    eos_evm* contract;

  public:
    eos_external(eos_evm* contractArg) {
      contract = contractArg;
    }

    void log(const std::vector<uint256_t>& topics, std::shared_ptr<bytes_t> data) {
      std::string output;
      for (int i = 0; i < topics.size(); i++) {
        output += "[" + Utils::uint256_2str(topics[i]) + "]\n";
      }
      output += "{" + Hex::bytesToHex(data) + "}";
      eosio::print(output);
    }

    std::shared_ptr<bytes_t> code(const uint256_t& address) {
      eos_evm::account_table _account(contract->get_self(), contract->get_self().value);
      auto accountIdx = _account.get_index<name("accountid")>();
      auto accountItr = accountIdx.find(BigInt::toFixed32(address));
      if (accountItr == accountIdx.end()) return std::make_shared<bytes_t>(bytes_t());

      eos_evm::account_code_table _account_code(contract->get_self(), accountItr->user.value);
      auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto accountCodeItr = accountCodeIdx.find(BigInt::toFixed32(address));
      if (accountCodeItr == accountCodeIdx.end()) return std::make_shared<bytes_t>(bytes_t());

      return std::make_shared<bytes_t>(Hex::hexToBytes(accountCodeItr->code));
    }

    double balance(const uint256_t& address) {
      return 0.0;
    }

    bytes_t storageAt(const uint256_t& address, const uint256_t& codeAddress) {
      // uint256_t compositeKey = Hash::keccak256Word(codeAddress, key);
      // eos_evm::account_state_table _account_state(contract->get_self(), contract->get_self().value);
      // auto idx = _account_state.get_index<name("statekey")>();
      // auto itr = idx.find(BigInt::toFixed32(compositeKey));
      // if (itr != idx.end()) return eos_utils::fixedToBytes(itr->value);
      return bytes_t();
    }

    void suicide(const uint256_t& address) {
      
    }

    emplace_t emplaceCode(const uint256_t& address, std::shared_ptr<bytes_t> code) {
      eos_evm::account_table _account(contract->get_self(), contract->get_self().value);
      auto accountIdx = _account.get_index<name("accountid")>();
      auto accountItr = accountIdx.find(BigInt::toFixed32(address));
      if (accountItr == accountIdx.end()) return EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND;

      eos_evm::account_code_table _account_code(contract->get_self(), accountItr->user.value);
      auto accountCodeIdx = _account_code.get_index<name("codeaddress")>();
      auto accountCodeItr = accountCodeIdx.find(BigInt::toFixed32(address));
      if (accountCodeItr != accountCodeIdx.end()) return EmplaceResult::EMPLACE_CODE_EXISTS;

      _account_code.emplace(accountItr->user, [&](auto& account_code) {
        account_code.pk = _account_code.available_primary_key();
        account_code.accountIdentifier = BigInt::toFixed32(address);
        account_code.code = Hex::bytesToHex(code);
      });
      return EmplaceResult::EMPLACE_SUCCESS;
    }
};
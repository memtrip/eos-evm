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
  public:
    eos_external(eos_evm* contractArg);
    void log(const std::vector<uint256_t>& topics, std::shared_ptr<bytes_t> data);
    std::shared_ptr<bytes_t> code(const uint256_t& address);
    double balance(const uint256_t& address);
    bytes_t storageAt(const uint256_t& address, const uint256_t& codeAddress);
    void suicide(const uint256_t& address);
    bytes_t keccak256(const bytes_t& bytes);
    void emplaceCode(const uint256_t& address, std::shared_ptr<bytes_t> code);
  private:
    eos_evm* contract;
};

eos_external::eos_external(eos_evm* contractArg) {
  contract = contractArg;
}

void eos_external::log(const std::vector<uint256_t>& topics, std::shared_ptr<bytes_t> data) {
  std::string output;
  for (int i = 0; i < topics.size(); i++) {
    output += "[" + Utils::uint256_2str(topics[i]) + "]\n";
  }
  output += "{" + Hex::bytesToHex(data) + "}";
  eosio::print(output);
}

std::shared_ptr<bytes_t> eos_external::code(const uint256_t& address) {
  return std::make_shared<bytes_t>(bytes_t());
}

double eos_external::balance(const uint256_t& address) {
  return 0.0;
}

bytes_t eos_external::storageAt(const uint256_t& key, const uint256_t& codeAddress) {
  uint256_t compositeKey = Hash::keccak256Word(codeAddress, key);
  eos_evm::account_state_table _account_state(contract->get_self(), contract->get_self().value);
  auto idx = _account_state.get_index<name("statekey")>();
  auto itr = idx.find(BigInt::toFixed32(compositeKey));
  if (itr != idx.end()) return eos_utils::fixedToBytes(itr->value);
  return bytes_t();
}

void eos_external::suicide(const uint256_t& address) {
}

void eos_external::emplaceCode(const uint256_t& address, std::shared_ptr<bytes_t> code) { 
};
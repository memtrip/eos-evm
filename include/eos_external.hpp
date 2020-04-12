#include <vector>
#include <memory>
#include <evm/types.h>
#include <evm/external.h>
#include <eos_evm.hpp>
#include <evm/hash.h>
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
  private:
    eos_evm* contract;
};

eos_external::eos_external(eos_evm* contractArg) {
  contract = contractArg;
}

void eos_external::log(const std::vector<uint256_t>& topics, std::shared_ptr<bytes_t> data) {
}

std::shared_ptr<bytes_t> eos_external::code(const uint256_t& address) {
  return std::make_shared<bytes_t>(bytes_t());
}

double eos_external::balance(const uint256_t& address) {
  return 0.0;
}

bytes_t eos_external::storageAt(const uint256_t& key, const uint256_t& codeAddress) {
  // uint256_t compositeKey = Hash::keccak256Word(
  //   accountState->cacheItems->at(i).codeAddress,
  //   accountState->cacheItems->at(i).key
  // );
  // account_state_table _account_state(contract->get_self(), contract->get_self().value);
  // auto idx = _account_state.get_index<name("statekey")>();
  // auto itr = idx.find(BigInt::toFixed32(compositeKey));
  // if (itr != idx.end()) return eos_utils::fixedToBytes(itr->value);
  return bytes_t();
}

void eos_external::suicide(const uint256_t& address) {
}

bytes_t eos_external::keccak256(const bytes_t& bytes) {
  return Hash::keccak256(bytes);
}
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
    void log(std::vector<uint256_t> topics, std::shared_ptr<bytes_t> data);
    std::shared_ptr<bytes_t> code(uint256_t address);
    double balance(uint256_t address);
    bytes_t storageAt(uint256_t address, uint256_t codeAddress);
    void suicide(uint256_t address);
    bytes_t keccak256(bytes_t& bytes);
  private:
    eos_evm* contract;
};

eos_external::eos_external(eos_evm* contractArg) {
  contract = contractArg;
}

void eos_external::log(std::vector<uint256_t> topics, std::shared_ptr<bytes_t> data) {
}

std::shared_ptr<bytes_t> eos_external::code(uint256_t address) {
  return std::make_shared<bytes_t>(bytes_t());
}

double eos_external::balance(uint256_t address) {
  return 0.0;
}

bytes_t eos_external::storageAt(uint256_t key, uint256_t codeAddress) {
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

void eos_external::suicide(uint256_t address) {
}

bytes_t eos_external::keccak256(bytes_t& bytes) {
  return Hash::keccak256(bytes);
}
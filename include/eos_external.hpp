#include <vector>
#include <memory>
#include <evm/types.h>
#include <evm/external.h>
#include <eos_evm.hpp>

class eos_external: public External {
  public:
    eos_external(eos_evm* contractArg);
    void log(std::vector<uint256_t> topics, bytes_t data);
    std::shared_ptr<bytes_t> code(uint256_t address);
    double balance(uint256_t address);
    bytes_t storageAt(uint256_t address);
    void suicide(uint256_t address);
  private:
    eos_evm* contract;
};

eos_external::eos_external(eos_evm* contractArg) {
  contract = contractArg;
}

void eos_external::log(std::vector<uint256_t> topics, bytes_t data) {
}

std::shared_ptr<bytes_t> eos_external::code(uint256_t address) {
  return std::make_shared<bytes_t>(bytes_t());
}

double eos_external::balance(uint256_t address) {
  return 0.0;
}

bytes_t eos_external::storageAt(uint256_t address) { 
  return bytes_t();
}

void eos_external::suicide(uint256_t address) {
}
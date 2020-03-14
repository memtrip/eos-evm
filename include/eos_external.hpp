#include <vector>
#include <evm/types.h>
#include <evm/external.h>

class eos_external: public External {
  public:
    eos_external();
    void log(std::vector<uint256_t> topics, bytes_t data);
    bytes_t code(uint256_t address);
    double balance(uint256_t address);
};

void eos_external::log(std::vector<uint256_t> topics, bytes_t data) {
}

bytes_t eos_external::code(uint256_t address) {
  return bytes_t();
}

double eos_external::balance(uint256_t address) {
  return 0.0;
}
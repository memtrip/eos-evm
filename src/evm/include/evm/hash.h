#include <vector>
#include <memory>
#include <evm/types.h>

class Hash {
  public:
    static bytes_t keccak256(bytes_t& bytes);
    static bytes_t keccak256(std::shared_ptr<bytes_t> bytes);
    static bytes_t keccak256(std::array<uint8_t, 33>& bytes);
    static bytes_t keccak512(bytes_t& bytes);
};
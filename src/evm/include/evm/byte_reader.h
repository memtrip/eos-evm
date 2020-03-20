#include <vector>
#include <evm/types.h>

class ByteReader {
  public:
    ByteReader(uint16_t p, const bytes_t& b): position(p), bytes(b) { };
    uint16_t position;
    bytes_t bytes;
    uint256_t read(uint16_t size);
    uint16_t len() const;
};
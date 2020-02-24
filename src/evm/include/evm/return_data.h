#include <evm/types.h>

class ReturnData {
  public:
    ReturnData();
    bytes_t mem;
    uint16_t offset;
    uint16_t size;
    void set(bytes_t memArg, uint16_t offsetArg, uint16_t sizeArg);
};
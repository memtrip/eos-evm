#include <evm/return_data.h>

ReturnData ReturnData::empty() {
  return {
    bytes_t(),
    uint256_t(),
    uint256_t()
  };
}
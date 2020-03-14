#include <evm/return_data.h>
#include <evm/call.h>

ReturnData ReturnData::empty() {
  return {
    bytes_t(),
    uint256_t(),
    uint256_t()
  };
}

ReturnData ReturnData::copy() {
  return {
    mem,
    offset,
    size
  };
}
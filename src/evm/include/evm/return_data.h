#pragma once
#include <variant>
#include <evm/types.h>

class ReturnData {
  public:
    bytes_t mem;
    uint256_t offset;
    uint256_t size;
    ReturnData copy() const;
    static ReturnData empty();
};

enum GasType {
  KNOWN,
  NEEDS_RETURN
};

struct NeedsReturn {
  uint256_t gasLeft;
  ReturnData data;
  bool apply;
};

typedef std::variant<
  uint256_t,
  NeedsReturn
> gas_return_t;

typedef std::pair<GasType, gas_return_t> gas_left_t;
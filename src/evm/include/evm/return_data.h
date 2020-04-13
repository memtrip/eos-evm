#pragma once
#include <variant>
#include <evm/types.h>

struct SlicePosition {
  uint64_t offset;
  uint64_t size;
};

enum GasType {
  KNOWN,
  NEEDS_RETURN
};

struct NeedsReturn {
  gas_t gasLeft;
  SlicePosition slicePosition;
  bool apply;
};

typedef std::variant<
  gas_t,
  NeedsReturn
> gas_return_t;

typedef std::pair<GasType, gas_return_t> gas_left_t;
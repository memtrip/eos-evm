#include <vector>
#include "types.h"

class Transaction {
  public:
    static transaction_t parse(std::vector<uint8_t> data);
};
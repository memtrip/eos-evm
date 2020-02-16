#include <vector>
#include <evm/types.h>

class Transaction {
  public:
    static transaction_t parse(bytes_t data);
};
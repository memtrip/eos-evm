#include <vector>
#include <evm/types.h>

class Transaction {
  public:
    static transaction_t parse(std::string hex);
    static bool signatureExists(transaction_t transaction);
};
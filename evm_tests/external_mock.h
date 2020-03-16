#include <evm/types.h>
#include <evm/external.h>

typedef std::vector<std::pair<std::vector<uint256_t>, bytes_t>> log_spy_t;

typedef std::vector<uint256_t> code_spy_t;

typedef std::vector<std::pair<uint256_t, double>> balance_responder_t;

typedef std::vector<std::pair<uint256_t, bytes_t>> code_responder_t;

class ExternalMock: public External {
  public:
    ExternalMock();
    void log(std::vector<uint256_t> topics, bytes_t data);
    bytes_t code(uint256_t address);
    double balance(uint256_t address);
    bytes_t storageAt(uint256_t address);
    log_spy_t logSpy;
    code_spy_t codeSpy;
    code_responder_t codeResponder;
    balance_responder_t balanceResponder;
};
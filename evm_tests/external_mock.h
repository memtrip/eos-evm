#include <memory>
#include <evm/types.h>
#include <evm/external.h>

typedef std::vector<std::pair<std::vector<uint256_t>, bytes_t>> log_spy_t;

typedef std::vector<std::pair<uint256_t, bytes_t>> bytes_spy_t;

typedef std::vector<uint256_t> word_spy_t;

typedef std::vector<std::pair<uint256_t, double>> balance_responder_t;

typedef std::vector<std::pair<uint256_t, bytes_t>> bytes_responder_t;

class ExternalMock: public External {
  public:
    ExternalMock();
    void log(const std::vector<uint256_t>& topics, std::shared_ptr<bytes_t> data);
    std::shared_ptr<bytes_t> code(const uint256_t& address);
    double balance(const uint256_t& address);
    bytes_t storageAt(const uint256_t& key, const uint256_t& codeAddress);
    void suicide(const uint256_t& address);
    void emplaceCode(const uint256_t& address, std::shared_ptr<bytes_t> code);
    log_spy_t logSpy;
    word_spy_t codeSpy;
    word_spy_t suicideSpy;
    bytes_spy_t emplaceSpy;
    bytes_responder_t codeResponder;
    balance_responder_t balanceResponder;
    bytes_responder_t storageResponder;
};
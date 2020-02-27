#include <evm/types.h>
#include <evm/external.h>

typedef std::vector<std::pair<std::vector<uint256_t>, bytes_t>> log_spy_t;

class ExternalMock: public External {
  public:
    ExternalMock();
    void log(std::vector<uint256_t> topics, bytes_t data);
  private:
    log_spy_t logSpy;
};
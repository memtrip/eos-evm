#include <evm/types.h>
#include <evm/external.h>

class ExternalMock: public External {
  public:
    void log(std::vector<uint256_t> topics, bytes_t data);
};
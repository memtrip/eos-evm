#include "external_mock.h"

ExternalMock::ExternalMock() {
  logSpy = log_spy_t();
}

void ExternalMock::log(std::vector<uint256_t> topics, bytes_t data) { 
  logSpy.push_back(std::make_pair(topics, data));
}
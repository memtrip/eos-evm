#include "external_mock.h"

ExternalMock::ExternalMock() {
  logSpy = log_spy_t();
  codeSpy = code_spy_t();
  codeResponse = bytes_t();
}

void ExternalMock::log(std::vector<uint256_t> topics, bytes_t data) { 
  logSpy.push_back(std::make_pair(topics, data));
}

bytes_t ExternalMock::code(uint256_t address) {
  codeSpy.push_back(address);
  return codeResponse;
}
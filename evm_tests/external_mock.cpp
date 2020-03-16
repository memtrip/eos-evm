#include "external_mock.h"

ExternalMock::ExternalMock() {
  logSpy = log_spy_t();
  codeSpy = code_spy_t();
  codeResponder = code_responder_t();
  balanceResponder = balance_responder_t();
}

void ExternalMock::log(std::vector<uint256_t> topics, bytes_t data) { 
  logSpy.push_back(std::make_pair(topics, data));
}

bytes_t ExternalMock::code(uint256_t address) {
  codeSpy.push_back(address);
  for (int i = 0; i < codeResponder.size(); i++) {
    if (codeResponder[i].first == address)
      return codeResponder[i].second;
  }
  return bytes_t();
}

double ExternalMock::balance(uint256_t address) { 
  for (int i = 0; i < balanceResponder.size(); i++) {
    if (balanceResponder[i].first == address)
      return balanceResponder[i].second;
  }
  return 0.0; 
};

bytes_t ExternalMock::storageAt(uint256_t address) { 
  return bytes_t(); 
};
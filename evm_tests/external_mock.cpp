#include "external_mock.h"

ExternalMock::ExternalMock() {
  logSpy = log_spy_t();
  codeSpy = word_spy_t();
  suicideSpy = word_spy_t();
  emplaceSpy = bytes_spy_t();
  codeResponder = bytes_responder_t();
  balanceResponder = balance_responder_t();
  storageResponder = bytes_responder_t();
}

void ExternalMock::log(const std::vector<uint256_t>& topics, std::shared_ptr<bytes_t> data) { 
  logSpy.push_back(std::make_pair(topics, bytes_t(data->begin(), data->end())));
}

std::shared_ptr<bytes_t> ExternalMock::code(const uint256_t& address) {
  codeSpy.push_back(address);
  for (int i = 0; i < codeResponder.size(); i++) {
    if (codeResponder[i].first == address)
      return  std::make_shared<bytes_t>(codeResponder[i].second);
  }
  return std::make_shared<bytes_t>(bytes_t());
}

double ExternalMock::balance(const uint256_t& address) { 
  for (int i = 0; i < balanceResponder.size(); i++) {
    if (balanceResponder[i].first == address)
      return balanceResponder[i].second;
  }
  return 0.0; 
};

bytes_t ExternalMock::storageAt(const uint256_t& key, const uint256_t& codeAddress) { 
  for (int i = 0; i < storageResponder.size(); i++) {
    if (storageResponder[i].first == key)
      return storageResponder[i].second;
  }
  return bytes_t();
};

void ExternalMock::suicide(const uint256_t& address) {
  suicideSpy.push_back(address);
}

void ExternalMock::emplaceCode(const uint256_t& address, std::shared_ptr<bytes_t> code) {
  emplaceSpy.push_back(std::make_pair(address, bytes_t(code->begin(), code->end())));
};
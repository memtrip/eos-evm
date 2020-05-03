#include <memory>
#include <evm/types.h>
#include <evm/external.h>
#include <evm/address.hpp>
#include <evm/big_int.hpp>
#include <evm/hex.hpp>

typedef std::vector<std::pair<std::vector<uint256_t>, bytes_t>> log_spy_t;
typedef std::vector<std::pair<uint256_t, std::string>> string_spy_t;
typedef std::vector<uint256_t> word_spy_t;
typedef std::vector<std::pair<uint256_t, uint256_t>> balance_responder_t;
typedef std::vector<std::pair<uint256_t, bytes_t>> bytes_responder_t;
typedef std::vector<std::pair<uint256_t, uint256_t>> word_responder_t;

class ExternalMock: public External {

  public:
    log_spy_t logSpy;
    word_spy_t codeSpy;
    word_spy_t selfdestructSpy;
    string_spy_t emplaceSpy;
    bytes_responder_t codeResponder;
    balance_responder_t balanceResponder;
    word_responder_t storageResponder;

    ExternalMock() {
      logSpy = log_spy_t();
      codeSpy = word_spy_t();
      selfdestructSpy = word_spy_t();
      emplaceSpy = string_spy_t();
      codeResponder = bytes_responder_t();
      balanceResponder = balance_responder_t();
      storageResponder = word_responder_t();
    }

    uint64_t senderNonce() {
      return 0;
    }

    uint64_t incrementNonce() { 
      return 1; 
    }

    uint256_t senderAccountBalance() {
      return uint256_t(0);
    }

    void log(const std::vector<uint256_t>& topics, const bytes_t& data) {
      logSpy.push_back(std::make_pair(topics, data));
    }

    std::shared_ptr<bytes_t> code(const uint256_t& address) {
      codeSpy.push_back(address);
      for (int i = 0; i < codeResponder.size(); i++) {
        if (codeResponder[i].first == address)
          return  std::make_shared<bytes_t>(codeResponder[i].second);
      }
      return std::make_shared<bytes_t>();
    }

    uint256_t balance(const uint256_t& addressWord) {
      for (int i = 0; i < balanceResponder.size(); i++) {
        if (balanceResponder[i].first == addressWord)
          return balanceResponder[i].second;
      }
      return uint256_t(0);
    }

    uint256_t storageAt(const uint256_t& key, const uint256_t& codeAddress) {
      for (int i = 0; i < storageResponder.size(); i++) {
        if (storageResponder[i].first == key)
          return storageResponder[i].second;
      }
      return uint256_t(0);
    }

    emplace_t selfdestruct(const uint256_t& address) {
      selfdestructSpy.push_back(address);
      return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
    }

    emplace_t transfer(const uint256_t& senderAddress, const uint256_t& toAddressWord, const uint256_t& value) { 
      return std::make_pair(EmplaceResult::EMPLACE_SUCCESS, 0);
    };

    emplace_t emplaceCode(
      const uint256_t& originWord,
      const uint256_t& codeAddressWord, 
      const uint256_t& endowment, 
      std::shared_ptr<bytes_t> code
    ) {
      emplaceSpy.push_back(std::make_pair(codeAddressWord, Hex::bytesToHex(code)));
      return std::make_pair(
        EmplaceResult::EMPLACE_SUCCESS,
        BigInt::toFixed32(Address::ethereumAddressFrom(codeAddressWord, uint256_t(0)))
      );
    }
};
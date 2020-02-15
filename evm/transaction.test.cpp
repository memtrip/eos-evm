#include "catch.hpp"
#include "transaction.h"
#include "utils.h"
#include "types.h"

TEST_CASE("Transaction data (1)", "[transaction)]") {

  // given
  std::string hex = "f85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870a801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  std::vector<uint8_t> bytes = Utils::hex2bin(hex);

  // when
  transaction_t transaction = Transaction::parse(bytes);

  // then
  CHECK(transaction_action_t::TRANSACTION_CALL == transaction.action);
  CHECK(uint256_t(0) == transaction.nonce);
  CHECK(uint256_t(0x01) == transaction.gas_price);
  CHECK(uint256_t(0x5208) == transaction.gas_limit);
  CHECK("095e7baea6a6c7c4c2dfeb977efac326af552d87" == 
    Utils::bytesTohex(transaction.to)
  );
  CHECK(uint256_t(0x0a) == transaction.value);
  CHECK("" == Utils::bytesTohex(transaction.data));
  CHECK(uint256_t(27) == transaction.v);
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == 
    Utils::bytesTohex(transaction.r)
  );
  CHECK("efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == 
    Utils::bytesTohex(transaction.s)
  );
}
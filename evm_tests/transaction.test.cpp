#include "catch.hpp"
#include <memory>
#include <evm/transaction.hpp>
#include <evm/utils.hpp>
#include <evm/types.h>
#include <evm/hex.hpp>
#include <evm/rlp_decode.hpp>
#include "test_utils.hpp"

TEST_CASE("Transaction call", "[transaction)]") {

  // given
  std::string hex = "f85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870a801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  bytes_t transactionBytes = Hex::hexToBytes(hex);;
  std::shared_ptr<std::vector<RLPItem>> rlp = std::make_shared<std::vector<RLPItem>>();
  RLPDecode::decode(transactionBytes, rlp);

  bytes_t v = Transaction::v(rlp);
  bytes_t r = Transaction::r(rlp);
  bytes_t s = Transaction::s(rlp);
  std::shared_ptr<bytes_t> data = Transaction::data(rlp);
  bytes_t address = Transaction::address(rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL ==Transaction::type(rlp));
  CHECK(uint256_t(0) == Transaction::nonce(rlp));
  CHECK(uint256_t(0x01) == Transaction::gasPrice(rlp));
  CHECK(uint64_t(0x5208) == Transaction::gasLimit(rlp));
  CHECK("095e7baea6a6c7c4c2dfeb977efac326af552d87" == 
    TestUtils::bytesToHex(address)
  );
  CHECK(uint256_t(0x0a) == Transaction::value(rlp));
  CHECK("" == TestUtils::bytesToHex(data));
  CHECK("1b" == TestUtils::bytesToHex(v));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == 
    TestUtils::bytesToHex(r)
  );
  CHECK("efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == 
    TestUtils::bytesToHex(s)
  );
}

TEST_CASE("Transaction contract", "[transaction)]") {

  // given
  std::string hex = "f901e4830263c8850879c08c7a830334508080b9018e6060604052341561000f57600080fd5b6101708061001e6000396000f3006060604052600436106100405763ffffffff7c010000000000000000000000000000000000000000000000000000000060003504166390b98a118114610045575b600080fd5b341561005057600080fd5b61007473ffffffffffffffffffffffffffffffffffffffff60043516602435610086565b60405190815260200160405180910390f35b600073521db06bf657ed1d6c98553a70319a8ddbac75a38373ffffffffffffffffffffffffffffffffffffffff811663a9059cbb83866040517c010000000000000000000000000000000000000000000000000000000063ffffffff851602815273ffffffffffffffffffffffffffffffffffffffff90921660048301526024820152604401600060405180830381600087803b151561012557600080fd5b6102c65a03f1151561013657600080fd5b5060019796505050505050505600a165627a7a723058203f339a2d354208169adb91e00c0cc7ffc9a9f9e67930818df75c3724b686179d002925a054a1805940f44a31be3fb3e284370f078f50f21e42cf0cbbad6a2f819211b2fea01d781f3d6b00ee9f1d7ffef90bd8ff78bfb0a88897b7f9a6c8cb4d923f7363f7";

  // when
  bytes_t transactionBytes = Hex::hexToBytes(hex);
  std::shared_ptr<std::vector<RLPItem>> rlp = std::make_shared<std::vector<RLPItem>>();
  RLPDecode::decode(transactionBytes, rlp);

  bytes_t v = Transaction::v(rlp);
  bytes_t r = Transaction::r(rlp);
  bytes_t s = Transaction::s(rlp);
  std::shared_ptr<bytes_t> data = Transaction::data(rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CREATE == Transaction::type(rlp));
  CHECK(uint256_t(156616) == Transaction::nonce(rlp));
  CHECK(uint256_t(0x0879c08c7a) == Transaction::gasPrice(rlp));
  CHECK(uint256_t(0x033450) == Transaction::gasLimit(rlp));
  CHECK(uint256_t(0x0) == Transaction::value(rlp));
  CHECK("6060604052341561000f57600080fd5b6101708061001e6000396000f3006060604052600436106100405763ffffffff7c010000000000000000000000000000000000000000000000000000000060003504166390b98a118114610045575b600080fd5b341561005057600080fd5b61007473ffffffffffffffffffffffffffffffffffffffff60043516602435610086565b60405190815260200160405180910390f35b600073521db06bf657ed1d6c98553a70319a8ddbac75a38373ffffffffffffffffffffffffffffffffffffffff811663a9059cbb83866040517c010000000000000000000000000000000000000000000000000000000063ffffffff851602815273ffffffffffffffffffffffffffffffffffffffff90921660048301526024820152604401600060405180830381600087803b151561012557600080fd5b6102c65a03f1151561013657600080fd5b5060019796505050505050505600a165627a7a723058203f339a2d354208169adb91e00c0cc7ffc9a9f9e67930818df75c3724b686179d0029" == 
    TestUtils::bytesToHex(data)
  );
  CHECK("25" == TestUtils::bytesToHex(v));
  CHECK("54a1805940f44a31be3fb3e284370f078f50f21e42cf0cbbad6a2f819211b2fe" == 
    TestUtils::bytesToHex(r)
  );
  CHECK("1d781f3d6b00ee9f1d7ffef90bd8ff78bfb0a88897b7f9a6c8cb4d923f7363f7" == 
    TestUtils::bytesToHex(s)
  );
}

TEST_CASE("Transaction call contract", "[transaction)]") {

  // given
  std::string hex = "f901958203fa85028fa6ae00830b5b519477598616174a411ae9a1e197640903faab9ac1ae880113806225a3c428b9012459f9cf0c000000000000000000000000000000000000000000000000000000000000004b00000000000000000000000000000000000000000000000000000000000000450000000000000000000000000000000000000000000000000000000000000080000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000a00000000000000000000000000000000000000000000000000000000000000041d2eaa477e07126513ab0c83723174b5e2e921382f216647f3cd0b88bffb97faf1767bd51418804947913b905809be585882f350bb272275943e4efdede347c421b0000000000000000000000000000000000000000000000000000000000000025a06a744032ad48eb8188d2f03ccc57bf9d91a45f780152288ee7abb700ee286393a02c2171570feb5e6855a62c4a9562b219ea4daeea98376a06f170e352035d353c";

  // when
  bytes_t transactionBytes = Hex::hexToBytes(hex);
  std::shared_ptr<std::vector<RLPItem>> rlp = std::make_shared<std::vector<RLPItem>>();
  RLPDecode::decode(transactionBytes, rlp);

  bytes_t v = Transaction::v(rlp);
  bytes_t r = Transaction::r(rlp);
  bytes_t s = Transaction::s(rlp);
  std::shared_ptr<bytes_t> data = Transaction::data(rlp);
  bytes_t address = Transaction::address(rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK(uint256_t(1018) == Transaction::nonce(rlp));
  CHECK(uint256_t(0x028fa6ae00) == Transaction::gasPrice(rlp));
  CHECK(uint256_t(0x0b5b51) == Transaction::gasLimit(rlp));
  CHECK("77598616174a411ae9a1e197640903faab9ac1ae" == 
    TestUtils::bytesToHex(address)
  );
  CHECK(uint256_t(0x0113806225a3c428) == Transaction::value(rlp));
  CHECK("59f9cf0c000000000000000000000000000000000000000000000000000000000000004b00000000000000000000000000000000000000000000000000000000000000450000000000000000000000000000000000000000000000000000000000000080000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000a00000000000000000000000000000000000000000000000000000000000000041d2eaa477e07126513ab0c83723174b5e2e921382f216647f3cd0b88bffb97faf1767bd51418804947913b905809be585882f350bb272275943e4efdede347c421b00000000000000000000000000000000000000000000000000000000000000" == 
    TestUtils::bytesToHex(data)
  );
  CHECK("25" == TestUtils::bytesToHex(v));
  CHECK("6a744032ad48eb8188d2f03ccc57bf9d91a45f780152288ee7abb700ee286393" == 
    TestUtils::bytesToHex(r)
  );
  CHECK("2c2171570feb5e6855a62c4a9562b219ea4daeea98376a06f170e352035d353c" == 
    TestUtils::bytesToHex(s)
  );
}

TEST_CASE("Transaction create (1)", "[transaction)]") {

  // given
  std::string hex = "f855018203e88207d0808088000000000000000025a06db1bf318e29ca002dc5314af1c0d1722659ad2dcb79357d7b7746aa5510afdaa0336e5414d221f6280598a5ac338a17331e2b925bd6ca693d85961248acefea72";

  // when
  bytes_t transactionBytes = Hex::hexToBytes(hex);
  std::shared_ptr<std::vector<RLPItem>> rlp = std::make_shared<std::vector<RLPItem>>();
  RLPDecode::decode(transactionBytes, rlp);

  // then
  bytes_t signatureBytes = Transaction::signature(rlp);
  uint8_t v = static_cast<uint8_t>(signatureBytes[0]);

  bytes_t digest = Transaction::digest(rlp, 0x01);

  CHECK(65 == signatureBytes.size());
  CHECK(27 == v);
  CHECK("1b6db1bf318e29ca002dc5314af1c0d1722659ad2dcb79357d7b7746aa5510afda336e5414d221f6280598a5ac338a17331e2b925bd6ca693d85961248acefea72" == 
    TestUtils::bytesToHex(signatureBytes)
  );
  CHECK("699f057e0ec6cf7ee1986c47e518b42ac4bdfe007c415097638c3b7166b65063" ==
    TestUtils::bytesToHex(digest)
  );
}

TEST_CASE("Transaction create (2)", "[transaction)]") {

  // given
  std::string hex = "f855018203e88207d0808088000000000000000025a078af7c5cff469dfc207c148a1326d3bd5d1bdc640dae2d20c30bba4f2416cfe1a00ef0a140416b1c684f4aeee637fd13779aac817a36b278c08dc24be679c02ce0";

  // when
  bytes_t transactionBytes = Hex::hexToBytes(hex);
  std::shared_ptr<std::vector<RLPItem>> rlp = std::make_shared<std::vector<RLPItem>>();
  RLPDecode::decode(transactionBytes, rlp);

  // then
  bytes_t signatureBytes = Transaction::signature(rlp);
  uint8_t v = static_cast<uint8_t>(signatureBytes[0]);

  bytes_t digest = Transaction::digest(rlp, 0x01);

  CHECK(65 == signatureBytes.size());
  CHECK(27 == v);
  CHECK("1b78af7c5cff469dfc207c148a1326d3bd5d1bdc640dae2d20c30bba4f2416cfe10ef0a140416b1c684f4aeee637fd13779aac817a36b278c08dc24be679c02ce0" == 
    TestUtils::bytesToHex(signatureBytes)
  );
  CHECK("699f057e0ec6cf7ee1986c47e518b42ac4bdfe007c415097638c3b7166b65063" ==
    TestUtils::bytesToHex(digest)
  );
}

TEST_CASE("Unsigned transaction", "[transaction)]") {

  // given
  std::string hex = "e6808609184e72a0008303000094b0920c523d582040f2bcb1bd7fb1c7c1ecebdb3480801c8080";

  // when
  bytes_t transactionBytes = Hex::hexToBytes(hex);
  std::shared_ptr<std::vector<RLPItem>> rlp = std::make_shared<std::vector<RLPItem>>();
  RLPDecode::decode(transactionBytes, rlp);

  bytes_t v = Transaction::v(rlp);
  bytes_t r = Transaction::r(rlp);
  bytes_t s = Transaction::s(rlp);
  bytes_t address = Transaction::address(rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK(uint256_t(0) == Transaction::nonce(rlp));
  CHECK(uint256_t(0x09184e72a000) == Transaction::gasPrice(rlp));
  CHECK(uint256_t(0x030000) == Transaction::gasLimit(rlp));
  CHECK("b0920c523d582040f2bcb1bd7fb1c7c1ecebdb34" == 
    TestUtils::bytesToHex(address)
  );
  CHECK(uint256_t(0x0) == Transaction::value(rlp));
  CHECK("1c" == TestUtils::bytesToHex(v));
  CHECK(0 == r.size());
  CHECK(0 == s.size());
}

TEST_CASE("Transaction digest", "[transaction)]") {

  // given
  std::string hex = "d5018203e88207d08080880000000000000000018080";

  // when
  bytes_t transactionBytes = Hex::hexToBytes(hex);
  std::shared_ptr<std::vector<RLPItem>> rlp = std::make_shared<std::vector<RLPItem>>();
  RLPDecode::decode(transactionBytes, rlp);

  bytes_t v = Transaction::v(rlp);
  bytes_t r = Transaction::r(rlp);
  bytes_t s = Transaction::s(rlp);
  std::shared_ptr<bytes_t> data = Transaction::data(rlp);

  bytes_t digest = Transaction::digest(rlp, 0x01);

  // then
  CHECK(TransactionActionType::TRANSACTION_CREATE == Transaction::type(rlp));
  CHECK(uint256_t(1) == Transaction::nonce(rlp));
  CHECK(uint256_t(0x03e8) == Transaction::gasPrice(rlp));
  CHECK(uint256_t(0x07d0) == Transaction::gasLimit(rlp));
  CHECK(uint256_t(0x0) == Transaction::value(rlp));
  CHECK("0000000000000000" == TestUtils::bytesToHex(data));
  CHECK("01" == TestUtils::bytesToHex(v));
  CHECK("" == 
    TestUtils::bytesToHex(r)
  );
  CHECK("" == 
    TestUtils::bytesToHex(s)
  );
  CHECK("699f057e0ec6cf7ee1986c47e518b42ac4bdfe007c415097638c3b7166b65063" ==
    TestUtils::bytesToHex(digest)
  );
}

TEST_CASE("Transaction message prefix", "[transaction)]") {

  // given
  std::string unsignedTransaction = "d5018203e88207d08080880000000000000000018080";

  // when
  bytes_t unsignedTransactionBytes = Hex::hexToBytes(unsignedTransaction);
  bytes_t digestWithPrefix = Transaction::prefixedBytes(unsignedTransactionBytes);

  // then
  CHECK("4f92172f1dfe85393316b4655808578b12882443614025a19d726ce8c0a6212f" == 
    TestUtils::bytesToHex(digestWithPrefix)
  );
}
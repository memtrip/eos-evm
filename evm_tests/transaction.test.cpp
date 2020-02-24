#include "catch.hpp"
#include <evm/transaction.h>
#include "utils.h"
#include <evm/types.h>
#include <evm/hex.h>

TEST_CASE("Transaction call", "[transaction)]") {

  // given
  std::string hex = "0xf85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870a801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  transaction_t transaction = Transaction::parse(hex, 0x01);

  // then
  CHECK(transaction_action_t::TRANSACTION_CALL == transaction.action);
  CHECK(uint256_t(0) == transaction.nonce);
  CHECK(uint256_t(0x01) == transaction.gas_price);
  CHECK(uint256_t(0x5208) == transaction.gas_limit);
  CHECK("095e7baea6a6c7c4c2dfeb977efac326af552d87" == 
    Hex::bytesToHex(transaction.to)
  );
  CHECK(uint256_t(0x0a) == transaction.value);
  CHECK("" == Hex::bytesToHex(transaction.data));
  CHECK("1b" == Hex::bytesToHex(transaction.v));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == 
    Hex::bytesToHex(transaction.r)
  );
  CHECK("efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == 
    Hex::bytesToHex(transaction.s)
  );
}

TEST_CASE("Transaction contract", "[transaction)]") {

  // given
  std::string hex = "0xf901e4830263c8850879c08c7a830334508080b9018e6060604052341561000f57600080fd5b6101708061001e6000396000f3006060604052600436106100405763ffffffff7c010000000000000000000000000000000000000000000000000000000060003504166390b98a118114610045575b600080fd5b341561005057600080fd5b61007473ffffffffffffffffffffffffffffffffffffffff60043516602435610086565b60405190815260200160405180910390f35b600073521db06bf657ed1d6c98553a70319a8ddbac75a38373ffffffffffffffffffffffffffffffffffffffff811663a9059cbb83866040517c010000000000000000000000000000000000000000000000000000000063ffffffff851602815273ffffffffffffffffffffffffffffffffffffffff90921660048301526024820152604401600060405180830381600087803b151561012557600080fd5b6102c65a03f1151561013657600080fd5b5060019796505050505050505600a165627a7a723058203f339a2d354208169adb91e00c0cc7ffc9a9f9e67930818df75c3724b686179d002925a054a1805940f44a31be3fb3e284370f078f50f21e42cf0cbbad6a2f819211b2fea01d781f3d6b00ee9f1d7ffef90bd8ff78bfb0a88897b7f9a6c8cb4d923f7363f7";

  // when
  transaction_t transaction = Transaction::parse(hex, 0x01);

  // then
  CHECK(transaction_action_t::TRANSACTION_CREATE == transaction.action);
  CHECK(uint256_t(156616) == transaction.nonce);
  CHECK(uint256_t(0x0879c08c7a) == transaction.gas_price);
  CHECK(uint256_t(0x033450) == transaction.gas_limit);
  CHECK(uint256_t(0x0) == transaction.value);
  CHECK("6060604052341561000f57600080fd5b6101708061001e6000396000f3006060604052600436106100405763ffffffff7c010000000000000000000000000000000000000000000000000000000060003504166390b98a118114610045575b600080fd5b341561005057600080fd5b61007473ffffffffffffffffffffffffffffffffffffffff60043516602435610086565b60405190815260200160405180910390f35b600073521db06bf657ed1d6c98553a70319a8ddbac75a38373ffffffffffffffffffffffffffffffffffffffff811663a9059cbb83866040517c010000000000000000000000000000000000000000000000000000000063ffffffff851602815273ffffffffffffffffffffffffffffffffffffffff90921660048301526024820152604401600060405180830381600087803b151561012557600080fd5b6102c65a03f1151561013657600080fd5b5060019796505050505050505600a165627a7a723058203f339a2d354208169adb91e00c0cc7ffc9a9f9e67930818df75c3724b686179d0029" == 
    Hex::bytesToHex(transaction.data)
  );
  CHECK("25" == Hex::bytesToHex(transaction.v));
  CHECK("54a1805940f44a31be3fb3e284370f078f50f21e42cf0cbbad6a2f819211b2fe" == 
    Hex::bytesToHex(transaction.r)
  );
  CHECK("1d781f3d6b00ee9f1d7ffef90bd8ff78bfb0a88897b7f9a6c8cb4d923f7363f7" == 
    Hex::bytesToHex(transaction.s)
  );
  CHECK(true == Transaction::signatureExists(transaction));
}

TEST_CASE("Transaction call contract", "[transaction)]") {

  // given
  std::string hex = "0xf901958203fa85028fa6ae00830b5b519477598616174a411ae9a1e197640903faab9ac1ae880113806225a3c428b9012459f9cf0c000000000000000000000000000000000000000000000000000000000000004b00000000000000000000000000000000000000000000000000000000000000450000000000000000000000000000000000000000000000000000000000000080000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000a00000000000000000000000000000000000000000000000000000000000000041d2eaa477e07126513ab0c83723174b5e2e921382f216647f3cd0b88bffb97faf1767bd51418804947913b905809be585882f350bb272275943e4efdede347c421b0000000000000000000000000000000000000000000000000000000000000025a06a744032ad48eb8188d2f03ccc57bf9d91a45f780152288ee7abb700ee286393a02c2171570feb5e6855a62c4a9562b219ea4daeea98376a06f170e352035d353c";

  // when
  transaction_t transaction = Transaction::parse(hex, 0x01);

  // then
  CHECK(transaction_action_t::TRANSACTION_CALL == transaction.action);
  CHECK(uint256_t(1018) == transaction.nonce);
  CHECK(uint256_t(0x028fa6ae00) == transaction.gas_price);
  CHECK(uint256_t(0x0b5b51) == transaction.gas_limit);
  CHECK("77598616174a411ae9a1e197640903faab9ac1ae" == 
    Hex::bytesToHex(transaction.to)
  );
  CHECK(uint256_t(0x0113806225a3c428) == transaction.value);
  CHECK("59f9cf0c000000000000000000000000000000000000000000000000000000000000004b00000000000000000000000000000000000000000000000000000000000000450000000000000000000000000000000000000000000000000000000000000080000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000a00000000000000000000000000000000000000000000000000000000000000041d2eaa477e07126513ab0c83723174b5e2e921382f216647f3cd0b88bffb97faf1767bd51418804947913b905809be585882f350bb272275943e4efdede347c421b00000000000000000000000000000000000000000000000000000000000000" == 
    Hex::bytesToHex(transaction.data)
  );
  CHECK("25" == Hex::bytesToHex(transaction.v));
  CHECK("6a744032ad48eb8188d2f03ccc57bf9d91a45f780152288ee7abb700ee286393" == 
    Hex::bytesToHex(transaction.r)
  );
  CHECK("2c2171570feb5e6855a62c4a9562b219ea4daeea98376a06f170e352035d353c" == 
    Hex::bytesToHex(transaction.s)
  );
  CHECK(true == Transaction::signatureExists(transaction));
}

TEST_CASE("Transaction create (1)", "[transaction)]") {

  // given
  std::string hex = "0xf855018203e88207d0808088000000000000000025a06db1bf318e29ca002dc5314af1c0d1722659ad2dcb79357d7b7746aa5510afdaa0336e5414d221f6280598a5ac338a17331e2b925bd6ca693d85961248acefea72";

  // when
  transaction_t transaction = Transaction::parse(hex, 0x01);

  // then
  bytes_t signatureBytes = Transaction::signatureBytes(transaction);
  
  uint8_t v = static_cast<uint8_t>(signatureBytes[0]);

  // Address: 0x8e2cec90ff1c67f51a7a3b986780d7c933f47fa9
  CHECK(65 == signatureBytes.size());
  CHECK(27 == v);
  CHECK("1b6db1bf318e29ca002dc5314af1c0d1722659ad2dcb79357d7b7746aa5510afda336e5414d221f6280598a5ac338a17331e2b925bd6ca693d85961248acefea72" == 
    Hex::bytesToHex(signatureBytes)
  );
  CHECK("699f057e0ec6cf7ee1986c47e518b42ac4bdfe007c415097638c3b7166b65063" ==
    Hex::bytesToHex(transaction.digest)
  );
}

TEST_CASE("Unsigned transaction", "[transaction)]") {

  // given
  std::string hex = "0xe6808609184e72a0008303000094b0920c523d582040f2bcb1bd7fb1c7c1ecebdb3480801c8080";

  // when
  transaction_t transaction = Transaction::parse(hex, 0x01);

  // then
  CHECK(transaction_action_t::TRANSACTION_CALL == transaction.action);
  CHECK(uint256_t(0) == transaction.nonce);
  CHECK(uint256_t(0x09184e72a000) == transaction.gas_price);
  CHECK(uint256_t(0x030000) == transaction.gas_limit);
  CHECK("b0920c523d582040f2bcb1bd7fb1c7c1ecebdb34" == 
    Hex::bytesToHex(transaction.to)
  );
  CHECK(uint256_t(0x0) == transaction.value);
  CHECK("1c" == Hex::bytesToHex(transaction.v));
  CHECK(0 == transaction.r.size());
  CHECK(0 == transaction.s.size());
  CHECK(false == Transaction::signatureExists(transaction));
}

TEST_CASE("Transaction digest", "[transaction)]") {

  // given
  std::string hex = "0xd5018203e88207d08080880000000000000000018080";

  // when
  transaction_t transaction = Transaction::parse(hex, 0x01);

  // then
  CHECK(transaction_action_t::TRANSACTION_CREATE == transaction.action);
  CHECK(uint256_t(1) == transaction.nonce);
  CHECK(uint256_t(0x03e8) == transaction.gas_price);
  CHECK(uint256_t(0x07d0) == transaction.gas_limit);
  CHECK(uint256_t(0x0) == transaction.value);
  CHECK("0000000000000000" == Hex::bytesToHex(transaction.data));
  CHECK("01" == Hex::bytesToHex(transaction.v));
  CHECK("" == 
    Hex::bytesToHex(transaction.r)
  );
  CHECK("" == 
    Hex::bytesToHex(transaction.s)
  );
  CHECK(false == Transaction::signatureExists(transaction));
  CHECK("699f057e0ec6cf7ee1986c47e518b42ac4bdfe007c415097638c3b7166b65063" ==
    Hex::bytesToHex(transaction.digest)
  );
}

TEST_CASE("Transaction message prefix", "[transaction)]") {

  // given
  std::string unsignedTransaction = "d5018203e88207d08080880000000000000000018080";

  // when
  bytes_t digestWithPrefix = Transaction::prefixedBytes(Hex::hexToBytes(unsignedTransaction));

  // then
  CHECK("4f92172f1dfe85393316b4655808578b12882443614025a19d726ce8c0a6212f" == 
    Hex::bytesToHex(digestWithPrefix)
  );
}
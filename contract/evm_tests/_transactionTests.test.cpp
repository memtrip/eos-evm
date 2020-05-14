//
// 14.05.2020
// Auto generated based off the Ethereum tests found here:
// https://github.com/ethereum/tests/blob/develop/TransactionTests/
//
#include "catch.hpp"
#include <memory>
#include <evm/transaction.hpp>
#include <evm/utils.hpp>
#include <evm/types.h>
#include <evm/hex.hpp>
#include <evm/rlp_decode.hpp>
#include "test_utils.hpp"

TEST_CASE("ttRSValue______$TransactionWithSvalue1", "[gen_transaction)]") {

  // given
  std::string hex = "f83f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a3664935301";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$RightVRSTestF0000000c", "[gen_transaction)]") {

  // given
  std::string hex = "f861030182c73894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a8082f030a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000c738" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000f030" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$RightVRSTestVPrefixedBy0", "[gen_transaction)]") {

  // given
  std::string hex = "f85f030182c73894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a8028a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000c738" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000028" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$RightVRSTestF0000000b", "[gen_transaction)]") {

  // given
  std::string hex = "f861030182c73894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a8082f029a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000c738" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000f029" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$TransactionWithRvalueTooHigh", "[gen_transaction)]") {

  // given
  std::string hex = "f85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba0fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$TransactionWithSvalue0", "[gen_transaction)]") {

  // given
  std::string hex = "f83f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a3664935380";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$TransactionWithSvalueLargerThan_c_secp256k1n_x05", "[gen_transaction)]") {

  // given
  std::string hex = "f85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a07fffffffffffffffffffffffffffffff5d576e7357a4501ddfe92f46681b20a1";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("7fffffffffffffffffffffffffffffff5d576e7357a4501ddfe92f46681b20a1" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$TransactionWithSvalueEqual_c_secp256k1n_x05", "[gen_transaction)]") {

  // given
  std::string hex = "f85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a07fffffffffffffffffffffffffffffff5d576e7357a4501ddfe92f46681b20a0";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("7fffffffffffffffffffffffffffffff5d576e7357a4501ddfe92f46681b20a0" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$unpadedRValue", "[gen_transaction)]") {

  // given
  std::string hex = "f8880d8609184e72a00082f710947c47ef93268a311f4cad0c750724299e9b72c26880a4379607f500000000000000000000000000000000000000000000000000000000000000051c9f6ab6dda9f4df56ea45583af36660329147f1753f3724ea5eb9ed83e812ca77a0495701e230667832c8999e884e366a61028633ecf951e8cd66d119f381ae5718";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("000000000000000000000000000000000000000000000000000000000000000d" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000009184e72a000" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000f710" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("379607f50000000000000000000000000000000000000000000000000000000000000005" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("0000000000000000000000007c47ef93268a311f4cad0c750724299e9b72c268" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001c" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("006ab6dda9f4df56ea45583af36660329147f1753f3724ea5eb9ed83e812ca77" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("495701e230667832c8999e884e366a61028633ecf951e8cd66d119f381ae5718" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$RightVRSTestF0000000e", "[gen_transaction)]") {

  // given
  std::string hex = "f86f030182c73894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a8090f0000000000000000000000000000029a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000c738" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("00000000000000000000000000000000f0000000000000000000000000000029" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$TransactionWithRSvalue0", "[gen_transaction)]") {

  // given
  std::string hex = "df800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801b8080";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$TransactionWithRSvalue1", "[gen_transaction)]") {

  // given
  std::string hex = "df800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801b0101";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$RightVRSTestF0000000d", "[gen_transaction)]") {

  // given
  std::string hex = "f86f030182c73894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a8090f0000000000000000000000000000028a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000c738" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("00000000000000000000000000000000f0000000000000000000000000000028" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$TransactionWithSvalueTooHigh", "[gen_transaction)]") {

  // given
  std::string hex = "f85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$TransactionWithRvalueHigh", "[gen_transaction)]") {

  // given
  std::string hex = "f85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba0fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364140a08887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364140" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("8887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$TransactionWithSvalueLessThan_c_secp256k1n_x05", "[gen_transaction)]") {

  // given
  std::string hex = "f85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a07fffffffffffffffffffffffffffffff5d576e7357a4501ddfe92f46681b2090";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("7fffffffffffffffffffffffffffffff5d576e7357a4501ddfe92f46681b2090" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$RightVRSTestVPrefixedBy0_2", "[gen_transaction)]") {

  // given
  std::string hex = "f85f030182c73894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a8029a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000c738" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000029" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$TransactionWithSvalueHigh", "[gen_transaction)]") {

  // given
  std::string hex = "f85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364140";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364140" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$TransactionWithRvalue0", "[gen_transaction)]") {

  // given
  std::string hex = "f83f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801b80a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$TransactionWithRvalue1", "[gen_transaction)]") {

  // given
  std::string hex = "f83f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801b01a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$RightVRSTestVPrefixedBy0_3", "[gen_transaction)]") {

  // given
  std::string hex = "f85f030182c73894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a8030a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000c738" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000030" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$RightVRSTestF0000000f", "[gen_transaction)]") {

  // given
  std::string hex = "f86f030182c73894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a8090f0000000000000000000000000000030a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000c738" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("00000000000000000000000000000000f0000000000000000000000000000030" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$RightVRSTestF0000000a", "[gen_transaction)]") {

  // given
  std::string hex = "f861030182c73894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a8082f028a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000c738" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000f028" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$TransactionWithRvaluePrefixed00", "[gen_transaction)]") {

  // given
  std::string hex = "f850800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801b910ebaaedce6af48a03bbfd25e8cd0364141a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("0000000000000000000000000000000ebaaedce6af48a03bbfd25e8cd0364141" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$TransactionWithSvaluePrefixed00", "[gen_transaction)]") {

  // given
  std::string hex = "f851800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a920ef0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("00000000000000000000000000000ef0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttAddress______$AddressMoreThan20", "[gen_transaction)]") {

  // given
  std::string hex = "f860800182520895b94f5374fce5edbc8e2a8697c15331677e6ebf0b1c0a801ca098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa08887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("0000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b1c" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001c" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("8887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttAddress______$AddressLessThan20", "[gen_transaction)]") {

  // given
  std::string hex = "f8528001825208870b9331677e6ebf0a801ca098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa08887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000b9331677e6ebf" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001c" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("8887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttAddress______$AddressLessThan20Prefixed0", "[gen_transaction)]") {

  // given
  std::string hex = "f85f800182520894000000000000000000000000000b9331677e6ebf0a801ca098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000b9331677e6ebf" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001c" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttAddress______$AddressMoreThan20PrefixedBy0", "[gen_transaction)]") {

  // given
  std::string hex = "f867367b8252089c0000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d870b121ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000036" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000007b" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("12" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttGasPrice______$TransactionWithHighGasPrice2", "[gen_transaction)]") {

  // given
  std::string hex = "f865808698852840a46f82520894095e7baea6a6c7c4c2dfeb977efac326af552d8780801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000098852840a46f" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$V_wrongvalue_ffff", "[gen_transaction)]") {

  // given
  std::string hex = "f863030182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a82554482ffffa098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("5544" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000ffff" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$WrongVRSTestVEqual29", "[gen_transaction)]") {

  // given
  std::string hex = "f85f800182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a801da098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa08887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001d" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("8887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$V_overflow64bitPlus28", "[gen_transaction)]") {

  // given
  std::string hex = "f86a03018255f094b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a8255448901000000000000001ca098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa08887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000055f0" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("5544" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000001000000000000001c" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("8887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$V_overflow32bit", "[gen_transaction)]") {

  // given
  std::string hex = "f866030182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a82554485010000001ba098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa08887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("5544" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000010000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("8887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$V_equals37", "[gen_transaction)]") {

  // given
  std::string hex = "f865808698852840a46f82d6d894095e7baea6a6c7c4c2dfeb977efac326af552d87808025a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000098852840a46f" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000d6d8" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000025" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$V_wrongvalue_101", "[gen_transaction)]") {

  // given
  std::string hex = "f863030182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a825544820101a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("5544" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000101" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$V_overflow32bitSigned", "[gen_transaction)]") {

  // given
  std::string hex = "f865030182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a825544847fffffffa098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa08887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("5544" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000007fffffff" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("8887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$V_wrongvalue_121", "[gen_transaction)]") {

  // given
  std::string hex = "f863030182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a825544820121a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("5544" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000121" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$WrongVRSTestVEqual39", "[gen_transaction)]") {

  // given
  std::string hex = "f85f800182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a8027a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000027" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$WrongVRSTestVEqual41", "[gen_transaction)]") {

  // given
  std::string hex = "f85f800182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a8029a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000029" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$V_wrongvalue_123", "[gen_transaction)]") {

  // given
  std::string hex = "f863030182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a825544820123a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("5544" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000123" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$WrongVRSTestVEqual36", "[gen_transaction)]") {

  // given
  std::string hex = "f85f800182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a8024a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000024" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$V_wrongvalue_122", "[gen_transaction)]") {

  // given
  std::string hex = "f863030182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a825544820122a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("5544" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000122" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$WrongVRSTestVEqual26", "[gen_transaction)]") {

  // given
  std::string hex = "f85f800182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a801aa098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa08887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001a" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("8887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$V_overflow64bitPlus27", "[gen_transaction)]") {

  // given
  std::string hex = "f86a03018255f094b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a8255448901000000000000001ba098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa08887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000055f0" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("5544" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000001000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("8887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$V_wrongvalue_ff", "[gen_transaction)]") {

  // given
  std::string hex = "f862030182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a82554481ffa098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("5544" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000000ff" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$WrongVRSTestVEqual31", "[gen_transaction)]") {

  // given
  std::string hex = "f85f800182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a801fa098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa08887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001f" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("8887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$V_wrongvalue_124", "[gen_transaction)]") {

  // given
  std::string hex = "f863030182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a825544820124a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("5544" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000124" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttVValue______$V_overflow64bitSigned", "[gen_transaction)]") {

  // given
  std::string hex = "f85f030182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a801ca098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa08887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001c" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("8887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttEIP2028______$DataTestZeroBytes", "[gen_transaction)]") {

  // given
  std::string hex = "f882800182540794095e7baea6a6c7c4c2dfeb977efac326af552d8780a3deadbeef0000000101010010101010101010101010101aaabbbbbbcccccccddddddddd1ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005407" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("deadbeef0000000101010010101010101010101010101aaabbbbbbcccccccddddddddd" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttEIP2028______$DataTestSufficientGas2028", "[gen_transaction)]") {

  // given
  std::string hex = "f882800182540894095e7baea6a6c7c4c2dfeb977efac326af552d8780a3deadbeef0000000101010010101010101010101010101aaabbbbbbcccccccddddddddd1ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005408" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("deadbeef0000000101010010101010101010101010101aaabbbbbbcccccccddddddddd" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$EmptyTransaction", "[gen_transaction)]") {

  // given
  std::string hex = "f85d80808094095e7baea6a6c7c4c2dfeb977efac326af552d8780801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$ZeroSigTransaction", "[gen_transaction)]") {

  // given
  std::string hex = "df030182c73894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a80808080";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000c738" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$Vitalik_3", "[gen_transaction)]") {

  // given
  std::string hex = "f864028504a817c80282f618943535353535353535353535353535353535353535088025a02d7c5bef027816a800da1736444fb58a807ef4c9603b7848673f7e3a68eb14a5a02d7c5bef027816a800da1736444fb58a807ef4c9603b7848673f7e3a68eb14a5";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000004a817c802" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000f618" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000008" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("0000000000000000000000003535353535353535353535353535353535353535" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000025" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("2d7c5bef027816a800da1736444fb58a807ef4c9603b7848673f7e3a68eb14a5" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("2d7c5bef027816a800da1736444fb58a807ef4c9603b7848673f7e3a68eb14a5" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$RSsecp256k1", "[gen_transaction)]") {

  // given
  std::string hex = "f85f030182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a801ca0fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141a0fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001c" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$Vitalik_16", "[gen_transaction)]") {

  // given
  std::string hex = "f8651380830493e094000000000000000000000000000000000000001280856d6f6f73652aa0d0e340578f9d733986f6a55c5401953c90f7ccd46fe72d5588592dd9cbdf1e03a001d8d63149bd986f363084ac064e8387850d80e5238cc16ed4d30fd0a5af7261";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000013" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000493e0" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("6d6f6f7365" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000012" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000002a" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("d0e340578f9d733986f6a55c5401953c90f7ccd46fe72d5588592dd9cbdf1e03" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("01d8d63149bd986f363084ac064e8387850d80e5238cc16ed4d30fd0a5af7261" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$Vitalik_17", "[gen_transaction)]") {

  // given
  std::string hex = "f8651480830493e094000000000000000000000000000000000000002280856d6f6f73652aa04bc84887af29d2b159ee290dee793bdba34079428f48699e9fc92a7e12d4aeafa063b9d78c5a36f96454fe2d5c1eb7c0264f6273afdc0ba28dd9a8f00eadaf7476";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000014" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000493e0" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("6d6f6f7365" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000022" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000002a" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("4bc84887af29d2b159ee290dee793bdba34079428f48699e9fc92a7e12d4aeaf" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("63b9d78c5a36f96454fe2d5c1eb7c0264f6273afdc0ba28dd9a8f00eadaf7476" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$Vitalik_2", "[gen_transaction)]") {

  // given
  std::string hex = "f864018504a817c80182a410943535353535353535353535353535353535353535018025a0489efdaa54c0f20c7adf612882df0950f5a951637e0307cdcb4c672f298b8bcaa0489efdaa54c0f20c7adf612882df0950f5a951637e0307cdcb4c672f298b8bc6";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000004a817c801" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000a410" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("0000000000000000000000003535353535353535353535353535353535353535" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000025" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("489efdaa54c0f20c7adf612882df0950f5a951637e0307cdcb4c672f298b8bca" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("489efdaa54c0f20c7adf612882df0950f5a951637e0307cdcb4c672f298b8bc6" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$Vitalik_5", "[gen_transaction)]") {

  // given
  std::string hex = "f865048504a817c80483019a28943535353535353535353535353535353535353535408025a013600b294191fc92924bb3ce4b969c1e7e2bab8f4c93c3fc6d0a51733df3c063a013600b294191fc92924bb3ce4b969c1e7e2bab8f4c93c3fc6d0a51733df3c060";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000004" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000004a817c804" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000019a28" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000040" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("0000000000000000000000003535353535353535353535353535353535353535" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000025" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("13600b294191fc92924bb3ce4b969c1e7e2bab8f4c93c3fc6d0a51733df3c063" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("13600b294191fc92924bb3ce4b969c1e7e2bab8f4c93c3fc6d0a51733df3c060" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$Vitalik_10", "[gen_transaction)]") {

  // given
  std::string hex = "f867088504a817c8088302e2489435353535353535353535353535353535353535358202008025a064b1702d9298fee62dfeccc57d322a463ad55ca201256d01f62b45b2e1c21c12a064b1702d9298fee62dfeccc57d322a463ad55ca201256d01f62b45b2e1c21c10";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000008" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000004a817c808" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000002e248" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000200" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("0000000000000000000000003535353535353535353535353535353535353535" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000025" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("64b1702d9298fee62dfeccc57d322a463ad55ca201256d01f62b45b2e1c21c12" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("64b1702d9298fee62dfeccc57d322a463ad55ca201256d01f62b45b2e1c21c10" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$Vitalik_9", "[gen_transaction)]") {

  // given
  std::string hex = "f867078504a817c807830290409435353535353535353535353535353535353535358201578025a052f1a9b320cab38e5da8a8f97989383aab0a49165fc91c737310e4f7e9821021a052f1a9b320cab38e5da8a8f97989383aab0a49165fc91c737310e4f7e9821021";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000007" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000004a817c807" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000029040" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000157" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("0000000000000000000000003535353535353535353535353535353535353535" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000025" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("52f1a9b320cab38e5da8a8f97989383aab0a49165fc91c737310e4f7e9821021" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("52f1a9b320cab38e5da8a8f97989383aab0a49165fc91c737310e4f7e9821021" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$ZeroSigTransaction6", "[gen_transaction)]") {

  // given
  std::string hex = "df030182c73894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a80058080";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000c738" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000005" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$Vitalik_8", "[gen_transaction)]") {

  // given
  std::string hex = "f866068504a817c80683023e3894353535353535353535353535353535353535353581d88025a06455bf8ea6e7463a1046a0b52804526e119b4bf5136279614e0b1e8e296a4e2fa06455bf8ea6e7463a1046a0b52804526e119b4bf5136279614e0b1e8e296a4e2d";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000006" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000004a817c806" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000023e38" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000000d8" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("0000000000000000000000003535353535353535353535353535353535353535" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000025" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("6455bf8ea6e7463a1046a0b52804526e119b4bf5136279614e0b1e8e296a4e2f" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("6455bf8ea6e7463a1046a0b52804526e119b4bf5136279614e0b1e8e296a4e2d" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$RightVRSTest", "[gen_transaction)]") {

  // given
  std::string hex = "f85f030182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a801ca098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001c" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$Vitalik_11", "[gen_transaction)]") {

  // given
  std::string hex = "f867098504a817c809830334509435353535353535353535353535353535353535358202d98025a052f8f61201b2b11a78d6e866abc9c3db2ae8631fa656bfe5cb53668255367afba052f8f61201b2b11a78d6e866abc9c3db2ae8631fa656bfe5cb53668255367afb";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000009" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000004a817c809" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000033450" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000002d9" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("0000000000000000000000003535353535353535353535353535353535353535" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000025" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("52f8f61201b2b11a78d6e866abc9c3db2ae8631fa656bfe5cb53668255367afb" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("52f8f61201b2b11a78d6e866abc9c3db2ae8631fa656bfe5cb53668255367afb" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$invalidSignature", "[gen_transaction)]") {

  // given
  std::string hex = "f8638080830f424094095e7baea6a6c7c4c2dfeb977efac326af552d87830186a0801ba0ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa0badf00d70ec28c94a3b55ec771bcbc70778d6ee0b51ca7ea9514594c861b1884";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000f4240" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000186a0" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("badf00d70ec28c94a3b55ec771bcbc70778d6ee0b51ca7ea9514594c861b1884" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$WrongVRSTestVOverflow", "[gen_transaction)]") {

  // given
  std::string hex = "f861800182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a80820136a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa08887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000136" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("8887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$Vitalik_4", "[gen_transaction)]") {

  // given
  std::string hex = "f865038504a817c803830148209435353535353535353535353535353535353535351b8025a02a80e1ef1d7842f27f2e6be0972bb708b9a135c38860dbe73c27c3486c34f4e0a02a80e1ef1d7842f27f2e6be0972bb708b9a135c38860dbe73c27c3486c34f4de";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000004a817c803" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000014820" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("0000000000000000000000003535353535353535353535353535353535353535" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000025" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("2a80e1ef1d7842f27f2e6be0972bb708b9a135c38860dbe73c27c3486c34f4e0" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("2a80e1ef1d7842f27f2e6be0972bb708b9a135c38860dbe73c27c3486c34f4de" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$Vitalik_12", "[gen_transaction)]") {

  // given
  std::string hex = "f8610e80830493e080809560f2ff61000080610011600039610011565b6000f31ca0a310f4d0b26207db76ba4e1e6e7cf1857ee3aa8559bcbc399a6b09bfea2d30b4a06dff38c645a1486651a717ddf3daccb4fd9a630871ecea0758ddfcf2774f9bc6";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CREATE == Transaction::type(rlp));
  CHECK("000000000000000000000000000000000000000000000000000000000000000e" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000493e0" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("60f2ff61000080610011600039610011565b6000f3" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001c" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("a310f4d0b26207db76ba4e1e6e7cf1857ee3aa8559bcbc399a6b09bfea2d30b4" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("6dff38c645a1486651a717ddf3daccb4fd9a630871ecea0758ddfcf2774f9bc6" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$Vitalik_7", "[gen_transaction)]") {

  // given
  std::string hex = "f865058504a817c8058301ec309435353535353535353535353535353535353535357d8025a04eebf77a833b30520287ddd9478ff51abbdffa30aa90a8d655dba0e8a79ce0c1a04eebf77a833b30520287ddd9478ff51abbdffa30aa90a8d655dba0e8a79ce0c1";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000005" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000004a817c805" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000001ec30" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000007d" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("0000000000000000000000003535353535353535353535353535353535353535" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000025" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("4eebf77a833b30520287ddd9478ff51abbdffa30aa90a8d655dba0e8a79ce0c1" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("4eebf77a833b30520287ddd9478ff51abbdffa30aa90a8d655dba0e8a79ce0c1" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$TransactionWithTooManyRLPElements", "[gen_transaction)]") {

  // given
  std::string hex = "f865800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870a801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804851de98d0edd";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$ZeroSigTransaction5", "[gen_transaction)]") {

  // given
  std::string hex = "df030182c73894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a80048080";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000c738" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000004" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$libsecp256k1test", "[gen_transaction)]") {

  // given
  std::string hex = "d1808609184e72a00082f3888080801b2c04";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CREATE == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000009184e72a000" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000f388" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000002c" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000004" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$ZeroSigTransaction4", "[gen_transaction)]") {

  // given
  std::string hex = "df030182c73894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a80038080";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000c738" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$Vitalik_6", "[gen_transaction)]") {

  // given
  std::string hex = "f865058504a817c8058301ec309435353535353535353535353535353535353535357d8025a04eebf77a833b30520287ddd9478ff51abbdffa30aa90a8d655dba0e8a79ce0c1a04eebf77a833b30520287ddd9478ff51abbdffa30aa90a8d655dba0e8a79ce0c1";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000005" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000004a817c805" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000001ec30" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000007d" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("0000000000000000000000003535353535353535353535353535353535353535" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000025" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("4eebf77a833b30520287ddd9478ff51abbdffa30aa90a8d655dba0e8a79ce0c1" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("4eebf77a833b30520287ddd9478ff51abbdffa30aa90a8d655dba0e8a79ce0c1" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$Vitalik_13", "[gen_transaction)]") {

  // given
  std::string hex = "f8660f80830493e09400000000000000000000000000000000000000c08086646f6e6b65791ba09f00c6da4f2e4b5f3316e70c7669f9df71fa21d533afa63450065731132ba7b6a03886c27a8b3515ab9e2e04492f8214718621421e92d3b6954d9e3fb409ead788";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("000000000000000000000000000000000000000000000000000000000000000f" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000493e0" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("646f6e6b6579" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000000c0" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("9f00c6da4f2e4b5f3316e70c7669f9df71fa21d533afa63450065731132ba7b6" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("3886c27a8b3515ab9e2e04492f8214718621421e92d3b6954d9e3fb409ead788" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$ZeroSigTransaction3", "[gen_transaction)]") {

  // given
  std::string hex = "df030182c73894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a80028080";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000c738" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000002" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$SenderTest", "[gen_transaction)]") {

  // given
  std::string hex = "f85f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870a801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$Vitalik_14", "[gen_transaction)]") {

  // given
  std::string hex = "f8610f80830493e080019560f3ff61000080610011600039610011565b6000f31ba0af2944b645e280a35789aacfce7e16a8d57b43a0076dfd564bdc0395e3576324a05272a0013f198713128bb0e3da43bb03ec7224c5509d4cabbe39fd31c36b5786";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CREATE == Transaction::type(rlp));
  CHECK("000000000000000000000000000000000000000000000000000000000000000f" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000493e0" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("60f3ff61000080610011600039610011565b6000f3" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("af2944b645e280a35789aacfce7e16a8d57b43a0076dfd564bdc0395e3576324" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("5272a0013f198713128bb0e3da43bb03ec7224c5509d4cabbe39fd31c36b5786" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$Vitalik_1", "[gen_transaction)]") {

  // given
  std::string hex = "f864808504a817c800825208943535353535353535353535353535353535353535808025a0044852b2a670ade5407e78fb2863c51de9fcb96542a07186fe3aeda6bb8a116da0044852b2a670ade5407e78fb2863c51de9fcb96542a07186fe3aeda6bb8a116d";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000004a817c800" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("0000000000000000000000003535353535353535353535353535353535353535" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000025" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("044852b2a670ade5407e78fb2863c51de9fcb96542a07186fe3aeda6bb8a116d" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("044852b2a670ade5407e78fb2863c51de9fcb96542a07186fe3aeda6bb8a116d" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$Vitalik_15", "[gen_transaction)]") {

  // given
  std::string hex = "f8651280830493e094000000000000000000000000000000000000000180856d6f6f736529a0376d0277dd3a2a9229dbcb5530b532c7e4cb0f821e0ca27d9acb940970d500d8a00ab2798f9d9c2f7551eb29d56878f8e342b45ca45f413b0fcba793d094f36f2b";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000012" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000493e0" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("6d6f6f7365" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000029" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("376d0277dd3a2a9229dbcb5530b532c7e4cb0f821e0ca27d9acb940970d500d8" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("0ab2798f9d9c2f7551eb29d56878f8e342b45ca45f413b0fcba793d094f36f2b" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttSignature______$ZeroSigTransaction2", "[gen_transaction)]") {

  // given
  std::string hex = "df030182c73894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a80018080";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000c738" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttNonce______$TransactionWithHighNonce32", "[gen_transaction)]") {

  // given
  std::string hex = "f8648501000000000182520894095e7baea6a6c7c4c2dfeb977efac326af552d8780801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000100000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000005208" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttData______$DataTestZeroBytes", "[gen_transaction)]") {

  // given
  std::string hex = "f87c80018261a894095e7baea6a6c7c4c2dfeb977efac326af552d870a9d00000000000000000000000000000000000000000000000000000000001ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000061a8" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttData______$DataTestNotEnoughGAS", "[gen_transaction)]") {

  // given
  std::string hex = "f86d800182521c94095e7baea6a6c7c4c2dfeb977efac326af552d870a8e0358ac39584bc98a7c979f984b031ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000521c" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("0358ac39584bc98a7c979f984b03" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttData______$DataTestLastZeroBytes", "[gen_transaction)]") {

  // given
  std::string hex = "f87c80018261a894095e7baea6a6c7c4c2dfeb977efac326af552d870a9d01000000000000000000000000000000000000000000000000000000001ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000061a8" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("0100000000000000000000000000000000000000000000000000000000" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttData______$dataTx_bcValidBlockTestFrontier", "[gen_transaction)]") {

  // given
  std::string hex = "f901fb803282c3508080b901ae60056013565b6101918061001d6000396000f35b3360008190555056006001600060e060020a6000350480630a874df61461003a57806341c0e1b514610058578063a02b161e14610066578063dbbdf0831461007757005b610045600435610149565b80600160a060020a031660005260206000f35b610060610161565b60006000f35b6100716004356100d4565b60006000f35b61008560043560243561008b565b60006000f35b600054600160a060020a031632600160a060020a031614156100ac576100b1565b6100d0565b8060018360005260205260406000208190555081600060005260206000a15b5050565b600054600160a060020a031633600160a060020a031614158015610118575033600160a060020a0316600182600052602052604060002054600160a060020a031614155b61012157610126565b610146565b600060018260005260205260406000208190555080600060005260206000a15b50565b60006001826000526020526040600020549050919050565b600054600160a060020a031633600160a060020a0316146101815761018f565b600054600160a060020a0316ff5b561ca0c5689ed1ad124753d54576dfb4b571465a41900a1dff4058d8adf16f752013d0a01221cbd70ec28c94a3b55ec771bcbc70778d6ee0b51ca7ea9514594c861b1884";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CREATE == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000032" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000c350" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("60056013565b6101918061001d6000396000f35b3360008190555056006001600060e060020a6000350480630a874df61461003a57806341c0e1b514610058578063a02b161e14610066578063dbbdf0831461007757005b610045600435610149565b80600160a060020a031660005260206000f35b610060610161565b60006000f35b6100716004356100d4565b60006000f35b61008560043560243561008b565b60006000f35b600054600160a060020a031632600160a060020a031614156100ac576100b1565b6100d0565b8060018360005260205260406000208190555081600060005260206000a15b5050565b600054600160a060020a031633600160a060020a031614158015610118575033600160a060020a0316600182600052602052604060002054600160a060020a031614155b61012157610126565b610146565b600060018260005260205260406000208190555080600060005260206000a15b50565b60006001826000526020526040600020549050919050565b600054600160a060020a031633600160a060020a0316146101815761018f565b600054600160a060020a0316ff5b56" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001c" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("c5689ed1ad124753d54576dfb4b571465a41900a1dff4058d8adf16f752013d0" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1221cbd70ec28c94a3b55ec771bcbc70778d6ee0b51ca7ea9514594c861b1884" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttData______$DataTestEnoughGAS", "[gen_transaction)]") {

  // given
  std::string hex = "f86d80018259d894095e7baea6a6c7c4c2dfeb977efac326af552d870a8e0358ac39584bc98a7c979f984b031ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000059d8" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("0358ac39584bc98a7c979f984b03" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttData______$DataTestFirstZeroBytes", "[gen_transaction)]") {

  // given
  std::string hex = "f87c80018261a894095e7baea6a6c7c4c2dfeb977efac326af552d870a9d00000000000000000000000000010000000000000000000000000000001ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("00000000000000000000000000000000000000000000000000000000000061a8" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("0000000000000000000000000001000000000000000000000000000000" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttData______$dataTx_bcValidBlockTest", "[gen_transaction)]") {

  // given
  std::string hex = "f901fc8032830138808080b901ae60056013565b6101918061001d6000396000f35b3360008190555056006001600060e060020a6000350480630a874df61461003a57806341c0e1b514610058578063a02b161e14610066578063dbbdf0831461007757005b610045600435610149565b80600160a060020a031660005260206000f35b610060610161565b60006000f35b6100716004356100d4565b60006000f35b61008560043560243561008b565b60006000f35b600054600160a060020a031632600160a060020a031614156100ac576100b1565b6100d0565b8060018360005260205260406000208190555081600060005260206000a15b5050565b600054600160a060020a031633600160a060020a031614158015610118575033600160a060020a0316600182600052602052604060002054600160a060020a031614155b61012157610126565b610146565b600060018260005260205260406000208190555080600060005260206000a15b50565b60006001826000526020526040600020549050919050565b600054600160a060020a031633600160a060020a0316146101815761018f565b600054600160a060020a0316ff5b561ca0c5689ed1ad124753d54576dfb4b571465a41900a1dff4058d8adf16f752013d0a01221cbd70ec28c94a3b55ec771bcbc70778d6ee0b51ca7ea9514594c861b1884";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CREATE == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000032" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000013880" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("60056013565b6101918061001d6000396000f35b3360008190555056006001600060e060020a6000350480630a874df61461003a57806341c0e1b514610058578063a02b161e14610066578063dbbdf0831461007757005b610045600435610149565b80600160a060020a031660005260206000f35b610060610161565b60006000f35b6100716004356100d4565b60006000f35b61008560043560243561008b565b60006000f35b600054600160a060020a031632600160a060020a031614156100ac576100b1565b6100d0565b8060018360005260205260406000208190555081600060005260206000a15b5050565b600054600160a060020a031633600160a060020a031614158015610118575033600160a060020a0316600182600052602052604060002054600160a060020a031614155b61012157610126565b610146565b600060018260005260205260406000208190555080600060005260206000a15b50565b60006001826000526020526040600020549050919050565b600054600160a060020a031633600160a060020a0316146101815761018f565b600054600160a060020a0316ff5b56" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001c" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("c5689ed1ad124753d54576dfb4b571465a41900a1dff4058d8adf16f752013d0" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1221cbd70ec28c94a3b55ec771bcbc70778d6ee0b51ca7ea9514594c861b1884" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttGasLimit______$NotEnoughGasLimit", "[gen_transaction)]") {

  // given
  std::string hex = "f85f0301824e2094b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a801ca098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa08887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000003" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000004e20" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000b94f5374fce5edbc8e2a8697c15331677e6ebf0b" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001c" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("8887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttGasLimit______$TransactionWithGasLimitOverflow63_1", "[gen_transaction)]") {

  // given
  std::string hex = "f865800188800000000000000194095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000008000000000000001" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttGasLimit______$TransactionWithGasLimitOverflow63", "[gen_transaction)]") {

  // given
  std::string hex = "f865800188800000000000000094095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000008000000000000000" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttGasLimit______$TransactionWithHighGas", "[gen_transaction)]") {

  // given
  std::string hex = "f8658001887fffffffffffffff94095e7baea6a6c7c4c2dfeb977efac326af552d8780801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000007fffffffffffffff" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttGasLimit______$TransactionWithGasLimitxPriceOverflow2", "[gen_transaction)]") {

  // given
  std::string hex = "f86780873b9403b9403b5c8398968094095e7baea6a6c7c4c2dfeb977efac326af552d8780801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("000000000000000000000000000000000000000000000000003b9403b9403b5c" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000989680" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttGasLimit______$TransactionWithHihghGasLimit63m1", "[gen_transaction)]") {

  // given
  std::string hex = "f8658001887fffffffffffffff94095e7baea6a6c7c4c2dfeb977efac326af552d87808025a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000007fffffffffffffff" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000025" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("98ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttGasLimit______$TransactionWithGasLimitOverflow2", "[gen_transaction)]") {

  // given
  std::string hex = "f865800188800000000000000094095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);

  // then
  CHECK(TransactionActionType::TRANSACTION_CALL == Transaction::type(rlp));
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" ==  Utils::uint256_2str(Transaction::nonce(rlp)));
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" ==  Utils::uint256_2str(Transaction::gasPrice(rlp)));
  CHECK("0000000000000000000000000000000000000000000000008000000000000000" ==  Utils::uint256_2str(Transaction::gas(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000000b" ==  Utils::uint256_2str(Transaction::value(rlp)));
  CHECK("" == Hex::bytesToHex(Transaction::data(rlp)));
  CHECK("000000000000000000000000095e7baea6a6c7c4c2dfeb977efac326af552d87" == TestUtils::bytesToPaddedHex(Transaction::address(rlp)));
  CHECK("000000000000000000000000000000000000000000000000000000000000001b" == TestUtils::bytesToPaddedHex(Transaction::v(rlp)));
  CHECK("48b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353" == TestUtils::bytesToPaddedHex(Transaction::r(rlp)));
  CHECK("1fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804" == TestUtils::bytesToPaddedHex(Transaction::s(rlp)));

  delete rlp;
}

TEST_CASE("ttRSValue______$TransactionWithSvalueOverflow", "[gen_transaction)]") {
  // given
  std::string hex = "0xf861800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a2fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f0000";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);
  delete rlp;
}

TEST_CASE("ttRSValue______$TransactionWithRvalueOverflow", "[gen_transaction)]") {
  // given
  std::string hex = "0xf861800182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba2fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd03641410000a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);
  delete rlp;
}

TEST_CASE("ttGasPrice______$TransactionWithHighGasPrice", "[gen_transaction)]") {
  // given
  std::string hex = "0xf87f80a0ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff82520894095e7baea6a6c7c4c2dfeb977efac326af552d8780801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);
  delete rlp;
}

TEST_CASE("ttGasPrice______$TransactionWithGasPriceOverflow", "[gen_transaction)]") {
  // given
  std::string hex = "0xf88080a101000000000000000000000000000000000000000000000000000000000000000082520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);
  delete rlp;
}

TEST_CASE("ttVValue______$V_equals38", "[gen_transaction)]") {
  // given
  std::string hex = "0xf87f80a0ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff82520894095e7baea6a6c7c4c2dfeb977efac326af552d87808026a098ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4aa01887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);
  delete rlp;
}

TEST_CASE("ttSignature______$WrongVRSTestIncorrectSize", "[gen_transaction)]") {
  // given
  std::string hex = "0xf863800182520894b94f5374fce5edbc8e2a8697c15331677e6ebf0b0a801ca298ff921201554726367d2be8c804a7ff89ccf285ebc57dff8ae4c44b9c19ac4a02c3a28887321be575c8095f789dd4c743dfe42c1820f9231f98a962b210e3ac2452a302c3";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);
  delete rlp;
}

TEST_CASE("ttSignature______$TransactionWithTooFewRLPElements", "[gen_transaction)]") {
  // given
  std::string hex = "0xf85b800194095e7baea6a6c7c4c2dfeb977efac326af552d87801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);
  delete rlp;
}

TEST_CASE("ttNonce______$TransactionWithNonceOverflow", "[gen_transaction)]") {
  // given
  std::string hex = "0xf880a10100000000000000000000000000000000000000000000000000000000000000000182520894095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);
  delete rlp;
}

TEST_CASE("ttNonce______$TransactionWithHighNonce256", "[gen_transaction)]") {
  // given
  std::string hex = "0xf87fa0ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0182520894095e7baea6a6c7c4c2dfeb977efac326af552d8780801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);
  delete rlp;
}

TEST_CASE("ttGasLimit______$TransactionWithGasLimitxPriceOverflow", "[gen_transaction)]") {
  // given
  std::string hex = "0xf8858088016345785d8a0000a0ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff94095e7baea6a6c7c4c2dfeb977efac326af552d8780801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);
  delete rlp;
}

TEST_CASE("ttGasLimit______$TransactionWithGasLimitOverflow", "[gen_transaction)]") {
  // given
  std::string hex = "0xf87e8001a101000000000000000000000000000000000000000000000000000000000000000094095e7baea6a6c7c4c2dfeb977efac326af552d870b801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);
  delete rlp;
}

TEST_CASE("ttValue______$TransactionWithHighValue", "[gen_transaction)]") {
  // given
  std::string hex = "0xf87f800182520894095e7baea6a6c7c4c2dfeb977efac326af552d87a0ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a01fffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);
  delete rlp;
}

TEST_CASE("ttValue______$TransactionWithHighValueOverflow", "[gen_transaction)]") {
  // given
  std::string hex = "0xf880800182520894095e7baea6a6c7c4c2dfeb977efac326af552d87a1010000000000000000000000000000000000000000000000000000000000000000801ba048b55bfa915ac795c431978d8a6a992b628d557da5ff759b307d495a36649353a0efffd310ac743f371de3b9f7f9cb56c0b28ad43601b4ab949f53faa07bd2c804";

  // when
  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(Hex::hexToBytes(hex), rlp);
  delete rlp;
}



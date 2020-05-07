#include "catch.hpp"
#include "external_mock.hpp"
#include <evm/types.h>
#include <evm/pending_state.hpp>

TEST_CASE("Put two items under different codeAddress, but the same key, retrieve the item for the first codeAddress", "[pending_state]") {

  // given
  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  PendingState pendingState {};

  // when
  pendingState.currentStackDepth = 1;
  pendingState.putState(uint256_t(0x00), uint256_t(0xB1), uint256_t(0xA1));
  pendingState.putState(uint256_t(0x00), uint256_t(0xB2), uint256_t(0xA2));

  // then
  CHECK(uint256_t(0xB1) == pendingState.getState(uint256_t(0x00), uint256_t(0xA1), external));
  CHECK(uint256_t(0xB2) == pendingState.getState(uint256_t(0x00), uint256_t(0xA2), external));
}

TEST_CASE("Get an item for a given key, when there are multiple items for the same key across different depths", "[pending_state]") {

  // given
  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  PendingState pendingState {};

  // when
  pendingState.currentStackDepth = 1;
  pendingState.putState(uint256_t(0x00), uint256_t(0xF1), uint256_t(0xA1));
  pendingState.putState(uint256_t(0x00), uint256_t(0xF2), uint256_t(0xA1));
  pendingState.currentStackDepth = 2;
  pendingState.putState(uint256_t(0x00), uint256_t(0xF3), uint256_t(0xA1));
  pendingState.putState(uint256_t(0x00), uint256_t(0xF4), uint256_t(0xA1));
  pendingState.currentStackDepth = 3;
  pendingState.putState(uint256_t(0x00), uint256_t(0xF5), uint256_t(0xA1));

  // then
  CHECK(uint256_t(0xF5) == pendingState.getState(uint256_t(0x00), uint256_t(0xA1), external));

  // and when
  pendingState.revert(3);

  // and then
  CHECK(uint256_t(0xF4) == pendingState.getState(uint256_t(0x00), uint256_t(0xA1), external));

  // and when
  pendingState.revert(2);

  // and then
  CHECK(uint256_t(0xF2) == pendingState.getState(uint256_t(0x00), uint256_t(0xA1), external));
}

TEST_CASE("Get an item for a given key, when there is 1 entry in the pending state", "[pending_state]") {

  // given
  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  PendingState pendingState {};

  // when
  pendingState.currentStackDepth = 1;
  pendingState.putState(uint256_t(0x00), uint256_t(0xB1), uint256_t(0xA1));

  // then
  CHECK(uint256_t(0xB1) == pendingState.getState(uint256_t(0x00), uint256_t(0xA1), external));
}

TEST_CASE("Get an item for a given key, when there are no entries in the pending state, but an entry in the external state", "[pending_state]") {

  // given
  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();

  PendingState pendingState {};

  // when
  external->storageResponder.push_back(std::make_pair(uint256_t(0x00), uint256_t(0xB1)));

  // then
  CHECK(uint256_t(0xB1) == pendingState.getState(uint256_t(0x00), uint256_t(0xA1), external));
}

TEST_CASE("Revert account state at the deepest depth", "[pending_state]") {

  // given
  PendingState pendingState {};

  pendingState.currentStackDepth = 1;
  pendingState.putState(uint256_t(0x00), uint256_t(0xF1), uint256_t(0xA1));
  pendingState.putState(uint256_t(0x02), uint256_t(0xF2), uint256_t(0xA2));
  pendingState.currentStackDepth = 2;
  pendingState.putState(uint256_t(0x03), uint256_t(0xF3), uint256_t(0xA3));
  pendingState.putState(uint256_t(0x04), uint256_t(0xF4), uint256_t(0xA4));
  pendingState.currentStackDepth = 3;
  pendingState.putState(uint256_t(0x05), uint256_t(0xF5), uint256_t(0xA5));

  // when
  pendingState.revert(3);

  // then
  CHECK(uint256_t(0xA1) == pendingState.accountState[0].codeAddress);
  CHECK(uint256_t(0xA2) == pendingState.accountState[1].codeAddress);
  CHECK(uint256_t(0xA3) == pendingState.accountState[2].codeAddress);
  CHECK(uint256_t(0xA4) == pendingState.accountState[3].codeAddress);

  CHECK(1 == pendingState.accountState[0].stackDepth);
  CHECK(1 == pendingState.accountState[1].stackDepth);
  CHECK(2 == pendingState.accountState[2].stackDepth);
  CHECK(2 == pendingState.accountState[3].stackDepth);
  CHECK(4 == pendingState.accountState.size());
}

TEST_CASE("Revert account state at a middle depth", "[pending_state]") {

  // given
  PendingState pendingState {};

  pendingState.currentStackDepth = 1;
  pendingState.putState(uint256_t(0x00), uint256_t(0xF1), uint256_t(0xA1));
  pendingState.putState(uint256_t(0x02), uint256_t(0xF2), uint256_t(0xA2));
  pendingState.currentStackDepth = 2;
  pendingState.putState(uint256_t(0x03), uint256_t(0xF3), uint256_t(0xA3));
  pendingState.putState(uint256_t(0x04), uint256_t(0xF4), uint256_t(0xA4));
  pendingState.currentStackDepth = 3;
  pendingState.putState(uint256_t(0x05), uint256_t(0xF5), uint256_t(0xA5));

  // when
  pendingState.revert(2);

  // then
  CHECK(uint256_t(0xA1) == pendingState.accountState[0].codeAddress);
  CHECK(uint256_t(0xA2) == pendingState.accountState[1].codeAddress);

  CHECK(1 == pendingState.accountState[0].stackDepth);
  CHECK(1 == pendingState.accountState[1].stackDepth);
  CHECK(2 == pendingState.accountState.size());
}

TEST_CASE("Revert account state at the top", "[pending_state]") {

  // given
  PendingState pendingState {};

  pendingState.currentStackDepth = 1;
  pendingState.putState(uint256_t(0x00), uint256_t(0xF1), uint256_t(0xA1));
  pendingState.putState(uint256_t(0x02), uint256_t(0xF2), uint256_t(0xA2));
  pendingState.currentStackDepth = 2;
  pendingState.putState(uint256_t(0x03), uint256_t(0xF3), uint256_t(0xA3));
  pendingState.putState(uint256_t(0x04), uint256_t(0xF4), uint256_t(0xA4));
  pendingState.currentStackDepth = 3;
  pendingState.putState(uint256_t(0x05), uint256_t(0xF5), uint256_t(0xA5));

  // when
  pendingState.revert(1);

  // then
  CHECK(0 == pendingState.accountState.size());
}

TEST_CASE("Revert logs at the deepest depth", "[pending_state]") {

  // given
  PendingState pendingState {};

  pendingState.currentStackDepth = 1;
  pendingState.log(std::vector<uint256_t>(), bytes_t { 1, 0 });
  pendingState.log(std::vector<uint256_t>(), bytes_t { 1, 1 });
  pendingState.currentStackDepth = 2;
  pendingState.log(std::vector<uint256_t>(), bytes_t { 2, 0 });
  pendingState.log(std::vector<uint256_t>(), bytes_t { 2, 1 });
  pendingState.currentStackDepth = 3;
  pendingState.log(std::vector<uint256_t>(), bytes_t { 3, 0 });

  // when
  pendingState.revert(3);

  // then
  CHECK(Hex::bytesToHex(bytes_t { 1, 0 }) == Hex::bytesToHex(pendingState.logs[0].data));
  CHECK(Hex::bytesToHex(bytes_t { 1, 1 }) == Hex::bytesToHex(pendingState.logs[1].data));
  CHECK(Hex::bytesToHex(bytes_t { 2, 0 }) == Hex::bytesToHex(pendingState.logs[2].data));
  CHECK(Hex::bytesToHex(bytes_t { 2, 1 }) == Hex::bytesToHex(pendingState.logs[3].data));

  CHECK(1 == pendingState.logs[0].stackDepth);
  CHECK(1 == pendingState.logs[1].stackDepth);
  CHECK(2 == pendingState.logs[2].stackDepth);
  CHECK(2 == pendingState.logs[3].stackDepth);
  CHECK(4 == pendingState.logs.size());
}

TEST_CASE("Revert logs at a middle depth", "[pending_state]") {

  // given
  PendingState pendingState {};

  pendingState.currentStackDepth = 1;
  pendingState.log(std::vector<uint256_t>(), bytes_t { 1, 0 });
  pendingState.log(std::vector<uint256_t>(), bytes_t { 1, 1 });
  pendingState.currentStackDepth = 2;
  pendingState.log(std::vector<uint256_t>(), bytes_t { 2, 0 });
  pendingState.log(std::vector<uint256_t>(), bytes_t { 2, 1 });
  pendingState.currentStackDepth = 3;
  pendingState.log(std::vector<uint256_t>(), bytes_t { 3, 0 });

  // when
  pendingState.revert(2);

  // then
  CHECK(Hex::bytesToHex(bytes_t { 1, 0 }) == Hex::bytesToHex(pendingState.logs[0].data));
  CHECK(Hex::bytesToHex(bytes_t { 1, 1 }) == Hex::bytesToHex(pendingState.logs[1].data));
  CHECK(2 == pendingState.logs.size());
}

TEST_CASE("Revert logs at the top", "[pending_state]") {

  // given
  PendingState pendingState {};

  pendingState.currentStackDepth = 1;
  pendingState.log(std::vector<uint256_t>(), bytes_t { 1, 0 });
  pendingState.log(std::vector<uint256_t>(), bytes_t { 1, 1 });
  pendingState.currentStackDepth = 2;
  pendingState.log(std::vector<uint256_t>(), bytes_t { 2, 0 });
  pendingState.log(std::vector<uint256_t>(), bytes_t { 2, 1 });
  pendingState.currentStackDepth = 3;
  pendingState.log(std::vector<uint256_t>(), bytes_t { 3, 0 });

  // when
  pendingState.revert(1);

  // then
  CHECK(0 == pendingState.logs.size());
}
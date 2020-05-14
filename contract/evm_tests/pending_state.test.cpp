#include "catch.hpp"
#include <evm/types.h>
#include <evm/pending_state.hpp>
#include <evm/hex.hpp>
#include <evm/utils.hpp>

TEST_CASE("Put two items under different codeAddress, but the same key, retrieve the item for the first codeAddress", "[pending_state]") {

  // given
  PendingState pendingState {};

  // when
  pendingState.currentStackDepth = 1;
  pendingState.putState(uint256_t(0x00), uint256_t(0xB1), uint256_t(0xA1));
  pendingState.putState(uint256_t(0x00), uint256_t(0xB2), uint256_t(0xA2));

  // then
  CHECK(uint256_t(0xB1) == pendingState.getState(uint256_t(0x00), uint256_t(0xA1)));
  CHECK(uint256_t(0xB2) == pendingState.getState(uint256_t(0x00), uint256_t(0xA2)));
}

TEST_CASE("Get an item for a given key, when there are multiple items for the same key across different depths", "[pending_state]") {

  // given
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
  CHECK(uint256_t(0xF5) == pendingState.getState(uint256_t(0x00), uint256_t(0xA1)));

  // and when
  pendingState.revert(3);

  // and then
  CHECK(uint256_t(0xF4) == pendingState.getState(uint256_t(0x00), uint256_t(0xA1)));

  // and when
  pendingState.revert(2);

  // and then
  CHECK(uint256_t(0xF2) == pendingState.getState(uint256_t(0x00), uint256_t(0xA1)));
}

TEST_CASE("Get an item for a given key, when there is 1 entry in the pending state", "[pending_state]") {

  // given
  PendingState pendingState {};

  // when
  pendingState.currentStackDepth = 1;
  pendingState.putState(uint256_t(0x00), uint256_t(0xB1), uint256_t(0xA1));

  // then
  CHECK(uint256_t(0xB1) == pendingState.getState(uint256_t(0x00), uint256_t(0xA1)));
}

TEST_CASE("Get an item for a given key, when there are no entries in the pending state, but an entry in the external state", "[pending_state]") {
  // given
  PendingState pendingState {};

  // then  
  CHECK(uint256_t(0xFF) == pendingState.getState(uint256_t(0x00), uint256_t(0xA1), [] () {
    return uint256_t(0xFF);
  }));
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

TEST_CASE("A persisted balance with no pending balance changes is returned unmodified", "[pending_state]") {

  // given
  PendingState pendingState {};

  // when
  uint256_t balance = pendingState.balanceWithPendingChanges(uint256_t(0xA), uint256_t(0x9));

  // then
  CHECK(Utils::uint256_2str(balance) == "0000000000000000000000000000000000000000000000000000000000000009");
}

TEST_CASE("A persisted balance with a pending addition, includes the addition in the balance", "[pending_state]") {

  // given
  PendingState pendingState {};

  pendingState.currentStackDepth = 1;
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x2));

  // when
  uint256_t balance = pendingState.balanceWithPendingChanges(uint256_t(0xA), uint256_t(0x9));

  // then
  CHECK(Utils::uint256_2str(balance) == "000000000000000000000000000000000000000000000000000000000000000b");
}

TEST_CASE("A persisted balance with two pending additions, includes the additions in the balance", "[pending_state]") {

  // given
  PendingState pendingState {};

  pendingState.currentStackDepth = 1;
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x2));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x2));

  // when
  uint256_t balance = pendingState.balanceWithPendingChanges(uint256_t(0xA), uint256_t(0x5));

  // then
  CHECK(Utils::uint256_2str(balance) == "0000000000000000000000000000000000000000000000000000000000000009");
}

TEST_CASE("A persisted balance with a pending substraction, includes the subtraction in the balance", "[pending_state]") {

  // given
  PendingState pendingState {};

  pendingState.currentStackDepth = 1;
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_SUBTRACT, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x4));

  // when
  uint256_t balance = pendingState.balanceWithPendingChanges(uint256_t(0xA), uint256_t(0x5));

  // then
  CHECK(Utils::uint256_2str(balance) == "0000000000000000000000000000000000000000000000000000000000000001");
}

TEST_CASE("A persisted balance with two pending subtractions, includes the subtractions in the balance", "[pending_state]") {

  // given
  PendingState pendingState {};

  pendingState.currentStackDepth = 1;
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_SUBTRACT, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x2));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_SUBTRACT, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x2));

  // when
  uint256_t balance = pendingState.balanceWithPendingChanges(uint256_t(0xA), uint256_t(0x5));

  // then
  CHECK(Utils::uint256_2str(balance) == "0000000000000000000000000000000000000000000000000000000000000001");
}

TEST_CASE("A persisted balance with pending additions and subtractions, includes the changes in the balance", "[pending_state]") {

  // given
  PendingState pendingState {};

  pendingState.currentStackDepth = 1;
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x2));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_SUBTRACT, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x2));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x2));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_SUBTRACT, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x2));

  // when
  uint256_t balance = pendingState.balanceWithPendingChanges(uint256_t(0xA), uint256_t(0x5));

  // then
  CHECK(Utils::uint256_2str(balance) == "0000000000000000000000000000000000000000000000000000000000000005");
}

TEST_CASE("A persisted balance with pending additions and subtractions, includes the changes in the balance (2)", "[pending_state]") {

  // given
  PendingState pendingState {};

  pendingState.currentStackDepth = 1;
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x20));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_SUBTRACT, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x19));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x27));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_SUBTRACT, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x33));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x1000));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_SUBTRACT, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x999));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x927));

  // when
  uint256_t balance = pendingState.balanceWithPendingChanges(uint256_t(0xA), uint256_t(0x112));

  // then
  CHECK(Utils::uint256_2str(balance) == "000000000000000000000000000000000000000000000000000000000000109b");
}

TEST_CASE("Balances changes from a reverted stack depth are not included in the final balance", "[pending_state]") {

  // given
  PendingState pendingState {};

  pendingState.currentStackDepth = 1;
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x10));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x20));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x30));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x12));
  pendingState.currentStackDepth = 2;
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_SUBTRACT, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x72));

  // when
  uint256_t balanceBeforeRevert = pendingState.balanceWithPendingChanges(uint256_t(0xA), uint256_t(0x00));

  pendingState.revert(2);

  uint256_t balanceAfterRevert = pendingState.balanceWithPendingChanges(uint256_t(0xA), uint256_t(0x00));

  // then
  CHECK(Utils::uint256_2str(balanceBeforeRevert) == "0000000000000000000000000000000000000000000000000000000000000000");
  CHECK(Utils::uint256_2str(balanceAfterRevert) == "0000000000000000000000000000000000000000000000000000000000000072");
}

TEST_CASE("Balance changes are resolved for each address", "[pending_state]") {

  // given
  PendingState pendingState {};

  pendingState.currentStackDepth = 1;
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_CONTRACT, uint256_t(0xA), uint256_t(0x10));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xC), uint256_t(0x20));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xB), uint256_t(0x30));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_CONTRACT, uint256_t(0xA), uint256_t(0x12));
  pendingState.currentStackDepth = 2;
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_SUBTRACT, BalanceAddressType::BALANCE_ADDRESS_CONTRACT, uint256_t(0xA), uint256_t(0x72));
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_SUBTRACT, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xC), uint256_t(0x72));
  pendingState.currentStackDepth = 3;
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_ADD, BalanceAddressType::BALANCE_ADDRESS_CONTRACT, uint256_t(0xA), uint256_t(0x72));

  // when
  std::vector<resolved_balance_t> resolvedBalances = pendingState.resolveBalanceChanges();

  // then
  CHECK(3 == resolvedBalances.size());
  CHECK(Utils::uint256_2str(resolvedBalances[0].value) == 
    "0000000000000000000000000000000000000000000000000000000000000022"
  );
  CHECK(resolvedBalances[0].addressType == BalanceAddressType::BALANCE_ADDRESS_CONTRACT);
  CHECK(Utils::uint256_2str(resolvedBalances[1].value) == 
    "0000000000000000000000000000000000000000000000000000000000000030"
  );
  CHECK(resolvedBalances[1].addressType == BalanceAddressType::BALANCE_ADDRESS_ACCOUNT);
  CHECK(Utils::uint256_2str(resolvedBalances[2].value) == 
    "0000000000000000000000000000000000000000000000000000000000000000"
  );
  CHECK(resolvedBalances[2].addressType == BalanceAddressType::BALANCE_ADDRESS_ACCOUNT);
}

TEST_CASE("Ensure that balances can't overflow", "[pending_state]") {

  // given
  PendingState pendingState {};

  pendingState.currentStackDepth = 1;
  pendingState.putBalanceChange(BalanceChangeType::BALANCE_CHANGE_SUBTRACT, BalanceAddressType::BALANCE_ADDRESS_ACCOUNT, uint256_t(0xA), uint256_t(0x72));

  // when
  uint256_t balanceOverflow = pendingState.balanceWithPendingChanges(uint256_t(0xA), uint256_t(0x00));

  // then
  CHECK(Utils::uint256_2str(balanceOverflow) == "0000000000000000000000000000000000000000000000000000000000000000");
}


TEST_CASE("A self destruct is tracked by pending changes", "[pending_state]") {

  // given
  PendingState pendingState {};

  // when
  pendingState.putSelfDestruct(uint256_t(0xA));
  pendingState.putSelfDestruct(uint256_t(0xB));

  // then
  REQUIRE(2 == pendingState.selfDestruct.size());
  CHECK(Utils::uint256_2str(pendingState.selfDestruct[0].address) == 
    "000000000000000000000000000000000000000000000000000000000000000a"
  );
  CHECK(Utils::uint256_2str(pendingState.selfDestruct[1].address) == 
    "000000000000000000000000000000000000000000000000000000000000000b"
  );
}

TEST_CASE("A self destruct pending change is removed by a revert", "[pending_state]") {

  // given
  PendingState pendingState {};

  // when
  pendingState.currentStackDepth = 1;
  pendingState.putSelfDestruct(uint256_t(0xA));
  pendingState.currentStackDepth = 2;
  pendingState.putSelfDestruct(uint256_t(0xB));
  pendingState.revert(2);

  // then
  REQUIRE(1 == pendingState.selfDestruct.size());
  CHECK(Utils::uint256_2str(pendingState.selfDestruct[0].address) == 
    "000000000000000000000000000000000000000000000000000000000000000a"
  );
}

TEST_CASE("Two contracts are created at different stack depths, and no changes are reverted", "[pending_state]") {

  // given
  PendingState pendingState {};

  // when
  pendingState.currentStackDepth = 1;
  pendingState.putContractCreate(uint256_t(0xA));
  pendingState.currentStackDepth = 2;
  pendingState.putContractCreate(uint256_t(0xB));

  // then
  REQUIRE(0 == pendingState.revertedContractCreation.size());
}

TEST_CASE("Two contracts are created at different stack depths, stack depth 2 is reverted", "[pending_state]") {

  // given
  PendingState pendingState {};

  // when
  pendingState.currentStackDepth = 1;
  pendingState.putContractCreate(uint256_t(0xA));
  pendingState.currentStackDepth = 2;
  pendingState.putContractCreate(uint256_t(0xB));
  pendingState.revert(2);

  // then
  REQUIRE(1 == pendingState.revertedContractCreation.size());
  CHECK(Utils::uint256_2str(pendingState.revertedContractCreation[0].address) == 
    "000000000000000000000000000000000000000000000000000000000000000b"
  );
}

TEST_CASE("Two contracts are created at different stack depths, stack depth 1 is reverted", "[pending_state]") {

  // given
  PendingState pendingState {};

  // when
  pendingState.currentStackDepth = 1;
  pendingState.putContractCreate(uint256_t(0xA));
  pendingState.currentStackDepth = 2;
  pendingState.putContractCreate(uint256_t(0xB));
  pendingState.revert(1);

  // then
  REQUIRE(2 == pendingState.revertedContractCreation.size());
  CHECK(Utils::uint256_2str(pendingState.revertedContractCreation[0].address) == 
    "000000000000000000000000000000000000000000000000000000000000000a"
  );
  CHECK(Utils::uint256_2str(pendingState.revertedContractCreation[1].address) == 
    "000000000000000000000000000000000000000000000000000000000000000b"
  );
}
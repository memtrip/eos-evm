#include <string>
#include <eosio/crypto.hpp>
#include <eos_evm.hpp>
#include <eos_system.hpp>
#include <eos_ecrecover.hpp>
#include <eos_utils.hpp>
#include <eos_execute.hpp>

#include <evm/address.hpp>
#include <evm/transaction.hpp>
#include <evm/hex.hpp>
#include <evm/rlp_decode.hpp>
#include <evm/big_int.hpp>
#include <evm/hash.hpp>
#include <evm/memory.hpp>

ACTION eos_evm::raw(name from, string code, string sender) {
  require_auth(from);

  bytes_t bytes = Hex::hexToBytes(code);

  std::shared_ptr<std::vector<RLPItem>> rlp = std::make_shared<std::vector<RLPItem>>();
  RLPDecode::decode(bytes, rlp);

  std::shared_ptr<External> external = std::make_shared<eos_external>(this);
  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);
  std::shared_ptr<Call> call = std::make_unique<Call>(0);

  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> memory = std::make_shared<Memory>(memoryBytes);

  if (Transaction::hasSignature(rlp)) {
    bytes_t accountIdentifierBytes = eos_ecrecover::recover(
      from.to_string(),
      rlp
    );

    eosio::checksum256 accountIdentifier = eos_utils::hexToChecksum256(accountIdentifierBytes);
    account_table _account(get_self(), get_self().value);
    auto idx = _account.get_index<name("accountid")>();
    auto itr = idx.find(accountIdentifier);

    check(itr != idx.end(), "The account identifier associated with this transaction does not exist.");

    std::shared_ptr<bytes_t> data = Transaction::data(rlp);
    uint256_t address = BigInt::fromBigEndianBytes(accountIdentifierBytes);
    call_result_t callResult = eos_execute::transaction(address, rlp, data, memory, external, accountState, call);
    handleCallResult(from, callResult, accountState);
    idx.modify(itr, from, [&](auto& account) {
      account.nonce += 1;
    });
  } else {
    std::pair<bytes_t, eosio::checksum256> accountIdentifier = eos_utils::senderToChecksum256(sender);
    account_table _account(get_self(), get_self().value);
    auto idx = _account.get_index<name("accountid")>();
    auto itr = idx.find(accountIdentifier.second);

    check(itr != idx.end(), "Could not find sender, did you provide the correct account identifier?");
    check(has_auth(itr->user), "You do not have permission to execute a transaction for the specified sender.");

    std::shared_ptr<bytes_t> data = Transaction::data(rlp);
    uint256_t address = BigInt::fromBigEndianBytes(accountIdentifier.first);
    call_result_t callResult = eos_execute::transaction(address, rlp, data, memory, external, accountState, call);
    handleCallResult(from, callResult, accountState);
    idx.modify(itr, from, [&](auto& account) {
      account.nonce += 1;
    });
  }
}

void eos_evm::handleCallResult(name from, call_result_t callResult, std::shared_ptr<AccountState> accountState) {
  switch (callResult.first) {
    case MESSAGE_CALL_SUCCESS:
    case MESSAGE_CALL_APPLY_CREATE:
      {
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);
        uint256_t gasLeft = callReturn.gasLeft;
        commitState(from, accountState);
        break;
      }
    case MESSAGE_CALL_REVERTED:
      {
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);
        uint256_t gasLeft = callReturn.gasLeft;
        check(false, "MESSAGE_CALL_REVERTED");
        break;
      }
    case MESSAGE_CALL_TRACE:
      {
        uint8_t position = std::get<uint8_t>(callResult.second);
        check(false, "MESSAGE_TRACE::" + std::to_string(position));
        break;
      }
    case MESSAGE_CALL_OUT_OF_GAS:
      check(false, "MESSAGE_CALL_OUT_OF_GAS");
      break;
    case MESSAGE_CALL_FAILED:
      {
        trap_t trap = std::get<trap_t>(callResult.second);
        switch (trap.first) {
          case TrapKind::TRAP_NONE:
            check(false, "MESSAGE_CALL_FAILED");
            break;
          case TrapKind::TRAP_STACK_UNDERFLOW:
            check(false, "STACK_UNDERFLOW");
            break;
          case TrapKind::TRAP_OUT_OF_STACK:
            check(false, "OUT_OF_STACK");
            break;
          case TrapKind::TRAP_INVALID_INSTRUCTION:
            check(false, "INVALID_INSTRUCTION");
            break;
          case TrapKind::TRAP_INVALID_JUMP:
            check(false, "INVALID_JUMP");
            break;
          case TrapKind::TRAP_CODE_EXISTS:
            check(false, "MESSAGE_CALL_FAILED [The sender address already contains a code entry, you must call suicide before creating another contract.]");
            break;
          case TrapKind::TRAP_INVALID_CODE_ADDRESS:
            check(false, "MESSAGE_CALL_FAILED [An invalid address is attempting to create a contract.]");
            break;
          case TrapKind::TRAP_CALL:
            check(false, "CALL FAILED");
            break;
          case TrapKind::TRAP_CREATE:
            check(false, "CREATE FAILED");
            break;
        }
        break;
      }
  }
}

void eos_evm::commitState(name from, std::shared_ptr<AccountState> accountState) {
  if (accountState->cacheItems->size() > 0) {
    // TODO: the scope of account_state should be derived from codeAddress
    account_state_table _account_state(get_self(), from.value);
    for (int i = 0; i < accountState->cacheItems->size(); i++) {
      eosio::checksum256 compositeKey =  BigInt::toFixed32(Hash::keccak256Word(
        accountState->cacheItems->at(i).codeAddress,
        accountState->cacheItems->at(i).key
      ));
      auto idx = _account_state.get_index<name("statekey")>();
      auto itr = idx.find(compositeKey);
      if (itr != idx.end()) {
        idx.modify(itr, from, [&](auto& account_state) {
          account_state.value = BigInt::toFixed32(accountState->cacheItems->at(i).value);
        });
      } else {
        _account_state.emplace(from, [&](auto& account_state) {
          account_state.pk = _account_state.available_primary_key();
          account_state.accountIdentifier = BigInt::toFixed32(accountState->cacheItems->at(i).codeAddress);
          account_state.key = compositeKey;
          account_state.value = BigInt::toFixed32(accountState->cacheItems->at(i).value);
        });
      }
    }
  }
}

ACTION eos_evm::create(name from, string message) {
  require_auth(from);

  account_table _account(get_self(), get_self().value);

  auto iterator = _account.find(from.value);
  check(iterator == _account.end(), "An Ethereum account already exists for this user.");

  bytes_t accountIdentifier = Address::accountIdentifierFromString(
    from.to_string(), 
    message
  );

  _account.emplace(from, [&](auto& account) {
    account.user = from;
    account.nonce = 0;
    account.accountIdentifier = eos_utils::hexToChecksum256(accountIdentifier);
  });
}

EOSIO_DISPATCH(eos_evm, (raw)(create))

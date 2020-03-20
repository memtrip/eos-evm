#include <string>
#include <eosio/crypto.hpp>
#include <eos_evm.hpp>
#include <eos_system.hpp>
#include <eos_ecrecover.hpp>
#include <eos_utils.hpp>
#include <eos_execute.hpp>

#include <evm/address.h>
#include <evm/transaction.h>
#include <evm/hex.h>

ACTION eos_evm::raw(name from, string code, string sender) {
  require_auth(from);

  transaction_t transaction = Transaction::parse(code, 0x01);

  if (Transaction::signatureExists(transaction)) {
    bytes_t accountIdentifierBytes = eos_ecrecover::recover(
      from.to_string(),
      transaction.digest,
      Transaction::signatureBytes(transaction)
    );

    eosio::checksum256 accountIdentifier = eos_utils::hexToFixed(accountIdentifierBytes);
    account_table _account(get_self(), get_self().value);
    auto idx = _account.get_index<name("accountid")>();
    auto itr = idx.find(accountIdentifier);

    check(itr != idx.end(), "The account identifier associated with this transaction does not exist.");
    // itr-user is used in the transaction
    //bytes_t address = eos_utils::fixedToBytes(accountIdentifier);
    bytes_t address = bytes_t();
    call_result_t callResult = eos_execute::transaction(transaction, address);
    handleCallResult(callResult);
    check(1 != 1, "TODO: Execute transaction signed transaction");
  } else {
    eosio::checksum256 accountIdentifier = eos_utils::hexToFixed(sender);
    account_table _account(get_self(), get_self().value);
    auto idx = _account.get_index<name("accountid")>();
    auto itr = idx.find(accountIdentifier);

    check(itr != idx.end(), "Could not find sender, did you provide the correct account identifier?");
    check(has_auth(itr->user), "You do not have permission to execute a transaction for the specified sender.");
    // itr->user is used in the transaction
    //bytes_t address = eos_utils::fixedToBytes(accountIdentifier);
    bytes_t address = bytes_t();
    call_result_t callResult = eos_execute::transaction(transaction, address);
    handleCallResult(callResult);
    check(1 != 1, "TODO: Execute transaction for account identifier, resolved by eosio");
  }
}

void eos_evm::handleCallResult(call_result_t callResult) {
  switch (callResult.first) {
    case MESSAGE_CALL_SUCCESS:
      {
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);
        uint256_t gasLeft = callReturn.gasLeft;
        check(false, "MESSAGE_CALL_SUCCESS");
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
      check(false, "MESSAGE_CALL_FAILED");
      break;
  }
}

ACTION eos_evm::create(name from, string message) {
  require_auth(from);

  account_table _account(get_self(), get_self().value);

  auto iterator = _account.find(from.value);
  check(iterator == _account.end(), "An Ethereum account already exists for this user.");

  _account.emplace(from, [&](auto& account) {
    account.user = from;
    account.nonce = 1;
    account.accountIdentifier = eos_utils::hexToFixed(
      Address::accountIdentifierFromString(
        from.to_string(), 
        message
      )
    );
  });
}

ACTION eos_evm::writelog(name from, string message) {
  require_auth(get_self());

  log_table _log(get_self(), get_self().value);

  _log.emplace(from, [&](auto& log) {
    log.key = _log.available_primary_key();
    log.user = from;
    log.message = message;
  });
}

ACTION eos_evm::clearlog() {
  require_auth(get_self());

  log_table _log(get_self(), get_self().value);

  auto log_itr = _log.begin();
  while (log_itr != _log.end()) {
    log_itr = _log.erase(log_itr);
  }
}

EOSIO_DISPATCH(eos_evm, (raw)(create)(writelog)(clearlog))

#include <string>
#include <eosio/crypto.hpp>
#include <eos_evm.hpp>
#include <eos_system.hpp>
#include <eos_ecrecover.hpp>
#include <eos_utils.hpp>

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
    check(1 != 1, "TODO: Execute transaction signed transaction");
  } else {
    eosio::checksum256 accountIdentifier = eos_utils::hexToFixed(sender);
    account_table _account(get_self(), get_self().value);
    auto idx = _account.get_index<name("accountid")>();
    auto itr = idx.find(accountIdentifier);

    check(itr != idx.end(), "Could not find sender, did you provide the correct account identifier?");
    check(has_auth(itr->user), "You do not have permission to execute a transaction for the specified sender.");
    // itr->user is used in the transaction
    check(1 != 1, "TODO: Execute transaction for account identifier, resolved by eosio");
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

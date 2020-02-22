#include <string>
#include <eosio/crypto.hpp>
#include <eos_evm.hpp>
#include <eos_system.hpp>
#include <ecrecover.hpp>

#include <evm/address.h>
#include <evm/transaction.h>

ACTION eos_evm::raw(name from, string code, string sender) {
  require_auth(from);

  transaction_t transaction = Transaction::parse(code, 0x01);

  // TODO: transactions and addresses will include th `0x` prefix
  if (Transaction::signatureExists(transaction)) {
    string accountIdentifier = ecrecover::recover(
      Transaction::signatureBytes(transaction), 
      transaction.digest
    );
    // TODO: check if the accountIdentifier exists in the accounts table
    check(1 != 1, "Execute transaction for: " + accountIdentifier);
  } else {
    // TODO: check if the sender exists in the account table
    // TODO: compare the account associated with the sender to the `from` name
    account_table _account(get_self(), get_self().value);

    auto iterator = _account.find(from.value);
    check(iterator != _account.end(), "You must create an Ethereum account via the create() action before executing transactions.");

    check(1 != 1, "Execute transaction for account identifier, resolved by eosio");
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
    account.accountIdentifier = Address::createAccountIdentifier(
      from.to_string(), 
      message
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

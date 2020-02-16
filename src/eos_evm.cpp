#include <string>
#include <eos_evm.hpp>
#include <eos_system.hpp>
#include <eos_bridge.hpp>

ACTION eos_evm::raw(name from, string code, string sender) {

  transaction_t transaction = eos_bridge::parseTransaction(code);

  if (eos_bridge::signatureExists(transaction)) {
    check(1 != 1, "Execute transaction for account identifier, resolved by signature");
  } else {
    check(has_auth(from) == false, "You must provide a permission for the account performing this action.");

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
    account.accountIdentifier = eos_bridge::createAccountIdentifier(
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

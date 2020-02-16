#include <string>
#include <eos_evm.hpp>
#include <eos_system.hpp>

ACTION eos_evm::raw(name from, string code, string sender) {
  require_auth(get_self());

  log_table _log(get_self(), get_self().value);

  _log.emplace(from, [&](auto& log) {
    log.key = _log.available_primary_key();
    log.user = from;
    log.message = std::to_string(eos_system::timestamp());
  });
}

ACTION eos_evm::create(name sender, string message) {
  require_auth(sender);

  log_table _log(get_self(), get_self().value);

  _log.emplace(sender, [&](auto& log) {
    log.key = _log.available_primary_key();
    log.user = sender;
    log.message = std::to_string(eos_system::block_num());
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

EOSIO_DISPATCH(eos_evm, (raw)(writelog)(clearlog))
